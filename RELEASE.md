# 🐸 FrogGBA v0.3.0 – Enhanced Auto-Resume & Game Configuration System

Major stability update with improved auto-resume functionality, per-game configuration system, and comprehensive bug fixes. This release focuses on reliability and user experience improvements.

---

### 📥 Install in 4 Steps

1. Download + unzip the release.
2. Copy the **PSP** folder to your Memory Stick root.
3. Drop `gba_bios.bin` into `PSP/GAME/FrogGBA/`.
4. Launch FrogGBA from your PSP Games menu (CFW required).

---

### 🆕 New in v0.3.0

#### 🎮 Game Configuration System
* **Per-Game Settings** – Automatic game detection via ROM header analysis
* **Customizable Configurations** – Per-ROM settings for frame skip, audio, video optimizations, and controls
* **Game-Specific Optimizations** – Better compatibility with ROM hacks and homebrew games
* **Persistent Per-Game Config** – Settings automatically saved and restored for each game

#### 🔧 Enhanced Auto-Resume System
* **Fixed Resume Freezing** – Completely resolved auto-resume freeze issues that occurred with games like Castlevania and Advance Wars
* **Improved State Loading** – Auto-save states now load immediately after reset for seamless gameplay
* **Hidden Slot 11** – Uses invisible save slot 11 for auto-resume functionality without interfering with user saves
* **Timing Optimization** – Fixed state loading timing to prevent emulation hangs

#### 📂 Recent Games Improvements  
* **Path Doubling Fix** – Recent games now load correctly on first attempt (previously required two tries)
* **Absolute Path Detection** – Improved handling of PSP absolute paths vs relative paths
* **Instant Loading** – Recent games launch immediately without file-not-found errors

### 🛠️ Critical Fixes

#### 🎯 Auto-Resume Stability
* **Fixed Auto-Resume Freeze** – Games no longer freeze when loading save states on boot
* **Resolved White Screen Issue** – Auto-resume now properly starts gameplay instead of showing blank screen  
* **State Loading Timing** – Fixed emulation context issues when loading states during startup
* **CPU State Restoration** – Proper CPU register restoration after state loads

#### 📁 File System Improvements
* **Recent Games Path Fix** – Fixed path doubling bug that caused "file not found" errors on first load attempt
* **PSP Path Detection** – Better handling of ms0:/ and host0:/ absolute paths vs relative paths
* **Load Path Resolution** – Improved path construction for both recent games and manual file selection

#### 🏗️ Repository Cleanup  
* **Submodule Integration** – Added psp-media-engine-custom-core as proper git submodule
* **Removed Duplicate Code** – Cleaned up 81,000+ lines of redundant reference code from repository
* **Better Dependency Management** – Streamlined build process with automatic ME library inclusion

---

### ⚡ Performance & Stability

* **Enhanced Reliability** – Fixed critical auto-resume and path handling bugs that caused crashes and hangs
* **Improved User Experience** – Games now resume seamlessly without freeze or white screen issues  
* **Cleaner Codebase** – Repository cleanup reduces compilation time and improves maintainability
* **Better File Management** – Resolved file loading issues that required multiple attempts to load games

---

### 🎮 Enhanced Features

#### 💾 Save & Resume System
* **Auto Save/Load States** – Automatic save state functionality using hidden slot 11
* **Resume Game on Boot** – Automatically resume your last played game when starting the emulator  
* **Recent Games Menu** – Quick access to your last played titles (now works reliably on first try)
* **Configurable Resume Options** – Choose between resume last game, load last save state, or both

#### 🎨 Visual & Controls
* **Configurable X/O Button Mapping** – Swap X and O button functions to match your preferences
* **Lightning-Fast Overlays** – Full-screen borders with zero performance impact
* **Custom Overlay Support** – Up to 10 designs with pixel-perfect positioning
* **Online Overlay Generator** – Create your own at [froggba.onrender.com](https://froggba.onrender.com)
* **Multiple Aspect Ratios** – Choose your preferred display mode
* **Fast Color Correction** – Hardware-accelerated color processing

#### 🔧 Advanced Options
* **ME Engine Control** – Menu option for PSP Media Engine features (Auto/Disabled/Enabled)
* **Per-Game Configurations** – Automatic ROM detection with customizable settings per game
* **Debug Logging** – Optional froglog.txt for troubleshooting (can be enabled when needed)

---

### 🧠 Technical Details

#### 🎯 Auto-Resume Architecture
* **Immediate State Loading** – Auto-save states load immediately after reset instead of delayed loading
* **Skip Execution Path** – Resume on boot bypasses normal loading flow to prevent conflicts
* **CPU Context Management** – Proper PC status flags and register restoration after state loads
* **Hidden Slot Implementation** – Uses slot 11 (invisible to users) for seamless auto-resume functionality

#### 📁 Path Resolution System
* **Absolute Path Detection** – Improved detection of PSP device paths (ms0:/, host0:/) vs relative paths
* **Path Construction Logic** – Smart path building that avoids doubling directory paths
* **Recent Games Integration** – Fixed path handling for games launched from recent games menu

#### 🏗️ Development Infrastructure  
* **Git Submodule Integration** – PSP Media Engine library now properly managed as submodule
* **Repository Cleanup** – Removed 81,000+ lines of redundant reference code
* **Build System Improvements** – Streamlined compilation with automatic dependency inclusion
* **Enhanced Debug Framework** – Comprehensive logging system for troubleshooting complex issues

---

### 🐛 Bug Fixes

#### 🎮 Gameplay Issues Resolved
* **Auto-Resume Freeze Fix** – Games like Castlevania and Advance Wars no longer freeze when auto-loading save states
* **Recent Games Loading Fix** – Games now load successfully on first attempt instead of requiring multiple tries
* **White Screen Resolution** – Fixed auto-resume causing blank screens instead of proper gameplay  
* **State Loading Context** – Resolved emulation hangs when loading states during startup sequence

#### 📂 File System Fixes
* **Path Doubling Prevention** – Eliminated ms0:/PSP/GAME/FrogGBA/roms/ being added twice to file paths
* **Absolute Path Handling** – Proper detection and handling of PSP device paths vs relative filenames
* **Recent Games Path Correction** – Fixed path construction for games stored in recent games menu

#### 🔧 Development & Build Fixes  
* **Submodule Integration** – Proper git submodule setup for psp-media-engine-custom-core dependency
* **Compilation Dependencies** – ME library now automatically included when submodule is present
* **Repository History Cleanup** – Removed duplicate/reference code that was bloating the repository

---

### 🛠️ Building from Source (New!)

FrogGBA now uses proper git submodules for easy building:

```bash
# Clone with submodules
git clone --recursive https://github.com/yourusername/FrogGBA.git
cd FrogGBA

# Build with Docker (recommended)
./build.sh

# Or build manually if you have PSP SDK installed
cd source
make
```

The PSP Media Engine library is automatically included as a submodule, eliminating the need for manual dependency setup.

---

### 💚 Compatibility

* Works on all PSP models (1000/2000/3000/Go)
* CFW required (any modern CFW works)  
* Based on heavily modified TempGBA4PSP with gpSP Kai optimizations
* Repository now properly structured with git submodules for dependencies

---

**TL;DR:** FrogGBA v0.3.0 delivers major stability improvements with fixed auto-resume functionality, resolved recent games loading issues, and a new per-game configuration system. No more freezes, white screens, or file-not-found errors. Enhanced repository structure with proper submodule management for easier building and maintenance. 🐸🎯

---

### Credits

* Original gpSP by Exophase
* gpSP Kai optimizations by takka
* TempGBA4PSP base
* FrogGBA improvements by the community

GPL v2+ Licensed