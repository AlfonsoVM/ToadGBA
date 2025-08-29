/* PSP Media Engine Background Processing
 * Non-real-time tasks perfect for ME offloading
 */

#ifndef ME_BACKGROUND_H
#define ME_BACKGROUND_H

#include "common.h"

// ME background task types
typedef enum {
    ME_TASK_NONE = 0,
    ME_TASK_COMPRESS_SAVESTATE,
    ME_TASK_DECOMPRESS_SAVESTATE, 
    ME_TASK_GENERATE_COLOR_LUT,
    ME_TASK_COMPRESS_SCREENSHOT
} METaskType;

// Shared memory structure for ME tasks
typedef struct {
    volatile u32 task_active;      // ME is processing
    volatile u32 task_complete;    // Task finished
    METaskType task_type;          // What to process
    
    // Save state compression
    u8 *savestate_input;
    u32 savestate_input_size;
    u8 *savestate_output;
    u32 savestate_output_size;
    u32 compression_level;
    
    // Color LUT generation
    u32 gamma_value;               // Fixed point gamma (1.0 = 0x10000)
    u32 contrast_value;            // Fixed point contrast
    u32 brightness_value;          // Fixed point brightness
    u16 *color_lut_output;         // 32768 entries (15-bit to 16-bit)
    
    // Screenshot compression
    u16 *screenshot_data;
    u32 screenshot_width;
    u32 screenshot_height;
    u8 *png_output;
    u32 png_output_size;
    
} MEBackgroundShared;

// ME functions
int me_background_init(void);
void me_background_shutdown(void);

// Save state compression (async)
int me_compress_savestate_async(u8 *input, u32 input_size, u8 *output, u32 *output_size);
int me_decompress_savestate_async(u8 *input, u32 input_size, u8 *output, u32 output_size);

// Color LUT generation (async)
int me_generate_color_lut_async(u32 gamma, u32 contrast, u32 brightness, u16 *lut_output);

// Check if ME task is complete
int me_background_task_complete(void);
void me_background_wait_complete(void);

extern u32 me_background_enabled;

#endif