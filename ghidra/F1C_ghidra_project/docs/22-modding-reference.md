# F1 Challenge 99-02 — Advanced Modding Reference

This document is a comprehensive reference for implementing mods for F1 Challenge 99-02 (`F1 Challenge Online.exe`), based on full reverse engineering of the 3.14 MB x86 PE32 binary (MSVC ~2002, 6,772 functions decompiled via Ghidra). It is written for an LLM or developer building modding tools, runtime frameworks, or binary patches.

For function-level detail, cross-reference `docs/01–21`. This document focuses on **how to modify the game** using the knowledge those docs contain.

---

## Table of Contents

1. [Executable Profile](#1-executable-profile)
2. [Mod Surface Overview](#2-mod-surface-overview)
3. [Layer 1 — Data File Modding](#3-layer-1--data-file-modding)
4. [Layer 2 — Runtime Memory Patching](#4-layer-2--runtime-memory-patching)
5. [Layer 3 — Binary Patching](#5-layer-3--binary-patching)
6. [Method A — D3D8 Proxy DLL](#6-method-a--d3d8-proxy-dll)
7. [Method B — VFXDrive.dll Hijack](#7-method-b--vfxdrivedll-hijack)
8. [Method C — Vtable Patching](#8-method-c--vtable-patching)
9. [Method D — Parser Extension (Ghost Fields)](#9-method-d--parser-extension-ghost-fields)
10. [Method E — Network Protocol Extension](#10-method-e--network-protocol-extension)
11. [Key Globals Quick Reference](#11-key-globals-quick-reference)
12. [Vehicle Struct Offset Map](#12-vehicle-struct-offset-map)
13. [Hookable Functions Catalog](#13-hookable-functions-catalog)
14. [Hardcoded Values Worth Patching](#14-hardcoded-values-worth-patching)
15. [File Format Parser Map](#15-file-format-parser-map)
16. [Existing Mod Precedent — F1CLiveUI](#16-existing-mod-precedent--f1cliveui)
17. [Safety and Compatibility Notes](#17-safety-and-compatibility-notes)

---

## 1. Executable Profile

| Property | Value |
|----------|-------|
| Binary | `F1 Challenge Online.exe` |
| Architecture | x86 PE32, 32-bit |
| Compiler | MSVC ~2002 (Visual C++ 6.0 / 7.0 era) |
| Size | 3.14 MB |
| Total functions | 6,772 decompiled |
| Documented functions | 2,413 full entries + 54 lightweight entries |
| Triaged functions | 7,108 (all classified by category) |
| Graphics API | DirectX 8 (d3d8.dll) |
| Networking | OpenPlay + Winsock2 (ws2_32.dll) |
| Audio | Miles Sound System + custom mixer |
| Compression | zlib 1.1.3 |
| Source path (from asserts) | `D:\dev\F1_1999_2002\Source\` |
| Original file extensions | `.cpp` (C++ source) |

---

## 2. Mod Surface Overview

Three layers of modification, from safest to most powerful:

| Layer | Method | Reversibility | Scope |
|-------|--------|---------------|-------|
| **Data files** | Edit `.svm`, `.hdv`, `.gdb`, `.tbc`, `.veh`, `.scn`, `.plr` | Fully reversible (backup originals) | Engine/tire/weather/damage parameters |
| **Runtime memory** | External process writes via `WriteProcessMemory`, or in-process via injected DLL | Volatile (revert on restart) | Any global or struct field at known address |
| **Binary patch** | Hex-edit the .exe at documented function addresses | Permanent until restored from backup | Hardcoded constants, logic branches, array limits |

Advanced methods (D3D8 proxy, VFXDrive hijack, vtable patching) are runtime techniques that combine the power of binary patching with the reversibility of data file modding — no .exe modification required.

---

## 3. Layer 1 — Data File Modding

### 3.1 Complete Parser Map

Every data file field the engine reads is parsed by known functions. Unrecognized field names are silently skipped.

#### Engine Power (`.svm`/`.hdv`, parser: `FUN_004f3c80`)

| Field | Effect |
|-------|--------|
| `FuelConsumption` | Fuel burn rate multiplier |
| `FuelEstimate` | Pre-race fuel calculation factor |
| `EngineInertia` | Rotational inertia of engine |
| `IdleRPMLogic` (min/max) | Idle RPM bounds |
| `IdleThrottle` | Throttle % at idle |
| `LaunchRPMLogic` (min/max) | Launch control RPM bounds |
| `RevLimitLogic` | Rev limiter threshold |
| `RPMTorque` | Power curve: (rpm, torque_throttle, torque_brake) points |

#### Engine Thermal (`.svm`/`.hdv`, parser: `FUN_004f3c80`)

| Field | Effect |
|-------|--------|
| `OptimumOilTemp` | Target oil temperature |
| `CombustionHeat` | Heat from combustion |
| `EngineSpeedHeat` | Heat from RPM |
| `OilMinimumCooling` | Minimum oil cooling rate |
| `OilWaterHeatTransfer` | Oil-to-water heat transfer coefficient |
| `WaterMinimumCooling` | Minimum water cooling rate |
| `RadiatorCooling` (min/max) | Radiator cooling bounds |

#### Engine Misc

| Field | Effect |
|-------|--------|
| `EngineEmission` (3 values) | Visual exhaust parameters |
| `OnboardStarter` | Starter motor enabled |
| `StarterTiming` (3 values) | Starter motor timing parameters |

#### Damage Model (`.svm`/`.hdv`, parser: `FUN_004f24f0`)

| Field | Effect |
|-------|--------|
| `FrontWingDetach`, `FrontWingRandom` | Front wing detachment threshold + randomness |
| `RearWingDetach`, `RearWingRandom` | Rear wing detachment |
| `WheelDetach`, `WheelBend`, `WheelRandom` | Wheel damage thresholds |
| `Part0–7 Detach/Random` | 8 detachable body parts |
| `RadiusAdd`, `RadiusMult`, `RadiusMax` | Body collision radius params |
| `AeroDiv`, `AeroMin`, `VertMult` | Aerodynamic damage factors |

#### Gearbox (parser: `FUN_0059d822` / `FUN_0059d8ab`)

Setup adjustment fields for gear ratios. Format: `.svm` or setup file, range `[0, 0x3ff00000)`.

Fields: `Gear1Setting` through `Gear10Setting`, `FinalDriveSetting`, `ReverseSetting`.

#### Brakes (parser: `FUN_00447d00`)

| Field | Effect |
|-------|--------|
| Brake bias slope | `_DAT_0059ea20` — bias per adjustment step |
| Brake bias intercept | Starting bias value |
| Max bias index | Number of adjustment steps |
| Display format | `"%4.1f:%4.1f"` (rear:front split) |
| Storage | Vehicle struct `+0x1564` through `+0x1580` |

#### Per-Wheel (parser: `FUN_004f2c60`, called 4× for FL/FR/RL/RR)

| Offset | Field |
|--------|-------|
| `+0xb8` | `BrakeOptimumTemp` (+273.15 K applied at load) |
| `+0xf0` | `BrakeWearRate` |
| `+0xf8` | `BrakeFailure` min |
| `+0x100` | `BrakeFailure` max |

#### Track Surface (parser: `FUN_004cdd80`, terrain config)

Per surface material type: `GripLevel`, `Resistance`, `BumpAmp`, `BumpWaveLen`, `Spring`, `Damper`, `CollFrict`.

#### AI Grip (parser: `FUN_004cf070`, track-specific `.gdb`)

`AIDryGrip`, `AIWetGrip` — per-track AI grip multipliers.

#### Tire Compounds (`.tbc`, parser: `FUN_004a4830`)

| Compound ID | Name |
|-------------|------|
| 2 | Hard |
| 3 | Soft |
| 4 | Intermediate |
| 5 | Wet |
| 6 | Monsoon |

#### Weather (`.gdb`, parser: `FUN_004fe0d0` / `FUN_004fe1e0`)

Wetness multipliers: Clear=0.0, Overcast≈0.007, Drizzle≈0.34, Monsoon≈0.61.
Grip multipliers: Normal=0.0 (full grip), Soaked≈0.05, Monsoon=1.0 (no grip).

#### Pit Window (`.gdb`, parser: `FUN_0059d74e`)

- `ReconPitOpen` → `DAT_007cec30` (float seconds, pit window open time)
- `ReconPitClosed` → `DAT_007cec54` (float seconds, pit window close time)

#### Season/Scoring (parser: `FUN_004c2a80` / `FUN_004c0910`)

`SeasonScoringInfo` — championship points table. Parsed via `thunk_FUN_0059d6a9` (1-indexed finish position to points). Only active when `DAT_007d0410` (RaceMode) == 3 or 4.

#### Vehicle Definition (`.veh`, parser: `FUN_004c3200`)

22 fields parsed including team name, driver, car number, model paths, nationality. Top-level vehicle identity file. Vehicle array: stride `0x424`, count stored at `DAT_008ac390`.

#### Scene Files (`.scn`, loader: `FUN_004c52c0`)

Scene array: stride `0x18c`, count at `DAT_008ac488`.

#### Top-Level Vehicle File Parser (`FUN_004f4270`, 8038 bytes)

The master `.svm`/`.hdv` loader. Reads all physics sections in sequence and dispatches to section-specific sub-parsers. All fields written by mods to `.svm` files are confirmed present in this parser.

### 3.2 Config File Parsing Mechanism

The engine uses a generic INI-style parser:
- `FUN_005897ca` — file read/tokenizer
- `FUN_00588410` — string compare (field name matching)
- `FUN_00566810` — string compare (section/key matching)
- `FUN_00499e20` — section entry reader
- `thunk_FUN_0059d6a9` — entry iterator

Fields are matched by exact string comparison. Unknown field names are silently skipped — this is exploitable (see Method D).

### 3.3 Season/GDB System

| GDB File | Season ID | Display ID |
|----------|-----------|------------|
| `F1_1999.gdb` | 0x1ec (492) | 0x1ea |
| `F1_2000.gdb` | 0x1f0 (496) | 0x1ee |
| `F1_2001.gdb` | 0x1f4 (500) | 0x1f2 |
| `F1_2002.gdb` | 0x1f8 (504) | 0x1f6 |

Season resolution: `FUN_00420cf0`. Team lookup: 17 teams (indices 1–0x11), IDs vary per season. Driver lookup: `FUN_00415d90` (150 string comparisons).

---

## 4. Layer 2 — Runtime Memory Patching

### 4.1 Key Globals (Direct Memory Addresses)

These are absolute virtual addresses in the game process. Read/write with `ReadProcessMemory`/`WriteProcessMemory` from external tool, or direct pointer dereference from injected DLL.

| Address | Type | Name | Effect |
|---------|------|------|--------|
| `0x007c56a4` | int | SessionType | 7=race, 6=quali, 0–5=practice |
| `0x007c56a8` | int | RacePhase | 0–7 phase progression |
| `0x007cea5c` | int | EngineWearMode | 0=off, 2=normal, 3=accelerated |
| `0x007cf080` | int | WeatherMode | 0–5 weather preset |
| `0x007cf134` | int | WeatherModeUI | 0–5 UI weather display |
| `0x007d00ec` | int | GameState | 1–7 state machine |
| `0x007d01a0` | int | AIDifficultySlider | 0–120 range |
| `0x007d0410` | int | RaceMode | 3/4=championship |
| `0x007d0308` | int | RaceActiveFlag | Nonzero when race running |
| `0x007d0c60` | float/double | TireWearMultiplier | Tire degradation rate |
| `0x005c329c` | int | VehicleCount | Number of active vehicles |
| `0x007c54e8` | ptr | PlayerVehiclePtr | Pointer to player's vehicle struct |
| `0x007c54f0` | ptr | VehiclePtrArray | Array of all vehicle struct pointers |
| `0x008acf9c` | int | TotalRaceLaps | Total laps in race |
| `0x007cebc4` | int | FormationLap | Formation lap active flag |
| `0x007ce958` | int | TireModelMode | Tire physics model selector |
| `0x005ea3d8` | float | TrackRefSpeed | AI reference speed for track |
| `0x008ac390` | int | VehicleFileCount | Loaded vehicle definitions |
| `0x008ac394` | ptr | VehicleArray | Vehicle data array (stride 0x424) |
| `0x008ac488` | int | SceneFileCount | Loaded scene definitions |
| `0x008ac490` | ptr | SceneArray | Scene data array (stride 0x18c) |
| `0x007d0434` | str | SeasonPath | Current season directory string |
| `0x005ec3d8` | str | SeasonDir | Season directory path |
| `0x005ec420` | str | TrackDir | Track directory path |
| `0x005ec438` | str | WeatherDir | Weather directory path |
| `0x005ec488` | str | PlayerFile | Player profile path |
| `0x005ec6d8` | str | PlayerDataPath | Player data directory |
| `0x007d2e48` | struct | SeasonScoringDB | Scoring database (stride 0x48c0) |
| `0x005bf9b0` | ptr | DriverDataTable | AI driver parameter table |
| `0x008aae70` | int | RingBufferCounter | QA/weather noise counter |
| `0x007cec30` | float | PitWindowOpen | Pit window open time (seconds) |
| `0x007cec54` | float | PitWindowClose | Pit window close time (seconds) |

### 4.2 Input Tables

| Address | Content |
|---------|---------|
| `0x005ecf0c` | Steering input lookup table |
| `0x005ed3ac` | Throttle input lookup table |
| `0x005ed3f0` | Brake input lookup table |
| `0x005ed434` | Analog axis mapping table |

### 4.3 Vehicle Struct Layout

Access individual vehicles via `VehiclePtrArray` (`0x007c54f0`). Each entry is a pointer to a vehicle struct. Player vehicle directly at `PlayerVehiclePtr` (`0x007c54e8`).

**Physics instance offsets:**

| Offset | Type | Field |
|--------|------|-------|
| `+0x1140` to `+0x115c` | double×4 | Front tire telemetry (4 channels) |
| `+0x1160` | byte[16] | Front compound flags |
| `+0x1170` | int | Current front compound index |
| `+0x1174` to `+0x117c` | int×3 | Compound selections: stops 2–4 |
| `+0x1178` | double | Secondary clamp min |
| `+0x117c` | double | Secondary clamp max |
| `+0x1180` | uint | PitStopFlag bitmask |
| `+0x1330` | double | Common double field (often speed/position) |
| `+0x153c` to `+0x1558` | double×4 | Rear tire telemetry |
| `+0x155c` | byte[16] | Rear compound flags |
| `+0x1564` to `+0x1580` | various | Brake bias fields |
| `+0x1db4` | double | Effective engine lifetime |
| `+0x1dbc` | double | LifetimeEngineRPM min |
| `+0x1dc4` | double | 1 / LifetimeEngineRPM max |
| `+0x1dcc` | double | LifetimeOilTemp min |
| `+0x1dd4` | double | 1 / LifetimeOilTemp max |
| `+0x0324` | int | RaceMode copy (from DAT_007d0410) |
| `+0x0da0` | double | Primary clamp min |
| `+0x0da4` | double | Primary clamp max |
| `+0x4060` | int | Finish position |
| `+0x4678` | char[0x3f] | Description (from .veh) |
| `+0x46b8` | char[0x3f] | Car number (from .veh) |
| `+0x4714` | str | Filename (from .veh) |

**Per-wheel corner struct (from `FUN_004f2c60`):**

| Offset | Type | Field |
|--------|------|-------|
| `+0xb8` | double | BrakeOptimumTemp (Kelvin, +273.15 applied) |
| `+0xf0` | double | BrakeWearRate |
| `+0xf8` | double | BrakeFailure threshold min |
| `+0x100` | double | BrakeFailure threshold max |

**Player options struct (from `FUN_004aa270`):**

| Offset | Stride | Count | Content |
|--------|--------|-------|---------|
| `+0x5c8` | 0x24 | 7 | FailureRate[0..6]: {current=2, min=0, max=3} |

### 4.4 How F1CLiveUI Does It (Proven Approach)

F1CLiveUI is a Java application that:
1. Opens game process via `OpenProcess(PROCESS_VM_WRITE, pid)`
2. Reads telemetry from shared memory via native bridge (`F1C_readLiveData.exe`)
3. Writes back via `WriteProcessMemory`

**Puncture injection:** Writes `0.77f` to `tireConditions[worstTire]` at offset `driverMemoryAddress - 4312`. Game then naturally degrades the tire — not instant flat. Removal writes `0.75f`.

**AI error injection:** Writes to vehicle struct offsets for `DriverErrorRace083` / `DriverErrorNonRace082` flags, forcing AI into error state for a scheduled time window.

**Puncture scheduling formula:**
```
loop_count = 20 + 5 * TirePuncturesFrequency
t = 30000/frequency + nextGaussian() * 50000/frequency
t *= (1.5 + (11 - frequency) * 0.5)
```
Frequency 2 (default) = ~0–1 per race. Frequency 5 = several per race.

---

## 5. Layer 3 — Binary Patching

Hex-edit `F1 Challenge Online.exe` at known function addresses to change hardcoded constants.

### 5.1 Methodology

1. Look up function in docs (e.g., `FUN_0041a3a0` — AI Formation Lap)
2. Note the hardcoded constant described in the doc entry
3. Open .exe in hex editor, navigate to function's virtual address minus image base (typically `0x00400000`)
4. Find the constant bytes within the function's byte range
5. Patch to desired value

File offset = Virtual Address - 0x00400000 (for default image base, verify in PE header).

### 5.2 High-Value Patch Targets

See Section 14 for the full catalog. Key categories:

- **AI behavior thresholds** — overtaking aggression, pit strategy triggers, formation lap timing
- **Array caps** — 128-vehicle limit, 20-entry sort buffer, 17-team limit
- **Physics constants** — collision response coefficients, suspension limits
- **Session state machine** — race phase transitions, qualifying format
- **Timer intervals** — update rates, timeout values

---

## 6. Method A — D3D8 Proxy DLL

### 6.1 Concept

Game imports `Direct3DCreate8` from `d3d8.dll` via import thunk at `0x0059b250`. Windows DLL search order loads a local `d3d8.dll` (in game directory) before the system one.

Create a proxy DLL that:
1. Exports `Direct3DCreate8` (and all other d3d8 exports)
2. Loads real `system32\d3d8.dll` internally
3. Forwards all calls to the real DLL
4. Intercepts specific calls for mod functionality

### 6.2 Hook Points

| Intercept | What you can do |
|-----------|----------------|
| `CreateDevice` | Get device pointer, hook vtable methods |
| `Present` / `EndScene` | Per-frame tick — read/write game memory, render overlays |
| `BeginScene` | Pre-frame setup |
| `DrawPrimitive` / `DrawIndexedPrimitive` | Shader replacement, visual mods |
| `CreateTexture` | Texture replacement/injection |

### 6.3 Capabilities

From within the Present hook (runs every frame):
- Read any `DAT_` global by direct pointer
- Read/write vehicle structs via `PlayerVehiclePtr` / `VehiclePtrArray`
- Render ImGui or custom DirectX overlays (telemetry HUD, debug panels)
- Implement per-frame game logic (dynamic weather, adaptive AI, tire wear curves)

### 6.4 Advantages

- Zero .exe modification
- Drop-in / remove to unmod
- Runs in-process (no `WriteProcessMemory` overhead)
- Compatible with all game versions (same d3d8 interface)
- Well-established technique (ENB, ReShade, dgVoodoo all work this way)

---

## 7. Method B — VFXDrive.dll Hijack

### 7.1 The Game's Built-In Plugin Interface

`FUN_004f8b50` at address `0x004f8b50` (26 bytes) does:

```c
HMODULE hLib = LoadLibraryA("VFXDrive.dll");
if (hLib == NULL) return 1;  // graceful failure — game continues

VFXOpen        = GetProcAddress(hLib, "VFXOpen");
VFXClose       = GetProcAddress(hLib, "VFXClose");
VFXZeroSet     = GetProcAddress(hLib, "VFXZeroSet");
VFXSetVideoMode = GetProcAddress(hLib, "VFXSetVideoMode");
VFXGetTracking = GetProcAddress(hLib, "VFXGetTracking");

if (all five resolved) { VFXOpen(); return 0; }
return 4;
```

Function pointers stored at:
- `0x008afc78` — DLL handle
- `0x008afc7c` — VFXOpen
- `0x008afc80` — VFXClose
- `0x008afc84` — VFXZeroSet
- `0x008afc88` — VFXSetVideoMode
- `0x008afc8c` — VFXGetTracking

### 7.2 Implementation

Write a DLL exporting these 5 functions:

```c
// Minimal VFXDrive.dll skeleton
__declspec(dllexport) int VFXOpen() {
    // Runs once at game startup. Game process fully loaded.
    // Initialize your mod framework here.
    // You are IN-PROCESS — direct memory access to all DAT_ globals.
    return 0;  // or nonzero to signal "no device" (game continues normally)
}

__declspec(dllexport) void VFXClose() {
    // Cleanup on game shutdown
}

__declspec(dllexport) void VFXZeroSet() {
    // Called to reset — use as needed
}

__declspec(dllexport) void VFXSetVideoMode(int mode) {
    // Receives video mode info
}

__declspec(dllexport) void VFXGetTracking(/* tracking data */) {
    // CALLED EVERY FRAME for force feedback polling.
    // This is your free tick function.
    // Read game state, apply modifications, run custom logic.
}
```

### 7.3 Advantages Over D3D8 Proxy

- Simpler — only 5 exports vs 85
- No need to forward graphics calls
- Game explicitly supports graceful failure
- `VFXGetTracking` provides a guaranteed per-frame callback
- No conflict with other D3D8 wrappers (dgVoodoo, ReShade)

### 7.4 Example Use Cases

From `VFXGetTracking` (every frame):
```c
// Dynamic weather based on lap count
int* totalLaps = (int*)0x008acf9c;
int* weatherMode = (int*)0x007cf080;
if (current_lap > *totalLaps / 2) {
    *weatherMode = 3;  // switch to rain at half distance
}

// Adaptive AI difficulty
int* aiDifficulty = (int*)0x007d01a0;
float gap = read_gap_to_leader();
if (gap > 5.0f) *aiDifficulty += 1;  // AI gets harder when player falls behind

// Live tire wear adjustment
double* tireWear = (double*)0x007d0c60;
*tireWear = compute_custom_wear_curve(current_lap, compound_type);
```

---

## 8. Method C — Vtable Patching

### 8.1 Concept

The game uses C++ virtual dispatch extensively. Vtable pointers are stored in known globals. Your docs map dispatch sites like:

```c
// From FUN_00470960:
(*(code **)(*DAT_007cd8c0 + 0x1c))(0x13);
// This calls: vtable[0x1c/4] = vtable[7] with argument 0x13
```

### 8.2 How to Patch

From injected DLL (D3D8 proxy or VFXDrive):

```c
// 1. Read vtable base from known global
int** vtable_ptr = *(int***)0x007cd8c0;

// 2. Save original function pointer at offset +0x1c
typedef int (*dispatch_fn)(int);
dispatch_fn original = (dispatch_fn)vtable_ptr[7];  // 0x1c / 4

// 3. Replace with your function
vtable_ptr[7] = (int)my_custom_dispatch;

// 4. Your function intercepts all calls
int my_custom_dispatch(int command) {
    if (command == 0x13) {
        // Custom handling for command 0x13
        do_custom_thing();
    }
    return original(command);  // forward to original
}
```

### 8.3 Known Vtable Globals

| Global | Vtable for | Known offsets |
|--------|-----------|---------------|
| `DAT_007cd8c0` | Game command dispatch | +0x1c (command dispatch), +0x44 (path resolve), +0x5c (search/filter) |
| `DAT_008b8f24` | D3D device wrapper | +0x04 (transform), +0x08 (blit) |
| Vehicle struct base | Per-vehicle vtable | Documented in `docs/10-vehicle-physics.md` |

### 8.4 Advantages

- Surgical — replace one behavior without touching anything else
- Original function preserved — call it as fallback
- No byte patching
- Reversible at any time by restoring original pointer

---

## 9. Method D — Parser Extension (Ghost Fields)

### 9.1 Concept

Game parsers use `FUN_00566810` / `FUN_00588410` (string compare) to match field names in data files. Unrecognized field names are silently skipped. This means data files can contain extra fields the game ignores.

### 9.2 Implementation

**Step 1:** Add custom-prefixed fields to data files:
```ini
[ENGINE]
RPMTorque=(500, 0, 0)
FuelConsumption=0.00123
; Standard fields above — game reads them normally

X_DynamicWeatherEnabled=1
X_WeatherChangeLap=15
X_WeatherTarget=3
X_AdaptiveAIEnabled=1
X_AdaptiveAIRange=10,120
X_CustomTireWearCurve=1.0,0.95,0.88,0.75,0.60
; Custom fields above — game silently skips them
```

**Step 2:** Your proxy/VFXDrive DLL reads the same data file at startup, parses `X_`-prefixed fields with your own INI parser, and stores the values.

**Step 3:** During `VFXGetTracking` / `Present` hook, apply the custom field values as runtime memory patches.

### 9.3 Advantages

- Modders edit familiar files with familiar syntax
- No separate config file format to learn
- `X_` prefix convention prevents collision with any future official fields
- Extensible without touching the DLL — add new `X_` fields, DLL interprets them
- Multiple mods can coexist if they use different prefixes (`X_`, `Y_`, `MOD_`)

---

## 10. Method E — Network Protocol Extension

### 10.1 Packet Routing Architecture

Network packet handler documented in `docs/21-audio-network-internals.md`:

- Packets routed by type class extracted from **top 3 bits** of first word (`param_2[0]`)
- Type class mapping: `1→class 0`, `2/3→class 1`, `4→class 2`, `6→class 3`, `default→-1 (reject)`
- Queue lookup: `(class + 7) * 16` offset into queue array
- Packet structure: 0x20-byte buffer, allocated via `operator_new`
- Byte order: `htonl`/`htons` for network byte order
- Class handler notification: `FUN_004b47a0`
- Free list globals: head=`0x008ab700`, tail=`0x008ab704`, prev=`0x008ab708`, count=`0x008ab70c`

### 10.2 Extension Approach

Type classes 5 and 7 (top 3 bits = `101` and `111`) are not mapped — packets with these types are rejected to `-1`. A custom multiplayer system could:

1. **Custom server** sends packets with unused type class in header
2. **Client-side proxy DLL** intercepts `recv` (Winsock import thunk) or hooks the packet router
3. Proxy identifies custom packets by type class, extracts payload
4. Proxy writes to game memory based on payload commands
5. Original game packet flow is untouched

### 10.3 Possible Applications

| Command | Implementation |
|---------|---------------|
| Server-synced weather changes | Write `DAT_007cf080` on all clients simultaneously |
| Virtual Safety Car | Reduce all AI speed, set yellow flag state |
| Red flag / session restart | Manipulate `DAT_007c56a8` (RacePhase) |
| Real-time penalties | Write time penalties to vehicle struct offsets |
| Sprint qualifying format | Server controls session transitions via phase manipulation |
| Synchronized tire model | Broadcast tire wear curves to all clients |

---

## 11. Key Globals Quick Reference

Organized by subsystem for modding use. All addresses are virtual addresses in the running process.

### Session State
| Address | Name | Values |
|---------|------|--------|
| `0x007c56a4` | SessionType | 0–5=practice, 6=quali, 7=race |
| `0x007c56a8` | RacePhase | 0–7 progression |
| `0x007d00ec` | GameState | 1–7 |
| `0x007d0308` | RaceActiveFlag | 0=inactive, nonzero=active |
| `0x007d0410` | RaceMode | 3 or 4=championship |
| `0x007cebc4` | FormationLap | Formation lap flag |
| `0x008acf9c` | TotalRaceLaps | Lap count for race |

### Vehicle
| Address | Name | Notes |
|---------|------|-------|
| `0x007c54e8` | PlayerVehiclePtr | Direct pointer to player struct |
| `0x007c54f0` | VehiclePtrArray | All vehicles |
| `0x005c329c` | VehicleCount | Active vehicle count |
| `0x008ac390` | VehicleFileCount | Loaded .veh files |
| `0x008ac394` | VehicleArray | Data array, stride 0x424 |

### Physics/Tires/Weather
| Address | Name | Notes |
|---------|------|-------|
| `0x007d0c60` | TireWearMultiplier | Global wear rate |
| `0x007ce958` | TireModelMode | Physics model selector |
| `0x007cf080` | WeatherMode | 0–5 preset |
| `0x007cea5c` | EngineWearMode | 0/2/3 |

### AI
| Address | Name | Notes |
|---------|------|-------|
| `0x007d01a0` | AIDifficultySlider | 0–120 |
| `0x005ea3d8` | TrackRefSpeed | AI reference speed |
| `0x005bf9b0` | DriverDataTable | AI driver parameters |
| `0x008aae70` | RingBufferCounter | QA/weather noise |

### Paths (String Pointers)
| Address | Content |
|---------|---------|
| `0x007d0434` | Season path string |
| `0x005ec3d8` | Season directory |
| `0x005ec420` | Track directory |
| `0x005ec438` | Weather directory |
| `0x005ec488` | Player file path |
| `0x005ec6d8` | Player data path |

---

## 12. Vehicle Struct Offset Map

Full vehicle struct layout for runtime memory access. Base pointer obtained from `VehiclePtrArray[index]` or `PlayerVehiclePtr`.

### Core Identity
| Offset | Type | Field |
|--------|------|-------|
| `+0x0324` | int | RaceMode copy |
| `+0x4060` | int | Finish position |
| `+0x4678` | char[63] | Description |
| `+0x46b8` | char[63] | Car number |
| `+0x4714` | str | Filename |

### Tire System
| Offset | Type | Field |
|--------|------|-------|
| `+0x1140` to `+0x115c` | double×4 | Front tire telemetry channels |
| `+0x1160` | byte[16] | Front compound flags |
| `+0x1170` | int | Current front compound index |
| `+0x1174` to `+0x117c` | int×3 | Pit stop compound selections (stops 2–4) |
| `+0x1180` | uint | PitStopFlag bitmask |
| `+0x153c` to `+0x1558` | double×4 | Rear tire telemetry channels |
| `+0x155c` | byte[16] | Rear compound flags |

### Engine
| Offset | Type | Field |
|--------|------|-------|
| `+0x1db4` | double | Effective engine lifetime |
| `+0x1dbc` | double | LifetimeEngineRPM min |
| `+0x1dc4` | double | 1 / LifetimeEngineRPM max |
| `+0x1dcc` | double | LifetimeOilTemp min |
| `+0x1dd4` | double | 1 / LifetimeOilTemp max |

### Brakes
| Offset | Type | Field |
|--------|------|-------|
| `+0x1564` to `+0x1580` | various | Brake bias parameters |

### Suspension/Dynamics
| Offset | Type | Field |
|--------|------|-------|
| `+0x0da0` | double | Primary clamp min |
| `+0x0da4` | double | Primary clamp max |
| `+0x10c` | ptr | Linked list head (sub-component) |
| `+0x110` | int | Linked list count |

### Ghidra Offset Patterns

When reading Ghidra pseudocode to find new offsets:

| Pattern | Meaning |
|---------|---------|
| `*(double *)(ptr + 0x1330)` | 8-byte double at struct offset 0x1330 |
| `param_1[0x4a]` | Int-indexed: real byte offset = 0x4a × 4 = 0x128 |
| `*(int *)(ptr + 0xXXX)` | 4-byte int at offset |
| `*(float *)(ptr + 0xXXX)` | 4-byte float at offset |

**False positive warning:** Offsets `+0x1130`/`+0x1132` also appear in DirectX device structs. Only treat as vehicle struct offsets if the function has NO DirectX API calls (`CreateDevice`, `IDirect3D`, `DrawPrimitive`).

---

## 13. Hookable Functions Catalog

Functions tagged `hookable` in the documentation — their behavior can be intercepted via vtable patching, detour hooking, or import redirection.

### AI System (`docs/02-ai-system.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x0040de60` | AI Behavior State Machine | Core AI decision loop |
| `0x00418ee0` | AI Target Driver Selection | Who AI targets for overtake |
| `0x00419690` | AI Overtake/Defend State Change | Attack/defend mode switching |
| `0x00424790` | AI Driver Struct Init | AI initialization — inject custom params |
| `0x00424cd0` | AI Command/Message Queue Dispatcher | All AI commands flow through here |
| `0x00424e70` | AI Main Update / Race Phase State Machine | Per-frame AI update tick |
| `0x00425920` | AI Racing Line / Overtaking Gap | Gap calculation for passes |
| `0x00429eb0` | Race-Phase Pit Entry Trigger | When AI decides to pit |
| `0x00429ee0` | Command Queue Response Handler | AI command responses |
| `0x0042a110` | Force Pit Exit / Advance State | Pit exit control |
| `0x0042a6f0` | Post-Pit Cleanup / Exit | Post-pit state reset |
| `0x0042a7d0` | Opponent Proximity Scan & Team Recognition | Proximity + team detection |
| `0x0042ae60` | Server Session Gate Check | Multiplayer session validation |
| `0x0042aee0` | Pit Stop Blocking Condition | Pit lane blocking logic |
| `0x0042af70` | Overtaking / Passing Decision | Core overtake decision |
| `0x004336f0` | Load AI Driver Names from Config | Driver name loading |
| `0x004339e0` | Look Up Vehicle Config Entry | Config lookup |
| `0x00433b60` | Add Vehicle Config Entry to Linked List | Config insertion |
| `0x004bf390` | AI Driver Sorting / Priority | AI priority ordering |

### Session / Race Logic (`docs/06-session-race-logic.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x004b1780` | InputClamp | Input processing — remap controls |
| `0x004b9890` | Race Tick Advance / Frame Dispatch | Main frame tick |
| `0x004b9b80` | Session Timestamp / AI Sort Trigger | Session time events |

### Engine Architecture (`docs/01-engine-architecture.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x00434460` | Car Selection State Machine | Car selection flow |
| `0x00465300` | Message Dispatch Node Allocator | Message system |

### Physics (`docs/17-physics-collision.md`, `docs/18-physics-dynamics.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x0044f7d0` | ContactFlagReadClear | Collision flag management |
| `0x004320a0` | PhysicsObjectAlloc | Physics object creation |
| `0x00448570` | PhysicsSubComponentDestroy | Physics cleanup |

### Renderer (`docs/19-renderer.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x00504731` | D3D Vertex Buffer Copy/Merge | Vertex manipulation |
| `0x00506003` | D3D Vertex Buffer Creation | Buffer allocation |

### Audio / Network (`docs/21-audio-network-internals.md`)

| Address | Name | Hook value |
|---------|------|------------|
| `0x00562d20` | SocketArrayCreate | Network socket setup |

---

## 14. Hardcoded Values Worth Patching

Functions tagged `Moddability: hardcoded` contain constants baked into the .exe. These cannot be changed via data files — only binary patching or runtime memory writes to the code section can alter them.

### AI Behavior (from `docs/02-ai-system.md`)

| Address | Function | What's hardcoded |
|---------|----------|-----------------|
| `0x0041a0c0` | AI Out-of-Track Event | Track limit trigger thresholds |
| `0x0041a170` | AI Vehicle Damage Event | Damage response thresholds |
| `0x0041a200` | AI Pit Strategy State | Pit decision parameters |
| `0x0041a3a0` | AI Formation Lap / Race Start | Formation lap behavior constants |
| `0x0041a8c0` | AI Session Event Audio | Audio trigger thresholds |
| `0x0041aa10` | AI Session Phase Counter | Phase transition timing |
| `0x00455580` | Keyboard Scancode-to-ASCII | Key mapping table |

### AI Data Structures

- 20-entry limit, stride 0x20 — hardcoded array cap for AI sorting
- `DAT_005ea2cc` gates AI update rate — hardcoded tick frequency

### Race Logic (from `docs/06-session-race-logic.md`)

Hundreds of hardcoded values throughout 785 functions. Key categories:
- Race phase transition thresholds
- Jump start detection parameters
- Pit lane speed limits
- Grid position calculation
- Retirement/DNF triggers
- Formation lap spacing

### Physics (from `docs/17, 18`)

- Collision response coefficients
- Suspension force limits
- Contact patch calculation constants
- Friction model parameters

### General Limits

| Limit | Value | Location |
|-------|-------|----------|
| Vehicle array cap | 128 | Various allocation functions |
| Sort buffer entries | 20 | AI sorting (stride 0x20) |
| Team count | 17 | Season/team lookup functions |
| Tire compounds | 5 | Compound ID range (2–6) |
| Weather presets | 6 | Mode range (0–5) |
| Race phases | 8 | Phase state machine (0–7) |

---

## 15. File Format Parser Map

Complete mapping of file formats to their parser functions.

| Format | Parser Function | Size (bytes) | Doc |
|--------|----------------|--------------|-----|
| `.svm`/`.hdv` (master) | `FUN_004f4270` | 8,038 | `docs/08` |
| `.svm`/`.hdv` (engine) | `FUN_004f3c80` | varies | `docs/08` |
| `.svm`/`.hdv` (damage) | `FUN_004f24f0` | varies | `docs/08` |
| `.svm`/`.hdv` (per-wheel) | `FUN_004f2c60` | varies | `docs/08` |
| `.veh` | `FUN_004c3200` | varies | `docs/08` |
| `.scn` | `FUN_004c52c0` | varies | `docs/08` |
| `.gdb` (season) | `FUN_00420cf0` | varies | `docs/08` |
| `.gdb` (weather) | `FUN_004fe0d0` / `FUN_004fe1e0` | varies | `docs/05` |
| `.gdb` (AI grip) | `FUN_004cf070` | varies | `docs/09` |
| `.gdb` (pit window) | `FUN_0059d74e` | varies | `docs/06` |
| `.tbc` (tire compound) | `FUN_004a4830` | varies | `docs/04` |
| `.plr`/`.plg` (player) | `FUN_004c18b0` | varies | `docs/08` |
| Terrain config | `FUN_004cdd80` | varies | `docs/09` |
| Setup file (gears) | `FUN_0059d822` / `FUN_0059d8ab` | varies | `docs/10` |
| Scoring | `FUN_004c2a80` / `FUN_004c0910` | varies | `docs/06` |

### String Parsing Infrastructure

| Function | Role |
|----------|------|
| `FUN_005897ca` | File read / tokenizer |
| `FUN_00588410` | String compare (field name matching) |
| `FUN_00566810` | String compare (section/key matching) |
| `FUN_00499e20` | Section entry reader |
| `thunk_FUN_0059d6a9` | Entry iterator |
| `FUN_00566650` | Path registry (resolves file paths) |
| `FUN_0058815f` | Path sprintf |

---

## 16. Existing Mod Precedent — F1CLiveUI

`F1CLiveUIPlugin` (`F1CUILive.jar`) is the only known advanced modding tool for F1C. Understanding its approach validates the memory patching methods described here.

### Architecture
- Standalone Java application (not a game plugin)
- Uses JNA → `Kernel32.dll` → `OpenProcess(PROCESS_VM_WRITE, pid)`
- Reads telemetry via `F1C_readLiveData.exe` (native shared memory bridge)
- Writes back via `WriteProcessMemory`

### Known Offsets Used
- Tire conditions: `driverMemoryAddress - 4312`
- AI error flags: `DriverErrorRace083`, `DriverErrorNonRace082` in vehicle struct
- Puncture value: writes `0.77f` (injection) / `0.75f` (cleanup)

### Scheduling System
- Per-driver AI error frequency from `.plg` file or `magic.ini` fallback
- Qualifying session multiplier (adjusts error density for session length)
- Gaussian-distributed event timing with configurable frequency parameter

### What We've Added Beyond F1CLiveUI
- F1CLiveUI knew ~10–20 offsets. This project documents ~400+ struct offsets.
- F1CLiveUI operated blind on globals. We've mapped ~50 named globals with exact semantics.
- F1CLiveUI used external process memory access. Methods A/B enable in-process access (faster, more capable).
- F1CLiveUI couldn't intercept game logic. Vtable patching (Method C) enables behavioral replacement.

---

## 17. Safety and Compatibility Notes

### Reversibility
| Method | How to revert |
|--------|---------------|
| Data file edits | Restore original files from backup |
| D3D8 proxy DLL | Delete `d3d8.dll` from game directory |
| VFXDrive.dll | Delete `VFXDrive.dll` from game directory |
| Vtable patches | Restart game (patches are in-memory only) |
| Binary patches | Restore original .exe from backup |

### Multiplayer Considerations
- Memory modifications are local only — they desync from other players
- Network protocol extensions require matching client/server modifications
- Data file changes must match across all players for fair play
- Consider implementing server-validated changes only for competitive use

### Stability Risks
| Risk | Mitigation |
|------|------------|
| Writing wrong offset | Verify all offsets against docs AND source .c files before deployment |
| Vtable corruption | Always save original pointer; restore on DLL unload |
| Thread safety | Game is largely single-threaded, but D3D callbacks are on render thread |
| Version mismatch | All addresses are for one specific .exe build — verify PE checksum |
| Stack corruption | Never modify function prologues/epilogues via binary patch |

### Address Verification

All addresses in this document are for one specific build of `F1 Challenge Online.exe`. Before using:

1. Verify the .exe file size matches (3.14 MB)
2. Check PE image base (expected: `0x00400000`)
3. Spot-check 2–3 known string references at documented addresses
4. If addresses don't match, all offsets need recalculation using Ghidra on the target build

### Cross-Reference

For full function-level detail, consult:

| Topic | Document |
|-------|----------|
| Engine architecture | `docs/01-engine-architecture.md` |
| AI system (62 functions) | `docs/02-ai-system.md` |
| Engine wear / damage | `docs/03-engine-wear-damage.md` |
| Tire system | `docs/04-tire-system.md` |
| Weather system | `docs/05-weather-system.md` |
| Session / race logic (785 functions) | `docs/06-session-race-logic.md` |
| Pit system | `docs/07-pit-system.md` |
| File formats (187 functions) | `docs/08-file-formats.md` |
| Track system (78 functions) | `docs/09-track-system.md` |
| Vehicle physics (72 functions) | `docs/10-vehicle-physics.md` |
| F1CLiveUI plugin | `docs/11-plugin-f1cliveui.md` |
| Globals reference | `docs/12-globals-reference.md` |
| Struct offsets | `docs/13-struct-offsets.md` |
| Moddable fields | `docs/16-moddable-fields.md` |
| Physics / collision (342 functions) | `docs/17-physics-collision.md` |
| Physics / dynamics (225 functions) | `docs/18-physics-dynamics.md` |
| Renderer (265 functions) | `docs/19-renderer.md` |
| Math utilities (182 functions) | `docs/20-math-utilities.md` |
| Audio / network (146 functions) | `docs/21-audio-network-internals.md` |
| Master triage index (7,108 entries) | `docs/decompiled_full_index_final.md` |
