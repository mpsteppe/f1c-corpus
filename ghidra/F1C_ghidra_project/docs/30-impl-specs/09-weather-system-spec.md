# Implementation Spec: Weather System

Source: docs/05-weather-system.md  |  Functions: 6 documented (+ 3 referenced helpers)  |  Date: 2026-07-15

---

## Overview

The weather system manages track surface wetness, ambient temperature, and track temperature for each session. It runs **once at session initialization** — called from `Game::Init` (FUN_0042d6b0) via `FUN_004fcaa0` (Weather Initializer). It does **not** run per-frame or per-tick; weather state is static for the duration of a session once set.

The system owns one global: `WeatherMode` (DAT_007cf080, stored per-season at `&DAT_007cf080 + seasonIndex * 9`). It provides two name-to-float lookup tables used by the GDB/track system to determine wetness and grip from weather condition strings.

**Data flow:**
1. Game init calls `FUN_004fcaa0` → checks `WeatherMode`
2. If mode == 0 (Selected Season), reads `weather.txt` from `WeatherDir` (DAT_005ec438) via `FUN_004fe820`
3. If mode == 1 (From GDB), reads `Weather` section from track GDB via `FUN_004fe7c0` → `FUN_004fe350`
4. Hardcoded modes (3=Raining, 4=Overcast, 5=Monsoon, default=Dry) skip file I/O and set fixed wetness values
5. Weather data (OnPathWetness, OffPathWetness, AmbientTemp, TrackTemp) is stored in a per-session struct

**Interfaces with:**
- **Track system** (docs/09): Reads `Weather` section from `.gdb` files for mode 1
- **Session/Race logic** (docs/06): Wetness values feed into tire grip calculations
- **Setup system** (docs/08): Reads from `weather.txt` file in `WeatherDir`
- **Renderer** (docs/19): Fog and sun position parameters affect visual rendering
- **AI system** (docs/02): Wetness affects AI driving ability multipliers

---

## Data Structures

### WeatherStateStruct (param_1 — weather instance)

Describes the weather state for a session. Populated by `FUN_004fe350` (weather data reader) or by hardcoded defaults.

| Offset | Type | Field | Notes |
|--------|------|-------|-------|
| +0x0c | float | UnknownFlag | Init 1.0 |
| +0x10 | int | UnknownID | Init -1 (0xFFFFFFFF) |
| +0x18 | float | UnknownNegOne | Init -1.0 |
| +0x20 | int | InitZero | Init 0 |
| +0x28 | float | OnPathWetness | 0.0 (dry) – 1.0 (fully wet) |
| +0x2c | float | OffPathWetness | Must be ≥ OnPathWetness (enforced at load) |
| +0x30 | float | AmbientTemp | °C, default 20 |
| +0x34 | float | TrackTemp | °C, default AmbientTemp + 2 |
| +0x38 | ptr | ChangeListHead | Linked list of {time, AmbientTemp, Conditions} per-minute nodes |
| +0xa4 | float | UnknownNegOneB | Init -1.0 |
| +0xb4 | float | SunPosX | Sun/light world position X (× DAT_0059e460) |
| +0xb8 | float | SunPosY | Sun/light world position Y (× DAT_0059e460) |
| +0xbc | float | SunPosZ | Sun/light world position Z (× DAT_0059e460) |
| +0xc0 | float | FogParam1 | Init 0.75 |
| +0xc4 | float | FogParam2 | Init 0.75 |
| +0xc8 | float | FogParam3 | Init 0.75 |
| +0xcc | float | FogParam4 | Init 0.5 |
| +0xd0 | float | FogParam5 | Init 0.5 |
| +0xd4 | float | FogParam6 | Init 0.5 |
| +0xe4 | float | Unknown175 | Init 175.0 |
| +0xe8 | float | Unknown700 | Init 700.0 |
| +0xec | float | DerivedSunAngle | Computed from sun position |
| +0xf0 | float | UnknownZero | Init 0 |
| +0xf4 | float | Unknown150 | Init 150.0 |
| +0xf8 | float | UnknownSmall | Init 0.01 |

Total size estimated: 0x100+ bytes. No stride observed — single instance per session.

### WeatherChangeNode (linked list node at +0x38)

Per-minute weather change node. Stored as a linked list traversed during weather file writing.

| Offset | Type | Field |
|--------|------|-------|
| +0x00 | ptr | NextNode |
| +0x04 | float | TimeMinutes |
| +0x08 | float | AmbientTemp |
| +0x0c | (string?) | Conditions |

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007cf080 | int | WeatherMode | 0=SelectedSeason, 1=FromGDB, 3=Raining, 4=Overcast, 5=Monsoon, other=Dry |
| DAT_008ab274 | float[256] | WeatherNoiseTable | Random noise table (256 floats) for weather/particle variation |
| DAT_008aae70 | int | RingBufferCounter | Shared counter indexing into WeatherNoiseTable (also used by QA noise) |

### WeatherMode values

| Value | Mode | Behavior |
|-------|------|----------|
| 0 | Selected Season | Reads `weather.txt` from WeatherDir |
| 1 | From GDB | Reads `Weather` section from track GDB |
| 3 | Raining | Hardcoded wetness = 0.65 |
| 4 | Overcast | Hardcoded wetness = 0.82 |
| 5 | Monsoon | Hardcoded wetness = 0.94 |
| other | Dry | Hardcoded wetness = 0.30 |

Note: WeatherMode is stored per-season at `&DAT_007cf080 + seasonIndex * 9`. Season index comes from `RaceMode` (DAT_007d0410). The UI constructor (`FUN_00470da0`) sets the weather pointer as `&DAT_007cf080 + DAT_007d0410 * 9`.

---

## Public API — Entry Points

### FUN_004fcaa0 — Weather Initializer

**Inferred signature:** `void WeatherInit(WeatherStateStruct* weatherState)`
**Called from:** Game::Init (FUN_0042d6b0, docs/01) — once per session start
**Called by (from callers.json):** 0x0042d6b0 (Game::Init)

**What it does:**
1. Sets defaults on the weather struct (param_1):
   - +0x0c = 1.0 (unknown flag)
   - +0x10 = -1 (unknown ID)
   - +0x18 = -1.0
   - +0xa4 = -1.0
   - +0xe4 = 175.0
   - +0xe8 = 700.0
   - +0xf0 = 0
   - +0xf4 = 150.0
   - +0xf8 = 0.01
2. Computes sun/light position: stores track position × DAT_0059e460 (AlphaScaleFactor) at +0xb4–+0xbc
3. Computes derived sun angle at +0xec from sun position
4. Sets fog params at +0xc0–+0xd4: 0.75 for first three, 0.5 for next three
5. Calls FUN_004fefc0 (fog init with constant 0.125)
6. Calls FUN_004fba10 (weather state init)
7. If `DAT_007cf080 == 0` (Selected Season mode):
   - Loads `weather.txt` from DAT_005ec438 (WeatherDir) directory via FUN_004fe820
   - WeatherNoiseTable (DAT_008ab274) applies variance: each entry × 0.05
   - RingBufferCounter (DAT_008aae70) consumed for noise indexing

**Side effects:**
- Writes: WeatherMode (DAT_007cf080) — used to select load path
- Writes: WeatherNoiseTable (DAT_008ab274) — seeded with variance
- Writes: RingBufferCounter (DAT_008aae70) — consumed
- Writes: Fog state via FUN_004fefc0
- Writes: Weather state struct fields specified above
- Calls: FUN_004fba10, FUN_004fefc0, (conditionally) FUN_004fe820

### FUN_004fe820 — Weather File Writer

**Inferred signature:** `void WriteWeatherFile(WeatherStateStruct* weatherState, const char* weatherDir)`
**Called from:** FUN_004fcaa0 (Weather Initializer) when WeatherMode == 0
**Callers:** Not found in callers.json (anonymous/hard-to-find call chain)

**What it does:**
1. Opens `weather.txt` in the weather directory for writing
2. Writes 8 session entries (each session writes):
   - `Conditions` (interpolated from weather change linked list)
   - `OnPathWetness` × 100.0 (percentage)
   - `OffPathWetness` × 100.0 (percentage)
   - `AmbientTemp` (raw float)
   - `TrackTemp` (raw float)
3. Iterates per-minute change nodes (linked list at +0x38):
   - For each change with time diff ≤ DAT_005acb08 threshold, writes the change data

**Constants:**
- DAT_0059e6f8 = 100.0 (percentage conversion for wetness)
- DAT_0059e5fc = time step per weather change
- DAT_005acb08 = minute threshold for weather changes

**Side effects:**
- Writes `weather.txt` to WeatherDir

### FUN_004fe7c0 — Weather Section Reader (GDB wrapper)

**Inferred signature:** `void ReadWeatherSection(WeatherStateStruct* weatherState, const char* gdbFilePath)`
**Called from:** Weather Initializer when WeatherMode == 1 (From GDB)
**Callers:** Not found in callers.json

**What it does:**
1. Opens the specified file
2. Finds the `[Weather]` section
3. Calls FUN_004fe350 (weather data reader) to parse wetness/temperature values into the weather state struct

**Side effects:**
- Reads: Track GDB file
- Calls: FUN_004fe350

### FUN_004fe350 — Weather Data Reader (lower-level)

**Inferred signature:** `void ParseWeatherData(WeatherStateStruct* weatherState, FILE* file)`
**Called from:** FUN_004fe7c0 (Weather Section Reader)

**What it does:**
1. Parses weather data from the current file position into the struct:
   - +0x28 = OnPathWetness (float)
   - +0x2c = OffPathWetness (float)
   - +0x30 = AmbientTemp (float)
   - +0x34 = TrackTemp (float)
   - +0x38 = linked list of {time, temperature, conditions} per-minute changes
2. Enforces constraint: If `OffPathWetness < OnPathWetness`, sets `OffPathWetness = OnPathWetness`
   (the grooved racing line can't be wetter than the marbles)

**Side effects:**
- Writes: Weather state struct fields +0x28 through +0x38
- Allocates: Linked list nodes for per-minute changes

### FUN_004fe0d0 — Weather Name → Wetness Multiplier

**Inferred signature:** `float GetWetnessFromName(const char* weatherName)`
**Called from:** GDB/track system (docs/09) when loading track weather section
**Callers:** Not found in callers.json

**What it does:**
1. Compares input string against known weather names using FUN_00588410 (string compare):
   - (empty string / DAT_005d6fa4) → 0.0 (DAT_005ad324)
   - (unknown / DAT_005d6f9c) → ~0.001 (DAT_0059e8b4)
   - "Clear" → 0.0 (DAT_0059e4e8)
   - "Overcast" → ~0.007 (DAT_0059e8f8)
   - "Drizzle" → ~0.34 (DAT_005ad320)
   - (unknown / DAT_005d6f84) → ~0.46 (DAT_0059e908)
   - "Monsoon" → ~0.61 (DAT_005ad31c)
2. **Fallback:** If no match, parses the name as float via FUN_0058850f, multiplies by DAT_0059e444, clamps to [0, 1]

**Calls:** FUN_00588410 (string compare, docs/06), FUN_0058850f (parse float, docs/20)

**Return value:** Float wetness multiplier, 0.0 = dry, 1.0 = fully wet

**Moddability:** Yes — moddable field. GDB weather severity values are validated/clamped.

### FUN_004fe1e0 — Weather Severity → Grip Multiplier

**Inferred signature:** `float GetGripFromSeverity(const char* severityName)`
**Called from:** GDB/track system (docs/09), likely used by tire/vehicle physics
**Callers:** Not found in callers.json

**What it does:**
1. Compares input string against known severity names using FUN_00588410:
   - (normal / PTR_DAT_005c6e98) → 0.0 (DAT_0059e440) — no grip reduction
   - (light rain / DAT_005d6fb4) → ~0.002 (DAT_0059e7f8)
   - (moderate / PTR_DAT_005c7234) → ~0.01 (DAT_0059e450)
   - "Soaked" → ~0.05 (DAT_0059e7fc)
   - "Monsoon" → 1.0 (DAT_0059e43c) — full grip reduction
2. **Fallback:** If no match, parses as float via FUN_0058850f, multiplies by DAT_0059e444, clamps to [0, 1]

**Calls:** FUN_00588410 (string compare, docs/06), FUN_0058850f (parse float, docs/20)

**Return value:** Float grip multiplier, 0.0 = full grip (no rain effect), 1.0 = no grip (monsoon)

**Note:** This is the INVERSE of wetness — grip = 0.0 means full grip (dry conditions), grip = 1.0 means zero grip (monsoon). This maps directly to tire grip reduction factor.

**Moddability:** Yes — moddable field. Grip multiplier range [0, 1] confirmed.

### FUN_00470da0 — Weather Mode UI Constructor

**Inferred signature:** `void WeatherModeUI_Init(void* uiWidget)`
**Source:** options/UI module
**Called from:** Options/menu system when player opens weather settings

**What it does:**
1. Sets vtable to PTR_FUN_005a09c0
2. Weather ptr = `&DAT_007cf080 + DAT_007d0410 * 9` (per-season weather slot)
3. Sets up 5 weather mode options in the UI list:
   - param_1[0xc9] = 5 (option count)
   - param_1[0xca] = 0 (default selected index)
   - param_1[0xcb] = 1 (active flag)
   - param_1[0xcc] = 1
   - param_1[0xcd] = 0x19b (scroll offset)
4. Calls FUN_00486f30 for each option string to register them sequentially

**UI Options presented:**
1. Selected Season (reads weather from season data)
2. Monsoon (full wet) — writes WeatherMode = 5
3. Raining (wet) — writes WeatherMode = 3
4. Overcast (damp) — writes WeatherMode = 4
5. Changing Weather (dynamic weather) — writes WeatherMode = ? (likely 2)

**Calls:** FUN_00466d60 (UI init, docs/01), FUN_00486f30 (add option string, docs/01)

**Moddability:** No — weather mode UI only.

---

## Internal Call Graph

```
Game::Init (0x0042d6b0)  [triggered by: Game startup sequence]
  +-- FUN_004fcaa0 — Weather Initializer  [sets defaults, fog, noise]
        +-- FUN_004fba10 — Weather State Init  [initializes weather substate]
        +-- FUN_004fefc0 — Fog Init  [fog params with 0.125 constant]
        +-- [if WeatherMode == 0] FUN_004fe820 — Weather File Writer
        |     [reads weather.txt from WeatherDir, writes 8 session entries]
        +-- [if WeatherMode == 1] FUN_004fe7c0 — Weather Section Reader
              +-- FUN_004fe350 — Weather Data Reader  [parses OnPathWetness, OffPathWetness, AmbientTemp, TrackTemp]

Weather Name → Value Lookups (stateless, called from track/GDB system):
  FUN_004fe0d0 — Weather Name → Wetness Multiplier
    +-- FUN_00588410 — String Compare
    +-- FUN_0058850f — Parse Float (fallback)

  FUN_004fe1e0 — Weather Severity → Grip Multiplier
    +-- FUN_00588410 — String Compare
    +-- FUN_0058850f — Parse Float (fallback)

Weather Mode UI (options/menu system):
  FUN_00470da0 — Weather Mode UI Constructor
    +-- FUN_00466d60 — UI Widget Init
    +-- FUN_00486f30 — Add Option String (×5)
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 0.30 | Fallback dry (WeatherMode != 0/1/3/4/5) | Default OnPathWetness for dry conditions |
| 0.65 | WeatherMode == 3 (Raining) | Hardcoded wetness for rain |
| 0.82 | WeatherMode == 4 (Overcast) | Hardcoded wetness for overcast |
| 0.94 | WeatherMode == 5 (Monsoon) | Hardcoded wetness for monsoon |
| 20.0 | Default ambient temp | °C default ambient temperature |
| 2.0 | Default track temp offset | TrackTemp = AmbientTemp + 2°C |
| ×100.0 | Weather file write | DAT_0059e6f8 — percentage conversion for wetness values |
| 0.05 | Weather noise variance | WeatherNoiseTable entries × 0.05 for session-to-session variation |
| 0.125 | Fog init constant | Passed to FUN_004fefc0 |
| 1.0 | +0x0c unknown flag | Init value in weather struct |
| -1 | +0x10 unknown ID | Sentinel value in weather struct |
| -1.0 | +0x18, +0xa4 unknown | Sentinel values in weather struct |
| 175.0 | +0xe4 unknown | Init value in weather struct |
| 700.0 | +0xe8 unknown | Init value in weather struct |
| 150.0 | +0xf4 unknown | Init value in weather struct |
| 0.01 | +0xf8 unknown | Init value in weather struct |
| 0.75 | +0xc0–+0xc8 fog params | First three fog parameters |
| 0.50 | +0xcc–+0xd4 fog params | Next three fog parameters |
| 5 | Option count in UI | Number of weather mode options presented |
| 0x19b | Scroll offset in UI | Scroll offset for weather mode selector |
| 9 | Season stride | WeatherMode stored per-season at stride 9 bytes |

### Wetness lookup table (FUN_004fe0d0)

| String | Wetness | Constant |
|--------|---------|----------|
| (empty) | 0.0 | DAT_005ad324 |
| (unknown/DAT_005d6f9c) | ~0.001 | DAT_0059e8b4 |
| "Clear" | 0.0 | DAT_0059e4e8 |
| "Overcast" | ~0.007 | DAT_0059e8f8 |
| "Drizzle" | ~0.34 | DAT_005ad320 |
| (unknown/DAT_005d6f84) | ~0.46 | DAT_0059e908 |
| "Monsoon" | ~0.61 | DAT_005ad31c |

### Grip multiplier lookup table (FUN_004fe1e0)

| String | Grip reduction | Constant |
|--------|---------------|----------|
| (normal/PTR_DAT_005c6e98) | 0.0 (no reduction) | DAT_0059e440 |
| (light rain/DAT_005d6fb4) | ~0.002 | DAT_0059e7f8 |
| (moderate/PTR_DAT_005c7234) | ~0.01 | DAT_0059e450 |
| "Soaked" | ~0.05 | DAT_0059e7fc |
| "Monsoon" | 1.0 (full reduction) | DAT_0059e43c |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_005ec438 (WeatherDir) — from setup (docs/08), path to weather data directory
- DAT_007d0410 (RaceMode) — from game (docs/01), used to compute per-season weather offset
- DAT_0059e460 (AlphaScaleFactor) — from renderer, used for sun/light position scaling
- DAT_0059e6f8 (100.0) — percentage conversion for wetness in weather file write
- DAT_0059e5fc (time step) — weather change time step constant
- DAT_005acb08 (minute threshold) — threshold for per-minute weather changes
- DAT_005ad324, DAT_0059e8b4, DAT_0059e4e8, DAT_0059e8f8, DAT_005ad320, DAT_0059e908, DAT_005ad31c — wetness lookup constants
- DAT_0059e440, DAT_0059e7f8, DAT_0059e450, DAT_0059e7fc, DAT_0059e43c — grip lookup constants
- DAT_0059e444 — fallback parse multiplier for name→value conversion

**Calls into:**
- docs/06-session-race-logic.md: FUN_00588410 (string compare), FUN_0058850f (parse float)
- docs/01-engine-architecture.md: FUN_00466d60 (UI init), FUN_00486f30 (add option string)
- docs/19-renderer.md (likely): FUN_004fefc0 (fog init with constant 0.125)
- docs/20-math-utilities.md: FUN_004fba10 (weather state init)

**Called by:**
- docs/01-engine-architecture.md: Game::Init (0x0042d6b0) calls FUN_004fcaa0 during startup
- docs/09-track-system.md: GDB parser calls FUN_004fe0d0 and FUN_004fe1e0 for wetness/grip lookups
- docs/01-engine-architecture.md (UI): FUN_00470da0 called when weather options menu is opened

### File I/O Dependencies

- Reads from: `WeatherDir/weather.txt` (when WeatherMode == 0)
- Reads from: Track `.gdb` file, `[Weather]` section (when WeatherMode == 1)

---

## Reimplementation Notes

1. **WeatherMode storage is per-season, not global.** The actual global is `DAT_007cf080`, but the weather UI uses `&DAT_007cf080 + DAT_007d0410 * 9` — meaning each season has its own 9-byte weather mode slot. When reimplementing, store WeatherMode as an array indexed by season.

2. **WeatherNoiseTable variance ensures non-determinism.** The 256-float table (DAT_008ab274) is seeded at weather init time with `result * 0.05`. The RingBufferCounter (DAT_008aae70) is consumed once during weather init. This means identical weather configs produce slightly different wetness values between sessions — same mechanism as QA time variance.

3. **OffPathWetness ≥ OnPathWetness constraint is enforced at load time**, not at write time. The GDB reader (`FUN_004fe350`) clamps OffPathWetness up to match OnPathWetness if the constraint is violated. This means saved weather files may have OffPathWetness < OnPathWetness, but it will be corrected on next load.

4. **Weather change interpolation:** The system supports per-minute weather changes via a linked list at +0x38. Each node stores a time offset, temperature, and conditions string. The Weather File Writer interpolates between these nodes when writing the 8-session output. The exact interpolation method is not documented — likely linear interpolation between consecutive nodes.

5. **Grip multiplier is an inverse scale:** grip = 0.0 means full grip (dry conditions), grip = 1.0 means zero grip (monsoon). This is used as a direct multiplier on tire grip force — the physics system multiplies tire grip by (1.0 - gripFromWeather).

6. **Fog constants:** Three fog parameters are set to 0.75 and three to 0.5. The fog init function is called with constant 0.125. These are likely Direct3D fog density/start/end parameters passed to `IDirect3DDevice::SetRenderState`.

7. **Weather state is static per session.** Unlike systems that update per-tick (physics, AI), weather state is set once during initialization and remains constant for the entire session. Dynamic weather (the "Changing Weather" UI option) would need per-tick updates, but this system does not implement it — the option likely just sets WeatherMode to a value that triggers per-tick checks in another system.

8. **Module structure:** The weather system lives in `weather.cpp` (source path from assert strings: `D:\dev\F1_1999_2002\Source\weather.cpp`). The two lookup functions (FUN_004fe0d0, FUN_004fe1e0) may live in a separate weather/gdb module based on naming.

9. **Default ambient temperature** is 20°C (room temperature). Track temperature defaults to ambient + 2°C. These are the baseline values used when no weather data file is present.

10. **The setup system (docs/08)** is responsible for resolving the WeatherDir path (DAT_005ec438) before the weather system initializes. The weather system reads from this path directly.

---

## Completeness

- Full specs written: 6 / 6 total documented functions
- Referenced helpers (FUN_004fba10, FUN_004fefc0, FUN_004fe350): referenced but not fully spec'd (they have their own doc entries in 17–21)
- Thunks/empty stubs omitted: 0
- Confidence: **high** — all 6 functions clearly documented with constants, logic flow, and calling context verified against call graph
