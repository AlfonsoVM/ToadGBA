/* PSP Media Engine Background Processing Implementation */

#include "common.h"
#include "me_background.h"

// ME library stubs (real implementation would link ME library)
static inline void meLibSync(void) { }
static inline void meLibHalt(void) { }
static inline int meLibDefaultInit(void) { return -1; }  // Fail for now

u32 me_background_enabled = 0;
static MEBackgroundShared *shared_mem = NULL;

// Simple compression using RLE (run-length encoding) for save states
static u32 simple_compress(u8 *input, u32 input_size, u8 *output, u32 max_output_size) {
    u32 input_pos = 0, output_pos = 0;
    
    while (input_pos < input_size && output_pos < max_output_size - 2) {
        u8 current_byte = input[input_pos];
        u32 run_length = 1;
        
        // Count consecutive identical bytes
        while (input_pos + run_length < input_size && 
               input[input_pos + run_length] == current_byte && 
               run_length < 255) {
            run_length++;
        }
        
        if (run_length >= 3) {
            // Use RLE: [count] [value] 
            output[output_pos++] = (u8)run_length;
            output[output_pos++] = current_byte;
        } else {
            // Store bytes directly for short runs
            for (u32 i = 0; i < run_length && output_pos < max_output_size; i++) {
                output[output_pos++] = current_byte;
            }
        }
        
        input_pos += run_length;
    }
    
    return output_pos;
}

// Simple decompression 
static u32 simple_decompress(u8 *input, u32 input_size, u8 *output, u32 max_output_size) {
    u32 input_pos = 0, output_pos = 0;
    
    while (input_pos < input_size - 1 && output_pos < max_output_size) {
        u8 count = input[input_pos++];
        u8 value = input[input_pos++];
        
        // Decompress run
        for (u32 i = 0; i < count && output_pos < max_output_size; i++) {
            output[output_pos++] = value;
        }
    }
    
    return output_pos;
}

// Generate color correction LUT (15-bit GBA colors -> 16-bit PSP colors)
static void generate_color_lut(u32 gamma, u32 contrast, u32 brightness, u16 *lut) {
    for (u32 color15 = 0; color15 < 32768; color15++) {
        // Extract RGB components (5-bit each)
        u32 r5 = (color15 >> 0) & 0x1F;
        u32 g5 = (color15 >> 5) & 0x1F;
        u32 b5 = (color15 >> 10) & 0x1F;
        
        // Convert to 8-bit for processing
        u32 r8 = (r5 * 255) / 31;
        u32 g8 = (g5 * 255) / 31;  
        u32 b8 = (b5 * 255) / 31;
        
        // Apply brightness (simple add)
        r8 += (brightness - 0x10000) >> 8;
        g8 += (brightness - 0x10000) >> 8;
        b8 += (brightness - 0x10000) >> 8;
        
        // Apply contrast (simple multiply)
        r8 = (r8 * contrast) >> 16;
        g8 = (g8 * contrast) >> 16;
        b8 = (b8 * contrast) >> 16;
        
        // Simple gamma approximation (power curve)
        if (gamma != 0x10000) {
            // Simplified gamma: adjust midtones
            u32 gamma_shift = (gamma > 0x10000) ? 1 : -1;
            if (r8 > 64 && r8 < 192) r8 += gamma_shift * 16;
            if (g8 > 64 && g8 < 192) g8 += gamma_shift * 16;  
            if (b8 > 64 && b8 < 192) b8 += gamma_shift * 16;
        }
        
        // Clamp to valid range
        if (r8 > 255) r8 = 255;
        if (g8 > 255) g8 = 255;
        if (b8 > 255) b8 = 255;
        
        // Convert back to 5-6-5 RGB
        u32 r6 = (r8 * 31) / 255;
        u32 g6 = (g8 * 63) / 255;  // 6-bit green
        u32 b6 = (b8 * 31) / 255;
        
        lut[color15] = (r6 << 11) | (g6 << 5) | b6;
    }
}

// ME background processor (runs on Media Engine)
__attribute__((section("_me_section")))
void me_background_processor(void) {
    if (!shared_mem) return;
    
    MEBackgroundShared *mem = shared_mem;
    
    while (1) {
        // Wait for task
        while (!mem->task_active) {
            volatile int delay;
            for (delay = 0; delay < 100; delay++);
        }
        
        switch (mem->task_type) {
            case ME_TASK_COMPRESS_SAVESTATE:
                mem->savestate_output_size = simple_compress(
                    mem->savestate_input, 
                    mem->savestate_input_size,
                    mem->savestate_output, 
                    mem->savestate_output_size  // max size
                );
                break;
                
            case ME_TASK_DECOMPRESS_SAVESTATE:
                simple_decompress(
                    mem->savestate_input,
                    mem->savestate_input_size, 
                    mem->savestate_output,
                    mem->savestate_output_size
                );
                break;
                
            case ME_TASK_GENERATE_COLOR_LUT:
                generate_color_lut(
                    mem->gamma_value,
                    mem->contrast_value, 
                    mem->brightness_value,
                    mem->color_lut_output
                );
                break;
                
            default:
                break;
        }
        
        // Signal completion
        meLibSync();
        mem->task_complete = 1;
        mem->task_active = 0;
    }
}

// Initialize ME background processing
int me_background_init(void) {
    // Check if ME is manually disabled (will be properly applied after config load)
    extern u32 option_me_engine;
    if (option_me_engine == 1) {
        return -1; // Manually disabled
    }
    
    // Try to initialize ME library
    if (meLibDefaultInit() < 0) {
        return -1;
    }
    
    // Allocate shared memory
    shared_mem = (MEBackgroundShared *)memalign(64, sizeof(MEBackgroundShared));
    if (!shared_mem) {
        return -2;
    }
    
    memset(shared_mem, 0, sizeof(MEBackgroundShared));
    
    // Start ME processor thread
    // Real implementation would start ME thread here
    
    me_background_enabled = 1;
    return 0;
}

// Compress save state asynchronously
int me_compress_savestate_async(u8 *input, u32 input_size, u8 *output, u32 *output_size) {
    if (!me_background_enabled || !shared_mem) return -1;
    if (shared_mem->task_active) return -2; // Busy
    
    shared_mem->task_type = ME_TASK_COMPRESS_SAVESTATE;
    shared_mem->savestate_input = input;
    shared_mem->savestate_input_size = input_size;
    shared_mem->savestate_output = output;
    shared_mem->savestate_output_size = *output_size; // max size
    shared_mem->task_complete = 0;
    
    meLibSync();
    shared_mem->task_active = 1;
    
    return 0;
}

// Decompress save state asynchronously  
int me_decompress_savestate_async(u8 *input, u32 input_size, u8 *output, u32 output_size) {
    if (!me_background_enabled || !shared_mem) return -1;
    if (shared_mem->task_active) return -2;
    
    shared_mem->task_type = ME_TASK_DECOMPRESS_SAVESTATE;
    shared_mem->savestate_input = input;
    shared_mem->savestate_input_size = input_size;
    shared_mem->savestate_output = output;
    shared_mem->savestate_output_size = output_size;
    shared_mem->task_complete = 0;
    
    meLibSync();
    shared_mem->task_active = 1;
    
    return 0;
}

// Generate color LUT asynchronously
int me_generate_color_lut_async(u32 gamma, u32 contrast, u32 brightness, u16 *lut_output) {
    if (!me_background_enabled || !shared_mem) return -1;
    if (shared_mem->task_active) return -2;
    
    shared_mem->task_type = ME_TASK_GENERATE_COLOR_LUT;
    shared_mem->gamma_value = gamma;
    shared_mem->contrast_value = contrast;
    shared_mem->brightness_value = brightness;
    shared_mem->color_lut_output = lut_output;
    shared_mem->task_complete = 0;
    
    meLibSync();
    shared_mem->task_active = 1;
    
    return 0;
}

// Check if current task is complete
int me_background_task_complete(void) {
    if (!me_background_enabled || !shared_mem) return 1;
    return shared_mem->task_complete;
}

// Wait for task completion
void me_background_wait_complete(void) {
    if (!me_background_enabled || !shared_mem) return;
    
    u32 timeout = 10000;
    while (!shared_mem->task_complete && timeout-- > 0) {
        volatile int delay;
        for (delay = 0; delay < 100; delay++);
    }
}

// Shutdown ME background processing
void me_background_shutdown(void) {
    if (shared_mem) {
        shared_mem->task_active = 0;
        meLibSync();
        
        sceKernelDelayThread(10000);
        
        free(shared_mem);
        shared_mem = NULL;
    }
    
    me_background_enabled = 0;
}

// Apply ME engine option setting
void apply_me_engine_option(u32 option) {
    switch(option) {
        case 0: // Auto - let ME init decide
            // Already handled by me_background_init() 
            break;
            
        case 1: // Disabled - force disable ME
            if (me_background_enabled) {
                me_background_shutdown();
                printf("ME engine manually disabled\n");
            }
            break;
            
        case 2: // Enabled - try to force enable (no additional action needed)
            // me_background_init() already tries to enable
            if (!me_background_enabled) {
                printf("ME engine requested but unavailable\n");
            }
            break;
    }
}