# Session and Race Logic

- Sets `DAT_007d0410 = 5` (multiplayer mode), clamps to min/max from `DAT_007d0418`/`DAT_007d041c`
- Sets `DAT_007d0f94 = 1`
- Calls `FUN_0057a920` (network setup)
- Calls `FUN_00463c60` to check if game already exists
- If exists: displays "MULTIPLAYER_CREATEGAME"
- If not: displays "SELECTCIRCUITPAGE"

**Calls:** FUN_0057a920, FUN_00463c60, FUN_00497940 (page display)

**Moddability:** Yes � sets up multiplayer session; affects page flow for network games.

---

## Replay System (3 functions)

### FUN_004ba1f0 � Replay Playback Loader (Prepping Replay)

Source: `Replay.cpp`. State machine for loading and initializing replay playback from a VCR file.

**State machine (param_1[0]):**
- **0/1**: Checks conditions � if `FUN_00404f10()` returns false and either `DAT_007d0038 != 0` or `DAT_007d005c != 0`, sets state=1 and returns. Otherwise state=0.
- **2**: Active loading phase:
  1. Asserts via `FUN_004d7a50` (source check)
  2. Opens VCR file via `FUN_00566b20` from path at param_1[2]+0xf94
  3. Displays "Prepping Replay" message via `FUN_00423a00` + `FUN_004a0e70` + Sleep(250ms)
  4. Initializes replay buffer (0x80 bytes, alloc via `operator_new(0x80)`)
  5. Opens output file via `FUN_00566940`
  6. Reads packets in loop: `FUN_00566c00` ? `FUN_00566bd0` (process)
  7. Closes file handles
  8. If successful: sets state=2, calls `FUN_004b9da0(5)` (replay data ready)
  9. Calls `FUN_004b87a0`/`FUN_004b86e0` for replay data init
- On failure: resets state=0

**Key strings:** "Prepping Replay", "Loading VCR File for playback", `D:\dev\F1_1999_2002\Source\Replay.cpp`

**Calls:** FUN_004d7a50 (assert), FUN_00566b20/FUN_00566940 (file I/O), FUN_00423a00 (string copy), FUN_004a0e70 (message display), FUN_004b9830 (replay buffer), FUN_00568540 (timer/sync), FUN_004b97d0 (replay data check), FUN_004b9810 (replay flag), FUN_004b9da0 (state update), FUN_004b9820/FUN_0042bbd0/FUN_0042bc40 (post-load config), FUN_004b87a0/FUN_004b86e0 (replay data init), FUN_00566c00/FUN_00566bd0 (packet streaming)

### FUN_004b7500 � Replay Save State Machine (Saving Replay)

Source: `Replay.cpp`. Handles replay recording � saves session data to VCR file.

**Key logic:**
- Guards on param_1+0x6e4 (replay data present)
- **param_1+0x700 == 1** (first-time save path):
  - Executes 0x68 iterations of `FUN_004b6190` (car state capture)
  - Calls `FUN_004b7a00` (replay header init)
  - If session not in state 4 AND replay duration threshold met AND param_2 != 0:
    - Displays "Saving Replay" message + Sleep(100ms)
    - Opens output file via `FUN_00566940` with subfolder index (0-4 from param_1+0x9a4)
    - Writes lap data via `FUN_004b6a10`
    - Streams car state data: `FUN_00566b20` + read loop `FUN_00566c00`/`FUN_00566bd0`
    - Closes file
  - Calls `FUN_004b8010` (replay save finalize)
- **param_1+0x700 != 1 AND param_1+0x6d0 == 0** (flag not set): close file, no-op
- **param_1+0x700 != 1 AND param_1+0x6d0 != 0** (flag set, replay active):
  - Clears flag at param_1+0x6d0
  - Displays "Saving Replay" + Sleep(100ms)
  - Opens output file from param_1+0xf94 path
  - Writes header data: `FUN_00566650` (path prep) + `FUN_004b6a10` (lap data)
  - Iterates linked list at param_1+0x714: writes each entry via `FUN_00566db0` + streaming
  - Closes file
- Final: clears param_1+0x700, calls `FUN_004b5f60`

**Calls:** FUN_004b52a0, FUN_004b6190 (car state), FUN_004b7a00 (header), FUN_00423a00/FUN_004a0e70 (message), FUN_00566940/FUN_00566b90/FUN_005668d0 (file I/O), FUN_004b6a10 (lap write), FUN_00566b20/FUN_00566c00/FUN_00566bd0 (stream), FUN_004b8010 (finalize), FUN_00566650 (path), FUN_00566db0 (entry write), FUN_004b5f60 (cleanup)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x6e4 | Replay data present flag |
| +0x700 | Save state (0/1) |
| +0x6d0 | Replay recording flag |
| +0x9a4 | Subfolder index (0-4) |
| +0xf30 | Lap time start |
| +0xf34 | Lap time end |
| +0x70c | Track name (file path base) |
| +0x704 | Input data source |
| +0xf94 | Output file path |
| +0x6e8 | Header data source |
| +0x714 | Entry linked list head |
| +0x71c | Entry linked list tail |

### FUN_004b9fd0 � Replay Activation UI (Replay Recording - On)

Source: `Replay.cpp`. Handles replay activation � displays "Replay Recording - On" and "Replay Activation" UI messages.

**Key logic:**
- Guards on: param_1[1] == 0 (not yet activated) AND param_1[0] == 1 (active state)
- Displays "Replay Recording - On" message via FUN_00423a00 + FUN_0045bd10 (priority 2)
- If FUN_00461db0() returns 0 (no errors):
  - Builds "Replay Activation" string in local buffer
  - Concatenates with `DAT_005c32d8` (file extension suffix)
  - Reads saved game name from `FUN_00455260(&DAT_007d1d8c)`
  - Appends game name to activation message
  - Displays final string via FUN_0045bd10 (priority 3)
- Sets param_1[1] = 1 (activation flag)

**Calls:** FUN_00423a00 (string copy), FUN_0045bd10 (message display, priorities 2/3), FUN_00461db0 (error check), FUN_00455260 (saved game name lookup)

---

## FUN_0047e4b0 � Circuit Info HTML Page

Source: results/web module. Generates an HTML info page for the current circuit: First Grand Prix year, Circuit Length, Lap Record, and Race Laps.

**Key logic:**
- Looks up current scene via FUN_004c5840(0)
- Initializes HTML writer via FUN_00489cb0
- Gets date/season header via FUN_004894d0
- Reads 4 track database fields via FUN_005679c0 + FUN_00567970:
  - `First Grand Prix` � section header 2
  - `Circuit Length` � section header 3
  - `Lap Record` � section header 4
  - `RaceLaps` � section header 5
- Writes each as `"%s %s %s"` via FUN_00489600

**Calls:** FUN_004c5840 (scene lookup), FUN_00489cb0 (HTML init), FUN_004894d0 (date header), FUN_005679c0 (field lookup), FUN_00567970 (value get), FUN_00487010 (section header 2-5), FUN_0058815f (format), FUN_00489600 (HTML write)

**Moddability:** No � output-only HTML display of track stats.

---

## FUN_004c02d0 � Qualifying Best Lap Time Lookup

Source: season/qualifying module. Looks up a driver's best qualifying lap time by matching driver name against the `Qualifying` section in scene data.

**Key logic:**
- Returns 0.0 if param_1 null or scene not loaded (FUN_004c5840)
- Reads `Qualifying` section via FUN_005679c0
- Iterates up to 0x68 (104) entries via thunk_FUN_0059d6a9
- For each entry: reads name via FUN_00499e20, compares against param_1 via FUN_00588410
- On match: reads lap time value via FUN_00567970, parses as float via FUN_0058850f
- Returns lap time (float) if >= _DAT_0059e5fc threshold, or 0.0 if below threshold
- Returns 0.0 if no match found

**Calls:** FUN_004c5840 (scene load), FUN_005679c0 (section lookup), FUN_00499e20 (entry name), FUN_00588410 (string compare), FUN_00567970 (value get), FUN_0058850f (float parse)

**Moddability:** Yes � reads Qualifying section times which contain per-driver lap time data.

---

## FUN_004c0260 � Qualifying Driver Index Lookup

Source: season/qualifying module. Returns the 1-based index of a driver in the `Qualifying` section, or 0x68 (max) if not found.

**Key logic:**
- Returns 0x68 if param_1 null or scene not loaded
- Reads `Qualifying` section via FUN_005679c0
- Iterates up to 0x68 entries, matching driver name against param_1
- Returns entry index + 1 on match, or 0x68 if not found

**Calls:** FUN_004c5840 (scene load), FUN_005679c0 (section lookup), FUN_00499e20 (entry name), FUN_00588410 (string compare)

**Moddability:** Yes � qualifying grid positioning.

---

## Race Start Stall / DNS - Mechanics

Source: `FUN_00424080`, session==7 + lap < 3 branch.

```c
if (rand() % 10000 < StartStalls * 10000) {   // StartStalls = 0.0–1.0 probability
    if (rand() % 10 == 0) {
        event = DNS;       // 10% of stall triggers → DNS
    } else {
        event = Stall;     // 90% → regular grid stall
    }
}
```

`StartStalls` in `.rcd` is a direct 0.0–1.0 probability, evaluated per driver on race
start laps 1–2.

### Scripted Race Events

When `DAT_007cea5c == 3` (scripted events mode), the game reads a `Script` field from
`.rcd` pointing to a `RaceEvents` section. Supported event type strings:

- `"Stall"` → grid stall, random lap from range
- `"Stall___DNS"` → stall that becomes DNS
- `"DNS"` → DNS
- `"Suspension"` → suspension failure (type 3)
- `"Brakes"` → brake failure (type 1)
- `"Engine"` → engine failure (type 0)
- `"Gearbox"` → gearbox failure (type 2)

Each event type has an associated lap range. Failure type integers correspond to
ISIMotor internal retirement codes.

---



---

## Session Type Codes

## Session Type Codes

Source: `FUN_004d3cf0` @ `0x004d3cf0` (`steward.cpp` Restart function)

`DAT_007c56a4` — global session type enum:

| Value | Session | Default duration |
|-------|---------|-----------------|
| 0 | TestDay | no limit |
| 1 | Practice1 | 3600 s (1 h) |
| 2 | Practice2 | 3600 s |
| 3 | Practice3 | 2700 s (45 min) |
| 4 | Practice4 | 2700 s |
| 5 | Practice5 | 3600 s |
| 6 | Qualifying | 1800 s (30 min) |
| 7 | Race | laps-based (`DAT_007d05a0`) |

Session 6 uses race pit speed limit (`RacePitKPH`). Sessions 1–5 use `NormalPitKPH`.
Both strings read from the GDB. `RaceTimeScaled` multiplies by `DAT_007d0798` (global
time scale factor — the in-game time acceleration slider).

---


---

## 107% Qualifying Rule - NOT IMPLEMENTED

## 107% Qualifying Rule — NOT IMPLEMENTED

Source: `FUN_004be760` @ `0x004be760`

Despite the game being based on F1 99-02, there is **no 107% qualifying cutoff rule** in
the engine. `FUN_004be760` is a **race finish time predictor**, not a qualifying filter.

What it actually does:
1. Finds fastest car lap time (`local_c`), checks if within 9000s sanity bound
2. Finds "close enough" 2nd car: must be within **1.15×** fastest (115% threshold)
3. Extrapolates finish time using track position interpolation between 1st and 2nd
4. Clamps result: predicted time ≥ `fastest × 0.97` (can't predict faster than 97% of fastest)
5. Initial default = **600 seconds** (10 min estimate before any laps are done)

Constants confirmed from `.rdata`:
- Fastest lap threshold for prediction: 9000.0 (sanity bound)
- 2nd car inclusion threshold: `× 1.15`
- Floor clamp: `× 0.97`
- Extrapolation rate: 0.15
- Default initial value: 600.0 seconds

The AI eligibility for race starts is governed by `StartStalls` probability only —
no lap time minimum exists.

---


---

## Race Penalties - Mechanics

## Race Penalties — Mechanics

Source: `FUN_004bccc0` @ `0x004bccc0` (`steward.cpp`)

All penalty enforcement gated by `DAT_007cef84` — if 0, penalties are fully disabled.

### Cut track
- Score threshold (minimum cut to register): `_DAT_0059e944`
- **Practice/Qualifying**: financial fine + **lap invalidated** (`param_1[0x18] != 0`)
- **Race, 1st offense**: warning only
- **Race, 2nd+ offense** (`param_1[0x34] >= 2` and cut score ≤ `_DAT_005acb30`): Stop/Go (10s)

### Speeding in pitlane
- **Race**: Stop/Go (10 seconds)
- **Practice/Qualifying**: fine = `excess_speed_integral * rate + base_fine`

### Blue flags — 3-stage timer
`param_1[0x37]` accumulates time (seconds) since blue flag shown:
- Stage 1 (warning) at `_DAT_0059e5fc` seconds
- Stage 2 (urgent) at `_DAT_0059e8ec` seconds
- DSQ at `_DAT_0059e468` seconds of accumulated ignoring

Counter resets to 0 on compliance (car moves over).

### Wrong way
DSQ triggered when wrong-way score exceeds `_DAT_005acd88`.

---

## FUN_004aa270 - Player Options Initializer / FailureRate Slots
### FUN_004aa270 — Player Options Initializer / FailureRate Slots

Triggered by the string `"Mechanical failure rate: 0=none..."` (a UI label). This function initializes the player options struct to defaults.

**7 independent FailureRate slots confirmed:**

```c
// at param_1 + 0x5c8, stride = 0x24 (9 dwords), 7 iterations
for (i = 0; i < 7; i++) {
    slot->current = 2;   // default = "normal"
    slot->min     = 0;   // 0 = none
    slot->max     = 3;   // 3 = scripted
}
```

7 independently configurable `FailureRate[0..6]` slots, one per scripted event type. Each has range 0–3 and defaults to 2. Maps to the 7 failure categories in the scripted events section.

---

## Steward System + UI Message Handler
### Steward System (FUN_004d36d0 / FUN_004d38f0 / FUN_004d4600)

- **FUN_004d36d0** (Setup): registers callbacks for VEHICLE, TIMING, PITSTOP. Trivial.
- **FUN_004d38f0** (Init): allocates lap timing arrays by `DAT_005ea3fc` (session total time). Locates track polygons: `XPITIN`, `XPITOUT`, `XFINISH`, `XSECTOR1`, `XSECTOR2`. Initializes helicopter model.
- **FUN_004d4600** (Cleanup): frees timing arrays. Calls `FUN_004bb950` once per `DAT_005c329c` vehicles for retirement/finish processing.

No moddable fields found.

---

### UI Message Handler — FUN_0047eb70

Dispatch switch on codes 0x1e4–0x1f9, not a weather simulation. Case `0x1f8` reads `DAT_007cf134` (weather mode 0–5), confirming the weather mode enum already in this document. No new findings.

---

## steward.cpp - Light/Glow Setup (1 new function)
### steward.cpp — Light/Glow Setup (1 new function)

#### FUN_004d0e20 — Steward Light/Glow Node Finder

Finds scene nodes by name for light and glow objects. Stores at:
- param_1+4 = light scene node
- param_1+8 = glow scene node

Errors: "Could not find light %s" / "Could not find glow %s" if nodes not found.
Simple scene node lookup — not moddable.

---

## FUN_004c03f0 - Career Standings State Loader
### FUN_004c03f0 — Career Standings State Loader

Reads player career standings from profile file.

**Standings struct (param_1, int-indexed):**

| Offset | Field | Notes |
|--------|-------|-------|
| +0x18 + i×4 | FINISHPOSITION[0..47] | Max 48 races (0x30) |
| +0xd8 + i×4 | FINISHPOINTS[0..47] | Points per race |
| +0x198 | SEASONPOINTS | Current season points |
| +0x19c | POINTSPOSITION | Points position |
| +0x1a0 | POLESTAKEN | Pole count |
| +0x1a4 | ORIGINALGRIDPOSITION | Original grid pos |
| +0x1a8 | CURRENTGRIDPOSITION | Current grid pos |
| +0x1ac | CONTROLTYPE | Control type |
| +0x1b0 | ACTIVE | Bool — is this entry active |

Also reads VEHFILE and RCDFILE fields (file paths).

---

## FUN_004bc0e0 - Disqualification Handler
### FUN_004bc0e0 — Disqualification Handler

Applies DSQ to vehicle. Only if not already DSQ (`param_1[0xc] != 3`) and
vehicle active (`*param_1 + 13000 == 0`).

- Sets `param_1[0xc] = 3` (DSQ state)
- Creates "Disqualified: <reason>" message
- Increments `DAT_0083ee60` (penalty count, max 0x3ff)
- Advances `DAT_008aae64` by 0x1b0 (penalty history stride)
- Calls `FUN_004b33b0` (vehicle event, code 4=DSQ, 0x1c)
- Calls `FUN_0041a940` (apply DSQ to vehicle)

**Penalty struct (param_1):**
| Offset | Field |
|--------|-------|
| +0x0c | penalty state (0=none, 1=stop/go pending, 3=DSQ) |

---

## FUN_004bbd60 - Stop/Go Penalty Handler
### FUN_004bbd60 — Stop/Go Penalty Handler

Applies Stop/Go penalty. Only if `param_1[0xc] == 0` (no existing penalty).

- Creates "Stop/Go Penalty: <reason>" message
- Same penalty history array as DSQ
- Calls `FUN_004b33b0` (code 4, 0x17=StopGo)
- Stores `param_3` at penalty record+8
- Calls `FUN_0041a720` (apply Stop/Go)

---

## FUN_004bbc60 - Warning Handler
### FUN_004bbc60 — Warning Handler

Issues warning. Only if `param_1[0xc] == 0` and vehicle active.

- Creates "Warning: <reason>" message
- No penalty history entry — just displays message
- Calls `FUN_0045bd10` (display message, priority 3)

---

## FUN_004bc4e0 - Lap Completion / Penalty Processing
### FUN_004bc4e0 — Lap Completion / Penalty Processing

Complex function handling lap completion and penalty enforcement.

**Key logic:**
- `param_4 != 0`: sector timing — stores lap times, calls timing update
- `param_4 == 0`: lap completion
- Session-specific handling (switch on `DAT_007c56a4`):
  - **Race (7):** Checks lap count vs `DAT_008acf8c` (total laps). Handles
    formation lap (`FUN_0042d140`). DSQ for ignored Stop/Go penalties
    ("Ignored Stop/Go Penalty"). Updates penalty countdown timers.
  - **Qualifying (5):** DSQ if exceeding time limit
  - **Practice (0):** Simple lap update
- Sets `DAT_008acfa0` (race half-distance flag) when lap ≥ (total+1)/2
- Updates `param_1[0x10]` penalty countdown array (stride 8, max param_1[0xf])
- Calls `FUN_004bc240` (standings update)

**Globals:**
- `DAT_008acf8c` — total race laps
- `DAT_008acf90` — race time offset
- `DAT_008acf94` — race time threshold
- `DAT_008acfa0` — half-distance flag
- `DAT_007c56a4` — session type
- `DAT_007c56a8` — race phase (8 = ?)
- `DAT_007ce814` — qualifying DSQ enabled

---

## FUN_00469d30 - Player Stats Display Cleanup
### FUN_00469d30 — Player Stats Display Cleanup

Frees linked list at param_1+0x44, clears +0x44–0x50. Displays labels:
Circuit, Experience (Laps), Best Lap. Calls UI setup functions.

---

## FUN_0046a560 - Standings Display
### FUN_0046a560 — Standings Display

Displays career stats: Experience (Laps), Starts, Avg Starting Position,
Avg Finish Position, Pole Positions, Points, Wins, Lap Records,
Drivers Championships.

Uses globals `DAT_007d2dd4`–`DAT_007d2df8` for stat values.
Formats as `"%s %s %i"` (integer stats) or `"%s %s %.1f"` (float stats).

**New globals:**
| Address | Stat |
|---------|------|
| DAT_007d2dd4 | Starts |
| DAT_007d2dd8 | Avg Starting Position |
| DAT_007d2de0 | Wins |
| DAT_007d2de8 | Lap Records |
| DAT_007d2dec | Pole Positions |
| DAT_007d2df0 | Points |
| DAT_007d2df4 | Avg Finish Position |
| DAT_007d2df8 | (float stat) |
| DAT_007d2e00 | Drivers Championships |

---

## FUN_004c0cc0 - Player/Opponent State Writer
### FUN_004c0cc0 — Player/Opponent State Writer

Writes season state to file: SeasonStatus, RaceSession, RaceOver, CurrentRace.
Then writes `[PLAYER]` section, then up to 103 `[OPPONENT %02d]` sections
(stride 0x1b4 per opponent). Active flag at +0x1b0.

**Game state struct (param_1):**
| Offset | Field |
|--------|-------|
| +0xb144 | SeasonStatus |
| +0xb148 | CurrentRace |
| +0xb14c | RaceSession |
| +0xb150 | RaceOver (bool) |
| +0x1b0 | Active flag (per entry, stride 0x1b4) |

---

## FUN_004e3360 � Track Limit / Penalty Zone System

Reads track limit enforcement zones from GDB/track config. Defines restriction spheres and force fields that enforce track boundaries.

**Sections read:**
- **RestrictionLimit / DefaultLimit** � speed/penalty thresholds
- **ForceFieldSphere** � kinematic force field zone (multi-vector)
- **RestrictionSphere** � penalty trigger zone (multi-vector)

Triggers full scene setup chain: `FUN_004f4270` (vehicle file parser), `FUN_004dd450` (scene init), `FUN_0042e320`.

Each restriction zone stores 3D position + radius + penalty parameters. Multiple zones per track (iterated via section read loop).

**Struct (local buffer, stride 3 doubles per entry):**
| Offset | Field |
|--------|-------|
| +0x00 | position X |
| +0x08 | position Y |
| +0x10 | position Z |
| +0x18 | radius/limit value |

**Globals:**
- `DAT_007c56a4` � session type (used for penalty severity)

Not moddable � track geometry/boundary data only.

---

## FUN_004d0110 � Grid/Starting Scene Initialization

Initializes the starting grid visual scene: grid characters, flags, banners. Loads:
- `CMAPS.MAS` � circuit map textures
- `CDB.MAS` � circuit database models
- `WCFLAG.BMP` � flag texture

Calls scene node setup for each grid position. Iterates `DAT_005c329c` (vehicle count) to place grid characters. Error: "Unable to setup scene after initializing grid character %d: %s".

Not moddable � graphics/scene initialization only.

---

## FUN_004bc9b0 � Jumped Start / Grid Penalty Detection

Source: race/steward module. Detects jumped starts (premature movement before green) and improper grid alignment. Called during race phase transitions.

**Key logic:**
- Reads vehicle velocity from param_1->vehicle +0x3500/0x34fc/0x34f8 (velocity vector X/Y/Z)
- Computes velocity magnitude squared
- If param_2 == 0 (jumped start check): 
  - Compares velocity to threshold `_DAT_0059e43c`
  - If moving: computes position relative to grid using FUN_004d10e0 (grid position lookup) and FUN_004efb20 (vehicle world position)
  - Computes dot product of movement direction vs grid forward direction
  - If velocity < `_DAT_005acd70` (stopped threshold) AND forward movement < `_DAT_0059f124` AND reverse dot < `_DAT_0059e908`: no penalty
  - If velocity > `_DAT_0059e920` and param_3 != 0: displays `"Not Lined Up Properly"` warning
  - If `DAT_007cef84` (PenaltiesEnabled) != 0 and not in pit: calls FUN_004bbd60 or FUN_004bc0e0 with `"Jumped start"` ? applies stop-go penalty
- If param_2 != 0 (grid alignment check):
  - Compares velocity to `_DAT_0059e43c` AND position offset to `_DAT_005acd78`
  - If off-grid: displays `"Not Lined Up Properly"` via FUN_0045bde0

**Vehicle struct offsets:**
| Offset | Field |
|--------|-------|
| +0x34f8 | Velocity/position Z |
| +0x34fc | Velocity/position Y |
| +0x3500 | Velocity/position X |
| +0x34c4 | Grid forward direction X |
| +0x34d0 | Grid forward direction Y |
| +0x34dc | Grid forward direction Z |

**Globals used:**
- `DAT_007cef84` � PenaltiesEnabled
- `DAT_005ec4cc` � MessageBuffer

**Calls:** FUN_004d10e0 (grid position), FUN_00566e40 (track data), FUN_004efb20 (world position), FUN_004bbd60 (penalty: 10s stop-go), FUN_004bc0e0 (penalty: jumped start), FUN_0045bd10 (HUD display), FUN_0045bde0 (warning display), FUN_00423a00 (string copy)

**Moddability:** Yes � penalty severity. However, these are runtime thresholds, not file fields. Indirectly relates to AI start behavior via .rcd StartStalls.

---

## FUN_004bba90 � Penalty Display Message

Source: steward/race module. Formats and displays penalty messages (time penalty or fine). Called during race to show penalties applied to drivers.

**Key logic:**
- If param_1[0xc] == 0 (penalty active):
  - If `DAT_007d0b10 == 0` (singleplayer): displays `"Penalty: [reason]"` combining "Penalty:" header with reason string
  - If `DAT_007d0b10 != 0` (multiplayer): displays `"Fined US$ [amount]"` with monetary fine
  - Output via FUN_0045bd10 to HUD
- Accumulates penalty time: param_1[0x29] += param_3 (float seconds)

**Struct offsets (param_1):**
| Offset | Field |
|--------|-------|
| +0x30 (0xc) | Penalty active flag |
| +0xa4 (0x29) | Accumulated penalty time (int, from float) |

**Calls:** FUN_00423a00 (string copy), FUN_0058815f (format), FUN_0045bd10 (HUD write)

**Moddability:** No � runtime penalty display only.

---

## FUN_0059d74e � Recon Pit Open/Closed Time Reader

Source: track/gdb config. Reads `ReconPitOpen` and `ReconPitClosed` float values from the `.gdb` track config file via FUN_005679c0/FUN_00567970. Stores to globals that control pit window timing.

**Key logic:**
- Reads "Recon Pit Open" ? stored to `DAT_007cec30` (pit open window start, float)
- Reads "Recon Pit Closed" ? stored to `DAT_007cec54` (pit closed time, float)
- Reads "RaceTime" ? calls FUN_004b1375 (race time config)

**New globals:**
- `DAT_007cec30` � Recon Pit Open time (float, seconds into race)
- `DAT_007cec54` � Recon Pit Closed time (float, seconds into race)

**Calls:** FUN_005679c0 (section search), FUN_00567970 (value read), FUN_00587ece (string?float), FUN_004b1375 (race time handler)

**Moddability:** Yes � **moddable field.** These are `.gdb` track config fields that control when the pit window opens and closes. Mods can vary pit window timing per track/season to create strategic variety.

---

## FUN_004a47e0 � Pit Service Type Name Lookup

Source: pit HUD module. Maps pit service type ID to display name string. Used in pit stop HUD.

**Mapping:**
| ID | Name |
|----|------|
| 0 | STOP/GO |
| 1 | (empty/ERROR) |
| 2 | TYRES |
| 3 | WING |
| 4 | DAMAGE |
| default | ERROR |

**Calls:** None (pure switch-table)

**Moddability:** No � display name lookup only.

---

## FUN_0047d800 � Season Stats Display (PrevYear/Drivers/Times)

Source: season stats UI. Displays previous year's championship results with driver times. Reads season data for `PrevYear`, `Drivers`, and `Times` sections.

**Key logic:**
- Reads season database via FUN_00489cb0/FUN_004894d0
- Checks for `PrevYear` data availability
- For each driver entry: loads driver name and time data via FUN_00567970
- Formats `"%s%s%s"` combining entries
- Writes each row via FUN_00489600 (UI table entry)

**Calls:** FUN_00489cb0 (season init), FUN_004894d0 (data load), FUN_004c5840 (data check), FUN_005679c0 (string search), FUN_00567980 (count), FUN_0059d6a9 (entry), FUN_00567970 (value), FUN_0058815f (format), FUN_00489600 (UI write)

**Moddability:** No � UI display of historical data.

---

## FUN_004d24d0 � Race Results File Writer (raceresults.txt)

Source: results module. Writes `raceresults.txt` to the `Results\` directory with full session data. Uses filename format `%d_%02d_%02d_%02d_%02d_%02d.txt` (timestamp). File header: `F1 Challenge 99-02`.

**Key logic:**
- Builds results path from `Results\` + timestamp filename
- Reads session time via FUN_00589e6c (returns packed date/time struct)
- If multiplayer (`DAT_007d0b28 != 0`): writes race timestamp
- If singleplayer race session (`DAT_007c56a4 == 7`) or multiplayer:
  - Writes header: `[Header]`, `Game = "F1 Challenge 99-02"`, `Version = 1.0`, `TimeString`, blank line
  - Writes `[Race]`: `RaceMode`, `Scene`, `AIDB`, `Qualify Laps`, `Race Laps`, `Race Time`, `Track Length`
  - If multiplayer: writes `[Local Settings]` with all drive aids, MechFail rate, DamageMultiplier, Fuel/Tire Mult, Vehicles Allowed, controls
  - Writes `[Results]` section per driver sorted by finish position:
    - Driver name (+0x4620), Vehicle name (+0x4678)
    - Qualifying position (+0x4058) and time (+0x405c)
    - Race finish position (+0x4060)
    - Lap times (from +0x403c = lap count, calls FUN_004bc2a0/FUN_004bc270 per lap)
    - Best lap time (+0x409c)
    - Finish state (+0x4064): 0=running/2=DNF ? writes reason code (+0x4068); 1=finished ? writes race time (+0x40b8); 3=DSQ
    - Gap to leader (+0x40d8)

**Globals used:**
- `DAT_007d0b28` � MultiplayerFlag
- `DAT_007c56a4` � SessionType
- `DAT_007d0410` � RaceMode
- `DAT_007ce5d0` � SceneName
- `DAT_007ce608` � AIDBPath
- `DAT_007d04a4` � QualifyLaps
- `DAT_007d05a0` � RaceLaps
- `DAT_008acf94` � RaceTimeThreshold
- `DAT_008acf90` � RaceTimeOffset
- `DAT_007c54f0` � VehiclePtrArray
- `DAT_005c329c` � VehicleCount
- `DAT_007cea5c` � EngineWearMode (MECHFAIL_rate)
- `DAT_007d0014` � DamageMultiplier
- `DAT_007d0b64` � FuelMult
- `DAT_007d0c60` � TireWearMultiplier
- `DAT_007ce6ac`�`DAT_007ce994` � drive aids globals (steering help, throttle, brake, antilock, etc.)
- `DAT_007d1b08`�`DAT_007d1fd8` � control binding array (stride 7)

**Calls:** FUN_00566650 (string write), FUN_005665b0 (path append), FUN_00589671 (mkdir), FUN_005896ee (fopen), FUN_00589e6c (get time), FUN_00566940 (file status), FUN_00566c30 (write header/section), FUN_00566b90 (file close), FUN_005668d0 (file cleanup), FUN_004bc2a0/FUN_004bc270 (lap time read), FUN_00567700 (format time), FUN_005676c0 (format time)

**Moddability:** No � writes results file (output only, not input).

---

## FUN_0049f870 � Race Monitor Overlay Renderer

Source: HUD/UI module. Renders the in-race standings overlay showing driver positions, names, and lap times during a live session. Uses "FTFU30WH" font surface.

**Key logic:**
- Skips if DAT_007ce254 (disable HUD) is set
- Gets random offset via FUN_00408490 if enabled
- Gets monitor timing via FUN_0045be00(4) with random component
- Computes frustum culling parameters (screen boundaries, visible range)
- Iterates vehicle grid DAT_005ef9a0 (stride 0x1230):
  - Filters active vehicles (non -1, non 0, +0x57d bit 1 set = monitored)
  - Reads driver TeamID (+0x4894), finish position (+0x4060), name (+0x46f8), season points (+0x403c)
  - Calls FUN_004dc960 for frustum visibility check
- Collects visible vehicles into linked list, sorts via FUN_0049feb0
- For each visible entry (max 3, or more if HUD flag set):
  - Computes screen position offsets from corner
  - Formats display string: driver name + position/points or just name
  - If replay mode (state 2): appends `" [%d ms]"` elapsed time and appends to name string
  - Calls FUN_0049b370 to render text
- Restores original render surface offsets
- Frees the linked list

**Struct offsets (vehicle grid DAT_005ef9a0 + stride 0x1230):**
| Offset | Field |
|--------|-------|
| +0x57d byte | bit 1 = monitored flag |
| +0x4894 | TeamID (for per-vehicle data index) |
| +0x46f8 | Driver name string |
| +0x4710 | Driver name/abbreviation (alt) |
| +0x4060 | Finish position / race position |
| +0x403c | Season points |

**Globals:**
- `DAT_007ce254` � disable HUD flag
- `DAT_007cc49c` � alternate display mode flag
- `DAT_005ef9a0` � vehicle grid array start (stride 0x1230)
- `DAT_005d6d64` / `DAT_005d6d60` � screen dimensions
- `DAT_005ea4e8` � random offset flag
- `DAT_0059e440` � threshold constant
- `DAT_007c56a4` � SessionType (7=race for points display)
- `DAT_007d0398` � flag controlling points display format
- `DAT_0059f0c0` / `DAT_0059e970` / `DAT_0059f124` � layout constants
- `DAT_005acb18` / `DAT_005a68e8` � screen scaling factors

**Calls:** FUN_00408490 (random seed), FUN_0045be00(4) (monitor timing), FUN_0040cd60 (session phase), FUN_0040c910 (lap counter), FUN_004dc960 (frustum cull), FUN_0049feb0 (sort visible list), FUN_0053d1f0 (font/surface lookup "FTFU30WH"), FUN_0049b370 (text render), FUN_004624e0 (driver check), FUN_00462530 (time check), FUN_0058815f (format), FUN_00587bcf (free), FUN_0049af30 (no-visible cleanup), FUN_00461cd0 (state check)

**Moddability:** No � display-only rendering, no file field access.

---

## FUN_0046c210 � Championship Standings HTML Writer

Source: web/results module. Generates an HTML standings page for the championship � writes 4 sections: header, race results, standings table, and track info.

**Key logic:**
- Initializes HTML writer via FUN_00489cb0
- Checks season mode == 2 (championship) via FUN_004c2760
- Loads season data via FUN_004c2850, gets race count via FUN_004c1390
- For each of 4 sections:
  - Gets section header/title via FUN_00487010(0-3)
  - Formats player name from FUN_004b0b20, season name from FUN_004c0a20
  - Writes `"%s %s %s"` via FUN_00489600
  - For section 1: formats round/race number `"%d/%d"` from race data
  - For section 2: formats position/points from FUN_004c13c0/FUN_004c1450
  - For section 3: reads `TrackName` from scene database, copies to message buffer, writes
  - Clears buffer between sections
- On non-championship mode: writes 4 simplified sections with "No season data" fallback

**Calls:** FUN_00489cb0 (HTML init), FUN_004c2760 (season mode), FUN_004c2850 (season load), FUN_004c1390 (race count), FUN_004c29d0 (race entry), FUN_004c0a20 (season name), FUN_004894d0 (year/season string), FUN_004b0b20 (player name), FUN_00487010 (section header 0-3), FUN_00489600 (HTML write), FUN_004c13c0/FUN_004c1450 (position/points), FUN_004c55b0 (scene data), FUN_004c5840 (scene/track enum), FUN_005679c0 (track name read), FUN_00567970 (value get), FUN_00423a00 (string copy), FUN_0058815f (format)

**Moddability:** No � output-only HTML page generation.

---

## FUN_00469900 � Individual Race Results HTML Writer

Source: web/results module. Generates HTML output for a single race result: track name, best lap time, and driver list with lap times.

**Key logic:**
- Reads track name from linked list at DAT_007d2dc0 (GrandPrixName field via FUN_004c58a0)
- Formats best lap time as `"%i:%06.3f"` (minutes:seconds)
- Writes 3 sections via FUN_00489600:
  - Section 0: track name + header
  - Section 1: best lap time
  - Section 2: driver name
- Then iterates remaining entries in linked list (DAT_007d2dc8) to write per-driver rows
- Uses FUN_004894d0 for date/season header string

**Globals:**
- `DAT_007d2dc0` / `DAT_007d2dc8` � linked list of race results (stride 4+ per entry)
- `DAT_007ce668` � track name display string
- `DAT_005c693c` � "GrandPrixName" constant

**Calls:** FUN_004894d0 (season/date header), FUN_00487010 (section header 0-2), FUN_00489600 (HTML write), FUN_004c58a0 (string field read), FUN_0058815f (format), FUN_00566650 (path registry), FUN_00423a00 (string copy)

**Moddability:** No � output-only HTML page generation.

---

## FUN_004b7de0 � Hot Lap File Writer

Source: hotlap/timing module. Saves the player's best lap time to a `.HOT` (hot lap) file for the current track.

**Key logic:**
- Reads player vehicle's best lap time from +0x409c and session time from +0x40b4
- Returns 0 if best lap == 0.0 (invalid) or <= 0.0 (not set)
- Builds hot lap file path from track name at param_1+0x70c:
  - Appends ".HOT" extension to track name
  - Appends "HOT LAP" message string to buffer
  - Prepends path from DAT_005be714/DAT_005be718
- Opens file via FUN_005668b0/FUN_00566940 with mode from param_1+0x9a4 (0-4 = subfolder index)
- On successful open: copies "Saving Hotlap" to message buffer
- Calls FUN_004b6a10 to format lap data (startTime + bestLapTime range)
- Calls FUN_004b7c80 to write sector/segment data to file
- Closes file via FUN_00566b90/FUN_005668d0

**Globals:**
- `DAT_007c54e8` � PlayerVehiclePtr
- `DAT_0059e670` � zero constant (invalid lap check)
- `DAT_0059e440` � threshold constant (> 0 check)
- `DAT_005c32d8` � ".HOT" extension constant
- `DAT_005be714`/`DAT_005be718` � hot lap directory path

**Calls:** FUN_004b6a10 (lap data format), FUN_004b7c80 (hot lap write), FUN_005668b0 (file open), FUN_00566940 (write check), FUN_00566b90 (file close), FUN_005668d0 (cleanup), FUN_00423a00 (string copy), FUN_004a0e70 (message buffer poll)

**Moddability:** No � output-only hot lap file saving.

---

## FUN_0046bc20 � Lap Time HTML Formatter

Source: timing/session display. Formats driver lap times into HTML table rows using `"%d:%06.3f"`.

**Key logic:**
- Checks if session data at `DAT_005ef9a0[iVar5*0x1230]` is valid and `DAT_005f0714` > 0
- Sets param_1+0x178 to -1 if invalid, otherwise processes
- Calls `FUN_00489cb0` to reset HTML buffer
- Copies driver name and team name from session data arrays
- Loops through laps up to `local_23c` (capped by min of two limits)
- Formats lap time as `"%d:%06.3f"` when time > 0, else `"--:--.---"`
- Computes gap to leader when applicable: `"%s%d:%06.3f"` (colored by gap threshold)
- Concatenates rank, name, time, gap strings and calls `FUN_00489600` to write HTML row
- Uses FUN_0058815f for string formatting, FUN_00489600 for HTML output

**Globals:** `DAT_005ef9a0` / `DAT_005f0cf8` / `DAT_005f0714` � session lap data arrays (stride 0x1230/0x48c0)

**Calls:** FUN_00489cb0 (HTML buffer reset), FUN_0058815f (format), FUN_00489600 (HTML write)

**Moddability:** Yes � reads and displays lap time data; visual output, no game state mutation.

---

## FUN_00468bf0 � Grand Prix Results HTML Writer

Source: HTML results module. Writes per-driver results page using `"%s%s%s"` format with `GrandPrixName`.

**Key logic:**
- Initializes local result name/time buffers to empty string `DAT_005c694c`
- Compares `DAT_007ce668` (current track name) against param_1+0x17c; if different, calls `FUN_00566650` (path change)
- Sets `DAT_007d2dc8` = `DAT_007d2dc0` (linked list head)
- Iterates linked list of result entries:
  - Gets driver name via `FUN_004c5840`; if non-zero, gets fallback via `FUN_005679c0`/`FUN_00567970`
  - Formats driver index via `FUN_0058815f` with `"%i:%06.3f"` (minutes:seconds)
  - Writes 4 HTML sections: driver name, index, time, blank line via `FUN_00489600`
  - Advances to next linked list entry

**Globals:** `DAT_007d2dc0` / `DAT_007d2dc8` � results linked list; `DAT_007ce668` � track name

**Calls:** FUN_00566650 (path change), FUN_004c5840 (string field read), FUN_005679c0/FUN_00567970 (INI lookup), FUN_0058815f (format), FUN_00487010 (section header), FUN_00489600 (HTML write)

**Moddability:** No � output-only HTML results page.

---

## FUN_0046b830 � Session Timing Display

Source: session/HUD timing. Formats driver lap/speed time using `"%02.2d:%06.3f"` or `"%6.2f"`.

**Key logic:**
- Reads driver pointer from `DAT_007c54f0[param_1]`
- Writes default `"--:--.---"` string to output buffer
- If driver valid and session type >= 0:
  - Session 0-6 (race/practice/qualify): checks for valid best lap (> 0) at driver+0x409c; formats `"%02.2d:%06.3f"` via FUN_0058815f
  - Session 7 (testing): checks driver mode == 1 and valid speed at +0x40b8; formats `"%6.2f"` speed percentage (uses global multipliers)

**Globals:** `DAT_007c54f0` � driver pointer array; `DAT_007c56a4` � session type; `DAT_0059e440` � zero threshold

**Calls:** FUN_0058815f (format), FUN_0058957a (time conversion)

**Moddability:** No � read-only HUD display formatting.

---

## FUN_0046b9b0 � Loading Grid Screen

Source: session/UI. Displays `"Loading Grid..."` text during grid loading state.

**Key logic:**
- Calls `FUN_00489cb0` to reset HTML buffer
- Sets param_1+0x178 to -1 (invalid index)
- If `DAT_007d0410 == 5` (race session), copies "Loading Grid..." string to `DAT_005ec4cc`
- Calls `FUN_00489600` to output the message as HTML

**Calls:** FUN_00489cb0 (HTML reset), FUN_00423a00 (string compare), FUN_00489600 (HTML write)

**Moddability:** No � pure UI loading indicator.

---

## FUN_004a0250 � Post Race Monitor

Source: race monitor page `"POST RACE MONITOR"`. Post-race results/standings display.

**Key logic:**
- Shows cursor via `ShowCursor(1)` loop
- If session type == 7 (race) and mode != 6:
  - Calls `FUN_004d21d0` (check some condition)
  - If false and not mode 5 and `DAT_007cec90 == 0`: calls `FUN_004a0da0`, `FUN_0042d210(1)`, `FUN_004c8d60`
  - If true: handles player vehicle state at +13000, checks input via vtable, optionally calls `FUN_0046ba20`/`FUN_0046c030`; then calls `FUN_00497940` to display monitor page
- Calls cleanup: `FUN_004d5840`, `FUN_004a0d30`, `FUN_0042bc10`
- If escape pressed: calls `FUN_004efac0`, `FUN_004c6d90`
- Iterates drivers: if driver+0xc4 flag set, calls `FUN_004f7010`
- Finalizes with camera/viewport setup

**Globals:** `DAT_007c56a4` � session type; `DAT_007d0410` � game mode; `DAT_007c54e8` � PlayerVehiclePtr

**Calls:** FUN_004d21d0, FUN_004a0da0, FUN_0042d210, FUN_004c8d60, FUN_004bc060, FUN_0046ba20, FUN_0046c030, FUN_00497940 (page display), FUN_004d5840, FUN_004a0d30, FUN_0042bc10, FUN_004efac0, FUN_004c6d90, FUN_004f7010

**Moddability:** Yes � post-race flow affects session transitions; called during race end logic.

---

## FUN_004a0030 � Monitor Page Display

Source: UI/monitor. Shows `"MONITORPAGE"` string based on game mode.

**Key logic:**
- Switch on `DAT_007d0410`:
  - Cases 1-4: calls `FUN_004a0d30(1)` then `FUN_00497940` with "MONITORPAGE"
  - Cases 5-6: calls `FUN_004a0d30(1)` (no page string)
- Calls `FUN_004c8d90(1)` and `FUN_0042e400()`

**Calls:** FUN_004a0d30, FUN_00497940 (page display), FUN_004c8d90, FUN_0042e400

**Moddability:** No � simple mode-based routing.

---

## FUN_004a0430 � Multiplayer/Monitor Page Router

Source: UI/multiplayer. Routes to `"MPCLIENTGRID"`, `"MPHOSTGRID"`, or `"MONITORPAGE"`.

**Key logic:**
- If mode 1-4: displays "MONITORPAGE"
- If mode 5: calls `FUN_00461dc0` to check host status; displays "MPHOSTGRID" if host, else "MPCLIENTGRID"

**Calls:** FUN_00461dc0 (host check), FUN_00497940 (page display)

**Moddability:** No � pure UI page routing for multiplayer.

---

## FUN_0046fc30 � Menu Page Router

Source: UI/menu. Routes to `"MAIN MENU"`, `"MPCLIENTGRID"`, `"MPHOSTGRID"`, or `"CH_POSTRACEDRIVERSTANDINGS"`.

**Key logic:**
- Calls vtable method on `DAT_005eb10c` if non-null
- Calls `FUN_004186a0` (cursor show)
- If mode == 4: plays win videos via `FUN_004a0760`, then navigates to "CH_POSTRACEDRIVERSTANDINGS"
- If mode != 5: navigates to "MAIN MENU", sets `DAT_005cc9e8 = 3`
- If mode == 5: checks host flag via `FUN_00461dc0`; navigates to "MPHOSTGRID" or "MPCLIENTGRID"

**Calls:** FUN_004186a0, FUN_004a0760 (videos), FUN_00486aa0 (page nav), FUN_00461dc0 (host check), FUN_00497940 (page display)

**Moddability:** Yes � controls post-race flow routing; determines which page loads next after race.

---

## FUN_00470190 � Monitor Timing Display

Source: timing/monitor. Displays driver standings timing with `"%i:%06.3f"` format.

**Key logic:**
- Calls `FUN_00489cb0` to reset HTML buffer
- Loops through `DAT_008ac488` entries with stride 0x18c
- Computes driver index as `iVar2 + DAT_008ac490`
- Formats time string `"%i:%06.3f"` (minutes:seconds.milliseconds)
- Builds full row string with rank, driver ID, separator, time, separator
- Calls `FUN_00489600` to write each row

**Globals:** `DAT_008ac488` � driver count; `DAT_008ac490` � base index offset

**Calls:** FUN_00489cb0 (HTML reset), FUN_0058815f (format), FUN_00489600 (HTML write)

**Moddability:** No � output-only display formatting.

---

## FUN_0047e400 � Race Laps Getter

Source: config/session. Reads `"RaceLaps"` setting from game configuration.

**Key logic:**
- Calls `FUN_004c5840` to check if config access is available
- If available, calls `FUN_005679c0("RaceLaps")` to find key in INI
- If found, calls `FUN_00567970()` to get value, passes to `FUN_00488b40` for processing

**Calls:** FUN_004c5840, FUN_005679c0 (INI key lookup), FUN_00567970 (INI value get), FUN_00488b40

**Moddability:** Yes � reads RaceLaps config value; used in session setup.

---

## FUN_0047e440 � Circuit Info Page

Source: UI/circuit info. Displays circuit details: name, location, first GP, length, lap record, `"Race Laps (100%):"`.

**Key logic:**
- Calls `FUN_004893c0` for initialization
- Sets param_1 vtable pointer to `PTR_FUN_005a6bc8`
- Calls `FUN_00486f30` for each info label: "Circuit Name:", "Location:", "First Grand Prix:", "Circuit Length:", "Lap Record:", "Race Laps (100%):"

**Calls:** FUN_004893c0, FUN_00486f30 (label write)

**Moddability:** No � static info page, no game logic.

---

## FUN_004b1190 � Session Config Loader

Source: session/config. Loads `"RaceLaps"`, `"QualifyLaps"`, `"Recon_Pit_Open"`, `"Recon_Pit_Closed"`, `"RaceTime"` from INI.

**Key logic:**
- Sets defaults: RaceLaps = 12, QualifyLaps = 5, Pits field width = 15
- Clamps values to min/max bounds from sibling fields
- Reads string at param_1+0x154 (track name); if non-null:
  - Calls `FUN_004c5840` to validate config access
  - Looks up "QualifyLaps": if found, converts via `FUN_00587ece` and clamps
  - Looks up "RaceLaps": if found, converts, clamps, ensures >= 1
  - Looks up "Recon_Pit_Open": if found, stores to `DAT_007cec30`
  - Looks up "Recon_Pit_Closed": if found, stores to `DAT_007cec54`
  - Looks up "RaceTime": calls `FUN_004b1375` for processing

**Globals:** `DAT_007cec30` � pit open lap; `DAT_007cec54` � pit close lap

**Calls:** FUN_004c5840, FUN_005679c0 (INI key lookup), FUN_00567970 (INI value get), FUN_00587ece (string-to-int), FUN_004b1375 (RaceTime handler)

**Moddability:** Yes � loads core session parameters (RaceLaps, QualifyLaps, pit window) from config; directly affects race structure.

---

## FUN_004a5f20 � Exiting Pits Under Red Penalty

Source: steward/penalty. Handles `"Exiting Pits Under Red"` message and penalty application.

**Key logic:**
- If driver pit exit flag (param_1+0x60*4) is non-zero:
  - Calls `FUN_004a5c80(0)` (clear penalty state)
  - Clears flag
  - Increments driver+0x406c penalty counter
  - Calls `FUN_0041a3a0` on driver (apply penalty)
  - If red flag active (`DAT_008acfd4 == 2 && DAT_007cef84 != 0`):
    - Session 7 (race): calls `FUN_004bc0e0` (message only)
    - Other: calls `FUN_004bba90` with volume 1000 (audible message)
- If param_1[5] (another flag) non-zero: calls `FUN_004a3fe0`

**Calls:** FUN_004a5c80, FUN_0041a3a0, FUN_004bc0e0, FUN_004bba90, FUN_004a3fe0

**Moddability:** Yes � enforces red-flag pit exit rule; penalizes player/AI.

---

## FUN_004a5ea0 � Entering Pits Under Red Penalty

Source: steward/penalty. Handles `"Entering Pits Under Red"` message during red flag.

**Key logic:**
- If driver pit entry flag (param_1+0x60*4) is zero:
  - Calls `FUN_004a5c80(2)` (set penalty state)
  - Sets flag to 1
  - Calls `FUN_0041a2b0` on driver
  - Calls `FUN_004bc240` (pit entry handling)
  - If red flag active (`DAT_008acfc8 == 2 && DAT_007cef84 != 0`):
    - Session 7 (race): calls `FUN_004bc0e0` (message)
    - Other: calls `FUN_004bba90` with volume 1000

**Calls:** FUN_004a5c80, FUN_0041a2b0, FUN_004bc240, FUN_004bc0e0, FUN_004bba90

**Moddability:** Yes � enforces red-flag pit entry rule; can trigger during randomizer-controlled sessions.

---

## FUN_004a0760 � Win Videos (windrivers.bik / winRace.bik)

Source: UI/video. Plays Bink videos for driver's championship (`windrivers.bik`) and race win (`winRace.bik`).

**Key logic:**
- Calls vtable method on `DAT_005eb10c` and `FUN_004186a0` (cursor)
- Calls `FUN_004b17b0` (sound setup)
- If escape not pressed, player mode == 1, and `DAT_007d032c == 1` (videos enabled):
  - Builds path: `<track_path>\winRace.bik` and plays via `FUN_004f9b70`
- Calls `FUN_004c2850` (championship check):
  - If championship won: calls `FUN_004c15a0`, checks if season finished (== 3)
  - If finished and driver+0x19c == 0 (human): builds `<track_path>\windrivers.bik` and plays
- Otherwise: calls `FUN_004c2a80` / `FUN_004c2810`
- Checks input keys for menu display via `FUN_0047c360`
- Calls `FUN_0041daf0`; sets `DAT_005cc9e8 = 3`

**Calls:** FUN_004186a0, FUN_004b17b0, FUN_0042bc10, FUN_004f9b70 (Bink play), FUN_004c2850, FUN_004c15a0, FUN_004c1390, FUN_004c2c10, FUN_004c2a80, FUN_004c2810, FUN_0047c360, FUN_0041daf0

**Moddability:** Yes � plays championship/race win videos during post-race flow; visual reward, no game state mutation.

---

## FUN_004a00a0 � FIA Short Bink Video

Source: UI/video. Plays `"FIAShort.bik"` intro video.

**Key logic:**
- Hides cursor via `ShowCursor(0)` loop
- If mode == 4 (race), session == 7 (race), and videos enabled (`DAT_007d032c == 1`):
  - Builds path: `<track_path>\FIAShort.bik` and plays via `FUN_004f9b70`
- Calls various cleanup: `FUN_00463e00`, `FUN_004a0d30`, `FUN_0042d210`, `FUN_004f9f70`, `FUN_00453560`
- Sets player references: `DAT_007c54e0` = current driver, `DAT_007c54dc` = current index
- Calls camera/viewport setup functions
- If escape not pressed: calls `FUN_00434000`, `FUN_004c6d90`, handles pit state, calls `FUN_004efa40`, `FUN_004e4910`
- Calls `FUN_004d4a80` to finalize

**Globals:** `DAT_007d0410` � mode; `DAT_007c56a4` � session type; `DAT_007d032c` � videos enabled flag

**Calls:** FUN_004f9b70 (Bink play), FUN_00463e00, FUN_004a0d30, FUN_0042d210, FUN_00453560, FUN_00434000, FUN_004c6d90, FUN_004efa40, FUN_004e4910, FUN_004d4a80, FUN_004a4000, FUN_004a3b50

**Moddability:** Yes � plays FIA intro video before race; visual, no game state mutation.

---

## FUN_004a08e0 � Constructors Win Bink Video

Source: UI/video. Plays `"winconstructors.bik"` when constructors championship won.

**Key logic:**
- Calls `FUN_004c2760` to check season state
- If state == 3 (season finished):
  - Calls `FUN_004c2850` (championship check)
  - If championship won: calls `FUN_004c1390` to get winning team
  - Calls `FUN_004c0a20` to get team name, `FUN_004c1450` to check if human team
  - If human team and videos enabled (`DAT_007d032c == 1`):
    - Builds path: `<track_path>\winconstructors.bik` and plays via `FUN_004f9b70`
- Calls `FUN_0041e320` to finalize

**Calls:** FUN_004c2760, FUN_004c2850, FUN_004c1390, FUN_004c0a20, FUN_004c1450, FUN_004f9b70 (Bink play), FUN_0041e320

**Moddability:** Yes � plays constructors championship win video; visual reward.

---

## FUN_004a09f0 � Driver Win Replay Video

Source: UI/video. Plays winning driver replay Bink video using `"%s%s%s"` path construction.

**Key logic:**
- Computes offset from `DAT_008ac48c * 0x18c + DAT_008ac490`
- If offset non-zero and videos enabled:
  - Extracts directory path from string at offset+4 by scanning backward for `\`
  - Builds path: `<track_path><driver_dir>\` + constant suffix
  - Plays via `FUN_004f9b70`

**Globals:** `DAT_008ac48c` / `DAT_008ac490` � session array indices; `DAT_007d032c` � videos enabled flag

**Calls:** FUN_0058815f (format), FUN_004f9b70 (Bink play)

**Moddability:** Yes � plays driver win replay video; visual reward.

---

## FUN_004a0490 � Main Menu Page

Source: UI/menu. Routes to `"MAIN MENU"` and handles mode transitions.

**Key logic:**
- If `DAT_007c569c == 5`: sets `DAT_005cc9e8 = 3`, calls `FUN_0042d210(0)` (disable input)
- If mode == 4 (race finished): calls `FUN_004b0770(0)`, checks track name, loads championship data via `FUN_004c40b0`
- If mode == 5: calls `FUN_00463140` (multiplayer main menu)
- If mode == 6: transitions to mode 1 (or fallback modes from `DAT_007d0418`/`DAT_007d041c`)
- Calls vtable method on `DAT_005eb10c`, `FUN_004186a0`, `FUN_0042bd60`, then `FUN_00497940` to display main menu

**Calls:** FUN_0042d210, FUN_004b0770, FUN_004c40b0, FUN_00566650, FUN_00463140, FUN_004186a0, FUN_0042bd60, FUN_00497940 (page display)

**Moddability:** Yes � controls post-race menu flow and mode transitions; determines where game goes after race.

---

## FUN_004a0af0 � Game Filter Dialog

Source: UI/menu. Opens `"Game Filter"` dialog for car/track filtering.

**Key logic:**
- Checks input via vtable call (key 0x17)
- If activated: calls `FUN_005681f0("Game Filter")` to get filter, passes to `FUN_00476f90` for display

**Calls:** FUN_005681f0 (string lookup), FUN_00476f90 (filter dialog)

**Moddability:** No � UI dialog for manual game filtering.

---

## FUN_004a1200 � Application Window Init

Source: main/app. Registers window classes `"F1 Challenge 99-02"` / `"CUBEApp"` / `"CUBERealtime"` and creates main window.

**Key logic:**
- Gets desktop window handle
- Initializes WNDCLASSEXA struct `DAT_007ce270` with:
  - Style, icon, cursor, background, class name "CUBERealtime"
  - Window proc at `LAB_004a1560`
- Formats title `"F1 Challenge 99-02 v%0.3f"` with version from `DAT_007c56b0`
- If `DAT_005ec4a4` flag is zero (fullscreen mode):
  - Registers "CUBERealtime" class, creates window via `CreateWindowExA`
  - Sets clipping region, shows window, sets `DAT_007ce2e4 = 1`
- Else (windowed mode):
  - Registers "CUBEApp" class with different style
  - Gets client rect, calls `FUN_0059db88` (windowed setup)

**Globals:** `DAT_007ce270` / `DAT_007ce2a8` � WNDCLASSEXA structs; `DAT_007c56b0` � app version; `DAT_005ec4a4` � fullscreen flag

**Calls:** GetDesktopWindow, LoadIconA, RegisterClassExA, CreateWindowExA, ClipCursor, ShowWindow, GetClientRect, FUN_0059db88, FUN_0058815f (format)

**Moddability:** No � one-time application startup, no runtime game logic.

---

## FUN_00463bc0 � Multiplayer Circuit Selection

Source: UI/multiplayer. Routes to `"SELECTCIRCUITPAGE"` or `"MULTIPLAYER_CREATEGAME"`.

**Key logic:**
- Checks if driver flag at `*param_1 + 0xc5` is non-zero (ready to create game)

## FUN_0041ac50 � Race Event Sound Dispatch

Source: session/commentary. Fires commentary based on race event type.

**Key logic:**
- Guard: RaceActiveFlag, track loaded, param_1!=0, RacePhase!=8, SessionType==7, player vehicle matches, finish state running
- param_2==0: ID 0xd0. param_2==2: IDs 0xd3-0xd9 by +0x39fc. param_2==3: ID 0xdc

**Struct offsets:** +0x39fc (sessionSubType), +0x4064 (FinishState), +0x489c (DriverNumber)

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041ad80 � Overtake / Position Swap

Source: session. Swaps two drivers' position arrays and fires overtake commentary.

**Key logic:**
- Computes time delta, reads team IDs
- Conditions for swap: lap-time delta < current time AND gap > threshold
- On swap: resets lap time, stores gap and target
- Random float selects commentary ID (0x72=passed, 0x73=was passed)
- Player or AI: different ID sets with ring buffer variety

**Struct offsets:** +0x4fc (lapTimeDelta), +0x69c (overtakeGap), +0x83c (overtakeTarget)

**Calls:** FUN_004f0050, FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041afd0 � Session Event Commentary (Per Car)

Source: session/commentary. Car-specific commentary for events 0-5.

**Key logic:**
- Player: IDs 0x6a-0x6f by event type
- AI: IDs 0xdd-0xdf, passes driver number

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041b190 � Session End Commentary

Source: session. Race-end commentary ID 0x4d.

**Key logic:**
- Only fires for player's own vehicle, audio 0x4d

**Calls:** FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041b250 � Session State / Penalty Commentary

Source: session. Fires commentary for penalty-reason codes.

**Key logic:**
- Player ReasonCode: 1?0x77, 7?0x76, else?0x75
- AI ReasonCode: 1?0xeb, 4?0xee, 9?0xec, else?0xed

**Struct offsets:** +0x4068 (ReasonCode), +0x4044 (penaltyFloat), +0x489c (DriverNumber)

**Calls:** FUN_004144d0, FUN_004d7c10, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_0041c440 � Championship Mode Commentator

Source: session. Championship-context commentary.

**Key logic:**
- If RaceMode 4: gets driver count via FUN_004c2990

**Calls:** FUN_004144d0, FUN_004c2990, FUN_00420000, FUN_004144f0, FUN_00418560

**Moddability:** hardcoded

---

## FUN_00462850 � Session Transition Guard

Source: session. Guards state transitions checking async operations.

**Key logic:**
- Calls FUN_004a0590 for async check
- If complete: calls race init, render UI, sets ready flag, returns 1
- If not: returns 0

**Calls:** FUN_004a0590, FUN_004613e0, FUN_00460710, FUN_0045f2b0

**Moddability:** gate, can force-complete

---

## FUN_00463ef0 � Season/Championship State Init

Source: session. Initializes championship variables.

**Key logic:**
- If no replay: sets championship position offsets based on RaceMode
- Sets DAT_007d0990 from positive bias

**Globals:** DAT_007ce260, DAT_007d0410, DAT_007d0a44, DAT_007d0990

**Moddability:** configurable via globals

---

## FUN_0046ba20 � Vehicle Grid/Start Order Builder

Source: session. Builds starting grid matching vehicle indices to driver IDs.

**Key logic:**
- param_1 != 0: update mode � enumerate, match +0x4060 to driver IDs, build path
- param_1 == 0: insert mode � match by name, insert into ordering

**Calls:** FUN_00489cb0, FUN_0046b5f0, FUN_0058815f, FUN_00489600, FUN_00489c10, FUN_00588410

**Moddability:** grid ordering by driver ID and name

---

## FUN_0046bf10 � Main Session Execution Loop

Source: session. Runs active session loop until completion.

**Key logic:**
- Sets time threshold by SessionType
- Loops FUN_004beb10 (frame tick) until done
- If race: cleanup via DAT_005eb10c
- Returns 0 when done

**Calls:** FUN_004be6f0, FUN_004c8d80, FUN_004988c0, FUN_004beb10, FUN_00496880, FUN_00497250, FUN_00496e90, FUN_004186a0, FUN_0041d630, FUN_004b0170

**Moddability:** inject custom loop behavior

---

## FUN_0046dc60 � Session State Machine

Source: session. Orchestrates pre-race/race/post-race transitions.

**Key logic:**
- Checks if loading complete
- If SessionType 5 + FormationLap: runs session, calls FUN_004d2450
- Sets DAT_005cc9e8 = 4 when done

**Calls:** FUN_004c8d80, FUN_00461db0, FUN_0042d210, FUN_0046bf10, FUN_004d2450, FUN_00497250, FUN_004a0590, FUN_00461dc0, FUN_00462850

**Moddability:** formation lap bypass, session transitions

---

## FUN_00472510 � SessionEnter_PitSupport

Source: game_logic. Prepares vehicle for pit/support session.

**Key logic:**
- Writes SessionType to +0x324, stores pointer-table entry
- Loads string resource, runs pitstop flag setup via FUN_004af220

**Calls:** FUN_00487010, FUN_0058815f, FUN_004af220, FUN_0048b810

**Moddability:** low � pure state transition

---

## FUN_00472630 � SessionEnter_SupportCheck

Source: game_logic. Support race session entry with guard.

**Key logic:**
- Writes SessionType, calls FUN_004ae9f0 for setup
- Checks vehicle count vs threshold, sets +0x310=0 (OK) or 2 (insufficient)

**Calls:** FUN_00487010, FUN_0058815f, FUN_004ae9f0, FUN_0048b810

**Moddability:** low-medium

---

## FUN_00472930 � SessionEnter_QualPractice

Source: game_logic. Qualifying/practice session entry.

**Key logic:**
- Writes SessionType, calls FUN_004ae490 for qual setup

**Calls:** FUN_00487010, FUN_0058815f, FUN_004ae490, FUN_0048b810

**Moddability:** low

---

## FUN_004732d0 � SessionEnter_Race

Source: game_logic. Race session entry.

**Key logic:**
- Calls FUN_004adf10 for race-specific setup (1372 bytes)

**Calls:** FUN_004adf10, FUN_00487010, FUN_0058815f, FUN_0048b810

**Moddability:** low

---

## FUN_00474510 � SessionEnter_Alt

Source: game_logic. Alternate session entry (swapped offsets).

**Key logic:**
- Writes SessionType to +800 (swapped vs siblings), pointer to +0x324

**Calls:** FUN_00487010, FUN_0058815f, FUN_0048b810

**Moddability:** low

---

## FUN_00474ab0 � SessionEnter_MessageOnly

Source: game_logic. Minimal session entry � message display only.

**Key logic:**
- Calls FUN_0058815f with 3 args, no setup call

**Calls:** FUN_0058815f, FUN_0048b810

**Moddability:** low

---

## FUN_00478ed0 � SessionExitOrChecks

Source: game_logic. Session exit with conditional actions.

**Key logic:**
- Compares driver name against DAT_007ce5d0
- If SessionType5 + RaceMode5 + flag: calls vtable +0x3c
- Calls FUN_00479320 cleanup

**Calls:** FUN_00588410, FUN_00479320

**Moddability:** medium

---

## FUN_0047f230 � VehicleArraySearchAndReset

Source: game_logic. Iterates vehicle array, resets mismatched entries.

**Key logic:**
- Outer loop over VehicleCount (stride 0x48c0), inner over VehicleFileCount (stride 0x424)
- Compares strings, if no match: calls FUN_004c78f0(0)

**Calls:** FUN_00588410, FUN_004c78f0

**Moddability:** high � controls cleanup logic

---

## FUN_0049b7a0 � SteeringInputToGear

Source: game_logic. Maps steering input to gear bitmask.

**Key logic:**
- Controller active: return binary gear mask
- Else: compare speed ratio against thresholds (0/1/3/7/0xF)

**Globals:** DAT_0059e824, DAT_005acaf0, DAT_005acaec, DAT_005acae8

**Calls:** FUN_004f1aa0

**Moddability:** high � threshold constants

---

## FUN_0049b9a0 � PlayerCarComparison

Source: game_logic. Compares player vehicle with target.

**Key logic:**
- Compares TeamID strings, vehicle ordering
- Calls FUN_0041b190 for entry setup if conditions met

**Calls:** FUN_0041b190

**Moddability:** medium

---

## FUN_0049d5d0 � HUD_TachoRenderDispatch

Source: game_logic/HUD. Dispatches tachometer rendering.

**Key logic:**
- Switch on DAT_007ce048 display mode
- Routes to sub-renderers: 0?sub-switch by SessionType, 1?FUN_0049e3e0, 3?FUN_0049e170, 4?FUN_0049db80
- Case 2: full tacho draw via FUN_0049de40

**Calls:** FUN_005432f0, FUN_0049d8b0, FUN_0049da60, FUN_0049d700, FUN_0049e3e0, FUN_0049e170, FUN_0049db80, FUN_0049de40

**Moddability:** high � central tacho dispatch

---

## FUN_0049de40 � HUD_TachoFullDraw

Source: game_logic/HUD. Full tachometer rendering (805 bytes).

**Key logic:**
- Guard checks on data pointers
- Draws RPM bar segments with color based on thresholds at +0xcd4/+0xd14/+0xd18/+0xd58
- Draws tick marks and gear indicator (yellow if player, green if not)

**Calls:** FUN_005432f0, FUN_00543440, FUN_0049e570, FUN_0049e7b0, FUN_0049f6a0, FUN_0049c700/770/830/8a0

**Moddability:** high

---

## FUN_0049e670 � HUD_TachoRPMBar

Source: game_logic/HUD. Draws three-segment RPM bar.

**Key logic:**
- If not player vehicle: green bar, return
- Loop 3 segments, compute color via FUN_0049e5b0

**Calls:** FUN_0049e5b0, FUN_00543440

**Moddability:** medium

---

## FUN_0049e7b0 � HUD_TachoTick

Source: game_logic/HUD. Draws single tachometer tick with color.

**Key logic:**
- Normalizes tick value, clamps
- Color: value <= threshold ? red, > threshold2 ? yellow, else ? green

**Globals:** DAT_0059e440, DAT_0059e8cc, DAT_0059e450

**Calls:** FUN_00543440

**Moddability:** high

---

## FUN_0049f170 � HUD_TachoGearCycle

Source: game_logic/HUD. Cycles gear display index.

**Key logic:**
- param_2==0: increment, wrap 0?4
- param_2!=0: decrement, wrap 4?0
- Continues until valid gear found at stride 0x40

**Moddability:** medium

---

## FUN_0049f1c0 � HUD Engine Temp Gauge

Source: game_logic/HUD. Engine temperature gauge.

**Key logic:**
- Loops 5 times reading part names from player ptr +0x3302
- Draws temperature gradient bars

**Calls:** FUN_004a47e0, FUN_00423a00, FUN_0049f6a0, FUN_00553a20

**Moddability:** no � HUD display only

---

## FUN_004a0590 � Session Type Dispatch

Source: game_logic. Maps SessionType to display-mode, triggers reload.

**Key logic:**
- Switch: 1?2, 2?3, 3?4, 4?5, 5?6, 6?7
- If RaceMode 4 and championship active: calls race replay or champ results

**Calls:** FUN_0042cf10, FUN_004c2850, FUN_004a09a0, FUN_004c15a0

**Moddability:** no � state dispatch

---

## FUN_004a0a80 � Session Init / Audio Setup

Source: game_logic. Initializes session audio and message buffer.

**Key logic:**
- If RaceMode 2/4 + SessionType 7: set button bindings
- Init audio engine, set message mode, UI cleanup

**Calls:** FUN_0042d210, FUN_00497250, FUN_004c8d90

**Moddability:** no

---

## FUN_004a0b20 � Points / Finish Position Event

Source: game_logic. Plays sound on season points milestones.

**Key logic:**
- Reads SeasonPoints (+0x403c), TeamID, FinishPosition
- If points %5 ==1: event 0xd. If first + points >1 + (points+3)%5==0: event 0x13

**Calls:** FUN_004d8760

**Moddability:** yes � thresholds are magic numbers

---

## FUN_004a0cb0 � Post-Race Check

Source: game_logic. Triggers post-race flow.

**Key logic:**
- Checks no replay, HUD not disabled, finish state==1
- If all true: calls FUN_004a0c60

**Calls:** FUN_004a0c60

**Moddability:** no

---

## FUN_004a0fd0 � Session State Machine / Pause Handler

Source: game_logic. Handles exit/pause/HUD toggle/input during race.

**Key logic:**
- Exit flag: vehicle cleanup, save check, return 4
- Escape/pause: return 6
- Options menu: return 6
- HUD disable: increment counter, check input
- Timer expiry: decrement, transition
- Process input bindings, call FUN_004a0cb0

**Calls:** FUN_004bc330, FUN_0042bc10, FUN_004ef5a0, FUN_00404b60, FUN_00485b90, FUN_004a0cf0, FUN_00404f00, FUN_00404f30, FUN_004a0cb0

**Moddability:** no � core session state machine

---

## FUN_004a4110 � AI Overtaking / Aggression Probability

Source: game_logic. Determines if AI attempts overtake.

**Key logic:**
- Iterates vehicles, removes invalid
- If any active with low ability: return 0
- Session 7 race: return 1 (always overtake)
- Multi-stage probability: early/mid/late race
- Probability modified by population, ability, track multiplier

**Calls:** FUN_0042add0, FUN_00426cc0, FUN_0042ae90, _rand

**Moddability:** yes � many probability constants

---

## FUN_004a6d50 � SeasonPointsCheck

Source: session_race_logic. Checks season points threshold.

**Key logic:**
- Only in race session (SessionType 7)
- Reads +0x4040 flag, +0x403c SeasonPoints
- If entry value == SeasonPoints + 1: call FUN_004a5c80(1)

**Calls:** FUN_004a5c80

**Moddability:** medium

---

## FUN_004b17b0 � HotlapRecordingCheck

Source: session_race_logic. Enables hotlap recording.

**Key logic:**
- SessionType 5 or 7, mode != 3, mode==4 + DAT_008acfa0!=0
- Calls FUN_004c2830(1)

**Calls:** FUN_004c2830

**Moddability:** high � simple conditions

---

## FUN_004b9890 � Race Tick Advance / Frame Dispatch

Source: session. Advances physics, sound, state for all vehicles.

**Key logic:**
- Guards on DAT_007ce254 (0=session active)
- Captures timer, clamps delta, calls vehicle tick loop
- Calls FUN_0042bbd0, FUN_0040cde0

**Calls:** FUN_0042d210, FUN_0040cd60, FUN_004b87c0, FUN_004b9cd0, FUN_004b9ce0, FUN_0040cde0, FUN_004b8bd0, FUN_004c8650, FUN_004b8ae0, FUN_0042bbd0, FUN_004b8940, FUN_004c8d60/70

**Moddability:** hookable

---

## FUN_004b9b80 � Session Timestamp Comparison / AI Sort Trigger

Source: session. Triggers AI re-sort when laps change.

**Key logic:**
- Orders timestamps, calls FUN_004b9510
- If rounded lap counts differ: calls FUN_004ee2d0 and FUN_004e3a50 per vehicle

**Calls:** FUN_004b8790, FUN_004b9510, FUN_004b3b40, FUN_005895a2, FUN_004ee2d0, FUN_004e3a50

**Moddability:** hookable

---

## FUN_004bb810 � Vehicle Array Buffer Allocator

Source: session. Allocates three parallel arrays for vehicle state.

**Key logic:**
- Sets mode by SessionType (7=race mode 2, else mode 0)
- Allocates 3 buffers (length clamped 0x80)
- Initializes to -1.0f and 0

**Calls:** FUN_004bb950, operator_new

**Moddability:** hardcoded (array cap 128)

---

## FUN_004bb8e0 � State Reset on Session Condition

Source: session. Resets tracking state fields.

**Key logic:**
- Non-race session + vehicle state valid: sets 3 floats to -4.0f
- Always resets counters/flags

**Calls:** FUN_004e9ca0

**Moddability:** hardcoded

---

## FUN_004bc060 � Vehicle Audio Event Dispatch

Source: session. Plays sound events for vehicle actions.

**Key logic:**
- If param_2 != 0: event 0x1a. Else: event 0x1b
- Uses ring buffer

**Calls:** FUN_004b33b0

**Moddability:** configurable

---

## FUN_004bc240 � State Machine Transition (Non-Race)

Source: session. Transitions state 2?1 in non-race.

**Key logic:**
- If not race AND flag set AND state==2: set state=1

**Moddability:** hardcoded

---

## FUN_004bc340 � Session Type Condition Check

Source: session. Returns combined flag based on session type.

**Key logic:**
- Complex condition on DAT_007c569c, DAT_007c56a4, DAT_007c56a8, DAT_007cef84
- Returns 1 or masked value

**Moddability:** hardcoded

---

## FUN_004bff70 � Race Mode Guard / Wrapper

Source: session. Thin wrapper based on RaceMode.

**Key logic:**
- If 0 < RaceMode < 6: calls FUN_0059d963

**Moddability:** hardcoded

---

## FUN_004bffa4 � Vehicle Grid Sorting / Starting Order

Source: session. Selection-sort of vehicles by metric.

**Key logic:**
- Sort path: index, query via FUN_004c0260/FUN_004c02d0, sort by value
- Non-sort (human present): pick starting position from DAT_007d0110 or random
- Fill remaining AI slots sequentially

**Calls:** FUN_0042bc10, FUN_004c0260, FUN_004c02d0, FUN_004bc2f0

**Moddability:** configurable via DAT_007d0110

---

## FUN_004c01a0 � SortDriverInitOrder

Source: steward. Initializes driver rendering priority order.

**Key logic:**
- Stores vehicle +0x4710 key indexed by +0x4894 driver ID
- Selection sort, calls FUN_004bc2f0 for draw order

**Calls:** FUN_004bc2f0

**Moddability:** render order, not gameplay-critical

---

## FUN_004c0850 � CopyDriverDataToScoringDB

Source: steward. Copies driver/team names to SeasonScoringDB.

**Key logic:**
- Computes destination base from DAT_007d2e48 + index*0x48c0
- Copies strings to +0x4620 (driver name) and +0x4714 (team name)
- Writes finish position to +0x4058

**Calls:** FUN_004c3f80, FUN_004bc2f0, FUN_004ef5a0

**Moddability:** direct scoring DB writes

---

## FUN_004c1050 � InitAllDrivers

Source: steward. Initializes all vehicle entries at session start.

**Key logic:**
- Resets UI theme, calls FUN_004c0850
- Loops 103 sub-slots, clears unused scoring slots
- Stores GameState from param_1+0xb14c
- Loads path strings for validation

**Calls:** FUN_004c11d0, FUN_004c11e0, FUN_004c55b0, FUN_004c54f0, FUN_004c0850, FUN_004c1370, FUN_004ef5a0, FUN_004b1190, FUN_00566650, FUN_00415730

**Moddability:** central init

---

## FUN_004c29f0 � UpdateRaceStateScoring

Source: steward. Per-tick scoring update during race.

**Key logic:**
- Gate check, SessionType 7 only
- Reads player position, calls scoring update
- AI adjustment via AIDifficultySlider, time scale update
- If RaceMode 3/4 and first: race-end trigger

**Calls:** FUN_0042bc10, FUN_004c2bf0, FUN_004c2c40, FUN_004c2dc0, FUN_004c2d30, FUN_004c2c30

**Moddability:** controls scoring tick

---

## FUN_004c4d50 � ParseDriverListString

Source: steward. Parses driver name string, builds linked list.

**Key logic:**
- If string non-null and not empty: parses against 6 pattern templates
- 3 match groups, capped at 49 each
- Allocates linked list nodes for each match

**Calls:** FUN_004c4cf0, FUN_00566650, FUN_005897ca, FUN_00588410, FUN_004c4990, FUN_004c4aa0, FUN_004c4bb0

**Moddability:** pattern templates at DAT_005d30xx determine matching

---

## FUN_004c6b60 � SessionTickUpdate

Source: steward. Per-frame session update.

**Key logic:**
- Calls timer, track pos, pause check
- On-track: AI driver update, player-specific update
- Off-track: AI recovery
- If session 7 + phase 3/4: pit update

**Calls:** FUN_004bb8e0, FUN_004d1180, FUN_004bc9b0, FUN_004ef7c0, FUN_004e9600, FUN_004f1c00, FUN_004a5e60, FUN_004a5e80, FUN_0040d100, FUN_00424b20, FUN_004efa40

**Moddability:** central update tick

---

## FUN_004c6e80 � ResetDriverGridState

Source: steward. Resets vehicle grid position state.

**Key logic:**
- Timer reset, scene reset, AI/physics reset per vehicle
- Sets grid column/row to -1

**Calls:** FUN_00410b40, FUN_004e4790, FUN_004e09e0, FUN_004a4db0, FUN_004f83b0, FUN_004bb950, FUN_0042ae20, FUN_004c79e0, FUN_004d1670

**Moddability:** grid reset

---

## FUN_004c6f10 � AssignDriverGridPosition

Source: steward. Finds unoccupied grid position.

**Key logic:**
- Computes column from TeamID mod 52
- Scans for team string match
- 3-row permutation: default {0,2,1} or inverted
- Checks conflict, tries all rows/columns

**Calls:** FUN_004d1410, FUN_00588410, FUN_00403f70, FUN_00403fc0, FUN_00404030

**Moddability:** grid layout (column count 52)

---

## FUN_004c7bd0 � IsDriverPlayer

Source: steward. Returns whether vehicle is player's car.

**Key logic:**
- Compares +0x4894 driver ID to player vehicle
- Returns packed (isPlayer, driverID>>8)

**Moddability:** pure query

---

## FUN_004cdb20 � Steward: Scoring/Overtake/AI Pace

Source: steward.cpp. Dispatches per-vehicle scoring, AI pace, physics.

**Key logic:**
- Cases 0-5: computes 2D screen position, alpha fade, renders name/distance
- Cases 6-7: formation lap culling
- Case 8: pit limiter alpha with corona layers
- Case 0xC: physics constraint, velocity integration
- Case 0xD: cleanup

**Calls:** FUN_004b9ce0, FUN_004cb5a0, FUN_004c9c70, FUN_004cbdd0, FUN_004cbf50, FUN_004ccb30, FUN_0040c870, FUN_004cc500, FUN_00558c60, FUN_00558cb0, FUN_00558cf0, FUN_00558dc0, FUN_005881f0

**Moddability:** no

---

## FUN_004d1180 � Steward Dispatch: Session Type Check

Source: steward. Dispatches render/update by session context.

**Key logic:**
- If SessionType 7 + RacePhase 2/3/4: calls FUN_004d10e0
- Otherwise: FUN_004d1140

**Moddability:** no

---

## FUN_004d1670 � Steward HUD: CEL/DNF Status Flags

Source: steward. Drives HUD indicator lights.

**Key logic:**
- Builds flag table from vehicle +0x48a4
- Iterates 52 slots: CEL flag?red/green, state flag?red

**Calls:** FUN_0054c030

**Moddability:** no

---

## FUN_004d1730 � Steward: Penalty System Logging

Source: steward. Checks penalty conditions, logs events.

**Key logic:**
- Phase 1: clear penalty states
- Phase 2: iterate vehicles, compute speed threshold, check track normal dot product
- Phase 3: process penalty list, log changes to ring buffer

**Calls:** FUN_004d0f00, FUN_004f0050, FUN_0041b3c0, FUN_004b33b0

**Moddability:** no

---

## FUN_004d1b50 � Driver ID Lookup

Source: steward. Looks up driver index by team/class slot.

**Key logic:**
- Reads team ID byte, checks validity table
- If invalid: iterate vehicles matching +0x4060
- Fallback: first vehicle's team ID

**Moddability:** no

---

## FUN_004d1c40 � Lap Time Comparison / Position Swap

Source: steward. Compares lap times, conditionally swaps position.

**Key logic:**
- If param_4==0 (compare mode): compares lap time from DAT_005f0774
- Returns comparison flags
- If new time NOT better: calls FUN_00419690 for swap

**Calls:** FUN_00419690

**Moddability:** no

---

## FUN_004d1d80 � Steward: Proximity / Gap Tracking

Source: steward. Computes per-vehicle distance, tracks overtake state.

**Key logic:**
- Phase 1: compute gap for each vehicle from player position
- Phase 2: detect overtake state changes
- Phase 3: sort by team ID, detect changes, write to ring buffer

**Calls:** FUN_004e9630, FUN_005890aa, FUN_004d0c20, FUN_004d0cf0, FUN_004d1730, FUN_004b33b0

**Moddability:** no

---

## FUN_004d2170 � All Clear Check for Warning

Source: steward. Checks all vehicles clear before proceeding.

**Key logic:**
- If time remaining + DSQ threshold >= current time: not yet clear
- Iterates all via FUN_004bc9b0

**Calls:** FUN_004bc9b0

**Moddability:** no

---

## FUN_004d21d0 � Race Phase Check

Source: steward. Returns 0 if pre-race/green, 1 otherwise.

**Key logic:**
- Cases 0-4 ? 0, default ? 1

**Moddability:** no

---

## FUN_004d2450 � Set First Uninitialized Vehicle Active

Source: steward. Finds first uninitialized vehicle, sets active.

**Key logic:**
- Searches for +0x4064 == 0, sets to 1 if not DSQ

**Moddability:** no

---

## FUN_004d24a0 � Check First Uninitialized Vehicle

Source: steward. Returns 1 if all vehicles initialized.

**Key logic:**
- Iterates for +0x4064 == 0. Returns 0 if any found

**Moddability:** no

---

## FUN_004d4580 � Steward Update Main Dispatch

Source: steward. Main steward tick � session start, pit timer, penalty, phase logic.

**Key logic:**
- If param_1+0xa4: session time init
- If param_1+0xa8: elapsed time update
- If SessionType < 7: compute remaining time, proximity update
- If SessionType 7 (race): switch on RacePhase (0-1, 2, 3, 4, 5-8)
- Handles formation lap, FCY, green flag, pit window, post-race

**Calls:** FUN_004d0b20, FUN_00448330, FUN_004d2e50, FUN_004d1d80, FUN_0044f460, FUN_0044f0e0, FUN_0045bde0, FUN_004d2260, FUN_0040dbc0, FUN_0040e170, FUN_004d2170, FUN_004d2300, FUN_00461cd0, FUN_004a0da0

**Moddability:** no

---

## FUN_004d59b0 � Setup Bitfield Encoding

Source: steward. Encodes session/vehicle config into bitfield.

**Key logic:**
- Iterates 11 entries from DAT_007c749a
- Special case EngineWearMode=0 at index 5
- Accumulates shifted values, writes 4 bytes + 4 floats

**Calls:** FUN_004d5be0

**Moddability:** configurable

---

## FUN_004d82d0 � On-Screen Display Indicators

Source: session/HUD. Builds command string for OSD (ABS, TC, brake, DRS, ERS).

**Key logic:**
- Appends characters: > (brake), A (ABS), ? (TC), f (engine brake), B (phase 8)
- If TC mode 2: DRS, ERS mode, ERS deploy indicators

**Calls:** FUN_00404f10, FUN_0049bad0, FUN_0049bb20, FUN_0049bab0, FUN_0049ba90, FUN_0049ba50, FUN_0049ba30, FUN_00552fc0, FUN_00553070

**Moddability:** indicator characters, display flags

---

## FUN_004d88d0 � Structure Init

Source: session. Initializes multi-entry structure.

**Key logic:**
- Fills 25 entries at +0x10 via FUN_004d9290/FUN_004daea0
- Fills 3 entries at +0x74 via FUN_004db420
- Sets +0xc via FUN_004dc220, +0xd8 via FUN_004dc290

**Calls:** FUN_004d9290, FUN_004daea0, FUN_004db420, FUN_004d93e0, FUN_004dc220, FUN_004dc290

**Moddability:** number of entries (0x19, 3)

---

## FUN_004d95d0 � Dual-Vehicle Position Updater

Source: session. Finds two vehicles by index, updates positions.

**Key logic:**
- Matches param_1/param_2 against vehicle +0x4060
- Calls FUN_004d9690 with offset constants

**Calls:** FUN_004d9690

**Moddability:** offset globals control spacing

---

## FUN_004da840 � Pit/Grid Position State Machine

Source: session. State machine for pit/grid logic.

**Key logic:**
- State 0: init ? state 2 or 1 (waiting)
- State 1: timer countdown ? state 2
- State 2: copy position, call FUN_004da990, FUN_004dae00
- If pit exit ready and cheats disabled: triggers retirement

**Calls:** FUN_004d1b50, FUN_004dad80, FUN_004da990, FUN_004dae00, FUN_004ef5a0, FUN_0040cde0, FUN_0040d240, FUN_004d8760

**Moddability:** state machine timer, retirement trigger

---

## FUN_004da990 � Vehicle Count by Threshold

Source: session. Counts vehicles with +0x403c = threshold.

**Gloabls:** DAT_005c329c, DAT_007c54f0

**Moddability:** comparison operator

---

## FUN_004dad80 � Pit Exit Visibility Check

Source: session. Returns 1 if vehicle should exit pits.

**Key logic:**
- Returns 1 if: vehicle behind player, or position >= VehicleCount
- Sets flag when leading field

**Calls:** FUN_004dae80, FUN_004da990, FUN_004d1b50

**Moddability:** visibility decision logic

---

## FUN_004dae00 � Pit Exit Readiness Check

Source: session. Returns 1 if pit exit timers firing.

**Key logic:**
- Checks param_1+0x14 timer, +0x1c timer
- Verifies AI slot, player ahead, engine running

**Calls:** FUN_004d1b50

**Moddability:** timer thresholds

---

## FUN_004dbac3 � HUD Command String Builder

Source: session/HUD. Builds command string from flags.

**Key logic:**
- Prepends '>' if brake flag set
- Appends ABS (A), engine brake (f), TC (?), phase 8 (B)

**Calls:** FUN_0049bb20, FUN_0049ba90, FUN_0049bab0, FUN_004d7e40

**Moddability:** indicator character mapping

---

## FUN_004f0430 � Vehicle Setup Init / Per-Frame Update

Source: session. Vehicle setup and per-frame update dispatch.

**Key logic:**
- Case 0 (player): full wheel/suspension setup, brake/TCS/ABS factors
- Cases 1-2: partial setup with steering wobble randomization
- Case 3 (replay): load from replay data
- Post-switch: calls per-frame effects update every 16 frames

**Calls:** FUN_004a55a0, FUN_00567120, FUN_004e23d0, FUN_004f87c0, FUN_00447100, FUN_00446fd0, FUN_004e2610, FUN_004e2230, FUN_004e24a0, FUN_004f12e0, FUN_004f1aa0, FUN_004b9ac0, FUN_004b9ce0, FUN_004c73f0, FUN_004f0dd0, FUN_004e19d0, FUN_004f0d20, FUN_0058957a

**Moddability:** suspension geometry, brake/TCS globals

---

## FUN_004f0d20 � Camera FOV / Zoom by Proximity

Source: session. Sets camera FOV based on other driver proximity.

**Key logic:**
- If driver index differs from player vehicle: compute distance
- If below threshold: set FOV from DAT_007cf83c
- Calls FUN_004e2ca0 with result

**Calls:** FUN_004d1140, FUN_004efb20, FUN_004e2ca0

**Moddability:** proximity threshold, FOV value

---

## FUN_004f1fe0 � AI State Machine for Pursuit

Source: ai_vehicle. AI pursuit behavior with timer + distance.

**Key logic:**
- State != 0: distance check, timer accumulation
- If SessionType 7 + flag: clear, call engine sound
- State == 0: distance check, opponent slot check
- Calls FUN_0041b250 (brake), path following
- Sets DAT_007ce258 if AI off

**Calls:** FUN_004e0ed0, FUN_004d21d0, FUN_004effd0, FUN_00403640, FUN_0041b250, FUN_004d1140, FUN_004ef7c0, FUN_004a5c80, FUN_004bc060

**Moddability:** timer threshold DAT_007d0a8c controls reaction speed

---

## FUN_0042bbd0 — Set Player Vehicle Index (DC)

Source: season_scoring.cpp. Sets DAT_007c54dc to array index matching param_1.

**Key logic:**
- Computes DAT_007c54e0 = base season address + param_1 * 0x48c0
- Iterates DAT_007c54f0 array (0x68 max), first match sets DAT_007c54dc = index

**Moddability:** no

---

## FUN_0042bc40 — Set Player Vehicle Index (E8)

Source: season_scoring.cpp. Mirror of FUN_0042bbd0 for DAT_007c54e8 and DAT_007c54e4.

**Key logic:**
- Computes DAT_007c54e8 = base season address + param_1 * 0x48c0
- Iterates DAT_007c54f0 array, first match sets DAT_007c54e4 = index

**Moddability:** no

---

## FUN_0042bc80 — Build Active Vehicle Pointer Array

Source: session_setup.cpp. Populates DAT_007c54f0 from season entries.

**Key logic:**
- Scans season database (stride 0x48c0) for entries with +13000 != -1
- Stores valid pointers in DAT_007c54f0
- Fills remaining slots re-scanning
- Resets DAT_007c54dc and DAT_007c54e4 to 0
- Finds indices matching DAT_007c54e0 and DAT_007c54e8
- Returns active count

**Moddability:** no

---

## FUN_004feaf0 — Audio Event Ring Buffer Processing

Source: audio. Generates, sorts, and stores audio events based on noise/QA sampling.

**Key logic:**
- Advances ring buffer counter DAT_008aae70
- Uses noise values from DAT_008ab274 scaled by constants
- Loops 720 times computing delta between center frequency and stepped value
- If positive delta found: finds matching peaks, applies scaling
- Two event generation passes with threshold checks
- After collection: merge-sorts event list by position

**Globals:** DAT_008aae70, DAT_008ab274, DAT_008aae74, DAT_007cf8cc, DAT_007cf8f0

**Calls:** FUN_004fde00, FUN_004fdeb0, operator_new, FUN_004ff2b0

**Moddability:** noise table, frequency offset, thresholds

---

## FUN_004ff1d0 — Audio Filter Parameter Calculation

Source: audio. Computes blend/parameter from event linked list.

**Key logic:**
- Reads linked list head from param_1+0x38
- Selects threshold by session type
- Iterates list tracking min/max intensity
- Computes average intensity + stored offset
- If result < zero: mute. If > 1.0: clamp
- Calls FUN_004feaa0 with computed value

**Calls:** FUN_004ff0e0, FUN_004feaa0

**Moddability:** threshold constants, stored offset bias

---

## FUN_00461610 — SessionConfigBuilder

Source: session. Builds session configuration structure from global variables.

**Key logic:**
- Gets scene name via FUN_00415c30 + FUN_004c5690
- Extracts filename from scene path (last segment after `\`)
- Strips extension (after `.`)
- Calls FUN_004336d0 + FUN_004618d0 for string processing
- Packs game configuration booleans into bitfield at param_1+0x76:
  - Bits from DAT_007d0a44, DAT_007d0fc4, DAT_007d0c18, DAT_007d0d14, DAT_007d0014, DAT_007ceb10
  - Bit packing from DAT_007ce874, DAT_007ce88c, DAT_007ce958 (TireModelMode), DAT_007ce97c, DAT_007ced44, DAT_007cee40, DAT_007cef3c
- Stores pit timers at +0x78 (ReconPitOpen) and +0x7a (ReconPitClosed)
- Sets fuel level from DAT_007d108c (clamped 0–65535)
- Selects session detail level via switch on DAT_007d0e50:
  - Default: 6, Case 1: 8, Case 2: 12, Case 3: 14, Case 4: 32
- Clamps to DAT_007d0ea0 (min) / DAT_007d0ea4 (max)
- Writes remaining session config globals (DAT_007cf134, DAT_007cf038, DAT_007d084c, DAT_007d0f4c)
- Calls FUN_004615c0 for vehicle ID setup

**Globals:** DAT_007d0a44, DAT_007d0fc4, DAT_007d0c18, DAT_007d0d14, DAT_007d0014, DAT_007ceb10, DAT_007ce874, DAT_007ce88c, DAT_007ce958 (TireModelMode), DAT_007ce97c, DAT_007ced44, DAT_007cee40, DAT_007cef3c, DAT_007cec30 (ReconPitOpen), DAT_007cec54 (ReconPitClosed), DAT_007d108c, DAT_007d0e50, DAT_007d0e98, DAT_007d0ea0, DAT_007d0ea4, DAT_007cf134, DAT_007cf038, DAT_007d084c, DAT_007d0f4c

**Calls:** FUN_00415c30, FUN_004c5690, FUN_004336d0, FUN_004618d0, FUN_004615c0

**Moddability:** `configurable` — all session config values read from setup globals

---

## FUN_00461900 — SessionConfigWriteback

Source: session. Writes session config structure back to global variables.

**Key logic:**
- For each bitfield at param_1+0x76: if bit set, writes to corresponding global:
  - Bit 0: DAT_007ce874, Bit 1: DAT_007ce88c, Bit 2: DAT_007ce958 (TireModelMode), Bit 3: DAT_007ce97c
  - Bit 4: DAT_007d108c (fuel level converted from short × _DAT_0059e600)
  - Bit 10: DAT_007ced44, Bit 11: DAT_007cee40, Bit 12: DAT_007cef3c
- Writes pit open/close timers from +0x78/+0x7a to DAT_007cec30/DAT_007cec54
- Checks player vehicle ID via FUN_004615f0(1) → DAT_007d0134
- Calls FUN_004b0ef0(5) for setup completion

**Globals:** DAT_007d0a44, DAT_007d0fc4, DAT_007d0c18, DAT_007d0d14, DAT_007d0014, DAT_007ceb10, DAT_007ce874, DAT_007ce88c, DAT_007ce958, DAT_007ce97c, DAT_007d108c, DAT_007ced44, DAT_007cee40, DAT_007cef3c, DAT_007cec30, DAT_007cec54, DAT_007d0134

**Calls:** FUN_004c5690, FUN_004c54f0, FUN_004b1410, FUN_0047f1f0, FUN_004646c0, FUN_00464720, FUN_004615f0, FUN_004b0ef0

**Moddability:** direct writeback — modifiable at config load

---

## FUN_004d2300 — SessionParticleTrigger

Source: race. Triggers session-state-dependent particle effect.

**Key logic:**
- Calls FUN_00461db0 to check param_1 flag
- If flag unset: uses speed factor 3.0
- If flag set: checks `_DAT_008afea0 < _DAT_005acef0` → early return; else speed factor 2.5
- If particle slot count (`DAT_0083ee60`) < 0x3ff: increments slot + allocates stride 0x1b0
- Calls FUN_004b33b0 to encode progress bar event (type 4, 0x14, 8, 0xff)
- Sets position from `_DAT_008afea0 + speed_factor`
- Adds random jitter from ring buffer

**Globals:** DAT_0083ee60, DAT_008aae64, DAT_008aae70, DAT_008aae74

**Calls:** FUN_00461db0, FUN_004b33b0

**Moddability:** speed factor, particle slot limit, jitter magnitude

---

## FUN_004186f0 — Text/Overlay Display Timer

Source: overlay.cpp. Manages timed display of text/overlay elements. Checks DAT_007d0308 (RaceActiveFlag) and DAT_007cf3c8. Uses timer at +0xae8 compared against _DAT_008afea8. Decrements counter at +0x135c when timer expired. Calls FUN_00411840 to render formatted text.

**Key logic:**
- Returns 0 if race inactive or timer not started
- Calls vtable at +0xaf4 for element operations
- Detects timer expiry via _DAT_008afea8 comparison
- Decrements repeat count at +0x135c
- Checks threshold at DAT_005bf9ac + index*0x14
- Renders text via FUN_00411840
- Sets display state flags at +0xae4

**Globals:** DAT_007d0308 (RaceActiveFlag), DAT_007cf3c8, _DAT_008afea8, DAT_005bf9ac

**Calls:** FUN_00418ac0, FUN_00411840, FUN_00566650

**Moddability:** timer values, display duration

---

## FUN_00418b90 — Score/Threshold Gate Check

Source: score.cpp. Checks value at DAT_005bf9a0+param_1*0x14 against threshold depending on DAT_007d0308 (game state). Threshold: state 0→0x7ffffffe, state 1→0x45, state 2→0x27, state 3→0. Returns true if exceeded.

**Key logic:**
- Switch on DAT_007d0308 game state
- Each state has different threshold
- Used to gate scoring/disp logic

**Globals:** DAT_007d0308 (RaceActiveFlag), DAT_005bf9a0

---

## FUN_00418e50 — HUD/Display Data Reset

Source: hud.cpp. Resets 0x68 (104) entries of HUD data struct starting at param_1+0x350. Each entry stores: ID (-1), threshold (0x7fffffff), current value (0), display flag (-1.0f = 0xbf800000), timers (0). Clears byte flag array at +0x9dc.

**Key logic:**
- Only runs if DAT_007d0308 != 0 and timer condition met
- Iterates 0x68 times, stride 0x30? between entries
- Resets value, display state, min/max timers
- Calls FUN_00418ee0 after reset

**Globals:** DAT_007d0308 (RaceActiveFlag), DAT_007cf3c8

**Calls:** FUN_00418ee0

---

## FUN_0041a4a0 — Display Message 0x11c (Practice/Quali)

Source: hud_messages.cpp. Displays message ID 0x11c (practice or qualifying session message). Runs only when race active.

**Key logic:**
- Checks DAT_007d0308 and timer
- Calls FUN_004144f0 with message ID 0x11c
- Calls FUN_00418560 to queue display

**Calls:** FUN_004144f0, FUN_00418560

---

## FUN_0041a500 — Time-based Message Chain

Source: hud_messages.cpp. Time-based cascade of messages (IDs 0x22-0x117). Compares param_1 (delta time) against thresholds at _DAT_0059e80c through _DAT_0059e81c. Accumulates time in _DAT_008afe98.

**Key logic:**
- Returns if race inactive or timer not started
- Computes delta from _DAT_008afea0
- Nested threshold checks: 0x5c→0x16→0x14→0x15→0x22→0x23
- Calls vtable on DAT_005eb10c if non-null
- Calls FUN_004186a0 for cleanup before message

**Globals:** DAT_007d0308, DAT_007cf3c8, _DAT_008afea0, _DAT_008afe98, _DAT_0059e80c-0x5c (thresholds), DAT_005eb10c

**Calls:** FUN_004144d0, FUN_004144f0, FUN_00418560, FUN_004186a0

---

## FUN_0041a6b0 — Display Message 0x113

Source: hud_messages.cpp. Displays message ID 0x113. Clears via FUN_004186a0 before display.

**Key logic:**
- Checks race active
- Calls vtable cleanup on DAT_005eb10c
- Calls FUN_004186a0
- Displays message ID 0x113

**Globals:** DAT_007d0308, DAT_007cf3c8, DAT_005eb10c

**Calls:** FUN_004186a0, FUN_004144f0, FUN_00418560

---

## FUN_0041b200 — Display Message 0x4a

Source: hud_messages.cpp. Displays message ID 0x4a.

**Key logic:**
- Same pattern as FUN_0041a4a0 with message ID 0x4a

**Calls:** FUN_004144f0, FUN_00418560

---

## FUN_0041c090 — Display Message 0x202

Source: hud_messages.cpp. Displays message ID 0x202.

**Calls:** FUN_004144f0, FUN_00418560

---

## FUN_0041c3e0 — Display Message 0x151

Source: hud_messages.cpp. Displays message ID 0x151.

**Calls:** FUN_004144f0, FUN_00418560

---

## FUN_0041c4c0 — Position-based Message Display

Source: hud_messages.cpp. Displays message based on player position. Gets position index via FUN_004c2990, adjusts by +2, then computes message ID via thunk_FUN_004201e0. Supports two display formats: param_1=0 uses default flags, param_1≠0 uses alternate.

**Key logic:**
- Gets player's position index via FUN_004c2990
- Computes message ID from position
- Calls FUN_004144f0 with computed ID + position info
- param_1 controls display color/flags

**Calls:** FUN_004144d0, FUN_004c2990, thunk_FUN_004201e0, FUN_004144f0, FUN_00418560

---

## FUN_0041e320 — Scoring/Classification Display

Source: hud_scoring.cpp. Large scoring display function. Gets driver list (FUN_0041f340) and race results (FUN_0041f5d0). Shows classification messages based on session state (FUN_004c11d0 check). Handles 3-way positions: current, best, and gap.

**Key logic:**
- Returns if race inactive
- Gets session driver and result lists
- If FUN_004c11d0 == 1: displays current classification
- Checks +0xb144 state flag for session type (3=race)
- Compares name strings for driver identification
- Shows gap/interval messages
- Handles position change detection

**Calls:** FUN_004144d0, FUN_004c2850, FUN_004c11d0, FUN_0041f340, FUN_0041f5d0, FUN_00415550, FUN_004144f0, FUN_00418560, FUN_00420cf0

**Moddability:** message IDs in switch

---

## FUN_0041e920 — Best Lap/Entrant Finder

Source: hud_scoring.cpp. Iterates session entries to find best lap or matching entrant. Uses FUN_004c2850 array and FUN_004c1390/FUN_004c13a0 iterators. Compares at +0x198 (lap time or score). Filters by driver name if param_1 non-null.

**Key logic:**
- Validates session data via FUN_004c2850
- If param_1 non-null: matches driver name via FUN_00588410
- Iterates all drivers finding minimum at +0x198
- param_2 controls return behavior (pointer vs value)

**Calls:** FUN_004c2850, FUN_004c1390, FUN_004c13a0, FUN_004c1370, FUN_00588410

---

## FUN_0041eb30 — Scoring/Session Stats Aggregator

Source: hud_scoring.cpp. Aggregates scoring data across sessions. Accumulates values from FUN_0041ed20 into 26-slot array. First slot (index 0) is overall aggregate, slots 1-25 per-session.

**Key logic:**
- Iterates over session entries
- Sums values from FUN_0041ed20 into per-entry array
- If param_1 non-null: filters by matching name
- Returns combined aggregate + session count

**Calls:** FUN_004c2850, FUN_004c11d0, FUN_004c1370, FUN_004c1390, FUN_004c13a0, FUN_0041ed20, FUN_00588410

---

## FUN_00463f70 — Session Type Setter

Source: session.cpp. Sets DAT_007c56a0 (session type) based on +0x3fc4 flag. Flag 1 or 2 → session type 3 (race). Other → session type 2 (quali). Formats name strings from driver entry.

**Key logic:**
- Reads +0x3fc4 flag
- Flag 1 or 2: DAT_007c56a0=3, reads name from linked list
- Other: DAT_007c56a0=2
- Copies driver name strings to output buffers

**Globals:** DAT_007c56a0 (SessionType5), DAT_005ea438

**Moddability:** session type mapping

---

## FUN_004643c0 — Session Scoring Update

Source: scoring.cpp. Updates session scoring/standings. Reads time from _DAT_008afe98. Checks +0x3fc4 flag for session type. Calls FUN_00462370 for lap counting. Manages timer at +0x37c.

**Key logic:**
- Returns if +0x3fc4 == 0
- Accumulates delta time
- Sessions 1-2: checks lap count via FUN_00462370
- Manages countdown timer; triggers FUN_004a0d30 on expiry

**Globals:** _DAT_008afe98

**Calls:** FUN_00462370, FUN_0057a900, FUN_004a0d30, FUN_004a0db0, FUN_004a0490, FUN_00460cb0

---

## FUN_0046ad50 — Message/Name Buffer Update

Source: messaging.cpp. Updates message buffer DAT_005ec4cc with name from array. Reads entry via FUN_00455560 and FUN_00455260. Uses FUN_00423a00 for string lookup. Copies to output via FUN_004894d0.

**Key logic:**
- Reads two name strings via FUN_00455560 and FUN_00455260 (at DAT_007d1b08+index*7)
- Looks up in string table via FUN_00423a00
- Falls back to copying raw string
- Calls FUN_004894d0 to finalize

**Globals:** DAT_005ec4cc (MessageBuffer), DAT_007d1b08

**Calls:** FUN_00455560, FUN_00455260, FUN_00423a00, FUN_004894d0

---

## FUN_0046fe80 — Session Flag Pointer Selector

Source: session_flags.cpp. Initializes struct and selects session flag pointer based on param_2 (1-6). Maps: 1=ReconPitOpen, 2=ReconPitClosed, 3=PitTimerVisible, 4=FormationLap, 5=PitWindow, 6= other. Sets vtable.

**Globals:** DAT_007ceb64 (ReconPitOpen), DAT_007ceb7c (ReconPitClosed), DAT_007ceb94 (PitTimerVisible), DAT_007cebac, DAT_007cebc4 (FormationLap), DAT_007cebdc

**Calls:** FUN_0048fe60

---

## FUN_00476fc0 — Driver Name Copy from Global Array

Source: driver_name.cpp. Reads driver name from DAT_007d0d5c array at param_2 index. Copies to param_3 buffer (max param_4 chars). Appends tracked flag string from param_1+0x188.

**Globals:** DAT_007d0d5c

**Calls:** _strncpy

---

## FUN_00477280 — Object Name Comparison

Source: compare.cpp. Compares names of two objects at +0x9c→+0x34 offsets. Returns string comparison result.

---

## FUN_00478390 — Profile Icon Path Setter

Source: ui_profile.cpp. If param_1+0xe0 non-zero and season profile loaded (FUN_0048f590), sets global PTR_s_ProfileIcon_DFT_bmp_005c6658 to profile's icon path at +0x30.

**Calls:** FUN_0048f590

---

## FUN_0049c600 — Season Name Lookup

Source: season_name.cpp. Looks up season name from string table PTR_DAT_005ccbd0 using FUN_00423a00 and DAT_005ec4cc. Copies result to param_1 buffer (max param_2 chars).

**Globals:** DAT_005ec4cc (MessageBuffer), PTR_DAT_005ccbd0

**Calls:** FUN_00423a00, _strncpy

---

## FUN_0049c830 — Event/Round Name Lookup

Source: season_name.cpp. Same pattern as 0049c600 but uses PTR_DAT_005ccbdc for event/round name.

**Globals:** DAT_005ec4cc, PTR_DAT_005ccbdc

**Calls:** FUN_00423a00, _strncpy

---

## FUN_004a0630 — Session/Scene Init Chain

Source: session_init.cpp. Calls FUN_0042cf10 (session state). Initializes via FUN_004c2780/FUN_004c2810. Loads track via FUN_004c55b0 with DAT_007ce5ec track path. Calls vtable on DAT_005eb10c.

**Globals:** DAT_007ce5ec, DAT_005eb10c

**Calls:** FUN_0042cf10, FUN_004c2780, FUN_004c2810, FUN_004c55b0

---

## FUN_004a0690 — Scene Clear/Reset

Source: scene_reset.cpp. Resets scene state. Calls FUN_004c2810. Reloads track via FUN_004c55b0. Calls vtable on DAT_005eb10c. Calls FUN_004186a0 and FUN_004a09f0.

**Globals:** DAT_007ce5ec, DAT_005eb10c

**Calls:** FUN_004c2810, FUN_004c55b0, FUN_004186a0, FUN_004a09f0

---

## FUN_004c4aa0 — Vehicle Grid Selection

Source: grid_select.cpp. Selects vehicles for race grid. Iterates DAT_008ac390 vehicles. Filters by availability (FUN_004c4cb0). Selects up to param_3 vehicles. Uses FUN_00566810 for random selection.

**Globals:** DAT_008ac390 (VehicleFileCount), DAT_008ac394 (VehicleArray)

**Calls:** FUN_004c4cb0, FUN_00566810, operator_new

---

## FUN_004d8130 — Timer/Clock Format

Source: timer_format.cpp. Formats time/clock string. Selects format character from DAT_005d4a60 based on param_2 flag. Copies formatted time to output buffer.

**Globals:** DAT_005d4a60, DAT_005d4a61

---

## FUN_004d98a0 — Timer Countdown

Source: timer_count.cpp. Counts down timer at param_1+0x10. Checks against DAT_0059e440 threshold. Decrements by _DAT_008afe98 delta. Reads DAT_007c54e0 player vehicle.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr), _DAT_008afe98

---

## FUN_004d9dd0 — Timer Display Render

Source: timer_display.cpp. Renders timer display text. Calls FUN_004d98a0 countdown. Formats text via FUN_0058815f with DAT_005ccef0. Calls FUN_004d7e40 for rendering.

**Calls:** FUN_004d98a0, FUN_0058815f, FUN_004d7e40, FUN_00423a00

---

## FUN_004d9fe0 — Vehicle State Update

Source: vehicle_state.cpp. Updates vehicle state based on player vehicle flags at +0x40d0/+0x40d4. Sets state at param_1+0x18/+0x1c.

**Globals:** DAT_007c54e0 (PlayerVehiclePtr)

---

## FUN_004db6f0 — Position/Order Name Display

Source: hud_position.cpp. Formats position/order name for display. If param_1==-1: looks up from DAT_005ccec4 via FUN_00423a00. Otherwise formats with color (0xffff00 default).

**Globals:** DAT_005ec4cc (MessageBuffer), DAT_005ccec4

**Calls:** FUN_00423a00, FUN_004d7e40

---

## FUN_004da080 — Timer/Value Comparison

Source: timer_compare.cpp. Compares float at param_1+0x14 against DAT_0059e440 threshold. Reads value at param_1+0x1c.

---

## FUN_004c5070 — Random Vehicle Selector

Source: vehicle_random.cpp. Picks random vehicle index. Uses FUN_005871f0 for random value. Validates bounds against linked list count at +0x14.

**Calls:** FUN_005871f0, FUN_004c6760

---

## FUN_004a09a0 — Session Active Check

Source: session_check.cpp. Returns 1 if no session active. Checks FUN_004c2850 and FUN_004c29d0. Returns 0 if session data present.

**Calls:** FUN_004c2850, FUN_004c29d0

---

## FUN_0049d320 — Track/Position Name Formatter

Source: hud_names.cpp. Formats track position name. Reads value via FUN_0049b8f0. If negative: looks up from DAT_005ccec4. If zero: looks up from DAT_005c36fc. Copies result to param_1 (3 chars max).

**Globals:** DAT_005ec4cc (MessageBuffer), DAT_005ccec4, DAT_005c36fc

**Calls:** FUN_0049b8f0, FUN_00423a00, _strncpy

---

## FUN_0047f010 — Vehicle Name to Message Buffer

Source: vehicle_name.cpp. Reads vehicle name via FUN_00462e00. Looks up in string table via FUN_00423a00. Falls back to copying raw name. Calls FUN_00488b40 to dispatch message.

**Globals:** DAT_005ec4cc (MessageBuffer)

**Calls:** FUN_00462e00, FUN_00423a00, FUN_00488b40

---

## FUN_00476660 — Season Path Match Search

Source: season_search.cpp. Searches linked list at param_1[0x3c] for entry matching DAT_007d0434 (SeasonPath). Compares +0x3c field of each node. Stores matching index at param_1[0x5d]. Calls vtable at +0x98.

**Globals:** DAT_007d0434 (SeasonPath)

**Calls:** FUN_00588410

---

## FUN_00420490 — Position Change Detector

Source: hud_scoring.cpp. Detects driver position changes in race. Compares current position (+0x198) against stored position (+0x66). If position changed and param_1 set: displays position-change message with driver name and old/new positions.

**Key logic:**
- Gets current leader from session data
- Checks if session state = 1 (racing)
- Compares each driver's +0x198 (position) against +0x66 (stored)
- If changed: displays overtake/position change message
- Formats message with driver name and position numbers

**Calls:** FUN_004c2850, FUN_004c1390, FUN_004c13a0, FUN_004c1370, FUN_004144d0, FUN_004144f0, FUN_00418560

---






## FUN_00593e46
- Address: 0x00593e46
- Size: 809 bytes
- Lines: 165
- Category: Memory
- Algorithm/Purpose: Custom heap free/coalesce — frees a memory block by checking size class, coalescing adjacent free blocks, updating free lists (64 size classes × 2 for small/large), managing bitmap freelist presence flags. Uses VirtualFree for page-level deallocation when a full page becomes free.
- Game Logic: Memory allocator for dynamic game object allocation
- Complexity: Very high — custom freelist management, bitmaps, size-class bins, coalescing, VirtualFree for pages
## FUN_00594c12
- Address: 0x00594c12
- Size: 520 bytes
- Lines: 116
- Category: Memory
- Algorithm/Purpose: Custom heap allocator — first-fit allocation from page-aligned blocks with 0x1000-size suballocations, maintains free lists with sentinel values (0xffffffff, 0xf0, 0xf1), uses VirtualAlloc for new pages, tracks per-size-class free blocks via bitmaps, coalesces adjacent frees.
- Game Logic: Low-level game engine memory manager
- Complexity: Very high — custom free-list, VirtualAlloc integration, size-class bitmaps, block splitting
## FUN_00598e9e
- Address: 0x00598e9e
- Size: 310 bytes
- Lines: 75
- Category: System/IO
- Algorithm/Purpose: Buffered output character write with overflow handling — writes single character to output buffer, handles buffer full via flush/callback, supports both direct buffer and encoding/transform paths.
- Game Logic: Output stream write (console/file log)
- Complexity: Medium — buffer management, multi-path output, flush callbacks
## FUN_0059c1e7
- Address: 0x0059c1e7
- Size: 295 bytes
- Lines: 73
- Category: System/IO
- Algorithm/Purpose: Buffered character write — writes a single 16-bit character to an output buffer with overflow handling, buffer rewind, and error flag management. Tracks buffer state via flags (0x82, 0x40, 0x10) and falls back to flush/expand on full buffer.
- Game Logic: File/stream output character write
- Complexity: Medium — buffered I/O, state flags, buffer expansion path
## FUN_00589db0
- Address: 0x00589db0
- Size: 188 bytes
- Lines: 72
- Category: Strings
- Algorithm/Purpose: Optimized strlen/strchr with aligned word scan — uses 4-byte aligned reads with magic constants (0x7efefeff) to detect null bytes in parallel, tests 4 bytes at a time for target character match.
- Game Logic: String search — fast character lookup in text buffers
- Complexity: Medium — SIMD-style word-at-a-time scan, alignment handling
## FUN_0058cf35
- Address: 0x0058cf35
- Size: 280 bytes
- Lines: 71
- Category: System/IO
- Algorithm/Purpose: Buffered byte write — writes a single byte to output buffer with overflow handling, supports both global and local buffer contexts, handles reclaim/expand via callback, manages error state.
- Game Logic: File/stream output byte write
- Complexity: Medium — buffered I/O, state management, fallback flush
## FUN_00592647
- Address: 0x00592647
- Size: 320 bytes
- Lines: 70
- Category: System/Time
- Algorithm/Purpose: Date/time computation — calculates day-of-week from date using Zeller-like formula, handles month offsets via lookup tables (leap/non-leap), computes absolute timestamp in milliseconds with wraparound handling.
- Game Logic: Real-time clock / calendar computation
- Complexity: Medium — date math, leap year handling, weekday calculation, ms-of-day conversion
## FUN_005910b6
- Address: 0x005910b6
- Size: 518 bytes
- Lines: 58
- Category: Math
- Algorithm/Purpose: Extended-precision floating-point modulus — computes fmod for 80-bit x87 float format by repeated subtraction or division-based reduction, handles exponent normalization and sign preservation.
- Game Logic: Floating-point math — modulus for extended precision
- Complexity: High — 80-bit float format, exponent manipulation, conditional reduction
## FUN_00566810
- Address: 0x00566810
- Size: 149 bytes
- Lines: 57
- Category: Strings
- Algorithm/Purpose: Case-insensitive substring search with skip — searches for needle in haystack with case folding via character classification (upper/lower conversion), supports repeated matching.
- Game Logic: String search — case-insensitive pattern match
- Complexity: Medium — character conversion, backtracking search
## FUN_00594f3e
- Address: 0x00594f3e
- Size: 169 bytes
- Lines: 57
- Category: Memory
- Algorithm/Purpose: Custom heap resize — resizes an allocation in-place or by adjusting block boundaries, handles expansion into adjacent free space, updates size headers with sentinel values (0xf1).
- Game Logic: Custom heap — in-place reallocation
- Complexity: Medium — boundary checks, sentinel update, size adjustment
## FUN_0059a9ca
- Address: 0x0059a9ca
- Size: 206 bytes
- Lines: 56
- Category: Strings
- Algorithm/Purpose: String/buffer copy with reference counting — copies a substring with shared reference or deep copy depending on reference count threshold, handles ref-count increment on shared data.
- Game Logic: String/buffer shared copy (copy-on-write support)
- Complexity: Medium — ref-counted buffer, shared vs deep copy decision
## FUN_0058b4d4
- Address: 0x0058b4d4
- Size: 203 bytes
- Lines: 55
- Category: Strings/Encoding
- Algorithm/Purpose: Character uppercase conversion with locale/code-page support — converts single character to uppercase using lookup tables or LCMapString for locale-aware case mapping, handles MBCS lead-byte sequences.
- Game Logic: Text processing — locale-aware case folding
- Complexity: Medium — code-page dispatch, MBCS handling, API fallback
## FUN_005950a3
- Address: 0x005950a3
- Size: 146 bytes
- Lines: 54
- Category: System
- Algorithm/Purpose: MXCSR/FPU control word flag translation — converts x87 FPU exception masks and rounding control bits to equivalent MXCSR bits, translates precision control and rounding mode.
- Game Logic: Floating-point control — FPU->SSE status conversion
- Complexity: Low — bitfield translation mapping
## FUN_0059a221
- Address: 0x0059a221
- Size: 175 bytes
- Lines: 52
- Category: System/IO
- Algorithm/Purpose: Buffered read with fallback — reads from buffer with cursor tracking, falls back to read callback or error state, copies 6-field result to output.
- Game Logic: File/stream buffered input
- Complexity: Medium — buffer state, callback fallback, error handling
## FUN_0058fca0
- Address: 0x0058fca0
- Size: 7 bytes (mislabeled — actually 51 lines, 275 bytes)
- Lines: 51
- Category: Strings
- Algorithm/Purpose: Optimized strcpy with aligned copy — copies string source to destination using 4-byte aligned reads with null-byte detection via magic constant (0x7efefeff), handles unaligned source start.
- Game Logic: String copy — fast aligned memory copy
- Complexity: Medium — SIMD-style word-at-a-time copy, alignment handling
## FUN_00598569
- Address: 0x00598569
- Size: 151 bytes
- Lines: 44
- Category: Strings
- Algorithm/Purpose: String search for character with MBCS awareness — searches for a character in a string, handling multi-byte lead bytes via lookup table (DAT_008d47e0). Uses optimized aligned search or locale-aware loop.
- Game Logic: MBCS string character search
- Complexity: Medium — MBCS lead-byte detection, dual-path search
## FUN_00595924
- Address: 0x00595924
- Size: 124 bytes
- Lines: 40
- Category: System/IO
- Algorithm/Purpose: File handle table setter — sets a file handle in the global handle table with bounds and duplicate check, handles stdin/stdout/stderr via SetStdHandle, sets errno on error.
- Game Logic: File I/O — handle table management
- Complexity: Low — bounds check, handle table write, error reporting
## FUN_00596089
- Address: 0x00596089
- Size: 105 bytes
- Lines: 35
- Category: Strings/Encoding
- Algorithm/Purpose: Wide character to multi-byte conversion — converts single WCHAR to MBCS using WideCharToMultiByte, handles ASCII fast-path, sets errno on failure.
- Game Logic: Text encoding — wide to multi-byte conversion
- Complexity: Low — code-page dispatch, API call, errno reporting
## FUN_00596d81
- Address: 0x00596d81
- Size: 125 bytes
- Lines: 29
- Category: System
- Algorithm/Purpose: Environment variable value lookup — searches environment table for variable name matching via case-insensitive comparison, returns value pointer (after "=").
- Game Logic: Environment variable access
- Complexity: Low — string comparison, env table walk
## FUN_0058c9b4
- Address: 0x0058c9b4
- Size: 101 bytes
- Lines: 25
- Category: System/IO
- Algorithm/Purpose: File handle read wrapper — validates file handle ID in global table, locks/unlocks around read operation, returns error via errno.
- Game Logic: File I/O — handle-validating read
- Complexity: Low — handle table lookup, lock, read, unlock
## FUN_00596e0f
- Address: 0x00596e0f
- Size: 49 bytes
- Lines: 22
- Category: Strings/Encoding
- Algorithm/Purpose: Character type flag check — tests if character has given property flags via lookup table, with optional mask check for MBCS.
- Game Logic: Character classification utility
- Complexity: Low — bitmap lookup
## FUN_00589bc6
- Address: 0x00589bc6
- Size: 45 bytes
- Lines: 17
- Category: Strings/Encoding
- Algorithm/Purpose: Character hex-digit test — checks if character is a hex digit (0-9, A-F, a-f) via lookup table, supports both narrow and wide character sets.
- Game Logic: Character classification — hex digit test
- Complexity: Low — bitmap lookup
## FUN_00596007
- Address: 0x00596007
- Size: 41 bytes
- Lines: 14
- Category: System/IO
- Algorithm/Purpose: File handle open status check — checks if handle ID in global table has the open flag (0x40) set.
- Game Logic: File I/O — handle open status query
- Complexity: Low — bitmap lookup
# Worker 2 — Full Review Entries
## FUN_0058b130 @ 0x0058b130

**Size:** 664 bytes (306 lines)
**Category:** Memory — Copy
**Purpose:** Overlap-safe memory move (memmove) with alignment optimization
**Game Logic:** Generic buffer copy

Full source in: `decompiled_full\0x0058b130__FUN_0058b130.c`
## FUN_0058b5d4 @ 0x0058b5d4

**Size:** 781 bytes (201 lines)
**Category:** Memory — Realloc
**Purpose:** Memory reallocation with copy (realloc wrapper with SEH)
**Game Logic:** Dynamic buffer resizing

Full source: `decompiled_full\0x0058b5d4__FUN_0058b5d4.c`

---
## FUN_00594624 @ 0x00594624

**Size:** 758 bytes (175 lines)
**Category:** Utility — Encoding
**Purpose:** Base-N decode from string buffer with byte extraction
**Game Logic:** Data decoding for asset loading

Full source: `decompiled_full\0x00594624__FUN_00594624.c`

---
## FUN_00597aa0 @ 0x00597aa0

**Size:** 544 bytes (162 lines)
**Category:** Data — Bit Packing
**Purpose:** Bit-string to decimal unpack with addition
**Game Logic:** Packed data decompression

Full source: `decompiled_full\0x00597aa0__FUN_00597aa0.c`

---
## FUN_00562710 @ 0x00562710

**Size:** 284 bytes (128 lines)
**Category:** Utility — String
**Purpose:** String duplication with character replacement
**Game Logic:** Text processing

Full source: `decompiled_full\0x00562710__FUN_00562710.c`

---
## FUN_0055cc20 @ 0x0055cc20

**Size:** 453 bytes (124 lines)
**Category:** Entity — State
**Purpose:** Multi-field state sync via vtable callbacks
**Game Logic:** Entity property update

Full source: `decompiled_full\0x0055cc20__FUN_0055cc20.c`

---
## FUN_0055c650 @ 0x0055c650

**Size:** 342 bytes (116 lines)
**Category:** Entity — Flag
**Purpose:** Integer-to-ID mapping with switch dispatch
**Game Logic:** State/enum mapper

Full source: `decompiled_full\0x0055c650__FUN_0055c650.c`

---
## FUN_00587c20 @ 0x00587c20

**Size:** 133 bytes (110 lines)
**Category:** Utility — Hash
**Purpose:** String hash function with bit mixing
**Game Logic:** Name/string lookup hashing

Full source: `decompiled_full\0x00587c20__FUN_00587c20.c`

---
## FUN_0055d720 @ 0x0055d720

**Size:** 466 bytes (107 lines)
**Category:** Entity — State
**Purpose:** Parameter update with flag check + sub-calls
**Game Logic:** Entity state refresh

Full source: `decompiled_full\0x0055d720__FUN_0055d720.c`

---
## FUN_00591fa1 @ 0x00591fa1

**Size:** 511 bytes (104 lines)
**Category:** System — Encoding
**Purpose:** WideChar-to-MultiByte conversion with buffer management
**Game Logic:** String encoding conversion

Full source: `decompiled_full\0x00591fa1__FUN_00591fa1.c`

---
## FUN_00597093 @ 0x00597093

**Size:** 389 bytes (103 lines)
**Category:** System — IO
**Purpose:** File/directory attribute scanning with glob walk
**Game Logic:** Filesystem traversal

Full source: `decompiled_full\0x00597093__FUN_00597093.c`

---
## FUN_0058ad08 @ 0x0058ad08

**Size:** 353 bytes (101 lines)
**Category:** Utility — Format
**Purpose:** snprintf wrapper with va_list
**Game Logic:** String formatting

Full source: `decompiled_full\0x0058ad08__FUN_0058ad08.c`

---
## FUN_00562530 @ 0x00562530

**Size:** 209 bytes (97 lines)
**Category:** Data — Buffer
**Purpose:** Buffer byte-to-string decode with format
**Game Logic:** Data unpack

Full source: `decompiled_full\0x00562530__FUN_00562530.c`

---
## FUN_00553aa0 @ 0x00553aa0

**Size:** 549 bytes (92 lines)
**Category:** Data — Decode
**Purpose:** RGB color channel extraction with byte packing
**Game Logic:** Color data decode

Full source: `decompiled_full\0x00553aa0__FUN_00553aa0.c`

---
## FUN_005823c0 @ 0x005823c0

**Size:** 299 bytes (90 lines)
**Category:** Data — List
**Purpose:** Linked-list node insertion (sorted)
**Game Logic:** Ordered list insert

Full source: `decompiled_full\0x005823c0__FUN_005823c0.c`

---
## FUN_005542f0 @ 0x005542f0

**Size:** 439 bytes (88 lines)
**Category:** Entity — State
**Purpose:** Parameter setter with vtable notification
**Game Logic:** Entity property set

Full source: `decompiled_full\0x005542f0__FUN_005542f0.c`

---
## FUN_0055ca90 @ 0x0055ca90

**Size:** 386 bytes (87 lines)
**Category:** Entity — State
**Purpose:** State sync with vtable callbacks via flag checks
**Game Logic:** Entity parameter update

Full source: `decompiled_full\0x0055ca90__FUN_0055ca90.c`

---
## FUN_0058fb90 @ 0x0058fb90

**Size:** 129 bytes (81 lines)
**Category:** Library
**Purpose:** strcmp — string compare (aligned word scan)
**Game Logic:** MSVC CRT strcmp

Full source: `decompiled_full\0x0058fb90___strcmp.c`

---
## FUN_0059bcfc @ 0x0059bcfc

**Size:** 237 bytes (79 lines)
**Category:** Data — Bitmap
**Purpose:** Bitmap/allocator scan with bit operations
**Game Logic:** Free space search

Full source: `decompiled_full\0x0059bcfc__FUN_0059bcfc.c`

---
## FUN_0059249b @ 0x0059249b

**Size:** 428 bytes (77 lines)
**Category:** Entity — Logic
**Purpose:** Conditional dispatch with global flag check
**Game Logic:** Game state branch

Full source: `decompiled_full\0x0059249b__FUN_0059249b.c`

---
## FUN_0059797b @ 0x0059797b

**Size:** 293 bytes (76 lines)
**Category:** Data — Accessor
**Purpose:** Global data accessor with fallback allocation
**Game Logic:** Singleton data access

Full source: `decompiled_full\0x0059797b__FUN_0059797b.c`

---
## FUN_00588410 @ 0x00588410

**Size:** 208 bytes (74 lines)
**Category:** Utility — Compare
**Purpose:** Byte string compare (non-lib)
**Game Logic:** String equality check

Full source: `decompiled_full\0x00588410__FUN_00588410.c`

---
## FUN_00587730 @ 0x00587730

**Size:** 323 bytes (72 lines)
**Category:** Data — Search
**Purpose:** Linked-list node find by field match
**Game Logic:** List search

Full source: `decompiled_full\0x00587730__FUN_00587730.c`

---
## FUN_00566940 @ 0x00566940

**Size:** 293 bytes (71 lines)
**Category:** UI — Window
**Purpose:** Window/UI class registration or dialog setup
**Game Logic:** UI window create

Full source: `decompiled_full\0x00566940__FUN_00566940.c`

---
## FUN_00590703 @ 0x00590703

**Size:** 7 bytes (71 lines)
**Category:** Utility
**Purpose:** Stub/no-op function (trivial)
**Game Logic:** Placeholder

Full source: `decompiled_full\0x00590703__FUN_00590703.c`

---
## FUN_00585040 @ 0x00585040

**Size:** 236 bytes (70 lines)
**Category:** Data — List
**Purpose:** Linked-list node removal with cleanup callback
**Game Logic:** List teardown

Full source: `decompiled_full\0x00585040__FUN_00585040.c`

---
## FUN_0058a973 @ 0x0058a973

**Size:** 231 bytes (69 lines)
**Category:** System — Sync
**Purpose:** Semaphore-guarded operation with P/V wrappers
**Game Logic:** Thread-safe access

Full source: `decompiled_full\0x0058a973__FUN_0058a973.c`

---
## FUN_00567af0 @ 0x00567af0

**Size:** 5 bytes (68 lines)
**Category:** Thunk
**Purpose:** thunk to FUN_00567b10 (trampoline)
**Game Logic:** Jump table

Full source: `decompiled_full\0x00567af0__thunk_FUN_00567b10.c`

---
## FUN_0055d900 @ 0x0055d900

**Size:** 325 bytes (67 lines)
**Category:** Entity — State
**Purpose:** State update with short/int field operations
**Game Logic:** Entity state machine

Full source: `decompiled_full\0x0055d900__FUN_0055d900.c`

---
## FUN_0055be80 @ 0x0055be80

**Size:** 232 bytes (66 lines)
**Category:** Utility — String
**Purpose:** String copy with size tracking
**Game Logic:** String duplication

Full source: `decompiled_full\0x0055be80__FUN_0055be80.c`

---
## FUN_00588f8b @ 0x00588f8b

**Size:** 204 bytes (66 lines)
**Category:** Utility — Compare
**Purpose:** Path/filename string comparison
**Game Logic:** File path match

Full source: `decompiled_full\0x00588f8b__FUN_00588f8b.c`

---
## FUN_0059a103 @ 0x0059a103

**Size:** 286 bytes (65 lines)
**Category:** Entity — State
**Purpose:** Flag/state read with short result
**Game Logic:** State query

Full source: `decompiled_full\0x0059a103__FUN_0059a103.c`

---
## FUN_00597d3c @ 0x00597d3c

**Size:** 264 bytes (64 lines)
**Category:** System — Locale
**Purpose:** Locale info query (GetLocaleInfoW wrapper)
**Game Logic:** Regional settings

Full source: `decompiled_full\0x00597d3c__FUN_00597d3c.c`

---
## FUN_00581c20 @ 0x00581c20

**Size:** 278 bytes (63 lines)
**Category:** Data — List
**Purpose:** Linked-list destruction with vtable release call
**Game Logic:** List teardown

Full source: `decompiled_full\0x00581c20__FUN_00581c20.c`

---
## FUN_0058fc20 @ 0x0058fc20

**Size:** 62 bytes (62 lines)
**Category:** Utility — Compare
**Purpose:** Byte string compare with stack buffer
**Game Logic:** String compare utility

Full source: `decompiled_full\0x0058fc20__FUN_0058fc20.c`

---
## FUN_00588c7a @ 0x00588c7a

**Size:** 283 bytes (61 lines)
**Category:** Data — Accessor
**Purpose:** Pointer chain dereference with offset math
**Game Logic:** Struct field access

Full source: `decompiled_full\0x00588c7a__FUN_00588c7a.c`

---
## FUN_00588640 @ 0x00588640

**Size:** 62 bytes (56 lines)
**Category:** Library
**Purpose:** strncmp — bounded string compare (aligned)
**Game Logic:** MSVC CRT strncmp

Full source: `decompiled_full\0x00588640___strncmp.c`

---
## FUN_005506a0 @ 0x005506a0

**Size:** 118 bytes (55 lines)
**Category:** Memory — Array
**Purpose:** Array pointer cleanup loop
**Game Logic:** Pointer array teardown

Full source: `decompiled_full\0x005506a0__FUN_005506a0.c`

---
## FUN_0058c5ac @ 0x0058c5ac

**Size:** 62 bytes (55 lines)
**Category:** System — Sync
**Purpose:** Semaphore P operation (acquire)
**Game Logic:** Thread sync acquire

Full source: `decompiled_full\0x0058c5ac__FUN_0058c5ac.c`

---
## FUN_00565ca0 @ 0x00565ca0

**Size:** 62 bytes (54 lines)
**Category:** Memory — Free
**Purpose:** Conditional pointer free with flag check
**Game Logic:** Conditional dealloc

Full source: `decompiled_full\0x00565ca0__FUN_00565ca0.c`

---
## FUN_005593d0 @ 0x005593d0

**Size:** 218 bytes (53 lines)
**Category:** Memory — List
**Purpose:** Linked-list traversal + double-field cleanup
**Game Logic:** Multi-list teardown

Full source: `decompiled_full\0x005593d0__FUN_005593d0.c`

---
## FUN_00582ce0 @ 0x00582ce0

**Size:** 209 bytes (53 lines)
**Category:** Data — List
**Purpose:** SEH-wrapped linked-list destruction with vtable release
**Game Logic:** List teardown

Full source: `decompiled_full\0x00582ce0__FUN_00582ce0.c`

---
## FUN_00596773 @ 0x00596773

**Size:** 201 bytes (53 lines)
**Category:** System — Encoding
**Purpose:** WideChar string processing with fallback
**Game Logic:** String encoding/convert

Full source: `decompiled_full\0x00596773__FUN_00596773.c`

---
## FUN_005896ee @ 0x005896ee

**Size:** 220 bytes (52 lines)
**Category:** Memory — Array
**Purpose:** Pointer array loop-free
**Game Logic:** Array teardown

Full source: `decompiled_full\0x005896ee__FUN_005896ee.c`

---
## FUN_00562150 @ 0x00562150

**Size:** 349 bytes (51 lines)
**Category:** Utility — Encode
**Purpose:** Bit/byte encoding with shifting
**Game Logic:** Data encode/decode

Full source: `decompiled_full\0x00562150__FUN_00562150.c`

---
## FUN_00597621 @ 0x00597621

**Size:** 199 bytes (51 lines)
**Category:** Data — Format
**Purpose:** Buffer digits-to-struct conversion (BCD-like)
**Game Logic:** Number format conversion

Full source: `decompiled_full\0x00597621__FUN_00597621.c`

---
## FUN_00561d40 @ 0x00561d40

**Size:** 191 bytes (50 lines)
**Category:** Entity — Dispatch
**Purpose:** Multi-arg setter dispatch with vtable call
**Game Logic:** Property update

Full source: `decompiled_full\0x00561d40__FUN_00561d40.c`

---
## FUN_0058dad7 @ 0x0058dad7

**Size:** 140 bytes (50 lines)
**Category:** Library
**Purpose:** __trandisp2 — CRT internal dispatch helper
**Game Logic:** MSVC CRT

Full source: `decompiled_full\0x0058dad7____trandisp2.c`

---
## FUN_00592891 @ 0x00592891

**Size:** 147 bytes (47 lines)
**Category:** Utility — Check
**Purpose:** Error/overflow flag check with bit test
**Game Logic:** Validation check

Full source: `decompiled_full\0x00592891__FUN_00592891.c`

---
## FUN_00592a9c @ 0x00592a9c

**Size:** 88 bytes (43 lines)
**Category:** Data — Accessor
**Purpose:** Global data pointer accessor
**Game Logic:** Singleton data getter

Full source: `decompiled_full\0x00592a9c__FUN_00592a9c.c`

---
## FUN_00589cc6 @ 0x00589cc6

**Size:** 156 bytes (41 lines)
**Category:** System — Error
**Purpose:** Error/abort handler with TerminateProcess + cleanup callbacks
**Game Logic:** Fatal error handling

Full source: `decompiled_full\0x00589cc6__FUN_00589cc6.c`

---
## FUN_00559d80 @ 0x00559d80

**Size:** 153 bytes (38 lines)
**Category:** Utility — String
**Purpose:** String copy with field search + getter
**Game Logic:** String utility

Full source: `decompiled_full\0x00559d80__FUN_00559d80.c`

---
## FUN_00566a70 @ 0x00566a70

**Size:** 164 bytes (37 lines)
**Category:** UI — Window
**Purpose:** Window/control registration with buffer alloc
**Game Logic:** UI window class setup

Full source: `decompiled_full\0x00566a70__FUN_00566a70.c`

---
## FUN_0059c0ac @ 0x0059c0ac

**Size:** 123 bytes (35 lines)
**Category:** Utility — Bit
**Purpose:** Bit field extract/test from uint
**Game Logic:** Bit check utility

Full source: `decompiled_full\0x0059c0ac__FUN_0059c0ac.c`

---
## FUN_00596fed @ 0x00596fed

**Size:** 74 bytes (33 lines)
**Category:** Entity — State
**Purpose:** State/flag read from entity struct
**Game Logic:** Flag query

Full source: `decompiled_full\0x00596fed__FUN_00596fed.c`

---
## FUN_0058afe1 @ 0x0058afe1

**Size:** 100 bytes (30 lines)
**Category:** System — Error
**Purpose:** Error code setter
**Game Logic:** Error state set

Full source: `decompiled_full\0x0058afe1__FUN_0058afe1.c`

---
## FUN_0059045f @ 0x0059045f

**Size:** 98 bytes (28 lines)
**Category:** Utility — Lookup
**Purpose:** Character classification / symbol lookup
**Game Logic:** Char classification

Full source: `decompiled_full\0x0059045f__FUN_0059045f.c`

---
## FUN_0059706a @ 0x0059706a

**Size:** 41 bytes (26 lines)
**Category:** Data — Accessor
**Purpose:** Simple global data getter
**Game Logic:** Global data access

Full source: `decompiled_full\0x0059706a__FUN_0059706a.c`

---
## FUN_005901f0 @ 0x005901f0

**Size:** 86 bytes (25 lines)
**Category:** Utility — Stub
**Purpose:** Simple stub/no-op function
**Game Logic:** Placeholder

Full source: `decompiled_full\0x005901f0__FUN_005901f0.c`

---
## FUN_00588931 @ 0x00588931

**Size:** 9 bytes (23 lines)
**Category:** Library
**Purpose:** __NLG_Notify1 — CRT notification helper
**Game Logic:** MSVC CRT NLG

Full source: `decompiled_full\0x00588931____NLG_Notify1.c`

---
## FUN_0058893a @ 0x0058893a

**Size:** 24 bytes (17 lines)
**Category:** System — Context
**Purpose:** Global context save (stores EAX, EBP + data to globals)
**Game Logic:** Debug/error context capture

Full source: `decompiled_full\0x0058893a__FUN_0058893a.c`

---
## FUN_00589c1b @ 0x00589c1b

**Size:** 46 bytes (17 lines)
**Category:** Utility — Char
**Purpose:** Character classification via lookup table with version check
**Game Logic:** Char type check

Full source: `decompiled_full\0x00589c1b__FUN_00589c1b.c`

---
## FUN_0057aa50 @ 0x0057aa50

**Size:** 23 bytes (15 lines)
**Category:** Entity — State
**Purpose:** Global state flags clear (zero 4 fields)
**Game Logic:** State reset

Full source: `decompiled_full\0x0057aa50__FUN_0057aa50.c`

---
## FUN_00595a1f @ 0x00595a1f

**Size:** 66 bytes (21 lines)
**Category:** Data — Bitmap
**Purpose:** Indexed bitmap lookup with bit test
**Game Logic:** Resource/allocation check

Full source: `decompiled_full\0x00595a1f__FUN_00595a1f.c`

---
## FUN_00590303 @ 0x00590303

**Size:** 55 bytes (19 lines)
**Category:** System — Locale
**Purpose:** System locale check with locale enumeration
**Game Logic:** Locale detection

Full source: `decompiled_full\0x00590303__FUN_00590303.c`

---


# Worker 4 — Full Review Entries## FUN_004af3a0 — Car Setup Defaults Initialization

Source: likely setup.cpp or carparameters.cpp. Initializes suspension, aero, brake, diff tuning defaults for 4 difficulty presets.

**Key logic:**
- Switch on +0x3b40 (0=Easy, 1=Hard, 2=Expert?, 3=Custom?)
- Each case writes float constants to ~50 struct fields
- Inner loop 2×8 with stride 0x24 (36 bytes) sets per-wheel parameters
- Case 2/3 call FUN_004b20d0 (push preset) + FUN_004b1de0 (set value) for serialized param list
- Constants: spring rates ~11288, damping 0.12-0.9, ride height 0.025-0.175, wing angles 0.5-1.5

**Key float constants decoded:**
| Hex | Float | Use |
|-----|-------|-----|
| 0x3f000000 | 0.5 | default spring |
| 0x3dcccccd | 0.1 | bump damping |
| 0x4633b000 | 11288.0 | spring rate max |
| 0x3f800000 | 1.0 | neutral setting |
| 0x3fc00000 | 1.5 | wing angle max |

**Calls:** FUN_004646c0 (pair setter x2), FUN_0047f1f0 (single setter), FUN_004b20d0, FUN_004b1de0

**Moddability:** configurable (values are compile-time hardcoded per preset)

<!-- target: docs/19-renderer.md -->

## FUN_00410bc0 — Wheel Controller Input Decoder

Source: likely input.cpp or controller.cpp. Decodes packed controller bitfield data into per-wheel input values (steering, throttle, brake, clutch, gear).

**Key logic:**
- Reads packed input packet (param_2) — bit-packed 32-byte struct
- Extracts fields: short values shifted from packed bytes, scaled by _DAT_0059e780/77c/778/774 (conversion factors)
- Switch on uVar1 (1-6) mapping to input axes:
  - 1 → steering (+0x24 array)
  - 2 → throttle (+0x30)
  - 3 → brake (+0x3c)
  - 4 → buttons/d-pad (+0x48/0x4c, stride 0x24 per entry, 0x1a0 entries)
  - 5 → secondary buttons (+0x54/0x58, stride 0x24, 0xd0 entries)
  - 6 → analog axes (+0x60/0x64, stride 0x24, 0x340 entries)
- Accesses 2D lookup tables at DAT_005ecf0c/5ed3ac/5ed3f0/5ed434 with stride 0x1230
- Validates button index range per type before processing
- Routes decoded data via FUN_0040ef70

**Globals:**
- DAT_005ecf0c — steering input table
- DAT_005ed3ac — throttle input table
- DAT_005ed3f0 — brake input table
- DAT_005ed434 — analog axis table

**Calls:** FUN_0040e770 (controller button handler), FUN_004ed250 (force feedback?), FUN_0040ef70 (apply input)

**Moddability:** hookable

<!-- target: docs/19-renderer.md -->

## FUN_00462a10 — Championship Standings Re-ordering

Source: likely championship.cpp or standings.cpp. Re-orders driver/team entries by championship position, rebuilds index lookup table.

**Key logic:**
- Reads count from *param_1 + 0x3e14
- Iterates entries at stride 0x8c: reads value from +0x410 (driver index), +0x3c74+i*4 (score)
- Looks up DAT_005f0730[driver_index * 0x1230] for current position
- Creates linked list of (index, score, position) triples
- Calls FUN_004647d0 to sort the list by score
- Re-writes DAT_005f0730 with new position indices
- Stores count at *param_1 + 0x3fd9

**Globals:**
- DAT_005f0730 — driver/team index table (stride 0x1230)

**Calls:** FUN_00461530, FUN_004647d0, FUN_00587bcf

**Moddability:** hardcoded

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004b57f0 — Car Physics State Initializer

Source: likely carphysics.cpp or vehicle.cpp. Initializes a large vehicle physics state struct with defaults.

**Key logic:**
- Zeros most of 0x3e5+ dword fields (large ~4KB struct)
- Sets float constants: +0x35e = 0xfe967699 (gravity or factor)
- Sets config: +0x269 = 4 (tires), +0x26a = 2, +0x26b = 2
- Sets +0x3e3 = 5, +0x3e4 = 0x44610000 (900.0)
- Calls initialization functions: FUN_004ba820 x3, FUN_005668b0, FUN_004ff670, FUN_00568ba0
- Calls FUN_00568be0(1), FUN_00568c60 (enable physics?)
- Sets DAT_005acd24 at +0x3dd, flags at +0xf79/+0xf7a = 1

**Calls:** FUN_004ba820, FUN_004bb150, FUN_005668b0, FUN_004ff670, FUN_00568ba0, FUN_00568be0, FUN_00568c60

**Moddability:** configurable

<!-- target: docs/19-renderer.md -->

## FUN_0041eda0 — Championship Score / Leader Check

Source: likely championship.cpp or scoring.cpp. Determines if a specific player is leading the championship standings.

**Key logic:**
- Gets player count from FUN_004c1370
- For given param_1 (player index): searches player list via FUN_004c1390/13a0 to find matching index
- Accumulates scores across (iVar2 - 1) race rounds via FUN_0041ed20 (points per round)
- Scores in local_68[0] = total, local_68[i+1] = per-player
- Checks if local_68[local_70] (target player) >= all other entries
- Returns combined result

**Globals:** none

**Calls:** FUN_004c2850, FUN_004c11d0, FUN_004c1370, FUN_004c1390, FUN_004c13a0, FUN_0041ed20

**Moddability:** hardcoded

<!-- target: docs/20-math-utilities.md -->

## FUN_00412490 ? Game Control Mapping

Source: likely input.cpp. Maps game control ID to DirectInput scan code.

**Key logic:**
- param_2=0 (device 0), param_2=1 (device 1)
- param_3=1-0x18 maps to scan codes 0x106-0x151 (base)
- param_4 != 0: alternate mapping (base 0x113-0x13b)
- param_5 != 0: shift modifier adds 0x2e or 0x32
- Cases 0x17-0x18 special: 0x106 (ESC?), 0xec/0xed
- Stores result in param_1+8, calls FUN_00414180 for config validation

**Calls:** FUN_00414180 (config apply)

**Moddability:** configurable

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004b3400 ? Central Message/Event Dispatcher

Source: likely message.cpp. Routes bit-packed messages to vehicle subsystems.

**Key logic:**
- Switch on *param_1 >> 0x1d (8 major types: 0-6 used)
- Sub-type at >> 0x12 & 0x3f (6-bit sub-type)
- Index at & 0xff for vehicle/entity index (< 0x68 = 104 max)
- Routes to physics (FUN_00463d10), position (FUN_004fc700), sound (FUN_004c8de0), setup, collision
- Case 3, sub 6: random sound playback with rand() % 3 + 5
- Case 4, sub 7: builds vehicle-linked structure with 0x48c0 stride arrays
- Validates via DAT_005ef9a0[] per-entry state table (0=invalid, 1/2/3=valid)

**Globals:** DAT_005ef9a0 (entity state), DAT_005ec6d8 (vehicle array), DAT_007ce254, DAT_008ac4b0, DAT_008ab6e4, DAT_008acfe4, DAT_008afedc

**Calls:** 20+ dispatch targets (FUN_00463d10, FUN_00410bc0, FUN_004e2c70, etc.)

**Moddability:** hookable

<!-- target: docs/21-audio-network-internals.md -->

## FUN_00545d00 ? Bitfield Flag Propagation

Source: likely entity.cpp. Propagates bitfield flags through linked entity lists.

**Key logic:**
- Checks param_2 & param_3 bits at positions 5 (0x20), 11-12 (0x1800)
- Traverses 4 linked lists from offsets 0x1b4-0x1d0
- Stride 0x84 between entries, stride 0x10 for sub-entries
- Sets/clears bits at entry+0x9c
- Entry sub-type 8: clears 8 sub-entries at stride 0x10 with type check (=8)

**Moddability:** hardcoded

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00426430 â€” AI Waypoint Steering

Source: likely AIPath.cpp. Computes steering angles for AI vehicle to follow waypoint path.

**Key logic:**
- Gets current waypoint from `param_1[0x10d5]` and target zone from `param_1[0x1154]` (race line type)
- If no waypoint, calls `FUN_004038e0` (find nearest waypoint) â€” returns 0 if none found
- Checks distance from vehicle position (`param_1[0xd38]`, `param_1[0xd3a]`) to current waypoint; if beyond `_DAT_0059e8e0`, finds new waypoint
- Computes side-to-wayline dot product to check if vehicle crossed the waypoint plane
- If crossed: increments waypoint index `param_1[0x1116]`, finds next waypoint via `FUN_00403aa0`
- Copies 7 waypoint indices into `param_1[0x10d6]..[0x10dc]` (lookahead path)
- Toggles `param_1[0x1154]` (racing line variant) based on speed/lap context via `FUN_004a46f0`
- Computes `param_1[0x1111]` = `speed / targetSpeed` â€” normalized speed ratio, clamped to 1.0
- `param_1[0x1115]` = weighted combination of accumulated crossed waypoints and approach distance
- Sets `param_1[0x111a]` to 0â€“3 (braking zone level) based on speed-to-target thresholds (`_DAT_0059e8d8`, `_DAT_0059e468`, `_DAT_0059e8d4`)
- **Steering angle computation:**
  - Computes `param_1[0x110a]` = lateral deviation from waypoint path (signed error)
  - Calculates desired heading using sin/cos of current yaw (`param_1[0xd3c]`)
  - Adjusts aim point by steering gain `param_1[0x1111]` * curve from waypoint ahead
  - Projects onto 2D plane using waypoint forward vector and solves line intersection at `param_1[0x1105]/[0x1106]/[0x1107]`
  - Clamps steering by `param_1[0x114a]/[0x114b]` (lock-to-lock limits)
  - Applies yaw correction when heading error exceeds `_DAT_0059e890`

**Globals:**
- `_DAT_0059e8e0` â€” waypoint reacquire distance threshold
- `_DAT_0059e8dc` â€” max target speed clamp
- `_DAT_0059e43c` â€” 1.0f constant
- `_DAT_0059e8d8`, `_DAT_0059e468`, `_DAT_0059e8d4` â€” speed thresholds for braking zone levels (0/1/2/3)
- `_DAT_0059e868` â€” steering response gain
- `_DAT_0059e8d0` â€” steering deadband threshold
- `_DAT_0059e890` â€” yaw error tolerance (radians)
- `_DAT_0059e888` â€” 2Ï€ (360Â° in radians)
- `_DAT_0059e600` â€” speed threshold for full-lock steering
- `_DAT_008acfb4` â€” idle/reverse speed target
- `DAT_005ea3fc` â€” waypoint accumulation weight
- `_DAT_0059e468` â€” medium speed threshold

**Calls:** FUN_004038e0 (find nearest waypoint), FUN_00403aa0 (get waypoint chain), FUN_004a46f0 (toggle race line), FUN_004e8ce0 (drive speed calculation), FUN_00424cd0 (component event log)

**Moddability:** `configurable` â€” speed thresholds, steering gains, deadband

---

<!-- target: docs/19-renderer.md -->

## FUN_00454da0 â€” Vehicle Input Smoothing (Throttle/Brake/Clutch/Steering)

Source: controls.cpp. Applies analog smoothing, deadzone, and per-vehicle rate limits to driver input axes.

**Key logic:**
- Four independent channels: steering (0x241c), throttle (0x2410), brake (0x2414), clutch (0x2418)
- Each channel checks a mode flag at 0x1b20/0x1b4c/0x21d4 â€” if `== 2`, snap directly to target value (digital override)
- Otherwise: apply `globalRate * param_2 * dt` decay toward zero (increasing/decreasing each frame)
- Reverse gear flag at 0x1b70 modifies throttle decay multiplier (_DAT_0059e8a4)
- Steering: bidirectional with DAT_0059e478 boost at center, clamps to Â±1.0 (0xbf800000/0x3f800000)
- Gear display index at 0x2424: cascade of checks from 0x20f0â†’0x1fbc maps to 0â€“7 or -1 (reverse) or -2 (neutral)
- DAT_007d1370 neutral override: if -2 and flag set â†’ set to 0
- Clutch channel checks 0x1c54 mode, snap or decay

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| 0x1b20 | throttleInputMode | 2=digital, else analog |
| 0x1b44 | throttleLinkage | 0=normal |
| 0x1b48 | throttleTarget | raw input value |
| 0x1b70 | reverseGearFlag | modifies throttle decay |
| 0x1b4c | brakeInputMode | 2=digital |
| 0x1b74 | brakeTarget | |
| 0x21d4 | clutchInputMode | 2=digital |
| 0x21fc | clutchTarget | |
| 0x1b78 | steeringInputMode | |
| 0x1ba4 | steeringDigitalFlag | |
| 0x1bcc | steeringTarget | |
| 0x1b9c | steeringDir | 0=left, 1=right |
| 0x1bc8 | steeringOppositeDir | |
| 0x1ba0 | steeringAngle | |
| 0x2410 | outputThrottle | 0.0â€“1.0 |
| 0x2414 | outputBrake | 0.0â€“1.0 |
| 0x2418 | outputClutch | 0.0â€“1.0 |
| 0x241c | outputSteering | -1.0â€“1.0 |
| 0x2420 | outputHandbrake | 0.0â€“1.0 |
| 0x2424 | gearDisplayIndex | -2(neutral), -1(reverse), 0â€“7 |
| 0x2428 | gearNeedsUpdate | flag |

**Globals:**
- `_DAT_007d12c8` â€” throttle decay rate
- `_DAT_007d12ec` â€” brake/clutch decay rate
- `_DAT_007d12a4` â€” steering rate
- `_DAT_007d1310` â€” handbrake decay rate
- `_DAT_0059e5fc` â€” global frame-rate correction
- `_DAT_0059e478` â€” steering center boost
- `_DAT_0059e440` â€” zero threshold (â‰ˆ0.0)
- `_DAT_0059e43c` â€” one threshold (â‰ˆ1.0)
- `_DAT_0059e670` â€” negative one threshold (â‰ˆ-1.0)
- `_DAT_0059e8a4` â€” reverse gear throttle multiplier
- `DAT_007d1370` â€” neutral display override flag

**Calls:** none

**Moddability:** `configurable` â€” rates and thresholds are globals

---

<!-- target: docs/19-renderer.md -->

## FUN_00412e50 â€” DirectInput Scancode Mapping

Source: input.cpp. Maps logical action ID + shift state to DirectInput scancode.

**Key logic:**
- param_2 = 0 â†’ primary key table, param_2 = 1 â†’ secondary key table
- param_3 = 1..26 â†’ maps to DIK_* scancode range 0xF0â€“0x10A
- param_4 = shift modifier: when non-zero, shift mask (âˆ’0x1A for table 0, âˆ’0x18 for table 1) produces shifted scancode
- Calls FUN_00414180 to resolve key binding
- Writes scancode to param_1 + 8, binding result to param_1 + 0xC
- Returns 0xFFFFFFFF on invalid params, 1 on success

**Globals:** none

**Calls:**
- FUN_00414180 â€” resolve key binding

**Moddability:** `hardcoded`

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0044f150 â€” Force Feedback / Joystick Input Processing

Source: input.cpp or ff_joystick.cpp. Polls HID joystick state, detects button changes, and schedules force feedback effects.

**Key logic:**
- Initial check: param_1[1] (device ptr) non-null, DAT_005cd08d (FF enabled flag) set
- If *param_1 == 2 (keyboard mode): reads raw keyboard state via vtable +0x24, handles buffer-full retry
- If *param_1 != 2 (joystick mode): reads joystick state bytes from param_1+0x37c, left-shifts by 7 (centering), writes via vtable +0x28
- Builds button bitmask from state bytes at offsets 0x11, 0x91, 0x2c, 0x1e, 0x2a, 0x39 (0x80 = pressed)
- Iterates 256 button slots: checks per-axis threshold vs DAT_008afea8
- When threshold exceeded: toggles button state (0â†’3=press, 1â†’1=hold, 3â†’1=release), stores timestamp
- If button has FF flag (bit 2): calls FUN_00404f10 (check game state), conditionally appends event to output buffer at param_1+0xc88
- Toggle logic: button 0x2e (shift?) flips high bit of event IDs 0x10â€“0x32

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| param_1[0x321] | eventCount | number of FF events in buffer |
| param_1+0x37c | buttonStates | 256-byte button state array |
| param_1+0x27c | buttonTimers | per-button timer/counter |
| param_1+0xc88 | eventBuffer | FF event list (ushort per entry) |

**Globals:**
- `DAT_005cd08d` â€” force feedback enabled flag
- `DAT_008afea8` â€” axis threshold (float)
- `DAT_007c569c` â€” game state (5 = specific condition)
- `DAT_0059e440` â€” zero threshold
- `FUN_00404f10` â€” game state check

**Calls:**
- FUN_00404f10 â€” game state query

**Moddability:** `configurable` â€” threshold at DAT_008afea8

---

<!-- target: docs/19-renderer.md -->

## FUN_0044b110 â€” ConstraintValidator3Way

Source: unknown. Validates a 3-element constraint system, trying all permutations to find a valid configuration.

**Key logic:**
- Initializes local buffers via FUN_00448ee0, FUN_0044af20, FUN_0044b040
- Iterates 3 slots (0â€“2): for each, tests slot against two candidate values using FUN_0044b090
- If a slot passes, marks it valid (`local_84[uVar5] = 1`)
- After iterating all 3: if <2 slots valid, tries forced cross-check (swap candidates across slots)
- If all 3 pass cross-check, returns `local_88` (the valid slot index, 0â€“3)
- Returns 0 on failure

**Struct offsets (param_1):**
| Offset | Notes |
|--------|-------|
| base+0x10+idx*0x5c | Per-slot data block (0x5c stride) |
| *(param_1 + idx*4) â†’ +4+pos*8 | Candidate value table |

**Calls:** FUN_00448ee0, FUN_0044af20, FUN_0044af60, FUN_0044b040, FUN_0044b090 (validation check)

**Moddability:** hardcoded

---

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00516c7b â€” ControllerStateMachine

Source: controller_feedback.cpp. State machine managing player controller/force-feedback transitions.

**Key logic:**
- Calls `FUN_00516a1d` and `FUN_00516c0c` for init/sub-state update
- Stores state byte from `FUN_005169ac` at `iVar1 + 0x10`
- If `+0x4a` disabled or `unaff_ESI[0x10]` zero: resets all state flags to 0 and skips processing
- Main dispatch on `unaff_ESI[0x19]` (mode):
  - Mode 3: checks sub-state at `unaff_ESI[0x1d]`
    - sub-state 0: normal â†’ sets `+0x16` active flag, or `+0x5a` flag
    - sub-state non-zero: sets `+0x59` flag
  - Other modes: clears flags, sets `+0x16 = 1` (default active)
- When active (`+0x16`): calls `FUN_0051eb6e`, reads intensity from `unaff_ESI[0x69]`
- When `+0x5a`/`+0x59` set: calls `FUN_0051e0dc`, reads intensity
- When `+0x41` disabled and state `+0x10` zero: calls `FUN_0051cb6d` + `FUN_0051c3e2`; else `FUN_0051d166`
- If `+0xc9` disabled: dispatches `FUN_0051aec2` or `FUN_0051ba70` based on `unaff_ESI[0x32]`
- End of frame: sets up effect at `unaff_ESI[2]` with duration = `unaff_ESI[0x46] * (base * 3 + 2)`, type = 2 or 3

**Struct offsets (unaff_ESI â€” controller):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10 | activeFlag | Master enable |
| +0x14 | state | State ID (from FUN_005169ac) |
| +0x16 | active | Active flag for default behaviour |
| +0x19 | mode | Mode selector (3 = triggered) |
| +0x1d | subState | Sub-state for mode 3 |
| +0x32 | altMode | Alternative mode flag |
| +0x41 | processingFlag | Processing path selector |
| +0x46 | durationMultiplier | Scales effect duration |
| +0x4a | globalEnable | Master enable byte |
| +0x59 | flagRight | Right-side trigger flag |
| +0x5a | flagLeft | Left-side trigger flag |
| +0x69 | intensity | Effect intensity value |
| +0xc9 | extendedFlag | Extended processing flag |
| [2] | effectObj | Effect object pointer |

**Calls:** FUN_00516a1d, FUN_00516c0c, FUN_005169ac, FUN_0051eb6e, FUN_0051e0dc, FUN_0051cb6d, FUN_0051c3e2, FUN_0051d166, FUN_0051bf23, FUN_0051bc88, FUN_0051aec2, FUN_0051ba70, FUN_0051a4f2, FUN_005198b3

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00466650 â€” AccelerationDecelerationInterpolator

Source: interpolation.cpp. Smooth interpolation with acceleration/deceleration over time for UI/camera transitions.

**Key logic:**
- Guard: `param_1[0x3c]` must be non-zero
- Queries elapsed time via `FUN_00498730()` and `FUN_00498880()` for start/end positions
- Accumulates time in `param_1[0x43]`, clamped to max (0x40400000 = 3.0f)
- Calls `FUN_0054b530` to begin interpolation frame
- In `param_1[0x3d]` mode (instant snap):
  - Resets accumulator to 0
  - Computes velocity from position delta / time: `(target - current) / dt * DEG2RAD`
  - Moves toward target at computed speed with clamping
- In normal mode:
  - Computes acceleration component: `(1.0 - time_frac * tuning) * SQRT(speed^2) * accelFactor`
  - Applies deceleration when near target or time exceeded
  - Smooth easing: blends acceleration + time-based movement
- Vtable call `*param_1 + 0x2c` notifies update completion
- Stores output position at `param_1[0x45]` and last frame position at `[0x41]`/`[0x42]`

**Globals:**
- `_DAT_0059e43c` â€” 1.0 constant
- `_DAT_0059e440` â€” 0.0 constant
- `_DAT_0059e450` â€” degrees-to-radians
- `_DAT_0059e478` â€” max time threshold
- `_DAT_0059e8ec` â€” speed deadzone
- `_DAT_0059e98c` â€” acceleration tuning
- `_DAT_0059f204` â€” low-speed threshold
- `_DAT_0059f208` â€” acceleration factor
- `_DAT_0059f20c` â€” deceleration factor

**Struct offsets (param_1 â€” interpolator):**
| Offset | Field | Notes |
|--------|-------|-------|
| [0x3c] | enableFlag | Non-zero = active |
| [0x3d] | snapMode | Instant snap mode |
| [0x41] | lastPosX | Previous frame position X |
| [0x42] | lastPosY | Previous frame position Y |
| [0x43] | elapsedTime | Accumulated time |
| [0x44] | targetSpeed | Target velocity |
| [0x45] | currentOutput | Current interpolated position |

**Calls:** FUN_00498730 (time query), FUN_00498880 (frame position get), FUN_0054b530 (interpolation begin), FUN_0054b4d0 (interpolation end), SQRT

**Moddability:** configurable via globals

---

<!-- target: docs/21-audio-network-internals.md -->

## FUN_0045c0c0 â€” Directory Entry Enumerator with Parser Dispatch

Source: likely `FileSys` or `Loader` (called during resource scanning). Enumerates directory entries, classifies them, and inserts into a linked list for later loading.

**Key logic:**
- Opens directory with `FUN_00565f80(path, 1, extension, 1)` then `FUN_00565f50()` to begin iteration
- Loop: reads entries via `FUN_005662d0()` until exhausted
- Formats path string using `FUN_0058815f(local_200, &DAT_005be860, extension, iVar3)`
- Routes to parser based on param_4:
  - **1:** FUN_0045c400 â€” likely texture/image parser
  - **2:** FUN_0045c650 â€” likely model/geometry parser
  - **else:** FUN_00568a60 â€” generic parser via param_1 + 1 (type byte)
- On success: strips to last backslash to get filename, allocates 12-byte node (`operator_new(0xc)`)
- Node layout: `[0]=0, [4]=0xffffffff, [8]=parsed_data_ptr`
- Allocates second node with: `[0]=first_node_ptr, [4]=0, [8]=1` (flag=linked)
- Appends to doubly-linked list at param_1: `+4` (head), `+8` (tail), `+0xc` (entry for appends), `+0x10` (count)
- Continues until `FUN_00565f20()` returns false

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +1 | TypeByte | Parser type selector (when param_4 â‰  1,2) |
| +4 | ListHead | Linked list head pointer |
| +8 | ListTail | Linked list tail pointer (for append) |
| +0xc | LastAppended | Last appended node |
| +0x10 | Count | Number of entries in list |

**Globals:**
- `DAT_005be860` â€” format string for path construction

**Calls:** FUN_00565f80 (open dir), FUN_00565f50 (begin iter), FUN_005662d0 (read entry), FUN_0058815f (format path), FUN_0045c400 (parser type 1), FUN_0045c650 (parser type 2), FUN_00568a60 (generic parser), FUN_00565f20 (iteration check), FUN_00566650 (string copy)

**Moddability:** configurable (extension filter via param_3)

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053cfe0 â€” String-Keyed Registry with Extension Fallback

Source: resource/loader system. Looks up a string in a global linked-list registry, supporting dot-extension stripping for fallback matching.

**Key logic:**
- Reverses input string `param_2` into local_100 buffer
- Normalizes via `FUN_00589901` (lowercase/trim)
- Walks global linked list at `DAT_008b8e20`:
  - Each node: string at +0x14 (stored reversed), next pointer at +0x870
  - Byte-by-byte comparison of reversed strings
- On mismatch: strips trailing characters after last '.' (extension removal) and retries
- If no match: allocates 0x874-byte node via `operator_new(0x874)`, calls `FUN_005523e0()` to initialize, `FUN_00552470(param_2, param_3)` to create entry
  - On success: registers via `FUN_0053d340(id)`, stores id to `*param_1`
  - On failure: cleans up with `FUN_00557470()` + `FUN_00587bcf(id)`
- Returns: 0 = found/created, 0xffffffff = error

**Globals:**
- `DAT_008b8e20` â€” global linked list head (entry registry)

**Calls:** FUN_00589901 (string normalize), FUN_005523e0 (alloc init), FUN_00552470 (create entry), FUN_0053d340 (register entry), FUN_00557470 (unload), FUN_00587bcf (free)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a600 â€” Large Object Initializer

Source: game object factory. Initializes a large struct (~0x238 bytes) with defaults, sets type tag and scale to 1.0.

**Key logic:**
- Calls FUN_0053c2a0() and FUN_0053b130() â€” subsystem init/prep
- Sets `param_1 + 0x3c = 0`, `*param_1 = 0` (base fields zeroed)
- Sets `param_1 + 0x50 = 6` â€” type tag (likely vehicle/object type ID)
- Zeroes two 16-entry arrays at +0xd4 and +0x1a0 (0x40 bytes each = 16 Ã— 4)
- Sets XYZ scale at +0x194/0x198/0x19c to 1.0f (0x3f800000)
- Zeroes remaining position, velocity, and state fields across +0x20..+0x238

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | ActiveFlag | 0 = inactive |
| +0x3c | SomeFlag | 0 = init |
| +0x50 | TypeTag | 6 = vehicle/player object type |
| +0xd4 | ArrayA[16] | Zeroed 16-element int array |
| +0x1a0 | ArrayB[16] | Zeroed 16-element int array |
| +0x194..+0x19c | ScaleXYZ | 3 floats, all 1.0f (identity scale) |
| +0x20..+0x238 | Misc fields | Position, velocity, state â€” all zeroed |

**Calls:** FUN_0053c2a0, FUN_0053b130 (subsystem prep)

**Moddability:** hardcoded (init only â€” moddable at runtime via field access)

---

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004b5e50 â€” Hash Bucket List Manager

Source: F1Manager.cpp. Processes 64 hash buckets (offset +0x40, stride 0x10 = 4 pointers each). Removes entries matching key from collision chain, frees memory, re-adds to a separate linked list tracked at +0x10/+0x14/+0x18/+0x1c.

**Key logic:**
- `piVar6` walks 104 iterations (0x68) starting at `param_1 + 0x40`, stepping by 4
- Each bucket has: head pointer, tail pointer, current pointer, count
- Iterates each bucket's chain; removes nodes matching key `iVar1`
- If node has flag byte != 0 at offset +8: calls FUN_004b0170 then frees `*piVar3` (key resource)
- Frees node via FUN_00587bcf
- Allocates new 12-byte node via operator_new, links into list at param_1+0x10

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10 | List head | Output list head |
| +0x14 | List tail | Output list tail |
| +0x18 | List current | |
| +0x1c | List count | |
| +0x40 | Bucket array start | 64 entries Ã— 4 pointers Ã— 4 bytes = 0x400 bytes |

**Calls:** FUN_004b0170 (resource cleanup), FUN_004b4f70 (sync/lock), FUN_00587bcf (free), operator_new

**Moddability:** `hardcoded`

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00548890 â€” Binary Tree String Lookup

Source: F1Resource.cpp. Searches a binary tree of named nodes by UTF-16 string comparison.

**Key logic:**
- Converts `param_2` to lowercase via FUN_00589901
- Walks tree starting from `*(byte **)(param_1 + 0x24)` (root)
- At each node, checks flag at `+0x9c & 0x200`:
  - If NOT set: direct UTF-16 comparison (case-insensitive via lowercase conversion)
  - If set: copies node name to local buffer (strips trailing bytes), then compares
- Binary search direction via `iVar5`: `(1 - bVar8) - (bVar8 != 0)` â†’ -1 (left), 0 (match), 1 (right)
- Left/right child at offset +0xc0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24 | Tree root pointer | |

**Node struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | Name string bytes | UTF-16 |
| +0x9c | Flags | Bit 0x200 = compare mode |
| +0xc0 | Child pointer | Left/right based on comparison |

**Calls:** FUN_00589901 (string lowercase conversion)

**Moddability:** `hardcoded`

---

<!-- target: docs/21-audio-network-internals.md -->

## FUN_004b44e0 â€” Fixed-Block Memory Pool Init

Source: F1Memory.cpp. Initializes a fixed-block allocator with 32 blocks of 0x1b0 bytes each.

**Key logic:**
- Clears global pool state pointers: `DAT_008ab6f0`, `DAT_008ab6f4`, `_DAT_008ab6f8`, `_DAT_008ab6fc`, `DAT_008ab700`, `_DAT_008ab704`, `DAT_008ab708`, `DAT_008ab70c`
- Allocates root node (4 bytes) and main buffer (0x3600 bytes)
- Allocates sentinel node (12 bytes) for block list
- Walks main buffer in 0x1b0-byte steps (32 iterations), chains each block address into free list
- Two linked lists: block list (`DAT_008ab6f0` family) and free address list (`DAT_008ab700` family)

**Globals (pool state):**
| Address | Field | Notes |
|---------|-------|-------|
| `DAT_008ab6f0` | Active list head | Block allocation nodes |
| `DAT_008ab6f4` | Active list tail | |
| `_DAT_008ab6f8` | Active list current | |
| `_DAT_008ab6fc` | Active list count | |
| `DAT_008ab700` | Free list head | Address nodes |
| `_DAT_008ab704` | Free list current | |
| `DAT_008ab708` | Free list tail | |
| `DAT_008ab70c` | Free list count | |

**Calls:** operator_new (Ã—3 for root, buffer, sentinel; Ã—32 for block nodes)

**Moddability:** `hardcoded`

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ae750 � HUD/Display Frame Range Configuration

Source: Unknown. Sets up UI element/sprite frame ranges and display positions for three display modes.

**Key logic:**
- param_2: mode (1, 2, or 3) selecting display layout
- Each case sets ~10 paired values (start + end) at diff offsets across struct
- Mode 1: uses small offsets (0x1e=30, 0x2c=44, 0x34=52, 0x33=51, 0x38=56, 0xb8=184)
- Mode 2: uses small integers (1-13), likely animation frame indices
- Mode 3: uses 0x1e-0x2b range (30-43)
- Also sets ~20 additional paired values for all non-zero modes (offsets 0x10-0xd0 range)

**Moddability:** hardcoded

<!-- target: docs/08-file-formats.md -->

## FUN_0042eaa0 — AI Gear Selection Set

Source: race_session.cpp or ai_gearbox.cpp. Sets the current gear selection for an AI driver in a session segment, with clamping and dirty-flag propagation.

**Key logic:**
- Computes per-driver per-segment offset: `(driverIdx * 0xb + segment) * 0x40` — 11 segments per driver, each 64 bytes
- Reads old value at `segment_base + 0xc4` (int)
- Points `puVar1` to `segment_base + 0xb0` (a ratio/gear sub-struct)
- Clamps `param_4` (new gear):
  - If `param_4 < 1` → set to 0 (neutral)
  - If `param_4 < limit_at_+0x10` → set to param_4
  - Else → set to `limit_at_+0x10 - 1` (max gear)
- If flag at `param_1 + 0x19a5` is set (driver active), calls:
  - FUN_0042e530(driverIdx, segment) — sync/apply
  - Maps driverIdx (0,1,2) to segment type (0→1, 1→0, 2→2) via conditional chain
  - FUN_0042e470(current_sub, target_sub) — copy gear data
- Always calls FUN_0042e530(driverIdx, segment) — update
- If gear changed from old value: sets `param_1[0x19a4] = 1` and `*param_1 = 1` (dirty flags)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x19a4 | DirtyFlagSegment | byte, set on gear change |
| +0x19a5 | DriverActiveFlag | byte, enables sync |

**Calls:** FUN_0042e530 (gear sync/application), FUN_0042e470 (gear data copy between segments)

**Moddability:** `hardcoded` — gear clamping logic embedded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051c099 — Track Map Pixel Fill

Source: ui_trackmap.cpp or overlay_render.cpp. Fills track map pixel buffer rows with a repeating color byte, then optionally mirrors/duplicates rows.

**Key logic:**
- Reads source stride/byte width from `*(byte*)(iVar5 + 0x8c)` and row count from `*(byte*)(iVar5 + 0x96)`
- Loops `*(int*)(param_1 + 0x110)` times (number of columns/segments)
- For each column: fills memory region at `iVar3 + local_c*4` with repeating byte from `*puVar10`
  - Byte is replicated to fill 4-byte chunks (DWORD fill) then remaining bytes
  - Fill span is `iVar5 + 0x8c` bytes wide (color depth / stride)
  - Destination range: from `*(int*)(param_1 + 0x5c) + puVar4` up to `puVar8` (buffer boundary)
- If row_count > 1, calls FUN_0051593f to copy/mirror rows downward (vertical fill)
- Advances column index by row_count each iteration

**Calls:** FUN_0051593f (row copy/duplicate)

**Moddability:** `hookable` — pixel fill could be overridden for custom HUD

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042aeb0 — Driver Setup Param Lookup by ID

Source: race_setup.cpp (referenced by FUN_004bef60 which reads SeasonPoints +0x403c). Searches a 5-entry lookup table for a driver parameter ID and returns its value.

**Key logic:**
- Iterates over 5 entries at `param_1 + 0x4144` (stride 8: key + value pairs)
- Compares each entry's key (int) with param_2
- On match: returns value at `param_1 + 0x4148 + i*8`
- If no match found after 5 iterations: returns 0xFFFFFFFF (-1)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4144 | LookupKeys[5] | 5 int keys, stride 8 |
| +0x4148 | LookupValues[5] | 5 int values, stride 8 |

**Called by:** FUN_004bef60 (reads param_1 from vehicle +0x403c / SeasonPoints, docs/06)

**Moddability:** `hardcoded` — lookup is fixed-size 5 entries

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9100 — Tire Force / Slip Lookup with Table Interpolation

Source: vehicle_dynamics.cpp (physics model). Computes tire lateral/longitudinal force using table interpolation with two lookup branches based on a threshold comparison.

**Key logic:**
- Computes `param_2² * param_1[0x3a70] - (param_2² * param_3 + param_4[1]) * param_1[0x3514]` (base force term)
- Computes `fVar4 = ABS(param_2² * param_5 - param_4[0]) * param_1[0x3514]` (deviation term)
- Branches on `DAT_0059e440 <= fVar4` (nonzero test):
  - **High branch** (friction engaged): uses lookup table at param_1+0x3c7c with index clamped to [0, 13], interpolates between table entries
  - **Low branch** (near zero): uses lookup table at param_1+0x3c3c
- Computes interpolation fraction as fractional part of table index
- For the second lookup: computes SQRT of `fVar1² - fVar4²`, divides by fVar1, applies another table lookup at param_1+0x3bfc with interpolation
- Multiplies result by param_1[0x3518] (scaling factor)
- Clamps final result to param_1[0x3d3c] (max limit)
- Returns: `param_1[0x3d44] * param_1[0x3518] * param_2² + final_value + param_4[2]`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3514 | ForceScaleFactor | float, scales force terms |
| +0x3518 | OutputScaleFactor | float, multiplies final result |
| +0x3a70 | StiffnessTerm | float, base stiffness |
| +0x3bfc | TableIndexB | float[14], second lookup table |
| +0x3c00 | TableValueB | float[14], values for second table |
| +0x3c04 | TableValueB_Next | float[14], next entry for interpolation |
| +0x3c3c | SlipTableLow | float[14], low regime table |
| +0x3c40 | SlipTableLow_Val | float[14], low regime values |
| +0x3c44 | SlipTableLow_Next | float[14], low regime next values |
| +0x3c7c | SlipTableHigh | float[14], high regime table |
| +0x3c80 | SlipTableHigh_Val | float[14], high regime values |
| +0x3c84 | SlipTableHigh_Next | float[14], high regime next values |
| +0x3d3c | MaxClamp | float, output clamp upper bound |
| +0x3d44 | OutputBiasScale | float, bias term multiplier |

**Globals:**
- `DAT_0059e440` — ZeroThreshold (~0.0f, used as comparison epsilon)

**Calls:** FUN_005895a2 (math approximation function, docs/20)

**Moddability:** `hardcoded` — table-driven model with fixed table sizes

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b5be0 — TimeStep/Sampling Interval Set

Source: race_session.cpp. Sets a sampling interval or time-step parameter based on a mode selector (0-4).

**Key logic:**
- Stores param_2 to `param_1 + 0x9ac` (mode/type selector)
- Switch on param_2 (0-4), sets float at `param_1 + 0xf7c`:
  - 0 → 0.1666667 (1/6)
  - 1 → 0.125 (1/8)
  - 2 → 0.1 (1/10)
  - 3 → 0.08333334 (1/12)
  - 4 → 0.04166667 (1/24)
- Values suggest frame-rate fractions or physics step intervals (e.g., 1/6 = ~16.7ms, 1/24 = ~4.2ms)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9ac | SamplingMode | int, mode selector (0-4) |
| +0xf7c | SamplingInterval | float, time step value |

**Moddability:** `hookable` — interval values could be adjusted via hook

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a488 — Texture Decode: 32-bit RGB10A2 Format

Source: texture_decode.cpp (renderer). Decodes 32-bit per-pixel texture data in RGB10A2 format (10-bit R, 10-bit G, 10-bit B, 2-bit A) to float RGBA.

**Key logic:**
- Computes pixel offset: `param_1[0x1050] * param_2 + param_1[0x1054] * param_3 + param_1[0x18]` (row-major)
- Iterates for `param_1[0x1058]` pixels
- For each 32-bit pixel:
  - R = `(short)(pixel << 6) >> 6` (sign-extend 10 bits) × scale factor `_DAT_0059e4d8`
  - G = `(short)(pixel >> 10 << 6) >> 6` (extract bits 10-19, sign-extend) × scale factor
  - B = `(short)(pixel >> 20 << 6) >> 6` (extract bits 20-29, sign-extend) × scale factor
  - A = `(pixel >> 30) × _DAT_0059e98c` (2-bit alpha, 0-3 range)
- If `param_1[0x10] != 0`: calls FUN_00507845 for chroma key post-processing (zeros pixels matching key color)

**Globals:**
- `_DAT_0059e4d8` — Float scale factor for 10-bit channel decoding (~1/512 or similar)
- `_DAT_0059e98c` — Float scale factor for 2-bit alpha decoding (~1/3)

**Calls:** FUN_00507845 (chroma key / color-key zeroing post-process)

**Moddability:** `hardcoded` — format-specific decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_005098b7 — Texture Decode: 16-bit RGB565 Format

Source: texture_decode.cpp (renderer). Decodes 16-bit per-pixel texture data in RGB565 format (5-bit R, 6-bit G, 5-bit B) to float RGBA.

**Key logic:**
- Computes pixel offset same as FUN_0050a488 (row-major: `param_1[0x1050]*param_2 + param_1[0x1054]*param_3 + param_1[0x18]`)
- Iterates for `param_1[0x1058]` pixels
- For each 16-bit pixel:
  - R = `(pixel & 0x7c00) >> 10` (5 bits) × `_DAT_005accd4` (scale factor)
  - G = `(pixel & 0x3e0) >> 5` (6 bits) × scale factor
  - B = `(pixel & 0x1f)` (5 bits) × scale factor
  - A = 1.0 (fully opaque)
- Calls FUN_00507845 for chroma key post-processing if param_1[0x10] != 0

**Globals:**
- `_DAT_005accd4` — Float scale factor for 5/6-bit channel decoding

**Calls:** FUN_00507845 (chroma key post-process)

**Moddability:** `hardcoded` — format-specific decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509b8e — Texture Decode: 32-bit RG Luminance-Alpha Format

Source: texture_decode.cpp (renderer). Decodes 32-bit per-pixel texture in an RG/luminance format (two 16-bit channels) to float RGBA.

**Key logic:**
- Same row-major pixel offset computation
- Iterates for `param_1[0x1058]` pixels
- For each 32-bit pixel:
  - R = `(pixel & 0xFFFF)` (low 16 bits) × `_DAT_005ad290` (scale)
  - G = `*(ushort*)(pixel + 2)` (high 16 bits) × scale
  - B = 1.0
  - A = 1.0
- Calls FUN_00507845 for chroma key post-processing if param_1[0x10] != 0

**Globals:**
- `_DAT_005ad290` — Float scale factor for luminance decoding

**Calls:** FUN_00507845 (chroma key post-process)

**Moddability:** `hardcoded` — format-specific decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ce10 — Thunk to FUN_00587b3e

Thunk — delegates to FUN_00587b3e with address of LAB_0042ce20. No independent logic.

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508007 — Texture Encode: 8-bit DXT/S3TC Quantization

Source: texture_encode.cpp (renderer). Encodes float RGBA pixels to a packed 8-bit format with ordered dithering from 4x4 matrix.

**Key logic:**
- If param_1[0x1048] != 0: remaps param_4 via FUN_00506ce2 (palette/color table lookup)
- Gets dither matrix base at param_1[0x2c]
- Calls FUN_00507473() (dither init)
- For each pixel (count = param_1[0x1058]):
  - Dither offset from 4x4 matrix: indexed by `(param_2 & 3) + (param_3 & 3) * 8 + (uV7 & 3)`
  - Reads 3 float channels from param_4
  - Quantizes: `ROUND(channel * _DAT_0059e864 + dither)`
  - Packs into byte: bit operations with B<<3, G, R>>1
  - Alpha quantized with `_DAT_0059e478` scale

**Globals:**
- `_DAT_0059e864` — Quantization scale for color channels
- `_DAT_0059e478` — Quantization scale for alpha

**Calls:** FUN_00506ce2 (palette remap), FUN_00507473 (dither init)

**Moddability:** `hardcoded` — format-specific encoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509cc2 — Texture Decode: 8-bit Alpha-Only Format

Source: texture_decode.cpp (renderer). Decodes 8-bit per-pixel alpha-only texture to float RGBA.

**Key logic:**
- Row-major pixel offset (same pattern)
- Each byte: R=0, G=0, B=0, A=`byte * _DAT_0059e460`
- Calls FUN_00507845 if param_1[0x10] != 0

**Globals:**
- `_DAT_0059e460` — Alpha scale factor

**Calls:** FUN_00507845 (chroma key post-process)

**Moddability:** `hardcoded` — format-specific decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_00544af0 — Audio/Network Stream Cleanup

Source: audio_network_mixer.cpp. Cleans up audio/network stream objects: releases buffers, walks pending work lists.

**Key logic:**
- Checks flag bit 0x100000 at param_1+0xec
  - If active with buffer count > 0: calls FUN_005502c0 per buffer, FUN_005478b0, clears pointers, calls FUN_00541420, clears flag
- Frees globals DAT_008b8dbc, DAT_008b8dc0 via FUN_00542e50, FUN_00557470, FUN_00587bcf
- Walks linked list at param_1+0x100 (next +0x104, child +0xec, sibling +0x4c), calls FUN_00544e20
- Walks param_1+0x108 linked list calling FUN_00544e20
- Walks param_1+0x148 calling FUN_00557630
- Calls FUN_00540760()
- Returns 0 on success, -1 if busy

**Globals:**
- `DAT_008b8dbc` — Stream handle A
- `DAT_008b8dc0` — Stream handle B

**Calls:** FUN_005502c0, FUN_005478b0, FUN_00541420, FUN_00542e50, FUN_00557470, FUN_00587bcf, FUN_00544e20, FUN_00557630, FUN_00540760

**Moddability:** `hardcoded` — cleanup routine

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509047 — Texture Encode: 32-bit RGB10A2

Source: texture_encode.cpp. Encodes float RGBA to 32-bit RGB10A2 with ordered dithering.

**Key logic:**
- If param_1[0x1048] != 0: remaps via FUN_00506ce2
- Dither matrix at param_1[0x2c]
- Per pixel: quantizes 4 channels to 10-bit with dither, packs into 32-bit word
- Uses _DAT_005accb4 as quantization scale

**Globals:**
- `_DAT_005accb4` — Scale factor for RGB10A2 encoding

**Calls:** FUN_00506ce2 (palette remap), FUN_00507473 (dither init)

**Moddability:** `hardcoded` — format-specific encoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e4500 — Physics/Tire System Constructor

Source: vehicle_dynamics.cpp. Initializes tire/suspension physics subsystem.

**Key logic:**
- Calls FUN_004f6f20, FUN_004dfbb0, FUN_004a48c0 (init chain)
- Loops 4× FUN_004dfb90 (per-wheel init)
- Calls FUN_004f2430
- Sets param_1[0x32bc] = -1, param_1[0x39a4] = 0
- Calls FUN_004e4790 (timer init)
- Returns param_1

**Calls:** FUN_004f6f20, FUN_004dfbb0, FUN_004a48c0, FUN_004dfb90 (×4), FUN_004f2430, FUN_004e4790

**Moddability:** `hardcoded` — init sequence

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5600 — Pitstop State Transition

Source: pit_crew.cpp. Switches pit animation state with transition guards.

**Key logic:**
- Guard: return if param_2 null or same as current
- If old state exists:
  - Block if mode=3 AND repair done flag set
  - Block if mode=4
  - Save state type flag (`*oldState & 1`)
  - Call FUN_004a3440 (exit state)
- Set new state
- If old had type flag 1: FUN_004a3390(0) — re-entry
- Else: FUN_004a3440() — normal entry

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | CurrentPitState | byte*, current animation state |
| +0x184 | PitMode | int (3=repair) |
| +0x190 | RepairDoneFlag | byte, blocks transitions |

**Calls:** FUN_004a3440, FUN_004a3390, FUN_004b69f0

**Moddability:** `hookable` — pit state transitions

<!-- target: docs/06-session-race-logic.md -->

## FUN_005452f0 — Audio/Network Node Count

Source: audio_network_mixer.cpp. Counts nodes in two linked lists.

**Key logic:**
- Walks list at param_1+0x100: for each, walks inner list at +0xec, counts
- Walks list at param_1+0x108, counts
- Returns total

**Moddability:** `hardcoded` — utility counter

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b6940 — Pitstop Action Set

Source: pit_crew.cpp. Sets a pit action value, starts or continues crew.

**Key logic:**
- Calls FUN_004b7860(0) — reset timer
- If crew inactive: FUN_004b69a0() — start
- If active: reset counters, FUN_004b4e10() — continue
- Writes param_2 to indexed action slot

**Struct offsets:**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b0 | PitActionBase | int |
| +0x9b8 | PitActionIndex | int |
| +0x9bc | PitActionCounter | int |

**Calls:** FUN_004b7860, FUN_004b69f0, FUN_004b69a0, FUN_004b4e10

**Moddability:** `hookable` — pit action dispatch

<!-- target: docs/06-session-race-logic.md -->

## FUN_00544d30 — Audio/Network Tree Walker

Source: audio_network_mixer.cpp. Recursive tree walk checking children and siblings.

**Key logic:**
- If child at +0x44 and recursive call fails → return -1
- If no sibling at +0x4c OR skip flag:
  - Walk pending list at +0x204, check via FUN_0054c6c0 with mask
  - Return -1 if any check fails, else 0
- If sibling exists: recurse on sibling

**Calls:** FUN_0054c6c0, recursive self

**Moddability:** `hardcoded` — tree traversal

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051cdf9 — Virtual Dispatch Wrapper

Source: renderer dispatch. Calls virtual method on object, increments counters.

**Key logic:**
- Calls vtable+0xc on *(param_1+0x19c) with parameters
- Post-increments *param_6, *param_3

**Moddability:** `hardcoded` — dispatch wrapper

<!-- target: docs/06-session-race-logic.md -->

## FUN_004d6ae0 — Temperature/Energy Delta

Source: vehicle_thermal.cpp. Computes thermal delta formula.

**Key logic:**
- Returns `(param_1[0x118] + _DAT_0059eac8) * dt * _DAT_0059eb40 * param_1[0x40] + param_1[0x38]`

**Globals:**
- `_DAT_0059eac8` — Thermal constant
- `_DAT_0059eb40` — Scaling constant

**Moddability:** `hardcoded` — formula

<!-- target: docs/06-session-race-logic.md -->

## FUN_00548dd0 — Audio Node Iterator

Source: audio_network_mixer.cpp. Walks linked list calling process function on each node.

**Key logic:**
- List at param_1+0x170 (next +0x18)
- Calls FUN_00548c20(param_1, 0) per node

**Calls:** FUN_00548c20

**Moddability:** `hardcoded` — list iteration

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053c630 — Doubly-Linked List Unlink

Source: generic list utility. Unlinks node from doubly-linked list.

**Key logic:**
- If prev: prev.next = this.next
- If next: next.prev = this.prev
- If head pointer == this: head = next

**Globals:**
- `DAT_008b8f28` — List head

**Moddability:** `hardcoded` — standard list op

<!-- target: docs/06-session-race-logic.md -->

## FUN_00411120 — Session Structure Cleanup

Source: likely steward/steward.cpp. Frees/resets multiple session-related data arrays.

**Key logic:**
- Loops through 6 fields at param_1+0x24, 0x30, 0x3c, 0x48, 0x54, 0x60 (structure stride 0x24)
- Each field acts as a count of items to free via FUN_0040f300
- For field groups with stride 0x24: checks array indices against bounds 0x3a80/0x1d40/0x7500
- Skips free if specific validation flags are set (DAT_005ef9a0, DAT_005ecf0c checks)
- Final call to FUN_0040f300 with _DAT_008afea0 (current time) passed as float param

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x24 | Count1 | int, number of items (stride 0x24 group 1) |
| +0x30 | Count2 | int, number of items (stride 0x24 group 2) |
| +0x3c | Count3 | int, number of items (stride 0x24 group 3) |
| +0x48 | Count4 | int, number of items (stride 0x24 group 4) |
| +0x54 | Count5 | int, number of items (stride 0x24 group 5) |
| +0x60 | Count6 | int, number of items (stride 0x24 group 6) |

**Globals:**
- `_DAT_008afea0` — current session time (passed to FUN_0040f300)
- `DAT_005ef9a0` — array stride 0x1230, validation flags
- `DAT_005ecf0c` — array stride 0x1230, sub-element validation
- `DAT_005ed3ac` / `DAT_005ed3ec` / `DAT_005ed3f0` / `DAT_005ed430` — additional validation
- `DAT_005ed434` — array stride 0x1230, element-type qualification

**Calls:** FUN_0040f300 (free/release object, per docs/06)

**Moddability:** `hardcoded` — internal session cleanup logic


<!-- target: docs/06-session-race-logic.md -->

## FUN_0046ae60 — Session Entry List Cleanup

Source: likely race/race.cpp. Frees linked list of session entries and resets team scoring data.

**Key logic:**
- Calls FUN_00489cb0 (shared state cleanup)
- Traverses linked list at param_1+0x44, freeing each node
- For each node: if flag at node[2] != 0 and node[0] pointer valid, frees both node[0] and *node[0] via FUN_00587bcf
- Zeros out four fields at param_1+0x44 through 0x50
- Iterates from 0 to DAT_007d1424 (team count), calling per-team cleanup:
  - FUN_00455560 (get team by index)
  - FUN_00486f30 (release handle)
  - FUN_0046ad50 (reset entry)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x44 | ListHead | pointer, linked list of session entries |
| +0x48 | Count | zeroed after cleanup |
| +0x4c | Count | zeroed after cleanup |
| +0x50 | Count | zeroed after cleanup |

**Globals:**
- `DAT_007d1424` — number of teams/entries

**Calls:** FUN_00489cb0 (state cleanup), FUN_00587bcf (free memory), FUN_00455560 (get team by index), FUN_00486f30 (release handle), FUN_0046ad50 (reset entry)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0051db31 — Bitstream Texture Block Copy

Source: likely renderer/rasterizer.cpp. Copies decompressed pixel data into frame buffer using bit-shifted addressing.

**Key logic:**
- Computes line offset: `(param_2 >> 2) * 0x20 + 4` (width dimension)
- Computes block offset: `(param_3 >> 2) * 0x20 + 4` (height dimension)
- Calls FUN_0051d897 to allocate/init block, then FUN_0051da17 to decompress into buffers
- Copies data from byte buffer to framebuffer via short-based writes
- Nested loops: 4 rows × 8 columns of shorts = 32 shorts total (64 bytes)
- Each short is set to `*pbVar5 + 1` (pixel value = byte value + 1)

**Calls:** FUN_0051d897 (texture block allocation), FUN_0051da17 (data decompression)

**Moddability:** `hardcoded` — internal texture decompression pipeline


<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bfc0 — Audio Buffer Mixing

Source: likely audio/audio.cpp. Mixes audio samples with volume control.

**Key logic:**
- Checks if buffer position (param_1+0x110) <= current offset (iVar2+0x5c)
- If so, calls function pointer from iVar2+0x28 for each channel (param_1+0x20 channel count)
- Resets offset counter at iVar2+0x5c = 0
- Computes bytes to copy: min(uVar5, buffer_size, bytes_remaining)
- Copies data via indirect call at *(param_1+0x1a0)+4
- Tracks position and remaining bytes
- Increments buffer index when full buffer consumed

**Calls:** Indirect calls through vtable-style function pointers (param_1+0x1a0)

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051a968 — Audio Buffer Reset

Source: likely audio/audio.cpp. Resets audio buffer playback position.

**Key logic:**
- Reads buffer pointer at param_1+0x194, advances its playback position by *(iVar2+0x14)/8
- Resets advance counter at iVar2+0x14 to 0
- Calls function pointer from *(param_1+400)+8 (virtual method)
- If call returns true: zeros array at iVar2+0x20 (length from param_1+0x120)
- Sets iVar2+0x30 = param_1+0xfc (buffer end), sets byte at iVar2+0x18 = 0
- Returns modified flag

**Calls:** Virtual function through vtable at param_1+400

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_004e1fd0 — 3D Transform Point by Matrix and Translation

Source: likely renderer/transform.cpp. Transforms a 3D point by rotation matrix then adds translation.

**Key logic:**
- Performs 3×3 matrix-vector multiply: param_2[0..2] = M[3×3] at param_1+0x20 × vector at param_1+0x8e8
- Adds translation component (param_1+8, +0xc, +0x10) to result
- Copies rotation quaternion/axis from param_1+0x14,0x18,0x1c to param_3[0..2]

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | TransX | float, translation X |
| +0x0c | TransY | float, translation Y |
| +0x10 | TransZ | float, translation Z |
| +0x14 | RotQuatX | float, rotation quaternion X |
| +0x18 | RotQuatY | float, rotation quaternion Y |
| +0x1c | RotQuatZ | float, rotation quaternion Z |
| +0x20-0x40 | Rotation3×3 | float[3][3], rotation matrix |
| +0x8e8 | VecInX | float, input vector X |
| +0x8ec | VecInY | float, input vector Y |
| +0x8f0 | VecInZ | float, input vector Z |

**Moddability:** `hardcoded` — math utility


<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a5cb — 16-bit to Float Texture Decompress

Source: likely renderer/texture.cpp. Decodes 16-bit RGB (5-6-5) texture data to float RGBA.

**Key logic:**
- Reads pixel from `(width*y + x + base)` at param_1+0x1058 count
- Each 16-bit pixel: R=lower 16 bits from low word, G from upper 16 bits low byte, B from upper 16 bits high byte
- Converts to float using _DAT_005ad290 as multiplier
- Sets all 4 RGBA channels from single value then overwrites A with separate scaling
- Calls FUN_00507845 if param_1+0x10 != 0 (alpha correction)

**Globals:**
- `_DAT_005ad290` — float multiplier for 16-bit to float conversion

**Calls:** FUN_00507845 (alpha correction)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_00509959 — RGB 5-5-5-1 to Float Texture Decompress

Source: likely renderer/texture.cpp. Decodes 16-bit RGB 5-5-5-1 format to float RGBA.

**Key logic:**
- Iterates over pixel count at param_1+0x1058
- Each 16-bit pixel: R=(bits>>10)&0x1f, G=(bits>>5)&0x1f, B=bits&0x1f, A=bits>>15
- Multiplies color channels by _DAT_005accd4 (float scaling factor)
- Alpha is 0.0 or 1.0
- Calls FUN_00507845 if param_1+0x10 != 0

**Globals:**
- `_DAT_005accd4` — float multiplier for 5-bit to [0,1] conversion

**Calls:** FUN_00507845 (alpha correction)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_00509c20 — RGB 3-3-2 to Float Texture Decompress

Source: likely renderer/texture.cpp. Decodes 8-bit RGB 3-3-2 format to float RGBA.

**Key logic:**
- Iterates over pixel count at param_1+0x1058
- Each 8-bit pixel: R=bits>>5, G=(bits>>2)&7, B=bits&3, A=1.0
- R and G use _DAT_005ad210 as multiplier, B uses _DAT_0059e98c
- Calls FUN_00507845 if param_1+0x10 != 0

**Globals:**
- `_DAT_005ad210` — float multiplier for 3-bit channels
- `_DAT_0059e98c` — float multiplier for 2-bit blue channel

**Calls:** FUN_00507845 (alpha correction)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dbe0 — Thunk to FUN_0042e320

Thunk — delegates to FUN_0042e320 (session state handler). No additional logic.

<!-- target: docs/06-session-race-logic.md -->

## FUN_005081ae — 15-bit to 16-bit Texture Dithering

Source: likely renderer/texture.cpp. Dithering color space conversion with matrix transform.

**Key logic:**
- If param_1+0x1048 != 0, calls FUN_00506ce2 (pre-transform)
- Reads source from param_1+0x2c
- Calls FUN_00507473 (dither setup)
- Iterates pixel count at param_1+0x1058
- Computes color index from (param_3&3) + (param_2&3)*8 + (uVar9&3)
- Packs 4 color channels into 16-bit: R<<3 | G<<3 | B<<2 | A
- Uses ROUND with DAT_0059fec8, _DAT_0059e864, _DAT_0059e478 as coefficients

**Globals:**
- `DAT_0059fec8` — float multiplier for alpha channel
- `_DAT_0059e864` — float multiplier for R/G channels
- `_DAT_0059e478` — float multiplier for B channel

**Calls:** FUN_00506ce2 (color space transform), FUN_00507473 (dither init)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_00515ecd — Director/Camera Object Setup

Source: likely director/director.cpp. Initializes a director camera object with vtable entries.

**Key logic:**
- Allocates 0x18 bytes via virtual allocator at **(param_1+4)
- Stores allocation pointer at param_1+0x18c
- Sets byte at allocated+4 = 0, allocated+0x11 = 0
- Sets up vtable: allocated[0] = label, allocated[1] = FUN_00515e85, allocated[2] = FUN_00515db8, allocated[3] = label
- Sets byte at allocated+5 = 1 (active flag)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x18c | CameraObjPtr | pointer to allocated director camera |

**Calls:** Allocator through *(param_1+4) vtable

**Moddability:** `hardcooked` — internal setup


<!-- target: docs/06-session-race-logic.md -->

## FUN_00545250 — Actor Node Linked-List Append

Source: likely actor/actor.cpp. Appends an actor node to a doubly-linked list.

**Key logic:**
- Sets param_2+0x4c = 0, ORs 0x08 into param_2+0x3c flags
- Calls FUN_00544c50 (node init)
- If param_1+0x108 (list head) is null: sets head = param_2, param_2+0x48(null)=0
- Else: walks next pointers (+0x4c) to find tail, links param_2 after tail

**Struct offsets:**
| param_1+0x108 | ListHead | pointer, linked list head |

**Calls:** FUN_00544c50 (node initialization)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0050917d — Texture Color Space Transform (Dot3)

Source: likely renderer/texture.cpp. Texture color space conversion with 3-component dot product.

**Key logic:**
- If param_1+0x1048 != 0, calls FUN_00506ce2 (transform)
- Computes source index from (param_3&3)+(param_2&3)*8 + loop index
- Performs dot product: src + (r*d0 + g*d1 + b*d2) * _DAT_0059f120
- Packs result to 16-bit signed short via ROUND
- Uses _DAT_005adb18, _DAT_005adb1c, _DAT_005adb20 as dot-product coefficients

**Globals:**
- `_DAT_005adb18/1c/20` — dot-product coefficients
- `_DAT_0059f120` — intensity multiplier

**Calls:** FUN_00506ce2 (pre-transform), FUN_00507473 (dither init)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_004e87e0 — Brake Thermal Model (Temperature Clamp)

Source: likely hdvehicle/hdvehicle.cpp. Computes brake temperature clamping factor.

**Key logic:**
- Computes temp_derivative = pad_temp - (cooling_coeff × airspeed components)
- If current brake temp or caliper temp == 0, returns 0
- Calculates: `fVar2 = (deriv² × area × coeff / brake_temp - friction) / caliper_temp`
- Clamps fVar2 to ≥ 0 and ≤ 1.0 (_DAT_0059e43c)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3500 | PadTemp | float, brake pad temperature |
| +0x34b8 | CoolingCoeff1 | float, cooling coefficient |
| +0x3a58/5c/60 | AirSpeedComps | float[3], airflow velocity components |
| +0x39c8 | BrakeTemp | float, brake rotor temp |
| +0x39ac | CaliperTemp | float, caliper temp |
| +0x3d40/44 | Area/Coeff | float, brake area and coefficient |
| +0x39a8 | Friction | float, friction component |

**Globals:**
- `DAT_0059e440` — float 0.0 constant
- `_DAT_0059e43c` — float 1.0 constant

**Calls:** Called by FUN_00425920 (brake thermal update), FUN_00426cf0

**Moddability:** `hardcoded` — physics model

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5700 — Championship Score Threshold Search

Source: likely game/championship.cpp. Searches driver standings for score between current points and race lap threshold.

**Key logic:**
- Iterates up to 3 entries (indices 0-2) in param_1+0x59 array (stride 2)
- For each entry: checks if `*driver->SeasonPoints < entry_value < DAT_008acf8c`
- Returns matching entry value, or -1 if no match found

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x58 | ArrayLength | int, number of entries (max 3) |
| +0x59+idx*2 | ScoreThresholds | int[3], championship score thresholds |

**Globals:**
- `DAT_008acf8c` — total race laps (upper bound)

**Calls:** Called by championship scoring logic

**Moddability:** `hardcoded` — championship calculations


<!-- target: docs/06-session-race-logic.md -->

## FUN_005454d0 — Drawable Object Node Manager (Bucket Insert)

Source: likely renderer/scenegraph.cpp. Inserts a drawable node into scene bucket and manages allocation.

**Key logic:**
- param_3 selects bucket: 1→list at param_1+0x120/0x11c, 2→+0x130/0x12c, 4→+0x128/0x124, else uses param_2 directly
- If bucket head is null: sets head = param_2, param_2[0x1a] = 0
- Else: walks +0x6c next pointers to find tail, appends
- Increments count at *piVar3
- Sets param_2[0x1b] = 0
- Computes total = count1 + count2
- Frees old allocation array at param_1+0x138 via FUN_00587bcf
- Allocates new array: total * 0x38 + 4 via operator_new
- Initializes each element with FUN_0055d200()

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x120/0x11c | Bucket1 | list head / count |
| +0x130/0x12c | Bucket2 | list head / count |
| +0x128/0x124 | Bucket4 | list head / count |
| +0x60 | TotalCount | int, sum of bucket counts |
| +0x138 | AllocPtr | pointer to allocation array |
| +0x134 | AllocSize | int, allocation size |

**Calls:** FUN_00544c50 (node init), FUN_00587bcf (free), operator_new (malloc), FUN_0055d200 (element init), FUN_004b0170 (free iterator)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_004e5080 — Brake Cooling Post-Treatment

Source: likely hdvehicle/hdvehicle.cpp. Handles brake cooling decay after braking ends.

**Key logic:**
- Subtracts param_1+0x34a8 (cooling rate) from param_1+0x3a04 (brake timer)
- If timer < 0: copies param_1+0x3a08 (brake state) to param_1+0x39f0, returns
- If brake flag (param_1+0x39ec) set AND brake state == 1 (releasing):
  - Computes cooling velocity = ((speed - target) + _DAT_0059e828) * _DAT_0059e444
  - Clamps to [0.0, 1.0] range
- Otherwise falls through to FUN_0059dad5

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3a04 | BrakeTimer | float, counts down |
| +0x34a8 | CoolingRate | float, subtract per tick |
| +0x39f0 | OutputTimer | float, output |
| +0x3a08 | BrakeState | int, 1=releasing |
| +0x39ec | BrakeEnabled | byte, brake exists |
| +0x3570 | CoolingVelocity | float, clamped output |
| +0x3990 | CurrentSpeed | float |
| +0x3994 | TargetSpeed | float |

**Globals:**
- `_DAT_0059e828` — float 1.0 constant
- `_DAT_0059e444` — float 0.016667 (1/60, frame delta)
- `DAT_0059e440` — float 0.0 constant
- `_DAT_0059e43c` — float 1.0 constant

**Calls:** FUN_0059dad5 (default fallback)

**Moddability:** `hardcoded` — physics model


<!-- target: docs/06-session-race-logic.md -->

## FUN_00544db0 — Priority Queue Recursive Process

Source: likely actor/actor.cpp. Recursively processes a priority queue checking a processing function.

**Key logic:**
- Recursively descends into left child (param_1+0x44), returns -1 if any child returns non-zero
- If right child (param_1+0x4c) exists and param_2==0: recursively processes right child with param_2=1
- Walks linked list at param_1+0x204 calling FUN_0054ca00 on each node
- Returns 0xffffffff if any node's processing function returns non-zero, else 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x44 | LeftChild | pointer |
| +0x4c | RightChild | pointer |
| +0x204 | NodeList | linked list head |

**Calls:** FUN_0054ca00 (per-node processing check)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0052855a — Rendering Branch on DAT_005d79dc

Source: likely renderer/scene.cpp. Conditional rendering call based on global flag.

**Key logic:**
- If DAT_005d79dc == 0: calls FUN_0052a6ec with assembled parameters including *(param_1+0x11c)+0x80
- If DAT_005d79dc != 0: calls FUN_0052ab4e (alternate rendering path)

**Globals:**
- `DAT_005d79dc` — rendering mode flag (0 = standard, non-zero = alternate)

**Calls:** FUN_0052a6ec (standard render), FUN_0052ab4e (alternate render)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_004e38d0 — Timer Clamp and Process

Source: likely hdvehicle/hdvehicle.cpp. Clamps a multi-use timer value and processes.

**Key logic:**
- If param_1+0xba8 < 0: sets to 0
- Else if > 0xb: sets to 0xb (11)
- Calls FUN_004ded20 for each count (0 to clamped value)
- Resets param_1+0xba8 to 0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xba8 | TimerCount | int, clamped to [0,11] |

**Calls:** FUN_004ded20 (per-tick timer process)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a1b0 — Field Zero Initializer

Source: likely actor/actor.cpp. Zeros two fields on an actor/object.

**Key logic:**
- Sets *(param_1+0x1a8) = 0 (list/sibling pointer)
- Sets *(param_1+0x1a4) = 0 (child/last pointer)

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0053d3a0 — Doubly-Linked List Node Removal

Source: likely data structures. Removes a node from doubly-linked list.

**Key logic:**
- If prev (param_1+0x86c) exists: sets prev->next = this->next
- If next (param_1+0x870) exists: sets next->prev = this->prev
- If DAT_008b8e20 (list head) == this: sets head to this->next
- Zeros prev and next on this node

**Globals:**
- `DAT_008b8e20` — list head pointer

**Moddability:** `hardcoded`


<!-- target: docs/06-session-race-logic.md -->

## FUN_0041fc60 — SessionStateSearch

Searches game sessions/states for a specific condition (value == 10 at offset +0xd8).

**Key logic:**
- Two-phase search: first checks active session list via FUN_00566810/FUN_004c11d0
- Phase 1: iterates sessions looking for value 10 at offset +0xd8 per session entry (stride 4)
- Phase 2: if Phase 1 fails, iterates all sessions (via FUN_004c1370 count), for each session calls FUN_004c0a20 to prepare buffer, then checks its sub-sessions for value 10
- Returns 1 if match found, 0 otherwise
- Stack buffer of 0x50 bytes used as temporary key/token storage

**Calls:** FUN_004c2850 (memory/string operation), FUN_004c1390 (container iterator), FUN_004c0a20 (session query), FUN_00566810 (state check), FUN_004c11d0 (container count), FUN_004c1370 (master container count), FUN_004c13a0 (container get-by-index)

**Moddability:** hardcoded — searches for hardcoded value 10

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef180 — WheelContactTransform

Transforms wheel-relative contact positions into world/chassis coordinates for 4 wheels.

**Key logic:**
- Loop with stride 0x128 over 4 wheel entries (iVar4 = 0, 0x128, 0x250, 0x378)
- For each wheel: computes local contact position using 3-component dot products with wheel contact offsets (+0x82c, +0x830, +0x834) against chassis rotation matrix columns (+0x704–+0x724)
- Calls FUN_004ec020 on suspension state (-0x6ec relative to wheel data)
- Calls FUN_0044c550 with hardcoded floating-point constants (0.100..., 0.5, 2.0, 389000.0) — collision detection parameters
- On collision hit: stores contact normal and calls FUN_004ce110 to apply contact response

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x704 | ChassisRotCol0 | float[3], first column of chassis rotation matrix |
| +0x710 | ChassisRotCol1 | float[3], second column |
| +0x71c | ChassisRotCol2 | float[3], third column |
| +0x82c | WheelPosLocal | float[3], wheel local position per wheel (stride 0x128) |
| +0x3668 | ContactID | int per wheel (stride 0xf8) |

**Calls:** FUN_004ec020 (suspension/wheel processing), FUN_0044c550 (collision detection — SAT/GJK query), FUN_004ce110 (contact response application)

**Moddability:** hookable — vehicle dynamics

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042eb60 — ListSelectionClamp

Clamps selection index within a menu/list and triggers update.

**Key logic:**
- Computes entry offset as param_2 * 0x40
- Stores previous selection at +0xbc4 in local var
- Clamps param_3: if < 1 → 0; if >= max (+0xbc0) → max-1; else param_3
- Stores clamped value at offset +0xbc4
- Calls FUN_0042e530(4, param_2) to signal redraw
- If selection changed, sets dirty flags at offsets 0x19a4 and 0

**Calls:** FUN_0042e530 (UI redraw/update signal, type 4)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ecc0 — ReplayStateCopy

Copies replay/state buffer data for an instant replay slot.

**Key logic:**
- Calls FUN_0042de10(param_2) — state initialization or save
- Copies single value from +0x1978 to +0x1640 (replay frame index?)
- Copies 8 entries from +0x1970 to +0x1680 with stride 0x10 (car position/state array)
- 8 iterations correspond to max 8 cars in replay buffer

**Calls:** FUN_0042de10 (replay state preparation)

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051c2db — ImageResampleFilter

Applies weighted horizontal resampling filter on image rows.

**Key logic:**
- Outer loop over rows (count from param_1 + 0x110)
- Inner loop processes 2 columns per row with interpolation
- Reads 3 source pixel pointers: param_3[-1] (left), param_3[0] (center), param_3[1] (right) — 2-wide interpolation window
- Blending formula: output = (current*3 + neighbor*4 + 8) >> 4 — weighted average with rounding
- For each row: processes first pixel, then for each interior pixel alternates blend weights
- Final pixel per row uses different weight (3*curr + 4*curr + 7 >> 4)
- Output stride depends on param_2 + 0x28 (row width)

**Calls:** none

**Moddability:** hardcoded — image format utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e2130 — ChassisWorldTransform

Transforms a world-relative chassis position into world coordinates with rotation.

**Key logic:**
- Reads chassis rotation matrix from +0x20 to +0x40 (3x3 float matrix, column-major)
- Reads local vector from +0x918 to +0x920 (3 floats)
- Computes: world_pos = rotation * local_vector + chassis_position (+0x8 to +0x10)
- Copies orientation quaternion from +0x14 to param_3

**Struct offsets (param_1 — VehicleStruct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x08 | PositionX | float, world position |
| +0x14 | Orientation | float[4], quaternion (x, y, z, w) |
| +0x20 | RotMatrix | float[3][3], column-major rotation matrix |
| +0x918 | LocalOffset | float[3], local-space offset |

**Calls:** none

**Moddability:** hardcoded — vehicle physics utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a6e5 — TextureDecodeRGB16

Decodes 16-bit RGB texture data to floating-point RGBA values.

**Key logic:**
- Computes source pointer using param_1 + 0x1050 (stride), 0x1054 (rows), 0x18 (base offset)
- Iterates over pixel count at param_1 + 0x1058
- Each pixel: reads 16-bit value, extracts channels via shifts and masks
- Channel A: from __aullshr result (shift right)
- Channel R: (*puVar4 >> 0x10) & 0xffff → float * _DAT_005ad290
- Channel G: *puVar4 & 0xffff → float * _DAT_005ad290
- Channel B: *(ushort*)(puVar4+6) → float * _DAT_005ad290
- Stores 4 floats per pixel (RGBA)
- If param_1 + 0x10 != 0, calls FUN_00507845 for post-processing

**Globals:**
- `_DAT_005ad290` — color channel normalization factor

**Calls:** FUN_00507845 (texture post-process/convert)

**Moddability:** hardcoded — texture decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509a09 — TextureDecodeRGBA4

Decodes 4-bit-per-channel RGBA texture data to floating-point values.

**Key logic:**
- Computes source pointer using param_1 + 0x1050, 0x1054, 0x18
- Iterates over pixel count at param_1 + 0x1058
- Each pixel: reads bytes, extracts nibbles
- Channel R: (byte+1) & 0xf → float * _DAT_005ac108
- Channel G: (*byte >> 4) & 0xf → float * _DAT_005ac108
- Channel B: *byte & 0xf → float * _DAT_005ac108
- Channel A: *byte >> 12 → float * _DAT_005ac108
- All channels use same scale factor
- If param_1 + 0x10 != 0, calls FUN_00507845

**Globals:**
- `_DAT_005ac108` — color normalization factor

**Calls:** FUN_00507845 (texture post-process)

**Moddability:** hardcoded — texture decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042dbf0 — Thunk

Thunk — delegates to FUN_00587b3e with LAB_0042dc00. No entry needed.

<!-- target: docs/06-session-race-logic.md -->

## FUN_005083d2 — TextureColorConvert10

Converts 10-10-10-2 format color data with per-pixel lookup interpolation.

**Key logic:**
- If param_1 + 0x1048 != 0, transforms param_4 via FUN_00506ce2 (palette/table transform)
- Calls FUN_00507473 (lock/prepare resource)
- Main loop over pixel count (param_1 + 0x1058)
- Each pixel: reads 4 float color values from input + lookup table at +0x2c indexed by (param_3 & 3) + (param_2 & 3)*8 + (uVar9 & 3)
- Writes packed 10-10-10-2 RGBA: each channel ROUND(value * scale + bias), packed with <<10 shifts
- Scale factors from globals _DAT_0059e478 and _DAT_005adba0

**Globals:**
- `_DAT_0059e478` — alpha channel scale
- `_DAT_005adba0` — RGB channel scale

**Calls:** FUN_00506ce2 (palette/color transform), FUN_00507473 (resource lock)

**Moddability:** hardcoded — texture format conversion

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051cd53 — AudioSampleStream

Streams audio sample data through callback interface with double-buffered state.

**Key logic:**
- Manages audio playback state at param_1 + 0x19c: +0x20 (current sample), +0x24 (active flag), +0x2c (remaining count), +0x28 (buffer size)
- Mode 0 (inactive): caps transfer to min(2, remaining), reads 1-2 samples from input, calls render callback at +0xc
- Mode 1 (active): calls FUN_0051593f for bulk playback, clears active flag
- Advances source position (param_6) by processed count
- Decrements remaining sample count
- If mode 0: increments param_3 (frame counter)

**Calls:** FUN_0051593f (bulk audio sample copy/process)

**Moddability:** hookable — audio playback stream

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545340 — LinkedListNodeFinder

Finds Nth node in a hierarchical linked list structure.

**Key logic:**
- Starts with list head at param_1 + 0x100
- Walks children via +0xec link, siblings via +0x4c link
- If head is null, tries fallback list at param_1 + 0x108
- Iterates until node index matches param_2, then returns
- Traverses depth-first: processes child chain before moving to next sibling at +0x104

**Calls:** none

**Moddability:** hardcoded — container utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509244 — TextureColorGradient

Applies color gradient/blend using per-channel weighted multipliers.

**Key logic:**
- If param_1 + 0x1048 != 0, transforms param_4 via FUN_00506ce2
- Calls FUN_00507473 (lock resource)
- Main loop over pixel count (param_1 + 0x1058)
- Each pixel: reads 4 float input values, computes dot product: (c0 * _DAT_005adb18 + c1 * _DAT_005adb1c + c2 * _DAT_005adb20) * _DAT_0059f120
- Adds lookup table value at +0x2c indexed by (param_3 & 3) + (param_2 & 3)*8 + (uVar9 & 3)
- Rounds to short and writes 16-bit output

**Globals:**
- `_DAT_005adb18` — channel 0 blend weight
- `_DAT_005adb1c` — channel 1 blend weight
- `_DAT_005adb20` — channel 2 blend weight
- `_DAT_0059f120` — overall blend scale

**Calls:** FUN_00506ce2 (palette transform), FUN_00507473 (resource lock)

**Moddability:** hardcoded — texture color processing

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509d34 — TextureDecodeRGB565

Decodes RGB565 + alpha 8-bit texture data to floating-point RGBA.

**Key logic:**
- Source pointer computed from param_1 + 0x1050, 0x1054, 0x18 (base offset)
- Each pixel: 2 bytes; first byte contains 565 RGB, second byte is alpha
- Channel R: (*byte >> 5) * _DAT_005ad210 (bits 7-5)
- Channel G: (*byte >> 2 & 7) * _DAT_005ad210 (bits 4-2)
- Channel B: (*byte & 3) * _DAT_0059e98c (bits 1-0)
- Channel A: byte[1] * _DAT_0059e460
- Each channel has independent scale factor
- If param_1 + 0x10 != 0, calls FUN_00507845

**Globals:**
- `_DAT_005ad210` — R/G channel scale
- `_DAT_0059e98c` — B channel scale
- `_DAT_0059e460` — A channel scale

**Calls:** FUN_00507845 (texture post-process)

**Moddability:** hardcoded — texture decoder

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b1780 — InputClamp

Clamps input value to range [-1, 1] under active condition.

**Key logic:**
- Reads value at param_1 + 0x2988
- Calls FUN_00461dc0 to check if input processing is active
- If active: clamps value to [-1, 1] range, returns clamped value
- If inactive: returns value unchanged

**Calls:** FUN_00461dc0 (input activation check)

**Moddability:** hookable — input processing

<!-- target: docs/06-session-race-logic.md -->

## FUN_005455f0 — DoublyLinkedListRemove

Removes a node from a doubly-linked list based on type field.

**Key logic:**
- Reads type from param_2 & 7:
  - Type 1: list pointers at param_1 + 0x11c (head) and +0x120 (tail)
  - Type 2: list pointers at param_1 + 300 (head) and +0x130 (tail)
  - Type 4: list pointers at param_1 + 0x124 (head) and +0x128 (tail)
  - Other types: self-referencing (node is its own list)
- Updates linked list prev/next pointers to remove param_2 from chain
- If head == param_2, updates head to next
- Decrements list count at *puVar2

**Calls:** none

**Moddability:** hardcoded — container utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ef680 — RideHeightDelta

Computes ride height delta from suspension displacement values.

**Key logic:**
- Sets param_2[2] = param_1 + 0x74c (some state reference)
- Resets param_2[0] and param_2[1] to 0
- Computes: param_2[1] = ((suspension_front_diff) + (suspension_rear_diff)) * _DAT_0059e450
  - suspension_front_diff = value at +0x3590 - value at +0x3610
  - suspension_rear_diff = value at +0x3688 - value at +0x3708

**Globals:**
- `_DAT_0059e450` — ride height conversion factor

**Calls:** none

**Moddability:** hookable — vehicle suspension

<!-- target: docs/06-session-race-logic.md -->

## FUN_004bdb90 — AudioMixerChannelInit

Initializes audio mixer channel bank (65 channels).

**Key logic:**
- Calls FUN_004bd7d0 (mixer channel init) in a loop: 64 times (0x40) + 1 extra = 65 channels
- Zeroes 5 fields at offsets +0x924 to +0x934 (mixer state/accumulators)
- Returns param_1

**Calls:** FUN_004bd7d0 (single mixer channel init)

**Moddability:** hookable — audio mixer

<!-- target: docs/06-session-race-logic.md -->

## FUN_005285a6 — RenderModeBranch

Branches rendering path based on vsync/page-flip mode.

**Key logic:**
- Checks global DAT_005d79dc (page-flip / vsync mode flag)
- If 0: calls FUN_0052b206 with rendering parameters (position, width at param_2+0x50 + param_1+0x11c + 0x80)
- If non-zero: calls FUN_0052b561 (alternative render path — likely page-flip)

**Globals:**
- `DAT_005d79dc` — page-flip / vsync mode selector

**Calls:** FUN_0052b206 (render surface blit), FUN_0052b561 (page-flip render)

**Moddability:** hardcoded — display mode

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e8780 — SuspensionRatioClamp

Computes clamped force/velocity ratio for suspension damper.

**Key logic:**
- If denominator (+0x39ac) == 1.0f: returns 1.0f (no division needed)
- Otherwise: result = -(numerator +0x39a8 / denominator +0x39ac)
- Clamps result to [1.0f, _DAT_0059e43c] range
- Used for shock absorber velocity ratio calculation

**Globals:**
- `_DAT_0059e43c` — upper clamp bound for suspension ratio
- `_DAT_0059e440` — constant 1.0f

**Calls:** none

**Moddability:** configurable — suspension ratio bounds

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c150 — FlagPropertyGetter

Returns property value based on bit flag match.

**Key logic:**
- Checks if param_3 & 0x800 matches flag at param_1 + 0x3c & 0x800
- If match: returns value at param_1 + 0x234
- Checks if param_3 & 0x1000 matches flag at param_1 + 0x3c & 0x1000
- If match: returns value at param_1 + 0x238
- Otherwise: param_2 unchanged

**Calls:** none

**Moddability:** hookable — property system

<!-- target: docs/06-session-race-logic.md -->

## FUN_0053d930 — StateIntSetter4

Conditional setter for 4 integer state fields with guard.

**Key logic:**
- Sets param_1 + 0x1508 = param_2, only if param_2 >= 0
- Sets param_1 + 0x150c = param_3, only if param_3 >= 0
- Sets param_1 + 0x1510 = param_4, only if param_4 >= 0
- Sets param_1 + 0x1514 = param_5, only if param_5 >= 0
- Negative values leave field unchanged (sentinel for "don't update")

**Calls:** none

**Moddability:** hookable — state management

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9a00 — PackedFlagRead

Extracts packed flag from audio/mixer state word.

**Key logic:**
- Reads byte at *param_1 + 0xf81 (subsystem index/type)
- Combines with bits from *param_1 >> 8
- Returns CONCAT31 — 4-byte value with marker

**Calls:** none

**Moddability:** hardcoded — mixer state read

<!-- target: docs/18-physics-dynamics.md -->

## FUN_00411bf0 — Race Event Message Dispatcher

Source: Unknown (UI/text module). Dispatches race event text/message rendering based on event type code.

**Key logic:**
- Generates random boolean via `_rand() & 1` for contextual variation
- Reads event type from `*(param_2 + 0xc)` (4-byte integer)
- Switch on event type (values 3–0x37) dispatches to specialized rendering functions:
  - Cases 3,5,6,9,10,0xd,0x13,0x16–0x18,0x26,0x29,0x2d,0x30,0x32,0x35–0x37 → FUN_004122c0 with random flag
  - Cases 8,0xf,0x21 → FUN_00412490 (flag=0)
  - Cases 0xb,0xc,0x33 → FUN_00412e50
  - Cases 0x11,0x1f,0x20,0x2a,0x2b,0x34 → FUN_004122c0 (flag=0)
  - Cases 0x12,0x19–0x1b,0x1d,0x1e,0x2e → FUN_004133b0
  - Cases 0x15,0x1c → FUN_004122c0 (flag=1)
  - Cases 0x27,0x28 → FUN_00413710
  - Case 0x31 → FUN_00412c30
  - Default → returns 0 (unhandled event)
- Each dispatched function receives param_4, param_1, and text param from `*(param_3 + 0x10)`

**Globals:** None directly.

**Calls:** FUN_004122c0 (text/UI rendering), FUN_00412490 (text/UI rendering), FUN_00412e50 (text/UI rendering), FUN_004133b0 (text/UI rendering), FUN_00413710 (text/UI rendering), FUN_00412c30 (text/UI rendering)

**Moddability:** `hardcoded` — event types are hardcoded switch cases

<!-- target: docs/06-session-race-logic.md -->

## FUN_00432650 — String Capitalizer (Name Case)

Source: Unknown string utility. Capitalizes first letter of each word in a string, lowercases others.

**Key logic:**
- First character: if lowercase (`'a'`–`'z'`), uppercases it (`-0x20`)
- Iterates through string until null terminator
- If current char is alphabetic (A-Z or a-z) and next char is lowercase → uppercases next char
- If current char is NOT alphabetic and next char is lowercase → uppercases next char
- If current char is alphabetic and next char is uppercase → lowercases next char (`+0x20`)
- Result: proper name/title casing ("dRiVeR nAmE" → "Driver Name")

**Struct offsets:** None.

**Globals:** None.

**Calls:** None.

**Moddability:** `hardcoded` — pure utility, no config

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed810 — Wheel/Tire Force Update (4-Wheel Loop)

Source: vehicle physics module. Updates tire lateral/longitudinal forces for all 4 wheels with damping and saturation clamping.

**Key logic:**
- Reads reference delta from `_DAT_008afef0 + _DAT_005acafc`
- For each of 4 wheels (loop count = 4):
  - Computes forced response combining ABS(steering/roll influence) × coefficient factors
  - Applies delta to previous value scaled by timestep `param_2`
  - Stores result at primary offset and duplicate offset (likely left/right wheel sync)
  - After update, clamps value via:
    - `fVar1 = (value - DAT_0059eec8) * DAT_0059eec0` (normalize)
    - Clamp to `[DAT_0059e440, _DAT_0059e43c]` range
    - Stores clamped result at secondary offset (possibly to output/display value)
  - Advances pfVar4 (+0x3e floats = 0xF8 bytes per wheel) and pfVar3 (+0x4a floats = 0x128 bytes per wheel)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x35dc | WheelForcePrev[4] | float, previous force value per wheel |
| +0x36d4 | WheelForceCopy[4] | float, duplicate storage |
| +0x37cc | WheelForcePrev2[4] | float, secondary axis force |
| +0x38c4 | WheelForceCopy2[4] | float, duplicate for secondary |
| +0x3500 | SteeringInfluence | float, ABS'd for force calc |
| +0x35b0 | LateralForce1 | float, per-wheel |
| +0x36a8 | LateralForce2 | float, per-wheel |
| +0x37a0 | LateralForce3 | float, per-wheel |
| +0x3898 | LateralForce4 | float, per-wheel |
| +0x3a38–0x3a54 | TuningCoeffs | float, force multipliers per wheel |
| +0x35d8, +0x36d0, +0x37c8, +0x38c0 | WheelCoeffs | float, per-wheel coefficients |
| +0x3a3c–0x3a50 | DampingCoeffs | float, damping factors |
| +0x8cc | ClampedOutput[4] | float, final clamped force output |

**Globals:**
- `_DAT_008afef0` — global force/torque reference
- `_DAT_005acafc` — additive offset
- `_DAT_0059e450` — global force scaling multiplier
- `_DAT_0059eec8` — normalization bias
- `_DAT_0059eec0` — normalization scale
- `DAT_0059e440` — clamp lower bound
- `_DAT_0059e43c` — clamp upper bound

**Calls:** None (inline math only)

**Moddability:** `hardcoded` — coefficients accessed from struct but source unknown

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9300 — Tire Grip/Lateral Force Calculation

Source: vehicle dynamics / tire model. Computes tire lateral force based on slip angle, load, and grip parameters, with lookup table interpolation.

**Key logic:**
- Inputs: param_2 (slip angle), param_3 (load), param_4[0..2] (grip params), param_5 (inflation/slip factor)
- Computes `fVar3 = slip^2`, then lateral force potential `fVar4 = fVar3 * C_spring - (fVar3 * load + grip[1]) * C_damping`
- Computes `fVar5 = ABS(slip^2 * param_5 - grip[0]) * C_damping` (magnitude of force)
- Branch on grip magnitude vs threshold `DAT_0059e440`:
  - **High grip path** (fVar5 >= threshold): uses offset +0x3c7c–+0x3cc0 tables
  - **Low grip path** (fVar5 < threshold): uses offset +0x3c3c–+0x3c80 tables
  - Both paths: multiplies fVar4 by table scale factor, calls `FUN_005895a2` (sqrt), ROUND to index [0..13], linear interpolates between table entries
- If fVar5 > threshold after calculation:
  - Checks `*(param_1 + 0x39f8)` (tire state flag)
  - Selects between +0x3580 and +0x3770 offset sets based on `*(param_1 + 0x39b4)` (axle type, 2=rear)
  - Computes final force using velocity/long slip ratio, compares to threshold
  - Returns grip-limited force via `FUN_0059d99e()` or `FUN_0059d984()`
- Returns: `(interpolated_grip * C_downforce * sqrt(magnitude)/local_28) - (C_friction * C_downforce * fVar3) - param_4[2]`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x3514 | DampingCoeff | float, lateral damping |
| +0x3518 | GripMultiplier | float, final grip scale |
| +0x3a70 | SpringCoeff | float, suspension/camber influence |
| +0x39f8 | TireStateFlag | int, grip model selector |
| +0x39b4 | AxleType | int, 2=rear |
| +0x3998 | ForceThreshold | float, comparison |
| +0x39d0 | SpeedRatio | float, velocity scaling |
| +0x3580+0x90 | RearAxleRef | float, rear axle param |
| +0x3770+0x90 | FrontAxleRef | float, front axle param |
| +0x3c3c–0x3cc4 | LowGripTable[14] | float array, low grip interpolated values |
| +0x3c7c–0x3d44 | HighGripTable[14] | float array, high grip interpolated values |

**Globals:**
- `DAT_0059e440` — grip/clamp threshold
- `_DAT_0059ed18` — force reduction factor

**Calls:** FUN_005895a2 (sqrt), FUN_0059d99e (force computation), FUN_0059d984 (force computation)

**Moddability:** `configurable` — table values at +0x3c3c–+0x3cc4 and +0x3c7c–+0x3d44 are likely loaded from .svm/.hdv

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054bf60 — Pit Crew Animation Offset Update

Source: pit crew/animation module. Applies positional offset updates to pit crew member bone transforms during pit stop animations.

**Key logic:**
- Iterates linked list starting at `*(param_1 + 0x204)` (pit crew anim node list)
- For each node, iterates through `*(iVar1 + 0x118)` bone groups
- For each bone group: if `group_id == param_2` (crew member ID):
  - If `param_3 == 0`: adds param_4 (X offset) and param_5 (Z offset) to bone transforms at `+0x24` (position X) and `+0x28` (position Z) with stride 0xC (12 floats per bone)
  - If `param_3 == 1`: adds offsets to secondary transforms at `+0x2c` (likely rotation or alternative position)
  - Sets dirty flag: `piVar3[0xc] |= 0x800` (transform needs update)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x204 | AnimNodeListHead | ptr, linked list of anim nodes |

**Struct offsets (node at iVar1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x10 | NextNode | ptr, linked list next |
| +0x118 | BoneGroupCount | int |
| +0x11c | BoneGroupArray | ptr to bone group structs |

**Struct offsets (bone group at piVar3):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x00 | GroupID | int, matches param_2 |
| +0x04 | BoneCount | int |
| +0x08 | BoneDataArray | ptr to bone transforms |
| +0x30 | DirtyFlags | int, bitmask |

**Globals:** None.

**Calls:** None.

**Moddability:** `hardcoded` — animation offsets passed as parameters

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051d1db — Track Surface Heightmap Increment

Source: track/terrain module. Increments heightmap cells at given 3D footprint positions.

**Key logic:**
- Reads `*(param_1 + 0x5c)` (heightmap stride/dimensions)
- Reads `*(*(param_1 + 0x1a4) + 0x18)` (heightmap data base pointer)
- For each of `param_4` footprint entries:
  - Reads 3-byte position tuple from `param_2 + i*4` (packed XYZ indices)
  - Computes heightmap cell index: `(pbVar5[1]>>2)*0x20 + (pbVar5[2]>>3)` within row, row selected by `pbVar5[0]>>3`
  - Increments `*psVar1 += 1` (height counter)
  - Clamps: if counter overflows to 0, resets to -1 (max short)
- Advances through 3-byte packed positions per iteration

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x5c | HeightmapStride | int, row width in cells |
| +0x1a4 | TrackData | ptr, track geometry container |

**Globals:** None.

**Calls:** None.

**Moddability:** `hardcoded` — inline bit manipulation of packed position data

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509e85 — 8-bit Vertex Color Decoder (Palette Lookup)

Source: renderer/texture utility. Decodes 8-bit indexed vertex colors to float RGBA via palette lookup table.

**Key logic:**
- Computes pixel data address: `base = *(param_1 + 0x1050) * param_2 + *(param_1 + 0x1054) * param_3 + *(param_1 + 0x18)`
- Iterates through `*(param_1 + 0x1058)` pixels (2 bytes each):
  - Reads palette index from `*pbVar2` (first byte)
  - Looks up 4 floats at offset `(index + 3) * 0x10 + param_1` (palette table, 16 bytes per entry = float[4] RGBA)
  - Copies palette RGB to output `param_4[0..2]`
  - Sets alpha from second byte: `param_4[3] = pbVar2[1] * _DAT_0059e460`
  - Advances output by 4 floats (16 bytes per vertex)
- If `*(param_1 + 0x10) != 0`: calls `FUN_00507845` for post-processing

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1050 | TexStrideX | int, texture width stride |
| +0x1054 | TexStrideY | int, texture height stride |
| +0x1058 | PixelCount | int, number of pixels to decode |
| +0x18 | PixelDataStart | int, base offset into data |
| +0x10 | PostProcessFlag | int, enables post-processing |

**Globals:**
- `_DAT_0059e460` — alpha scale factor

**Calls:** FUN_00507845 (post-process decoded vertex colors)

**Moddability:** `hardcoded` — internal renderer utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509de6 — 4-bit Packed Color Decoder

Source: renderer/texture utility. Decodes 4-bit packed RGB data to float RGBA vertex colors.

**Key logic:**
- Same pixel addressing as 09e85: `base = *(0x1050)*y + *(0x1054)*z + *(0x18)`
- Iterates through `*(param_1 + 0x1058)` pixels (2 bytes each):
  - Extracts 4-bit color components:
    - Blue: `(pbVar3[1] & 0xf)` — second byte low nibble
    - Green: `(*pbVar3 >> 4)` — first byte high nibble
    - Red: `(*pbVar3 & 0xf)` — first byte low nibble
  - Each component multiplied by `_DAT_005ac108` (scale to 0.0–1.0 range)
  - Alpha set to 1.0
  - Stores float[4] RGBA to output
- If `*(param_1 + 0x10) != 0`: calls `FUN_00507845` for post-processing

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1050 | TexStrideX | int |
| +0x1054 | TexStrideY | int |
| +0x1058 | PixelCount | int |
| +0x18 | DataOffset | int |

**Globals:**
- `_DAT_005ac108` — 4-bit color scale factor (1/15 ≈ 0.0667)

**Calls:** FUN_00507845 (post-process decoded vertex colors)

**Moddability:** `hardcoded` — internal renderer utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042ed30 — AI Path Node Delegate

Source: AI pathfinding. Thin wrapper that reads a path node ID from vehicle struct and delegates to path processing.

**Key logic:**
- Reads node handle from `*(param_1 + 0x1644)`
- Calls `FUN_0042dd80(path_node_handle)`
- Returns void

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1644 | AIPathNodeHandle | int, AI path node identifier |

**Calls:** FUN_0042dd80 (process AI path node)

**Moddability:** `hardcoded` — simple delegation

<!-- target: docs/06-session-race-logic.md -->

## FUN_00508c22 — Float-to-Byte Color Converter (DXT-style)

Source: renderer/texture utility. Converts float RGBA vertex colors to packed 32-bit BGRA bytes with dithering/blending.

**Key logic:**
- If `*(param_1 + 0x1048) != 0`: transforms param_4 through FUN_00506ce2
- Gets color table base from `*(param_1 + 0x2c)`
- Calls `FUN_00507473()` (likely set up color conversion context)
- Loop `*(param_1 + 0x1058)` iterations:
  - Indexes into float table using `(param_3 & 3) + (param_2 & 3) * 8` with `(uVar6 & 3)` for dithering
  - RGB channels: `ROUND(*pfVar1 * _DAT_0059e6fc + fVar4)` — multiply by 255 and round
  - Alpha: `ROUND(pfVar3[3] * DAT_0059fec8 + fVar4)` — separate alpha multiplier
  - Packs into 32-bit BGRA word
- Output written via `extraout_EDX` pointer

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | TransformFlag | int, enables pre-transform |
| +0x1058 | PixelCount | int |
| +0x2c | ColorTableBase | ptr, float[4] color entries |

**Globals:**
- `_DAT_0059e6fc` — RGB channel multiplier (~255.0)
- `DAT_0059fec8` — alpha channel multiplier
- `_DAT_0059fec8` — additional scaling

**Calls:** FUN_00506ce2 (data transform), FUN_00507473 (context setup)

**Moddability:** `hardcoded` — internal renderer utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_00539690 — Bit Stream Writer (Byte Alignment)

Source: serialization/network utility. Writes bit-packed data to output buffer with byte-aligned flushing.

**Key logic:**
- Reads bit buffer state from `*(param_1 + 0x16ad)` (bits remaining)
- **If exactly 16 bits (0x10):** flushes two bytes
  - Writes byte at +0x16ab to buffer[offset], advances offset
  - Writes byte at +0x16ac to buffer[offset+1], advances offset
  - Resets +0x16ab and +0x16ad to 0
- **If > 7 bits:**
  - Writes low byte (+0x16ab) to buffer, advances offset
  - Shifts remaining bits: moves +0x16ac into +0x16ab
  - Decrements bit count by 8
- Buffer base at `*(param_1 + 8)`, current offset at `*(param_1 + 0x14)`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +8 | BufferBase | ptr, output byte buffer |
| +0x14 | BufferOffset | int, current write position |
| +0x16ab | BitAccumLow | ushort, pending low bits |
| +0x16ac | BitAccumHigh | byte, pending high bits |
| +0x16ad | BitCount | int, remaining bits in accumulator |

**Calls:** None.

**Moddability:** `hardcoded` — serialization utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_00549fb0 — Sphere vs Frustum Visibility Test

Source: renderer/culling. Tests whether a bounding sphere intersects a view frustum for visibility culling.

**Key logic:**
- Reads status flags at `*(param_1 + 4)`
- **Early out:** if `(flags & 0x50) != 0` → sets `flags |= 2` (culled), returns 0
- Computes world-space sphere center: adds sphere offset (+0x24, +0x28, +0x2c from param_2) to frustum position (+0x7c, +0x80, +0x84)
- Clears status flags lower nibble (`flags & 0xfffffff0`)
- **Distance cull:** if sphere radius (param_2+8) < distance to center − frustum near plane (+0x18): sets `flags |= 8` (too far), returns 0
- Sets `flags |= 1` (visible/maybe visible)
- Tests against 6 frustum planes at param_2+0x104 (stride 4 floats = 16 bytes per plane):
  - Plane equation: `ax + by + cz + d`
  - If sphere is fully outside any plane (`fVar1 > radius`): sets `flags |= 2` (culled), returns 0
  - If sphere intersects all planes: sets `flags |= 4` (fully visible), returns 0
- Returns 0 (status encoded in flags)

**Struct offsets (param_1 — frustum state):**
| Offset | Field | Notes |
|--------|-------|-------|
| +4 | CullFlags | uint, visibility status bits |
| +0x18 | NearPlaneDist | float, frustum near plane offset |
| +0x7c–0x84 | FrustumPosition | float[3], camera/frustum world position |

**Struct offsets (param_2 — sphere):**
| Offset | Field | Notes |
|--------|-------|-------|
| +8 | SphereRadius | float |
| +0x24–0x2c | SphereOffset | float[3], local offset from frustum |
| +0x104 | FrustumPlanes[6] | float[4] per plane (a,b,c,d), stride 16 bytes |

**Calls:** None (uses SQRT intrinsic).

**Moddability:** `hardcoded` — renderer culling utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050930b — Float-to-Byte Color Converter (RGB variant)

Source: renderer/texture utility. Converts float RGB vertex colors to packed 16-bit color with dithering.

**Key logic:**
- If `*(param_1 + 0x1048) != 0`: transforms param_4 through FUN_00506ce2
- Gets color table base from `*(param_1 + 0x2c)`
- Calls `FUN_00507473()` (color conversion context setup)
- Loop `*(param_1 + 0x1058)` iterations:
  - Indexes float color table using `(param_3 & 3) + (param_2 & 3) * 8` with `(uVar6 & 3)` for dithering
  - RGB: `ROUND(r * _DAT_005adb18 + g * _DAT_005adb1c + b * _DAT_005adb20)` — weighted blend
  - Alpha/packed high byte: `ROUND(alpha_component * _DAT_0059f120 + fVar1)`
  - Packs into 32-bit word: high 16 bits = alpha, low 16 bits = blended RGB
- Output written via `extraout_EDX` pointer

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1048 | TransformFlag | int |
| +0x1058 | PixelCount | int |
| +0x2c | ColorTableBase | ptr |

**Globals:**
- `_DAT_005adb18` — R channel weight
- `_DAT_005adb1c` — G channel weight
- `_DAT_005adb20` — B channel weight
- `_DAT_0059f120` — output scaling factor

**Calls:** FUN_00506ce2 (data transform), FUN_00507473 (context setup)

**Moddability:** `hardcoded` — internal renderer utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_004eff00 — Force Direction Projection (Normalized Dot Product)

Source: vehicle physics. Computes normalized negative dot product of a force/velocity vector against a direction.

**Key logic:**
- Checks if all 3 components at +0x34ec/f0/f4 are zero (equal to `DAT_0059e440` ≈ 0.0)
- If zero vector → returns 0.0
- Otherwise:
  - Magnitude = `sqrt(x² + y² + z²)`
  - Normalizer = `_DAT_0059e43c / magnitude`
  - Returns `-(x_norm * dir_x + y_norm * dir_y + z_norm * dir_z)`
- Direction vector at +0x34b8, +0x34c4, +0x34d0 (3 components)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34ec–34f4 | InputVector | float[3], force/velocity to project |
| +0x34b8 | DirX | float, direction component X |
| +0x34c4 | DirY | float, direction component Y |
| +0x34d0 | DirZ | float, direction component Z |

**Globals:**
- `DAT_0059e440` — zero threshold (~0.0f)
- `_DAT_0059e43c` — normalization constant (1.0f or max range)

**Calls:** None.

**Moddability:** `hardcoded` — physics math utility

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b5da0 — Pit Stall Proximity Check

Source: pit system. Checks if a driver's pit lane progress matches a pit stall position and triggers pit stop.

**Key logic:**
- Calls `FUN_004b68c0()` to get available pit stall count
- If zero: calls `FUN_004b6940(param_3)` to initialize pit stalls
- Loops through pit stalls (0 to count):
  - Computes modular index: `iVar2 = *(param_1 + 0x9b8) - iVar3` (lane position from entry point)
  - Wraps using `*(param_1 + 0x9b4)` if negative (circular pit lane)
  - Calls `FUN_004b6920(iVar2)` to get stall position data
  - Compares `*(param_2 + 4)` (driver's pit lane progress) against stall's `+0x6c` position
  - If driver progress <= stall position: found candidate
- If driver progress is within `_DAT_0059e8a4` of stall position: calls `FUN_004b48e0(param_2, param_3)` to trigger pit stop animation

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x9b4 | PitLaneLength | int, total pit lane length/segments |
| +0x9b8 | PitEntryIndex | int, entry point index in pit lane |

**Struct offsets (param_2 — driver):**
| Offset | Field | Notes |
|--------|-------|-------|
| +4 | PitProgress | float, driver's position in pit lane |

**Struct offsets (stall at iVar2):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x6c | StallPosition | float, stall position along pit lane |

**Globals:**
- `_DAT_0059e8a4` — proximity threshold for pit stop trigger

**Calls:** FUN_004b68c0 (get pit stall count), FUN_004b6940 (init pit stalls), FUN_004b6920 (get stall data), FUN_004b48e0 (trigger pit stop animation)

**Moddability:** `configurable` — threshold `_DAT_0059e8a4` adjustable

<!-- target: docs/06-session-race-logic.md -->

## FUN_00546010 — Audio Engine Initialization

Source: audio system. Initializes audio engine buffers, allocates mixer channels, and sets up processing chain.

**Key logic:**
- Resets global sample counters: `DAT_008b8ef8 = 0`, `DAT_008b8eec = 0`, `DAT_008b8ee8 = 0`
- Calls `FUN_0055b8c0(param_2, &DAT_008b8ee8)` to get buffer size info
- If callback `DAT_008b8f00` is set: calls it with 0
- Sets up buffer: `DAT_008b8ef0 = DAT_008b8ee8`, half-size = `DAT_008b8ee8 / 2`
- Thread-safe increment via `InterlockedIncrement`
- Calls `FUN_00545f50(0)` (buffer flush/reset)
- Allocates 0x1f0 bytes for mixer channel object via `operator_new`
- Initializes channel via FUN_005435d0, FUN_0053c5d0
- Sets channel flags: `flags |= param_3`
- Calls `FUN_0053ac70(2, 0)` (audio mode setup)
- Calls `FUN_00543a80(param_2)` to initialize sample data — if fails: cleanup
- Accumulates sample sizes from `+0x14..0x20` into global counter
- Calls `FUN_00543fa0()` — if fails: cleanup
- Iterates linked list at `*(*param_1 + 0x100)` calling processing chain setup functions
- Final flush via `InterlockedIncrement` + `FUN_00545f50`
- Calls `FUN_0053ac70(1, 0)` to finalize audio mode
- On failure: calls FUN_0053c630 to free resources

**Globals:**
- `DAT_008b8ee8` — audio buffer size
- `DAT_008b8eec` — half buffer size
- `DAT_008b8ef0` — buffer pointer/reference
- `DAT_008b8ef4` — total sample data size
- `DAT_008b8ef8` — buffer ready counter
- `DAT_008b8f00` — audio system callback

**Calls:** FUN_0055b8c0 (buffer size negotiation), FUN_0053ac70 (audio mode), FUN_005435d0 (channel alloc), FUN_0053c5d0 (channel init), FUN_00543a80 (sample init), FUN_00543fa0 (mixer init), FUN_00545f50 (buffer flush), FUN_0053c630 (cleanup), FUN_00549170/FUN_005492b0/FUN_00549380/FUN_00549440/FUN_00549470 (processing chain setup)

**Moddability:** `hardcoded` — audio engine internal initialization

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f6a50 — Quadratic Force/Torque Curve Evaluation

Source: vehicle physics. Evaluates a quadratic force/torque curve from stored coefficients when active.

**Key logic:**
- If `*(char *)(param_1 + 0x4d4)` (curve active flag) is non-zero:
  - Computes: `output = c0 + param_2*c1 + param_2*c2 + param_2*param_2*c3`
  - Where c0–c3 are doubles cast to float stored at +0x4d8–0x4f0
  - Writes result to `*param_3`
- If flag is zero: writes 0.0 to `*param_3`
- This is likely a torque curve, spring force, or engine power curve evaluation where param_2 is RPM/throttle/distance

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4d4 | CurveActiveFlag | char, enables curve evaluation |
| +0x4d8 | Coeff0 | double, constant term |
| +0x4e0 | Coeff1 | double, linear term 1 |
| +0x4e8 | Coeff2 | double, quadratic term |
| +0x4f0 | Coeff3 | double, linear term 2 |

**Calls:** None.

**Moddability:** `configurable` — curve coefficients likely from .svm/.hdv

<!-- target: docs/06-session-race-logic.md -->

## FUN_004be9e0 — Animation State Setter

Source: animation/pit crew. Stores animation state parameters into a struct.

**Key logic:**
- Sets 4 fields on the struct at `param_1`:
  - `+0x340 = param_2` (byte flag)
  - `+0x341 = param_3` (byte flag)
  - `+0x344 = param_4` (int/float value)
  - `+0x350 = param_5` (int/float value)
- Simple state setter for animation control parameters

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x340 | AnimFlag1 | byte, animation state flag |
| +0x341 | AnimFlag2 | byte, animation state flag |
| +0x344 | AnimValue1 | int/float, animation parameter |
| +0x350 | AnimValue2 | int/float, animation parameter |

**Calls:** None.

**Moddability:** `hookable` — state values passed in as parameters

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545150 — 3D Sound Source Destructor

Source: audio system. Recursively destroys a 3D sound source node and cleans up resources.

**Key logic:**
- Recursively destroys child nodes at +0x44 and +0x4c (left/right or child/sibling)
- Checks `FUN_0054a770()` for shutdown state → returns -1 if shutting down
- Audio cleanup: if +0x230 (sound buffer) is set:
  - Calls FUN_00560e50 (sound system remove)
  - If no parent (+0x40 == 0): calls FUN_005459d0(buffer)
  - If parent has own buffer: calls FUN_00560f10(buffer)
  - Then FUN_00560c00 + FUN_00587bcf (free)
- Removes reference from parent param_1's child array at +0x150 (stride 0x18)
- Calls FUN_005452b0 (unlink), FUN_0054a710 (decrement refcount), FUN_00587bcf (free)

**Struct offsets (param_1 — parent container):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14c | ChildCount | int |
| +0x150 | ChildArray | ptr, array of child object ptrs (stride 0x18) |

**Struct offsets (param_2 — sound source node):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x40 | ParentNode | ptr |
| +0x44 | ChildNode1 | ptr, first child |
| +0x4c | ChildNode2 | ptr, second child |
| +0x230 | SoundBuffer | ptr, audio buffer/handle |

**Calls:** FUN_0054a770 (shutdown check), FUN_00560e50/510/500 (sound system), FUN_005459d0 (buffer free), FUN_00587bcf (memory free), FUN_005452b0 (unlink), FUN_0054a710 (refcount dec)

**Moddability:** `hardcoded` — internal destructor

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052d9b0 — C++ Constructor (VTable Setup)

Source: game object. Sets vtable pointer and optionally calls initialization.

**Key logic:**
- Sets `*param_1 = &PTR_FUN_005b47e8` (vtable pointer for this class)
- If `*(char *)(param_1 + 0x93b) != 0` (byte flag at offset 0x93b — likely a config flag):
  - Calls `FUN_0052e320()` (further initialization / event subscribe)

**Globals:**
- `PTR_FUN_005b47e8` — vtable reference

**Calls:** FUN_0052e320 (post-constructor initialization)

**Moddability:** `hardcoded` — constructor pattern

<!-- target: docs/06-session-race-logic.md -->

## FUN_00424010 — Vehicle Subsystem Cleanup

Source: vehicle lifecycle. Frees a subsystem pointer and calls update functions during vehicle teardown.

**Key logic:**
- If `*(param_1 + 0x44a8) != 0`: frees it via `FUN_00587bcf(*(param_1 + 0x44a8))`
- Calls `FUN_004b0170()` (pit/vehicle system cleanup)
- Calls `FUN_004e4570()` (physics cleanup)

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x44a8 | SubsystemPtr | ptr, dynamically allocated subsystem object |

**Calls:** FUN_00587bcf (free), FUN_004b0170 (pit system), FUN_004e4570 (physics cleanup)

**Moddability:** `hardcoded` — cleanup/destructor

<!-- target: docs/06-session-race-logic.md -->

## FUN_00541470 — Audio Buffer Clear

Source: audio system. Clears a portion of an audio sample buffer to zero.

**Key logic:**
- If `*(param_1 + 0x114c) != 0` (audio buffer pointer exists):
  - Computes target address: `buffer_base + index * 0x24`
  - Calls `FUN_00540f00(addr, 0x60, 0, 0)` — clears 96 bytes to zero
- Buffer index at `*(param_1 + 0x1148)`, buffer base at `*(param_1 + 0x114c)`

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x1148 | BufferIndex | int, sample index (stride 0x24) |
| +0x114c | BufferBase | ptr, audio buffer base address |

**Calls:** FUN_00540f00 (memset/clear)

**Moddability:** `hardcoded` — audio buffer management

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9cb0 — Vehicle Lifetime Average Accessor

Source: vehicle physics. Reads the lifetime average value from a vehicle struct.

**Key logic:**
- Dereferences param_1 as a pointer to vehicle struct pointer (`*param_1`)
- Reads float at offset +0xf30
- Returns the value as float10
- This is a simple getter accessor

**Struct offsets (*param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf30 | LifetimeAvgField | float, likely related to engine/driver lifetime average |

**Moddability:** `hardcoded` — pure accessor

<!-- target: docs/17-physics-collision.md -->

## FUN_00531830 — Audio Mixer: Floating-Point to 16-bit PCM Conversion

Source: audio_mixer.cpp. Converts blocks of floating-point audio data to 16-bit signed PCM output with coefficient mixing.

**Key logic:**
- Maintains a 16-entry ring buffer counter at +0x24bc decremented modulo 16; tracks current mixing block
- Iterates over `iVar31` blocks (at +0x24cc), each with 0x900 byte stride for source data and 0x80 byte stride for output
- Inner loop (16 iterations) computes dot products between coefficient arrays and data arrays using floating-point arithmetic
- Each dot product result is clamped to ±0x8000 (-32768 to 32767) and stored as `short` in output buffer
- Final loop (15 iterations) computes additional mixing terms with coefficient patterns
- Coefficient stride is 0x20 words (32 floats), data stride is 0x10 words (16 floats) per channel
- Supports stereo/multi-channel mixing with interleaved output at stride `iVar31` (number of channels)

**Globals:**
- `DAT_005b666c` — coefficient table base for audio mixing

**Calls:** FUN_00531b50 (audio mixing kernel, processes one block)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051e7d7 — Audio Synthesis: 3-Channel Sample Generator

Source: audio_synth.cpp. Generates audio samples by summing three-channel lookup table values.

**Key logic:**
- Reads state from `param_1 + 0x1a4` (audio context pointer)
- Uses 3 lookup table bases from context: +0x30, +0x34, +0x38, +0x3c
- Inner loop processes `iVar7` samples (at +0x5c) in batches of `param_4` output elements
- Each output sample = sum of 3 values from separate lookup tables (indexed by pbVar13[0], [1], [2])
- Input strides: iVar4, iVar5, iVar6 (per-channel base offsets)
- Lookup table stride: 0x40 bytes (64 floats) between table sets
- Phase counter at context+0x30 advances modulo 16 after each batch
- Buffer pointer `param_3` indexes output array; `param_2` provides base offset

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00507779 — Temporary State Wrapper

Source: render_wrapper.cpp. Saves and restores object state around a pair of vtable function calls.

**Key logic:**
- Saves state from offsets +0x416, +0x419, +0x6, +0xb, +0x4 into locals
- Sets param_1[0x416] = 1, param_1[0x419] = param_1[0x41a] (state copy)
- Overwrites buffer pointer at +0x6 with stack buffer `local_28`, sets +0xb to `DAT_005d76c8` constant, clears +0x4
- If object type at param_1[2] != 1: saves +0x412 and +0x413, sets them to 1 and (param_1+7), calls FUN_00506ce2 to init, then restores them
- Calls two vtable functions: `(*param_1)(0,0,param_1+7)` at offset +8 and +4
- Restores all saved state

**Globals:**
- `DAT_005d76c8` — constant data pointer for temporary state

**Calls:** FUN_00506ce2 (state initialization), called via vtable at `*param_1 + 4` and `*param_1 + 8`

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00519d51 — Drawable Object Batch Processor

Source: render_batch.cpp. Iterates through render items and dispatches batch processing.

**Key logic:**
- Waits until `param_1+0x7c >= param_1+0x84` (producer/consumer buffer wait condition)
- Loops through objects at stride 0x54, checking each object's active flag at +0x30
- For active objects: calls vtable function at `*(param_1+4)+0x20` to create a buffer copy
- Calculates copy size: for early rows (`current < total-1`) uses full stride; for last row uses modulo
- Processes each row via vtable callback at `*(param_1+0x198)+4+local_8*4`
- Inner loop iterates over sub-rows (`uVar7` count, from object+0x1c) with stride object+0x24
- Returns `4 - (counter >= limit)` — returns 4 while more work available, 3 when complete

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x7c | ConsumerPosition | uint, current read position |
| +0x84 | ProducerPosition | uint, write position limit |
| +0x88 | BatchCounter | uint, incremented each call |
| +0x118 | TotalCount | uint, total items to process |
| +0x184 | BufferBase | pointer, base of data buffer |
| +0x18c | VTablePtr | pointer to vtable |
| +0x198 | CallbackTable | pointer to callbacks array |

**Calls:** via vtable (FUN_00 ptr at +0x20 in param_1+4), via callback table at param_1+0x198

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0040c780 — Scoring Gate Condition Check

Source: scoring.cpp. Returns a float value based on the scoring gate state.

**Key logic:**
- Checks global `DAT_008ab6e4` (ScoringGate)
- If ScoringGate == 2: calls FUN_004b9cf0() and returns its absolute value
- Otherwise: returns global `_DAT_008afe98`

**Globals:**
- `DAT_008ab6e4` — ScoringGate (mode selector, 2 = special mode)
- `_DAT_008afe98` — default return value (float)

**Calls:** FUN_004b9cf0 (returns float value)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054bdc0 — UI Element Bitfield State Setter

Source: ui_state.cpp. Walks a linked list of UI elements and applies bitmask state changes, handling color updates and state-specific callbacks.

**Key logic:**
- Iterates through linked list starting at `param_1 + 0x204`, following `+0x10` next pointers
- For each node: iterates through sub-elements at stride 0x10 (child count at +0x118)
- Applies `param_2` set-bits and `param_3` clear-bits to each element's flags
- If `param_2 & 0x20` is SET (enable branch): calls FUN_0054e0e0 to clear, then sets pixel color values on element's texture buffer using a palettized encoding scheme; increments global counter at `DAT_008b8f28 + 0x1b0`
- If `param_2 & 0x20` is CLEAR (disable branch) AND `param_3 & 0x20` is set: calls state-specific callback (FUN_0055d900, FUN_0055e320, or FUN_0055da50) based on flags & 3; conditionally calls FUN_0055eb30 if flag 0x400000 is set

**Globals:**
- `DAT_008b8f28` — UI context base (counter at +0x1b0)

**Calls:** FUN_0054e0e0 (state clear), FUN_0054e0f0 (state restore), FUN_0055d900 (state 0 callback), FUN_0055e320 (state 1 callback), FUN_0055da50 (state 2/3 callback), FUN_0055eb30 (extra state callback)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004e9bd0 — 3x3 Matrix Transform with Translation

Source: vehicle_physics.cpp. Applies a 3x3 rotation matrix and 3-component translation vector to a 3D vector.

**Key logic:**
- Reads 3x3 rotation matrix from offset range +0x34b0 to +0x34d0 (9 floats)
- Reads input vector from offsets +0x3b54, +0x3b58, +0x3b5c (3 floats)
- Computes matrix-vector product: output[i] = sum(matrix[i][j] * input[j])
- Adds translation from offsets +0x34d4, +0x34d8, +0x34dc
- Writes result to offsets +0x3b60, +0x3b64, +0x3b68

**Struct offsets (param_1 — vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34b0 | RotationMatrix[0][0] | float, 3x3 rotation matrix |
| +0x34d4 | TranslationX | float, translation component |
| +0x3b54 | InputVector[0] | float, input vector to transform |
| +0x3b60 | OutputVector[0] | float, transformed result |

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a55b — 16-bit Grayscale to RGBA Texture Converter

Source: texture_converter.cpp. Converts a 16-bit grayscale image buffer to RGBA floating-point format.

**Key logic:**
- Computes source pixel offset: `param_1[0x1050] * param_2 + param_1[0x1054] * param_3 + param_1[0x18]`
- Iterates over `param_1[0x1058]` pixels starting from computed offset
- For each pixel: reads `ushort`, scales by `_DAT_005ad290`, sets RGB all to same scaled value, alpha to 1.0
- Writes RGBA as 4 floats per pixel
- If flag at `param_1+0x10` is non-zero: calls FUN_00507845 on completed buffer

**Globals:**
- `_DAT_005ad290` — 16-bit grayscale intensity scaling factor

**Calls:** FUN_00507845 (texture buffer post-process)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00509f70 — 8-bit Grayscale to RGBA Texture Converter

Source: texture_converter.cpp. Converts an 8-bit grayscale image buffer to RGBA floating-point format.

**Key logic:**
- Computes source pixel offset: `param_1[0x1050] * param_2 + param_1[0x1054] * param_3 + param_1[0x18]`
- Iterates over `param_1[0x1058]` pixels starting from computed offset
- For each pixel: reads `byte`, scales by `_DAT_0059e460`, sets RGB all to same scaled value, alpha to 1.0
- Writes RGBA as 4 floats per pixel
- If flag at `param_1+0x10` is non-zero: calls FUN_00507845 on completed buffer

**Globals:**
- `_DAT_0059e460` — 8-bit grayscale intensity scaling factor

**Calls:** FUN_00507845 (texture buffer post-process)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00435260 — Thunk to FUN_00438c10

Thunk — delegates to FUN_00438c10. No entry needed.

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051bd61 — Audio Ring Buffer Manager

Source: audio_stream.cpp. Manages a ring buffer for streaming audio data, tracking read/write positions and flushing completed data.

**Key logic:**
- Reads buffer state from `param_1 + 0x188` (audio buffer object)
- If buffer ring is empty (`*puVar1 == 0`): allocates new data via vtable at `*(param_1+4)+0x1c`
  - Uses buffer[8], buffer[0x14], buffer[0x10] as allocation parameters
  - Stores result at buffer[0xc]
- Stores current ring position
- Calls vtable callback at `*(param_1+0x19c)+4` with buffer data and ring position
- If ring has advanced: computes delta, calls vtable at `*(param_1+0x1a4)+4` to flush consumed data from buffer base + old position
- If ring position >= buffer size: advances buffer offset by size and resets ring position to 0

**Struct offsets (param_1 — audio stream):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x188 | BufferObj | int*, buffer descriptor ptr |
| +0x19c | PlayCallback | int*, vtable for playback |
| +0x1a4 | FlushCallback | int*, vtable for buffer flush |

**Calls:** via vtable (param_1+4 +0x1c, param_1+0x19c +4, param_1+0x1a4 +4)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00539720 — Unicode Buffer Flusher

Source: text_output.cpp. Writes accumulated 2-byte (likely Unicode) data to an output buffer when sufficient data has accumulated.

**Key logic:**
- Checks accumulated byte count at +0x16ad
- If count > 8: writes byte from +0x16ab and byte from +0x16ac to buffer at `param_1[8] + param_1[0x14]` in sequence, advances position by 2, resets accumulators to zero
- If 0 < count <= 8: writes single byte from +0x16ab, advances position by 1
- If count <= 0: just resets accumulators without writing
- Supports buffered writing of 2-byte character sequences with minimum 8-byte accumulation threshold

**Struct offsets (param_1 — text buffer):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x8 | OutputBufferPtr | int*, destination buffer |
| +0x14 | WritePosition | int, current write offset |
| +0x16ab | CharBuffer[0] | byte, first character byte |
| +0x16ac | CharBuffer[1] | byte, second character byte |
| +0x16ad | Accumulator | int, accumulated byte count |

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054a2d0 — String Lookup in Linked Dictionary

Source: string_table.cpp. Walks a linked list comparing a search key against string entries, returns matching node.

**Key logic:**
- Starts from linked list head at `param_1 + 0x100`
- Compares input string `param_2` against each node's string (starting at node+8)
- Comparison is byte-by-byte with null-terminated strings
- If full match found (iVar4 == 0): returns node pointer
- If no match: follows `+0x104` next pointer and continues
- Returns 0 if list exhausted with no match

**Struct offsets (param_1 — dictionary):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x100 | HeadPtr | int*, first node in linked list |
| +0x104 | NextPtr | int*, per-node next pointer |

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005115c4 — State Reset

Source: state_manager.cpp. Clears several state counters and buffer fields to zero.

**Key logic:**
- Sets param_1+0xc4 = 0, param_1+0x7c = 0, param_1+0x178 = 0
- Reads pointer stored at param_1 + 400 (0x190)
- Sets bytes at that pointer+0x50 and +0x51 to 0
- Sets int at that pointer+0x58 to 0

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b69d0 — Ring Buffer Counter with Wrap

Source: ring_buffer.cpp. Implements a circular counter with modulo wrapping, returns overflow count.

**Key logic:**
- Reads current position at +0x9bc and limit at +0x9b4
- If positions differ: increments current, divides by limit, stores remainder as new position
- Returns quotient (overflow count)

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c230 — Linked List Indexed Accessor

Source: linked_list.cpp. Returns the Nth element from a linked list.

**Key logic:**
- Starts from linked list head at `param_1 + 0x204`
- Walks nodes via `+0x10` next pointer, counting steps
- Returns node pointer when count matches `param_2`
- Returns 0 if list ends before index reached

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c0ab0 — Audio Subsystem Initializer

Source: audio_init.cpp. Initializes an audio subsystem with 104 channel-slots and sets initial state.

**Key logic:**
- Calls FUN_004c03c0 0x68 (104) times — each call likely initializes one mixer channel
- Calls FUN_004c0370 (master init)
- Sets param_1+0xb144 = 0 (sample counter)
- Sets param_1+0xb150 = 0 (active flag)
- Sets param_1+0xb148 = 0xffffffff (last ID)
- Sets param_1+0xb14c = 1 (init complete flag)

**Calls:** FUN_004c03c0 (channel init, called 104 times), FUN_004c0370 (master init)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054ba00 — Doubly-Linked List Node Mover

Source: list_manager.cpp. Unlinks a node from its current doubly-linked list and appends it to another list.

**Key logic:**
- Reads node's prev (+0x48) and next (+0x4c) pointers
- If prev exists: updates prev->next = node->next
- If next exists: updates next->prev = node->prev
- If node is list head (global `DAT_008b8f28 + 0x108`): updates head to node->next
- If `param_3 != 0`: calls FUN_00544c50 to deallocate or finalize node
- Appends node to param_1's list: walks to tail via +0x4c, inserts node at end
- Sets node->prev = old tail, node->next = 0, node->parent = param_1
- If both param_1+0x230 and param_2+0x230 have buffers: calls FUN_00560eb0

**Globals:**
- `DAT_008b8f28 + 0x108` — global linked list head

**Calls:** FUN_00544c50 (node deallocation), FUN_00560eb0 (buffer merge/copy)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed1c0 — Float Parameter Forwarder

Source: param_forward.cpp. Forwards a float parameter to two functions, conditional on a state flag.

**Key logic:**
- Calls FUN_004ed0f0(param_2) unconditionally
- If param_1+0x32bc == 0: calls FUN_0043ebd0((double)param_2)

**Calls:** FUN_004ed0f0, FUN_0043ebd0

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004a5e40 — State-Conditional Action

Source: state_action.cpp. Calls a function if state is 0 or 4.

**Key logic:**
- Checks param_1+0x184 for value 0 or 4
- If either: calls FUN_004a5c80(1)

**Calls:** FUN_004a5c80 (action function)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005414a0 — Array Element Accessor

Source: array_access.cpp. Accesses an element in a 0x24-byte stride array by index.

**Key logic:**
- Checks if array base at +0x114c is non-null
- If so: computes offset `base + index * 0x24` and calls FUN_00540f90

**Calls:** FUN_00540f90 (element processor)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9cc0 — Vehicle Speed Accessor

Source: vehicle_access.cpp. Returns a float value from the vehicle struct at a fixed offset.

**Key logic:**
- Reads `*param_1` (vehicle pointer)
- Returns float at `(*param_1) + 0xf34`

**Struct offsets (param_1 — vehicle struct):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xf34 | SpeedValue | float, vehicle speed or RPM |

**Calls:** None

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_004ebc60 — Vehicle Contact Force Accumulation

Source: hdphysics.cpp. Accumulates wheel contact forces from suspension into vehicle rigid body, with collision-type branching for particle effects.

**Key logic:**
- Reads 3×3 rotation matrix at param_1+0x34b0–0x34d0 (9 floats) — wheel orientation or body-to-world transform
- Reads reference velocity vector via FUN_004ea930
- Computes local-space force and torque contributions from contact point data in param_2 (position +0x04, +0x14–0x1c; direction +0x20–0x28)
- Accumulates force at param_1+0x34f8–0x3500 (3 floats)
- Accumulates torque at param_1+0x3504–0x350c (3 floats), scaled by inverse inertia-like coefficients at +0x3528–0x3530
- Reads collision type at param_1+0x32bc:
  - Type 0: processes contact point position/velocity for collision response, calls FUN_004ec050, FUN_0043e5d0
  - Type 0 or 1 with param_3 != 0: calls FUN_004ec1a0 (play collision sound?)
  - Type 2: triggers debris/particle effects via FUN_00463dc0, FUN_004b2580, FUN_0045eb00, FUN_004ec020, FUN_004b2480

**Calls:** FUN_004ea930 (read global velocity vector), FUN_004ec050, FUN_0043e5d0 (contact geometry), FUN_004ec1a0 (collision sound), FUN_00463dc0, FUN_004b2580 (debris), FUN_0045eb00, FUN_004ec020, FUN_004b2480

**Moddability:** hardcoded — collision type branching, contact stiffness baked in

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0051b37d — Plane-Visibility Test with Bitfield Output

Source: render_util.cpp. Tests a set of points against a plane or frustum and sets bitmask flags per element.

**Key logic:**
- Reads element count from param_1+0x13c
- Uses a bitmask at param_1+0x174 to select a bit position (1 << (value & 0x1f))
- Tests each element's data at param_2 with indices 0..count-1
- For each element, tests 8 vectors/points against planes using dot product test
- If point fails plane test (dot product < negative sum), sets corresponding bit in element's ushort flags
- Tracks state via param_2 with bit consumption from iVar6/iVar8 bitstream
- Returns 1 on success, 0 on failure
- Decrements counter at iVar2+0x34

**Calls:** FUN_0051aefc (state check), FUN_0051a794 (bit test)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042f140 — String Copy with Return

Source: utility.cpp. Copies a string to internal buffer with null-termination, returns buffer pointer.

**Key logic:**
- Calls FUN_00423a00 to validate param_2 string
- If non-empty: copies via memmove-style loop from param_2 to param_1+0xc
- Returns pointer to param_1+0xc (the copy destination)
- If string is empty: sets *param_1+0xc = 0 and returns it

**Calls:** FUN_00423a00 (string length/validation check)

**Moddability:** hardcoded — utility function

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0042a740 — Track Parameter Minimum Clamp

Source: vehicle_setup.cpp. Clamps a vehicle performance parameter to a running minimum value with a floor.

**Key logic:**
- If param_2 < *(param_1+0x4484): sets *(param_1+0x4484) = param_2 (track minimum)
- If *(param_1+0x4484) < 5.0f (0x40a00000): sets to 5.0f (floor clamp)
- Used for recording best/worst parameter values during a session

**Globals:**
- `_DAT_0059e7ec` — compared constant (5.0f encoded indirectly)

**Calls:** none

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054d910 — AABB-Frustum Visibility Classification

Source: scene_graph.cpp. Tests an axis-aligned bounding box against 8 half-spaces/planes and classifies as fully inside, outside, or intersecting.

**Key logic:**
- Tests up to param_1+0xfc elements (count)
- For each element: tests 8 corner points against a plane equation using dot product
- If all 8 corners on the wrong side (0xff): sets flag bit 1 (2) = fully outside
- If any corner on wrong side: sets flag bit 2 (4) = intersecting
- If all corners inside: sets flag bit 0 (1) = fully inside
- Flag stored at param_1+0x14, lower 3 bits masked with 0xfffffff8
- Used for frustum culling or collision broadphase culling

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x14 | CullFlags | bit 0=inside, bit 1=outside, bit 2=intersecting |
| +0xfc | ElementCount | number of elements to test |

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a172 — RGB565 Texture Decompression

Source: texture_decode.cpp. Decompresses 16-bit RGB565 texel data into RGBA float format.

**Key logic:**
- Computes source pointer from param_1: offset = param_1+0x1050 × param_2 + param_1+0x1054 × param_3 + param_1+0x18
- Reads count from param_1+0x1058
- For each texel: reads ushort, extracts 5-bit channels via bit shifts
  - R: bits 0-4 (signed shift trick for sign extension)
  - G: bits 5-9
  - B: 0.0
  - A: bits 10-15, scaled by _DAT_005accdc
- All RGB channels scaled by _DAT_0059e9e0
- Output: RGBA float quadruplets to param_4

**Globals:**
- `_DAT_0059e9e0` — color channel scale factor
- `_DAT_005accdc` — alpha channel scale factor

**Calls:** FUN_00507845 (optional end-of-buffer processing)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00545bb0 — Scene Instance Collection

Source: scene_graph.cpp. Traverses scene graph node lists and collects instances matching render/physics flags.

**Key logic:**
- Reads instance count from param_1+0x174, allocates array (stride 0x18 + 4 header) via operator_new
- Frees old instance list via FUN_00587bcf
- Traverses list at param_1+0x100 (sibling-linked): filters for nodes with flag 0x20000 at +0x14 and no flag 0x40 at +0x04
- Stores matching instances into array at param_1+0x178
- Similarly traverses list at param_1+0x108
- Stride per entry: 0x18 (24 bytes)

**Calls:** FUN_004b0170 (object initializer), FUN_00587bcf (heap free), FUN_00548e00 (object constructor), operator_new

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a659 — 16-bit Vertex Position Decompression

Source: vertex_decode.cpp. Decompresses 16-bit unsigned vertex position data into float vec4 format.

**Key logic:**
- Computes source pointer: param_1+0x1050 × param_2 + param_1+0x1054 × param_3 + param_1+0x18
- Stride: 3 ushorts per vertex (6 bytes)
- Count from param_1+0x1064 (end pointer)
- Each vertex: reads 3 ushorts as X, Y, Z, scales by _DAT_005ad290
- Output: vec4 (x, y, z, 1.0) to param_4
- Calls FUN_00507845 at end if param_1+0x10 is set

**Globals:**
- `_DAT_005ad290` — position scale factor

**Calls:** FUN_00507845 (end-of-buffer flush)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0050a0f0 — 8-bit Vertex Position Decompression (2D)

Source: vertex_decode.cpp. Decompresses 8-bit signed vertex data into 2D float vec4 format.

**Key logic:**
- Computes source pointer: param_1+0x1050 × param_2 + param_1+0x1054 × param_3 + param_1+0x18
- Stride: 2 bytes per vertex, count from param_1+0x1058
- Each vertex: reads 2 signed bytes as X, Y, scales by _DAT_0059e774
- Output: vec4 (x, y, 0.0, 1.0) to param_4
- Calls FUN_00507845 at end if param_1+0x10 is set

**Globals:**
- `_DAT_0059e774` — position scale factor

**Calls:** FUN_00507845 (end-of-buffer flush)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00435270 — Thunk

Thunk — registers callback via FUN_00587b3e with &LAB_00435280. No entry needed.

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00537e40 — UI Element Initialization

Source: ui_element.cpp. Initializes a UI element with pointer table entries and default values.

**Key logic:**
- Calls FUN_00537eb0 (base constructor)
- Sets up internal pointer table at offsets +0xb0e, +0xb1a, +0xb16, +0xb22, +0xb26, +0xb2e
- Zeroes +0x16ab (word) and +0x16ad (dword)
- Sets +0x16a7 = 8
- Calls FUN_00537ec0 (completion init)

**Calls:** FUN_00537eb0, FUN_00537ec0

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005425a0 — Viewport Position Clamping

Source: ui_viewport.cpp. Clamps a 2D position within a parent viewport's boundaries.

**Key logic:**
- Gets float position from vtable call on DAT_008b8f24 (renderer)
- Clamps X to [param_1+0x68, param_1+0x54 + param_1+0x68]
- Clamps Y to [param_1+100, param_1+0x58 + param_1+100]
- Output via param_3 pointer

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x54 | Width | int, viewport width |
| +0x58 | Height | int, viewport height |
| +0x68 | XOffset | int, viewport X origin |
| +100 | YOffset | int, viewport Y origin (decimal!) |
| +0x15c | LocalData | data passed to renderer |

**Calls:** __ftol (float-to-int)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054b2c0 — Scene Graph Flag Propagation

Source: scene_graph.cpp. Propagates flag bits through scene graph hierarchy.

**Key logic:**
- ORs param_2 into flags at param_1+0x3c
- If param_3 != 0 and has children (param_1+0x204): ORs param_3 into child flags, recurses through sibling chain at +0x10
- If has sub-nodes (param_1+0x44): recursively calls self
- Traverses sibling chain (param_1+0x4c) with param_4 direction flag

**Calls:** FUN_0054b2c0 (recursive)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005196b8 — Buffered Data Stream Write

Source: data_stream.cpp. Manages buffered writes to a data stream/pipe.

**Key logic:**
- Checks state flag (active/inactive)
- If inactive: tries activation via vtable
- Calls write method via vtable
- Resets when count reaches capacity

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004f69e0 — Linear Vehicle Parameter Evaluation

Source: vehicle_eval.cpp. Evaluates linear combination of vehicle parameters (double-precision coefficients).

**Key logic:**
- *param_6 = param_3*coeff1 + param_2*coeff2 + bias (from +0x520, +0x530, +0x4ac)
- *param_5 = ABS(*(double*)+0x444)
- param_5[1] = ABS(*(double*)+0x47c)
- param_5[2] = param_4*coeff_a + param_3*coeff_b + param_2*coeff_c + bias_2 (from +0x3fc, +0x518, +0x528, +0x3f4)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_00500190 — Vehicle Data Buffer Clear

Source: vehicle_data.cpp. Zeroes 0x1b0-byte buffer.

**Key logic:**
- Zeroes 0x6c dwords starting at param_1+0x1b8
- Sets *(param_1+0x1bc) = _DAT_005ad348

**Globals:**
- `_DAT_005ad348` — default value

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c6920 — Vehicle Object Constructor

Source: vehicle.cpp. Constructs vehicle with TeamID=-1.

**Key logic:**
- Calls FUN_00423e80 (base), sets TeamID=-1, calls FUN_004c79e0, FUN_00424040
- Returns param_1

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x4894 | TeamID | int, -1 = unassigned |

**Calls:** FUN_00423e80, FUN_004c79e0, FUN_00424040

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0054c210 — Scene Graph Child Count

Source: scene_graph.cpp. Counts children in linked list.

**Key logic:**
- Traverses list from param_1+0x204 (next at +0x10)
- Returns count

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_0052d9f0 — Object VTable Initialization

Source: object_base.cpp. Sets vtable and zeroes fields.

**Key logic:**
- *param_1 = &PTR_FUN_005b47e8
- Zeroes byte at 0x24ec and dword at 0x24f0

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004ed1f0 — Force Application Router

Source: vehicle_physics.cpp. Routes force based on collision type.

**Key logic:**
- Calls FUN_004ed0f0(param_2)
- If param_1+0x32bc == 0: calls FUN_0043ec00(param_2)

**Calls:** FUN_004ed0f0, FUN_0043ec00

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b15d0 — Bitmask State Test

Source: vehicle_state.cpp. Tests bit in state mask.

**Key logic:**
- If state at +0x1f78 != 5: returns true
- Else tests bit at position param_2 in mask at +0x2ab4

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_005414c0 — UI Toggle State

Source: ui_toggle.cpp. Flips boolean.

**Key logic:**
- *(param_1+0x1148) = 1 - *(param_1+0x1148)

**Moddability:** hardcoded

---

<!-- target: docs/06-session-race-logic.md -->

## FUN_004b9e30 — Vehicle Data Accessor

Source: vehicle_access.cpp. Single dereference accessor.

**Key logic:**
- Returns *(*param_1 + 0xf8c)

**Moddability:** hardcoded

---

<!-- target: docs/17-physics-collision.md -->

## FUN_004ed420 — VehicleGeometryProximityTest

Source: unknown (no assert string). Tests if a point lies within any of 4 bounding spheres of a vehicle/object, computing closest-point-on-ray.

**Key logic:**
- Gets rotation matrix from FUN_004ea930 (3x3 stored at param_1+0x34b0/0x34bc/0x34c8)
- Transforms input point (param_3) and a local offset into object-local space via matrix multiply
- Loops iVar5=0..3 testing 4 bounding elements stored at stride 0xf8 (pfVar3) / 0x128 (piVar6):
  - Each element has position at offsets [-2,-1,0] and radius at [+0x1f]
  - Element is active if `*piVar6 != 0` AND `piVar6[0x10] != 0` (flag check)
  - Tests if squared distance from transformed point to element center < radius²
- If sphere hit: computes reflection/impulse using per-element contact data at offset 0x35b0 + iVar5*0xf8 and global DAT_0059e440
- If no hit (fallback): computes closest-point on ray via dot product (param_4) and distance (param_5 via FUN_004ed380)
- If param_6 non-zero: computes contact normal/plane data via FUN_004ed7b0

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x34b0 | RotMatrix_row0 | 3 floats, rotation matrix row 0 |
| +0x34bc | RotMatrix_row1 | rotation matrix row 1 |
| +0x34c8 | RotMatrix_row2 | rotation matrix row 2 |
| +0x828 | ElementFlags[4] | int array stride 0x128, flags per element |
| +0x3594 | ElementArray[4] | stride 0xf8, position + radius per element |

**Globals:**
- `DAT_0059e440` — constant used in contact response computation

**Calls:** FUN_004ea930 (get rotation matrix), FUN_004ed750 (get vector), FUN_004ed710 (get direction), FUN_004ed380 (dot/angle between vectors), FUN_004ed7b0 (contact point computation)

**Moddability:** hardcoded — geometry hardcoded to 4 elements at fixed offsets

<!-- target: docs/06-session-race-logic.md -->

## FUN_004c11c0 — TireWearGetter

Source: unknown. Returns the tire wear/condition value at +0xb14c.

**Key logic:**
- Returns int at param_1+0xb14c

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0xb14c | TireWearValue | undefined4 |

**Calls:** none

**Moddability:** hardcoded — simple accessor

<!-- target: docs/17-physics-collision.md -->

## FUN_005438b0 — AudioPanUpdate

Source: unknown. Updates audio pan/balance parameters with clamping.

**Key logic:**
- If param_2 >= _DAT_0059e430 (NaN/zero): sets param_1+0x194 = param_2 (left pan)
- If param_1+0x194 <= param_3: sets param_1+0x198 = param_3 (right pan), sets dirty flag (bit 0x10000 at +0xec)
- Else: sets param_1+0x198 = param_1+0x194 (fallback), sets dirty flag

**Globals:**
- `_DAT_0059e430` — NaN/zero sentinel

**Struct offsets (param_1):**
| Offset | Field | Notes |
|--------|-------|-------|
| +0x0ec | DirtyFlags | uint, bit 0x10000 = pan update needed |
| +0x194 | PanLeft | float |
| +0x198 | PanRight | float |

**Calls:** none

**Moddability:** hardcoded

<!-- target: docs/06-session-race-logic.md -->
