# FrogGBA - TempGBA mod by Prosty

## Download & Installation
![FrogGBA Icon](source/res/ICON0.png)

**→ [Download the latest release here](https://github.com/tzubertowski/FrogGBA/releases) ←**

You need to have a CFW installed on your PSP. 
- Unzip the folder
- Copy the unzipped PSP folder into root of your PSP SD card
- Launch the emulator on the console

### TL;DR - Key Improvements in v0.2.3 (Latest)
• 🔧 **Auto-Resume Fixed** - No more freezing when loading save states on boot
• 📂 **Recent Games Fixed** - Path doubling bug resolved, games load on first try
• 🎮 **Game Config System** - Per-game settings with automatic ROM detection
• ⚡ **ME Framework** - PSP Media Engine integration framework (disabled pending testing)
• 💾 **Hidden Slot 11** - Automatic save/resume using invisible save slot
• 🚀 **gpSP Kai Optimizations** - 10-25% performance gains in demanding titles
• 💯 **Full Speed Castlevania** - Water sections now run at 30+ FPS (was 15-20)
• 🎮 **Recent Games Menu** - Quick access to your last 10 played titles
• 🖼️ **Lightning-Fast Overlays** - Full-screen borders with zero performance impact
• ⚡ **No More Stutters** - Smart cache management eliminates micro-stutters

## About
This is a modified version of TempGBA - a Game Boy Advance emulator for PlayStation Portable.

This mod is based on:
- [TempGBA](https://github.com/Nebuleon/TempGBA) by Nebuleon, Normmatt, and BassAceGold
- TempGBA4PSP-mod (TempGBA4PSP-26731020), http://www1.axfc.net/uploader/so/3063963

## What's New in FrogGBA (Since v1.0)

### 🖼️ Overlay System (Enhanced in v0.2.2)
- **Lightning-Fast Loading**: Completely reworked overlay system loads instantly with zero performance impact
- **Full-Screen Borders**: Overlays can now stretch across the entire PSP display
- **Custom Overlays/Borders**: Render PNG overlays above the game window for bezels, borders, and custom frames
- **X/Y Offset Controls**: Position the game window anywhere on screen
- **Online Overlay Generator**: Convert PNG images to OVL format at [froggba.onrender.com](https://froggba.onrender.com)
- **Multiple Overlay Slots**: Store up to 10 different overlays and switch between them
- **RLE Compression**: Advanced compression handles pixel-dense designs without slowdown

### 📐 Display Options
- **Aspect Ratio Modes**:
  - **Core Provided (3:2)**: Original GBA aspect ratio with proper scaling
  - **Zoom (Fill Screen)**: Fills screen vertically, crops sides slightly
  - **Stretch (Full PSP)**: Stretches to fill entire 480×272 screen
- **Color Correction**: 
  - GPSP mode with optimized lookup tables
  - Retro mode for authentic GBA colors
  - Off for raw output
- **FPS Display**: SELECT + Square to toggle performance counter

### ⚡ Performance Optimizations
- **gpSP Kai Engine**: Implemented proven optimizations from the legendary gpSP Kai
  - Static translation caches for reduced memory fragmentation
  - Cache invalidation reduction for smoother frame pacing  
  - Optimized tile rendering pipeline matching gpSP Kai approach
- **Multi-Layer Rendering**: Fixed 4-layer Mode 0 bottlenecks
  - **Castlevania Series**: Water sections now run at full 30+ FPS (was 15-20 FPS)
  - **Golden Sun Series**: Battle effects and world map rendering improved
  - **Fire Emblem**: Large battle animations no longer cause slowdown
- **Memory Management**: Optimized for PSP architecture
  - 2MB ROM cache, 256KB RAM cache (reduced from previous oversized caches)
  - Pre-warmed cache lines reduce initial load stutters
- **Audio Processing**: Improved buffering reduces crackling and provides smoother sound
- **Volatile Memory Support**: Uses additional PSP RAM for maximum performance
  - Works on all PSP models (1000/2000/3000/Go)

### 💾 Save State Improvements
- **Auto Menu Exit**: Menu automatically closes after loading/saving states
- **Better Memory Management**: Temporarily frees overlay memory during save/load operations
- **File Validation**: Prevents crashes from corrupted or empty save states
- **Persistent Settings**: All new options are saved in config

### 🎮 Quality of Life  
- **Recent Games Menu**: Your last 10 played titles appear at the top when loading a game
  - Fixed path doubling issue for recent games
  - Recent games now load correctly on first attempt
- **Auto Save/Resume**: 
  - Automatically saves state to hidden slot 11 when exiting
  - Auto-loads save state when launching a game
  - Resume on boot option to continue where you left off
- **Fast Forward**: SELECT + R toggles 2x/3x speed modes
- **Turbo Buttons**: Triangle and Square as dedicated turbo buttons
- **ROM Validation**: Prevents crashes when loading invalid files
- **Clean Exit**: Fixed BSOD crashes when exiting the emulator
- **Smooth Transitions**: Eliminated micro-stutters during level loading

### 🔧 Technical Improvements
- **PSP Cycle Batching**: Reduces dynamic recompiler overhead
- **Cache Invalidation Reduction**: Conservative cache management
- **Timer Prescaling Optimization**: Better audio/video sync
- **Smart Memory Allocation**: Dynamic allocation reduces static memory usage by ~550KB

### 📈 Performance Impact (v0.2.2)
- **Castlevania Series**: Water sections 15-20 FPS → 30+ FPS (100% speed achieved!)
- **Golden Sun Series**: Battle effects now run without slowdown
- **Fire Emblem**: Large animations no longer cause frame drops
- **Kirby Amazing Mirror**: Eliminated level transition stutters
- **Overall**: 10-25% improvement in demanding titles, consistent 60 FPS in most games

## 🎨 How to Use Custom Overlays

### Creating Overlays
1. **Visit the Online Generator**: Go to [froggba.onrender.com](https://froggba.onrender.com)
2. **Upload Your PNG**: 
   - Image must be exactly 480×272 pixels (PSP screen size)
   - Transparent areas will show the game
   - Opaque areas will be the border/bezel
3. **Download OVL File**: Click convert and download the generated .ovl file
4. **Install on PSP**:
   - Copy the .ovl file to `/PSP/GAME/FrogGBA/overlays/` on your Memory Stick
   - Files will appear in the Overlay menu in-game

### Using Overlays in FrogGBA
1. Press **HOME** during gameplay to open the menu
2. Navigate to **Overlay Settings**
3. Select your overlay from the list
4. Adjust X/Y offset if needed to position the game window
5. Enable/disable overlays with the toggle option

### Tips for Best Results
- Design overlays with a transparent center area for the game (240×160 minimum)
- Use PNG transparency for see-through areas
- Keep border designs simple to avoid hitting the 30,000 pixel limit
- Test different aspect ratios with your overlays (Core/Zoom/Stretch)

## Latest Optimizations & Enhancements (NEW)

### 🔧 Video Rendering Optimizations Re-Enabled
- **Fast Path Rendering** - Re-enabled optimized rendering pipeline with proper blending support
- **VCOUNT Caching** - Reduced register reads for better performance
- **BG Register Caching** - Cached background scroll and control registers  
- **Window Coordinate Caching** - Optimized window clipping calculations
- **Layer Merge Optimizations** - Intelligent layer combining (disabled by default due to compatibility)

### 🎵 Enhanced Audio Performance for Pokemon ROM Hacks
- **FAST_AUDIO_MODE** - Enabled for performance-critical audio processing
- **Volume Calculation Caching** - Cached volume computations to reduce multiplications per sample
- **Early Exit Optimizations** - Skip processing for minimal sample counts
- **Performance Mode Flag** - `audio_performance_mode` for heavy audio games like Pokemon Unbound
- **Optimized for Pokemon ROM Hacks** - Significant performance improvements for Pokemon Unbound, Radical Red, and similar audio-heavy games

### ⚡ PSP Media Engine (ME) Integration (PLANNED)

FrogGBA includes framework support for the **PSP Media Engine** to offload background processing tasks. The ME integration is currently disabled by default but the infrastructure is in place.

#### ME Library Support (Framework Ready)
- **Library**: [psp-media-engine-custom-core](https://github.com/mcidclan/psp-media-engine-custom-core)
- **Purpose**: Utilize PSP's secondary 333MHz MIPS core for parallel processing  
- **Integration**: Background tasks only - no real-time audio/video processing
- **Status**: Framework implemented, ME features currently disabled pending further testing

#### ME-Accelerated Features (Framework Ready)

**1. Save State Compression (Planned)**
- **Asynchronous compression** during save operations using ME
- **Asynchronous decompression** during load operations
- **RLE compression** to reduce save file sizes
- **Backwards compatibility** with uncompressed save states
- **Automatic fallback** to CPU when ME unavailable

**2. Color Correction LUT Generation (Planned)**
- **Accelerated computation** of 32K color lookup tables
- **Parallel processing** of GPSP and Retro color modes
- **Background generation** during emulator startup
- **No blocking** of main emulation thread

#### ME Control Options
- **ME Engine Setting**: Menu option with Auto/Disabled/Enabled states
  - **Auto**: Attempts to initialize ME, falls back to CPU if unavailable
  - **Disabled**: Forces ME features off, uses CPU for all processing
  - **Enabled**: Tries to force ME on, shows warning if unavailable

#### ME Usage Notes
- **Framework Complete**: All ME integration code is implemented
- **Currently Disabled**: ME features disabled by default pending further testing
- **Graceful Degradation**: Full functionality without ME library
- **No Timing Issues**: Only background processing, no real-time synchronization
- **Memory Safe**: Proper cleanup and error handling

### 🎮 Game Configuration System
- **Per-Game Settings** - Automatic game detection via ROM header analysis
- **Per-game configuration files** stored in `game_config.txt` format
- **Customizable settings** per ROM including frame skip, audio, video optimizations, and controls
- **Game-specific optimizations** for better compatibility with ROM hacks

### Installation & ME Support

#### Standard Installation
1. Download FrogGBA release
2. Extract to PSP memory stick
3. Run normally - all optimizations work without ME

#### Building with ME Acceleration  
The ME library is included as a git submodule for easy building:

```bash
# Clone with submodules
git clone --recursive https://github.com/yourusername/FrogGBA.git

# Or if already cloned, initialize submodules
git submodule update --init --recursive

# Build normally - ME library will be linked automatically
make
```

The psp-media-engine-custom-core library is automatically included during compilation when the submodule is present.

### Performance Impact Summary
- **Pokemon ROM Hacks**: Major audio performance improvements (Pokemon Unbound now runs smoothly)
- **Auto Resume**: Fixed freeze issues when loading save states on boot
- **Recent Games**: Path doubling bug fixed, games load correctly on first attempt  
- **State Management**: Improved timing for auto-save/resume prevents emulation freezes
- **Smart Fallback**: All features work without additional libraries

## Original TempGBA Features

- Added gpsp kai's cheats function
- Added Chinese language support  
- Added restore function
- New menu icon
- Imported code from TempGBA-mod-dstwo-26750220
- Modern PSP SDK compatibility
- Docker-based build system
