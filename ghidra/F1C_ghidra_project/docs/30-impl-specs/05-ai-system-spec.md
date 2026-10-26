# Implementation Spec: AI System

Source: docs/02-ai-system.md  |  Functions: ~70  |  Date: 2026-07-15

---

## Overview

The AI system controls all non-player vehicle behavior in F1 Challenge 99-02: speed targeting, steering/racing line, overtaking/defending, pit strategy, and skill representation. It runs at multiple frequencies — per-frame (physics tick), per-lap (speed update), per-session (init/cleanup). It does NOT own vehicle physics (docs/10, docs/18-physics-dynamics.md) but reads physics state to make decisions.

The system is organized into three layers:
1. **AI Ability/Skill** (FUN_00424080, FUN_004040a0) — loads `.rcd` driver ratings, computes runtime speed deltas with quadratic scaling, difficulty interpolation
2. **AI Controller/State Machine** (FUN_00424e70, FUN_004270a0, FUN_00425670) — per-frame behavior dispatch: steering, braking, path following, rival interaction
3. **AI Event/Audio** (FUN_00419120–FUN_0041aa10) — triggers commentary audio on position changes, overtakes, pit entry, retirement, corner speed comparison

Data flow: Raw ability values from `.rcd` → per-session scaled speed targets (DAT_005ea3d8, track reference × difficulty) → per-lap live ratio (param_1+0x114f) → per-frame steering/braking decisions → physics integration.

## Data Structures

### VehicleStruct (param_1 — vehicle state block)
```c
// Total size: 0x48C0 (observed stride across vehicle array)
// Accessed via: DAT_007c54f0 (VehiclePtrArray)
struct VehicleStruct {
    /* +0x0000 */ void* vtable;           // MSVC object header
    /* +0x0008 */ float posX;             // world position
    /* +0x000C */ float posY;
    /* +0x0010 */ float posZ;
    /* +0x1130 */ int   qualifyingAbility; // stored as (1.0 - QA) * scale, inverted from .rcd
    /* +0x1131 */ float rawSlowness;      // (22 - RaceAbility) / 22, scaled by slider²
    /* +0x1132 */ float rainSensitivity;  // RainAbility × 0.01 × global_rain_scale
    /* +0x1133 */ float passEffort;       // Passing × 0.001 + 0.9, clamped [0.9, 1.0]
    /* +0x1135 */ float pushProbRef;      // (22 - RaceAbility × 0.67) × (1/22)
    /* +0x1136 */ float speedVarWindow;   // (1 - baseSpeedRatio) × 0.67
    /* +0x113d */ float baseSpeedRatio;   // (1 - RA × 0.01) × DAT_005ea3d8
    /* +0x113e */ float trackAggression;  // TrackAggression × DAT_007d017c, min 0.01
    /* +0x1140 */ float corneringAdd;     // from .rcd (default 1.5)
    /* +0x1141 */ float corneringMult;    // from .rcd (default ~0.967)
    /* +0x1142 */ uint8_t lapTypeFlag;    // 0=conservative, 1=push
    /* +0x1143 */ uint8_t pushLapCounter; // consecutive push laps
    /* +0x1144 */ uint32_t behaviorState; // FSM state: 0/6=follow, 1=pursuit, 2=pit in, 3=pit entry, 4/5=pit window, 7=overtake
    /* +0x114f */ float liveLapRatio;     // current lap speed target, ±0.01/lap
    /* +0x1152 */ uint8_t steerOverride;  // 1=skip steering correction
    /* +0x1153 */ uint8_t pushActive;     // push lap flag
    /* +0x1157 */ float brakeAccum;       // brake frame counter
    /* +0x115c */ float brakeTimerLeft;
    /* +0x115d */ float brakeTimerRight;
    /* +0x1160 */ float wetSpeedMult;     // 1.0 - wetness × rainSensitivity, ≥0.5
    /* +0x1167 */ uint8_t pitBlockFlags;  // bit 3 = pit blocked (non-race)
    /* +0x1178 */ uint32_t pitStopBitmask; // planned pit stops
    /* +0x117f */ uint8_t overtakeTarget; // passing direction
    /* +0x1b0  */ uint32_t driverState;   // current driver audio/state ID
    /* +0x1b10 */ uint32_t raceMode;      // difficulty/race mode selector
    /* +0x32bc */ uint32_t pathValid;     // path validity flag
    /* +0x34b0 */ float orientMatrix[12]; // 3×4 orientation matrix
    /* +0x34d4 */ float offsetX;          // integrated path offset
    /* +0x34d8 */ float offsetY;
    /* +0x34dc */ float offsetZ;
    /* +0x34e0 */ void*  aiStateStruct;   // pointer to AI substate (FUN_00425670 context)
    /* +0x3668 */ void*  wheelPtr[4];     // per-wheel contact (stride 0x3e)
    /* +0x403c */ int    seasonPoints;    // current championship points
    /* +0x4040 */ int    pitStrategy;     // 2 or -1 = no strategy
    /* +0x4058 */ int    qualifyingPosition;
    /* +0x405c */ float  qualifyingTime;
    /* +0x4060 */ int    finishPosition;
    /* +0x4064 */ int    finishState;     // 0=running, 1=finished, 2=DNF, 3=DSQ
    /* +0x409c */ float  bestLapTime;
    /* +0x4354 */ uint32_t aiStateFlags;  // overtaking zone flags (80 bytes)
    /* +0x4438 */ void*  aiFollowTarget;  // current follow target vehicle ptr
    /* +0x4448 */ float  ringBufferField; // from RingBufferCounter + difficulty calc
    /* +0x445c */ float  aiGapToAhead;
    /* +0x44f4 */ float  forceCoefficient; // lateral force calc
    /* +0x4500 */ float  passScoreBiasAdd;
    /* +0x4504 */ float  passScoreBiasMult;
    /* +0x4534 */ float  pitCrewTimer;    // pit crew timer
    /* +0x4538 */ float  driverParameter;
    /* +0x453c */ float  trackCorneringFactor;
    /* +0x454c */ int    aiSpeedDelta;
    /* +0x4550 */ int    aiTargetParam;
    /* +0x4579 */ uint8_t brakeActive;
    /* +0x4580 */ float  aggressionFactor;
    /* +0x4584 */ uint8_t pitStintFlag;
    /* +0x4588 */ int    stateCountIndex;
    /* +0x4590 */ uint32_t stateTable[];  // stride 0x10
    /* +0x45e0 */ int    stintCount;
    /* +0x45f4 */ uint8_t needsUpdateFlag;
    /* +0x45f8 */ int    lastSelection;
    /* +0x45fc */ int    currentSelection;
    /* +0x4620 */ char   driverName[64];
    /* +0x4678 */ char   vehicleDescription[];
    /* +0x4714 */ char   filePath[];
    /* +0x4794 */ char   aiSettingsFile[256]; // AI settings file path
    /* +0x4893 */ uint8_t nullTerminator;
    /* +0x4894 */ int    teamID;
    /* +0x489c */ int    driverNumber;
    /* +0x48bc */ int    aiControlFlags;   // bit 0 = AI enable
};
// Size: 0x48C0 (confirmed from VehicleArray stride)
```

### AI Database Struct (param_1 — waypoint/config database)
```c
// Size: ~0x168+ bytes. Allocated by FUN_004040a0.
// Accessed as int[] or float[] depending on field.
struct AIDatabase {
    /* +0x00 */ float  grooveWidth;        // from .gdb
    /* +0x04 */ float  grooveWidthWet;      // from .gdb
    /* +0x46 */ float  globalSpeedMult;     // computed from AIDifficultySlider
    /* +0x47 */ float  speedMultMin;        // 0.5
    /* +0x48 */ float  speedMultMid;        // 1.0
    /* +0x49 */ float  speedMultMax;        // 1.3
    /* +0x58 */ int    gridSpotCount;       // 104
    /* +0x59 */ int    pitSpotCount;        // 52
    /* +0x5a */ int    garageSpotCount;     // 3
    /* +0x57 */ int    unknownFlag;         // 1
    /* +0x11c */ float worstAdjust;         // AI racing line worst, clamped ≥0.5
    /* +0x120 */ float midAdjust;
    /* +0x124 */ float bestAdjust;          // clamped ≤1.3
    /* +0x128 */ float raceQualRatio;
    /* +0x12c */ int   leftHandedPits;      // bool
    /* +0x130 */ int   waypointCount;
    /* +0x134 */ void* waypointArray;       // stride 0x13c
    /* +0x13c */ float lapLength;
    /* +0x140 */ float sector1Length;
    /* +0x144 */ float sector2Length;
    /* +0x14c */ float fuelUse;
    /* +0x150 */ void* gridArray;           // stride 0x1c, max 104
    /* +0x154 */ void* pitArray;            // stride 0x1c, max 52
    /* +0x158 */ void* garageArray;         // stride 0x1c
    /* +0x15c */ int   pitlaneCount;
    /* +0x160 */ int   startingGridMin;     // min 104
    /* +0x164 */ int   pitSpotsMin;         // min 52
    /* +0x168 */ int   garageSpotsMin;      // min 3
};
// Loaded from .gdb file "Features" section + waypoint data.
```

### Waypoint Struct (stride 0x13c = 316 bytes)
```c
#define WAYPOINT_STRIDE 0x13c
struct Waypoint {
    /* +0x00 */ float posX, posY, posZ;     // position
    /* +0x08 */ float perpX, perpY, perpZ;  // perpendicular vector
    /* +0x0b */ float width[4];              // waypoint width
    /* +0x16 */ float dwidth[4];             // delta width
    /* +0x12 */ float score;
    /* +0x21 */ uint32_t event[2];
    /* +0x46 */ float galpha;
    /* +0x47 */ float grooveLat;
    /* +0x48 */ void* nextWp[3];             // 3 next waypoint pointers
    /* +0x4b */ int   branchID;
    /* +0x4c */ uint32_t bitfields;
    /* +0x4d */ float wpse[2];
    /* +0x110 */ void* linkedNext;            // linked list next pointer
    /* +0x25 */ float backupPos[3];
};
```

### Driver Data Table (20 entries, stride 0x20)
```c
#define DRIVER_TABLE_ENTRIES 20
#define DRIVER_TABLE_STRIDE 0x20  // 8 ints per entry
struct DriverTableEntry {
    /* +0x00 */ int   key;           // driver ID / sort key
    /* +0x04 */ int   fields[7];     // time, score, etc.
};
// Base at param_1+0x864, accessed by FUN_00418560, FUN_00418a60
```

### AI Opponent Node (0xc bytes)
```c
struct AIOpponentNode {
    /* +0x00 */ void* aiEntryPtr;    // 8 bytes: ID + QA score float
    /* +0x04 */ void* next;          // linked list
    /* +0x08 */ uint8_t flag;        // set to 1
};
// Used by FUN_004bf790 for AI opponent selection
```

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007d01a0 | int | AIDifficultySlider | 0–120, global difficulty setting |
| DAT_005ea3d8 | float | TrackRefSpeed | Track-scaled AI reference speed (set per session) |
| DAT_008aae70 | int | RingBufferCounter | 256-slot ring buffer counter for noise/random |
| DAT_008aae74 | float[256] | RingBufferTable | Ring buffer values (qualifying noise, random offsets) |
| DAT_005bf9b0 | void* | DriverDataTable | Base of driver data table (stride 0x14) |
| DAT_007d017c | float | TrackAggressionMult | Global track aggression multiplier (per-track config) |
| DAT_005ea3dc | float | DifficultyLow | Low difficulty reference value |
| DAT_005ea3e0 | float | DifficultyMid | Mid difficulty reference value |
| DAT_005ea3e4 | float | DifficultyHigh | High difficulty reference value |

## Public API — Entry Points

### FUN_004040a0 — AIDatabase::Init()

**Inferred signature:** `void AIDatabase::Init(AIDatabase* this)`
**Called from:** game startup init chain (FUN_0042d6b0)
**Called by (from callers.json):** 0x0042d6b0 (unknown)

**What it does:**
1. Sets default aiDB values: groove width (4.5/4.3125), speed mult endpoints (0.5/1.0/1.3), grid/pit/garage counts
2. Computes aiDB[0x46] (globalSpeedMult) from AIDifficultySlider:
   - slider > 100: lerp between 1.0 and 1.3 using `(slider - 100) * DAT_0059e448`
   - slider ≤ 100: lerp between 0.5 and 1.0 using `(slider - 70) * DAT_0059e474`
3. Opens "AI Database File" from DAT_007ce608 path
4. Loads waypoint database via FUN_00402690 (.gdb parser)

**Constants:**
- `DAT_0059e448` = slider>100 interpolation rate (0.05?)
- `DAT_0059e474` = slider≤100 interpolation rate (1/30?)
- `DAT_0059e478` = default value for entries [0x4f..0x51]

**Side effects:**
- Writes: aiDB array fields (groove, speed mult, grid/pit counts)
- Opens/reads .gdb file from disk

---

### FUN_00424080 — AI Profile Loader / Ability Processor

**Inferred signature:** `void ProcessAIAbility(VehicleStruct* vehicle, void* rcdData)`
**Called from:** FUN_00424790 (AI driver init)
**Called by (from callers.json):** 0x00424790

**What it does:**
1. Reads .rcd fields: QualifyingAbility, RaceAbility, RainAbility, Passing, CorneringAdd, CorneringMult, StartsDry, StartsWet
2. Computes per-vehicle runtime parameters:
   - param_1[0x1130] = (int)((1.0 - QualifyingAbility) * scale) — inverted storage
   - param_1[0x1131] = raw_slowness = (22 - RaceAbility) / 22, then quadratically scaled if slider < 100
   - param_1[0x1132] = RainAbility × 0.01 × global_rain_scale
   - param_1[0x1133] = clamp(Passing × 0.001 + 0.9, 0.9, 1.0)
   - param_1[0x113d] = (1 - RaceAbility × 0.01) × DAT_005ea3d8
   - param_1[0x1136] = (1 - param_1[0x113d]) × 0.67
   - param_1[0x1135] = (22 - RaceAbility × 0.67) × (1/22)
   - param_1[0x113e] = max(TrackAggression × DAT_007d017c, 0.01)
   - param_1[0x114f] = 1.0 (init live lap ratio)
3. Reads CorneringAdd/CorneringMult from .rcd (undocumented fields)
4. Computes tire start temperature multiplier from StartsDry/StartsWet blended by wetness

**Quadratic scaling (slider < 100 only):**
```
if (DAT_007d01a0 < 100):
    RaceAbility = (slider/100.0)² × RaceAbility
```
This compresses ability spread at lower difficulty settings.

**Constants:**
- 22.0 = reference maximum RaceAbility (DAT_0059e85c)
- DAT_005ea3d8 = track-scaled reference speed

---

### FUN_00424e70 — AI Main Update / Race Phase State Machine

**Inferred signature:** `void AIUpdate(VehicleStruct* vehicle)`
**Called from:** main game loop tick (0x0042c690)
**Called by (from callers.json):** 0x0042c690

**What it does:**
1. Gates on param_1[0xcb2] — must be 0 or 1 (AI active)
2. Pit exit block: heading computation, lap push logic, ability update
3. Behavior state machine at param_1[0x1144]:
   - States 4/5: pit window — manages pit entry timing
   - States 0/6: follow — follow racing line at target speed
   - State 1: pursuit — chasing another vehicle
   - State 3: pit entry — driving to pit lane
   - State 2: pit in — inside pit lane
   - State 7: overtake — attempting pass
4. Race phase transition detection: detects phase change, decrements timer
5. Phase 4 (parked): computes steering with random offset

**Called sub-functions (internal dispatch):**
- FUN_00426430 — component event log
- FUN_0042a180 — push lap / closing gap update
- FUN_00429470 — per-lap speed update (on lap completion)
- FUN_0042ae00 — AI state flags update
- FUN_00425670 — waypoint path tracking
- FUN_004258c0 — pit lane path tracking
- FUN_0042a7d0 — opponent proximity scan
- FUN_00425920 — racing line / overtaking gap
- FUN_004270a0 — steering output computation
- FUN_00426100 — pit exit merge logic
- FUN_00426cf0 — steering correction / stability
- FUN_00426330 — speed target computation
- FUN_00424c80 — ring buffer field update
- FUN_0042adb0 — command queue status

**Side effects:**
- Writes: vehicle state fields (steering, braking, speed target, behavior state)
- Triggers pit entry decisions
- Updates live lap ratio

---

### FUN_004270a0 — Steering / Racing Line Controller

**Inferred signature:** `void ComputeSteering(VehicleStruct* vehicle)`
**Called from:** 0x00424e70 (AI update)
**Called by (from callers.json):** 0x00424e70

**What it does:**
1. Reads current vehicle ptr from param_1[0x10d5] and flag from param_1[0x115b]
2. Initializes steering limits (param_1[0x1103]) from track-speed; clamps left/right limits (param_1[0x1105]/[0x1106])
3. Computes brake modifier: ratio of min rival speed to (min+max)
4. Main loop (0..4): iterates 5 path/rival candidates at stride +0x11 per candidate:
   - Candidate struct: vehicle ptr (+0x0), lateral distance (+0x3), longitudinal gap (+0xc), threshold check (+0xd), path segment index (+0xe), index offset (+0x10)
5. For each sorted rival (priority order):
   - State machine at rival state index:
     - 0: normal (pending overtake/block decision)
     - 1: passing right, 2: passing left
     - 3: side-by-side right, 4: side-by-side left
     - 5: fall back / yield
     - 7: defend right, 8: defend left
     - 0x10: alongside (blocked)
   - Brake computation: left/right brake via sqrt(target) + penalty adjustments
   - Lateral gap: angular offset to rival; maintain speed if within threshold
   - Collision avoidance: gap below threshold → state 5 (fall back)
6. Final output: param_1[0x1103] (steering), param_1[0x1102] (clamped steering copy), param_1+0x4579 (brake active flag)

**Calls:** FUN_00403aa0 (path segment resolve), FUN_004039c0 (alt path resolve), FUN_00423ca0/FUN_00423db0/FUN_00423b10 (segment handling), FUN_0042a740 (set throttle), FUN_0042af70 (vehicle-facing state dispatch), FUN_004fae70 (sqrtf)

---

### FUN_00429470 — Per-Lap Speed Update

**Inferred signature:** `void UpdateLapSpeed(VehicleStruct* vehicle)`
**Called from:** 0x00424e70 (AI update, at lap completion in race only)
**Called by (from callers.json):** 0x00424e70

**What it does:**
1. Branch on vehicle type via FUN_004d1cf0
2. Lap type selection:
   - If param_1[0x1142] == 0 (conservative): liveLapRatio -= 0.01, floored at 0x113d
   - If param_1[0x1142] != 0 (push): liveLapRatio approaches (0x113d + 0x1136), step up +0.01
3. Push probability roll each lap:
   - probability = (param_1[0x1135] - param_1[0x1143] × 0.5) × 100
   - if rand()%100 ≤ probability: aggressive jump to maximum
   - else: conservative pull-back toward 0x113d × 0.5
   - Resets lap type flag (0x1142) and push counter (0x1143) to 0
4. Pit check: tire-lap counter vs current lap → call FUN_0042a110
5. Compound mismatch check → call pit if mismatch
6. Tire wear threshold check → call pit if exceeded

**Constants:**
- 0.01 = lap ratio step size
- 0.5 = push probability decay per consecutive push lap

---

### FUN_0042a180 — Push Lap / Rain Penalty Update

**Inferred signature:** `void UpdatePushLap(VehicleStruct* vehicle)`
**Called from:** 0x00424e70 (per physics tick)
**Called by (from callers.json):** 0x00424e70

**What it does:**
1. Early return if vehicle state != 1
2. Non-race: liveLapRatio = min(10, lap_index) × 0.01 + current (gradual improvement)
3. Rain penalty: recomputes 0x1160 = max(0.5, 1.0 - wetness × rainSensitivity) from rainSensitivity at 0x1132
4. Push active check at +0x1153
5. Pit check: tire-lap counter ≤ current lap → call pit
6. Compound mismatch → call pit. Tire wear threshold → call pit

---

### FUN_0042a3d0 — Pit Stop Decision & Tire Compound

**Inferred signature:** `int DecidePitStop(VehicleStruct* vehicle)`
**Called from:** 0x00429470 (lap update), 0x004a6200

**What it does:**
1. Read planned pit stops from param_1[0x1178] bitmask
2. Compute remaining laps to next planned stop
3. DRS override: randomize pit target to current lap (randomize pit timing)
4. Pit-blocking check via FUN_0042aee0
5. Tire compound selection by aggression:
   - aggression < 0.01 → hard compound (index 4)
   - 0.01 ≤ aggression < 0.1 → medium compound (index 5)
   - aggression ≥ 0.1 → soft compound (index 6)
6. Scan 7 compound slot indices for matching compound; adjust gear ratios
7. Return decision (0 = no stop, 1 = stop now)

**Calls:** FUN_0042aee0, FUN_004c6d90, FUN_004bc060, FUN_004a5bd0, FUN_004f1890, FUN_0042a6f0, FUN_004a5750, FUN_004a57a0

---

### FUN_004333e0 — AI Settings File Loader

**Inferred signature:** `void LoadAISettings()`
**Called from:** 0x0042c3b0 (AI settings)
**Called by (from callers.json):** 0x0042c3b0

**What it does:**
1. For each vehicle (DAT_005c329c loop):
2. Call FUN_00433890 to resolve settings filename
3. If DAT_007d03e0 == 0 (simple mode): copy settings path to vehicle +0x4794
4. Else (advanced mode): build path from settings dir + team name + suffix
   - Session 5 (qualifying): `.qual` suffix
   - Other sessions: `.race` suffix
   - Falls back to `ai.svm`
5. Open file, copy path to vehicle struct

**Globals:** DAT_007d03e0 (AI settings mode), DAT_005c329c (vehicle count), DAT_007c54f0 (vehicle array)

---

### FUN_004bf790 — AI Opponent Selection

**Inferred signature:** `int SelectAIOpponents(void* listHead)`
**Called from:** 0x004bfd90, 0x004c0db0 (filter setup)
**Called by (from callers.json):** 0x004bfd90, 0x004c0db0

**What it does:**
1. If param_2 < 0xb and slot already filled by FUN_004bfa00: return early
2. Randomly select param_2 AI drivers from pool (FUN_004c5070/FUN_005871f0)
3. For each candidate:
   - Check duplicates via FUN_00588410 (string compare)
   - Create linked list node: stores AI entry pointer + QA score (FUN_004bf6a0)
   - Append to linked list
4. Merge-sort linked list by QA score (ascending)
5. Return count of AI drivers selected

---

## Internal Call Graph

### AI Speed Pipeline
```
FUN_004040a0 — AIDatabase::Init  [session start]
  +-- FUN_00402690 — Waypoint Database Loader (.gdb parser)
        +-- FUN_004024f0 — Waypoint Path Validator (loop check)

FUN_00424080 — Process AI Ability  [per vehicle init, called from FUN_00424790]
  (leaf — no calls to other documented AI functions)

FUN_00424e70 — AI Main Update  [per physics tick]
  +-- FUN_0042a180 — Push Lap / Rain Penalty Update
  |     +-- FUN_0042a110 — Force Pit Exit Check
  |     +-- FUN_004f1630 — Wear/Temperature Check
  |     +-- FUN_004a4830 — Pit Strategy Check
  +-- FUN_00429470 — Per-Lap Speed Update  [on lap complete]
  |     +-- FUN_0042a3d0 — Pit Stop Decision & Tire Compound
  |     |     +-- FUN_0042aee0 — Pit Stop Blocking Condition
  |     |     +-- FUN_0042a6f0 — Post-Pit Cleanup/Exit
  |     |     +-- FUN_004c6d90 — Vehicle Reset
  |     +-- FUN_0042a6f0 — Post-Pit Cleanup
  |     +-- FUN_0042a110 — Force Pit Exit Check
  |     +-- FUN_004f1630 — Wear/Temperature
  |     +-- FUN_004a4830 — Pit Strategy
  |     +-- FUN_00429eb0 — Phase-Based Pit Entry
  |           +-- FUN_0042ad20 — Random Proximity Check
  |           +-- FUN_0042a110 — Force Pit Exit
  +-- FUN_00425920 — Racing Line / Overtaking Gap
  |     +-- FUN_0042a780 — Opponent Score Computation
  |     +-- FUN_004e87e0 — Wheel Force/State
  |     +-- FUN_0042ae00 — State Flag Update
  +-- FUN_004270a0 — Steering / Racing Line Controller  [5-rival loop]
  |     +-- FUN_00403aa0 — Path Segment Resolve
  |     +-- FUN_004039c0 — Alt Path Resolve
  |     +-- FUN_00423ca0/DB0/3B10 — Segment Handling
  |     +-- FUN_0042a740 — Set Throttle
  |     +-- FUN_0042af70 — Overtaking Decision
  |     +-- FUN_004fae70 — sqrtf
  +-- FUN_0042a7d0 — Opponent Proximity Scan
  |     +-- FUN_004a4710 — Find Nearest Vehicle
  +-- FUN_00426cf0 — Steering Correction / Stability
  +-- FUN_00426100 — Pit Exit Merge Logic
  +-- FUN_00426330 — Speed Target Computation
  +-- FUN_00424c80 — Ring Buffer Field Update
  +-- FUN_0042adb0 — Command Queue Status

### AI Event/Audio Chain
FUN_00419120 — Driver State Transition  [on event]
  +-- FUN_004144d0 — Random/Text Init
  +-- FUN_004144f0 — Driver Data Lookup

FUN_004beb10 — Overtake / Collision Detection Loop  [per tick]
  +-- FUN_004bf0a0 — AI Behavior Init / Gap Computation
  |     +-- FUN_004be760 — Finish Time Predictor
  |     +-- FUN_0042ae90 — State Count Update
  |     +-- FUN_004bf390 — Driver Sorting
  +-- FUN_004bef60 — Collision Type Detection
  +-- FUN_004bf390 — Driver Sorting (bubble-sort)
  +-- FUN_004bf4f0 — Tick Update / Ring Buffer Reset

FUN_004bfd90 — AI Driver Count / Grid Setup  [session start]
  +-- FUN_004bf790 — AI Opponent Selection
        +-- FUN_004bfa00 — Slot Check
        +-- FUN_004bf6a0 — QA Score
        +-- FUN_004c5070 — AI Pool Access
        +-- FUN_00588410 — String Compare
```

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 22.0 | FUN_00424080 | Reference maximum RaceAbility (DAT_0059e85c) |
| 0.67 | FUN_00424080 | Speed variation window factor |
| 0.01 | FUN_00429470 | Lap ratio step size (per lap) |
| 0.5 | FUN_00429470 | Push probability decay multiplier per consecutive push lap |
| 0.9 | FUN_00424080 | Passing effort minimum (clamp floor) |
| 1.0 | FUN_00424080 | Passing effort maximum (clamp ceiling) |
| 0.5 | FUN_004040a0 | Minimum global speed multiplier (aiDB[0x47]) |
| 1.0 | FUN_004040a0 | Mid global speed multiplier (aiDB[0x48]) |
| 1.3 | FUN_004040a0 | Maximum global speed multiplier (aiDB[0x49]) |
| 104 | FUN_004040a0 | Grid spot count |
| 52 | FUN_004040a0 | Pit spot count |
| 3 | FUN_004040a0 | Garage spot count |
| 0.003 | FUN_0042a180 | Non-race per-lap improvement rate |
| 0.1 | FUN_0042a3d0 | Aggression threshold for soft tire compound |
| 0.01 | FUN_0042a3d0 | Aggression threshold for hard tire compound |
| 1/120 | FUN_004bf0a0 | Difficulty normalization factor (DAT_005acde0) |
| 0x5f (95) | FUN_00424750 | Difficulty threshold for low-range interpolation |
| 20 | FUN_00418560 | Driver table entry count |
| 0x20 (32) | FUN_00418560 | Driver table entry stride |
| 0x48c0 | multiple | VehicleStruct total size |
| 0x424 | multiple | VehicleArray stride (DAT_008ac394) |
| 0x13c | FUN_00402690 | Waypoint struct stride |
| 0x1c | FUN_00402690 | Grid/pit/garage slot stride |

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_007c56a4 (SessionType) — from docs/12, determines race/quali/practice branches
- DAT_007c56a8 (RacePhase) — from docs/12, race state machine transitions
- DAT_007d00ec (GameState) — from docs/12, game mode gating
- DAT_007d0410 (RaceMode) — from docs/12, championship vs single race
- DAT_005c329c (VehicleCount) — from docs/12, vehicle loop bounds
- DAT_007c54f0 (VehiclePtrArray) — from docs/12, vehicle access
- DAT_007cea5c (EngineWearMode) — from docs/12, wear model branch
- DAT_007d0c60 (TireWearMultiplier) — from docs/12, tire wear for pit decisions
- DAT_007cf080 (WeatherMode) — from docs/12, rain/wetness for rain ability
- DAT_008afee8 (TrackWetness) — current track wetness for rain penalty computation
- DAT_007d0308 (RaceActiveFlag) — race activity gating

**Calls into:**
- docs/10-vehicle-physics.md: FUN_004e87e0 (wheel force/state), FUN_004f1630 (wear/temp)
- docs/18-physics-dynamics.md: FUN_004ef680 (transform matrix)
- docs/20-math-utilities.md: FUN_00588410 (string compare), FUN_005871f0 (RNG)
- docs/06-session-race-logic.md: FUN_004a5c40, FUN_004a5e40 (session phase)

**Called by:**
- docs/01-engine-architecture.md: main game loop (FUN_0042c690 → AI update tick)
- docs/06-session-race-logic.md: session init chain (FUN_0042c1a0 → AI driver count setup)
- docs/10-vehicle-physics.md: vehicle init chain (FUN_0042c3b0 → AI settings load)

## Reimplementation Notes

1. **Quadratic difficulty scaling**: At slider < 100, RaceAbility is scaled by `(slider/100)²`. This means mods that expect linear response at 70% difficulty get ~49% actual effect. Reimplementation must preserve this for save-game compatibility.

2. **Two-tier difficulty**: The system applies difficulty at two independent points — per-car quadratic (RaceAbility) and global linear (aiDB[0x46]). These multiply at different stages and are NOT combined.

3. **QualifyingAbility vs RaceAbility**: QA is ONLY used for synthetic time generation (FUN_004bf6a0). RA drives actual on-track performance. Synthetic QA times include session-persistent ring buffer noise (DAT_008aae70) that produces different gaps each session even with identical .rcd files.

4. **RainAbility inverted**: Higher RainAbility = MORE wet sensitivity = WORSE in rain. REVERSE of intuitive naming. RainAbility at 0 makes rain specialist, at 100 makes rain-phobic.

5. **Ring buffer noise**: The ring buffer at DAT_008aae74 (256 floats, indexed by DAT_008aae70 modulo 256) is NOT reset between sessions. Each AI driver consumes one slot per synthetic time generation. The counter wraps indefinitely.

6. **AI state machine ordering**: The behavior state at param_1[0x1144] must be checked in order: pit window states (4/5) take priority over follow (0/6), pursuit (1), overtake (7). Pit states (2/3) are exclusive.

7. **Steering controller per-rival state**: Each of 5 rival slots has a 4-bit state machine (0–0x10). States are persistent between frames and must be preserved. The state determines steering direction and braking behavior for that rival.

8. **No virtual methods**: The AI system uses plain C-style function calls with struct pointer arguments. No C++ virtual dispatch on AI objects (except the vehicle struct which has a vtable for object lifecycle).

9. **Pit decision priority**: Tire wear threshold check → compound mismatch → planned stop count → DRS randomization. All four conditions are evaluated each lap, first true condition triggers pit.

10. **Minimal external state**: The AI system reads from vehicle physics state but writes only to its own fields (0x1100–0x4600 range) plus the audio/commentary dispatch.

## Completeness

- Full specs written: 8 entry points + overview + data structures + call chains
- Minor helper/shim functions omitted: FUN_0042ac70, FUN_0042aca0, FUN_0042acd0 (simple state setters)
- Confidence: **high** — all key formulas and branches are documented from decompiled source
- Remaining unknowns: exact track reference speed computation (anonymous session init function), exact tire wear threshold values for pit decisions, exact values of some DAT_0059xxxx tuning constants

---
