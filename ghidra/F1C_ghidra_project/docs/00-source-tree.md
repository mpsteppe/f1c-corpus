# F1 Challenge 99-02 — Reconstructed Source Tree

*Merged from 3 worker(s) on 2026-07-15.*


## Directory Structure

<!-- from worker_A.md -->
```
D:\dev\
├── AudioDev\Shared\Engine\Dev\
│   └── LbMpeg.cpp                        (3 funcs, 0x0052da30–0x0052e2e8)
└── F1_1999_2002\Source\
    ├── O_AppGz.cpp                       (1 func, 0x0046de10–0x0046e169)  [IDA-only]
    ├── Replay.cpp                        (1 func, 0x004ba1f0–0x004ba45e)
    ├── ai_db.cpp                         (1 func, 0x004024f0–0x0040268e)
    ├── config.cpp                        (1 func, 0x00421cd0–0x00422bdf)
    ├── game.cpp                          (9 funcs, 0x0042cf10–0x0042dbcb)
    ├── garage.cpp                        (1 func, 0x0042fd00–0x004305e4)
    ├── htree.cpp                         (1 func, 0x00449a80–0x00449eb3)
    ├── hwinput.cpp                       (1 func, 0x00455bf0–0x00455c59)
    ├── options.cpp                       (1 func, 0x004a0eb0–0x004a0fad)
    ├── osman.cpp                         (1 func, 0x004a18d0–0x004a192a)
    ├── plrfile.cpp                       (5 funcs, 0x004b0770–0x004b194b)
    ├── render.cpp                        (1 func, 0x004b4030–0x004b405d)
    ├── setup.cpp                         (4 funcs, 0x004c3200–0x004c54ea)
    ├── specialfx.cpp                     (10 funcs, 0x004ca480–0x004d001d)
    ├── tire_manager.cpp                  (1 func, 0x004d5ee0–0x004d5f69)
    ├── vehgfx.cpp                        (2 funcs, 0x004ddf90–0x004e07f6)
    ├── vidman.cpp                        (7 funcs, 0x004f9310–0x004fad7d)
    └── weather.cpp                       (1 func, 0x004fe820–0x004fea97)
```

---

<!-- from worker_B.md -->
```
D:\dev\F1_1999_2002\Source\
  ├── NetComm.cpp          (16 functions, 0x0045d890—0x00464290, ~69KB)
  ├── O_BaseGz.cpp          (1 function,  0x0048e8d0,               ~1.4KB)
  ├── Replay.cpp            (1 function,  0x004ba1f0,               ~2.7KB)
  ├── camera.cpp            (3 functions, 0x0040c920—0x0040cce0,    ~2.3KB)
  ├── dynman.cpp            (6 functions, 0x0042c130—0x0042ca70,    ~5.5KB)
  ├── hdvehicle.cpp         (5 functions, 0x00439210—0x0043da10,    ~98KB)
  ├── htree.cpp             (1 function,  0x00449a80,               ~7.1KB)
  ├── onscreen.cpp          (6 functions, 0x0049ef40—0x0049f120,    ~2.3KB)
  ├── options.cpp           (1 function,  0x004a0eb0,               ~1.2KB)
  ├── pitcrew.cpp           (3 functions, 0x004a2010—0x004a2a90,    ~17KB)
  ├── plrfile.cpp           (5 functions, 0x004b0770—0x004b1900,    ~8KB)
  ├── searchgrid.cpp        (1 function,  0x004bdc10,               ~2.3KB)
  ├── sound.cpp             (6 functions, 0x004c8a20—0x004c8d00,    ~2.6KB)
  ├── steward.cpp           (6 functions, 0x004d0110—0x004d4600,    ~46KB)
  ├── util.cpp              (1 function,  0x004dc770,               ~2.7KB)
  ├── vehload.cpp           (3 functions, 0x004f3240—0x004f4270,    ~52KB)
  └── vidman.cpp            (7 functions, 0x004f9310—0x004fad00,    ~15KB)
```

---

<!-- from worker_C.md -->
```
D:\dev\F1_1999_2002\Source\
  ├── NetComm.cpp              (1 function, 0x00463160)
  ├── O_BaseGz.cpp             (1 function, 0x0048e8d0)
  ├── ai_db.cpp                (2 functions, 0x004024f0–0x004040a0)
  ├── camera.cpp               (1 function, 0x0040c920)
  ├── dynman.cpp               (1 function, 0x0042c130)
  ├── garage.cpp               (1 function, 0x0042fd00)
  ├── hdvehicle.cpp            (1 function, 0x00439210)
  ├── hwinput.cpp              (6 functions, 0x00455bf0–0x00455f00)
  ├── onscreen.cpp             (1 function, 0x0049ef40)
  ├── osman.cpp                (2 functions, 0x004a18d0–0x004a1930)  [see note]
  ├── pitcrew.cpp              (1 function, 0x004a2010)
  ├── render.cpp               (3 functions, 0x004b4030–0x004b4170)
  ├── searchgrid.cpp           (1 function, 0x004bdc10)
  ├── sound.cpp                (1 function, 0x004c8a20)
  ├── tire_manager.cpp         (7 functions, 0x004d5ee0–0x004d7880)
  ├── util.cpp                 (1 function, 0x004dc770)
  ├── vehload.cpp              (1 function, 0x004f3240)
  └── weather.cpp              (1 function, 0x004fe820)

Additional: game.cpp               (1 function, 0x0042db20 — misattributed to osman.cpp)
```

## Source File Details

### AudioDev/Shared/Engine/Dev/LbMpeg.cpp

External audio library — MPEG (MP2/MP3) streaming layer.
Source: `D:\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp` (external to F1 source tree)

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_0052da30 | 0x0052da30 | 599 | `CMpegBase::ProcessHeader()` — parses MPEG frame header, validates bit rate |
| FUN_0052e090 | 0x0052e090 | 209 | `CMpegBase::Open()` — opens MPEG stream, calls `GetHeader()` |
| FUN_0052e1d0 | 0x0052e1d0 | 280 | `CMpegFilePlayer::Open()` — file player open with two-stage header validation |

- **Address range:** 0x0052da30 — 0x0052e2e8
- **Estimated total functions:** 3 (all accounted)
- **Gap between 0x0052dc87 and 0x0052e090:** 0x409 bytes (likely functions in LbMpeg.cpp not captured by assert strings, or inlined)

---

### F1_1999_2002/Source/O_AppGz.cpp

Application-level GZip compression wrapper.
Source: `D:\dev\F1_1999_2002\Source\O_AppGz.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| sub_46DE10 | 0x0046de10 | 857 | Decompression routine — reads float at +0xE4, calls virtual function table dispatch |

- **Address range:** 0x0046de10 — 0x0046e169
- **Source:** IDA Hex-Rays decompilation (not in Ghidra function_sizes.csv)
- **Estimated total functions:** 1+ (only 1 found; likely more inlined or path-less)

---

### F1_1999_2002/Source/Replay.cpp

VCR (replay) file playback system.
Source: `D:\dev\F1_1999_2002\Source\Replay.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004ba1f0 | 0x004ba1f0 | 622 | "Prepping Replay" / "Loading VCR File for playback" — replay file load and prep |

- **Address range:** 0x004ba1f0 — 0x004ba45e
- **Estimated total functions:** 1+ (at minimum 1 lifecycle function found; `Replay.cpp` likely has Enter/Setup/Init/Post/Exit pattern)

---

### F1_1999_2002/Source/ai_db.cpp

AI database — driver ability, waypoint path handling.
Source: `D:\dev\F1_1999_2002\Source\ai_db.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004024f0 | 0x004024f0 | 414 | "Incomplete waypoint path" — validates waypoint path completeness for AI pathfinding |

- **Address range:** 0x004024f0 — 0x0040268e
- **Estimated total functions:** 1+ (ai_db.cpp is a large module; only 1 function has assert strings)

---

### F1_1999_2002/Source/config.cpp

Configuration file parser — reads Config.ini for version, IP, VCR settings.
Source: `D:\dev\F1_1999_2002\Source\config.cpp` (inferred; no assert string in decompiled output, but references Config.ini)

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_00421cd0 | 0x00421cd0 | 3855 | Main config parser — reads [VERSION], IPADDRESS, VCRFILE, VCRCYCLE from Config.ini |

- **Address range:** 0x00421cd0 — 0x00422bdf
- **Estimated total functions:** 1 (large single function; likely config loading only)

---

### F1_1999_2002/Source/game.cpp

Core game state machine — Enter/Setup/Init/Restart/Post/Exit lifecycle.
Source: `D:\dev\F1_1999_2002\Source\game.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_0042cf10 | 0x0042cf10 | 557 | "Multiplayer mode: setting vehicle places for RACE" — multiplayer grid setup |
| FUN_0042d260 | 0x0042d260 | 232 | "No vehicle files found" / "No scene files found" — validation check |
| FUN_0042d370 | 0x0042d370 | 604 | `Game::Enter()` — loads F1_2002.gdb, *.pit, *.rcd, enters game |
| FUN_0042d5d0 | 0x0042d5d0 | 209 | `Game::Setup()` — state machine transition to setup phase |
| FUN_0042d6b0 | 0x0042d6b0 | 233 | `Game::Init()` — state machine transition to init phase |
| FUN_0042d7a0 | 0x0042d7a0 | 243 | `Game::Restart()` — state machine transition to restart phase |
| FUN_0042d8a0 | 0x0042d8a0 | 399 | `Game::Post()` — state machine dispatch, reports unexpected states |
| FUN_0042da30 | 0x0042da30 | 231 | `Game::Post()` continuation — state = 6 |
| FUN_0042db20 | 0x0042db20 | 171 | `Game::Exit()` — state machine transition to exit phase |

- **Address range:** 0x0042cf10 — 0x0042dbcb
- **Total attributed:** 2879 bytes across 9 functions
- **Estimated total functions:** 12–15 (~3–6 inlined or path-less lifecycle helpers)
- **Gaps:**
  - 0x0042d13d → 0x0042d260: **291 bytes** (likely inlined/gap functions)
  - 0x0042d348 → 0x0042d370: 40 bytes
  - 0x0042d5cc → 0x0042d5d0: 4 bytes (padding)
  - 0x0042d799 → 0x0042d7a0: 7 bytes
  - 0x0042db17 → 0x0042db20: 9 bytes

---

### F1_1999_2002/Source/garage.cpp

Garage/grid setup — car selection and configuration persistence.
Source: `D:\dev\F1_1999_2002\Source\garage.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_0042fd00 | 0x0042fd00 | 2276 | "Failed to open %s for writing" — garage file I/O, large function with config save/load |

- **Address range:** 0x0042fd00 — 0x004305e4
- **Estimated total functions:** 1+ (likely 3–5 lifecycle functions in garage.cpp)

---

### F1_1999_2002/Source/htree.cpp

Hierarchical transform tree — skeleton/blend shapes with Gaussian elimination for HAT (Homogeneous Affine Transform) polyfitting.
Source: `D:\dev\F1_1999_2002\Source\htree.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_00449a80 | 0x00449a80 | 1075 | "Gaussian elimination for HAT poly failed" — transform tree solving with fallback retry |

- **Address range:** 0x00449a80 — 0x00449eb3
- **Estimated total functions:** 1+ (htree is large; likely 5–10 transform-related functions)

---

### F1_1999_2002/Source/hwinput.cpp

Hardware input — direct input device initialization.
Source: `D:\dev\F1_1999_2002\Source\hwinput.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_00455bf0 | 0x00455bf0 | 105 | `HWInput::Enter()` — hardware input lifecycle enter |

- **Address range:** 0x00455bf0 — 0x00455c59
- **Estimated total functions:** 1+ (likely full lifecycle: Enter/Setup/Init/Restart/Post/Exit)

---

### F1_1999_2002/Source/options.cpp

Options/settings UI lifecycle.
Source: `D:\dev\F1_1999_2002\Source\options.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004a0eb0 | 0x004a0eb0 | 253 | `Options::Setup()` — options screen setup |

- **Address range:** 0x004a0eb0 — 0x004a0fad
- **Estimated total functions:** 1+ (full lifecycle expected)

---

### F1_1999_2002/Source/osman.cpp

OS Manager — app mutex, window management.
Source: `D:\dev\F1_1999_2002\Source\osman.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004a18d0 | 0x004a18d0 | 90 | `OSMan::Enter()` — creates app mutex ("_F1 Challenge 99-02_APP_MUTEX_"), enters OS manager |

- **Address range:** 0x004a18d0 — 0x004a192a
- **Estimated total functions:** 1+ (full lifecycle expected)

---

### F1_1999_2002/Source/plrfile.cpp

Player file — save/load career progress.
Source: `D:\dev\F1_1999_2002\Source\plrfile.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004b0770 | 0x004b0770 | 448 | "Attempting to save to %s" — player file save with rename retry |
| FUN_004b1820 | 0x004b1820 | 65 | `PlayerFile::Enter()` — lifecycle enter |
| FUN_004b1870 | 0x004b1870 | 84 | `PlayerFile::Setup()` — lifecycle setup |
| FUN_004b18d0 | 0x004b18d0 | 45 | `PlayerFile::Restart()` — lifecycle restart |
| FUN_004b1900 | 0x004b1900 | 75 | `PlayerFile::Post()` — lifecycle post |

- **Address range:** 0x004b0770 — 0x004b194b
- **Total attributed:** 717 bytes across 5 functions
- **Estimated total functions:** 6–8 (missing Init/Exit lifecycle functions)
- **Gap between 0x004b0930 and 0x004b1820:** **3824 bytes** — substantial gap, likely contains init/load/setup functions and helpers

---

### F1_1999_2002/Source/render.cpp

Renderer — rendering subsystem lifecycle.
Source: `D:\dev\F1_1999_2002\Source\render.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004b4030 | 0x004b4030 | 45 | `Render::Init()` — renderer initialization |

- **Address range:** 0x004b4030 — 0x004b405d
- **Estimated total functions:** 1+ (full lifecycle expected; most rendering code in vidman.cpp and other files)

---

### F1_1999_2002/Source/setup.cpp

Setup subsystem — scene/vehicle file discovery, season config.
Source: `D:\dev\F1_1999_2002\Source\setup.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004c3200 | 0x004c3200 | 1671 | "TrackLivery", "PitcrewLivery" — parses livery and driver/engine/class config |
| FUN_004c3d80 | 0x004c3d80 | 512 | "Failed reading data for %s" — reads *.veh vehicle files |
| FUN_004c40d0 | 0x004c40d0 | 355 | "Could not find %s" — path resolution with %scommon\%s fallback |
| FUN_004c52c0 | 0x004c52c0 | 554 | Scene validation — checks directories, reports "no scene files" errors |

- **Address range:** 0x004c3200 — 0x004c54ea
- **Total attributed:** 3092 bytes across 4 functions
- **Estimated total functions:** 6–10 (likely scene scanning, season config, track selection)
- **Gaps:**
  - 0x004c3887 → 0x004c3d80: **1273 bytes** (likely scene/track scanning functions)
  - 0x004c3f80 → 0x004c40d0: 336 bytes
  - 0x004c4233 → 0x004c52c0: **4237 bytes** (largest gap — likely multiple setup helpers)

---

### F1_1999_2002/Source/specialfx.cpp

Special effects — particle systems, terrain.ini rendering, cube maps, reaction effects.
Source: `D:\dev\F1_1999_2002\Source\specialfx.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004ca480 | 0x004ca480 | 2211 | Particle system parser — COLOR, DESTBLEND, ALPHAFADE, DEFORMABLE, BILLBOARDS, STAMPS, MTSFILE |
| FUN_004cada0 | 0x004cada0 | 302 | Blend mode parser — maps string names (SRCALPHA, DSTCOLOR, etc.) to enum values |
| FUN_004cb120 | 0x004cb120 | 966 | "CUBE Error: %s" — particle system creation with MTS/BMP fallback |
| FUN_004cdc70 | 0x004cdc70 | 262 | "Could not find track variable" — terrain.ini variable lookup |
| FUN_004cee90 | 0x004cee90 | 45 | `SpecialFX::Enter()` — lifecycle enter |
| FUN_004ceec0 | 0x004ceec0 | 45 | `SpecialFX::Setup()` — lifecycle setup |
| FUN_004cf070 | 0x004cf070 | 3061 | "CMAPS.MAS" / "REACTION" — cube map loading + reaction particle system, large function |
| FUN_004cfc90 | 0x004cfc90 | 45 | `SpecialFX::Restart()` — lifecycle restart |
| FUN_004cfed0 | 0x004cfed0 | 285 | `SpecialFX::Post()` — lifecycle post |
| FUN_004cfff0 | 0x004cfff0 | 45 | `SpecialFX::Exit()` — lifecycle exit |

- **Address range:** 0x004ca480 — 0x004d001d
- **Total attributed:** 7217 bytes across 10 functions
- **Estimated total functions:** 15–20 (many effect-specific functions without assert strings)
- **Major gaps:**
  - 0x004cad23 → 0x004cada0: contiguous
  - 0x004caece → 0x004cb120: **0x252 bytes** (594 bytes)
  - 0x004cb4e6 → 0x004cdc70: **0x278A bytes** (10,122 bytes) — **large gap** — likely contains multiple special effect render/update functions
  - 0x004cdd76 → 0x004cee90: **0x111A bytes** (4378 bytes)
  - 0x004ceeed → 0x004cf070: **0x183 bytes** (387 bytes)
  - 0x004cfc65 → 0x004cfc90: 0x2B bytes (padding)
  - 0x004cfcbd → 0x004cfed0: **0x213 bytes** (531 bytes)
  - 0x004cffed → 0x004cfff0: 3 bytes (padding)

---

### F1_1999_2002/Source/tire_manager.cpp

Tire manager — tire load factor physics.
Source: `D:\dev\F1_1999_2002\Source\tire_manager.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004d5ee0 | 0x004d5ee0 | 137 | "Tire load factor should be positive" — validates tire load factor parameter |

- **Address range:** 0x004d5ee0 — 0x004d5f69
- **Estimated total functions:** 1+ (tire_manager.cpp is a large physics module; likely 5–10 functions)

---

### F1_1999_2002/Source/vehgfx.cpp

Vehicle graphics — wheel/steering/tire rendering nodes.
Source: `D:\dev\F1_1999_2002\Source\vehgfx.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004ddf90 | 0x004ddf90 | 1519 | NOTSPIN, TEAMDIR, VEHDIR — vehicle graphics node parser, dash/team/vehicle directory resolution |
| FUN_004dfce0 | 0x004dfce0 | 2838 | WHEEL, CATSTEER, LFTIRE, RFTIRE, LRTIRE, RRTIRE — wheel/steering/tire hierarchy builder |

- **Address range:** 0x004ddf90 — 0x004e07f6
- **Total attributed:** 4357 bytes across 2 functions
- **Estimated total functions:** 5–8
- **Gap between 0x004de57f and 0x004dfce0:** **5985 bytes** — substantial gap, likely vehicle shadow/reflection/LOD nodes

---

### F1_1999_2002/Source/vidman.cpp

Video manager — Direct3D/CUBE scene rendering, full lifecycle.
Source: `D:\dev\F1_1999_2002\Source\vidman.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004f9310 | 0x004f9310 | 270 | "CUBE error : %s" — CUBE engine error wrapper |
| FUN_004fa000 | 0x004fa000 | 747 | `VidMan::Enter()` — "3DCONFIG.EXE", "No Device" — device check and enter |
| FUN_004fa2f0 | 0x004fa2f0 | 47 | `VidMan::Setup()` — lifecycle setup |
| FUN_004fa320 | 0x004fa320 | 792 | `VidMan::Init()` — "CUBE error loading scene file" — scene load |
| FUN_004fa640 | 0x004fa640 | 376 | `VidMan::Restart()` — lifecycle restart |
| FUN_004fac00 | 0x004fac00 | 248 | `VidMan::Post()` — lifecycle post |
| FUN_004fad00 | 0x004fad00 | 125 | `VidMan::Exit()` — lifecycle exit |

- **Address range:** 0x004f9310 — 0x004fad7d
- **Total attributed:** 2605 bytes across 7 functions
- **Estimated total functions:** 8–10
- **Gap between 0x004f941e and 0x004fa000:** **3042 bytes** — likely render device enumeration/setup functions

---

### F1_1999_2002/Source/weather.cpp

Weather system — writes weather configuration files.
Source: `D:\dev\F1_1999_2002\Source\weather.cpp`

| Function | Address | Size | Description |
|----------|---------|------|-------------|
| FUN_004fe820 | 0x004fe820 | 631 | "Could not write to file %s" — weather file write, likely saves weather config |

- **Address range:** 0x004fe820 — 0x004fea97
- **Estimated total functions:** 1+ (full lifecycle expected)

---

### NetComm.cpp
Network communication module — session management, player slot tracking, server
sync, autojoin, Internet/LAN updates.

- **Address range:** 0x0045d890 — 0x00464290 (~69KB total)
- **Functions attributed:** 16
- **Estimated functions total:** ~20 (some small helpers may lack assert strings)

| Address | Symbol | Name from strings | Lines |
|---------|--------|-------------------|-------|
| 0x0045d890 | FUN_0045d890 | NetComm message handler (huge switch on msg type) | 566 |
| 0x0045eb50 | FUN_0045eb50 | Find player name by nodeid | 27 |
| 0x0045ecd0 | FUN_0045ecd0 | (no assert string — adjacent, likely NetComm) | 137 |
| 0x0045f950 | FUN_0045f950 | (no assert string — adjacent, likely NetComm) | 104 |
| 0x0045fc50 | FUN_0045fc50 | Slot loading/unloading processing | 303 |
| 0x00460470 | FUN_00460470 | Send server OK request | 32 |
| 0x00460520 | FUN_00460520 | NetComm::SetSelfAsReady | 66 |
| 0x00460cb0 | FUN_00460cb0 | Mark slot as unused | 57 |
| 0x00460e90 | FUN_00460e90 | *** Opening (connect/open track) | 70 |
| 0x00461020 | FUN_00461020 | *** Closing track | 68 |
| 0x00461190 | FUN_00461190 | Server opened/closed state notification | 71 |
| 0x004612e0 | FUN_004612e0 | Apply frame time toward opening track | 38 |
| 0x00461de0 | FUN_00461de0 | Start Internet/LAN update | 41 |
| 0x00462c00 | FUN_00462c00 | Send Join Request to host | 36 |
| 0x00462e20 | FUN_00462e20 | Qualification slot management | 66 |
| 0x00463160 | FUN_00463160 | Qualification data processing | 263 |
| 0x004637a0 | FUN_004637a0 | AutoJoin session management | 145 |
| 0x00464290 | FUN_00464290 | SynchronizeWithServer | 54 |

**Notable:** `FUN_0045d890` is the main network message dispatcher (570+ lines)
with a large switch handling ~20 message types. It manages terrain/file
synchronization, player booting, vehicle slot state, and server master list
updates.

### O_BaseGz.cpp
Base game object — scene file loading.

- **Address range:** 0x0048e8d0 (single function)
- **Functions attributed:** 1
- **Lines:** 45, **Size:** ~1.4KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x0048e8d0 | FUN_0048e8d0 | CUBE scene file loader | 45 |

Loads a 3D scene file via the CUBE engine, reports errors with
"CUBE error loading scene file %s: %s".

### Replay.cpp
Replay/VCR playback system.

- **Address range:** 0x004ba1f0 (single function)
- **Functions attributed:** 1
- **Lines:** 97, **Size:** ~2.7KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004ba1f0 | FUN_004ba1f0 | Replay loader/player | 97 |

Loads a VCR replay file, preps replay state, processes replay data in chunks.
"Loading VCR File for playback", "Prepping Replay".

### camera.cpp
Camera manager — lifecycle hooks for the camera system.

- **Address range:** 0x0040c920 — 0x0040cce0
- **Functions attributed:** 3
- **Estimated total:** ~5 (internal cam functions lack assert strings)

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x0040c920 | FUN_0040c920 | CamMan::Init (registers MAINVIEW camera) | 31 |
| 0x0040c9e0 | FUN_0040c9e0 | CamMan::Restart | 15 |
| 0x0040cce0 | FUN_0040cce0 | CamMan::Post | 27 |

Standard lifecycle pattern: Init registers the MAINVIEW camera object,
Restart clears camera state, Post releases camera references.

### dynman.cpp
Dynamic object manager — scene object lifecycle.

- **Address range:** 0x0042c130 — 0x0042ca70
- **Functions attributed:** 6

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x0042c130 | FUN_0042c130 | DynMan::Enter | 13 |
| 0x0042c170 | FUN_0042c170 | DynMan::Setup | 12 |
| 0x0042c1a0 | FUN_0042c1a0 | DynMan::Init | 76 |
| 0x0042c3b0 | FUN_0042c3b0 | DynMan::Restart | 26 |
| 0x0042c9f0 | FUN_0042c9f0 | DynMan::Post | 23 |
| 0x0042ca70 | FUN_0042ca70 | DynMan::Exit | 12 |

Standard state-machine lifecycle (Enter→Setup→Init→Restart→Post→Exit).
`Init` is the largest at 76 lines.

### hdvehicle.cpp
High-detail vehicle physics and setup — suspension, tire compounds, inertia.

- **Address range:** 0x00439210 — 0x0043da10 (~98KB)
- **Functions attributed:** 5
- **Estimated total:** ~12 (many internal helpers lack assert strings)

| Address | Symbol | Name from strings | Lines |
|---------|--------|-------------------|-------|
| 0x00439210 | FUN_00439210 | Vehicle inertia validation (zero/negative check) | 883 |
| 0x0043af50 | FUN_0043af50 | Suspension bar lookup | 61 |
| 0x0043b040 | FUN_0043b040 | Front suspension setup (5-link) | 277 |
| 0x0043c250 | FUN_0043c250 | Tire compound loader from .hdv | 761 |
| 0x0043da10 | FUN_0043da10 | Tire slip curve loader, optimum camber | 190 |

This is a large module. `FUN_00439210` (883 lines) validates vehicle inertia
tensor. `FUN_0043c250` (761 lines) processes .hdv tire compound references.
`FUN_0043b040` (277 lines) handles suspension linkage setup.

### htree.cpp
HAT (Hierarchical Area Tree) — collision/pathfinding spatial tree.

- **Address range:** 0x00449a80 (single function)
- **Functions attributed:** 1
- **Lines:** 214, **Size:** ~7.1KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x00449a80 | FUN_00449a80 | HAT polygon Gaussian elimination | 214 |

Performs Gaussian elimination for HAT poly fitting. Error messages about
"Gaussian elimination for HAT poly failed".

### onscreen.cpp
On-screen display manager — UI overlay lifecycle.

- **Address range:** 0x0049ef40 — 0x0049f120
- **Functions attributed:** 6

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x0049ef40 | FUN_0049ef40 | OnScreen::Enter | 12 |
| 0x0049ef70 | FUN_0049ef70 | OnScreen::Setup | 12 |
| 0x0049efa0 | FUN_0049efa0 | OnScreen::Init | 19 |
| 0x0049f000 | FUN_0049f000 | OnScreen::Restart | 18 |
| 0x0049f0d0 | FUN_0049f0d0 | OnScreen::Post | 16 |
| 0x0049f120 | FUN_0049f120 | OnScreen::Exit | 12 |

Standard lifecycle (Enter→Setup→Init→Restart→Post→Exit), all thin wrappers
(~12-19 lines each).

### options.cpp
Options menu lifecycle.

- **Address range:** 0x004a0eb0 (single function)
- **Functions attributed:** 1
- **Lines:** 44, **Size:** ~1.2KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004a0eb0 | FUN_004a0eb0 | Options::Setup | 44 |

### pitcrew.cpp
Pit crew animation and positioning system.

- **Address range:** 0x004a2010 — 0x004a2a90 (~17KB)
- **Functions attributed:** 3
- **Estimated total:** ~5 (animation helpers)

| Address | Symbol | Name from strings | Lines |
|---------|--------|-------------------|-------|
| 0x004a2010 | FUN_004a2010 | Pitcrew mesh loader | 70 |
| 0x004a22d0 | FUN_004a22d0 | Pitcrew animation file loader | 107 |
| 0x004a2a90 | FUN_004a2a90 | Pitcrew position/animation setup | 336 |

Loads pitcrew meshes and animation files (.ANM), positions crew with POSITION/
ROTATE/MOVE commands. Largest function handles full animation state setup.

### plrfile.cpp
Player file management — save/load player profiles.

- **Address range:** 0x004b0770 — 0x004b1900 (~8KB)
- **Functions attributed:** 5

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004b0770 | FUN_004b0770 | Player file save (rename + write) | 56 |
| 0x004b1820 | FUN_004b1820 | PlayerFile::Enter | 14 |
| 0x004b1870 | FUN_004b1870 | PlayerFile::Setup | 18 |
| 0x004b18d0 | FUN_004b18d0 | PlayerFile::Restart | 12 |
| 0x004b1900 | FUN_004b1900 | PlayerFile::Post | 17 |

Standard lifecycle plus the main save function that renames temp file.

### searchgrid.cpp
Scene search grid — spatial partitioning for scene objects.

- **Address range:** 0x004bdc10 (single function)
- **Functions attributed:** 1
- **Lines:** 76, **Size:** ~2.3KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004bdc10 | FUN_004bdc10 | Search grid extents computation | 76 |

Computes extents of scene objects for spatial search grid construction.
"Could not get extents of scene ... numInstances=%d".

### sound.cpp
Sound manager lifecycle.

- **Address range:** 0x004c8a20 — 0x004c8d00
- **Functions attributed:** 6

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004c8a20 | FUN_004c8a20 | Sound::Enter | 23 |
| 0x004c8ab0 | FUN_004c8ab0 | Sound::Setup | 12 |
| 0x004c8ae0 | FUN_004c8ae0 | Sound::Init | 13 |
| 0x004c8b20 | FUN_004c8b20 | Sound::Restart | 15 |
| 0x004c8ca0 | FUN_004c8ca0 | Sound::Post | 16 |
| 0x004c8d00 | FUN_004c8d00 | Sound::Exit | 17 |

Standard lifecycle (Enter→Setup→Init→Restart→Post→Exit), all thin wrappers
(~12-23 lines each).

### steward.cpp
Race steward — timing, race phase management, lighting/glow objects.

- **Address range:** 0x004d0110 — 0x004d4600 (~46KB)
- **Functions attributed:** 6
- **Estimated total:** ~15 (many steward .c files in decompiled_full)

| Address | Symbol | Name from strings | Lines |
|---------|--------|-------------------|-------|
| 0x004d0110 | FUN_004d0110 | Scene setup (BMP/MAS loading, grid init) | 399 |
| 0x004d0e20 | FUN_004d0e20 | Light/glow object finder | 25 |
| 0x004d36d0 | FUN_004d36d0 | Steward::Setup (registers VEHICLE/TIMING/PITSTOP) | 15 |
| 0x004d38f0 | FUN_004d38f0 | Steward::Init (STLITE, PTLIT, helicoptor) | 139 |
| 0x004d3cf0 | FUN_004d3cf0 | Steward::Post (RaceTime, Duration, PreRacePresentation) | 384 |
| 0x004d4600 | FUN_004d4600 | Steward::Post (cleanup) | 78 |

The steward manages race timing with RaceTime/RaceTimeScaled calculations,
pre-race presentation sequencing, and lighting/glow object registration via
CUBE engine. `FUN_004d0110` at 399 lines handles full scene setup including
MAS/BMP file loading. `FUN_004d3cf0` at 384 lines manages race time display.

### util.cpp
Utility functions — texture manipulation.

- **Address range:** 0x004dc770 (single function)
- **Functions attributed:** 1
- **Lines:** 88, **Size:** ~2.7KB

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004dc770 | FUN_004dc770 | Texture material adjustment | 88 |

Adjusts texture materials (tex0/tex1/tex2 strings).

### vehload.cpp
Vehicle file loader (.veh) — tire compounds, gear settings, aerodynamics, cooling.

- **Address range:** 0x004f3240 — 0x004f4270 (~52KB)
- **Functions attributed:** 3
- **Estimated total:** ~8 (many vehload .c files in decompiled_full)

| Address | Symbol | Name from strings | Lines |
|---------|--------|-------------------|-------|
| 0x004f3240 | FUN_004f3240 | Force/direction validation (axis damping) | 67 |
| 0x004f3c80 | FUN_004f3c80 | Cooling system params (RadiatorCooling, WaterMin... | 167 |
| 0x004f4270 | FUN_004f4270 | Gear settings, tire compound refs | 776 |

`FUN_004f4270` (776 lines) parses .veh file gear settings (Gear1Setting–Gear6Setting),
tire compound references, and related vehicle parameters. `FUN_004f3c80` loads
thermal/cooling parameters.

### vidman.cpp
Video manager — CUBE/D3D rendering lifecycle.

- **Address range:** 0x004f9310 — 0x004fad00 (~15KB)
- **Functions attributed:** 7

| Address | Symbol | Name | Lines |
|---------|--------|------|-------|
| 0x004f9310 | FUN_004f9310 | CUBE error handler | 43 |
| 0x004fa000 | FUN_004fa000 | VidMan::Enter (3DCONFIG, device detection) | 147 |
| 0x004fa2f0 | FUN_004fa2f0 | VidMan::Setup | 12 |
| 0x004fa320 | FUN_004fa320 | VidMan::Init (CUBE scene loader) | 136 |
| 0x004fa640 | FUN_004fa640 | VidMan::Restart | 55 |
| 0x004fac00 | FUN_004fac00 | VidMan::Post | 57 |
| 0x004fad00 | FUN_004fad00 | VidMan::Exit | 21 |

Standard lifecycle plus error handling and Direct3D device setup via
3DCONFIG.EXE. `Enter` detects the display device and runs 3D configuration.

---

### NetComm.cpp

Network communication module — command-line argument parsing for multiplayer sessions.

**Functions (1):** FUN_00463160
**Address:** 0x00463160
**Estimated total functions:** ~20–30 (NetComm class with lifecycle + transport)

#### FUN_00463160 — NetComm::ParseCommandLine
- Parses command-line arguments for multiplayer network setup
- **Password:** reads `/password:<value>` argument, stores via FUN_00463710
- **Autohost:** `/autohost:<gamename>` activates autohost mode (sets +0xC5 flag), reads game name
- **Autojoin:** `/connect:<host:port>` activates autojoin mode (sets +0xC6 flag), copies address to struct offset +200, resolves port via FUN_00587ece
- **Network name:** reads next positional arg as network name (stores at +0x11C)
- **Max players:** reads `/maxplayers:<N>` (stores at +0x1AC), clamps to [2, 104]
- First checks FUN_00566810 for each keyword token
- Uses `DAT_007c569c` (SessionType5) guard for debug logging

**Globals:** DAT_007c569c (SessionType5), DAT_008ad25c (debug buffer), DAT_007d1004 (autojoin address)

**Calls:** FUN_004d7a50 (assert/trace gate), FUN_004d7aa0 (debug printf), FUN_00566810 (arg parser), FUN_00587c20 (string compare), FUN_00587ece (atoi), FUN_005897ca (strstr), FUN_0058815f (sprintf), FUN_00463710 (set password), FUN_004d7a50 (assert gate)

---

### O_BaseGz.cpp

CUBE scene file loading — base geometry/3D scene object.

**Functions (1):** FUN_0048e8d0
**Address:** 0x0048e8d0
**Estimated total functions:** ~15–25 (scene graph load/parse/free)

#### FUN_0048e8d0 — CUBE scene loader entry
- Loads a scene file (.scn or similar) through the CUBE engine
- Uses +0xE0 as optional custom path, falls back to `DAT_005ea438` (LoadPath)
- Compares path to current directory via FUN_00588410 (strcmp)
- On match: calls FUN_00496e40 (flush), then FUN_00546010 (CUBE scene load)
- On load failure: emits "CUBE error loading scene file %s: %s"
- On success: calls FUN_00545020 (get instance count), stores at +0xEC
- Calls FUN_00541cd0 (clear scene) and FUN_00541ca0

**Globals:** DAT_005ea438 (LoadPath), DAT_008ad25c (debug buffer)

**Calls:** FUN_00496e40, FUN_00546010, FUN_0053c5b0, FUN_00545020, FUN_00541cd0, FUN_00541ca0, FUN_004d7a50, FUN_004d7aa0, FUN_00588410

---

### ai_db.cpp

AI database — waypoint path validation and database initialization.

**Functions (2):** FUN_004024f0, FUN_004040a0
**Address range:** 0x004024f0 — 0x004040a0 (~0x1BB0 bytes)
**Estimated total functions:** ~30–50 (waypoint graph, AI driver data, difficulty)

#### FUN_004024f0 — AI waypoint path checker/renderer
- Walks AI waypoint linked list from +0x134 → +0x110
- Validates path completeness (checks for cycles up to 12000 nodes)
- Renders path using debug lines: FUN_004cefa0 for position/color
- Uses FUN_00402220 to get waypoint positions (2 variants: position only, with direction)
- Calls FUN_0053ac70 with 2 then 1 to set render state
- Falls through on empty path with "Incomplete waypoint path" assert

**Calls:** FUN_004cf010, FUN_0053ac70, FUN_00402220, FUN_004cefa0, FUN_004d7a50, FUN_004d7aa0

#### FUN_004040a0 — AIDatabase::Init()
- Debug trace: "Entered AIDatabase::Init()"
- Initializes default difficulty parameters for 3 difficulty levels
- Sets float array at param_1[0x4F..0x51] from `_DAT_0059e478` scaled by index
- Zeroes param_1[0x4C..0x4E] (low/mid/high difficulty slots)
- Sets param_1[0x47]=0.5f (min factor), [0x48]=1.0f (mid), [0x49]=1.3f (max)
- Sets param_1[0x58]=0x68 (104), [0x59]=0x34 (52), [0x5A]=3
- param_1[0x57]=1 (enable flag)
- Default setup values: param_1[0]=4.75f, [1]=4.25f (time deltas)
- param_1[0x52]=-1.0f
- Attempts to load "AI Database File" via FUN_004c58a0
- Difficulty interpolation: reads `DAT_007d01a0` (AIDifficultySlider 0–120)
  - If >100: lerp between mid and max
  - If ≤100: lerp between min and mid
- Result stored in param_1[0x46]

**Struct offsets:** +0x4F (3 arrays for low/mid/high), +0x46 (final difficulty coeff)
**Globals:** DAT_007d01a0 (AIDifficultySlider), DAT_007ce608 (AI DB path override), DAT_005ea438 (LoadPath)

**Calls:** FUN_004c58a0, FUN_00587db0, FUN_00587d02, FUN_00402690, FUN_004d7a50, FUN_004d7aa0

---

### camera.cpp

Camera manager — game camera system.

**Functions (1):** FUN_0040c920
**Address:** 0x0040c920
**Estimated total functions:** ~20–40 (CamMan class with multiple camera modes)

#### FUN_0040c920 — CamMan::Init()
- Creates MAINVIEW camera via FUN_00544f50("MAINVIEW"), stores as *param_1
- Zeroes 6 global camera vectors (DAT_005ea550–508)
- Calls sub-init functions: FUN_0040c240, FUN_0040c3b0, FUN_0040c520
- Sets +0x2D flag to 0
- Checks FUN_0040c140 (camera setup validation), on 0 copies param_1[6] → param_1[2]
- Calls FUN_0054a200(0x20, 1) — render state setup

**Globals:** DAT_005ea550/554/558 (camera position?), DAT_005ea500/504/508 (camera target?), DAT_008ad25c

**Calls:** FUN_004d7a50, FUN_004d7aa0, FUN_00544f50, FUN_0040c240, FUN_0040c3b0, FUN_0040c520, FUN_0040c140, FUN_0054a200

---

### dynman.cpp

Dynamic object manager — physics dynamics world.

**Functions (1):** FUN_0042c130
**Address:** 0x0042c130
**Estimated total functions:** ~10–20 (DynMan lifecycle + collision world)

#### FUN_0042c130 — DynMan::Enter()
- Debug trace: "Entered DynMan::Enter()"
- Delegates to FUN_0042bd60 (likely world init)

**Calls:** FUN_004d7a50, FUN_004d7aa0, FUN_0042bd60

---

### garage.cpp

Garage/car setup management — writes car setup files.

**Functions (1):** FUN_0042fd00
**Address:** 0x0042fd00
**Estimated total functions:** ~20–35 (full garage UI + file I/O)

#### FUN_0042fd00 — Garage setup file writer
- Writes full car setup to an open file
- **Key fields written (all from param_1 struct):**
  - Notes (from +0x68 path buffer, sliced 0x80 bytes)
  - Symmetric flag (+0x19A5 byte)
  - CGRightSetting (+0xC04), CGRearSetting (+0xC44), WedgeSetting (+0xC84)
  - TireCompoundSetting (+0xBC4), FuelSetting (+0xCC4)
  - NumPitstops (+0x1884), Pitstop1/2/3 (+0x18C4, 0x1904, 0x1944)
  - LEFTFENDER: FenderFlareSetting (+0xE04)
  - RIGHTFENDER: FenderFlareSetting (+0xE44)
  - FRONTWING: FWSetting (+0x1284)
  - REARWING: RWSetting (+0x12C4)
  - BODYAERO: RadiatorSetting (+0x1304), BrakeDuctSetting (+0x1344)
  - SUSPENSION: Front/RearAntiSway, ToeIn, Caster, TrackBar, 3rd spring/packer/bump/rebound settings
  - CONTROLS: SteerLock, RearBrake, BrakePressure, HandbrakePress
  - ENGINE: RevLimit, EngineMap, EngineBrakeMap
  - DRIVELINE: Gear settings (6 + reverse), FinalDrive, Reverse
  - Diff: Pump, Power, Coast, Preload
  - Per-wheel (FR/FL/RR/RL): Camber, Pressure, Packer, Spring, RideHeight, Slow/FastBump, Slow/FastRebound, BrakeDisc, BrakePad
  - BASIC: Downforce, Balance, Ride, Gearing, Custom
- Uses FUN_00566c30 for each formatted write line
- **Notable:** clamps gear ratios to minimum of previous gear (ensures ascending ratios)
- Returns 0 on success, 0xFFFFFFFF on open failure

**Struct offsets:** large struct spanning >0x1CA8 bytes (full car setup)

**Calls:** FUN_005668b0/0xd0 (file lock/unlock), FUN_00566940 (fopen), FUN_00566c30 (fprintf-like), FUN_004d7a50, FUN_004d7aa0

---

### hdvehicle.cpp

High-detail vehicle physics — main vehicle dynamics computation.

**Functions (1):** FUN_00439210
**Address:** 0x00439210 (very large, ~888 lines of decompiled code)
**Estimated total functions:** ~60–100 (full HDVehicle class: load, physics step, damage, setup)

#### FUN_00439210 — Vehicle dynamics integration step
- Core physics integration function — massive (888 lines decompiled)
- **Tire force computation:** reads 4 tire contact patches at stride 0x4A (4×74 = 296 bytes per wheel)
- Collects suspension deflection data into local_138[6] (3-axis per corner)
- **ARB (anti-roll bar) computation:** computes roll couple distribution from suspension geometry
- **Toe-in compliance:** adjusts lateral forces based on steering geometry offsets (+0x54C..0x564)
- **Chassis force accumulation:** sums contact forces, computes net force/torque on body
- **Suspension stiffness integration:** computes ride height, bump stop forces
- **Wheel velocity computation:** uses FUN_004d6ae0 for tire brush model
- **Quaternion/rotation math:** computes orientation deltas, cross products
- **Constraint solver iteration:** loops over contact constraints (4 wheels + 5th node)
- **Joint force distribution:** distributes forces through suspension links
- **Collision response:** applies restitution and friction at contact points
- References large physics-block workspace (DAT_0059ebd0+ coefficients matrix)
- Uses `DAT_007ce958` (TireModelMode) at end — sets tire model coefficients
- "Vehicle has zero or negative inertia" assert if inertia tensor invalid
- Massive struct access: param_1 is HDVehicle, param_2 = setup, param_3 = state

**Globals:** DAT_0059ebd0..DAT_0059ec08 (physics coefficients matrix), DAT_0059e880 (0.5), DAT_0059e420 (1.0), DAT_0059e430 (0.0), DAT_007ce958 (TireModelMode), DAT_007c569c (SessionType5), DAT_008ad25c

**Calls:** FUN_004d7880, FUN_004d7570, FUN_004d6ae0, FUN_0056bd40, FUN_0056bde0, FUN_005691d0, FUN_0043aee0, FUN_004361d0, FUN_004388d0, FUN_00435e00, FUN_005697a0, FUN_0043b040, FUN_0043b590, FUN_0056d1c0, FUN_0056cf70, FUN_0056d020, FUN_0056d2d0, FUN_0043bb00, FUN_004390a0, FUN_00588570, FUN_0054b3b0

---

### hwinput.cpp

Hardware input — DirectInput wrapper.

**Functions (6):** FUN_00455bf0, FUN_00455c60, FUN_00455d50, FUN_00455da0, FUN_00455e70, FUN_00455f00
**Address range:** 0x00455bf0 — 0x00455f00 (~0x310 bytes)
**Estimated total functions:** ~40–60 (HWInput class + device enumeration + force feedback)

#### FUN_00455bf0 — HWInput::Enter()
- Debug trace: "Entered HWInput::Enter()"
- Calls FUN_0044f4e0 (init input system)
- Hides cursor via ShowCursor(0) until hidden
- Calls FUN_00455290 (enum devices)
- If DAT_007d13a0 == 1, calls FUN_004f8ae0 (force feedback init?)

**Globals:** DAT_007d13a0 (force feedback flag?)

**Calls:** FUN_0044f4e0, ShowCursor, FUN_00455290, FUN_004f8ae0

#### FUN_00455c60 — HWInput::Setup()
- Creates DirectInput8 device: DirectInput8Create(DAT_007ce2a0, 0x800, IID_IDirectInput8, param_1, 0)
- On success: calls keyboard/mouse setup chain FUN_0044ee10, FUN_0044fa60, FUN_0044fbe0, FUN_004533a0

**Globals:** DAT_007ce2a0 (hInstance), DAT_005ec4a4 (hwnd), DAT_005ad4a0 (IID_IDirectInput8), DAT_007c569c, DAT_008ad25c

**Calls:** DirectInput8Create, FUN_0044ee10, FUN_0044fa60, FUN_0044fbe0, FUN_004533a0

#### FUN_00455d50 — HWInput::Init()
- Debug trace: "Entered HWInput::Init()"
- Calls FUN_004532d0, FUN_004533a0, FUN_00453560 (init sub-components)

**Calls:** FUN_004532d0, FUN_004533a0, FUN_00453560

#### FUN_00455da0 — HWInput::Restart()
- Calls FUN_0044f680 (set cooperative level) and FUN_0044f0a0 (acquire devices)
- If DAT_007d1ffc != 0, calls FUN_0044ff50 (force feedback restart)
- Sets +0x2428 flag to 0
- Scans wheel array at +0x1F98 (stride 0x2C, 26 entries) — checks if any wheel has device handle 0 with type 0x59 (wheel)
- If found, sets +0x2428 to 1 (wheel detected)

**Struct offsets:** +0x1F98 (wheel device array, 26 entries × 0x2C), +0x2428 (wheel detected flag)
**Globals:** DAT_007d1ffc, DAT_005d6d60/4, DAT_007c569c

#### FUN_00455e70 — HWInput::Post()
- Calls FUN_0044f070(1) (unacquire devices)
- If param_1[0x665] != 0, calls FUN_004526c0 (FFB stop)
- Calls FUN_0044fbe0 (release) and FUN_0044efe0
- Releases DirectInput interface via vtable[2] (Release)

**Calls:** FUN_0044f070, FUN_004526c0, FUN_0044fbe0, FUN_0044efe0

#### FUN_00455f00 — HWInput::Exit()
- Debug trace: "Entered HWInput::Exit()"
- Releases DirectInput (FUN_0044fbe0 ×2, FUN_0044f5f0, FUN_0044efe0)
- Releases DirectInput interface via vtable[2]
- If DAT_007d13a0 == 1, calls FUN_004f8c90 (FFB shutdown), sets param_1[0x6C4] = -1

**Globals:** DAT_007d13a0

**Calls:** FUN_0044fbe0, FUN_0044f5f0, FUN_0044efe0, FUN_004f8c90

---

### onscreen.cpp

On-screen display — HUD/text overlay system.

**Functions (1):** FUN_0049ef40
**Address:** 0x0049ef40
**Estimated total functions:** ~30–50 (full OSD: FPS, messages, telemetry)

#### FUN_0049ef40 — OnScreen::Enter()
- Debug trace only: "Entered OnScreen::Enter()"
- No other logic

**Calls:** FUN_004d7a50, FUN_004d7aa0

---

### osman.cpp

OS Manager — application-level OS integration.

**Functions (2):** FUN_004a18d0, FUN_004a1930
**Address range:** 0x004a18d0 — 0x004a1930
**Estimated total functions:** ~10–20 (OSMan: mutex, time, process)

#### FUN_004a18d0 — OSMan::Enter()
- Creates named mutex "_F1 Challenge 99-02_APP_MUTEX_" via CreateMutexA
- If GetLastError() == ERROR_ALREADY_EXISTS (0xB7), returns 1 (instance already running)
- Returns 0 on success (first instance)

**Globals:** DAT_007ce2d8 (mutex handle)

**Calls:** CreateMutexA, GetLastError, FUN_004d7a50, FUN_004d7aa0

#### FUN_004a1930 — OSMan::Exit()
- Closes mutex handle DAT_007ce2d8 via CloseHandle

**Globals:** DAT_007ce2d8

**Calls:** CloseHandle, FUN_004d7a50, FUN_004d7aa0

---

### pitcrew.cpp

Pit crew mesh loading — loads 3D meshes for pit crew animations.

**Functions (1):** FUN_004a2010
**Address:** 0x004a2010
**Estimated total functions:** ~15–30 (PitCrew class: load, animate, render)

#### FUN_004a2010 — Pit crew mesh loader
- Loads pit crew mesh via CUBE engine (FUN_005450e0)
- On error: "CUBE error loading pitcrew mesh %s: %s"
- Walks animation nodes (linked list at +0x44 chain)
- Disables non-animated nodes (+0x40 byte flag check)
- If param_4 == 0: calls FUN_00545250 (immediate mode)
- If param_4 != 0: calls FUN_0054ba00 (animation mode)
- Creates bone matrix array (FUN_0054c210 + operator_new)
- Stores bone transforms in allocated array
- Copies param_2 (name) to param_1 string area
- Uses `DAT_007cf884` for LOD/skill comparison

**Globals:** DAT_007cf884

**Calls:** FUN_005450e0, FUN_0053c5b0, FUN_0054a870, FUN_00545250, FUN_0054ba00, FUN_0054c210, FUN_0054c230, FUN_00545930, FUN_004d7a50, FUN_004d7aa0

---

### render.cpp

Renderer — Direct3D rendering lifecycle.

**Functions (3):** FUN_004b4030, FUN_004b4060, FUN_004b4170
**Address range:** 0x004b4030 — 0x004b4170 (~0x140 bytes)
**Estimated total functions:** ~80–120 (full Render class: D3D init, scene, post-processing)

#### FUN_004b4030 — Render::Init()
- Debug trace only: "Entered Render::Init()"

#### FUN_004b4060 — Render::Restart()
- Initializes param_1 (26 × 4 bytes) to 0x01010101 (likely clear color or texture LOD bias array)

#### FUN_004b4170 — Render::Post()
- Debug trace only: "Entered Render::Post()"

---

### searchgrid.cpp

Spatial search grid — scene bounding box computation for spatial indexing.

**Functions (1):** FUN_004bdc10
**Address:** 0x004bdc10
**Estimated total functions:** ~10–20 (search grid build, query, update)

#### FUN_004bdc10 — Scene extent computation
- Iterates all scene instances via FUN_005452f0/5340
- Computes world-space AABB (min/max corners) by calling FUN_004dd550 per instance
- Skips instances with bit 0x10 set in flags (+0x3C)
- Stores computed min/max into param_1 (+0x924..0x930):
  - +0x924 = minX, +0x92C = minZ
  - +0x928 = 1.0/(maxX-minX) (inverse scale X)
  - +0x930 = 1.0/(maxZ-minZ) (inverse scale Z)
- If all extents equal (degenerate), emits "Could not get extents of scene ... numInstances=%d"

**Calls:** FUN_005452f0, FUN_00545340, FUN_0054fb70, FUN_004dd550, FUN_004d7a50, FUN_004d7aa0

---

### sound.cpp

Sound system — Miles Sound System integration.

**Functions (1):** FUN_004c8a20
**Address:** 0x004c8a20
**Estimated total functions:** ~20–35 (Sound class: init, load, play, engines)

#### FUN_004c8a20 — Sound::Enter()
- Debug trace: "Entered Sound::Enter()"
- Calls FUN_004c82c0 — if returns 0, calls FUN_004c82f0 (init sound)
- Calls FUN_004c83b0 (setup)
- Calls FUN_004c8560 (load sound files)
- Calls FUN_004c8900(DAT_007cf380) — set output device
- Calls FUN_004184f0 (engine sound?)
- Calls FUN_004116c0(0) and (1) — channel init

**Globals:** DAT_007cf380 (sound device handle)

**Calls:** FUN_004c82c0, FUN_004c82f0, FUN_004c83b0, FUN_004c8560, FUN_004c8900, FUN_004184f0, FUN_004116c0

---

### tire_manager.cpp

Tire manager — tire brand/compound/slip curve data loading and lookup.

**Functions (7):** FUN_004d5ee0, FUN_004d5f70, FUN_004d7150, FUN_004d7570, FUN_004d75d0, FUN_004d7660, FUN_004d7880
**Address range:** 0x004d5ee0 — 0x004d7880 (~0x19A0 bytes)
**Estimated total functions:** ~30–50 (full TireManager: .tbc parser, slip curve model, compound DB)

#### FUN_004d5ee0 — Tire load factor setter
- Validates tire load factor > 0 (else assert: "Tire load factor should be positive")
- Stores 4 values in param_1 double array:
  - param_1[0] = (param_2 + param_3) * 0.5 (mean)
  - param_1[1] = (param_2 - param_3) * 0.5 (half-diff)
  - param_1[2..3] = param_4/param_5 (load factor as double)
  - param_1[3] = 1.0 / load factor

**Calls:** FUN_004d7a50, FUN_004d7aa0

#### FUN_004d5f70 — Tire slip curve builder
- Parses and builds tire slip curve data from text config
- Reads data points using text parser (FUN_00566cc0 + FUN_005651b0)
- Handles "DATA" keyword and numeric data points
- Validates: step > 0, first point = 0, ≥3 data points minimum
- Fits cubic polynomials per interval (Hermite spline segments)
- Allocates curve storage (5 doubles per interval: coefficients a,b,c,d + value)
- Normalizes curve to peak = 1.0
- Finds maximum point and stores peak location

**Calls:** FUN_00566cc0, FUN_005651b0, FUN_005897ca, FUN_005887ed, FUN_005654a0, FUN_00566650, FUN_00565aa0, FUN_00587c20, FUN_005677b0, FUN_00587bcf, FUN_004d7a50, FUN_004d7aa0

#### FUN_004d7150 — Tire brand file parser (*.tbc)
- Opens and parses .tbc tire brand files
- First pass: counts SLIPCURVE and COMPOUND sections
- Allocates arrays: slip curves (0x18 bytes each) and compounds (0x2A8 bytes each)
- Second pass: fills data via FUN_004d5f70 (slip curves) and FUN_004d6b00 (compounds)
- Validates file format: "Bad syntax in file %s caused miscount"
- Extracts filename without extension for brand name

**Globals:** DAT_005ea438 (LoadPath)

**Calls:** FUN_004d7050, FUN_00566650, FUN_00568a60, FUN_00589901, FUN_005668b0/0xd0, FUN_00566b20, FUN_00566cc0, FUN_005651b0, FUN_00587c20, FUN_00566d30, FUN_004d5f70, FUN_004d6b00, FUN_00566b90, FUN_004d7a50, FUN_004d7aa0

#### FUN_004d7570 — Compound index lookup
- Returns pointer to compound data at index param_2
- Compound stride: 0x2A8 bytes
- Bounds-checked: [-1 < index < brand.compoundCount]
- Error: "Tire brand doesn't have compound index %d"

#### FUN_004d75d0 — Curve name lookup
- Searches brand's slip curve array for curve matching name param_2
- Curve stride: 0x18 bytes
- String compare via FUN_00588410 (strcmp)
- Error: "Tire brand doesn't have curve name %s"

**Globals:** DAT_005ea438

**Calls:** FUN_00588410, FUN_004d7a50, FUN_004d7aa0

#### FUN_004d7660 — Tire brand loader (*.tbc)
- Scans season directory for *.tbc files
- Builds path: `<TrackDir>\<SeasonName>` 
- Uses FUN_00565f80 to enumerate files matching "*.tbc"
- Allocates brand array (stride 0x24 bytes)
- Iterates found files: constructs full path and calls FUN_004d7150 to parse each

**Globals:** DAT_005ec428 (SeasonName), DAT_005ec3d8 (TrackDir), DAT_005ea438 (LoadPath)

**Calls:** FUN_004d7800, FUN_00567740, FUN_0058815f, FUN_00565f80, FUN_00565f70, FUN_004d7020, FUN_00565f50, FUN_005662d0, FUN_004d7150, FUN_00565f20, FUN_00565eb0, FUN_00567780, FUN_004d7a50, FUN_004d7aa0

#### FUN_004d7880 — Tire brand lookup
- Searches brand array for brand name matching param_2
- Brand stride: 0x24 bytes
- String compare via FUN_00588410 (strcmp)
- Error: "Non-existent tire brand \"%s\""
- Returns pointer to brand struct or 0

**Globals:** DAT_007c569c (SessionType5), DAT_005ea438

**Calls:** FUN_00588410, FUN_004d7a50, FUN_004d7aa0

---

### util.cpp

Utility functions — texture adjustment.

**Functions (1):** FUN_004dc770
**Address:** 0x004dc770
**Estimated total functions:** ~15–30 (file I/O, string, texture helpers)

#### FUN_004dc770 — Texture adjuster
- Adjusts material textures (up to 3: param_2/3/4)
- Calls FUN_004dc430 (check texture system ready)
- Calls FUN_00548890 (validate material)
- For each non-null texture param: calls FUN_004dc450 (adjust texture)
- On failure: logs "Unable to adjust texture for material: %s, tex0=%s, tex1=%s, tex2=%s"
- Copies DAT_005ea438 for empty texture names
- Returns: 0/1/2 = which texture failed, -1 on general failure, 0 on success

**Globals:** DAT_005ea438 (LoadPath), DAT_008ad25c

**Calls:** FUN_004dc430, FUN_00548890, FUN_004dc450, FUN_004d7a50, FUN_004d7aa0, _strncpy

---

### vehload.cpp

Vehicle load parser — validates vehicle configuration damping.

**Functions (1):** FUN_004f3240
**Address:** 0x004f3240
**Estimated total functions:** ~20–40 (VehLoad: .veh/.hdv parser)

#### FUN_004f3240 — Vehicle damping direction validation
- Reads 3 values from config into (force, velocity, direction) struct at param_1 + param_3*0x18
- Validates that damping force opposes velocity for all 6 axes:
  - case 0: +x force → velocity in +x (positive damping)
  - case 1: -x force → velocity in -x
  - case 2: +y force → velocity in +y
  - case 3: -y force → velocity in -y
  - case 4: +z force → velocity in +z
  - case 5: -z force → velocity in -z
- Asserts if damping direction is wrong (force aiding motion, not opposing)

**Globals:** DAT_0059e430 (0.0), DAT_007c569c (SessionType5)

**Calls:** FUN_00565aa0, FUN_004d7a50, FUN_004d7aa0

---

### weather.cpp

Weather system — weather data file writer.

**Functions (1):** FUN_004fe820
**Address:** 0x004fe820
**Estimated total functions:** ~15–30 (Weather class: conditions, rain, temperature)

#### FUN_004fe820 — Weather conditions file writer
- Opens file for writing via FUN_00587db0
- Writes header "Weather" and separator
- Loops 8 times (weather segments/sessions):
  - Writes conditions header and per-minute data
  - Uses FUN_004fb910 for total minutes
  - Steps through time in increments of `_DAT_0059e5fc` (1 min?)
  - Evaluates weather at each step — interpolates Conditions percentage
  - Writes: Conditions%, OnPathWetness%, OffPathWetness%, AmbientTemp, TrackTemp
  - Walks linked list at +0x38 chain for detailed per-minute forecast:
    - Minute offset, Conditions%, AmbientTemp
- On error: "Could not write to file %s"

**Struct offsets:** +0x28 (OnPathWetness), +0x2C (OffPathWetness), +0x30 (AmbientTemp), +0x34 (TrackTemp), +0x38 (forecast linked list), +0x3C

**Calls:** FUN_00587db0, FUN_005887b1, FUN_0042ce30, FUN_004fb910, FUN_004fdeb0, FUN_00587d02, FUN_004d7a50, FUN_004d7aa0

---

## Statistics

- Directly attributed functions: 32
- Estimated functions missing (in gap regions): 25
- Functions attributed: 52
- Functions attributed via assert strings: 58
- IDA-only functions: 1
- Largest gap: 10
- Misattributed functions discovered: 1
- Source files: 18
- Source files in batch (unique .cpp): 19
- Source files with multiple functions: 7
- Source files with single function found: 12
- Source tree locations: 2
- Unique .cpp files: 19
- Unique address range: 0
