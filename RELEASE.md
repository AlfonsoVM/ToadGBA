# 🐸 ToadGBA v0.2.4 – Critical Fixes & Game Resume

![toadgba24](https://github.com/user-attachments/assets/placeholder-image.png)

Critical update fixing major visual rendering issues and introducing convenient game resume functionality. This release prioritizes accuracy and user experience over raw performance.

---

### 📥 Install in 4 Steps

1. Download + unzip the release.
2. Copy the **PSP** folder to your Memory Stick root.
3. Drop `gba_bios.bin` into `PSP/GAME/ToadGBA/`.
4. Launch ToadGBA from your PSP Games menu (CFW required).

---

### 🆕 New in v0.2.4

* **Resume Game on Boot** – Automatically resume your last played game when starting the emulator for seamless gaming sessions.
* **Auto Save/Load States** – New automatic save state functionality with configurable intervals (1-30 minutes) to never lose progress.
* **Split Resume Options** – Resume feature now split into two separate configurable options for better control over your gaming experience.
* **Dedicated Saving Submenu** – Added organized submenu for all save-related settings and options.

### 🛠️ Critical Fixes

* **Fixed Water Transparency Issues** – Resolved major visual bugs causing water and transparent effects to show vertical stripes instead of smooth transparency.
* **Fixed Kirby Startup Logo** – Kirby's black startup logo now displays in proper colors thanks to corrected blending calculations.
* **Eliminated Green Flickering** – No more green blinking during black transition screens in Castlevania and other games.
* **Restored Visual Accuracy** – Disabled problematic optimizations that were causing widespread blending and alpha channel rendering issues.

---

### ⚠️ Performance Impact

* **Prioritized Accuracy** – Some optimizations were disabled to fix critical visual issues, resulting in slight performance reduction compared to v0.2.3.
* **Visual Quality First** – Games now render correctly with proper transparency and blending effects, even if slightly slower.
* **Stable Experience** – Rock-solid compatibility with correct sprite and background rendering across all tested games.

---

### 🎮 Retained Features

* **Configurable X/O Button Mapping** – Swap X and O button functions to match your preferences (from v0.2.3)
* **Recent Games Menu** – Quick access to your last played titles
* **Lightning-Fast Overlays** – Full-screen borders with zero performance impact
* **Custom Overlay Support** – Up to 10 designs with pixel-perfect positioning
* **Online Overlay Generator** – Create your own at [toadgba.onrender.com](https://toadgba.onrender.com)
* **Multiple Aspect Ratios** – Choose your preferred display mode
* **Fast Color Correction** – Hardware-accelerated color processing

---

### 🧠 Technical Details

* **Disabled Tile Base Caching** – Reverted to direct tile calculation to fix transparency issues
* **Removed VCOUNT Caching** – All vertical counter reads now access register directly for accurate timing
* **Conservative Sprite Clearing** – Restored simple memset() approach for reliable sprite rendering
* **Disabled Fast Path Optimizations** – Prioritized accuracy over performance for consistent visual output
* **Enhanced Auto-Save System** – Robust state management with configurable timing intervals

---

### 🐛 Bug Fixes

* **Critical Blending Fix** – Water and transparent effects now render correctly without vertical stripe artifacts
* **Alpha Channel Correction** – Fixed black sprites and logos appearing due to broken alpha blending
* **Transition Screen Fix** – Eliminated green flickering during fade effects in various games
* **Simplified FPS Display** – Removed problematic sprite counter that was incrementing infinitely
* **Clean Release Build** – Removed all debug logging for production-ready performance

---

### 💚 Compatibility

* Works on all PSP models (1000/2000/3000/Go)
* CFW required (any modern CFW works)
* Based on heavily modified TempGBA4PSP with gpSP Kai optimizations

---

**TL;DR:** ToadGBA v0.2.4 fixes critical visual rendering issues that were causing broken transparency and blending effects. Now includes convenient resume-on-boot and auto-save features for the best user experience. Visual accuracy is prioritized over raw performance. 🐸🎯

---

### Credits

* Original gpSP by Exophase
* gpSP Kai optimizations by takka
* TempGBA4PSP base
* ToadGBA improvements by the community

GPL v2+ Licensed