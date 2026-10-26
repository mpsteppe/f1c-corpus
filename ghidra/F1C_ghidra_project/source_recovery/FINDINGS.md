# Findings Log

Append-only. Every discovery gets a dated entry with evidence.
Tag `[MERGE-READY]` when verified and ready for docs/.

---

## 2026-07-16 — Phase 1 Binary Forensics Complete (BF-01 through BF-05)

### Build Environment (BF-01, BF-03)
- **Compiler: MSVC 6.0 SP6** (C compiler build 8447)
- **Linker: 6.0**
- **Build date: 2003-04-15 15:27:50 UTC** (2 months before June 2003 release)
- **69 compilation units** (68 C + 1 C++) vs 31 known .cpp files = **~38 missing source files**
- **No debug directory, no PDB path, no exports** — fully stripped release build

### RTTI Scan (BF-02)
- 20 `.?AV` hits — **all STL/CRT, zero ISI game classes**
- `/GR-` flag confirmed. RTTI avenue closed for F1C retail exe.
- Still worth scanning F1 2002 WIP Demo and Sports Car GT (different builds may differ)

### Graphics API (BF-05)
- [MERGE-READY] **DirectX 8** (d3d8.dll, `Direct3DCreate8`), NOT DirectX 9
- DLL proxy target is d3d8.dll, not d3d9.dll
- Corrects assumption in Opus chat and some community references

### .text1 Section (BF-03)
- Secondary code section at VA 0x4D8000-0x58E000 (745KB)
- Maps to the dynamics solver, LDL^T, rigid body code found via IDA
- **Likely a separately-compiled physics library statically linked**
- LBMPEG_D section confirms MPEG decoder is another separate module

### Threading (BF-05)
- `CreateThread`/`SuspendThread`/`ResumeThread`/`CriticalSection` APIs imported
- Game IS multi-threaded at OS level, but Frida trace showed physics+AI+render on single thread
- Worker threads likely handle I/O, audio, or network

### Source Tree (BF-04)
- 31 source files confirmed from strings (30 ISI + 1 LbMpeg)
- Build path: `D:\dev\F1_1999_2002\Source\` (ISI game source)
- MPEG path: `\Dev\AudioDev\Shared\Engine\Dev\LbMpeg.cpp` (shared engine component)
- Only 2 assert-like strings in binary — ISI used trace strings, not asserts

### SDK Header (SDK-01)
- `InternalsPlugin.hpp` downloaded and indexed
- rF1 structs: TelemWheel (10 fields, 48 bytes), TelemInfoBase (29 fields), ScoringInfoV2 (game phases 0-8)
- Game phase enum 0-8 maps to our RacePhase observations
- [MERGE-READY] ScoringInfoV2 game phases: 0=before, 1=recon, 2=grid walk, 3=formation, 4=starting lights, 5=green, 6=caution/SC, 7=stopped, 8=over

## 2026-07-16 — F1 2002 WIP Demo Analysis (CB-02)

### [MERGE-READY] Original ISI Source Tree Structure
The F1 2002 Demo (April 2002) reveals the pre-fork source layout:
- `D:\Dev\Common\Source\` — 25 shared isiMotor1 engine files
- `D:\Dev\F1_2002\Source\` — 4 game-specific files (onscreen, options, plrfile, steward)
- `D:\Dev\AudioDev\Shared\Engine\Dev\` — shared audio/video (LbMpeg.cpp)
- F1C forked all 29 files into `D:\dev\F1_1999_2002\Source\` (common + specific merged)
- `config.cpp` is new in F1C, not present in F1 2002

### 3DConfig.exe is a DEBUG BUILD
- PDB path: `D:\Dev\CONFIG\Debug\3DConfig.pdb`
- PDB not shipped with demo, but build path confirms `D:\Dev\` as ISI's dev root
- 3DConfig has one extra RTTI class (bad_alloc) vs game exe

### Demo vs F1C Compilation Units
- Demo: 70 (69C + 1C++), F1C: 69 (68C + 1C++)
- Demo has NO .text1 section — physics library was added later (or compiled differently)
- Same compiler (MSVC 6.0 SP6), same RTTI profile (STL only), same `/GR-`

### Downloads Catalog
- InternalsPlugin.hpp: HAVE (in 03_sdk_crossref/headers/)
- F1 2002 WIP Demo: HAVE (in source_material/, 54MB installer — needs extraction)
- Sports Car GT: HAVE (in source_material/, 552MB zip — needs extraction)
- Sports Car GT patch + widescreen fix: HAVE

## 2026-07-16 — Full Source Material Inventory

### Source Material Directory (`%USERPROFILE%\Desktop\source_material\`)

#### Binaries Analyzed

| Binary | Size | Type | Source Paths | RTTI | PDB | Debug Dir |
|--------|------|------|-------------|------|-----|-----------|
| NASCAR_Thunder_2003_Demo.exe | 1.9MB | PE32 x86 | 32 (D:\Dev\NASCAR_2003\Source\) | 20 (STL only) | No | No |
| NASCAR_Thunder_2003.exe (retail v1.1) | 1.9MB | PE32 x86 | 32 (same paths) | 20 (STL only) | No | No |
| NASCAR_Thunder_2004_Demo.exe | 2.2MB | PE32 x86 | 32 (D:\Dev\NASCAR_2004\Source\) | 20 (STL only) | No | No |
| NASCAR_Thunder_2004.exe (retail retail) | 2.2MB | PE32 x86 | 32 (D:\dev\NASCAR_2004\Source\) | 20 (STL only) | No | No |
| 3DConfig.exe (NASCAR 2003) | 836KB | PE32 x86 | config.cpp, dict.cpp, FileLine.cpp, DX8*.cpp, Particle.cpp, Shadow.cpp | **21 (STL + bad_alloc)** | **D:\Dev\CONFIG\Debug\3DConfig.pdb** | **Yes (0xad320)** |
| 3DConfig.exe (NASCAR 2004) | 848KB | PE32 x86 | config.cpp, dict.cpp, Cube.cpp, same DX8* | 0 | **D:\Dev\CUBE42\Config\Debug\3DConfig.pdb** | **Yes (0xae360)** |
| Spcar.exe (SCGT full install) | 1.1MB | PE32 x86, 8 sections | None | 0 | No | No |
| Spcar.exe (SCGT 1551 patch) | 1.1MB | PE32 x86, 8 sections | None | 0 | No | No |
| F1_2002_WIP_DEMO.exe | 54MB | InstallShield SFX | (installer, not game exe) | N/A | N/A | N/A |

#### ISI Dev Tree Structure (from all binaries combined)

```
D:\Dev\
├── AudioDev\Shared\Engine\Dev\          — LbMpeg.cpp (all games share this)
├── Common\Source\                        — 25 shared isiMotor1 files (F1 2002 demo only)
├── CONFIG\Debug\                         — 3DConfig.pdb (NASCAR 2003)
├── CUBE41\Library\Source\                — DX8Main/Pipe/Util.cpp, Particle.cpp, Shadow.cpp (NASCAR 2003)
├── CUBE42\                               — (NASCAR 2004 - engine revision bump)
│   ├── Config\Debug\                     — 3DConfig.pdb
│   └── Library\Source\                   — Cube.cpp, DX8Main/Pipe/Util.cpp, Particle.cpp, Shadow.cpp
├── F1_2002\Source\                        — 4 game-specific files (F1 2002 demo)
├── F1_1999_2002\Source\                   — 31 files (F1C retail — merged common+specific)
├── ISIUtility\Source\                     — FileLine.cpp (error/debug utility)
├── NASCAR_2003\Source\                    — 34 files (32 game + config.cpp + dict.cpp from 3DConfig)
└── NASCAR_2004\Source\                    — 34 files (same set as 2003)
```

#### [MERGE-READY] Source File Cross-Reference

Files unique to specific games (not in F1C):
- **pitman.cpp** — NASCAR 2003/2004 only (pit man crew, not pit crew)
- **random.cpp** — NASCAR 2003/2004 only
- **dict.cpp** — NASCAR 2003/2004 3DConfig only
- **FileLine.cpp** — ISIUtility shared module (3DConfig only)
- **Cube.cpp** — CUBE42 renderer (NASCAR 2004 3DConfig only)
- **DX8Main.cpp, DX8Pipe.cpp, DX8Util.cpp** — CUBE renderer library
- **Particle.cpp, Shadow.cpp** — CUBE renderer effects

Files unique to F1C (not in NASCAR):
- **camera.cpp** — present in F1C but absent from NASCAR 2004 (NASCAR 2003 has it)
- **config.cpp** — present in F1C retail but not NASCAR 2003 demo (present in NASCAR 2004)

#### [MERGE-READY] CUBE Engine Versioning
- **CUBE41** = NASCAR Thunder 2003 renderer
- **CUBE42** = NASCAR Thunder 2004 renderer (added Cube.cpp)
- F1C uses same-era renderer but no CUBE version string found in F1C binary
- SCGT uses "CUBE 3D Engine v" string — earliest CUBE version

#### NASCAR 2003 Additional Intelligence
- Credits: Programmers = Prashant Patel, Brad Searles, Dan Searles, Michael Zielinski
- Config.ini: GRIDSIZE=22, CPURATING=3, SEASONDIR=SEASON03
- .osc format: ISI UI scripting, Source_MAS= for asset loading, AttributeSet= for fonts
- Uses Bink video (.bik), Miles Sound System (Mss32.dll)
- 22-car grid vs F1C 22-car grid — same engine capacity

#### Sports Car GT Analysis
- **PC version**: 3 exe variants (original 1.1MB, 1551 patch 1.1MB, widescreen fix)
- **PS1 version**: CD image (Track 01 = data, Tracks 02-12 = CD audio)
- **Engine**: CUBE 3D Engine, no RTTI, no source paths, no debug info
- **8 PE sections** with CODE/DATA/CONST named sections (unusual for MSVC — may indicate Watcom linker or mixed compilation)
- **Glide/3Dfx** support (40 strings, voodoo references) — D3D was secondary on 1999 hardware
- **Core strings shared with F1C+NASCAR**: 406 strings, including OSC reader, Gizmo system, CURRENTRACE, RaceSession, damage dynamics
- SCGT is the **oldest isiMotor1** binary — architectural ancestor to all others

#### Incomplete Download
- `Vahvistamaton 716353.crdownload` — 546MB ZIP, incomplete (Finnish filename = "Unconfirmed"). Likely NASCAR 2004 ISO.

#### InternalsPlugin.hpp (rFactor SDK)
- Copyright 1996-2007 ISI, `isiMotor Technology (tm)`
- 367 lines, V1/V2/V3 plugin hierarchy
- TelemWheel: 44 bytes (10 fields)
- TelemInfoBase: 276 bytes (29 fields)
- VehicleScoringInfo: 148 bytes (18 fields) 
- ScoringInfoBase: 92 bytes (8 fields)
- Game phases 0-8 documented (matches F1C RacePhase)
- Hardware control plugin: `CheckHWControl(controlName, fRetVal)` — plugin can override steering/throttle/brake by name
- These are rFactor/isiMotor2 structs, but evolved from isiMotor1 era structures

## 2026-07-16 — NASCAR Thunder 2004 Dedicated Server Analysis

### NT2004_Dedicated.exe (from ISO)
- **Size:** 2,285,568 bytes (2.18 MB)
- **Build:** 2003-08-22 22:30:35 UTC — **270 seconds after retail** (same build session)
- **Sections:** 7 (.text, .rdata, .data, LBMPEG_D, .tls, .data1, .rsrc) — NO .text1 (no physics lib section, unlike F1C)
- **RTTI:** 20 (STL only, same as retail)
- **Source paths:** 32 files (identical to retail, `D:\dev\NASCAR_2004\Source\`)
- **Debug:** No PDB, no debug directory
- **Rich header:** Identical to retail — 167 compilation units (24 C + 143 C++)
- **Imports:** Same 11 DLLs as retail (including d3d8.dll and DINPUT8.dll — dedi still links graphics/input)

### Dedi vs Retail Diff
- .text size difference: **4,096 bytes** (retail is 4KB larger)
- NOT a patched exe — fully recompiled (all offsets shifted, 57K diff regions)
- Built with same compiler, same libs, same session — different `#define` (likely `#define DEDICATED_SERVER`)
- **Only 8 meaningful string differences:** retail has autojoin/autohost mode strings that dedi lacks
- All network/server strings **SHARED** — `HotPacket::Winsock`, GameSpy, vote system, kick/boot, chat, session management
- **2,436 strings shared with F1C** — confirms identical isiMotor1 codebase

### NASCAR 2004 ISI Programmer Credits
Joe Campana, Terence Groening, Brad Porter, Brad Searles, Dan Searles, Michael Zielinski
(vs NASCAR 2003: Prashant Patel, Brad Searles, Dan Searles, Michael Zielinski)

### [MERGE-READY] 273 Physics Parameter Names
Extracted CamelCase parameter names from dedi binary — these are .hdv/.pm file field names that map directly to struct offsets via sscanf parsing. Key categories:
- **Tire:** TireBrand, TireCompoundSetting, TireCutDull, TireCutSharp, TireHeatMult, TireWearMulti, OptimumPressure, GripTempPress, LoadSens, WearRate
- **Brake:** BrakeTorque, BrakeOptimumTemp, BrakeCooling, BrakeHeating, BrakeFadeRange, BrakeWearRate, BrakeDiscInertia, BrakeDuctCooling/Drag/Lift, BrakePressureRange, HandbrakePress
- **Suspension:** SpringRange/Setting/Base, SlowBump/Rebound Range/Setting, FastBump/Rebound Range/Setting, BumpStopSpring/Damper, RideHeightRange/Setting, Front/Rear 3rd springs, AntiSwayRate/Range
- **Engine:** EngineInertia, EngineMapRange, EngineBrakingMapRange, LifetimeEngineRPM, FuelConsumption, FuelTankPos/Motion
- **Aero:** BodyDragBase/HeightAvg/HeightDiff, FW/RWDragParams, FenderDragParams, RadiatorDrag, Front/RearWingMassInertia
- **Wheels:** CamberRange/Setting, ToeInRange/Setting, CasterRange/Setting, WheelTrack, WheelBase, WheelBend/Detach/Drive
- **Gearbox:** ForwardGears, Gear1-7Setting, UpshiftClutchTime, DownshiftClutchTime, AutoUp/DownshiftGripThresh
- **Differential:** DiffPreloadRange/Setting
- **AI:** AIDamperFast/Slow, AIDownforceBias/ZArm, AIGripMult, AIPeakSlip, AISpringRate, AITireWear, AIFuelMult
- **Steering:** SteeringWheelAxis, AlignWheels
- **Mass/Inertia:** Mass, Inertia, HeadMass, HeadInertia, SpinInertia, FrontWingMassInertia

### Compiler Analysis Update
- F1C: **MSVC 6.0** (C compiler build 8447) + **MSVC 7.x** (.NET 2003, build 9044) — mixed toolchain
- NASCAR 2003: Same mixed toolchain — 51 MSVC6 C + 21 MSVC7 C + 135 MSVC7 C++ = 207 units
- NASCAR 2004: Pure **MSVC 7.x** — 24 MSVC7 C + 143 MSVC7 C++ = 167 units (dropped MSVC6)
- All share: MASM 8047/8799, same linker 7299, same Resource Compiler 1735
- F1C retained 52 MSVC6 C units that NASCAR 2004 migrated to MSVC7 — F1C was built earlier in the transition

### Value Assessment
Dedi server is NOT a separate stripped-down build — it's the full game exe with `#define DEDICATED_SERVER` toggling ~4KB of code (mostly removing autojoin client paths). Same physics engine, same network stack, same parameters. Primary value: confirms parameter naming and validates cross-binary analysis approach. Physics parameter names directly applicable to F1C struct field naming.

## 2026-07-16 — F1 2000 Analysis (Fully Installed Game)

### Overview
F1 2000 (EA Sports / Image Space Inc., March 2000) — the **direct predecessor** to F1 Challenge. Fully installed game found at `%USERPROFILE%\Desktop\source_material\F1 2000\`.

### Binary Architecture
- **F1_2000.exe** (253KB) — copy protection launcher (SafeDisc clcd16/clcd32/clokspl/secdrv.sys), NOT the game engine
  - Linker 5.0, no Rich header, no RTTI, imports only KERNEL32/USER32/ADVAPI32/VERSION
  - Build path: `D:\F1_2000\SPLASHSCREENS\SPLASH16.BMP` (EA build, not ISI dev tree)
- **F1_2000.ICD** (1.49MB) — the **REAL game executable**, hidden behind SafeDisc
  - Build: **2000-03-08 01:48:29 UTC**, Linker 6.0
  - **10 PE sections** including CODE, UVA_DATA, IDCT_DAT, _DATA (unusual layout)
  - **581 compilation units** in Rich header (type IDs differ from later ISI builds — older Rich format)
  - No RTTI (0 hits), no source paths in strings (unlike F1C), no format strings
  - Only D: path found: `D:\Dev\F1\WIN32\Gold\f1_2000.pdb`
  - Imports: DDRAW.dll, DINPUT.dll, DSOUND.dll + TbAudioR.dll (QMixer-based, not Miles)
- **F1Config.exe** (602KB) — configuration utility, **debug build**
  - PDB: `D:\Dev\F1\CONFIG\Debug\F1Config.pdb`
  - Build: 2000-03-07 00:40:24 UTC
  - Rich header: 470 compilation units
  - Contains `CUBE 3D Engine v` and `CUBE Render Technology` strings
  - `(c) 1993-1999 Image Space Incorporated` — confirms ISI copyright
  - Strings: `__OSC_LOCALE_STRING`, `CUBEASF`, `CUBEMAS` — same ISI formats as F1C

### [MERGE-READY] ISI Dev Tree — F1 2000 Era
```
D:\Dev\
├── F1\
│   ├── WIN32\Gold\           — f1_2000.pdb (game exe release build)
│   └── CONFIG\Debug\         — F1Config.pdb (config debug build)
└── F1_2000\SPLASHSCREENS\    — EA publisher asset path (not ISI)
```
This is the **earliest** ISI dev tree path found. Later evolution:
- F1 2000: `D:\Dev\F1\`
- F1 2002: `D:\Dev\Common\Source\` + `D:\Dev\F1_2002\Source\`
- F1C: `D:\dev\F1_1999_2002\Source\` (common+specific merged)
- NASCAR: `D:\Dev\NASCAR_200X\Source\`

### [MERGE-READY] Pre-isiMotor1 Architecture Differences
- **Graphics: DirectDraw + Direct3D** (DDRAW.dll), NOT pure D3D8 like F1C
- **Audio: QMixer/TbAudioR** (custom ISI audio), NOT Miles Sound System
- **Video: Custom MPEG decoder** (UVA_DATA, IDCT_DAT sections), NOT Bink
- **Copy protection: SafeDisc** (.ICD launcher pattern)
- **CUBE engine version**: `CUBE 3D Engine v` (no version number suffix found)
- **22 mangled C++ symbols** — all TbAudioSystem/TbSysCommand methods (audio library only)

### C++ Class Names (from mangled symbols in ICD)
- `TbAudioSystem` — audio engine main class
- `TbSysCommand` — audio command dispatch (Process, StopAll, SetDistanceMapping, etc.)
- `TbError` — audio error type
- `TbSoundPosition` — 3D audio positioning
- `CAudioConfig` — audio configuration
- `TbAudioBody` — audio body (virtual dispatch target)
These are from the TbAudioR.dll interface — ISI's pre-Miles audio system.

### Vehicle Physics Config Format (from .veh files)
F1 2000 uses `.veh` files with same parameter structure as F1C's `.hdv`/`.pm`:
- `[GENERAL]`: mass, center_height, weight_distrib, inertia, fuel, consumption
- `[AERODYNAMICS]`: frontwing_angle/func/center, rearwing_angle/func/center, downforce_coeff, drag_coeff
- `[SUSPENSION]`: geometry, antisway_front/rear, antipitch_susp
- `[CONTROLS]`: braking_ratio, rear_brake_distrib, front/rear_friction
- `[ENGINE]`: idle_rpm, auto_shift_rpm, maximum_rpm, engine_inertia, rpm_torque curves
- `[DRIVELINE]`: final_drive_ratio, clutch_eff, diff_lock, rear_drive
- `[GEARS]`: gear_reverse, gear (multiple)
- `[FAILURES]`: gear_loss, engine_mod/rpm3/lifetime/variance, brake_lifetime/variance
- `[FRONTLEFT/FRONTRIGHT/REARLEFT/REARRIGHT]`: friction, rolling, stiffness, load_sens, mass, inertia, radius, spring_coeff, bump_fast/slow, rebound_fast/slow, bumpstop_limit/len/coeff, ride_height, camber, cold_pressure, opt_warm, width
**Direct ancestor format to F1C.** Many field names identical. Confirms struct field naming for F1C physics structs.

### Save Files
- `.svm` files are **binary** (encrypted/compressed), not plaintext
- `CAMS.CFG` — camera config
- AI setups: default.svm, grip.svm, speed.svm (referenced in game.gdb)

### Game Data
- `game.gdb` — season config with AI qualifying/race times, scoring, AI setup assignments per track
- `.osc` files — ISI Options Screen Configuration (same format as F1C)
- `.dic` files — localization dictionaries
- `.mas` files — ISI archive format (tracks, vehicles, gizmos)
- `.tgq` files — video/animation (per-track intro movies)
- `.rcd` files — driver records (per-driver: AWurz, DCoulthard, etc.)
