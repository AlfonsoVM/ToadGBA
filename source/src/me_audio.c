/* ME Audio Processing Implementation
 * Offloads GBA audio to PSP Media Engine for better performance
 */

#include "common.h"
#include "me_audio.h"

// Simplified ME stubs for compilation (ME library integration would be added later)
static inline void meLibSync(void) { }
static inline void meLibHalt(void) { }
static inline int meLibDefaultInit(void) { return -1; }  // Fail for now

// Dummy hardware register stubs
static u32 HW_SYS_BUS_CLOCK_ENABLE;
static u32 HW_SYS_NMI_FLAGS;  
static u32 HW_SYS_TACHYON_CONFIG_STATUS;

u32 me_audio_enabled = 0;
static MEAudioShared *shared_mem = NULL;

// ME-side audio processing function (runs on Media Engine)
__attribute__((section("_me_section")))
void meLibExec(void) {
  // Initialize ME hardware
  HW_SYS_BUS_CLOCK_ENABLE = 0x0f;
  HW_SYS_NMI_FLAGS = 0xffffffff;
  HW_SYS_TACHYON_CONFIG_STATUS = 0x02;
  meLibSync();
  
  MEAudioShared *shared = (MEAudioShared *)0x00200000;  // Use EDRAM for shared memory
  
  while (shared->me_running) {
    // Process commands from main CPU
    while (shared->cmd_read_pos != shared->cmd_write_pos) {
      MEAudioCommand *cmd = &shared->commands[shared->cmd_read_pos & 1023];
      
      switch (cmd->cmd_type) {
        case ME_AUDIO_CMD_REG_WRITE:
          // Update audio register
          shared->gbc_sound_registers[cmd->reg_address & 63] = cmd->value;
          break;
          
        case ME_AUDIO_CMD_FIFO_WRITE:
          // Update DirectSound FIFO
          if (cmd->channel < 2) {
            shared->direct_sound_fifo[cmd->channel][cmd->value & 31] = (s8)(cmd->value >> 8);
          }
          break;
          
        case ME_AUDIO_CMD_TIMER_OVERFLOW:
          // Process timer overflow - trigger sample playback
          // This is where we'd process DirectSound samples
          break;
          
        case ME_AUDIO_CMD_SYNC:
          // Generate audio samples up to this CPU tick point
          // Calculate how many samples to generate based on CPU ticks
          {
            static u32 last_cpu_ticks = 0;
            u32 cpu_tick_delta = cmd->cpu_ticks - last_cpu_ticks;
            last_cpu_ticks = cmd->cpu_ticks;
            
            // Convert CPU ticks to audio samples (simplified calculation)
            // GBA CPU: 16.78MHz, Audio: 44.1KHz
            u32 samples_to_generate = (cpu_tick_delta * 44100) / 16780000;
            if (samples_to_generate > 512) samples_to_generate = 512; // Limit burst
            
            // Generate samples (simplified GBC + DirectSound mixing)
            u32 i;
            for (i = 0; i < samples_to_generate; i++) {
              s32 left_sample = 0, right_sample = 0;
              
              // Simple square wave generation for GBC channel 1 (proof of concept)
              // In reality, this would process all 4 GBC channels + 2 DirectSound
              if (shared->gbc_sound_registers[0x10 / 2] & 0x8000) { // Channel 1 enabled
                static u32 phase = 0;
                u32 freq = shared->gbc_sound_registers[0x14 / 2] & 0x7FF;
                if (freq > 0) {
                  phase += (131072 / (2048 - freq));  // Simplified frequency calculation
                  s16 square_sample = (phase & 0x8000) ? 1000 : -1000;
                  left_sample += square_sample;
                  right_sample += square_sample;
                }
              }
              
              // Add DirectSound channels (simplified)
              // Channel A
              if (shared->gbc_sound_registers[0x82 / 2] & 0x0100) { // DirectSound A enabled
                // Would process FIFO data here
                s16 ds_sample = (s16)(shared->direct_sound_fifo[0][i & 31]) << 6;
                left_sample += ds_sample;
                right_sample += ds_sample;
              }
              
              // Channel B  
              if (shared->gbc_sound_registers[0x82 / 2] & 0x1000) { // DirectSound B enabled
                s16 ds_sample = (s16)(shared->direct_sound_fifo[1][i & 31]) << 6;
                left_sample += ds_sample;
                right_sample += ds_sample;
              }
              
              // Clamp and write to buffer
              if (left_sample > 32767) left_sample = 32767;
              if (left_sample < -32768) left_sample = -32768;
              if (right_sample > 32767) right_sample = 32767;
              if (right_sample < -32768) right_sample = -32768;
              
              u32 pos = (shared->audio_write_pos + i * 2) & 8191;
              shared->audio_buffer[pos] = (s16)left_sample;
              shared->audio_buffer[pos + 1] = (s16)right_sample;
            }
            
            shared->audio_write_pos = (shared->audio_write_pos + samples_to_generate * 2) & 8191;
          }
          break;
          
        case ME_AUDIO_CMD_RESET:
          // Reset audio state
          break;
      }
      
      shared->cmd_read_pos = (shared->cmd_read_pos + 1) & 1023;
    }
    
    // Small delay to prevent ME from spinning too fast
    volatile int delay;
    for (delay = 0; delay < 100; delay++);
  }
  
  meLibHalt();
}

// Initialize ME audio processing
int me_audio_init(void) {
  // Check if ME library can be initialized
  const int tableId = meLibDefaultInit();
  if (tableId < 0) {
    return -1;
  }
  
  // Allocate shared memory (uncached for both CPU and ME)
  shared_mem = (MEAudioShared *)memalign(64, sizeof(MEAudioShared));
  if (!shared_mem) {
    return -2;
  }
  
  // Clear shared memory
  memset(shared_mem, 0, sizeof(MEAudioShared));
  
  // Mark ME as running
  shared_mem->me_running = 1;
  
  // Flush cache
  sceKernelDcacheWritebackInvalidateAll();
  
  me_audio_enabled = 1;
  return 0;
}

// Queue audio command for ME
void me_audio_queue_command(ME_AUDIO_CMD_TYPE cmd, u32 value, u32 cpu_ticks) {
  if (!me_audio_enabled || !shared_mem) return;
  
  u32 next_pos = (shared_mem->cmd_write_pos + 1) & 1023;
  
  // Don't overflow command buffer
  if (next_pos == shared_mem->cmd_read_pos) {
    return;  // Buffer full, drop command (shouldn't happen in practice)
  }
  
  MEAudioCommand *cmd_slot = &shared_mem->commands[shared_mem->cmd_write_pos];
  cmd_slot->cmd_type = cmd;
  cmd_slot->value = value;
  cmd_slot->cpu_ticks = cpu_ticks;
  
  // Memory barrier to ensure write is visible to ME
  meLibSync();
  
  shared_mem->cmd_write_pos = next_pos;
}

// Queue register write for ME
void me_audio_queue_reg_write(u16 reg_address, u32 value, u32 cpu_ticks) {
  if (!me_audio_enabled || !shared_mem) return;
  
  u32 next_pos = (shared_mem->cmd_write_pos + 1) & 1023;
  if (next_pos == shared_mem->cmd_read_pos) return;
  
  MEAudioCommand *cmd_slot = &shared_mem->commands[shared_mem->cmd_write_pos];
  cmd_slot->cmd_type = ME_AUDIO_CMD_REG_WRITE;
  cmd_slot->reg_address = reg_address;
  cmd_slot->value = value;
  cmd_slot->cpu_ticks = cpu_ticks;
  
  meLibSync();
  shared_mem->cmd_write_pos = next_pos;
}

// Queue FIFO write for ME
void me_audio_queue_fifo_write(u8 channel, u8 sample, u32 cpu_ticks) {
  if (!me_audio_enabled || !shared_mem) return;
  
  u32 next_pos = (shared_mem->cmd_write_pos + 1) & 1023;
  if (next_pos == shared_mem->cmd_read_pos) return;
  
  MEAudioCommand *cmd_slot = &shared_mem->commands[shared_mem->cmd_write_pos];
  cmd_slot->cmd_type = ME_AUDIO_CMD_FIFO_WRITE;
  cmd_slot->channel = channel;
  cmd_slot->value = sample;
  cmd_slot->cpu_ticks = cpu_ticks;
  
  meLibSync();
  shared_mem->cmd_write_pos = next_pos;
}

// Get audio samples from ME
u32 me_audio_get_samples(s16 *buffer, u32 count) {
  if (!me_audio_enabled || !shared_mem) return 0;
  
  u32 available = (shared_mem->audio_write_pos - shared_mem->audio_read_pos) & 8191;
  available /= 2;  // Convert from samples to stereo pairs
  
  if (available > count) {
    available = count;
  }
  
  u32 i;
  for (i = 0; i < available * 2; i++) {
    buffer[i] = shared_mem->audio_buffer[(shared_mem->audio_read_pos + i) & 8191];
  }
  
  shared_mem->audio_read_pos = (shared_mem->audio_read_pos + available * 2) & 8191;
  
  return available;
}

// Shutdown ME audio
void me_audio_shutdown(void) {
  if (shared_mem) {
    shared_mem->me_running = 0;
    meLibSync();
    
    // Wait a bit for ME to stop
    sceKernelDelayThread(10000);
    
    free(shared_mem);
    shared_mem = NULL;
  }
  
  me_audio_enabled = 0;
}