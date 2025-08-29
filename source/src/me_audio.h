/* ME Audio Processing for FrogGBA
 * Offloads GBA audio emulation to PSP Media Engine
 */

#ifndef ME_AUDIO_H
#define ME_AUDIO_H

#include "common.h"

// Audio command types for ME
typedef enum {
  ME_AUDIO_CMD_NONE = 0,
  ME_AUDIO_CMD_REG_WRITE,      // Write to audio register
  ME_AUDIO_CMD_FIFO_WRITE,      // DirectSound FIFO write
  ME_AUDIO_CMD_TIMER_OVERFLOW,  // Timer overflow event
  ME_AUDIO_CMD_SYNC,            // Sync point
  ME_AUDIO_CMD_RESET            // Reset audio system
} ME_AUDIO_CMD_TYPE;

// Command structure for ME audio processing
typedef struct {
  u8 cmd_type;
  u8 channel;
  u16 reg_address;
  u32 value;
  u32 cpu_ticks;
} MEAudioCommand;

// Shared memory structure between main CPU and ME
typedef struct {
  // Command ring buffer (main CPU writes, ME reads)
  MEAudioCommand commands[1024];
  volatile u32 cmd_write_pos;
  volatile u32 cmd_read_pos;
  
  // Audio output ring buffer (ME writes, main CPU reads)
  s16 audio_buffer[8192];  // Stereo samples
  volatile u32 audio_write_pos;
  volatile u32 audio_read_pos;
  
  // Synchronization
  volatile u32 me_running;
  volatile u32 frame_counter;
  
  // Audio state cache for ME
  u8 direct_sound_fifo[2][32];
  u32 gbc_sound_registers[64];
  
} MEAudioShared;

// Initialize ME audio processing
int me_audio_init(void);

// Queue audio command for ME
void me_audio_queue_command(ME_AUDIO_CMD_TYPE cmd, u32 value, u32 cpu_ticks);
void me_audio_queue_reg_write(u16 reg_address, u32 value, u32 cpu_ticks);
void me_audio_queue_fifo_write(u8 channel, u8 sample, u32 cpu_ticks);

// Get audio samples from ME
u32 me_audio_get_samples(s16 *buffer, u32 count);

// Shutdown ME audio
void me_audio_shutdown(void);

// Check if ME audio is enabled
extern u32 me_audio_enabled;

#endif // ME_AUDIO_H