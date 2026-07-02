# ToadGBA — TempGBA/FrogGBA mod by AlfonsoVM

> **ToadGBA** is a fork of [FrogGBA](https://github.com/tzubertowski/FrogGBA) for PSP.
> It extends FrogGBA's color correction and aspect ratio work with GPU-accelerated
> filters, deeper image controls, and a range of correctness and performance fixes.

## Download & Installation
![ToadGBA Icon](source/res/ICON0.png)

**→ [Download the latest release here](https://github.com/AlfonsoVM/ToadGBA/releases) ←**

You need custom firmware (CFW) on your PSP (e.g. CFW 6.61 LME or PRO-C2).

The release contains two files: `EBOOT.PBP` and `ToadGBA.prx`.

1. On your PSP memory card, create the folder **`/PSP/GAME/ToadGBA/`** if it doesn't exist.
2. Copy both `EBOOT.PBP` and `ToadGBA.prx` into that folder.
3. Eject the memory card and insert it into your PSP (or reconnect USB).
4. Launch **ToadGBA** from the XMB game menu under *Game → Memory Stick*.

> **Updating from a previous version?** Just overwrite `EBOOT.PBP` and `ToadGBA.prx`
> in the same folder. Your saves, settings and overlays are kept separately and
> won't be affected.

---

## What ToadGBA adds over FrogGBA

### Visual filters
- **Sharp Bilinear filter** — two-pass GPU filter: nearest-neighbor 2× upscale into an
  intermediate buffer, then bilinear scaling to the display. Crisp pixels at any scale,
  zero CPU cost. (FrogGBA had no sharpening filter.)
- **LCD grid filter** — simulates the GBA pixel grid (Off / Subtle / Full GBA), rendered
  entirely on the GPU as a screen-space overlay.

### New color modes
- **AGS-101** — replicates the backlit GBA SP screen.
- **LCD Dim** — simulates the original dark GBA LCD.
  (FrogGBA had GPSP and Retro modes; AGS-101 and LCD Dim are ToadGBA additions.)

### Extended image controls
- Brightness, **Contrast**, **Saturation**, **Color Temperature**, and
  **per-channel RGB gain** — all tunable from the menu with LUT-based rendering
  so there is no per-frame CPU cost.

### New aspect ratio
- **4:3 pillarbox** — displays the GBA image at exact 4:3 proportions with black bars,
  no distortion. (FrogGBA had Core/3:2, Zoom, and Stretch.)

### Frameskip
- **SMART frameskip mode** — predictive frameskip with a debt accumulator that
  eliminates the 30 FPS oscillation found in FrogGBA's reactive AUTO mode.

### Browser
- **Show current directory** in the Directories menu path display.

### Performance fixes
- Replaced full `DcacheWritebackAll()` flushes with targeted
  `sceKernelDcacheWritebackRange()` scoped to the exact texture region.
- Removed `PSP_REDUCE_CACHE_INVALIDATION` — it masked a JIT stale-code bug.
- Removed JIT cache pre-warm at startup (no-op on PSP uncached VRAM).
- Replaced per-sample ring-buffer loop in `fill_sound_buffer()` with a
  two-segment `memcpy` approach.
- Reordered `obj_priority_list` from `[priority][scanline]` to
  `[scanline][priority]` for sequential access in the hot rendering loop.
- Eliminated redundant IO register reads in per-scanline hotpaths.
- Replaced per-pixel VRAM write loops with `u32`-pair writes and `memcpy`.
- LUT-based color correction hot path (u32 pairs, per-channel LUTs, prefetch).

### Bug fixes
- **Timer prescale corruption** — `timer_control_low()` read the old prescale before
  the write for timers 2–3, corrupting audio in games using cascaded timers.
- **GBC stereo panning** — left/right channels were swapped in `RENDER_SAMPLE_BOTH`.
- **Sound thread wakeup delay** — removed a stale 100 µs sleep after thread wake.
- **`affine_render_scale_pixel` tile-pointer cache** — the cache was nullified at
  the end of each cached iteration, negating the optimization.
- **`psp_fclose` stale handle** — the caller's handle was not zeroed after close,
  enabling use-after-close.
- **Write-buffer SYNC** — restored the CPU write-buffer drain before GE texture reads
  to prevent the GE racing a partially-written frame.
- **Sharp Bilinear menu flicker** in pillarbox mode.

### Dead code removal
- Scale2x filter (CPU-heavy, replaced by Sharp Bilinear).
- CPU sharpness filter (per-pixel VRAM reads, too slow on PSP).
- Incomplete layer-merge system (slower than baseline in all tests).
- `cpu_common.c` (duplicate of `cpu.c` definitions).
- `PSP_REDUCE_CACHE_INVALIDATION` flag (masked a correctness bug).
- JIT pre-warm at startup (no effect on uncached VRAM).
- `-funsafe-loop-optimizations` from CFLAGS (risks silent mis-compilation).

---

## Inherited from FrogGBA

The following features were already present in FrogGBA and are included unchanged
(or with minor fixes) in ToadGBA.

### Overlay system
- Full-screen PNG bezel/border support via `.ovl` files.
- RLE compression for pixel-dense designs.
- X/Y offset controls to reposition the game window.
- Up to 10 overlay slots, switchable from the menu.
- Online converter at [toadgba.onrender.com](https://toadgba.onrender.com).

### Performance
- **gpSP Kai engine optimizations** — static translation caches, reduced cache
  invalidation, optimized tile rendering pipeline.
- **Multi-layer Mode 0 fix** — 4-layer rendering bottleneck resolved; Castlevania
  water sections went from 15–20 FPS to 30+ FPS.
- **Memory management** — 2 MB ROM cache, 256 KB RAM cache.
- **Volatile memory support** — uses extra PSP RAM on all models.

### Color correction
- GPSP mode and Retro mode with optimized lookup tables.

### Aspect ratio modes
- Core (3:2 GBA native), Zoom (fill screen vertically), Stretch (fill 480×272).

### Quality of life
- Recent Games menu (last 10 played titles).
- Fast-forward (SELECT + R, 2×/3× speed).
- Turbo buttons (Triangle and Square).
- ROM validation before load.
- Clean exit (no BSOD on emulator quit).
- Save/load state with auto menu close and file validation.
- FPS display toggle (SELECT + Square).

---

## Acknowledgements

ToadGBA stands on the shoulders of:

- **[gpSP](https://github.com/HACKERCHANNEL/gpsp)** by *Exophase* — the original
  GBA emulator for PSP and the foundation for everything that followed.
- **[gpSP Kai](https://github.com/uofw/gpsp)** by *takka* — the definitive
  performance and compatibility fork that pushed PSP GBA emulation to its limits.
- **[TempGBA](https://github.com/Nebuleon/TempGBA)** by *Nebuleon*, *Normmatt*,
  and *BassAceGold*, and **TempGBA4PSP-mod** — the codebase both FrogGBA and
  ToadGBA are built on.
- **[FrogGBA](https://github.com/tzubertowski/FrogGBA)** by *tzubertowski* — the
  direct parent of ToadGBA; contributed the overlay system, gpSP Kai engine
  integration, color correction (GPSP/Retro), aspect ratio modes (Core/Zoom/Stretch),
  Recent Games menu, and stability fixes that ToadGBA builds on.

---

## Building from Source

Requires Docker:

```bash
docker-compose run --rm psp-dev
```

Output files appear in `build/`. Copy `EBOOT.PBP` to `/PSP/GAME/ToadGBA/` on your
memory card.

---

## Custom Overlays

1. Visit **[toadgba.onrender.com](https://toadgba.onrender.com)** and upload a
   480×272 PNG (transparent center = game area, opaque edges = bezel).
2. Download the generated `.ovl` file.
3. Copy it to `/PSP/GAME/ToadGBA/overlays/` on your memory card.
4. In-game: **HOME → Overlay Settings** → select and enable.

---

## Technical Notes for Developers

### Sharp Bilinear Filter (GPU, two-pass)

**Goal:** replace the CPU `apply_pixel_double()` loop with a GPU equivalent.

The old path wrote ~384 KB of data to VRAM per frame: for each of 160 GBA rows
it read the source scanline, built a u32-packed doubled row in a stack buffer,
and did two `memcpy` calls into `scale2x_buffer`. At PSP memory bandwidth this
cost ~0.5–2 ms per frame and was perceptible on slower titles.

**New pipeline:**

```
screen_texture (240×160, VRAM)
  → Pass 1: GE nearest-neighbor upscale → scale2x_buffer (480×320, VRAM)
  → Pass 2: GE bilinear render          → framebuffer (display rect)
```

Both passes are separate `GU_DIRECT` submissions separated by `sceGuSync()`.
The sync is mandatory: a single display list with `sceGuTexFlush()` between
the two draws is insufficient on PSP — the GE rasterizer and texture unit can
pipeline such that Pass 2 reads `scale2x_buffer` before Pass 1 finishes
writing it.

**VRAM layout:**

```
VRAM 0x4000000
  + 0x00000  FB0  (512×272×2 = 0x44000)
  + 0x44000  FB1  (0x44000)
  + 0x88000  screen_texture  (256×256×2 = 0x20000)
  + 0xA8000  scale2x_buffer  (512×320×2 = 0x50000)
```

`scale2x_buffer` has stride 512 so the GE can address it as a 512×512
power-of-two texture in Pass 2: `sceGuTexImage(0, 512, 512, 512, ...)`.

**Why `GU_DIRECT`, not `GU_CALL`, for Pass 1:**

An earlier version pre-built Pass 1 as a static `GU_CALL` list built once at
init. This caused a persistent double-image/flicker artifact. The root cause:
`sceGuDrawBuffer()` inside a `GU_CALL` sub-list is non-standard on PSP — every
PSP render-to-texture example uses a dedicated `GU_DIRECT` submission for the
write-to-offscreen pass. Moving Pass 1 inline into `bitbilt_gu()` as a
`GU_DIRECT` list fixed the artifact completely.

**Screen-texture dcache flush:**

```c
sceKernelDcacheWritebackRange(screen_texture,
    GBA_SCREEN_HEIGHT * GBA_LINE_SIZE * sizeof(u16));
```

Emits a MIPS SYNC that drains the GBA renderer's CPU write buffer before the
GE DMA reads `screen_texture`. Without it the GE can race the CPU and display
a partially-written frame.

---

### LCD Grid Filter (GPU screen-space)

The grid filter draws darkened horizontal (and optionally vertical) strips over
the framebuffer in PSP screen space, simulating a GBA LCD pixel grid.

Pre-built `GU_CALL` list containing thin `GU_SPRITES` quads covering the display
rectangle, rendered with `GU_BLEND` multiply mode. Vertices are cached and only
rebuilt on display-mode change — zero per-frame CPU cost. The old implementation
was a CPU per-pixel VRAM loop.

---

### Color Correction (LUT-based hot path)

Three-tier approach applied during `apply_pixel_double()`:

1. **u32-pair inner loop** — two adjacent pixels per iteration, halving memory
   bandwidth.
2. **Per-channel LUTs** — 32-entry tables (one per RGB channel) encoding
   brightness, contrast, saturation, color temperature, and per-channel gain in
   a single indexed lookup (3 table reads instead of 6–8 arithmetic ops per pixel).
3. **Prefetch** — `__builtin_prefetch` on the next pixel pair keeps the LUT hot
   in L1 cache.

The combined LUT is rebuilt by `rebuild_color_lut()` on any option change;
per-frame cost is zero.

---

### Targeted dcache Flushes

Replaced `sceKernelDcacheWritebackAll()` with `sceKernelDcacheWritebackRange()`
scoped to the exact texture region. The PSP dcache is 16 KB; a full flush evicts
JIT and audio working data every frame.

---

### PSP_REDUCE_CACHE_INVALIDATION Removed

This flag reduced JIT cache invalidation aggressiveness to hide a stale-code bug.
Removing it restored correct invalidation. The performance cost was negligible
since the flag was only effective paired with a larger JIT cache than TempGBA
allocated.

---

### Timer Prescale Fix (Timers 2–3)

`timer_control_low()` read `timer_prescale[n]` before the write that updated it,
then stored the old value back. For timers 2 and 3 this corrupted the prescale
on every write, causing audio drift in games with cascaded timers. Fixed by
storing the prescale only after reading the new register value.

---

### GBC Stereo Panning Fix

`RENDER_SAMPLE_BOTH` applied left gain to the right output and right gain to the
left output. Fixed by matching channel index to the correct output side.

---

### `fill_sound_buffer()` Linear-Segment Rewrite

Replaced a per-sample ring-buffer loop with a two-segment approach that computes
the contiguous regions and issues at most two `memcpy` calls per fill.

---

### `obj_priority_list` Cache-Locality Fix

Transposed from `[priority][scanline]` to `[scanline][priority]` so the hot
rendering loop (which iterates by scanline) accesses memory sequentially.

---

### `affine_render_scale_pixel` Tile-Pointer Cache Fix

The cached `tile_ptr` was overwritten with `NULL` at the end of each cached
iteration, nullifying the cache on the very next call. Fixed by preserving the
pointer until the tile index actually changes.

---

### `psp_fclose` Handle Nulling

`psp_fclose()` did not set `*filename_tag = -1` after closing. Any code that
checked the handle afterward saw a stale valid-looking value and could
double-close or use-after-close. Fixed by zeroing the caller's handle
unconditionally.

---

### SMART Frameskip

AUTO mode compared the previous frame's real time against the VBlank period and
skipped the next frame if behind — producing a 30 FPS oscillation (skip → catch
up → skip ...). SMART mode adds a debt accumulator: excess latency is paid off
gradually over multiple frames rather than triggering a skip immediately.
