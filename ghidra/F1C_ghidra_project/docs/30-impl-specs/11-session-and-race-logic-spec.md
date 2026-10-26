# Implementation Spec: Session and Race Logic

Source: docs/06-session-race-logic.md  |  Functions: 845  |  Date: 2026-07-15

---

## Overview

The Session and Race Logic system manages all aspects of a racing session from start to finish. It owns the session state machine (practice/qualifying/race transitions), the steward system (penalty enforcement, lap counting, proximity tracking), race results generation, HUD rendering, and session configuration loading/persisting.

The system runs at multiple granularities:
- **Per-frame tick**: `FUN_0046bf10` (Main Session Execution Loop) advances physics, sound, and state for all vehicles each frame via `FUN_004b9890` (Race Tick Advance). Steward per-tick dispatch `FUN_004d4580` runs penalty/proximity/phase logic.
- **Per-event**: Penalty handlers (`FUN_004bc0e0`/`FUN_004bbd60`/`FUN_004bbc60`) fire on infractions. Lap completion (`FUN_004bc4e0`) fires when a vehicle crosses the finish line.
- **Per-session**: Session enter functions (`FUN_00472510`–`FUN_00474ab0`) run once at session start. Session state machine (`FUN_0046dc60`) orchestrates pre-race/race/post-race.
- **On-load**: Session config builder (`FUN_00461610`) reads global setup variables and packs them into a bitfield structure.

**Data structures owned:**
- **SessionConfig bitfield**: Packed configuration flags for tire model, fuel, damage, pit timers (built by `FUN_00461610`, written back by `FUN_00461900`).
- **PenaltyRecord array**: Per-vehicle penalty state (type, timer, reason). Stride 8, max 128 entries. Managed by steward.
- **Timing arrays**: Lap times, sector times, and gap tracking allocated by `FUN_004d38f0` (steward init), freed by `FUN_004d4600` (steward cleanup).
- **Replay buffers**: Linked lists of replay data entries, VCR file streams.
- **Results data**: HTML page generators and `raceresults.txt` writer.

**Boundary interfaces:**
- **Input from**: SessionType (`DAT_007c56a4`), RacePhase (`DAT_007c56a8`), RaceMode (`DAT_007d0410`), FormationLap (`DAT_007cebc4`), PenaltiesEnabled (`DAT_007cef84`), VehiclePtrArray (`DAT_007c54f0`), PlayerVehiclePtr (`DAT_007c54e8`).
- **Output to**: Vehicle struct fields (finish state +0x4064, position +0x4060, penalty counters), audio system (commentary events via `FUN_004b33b0`), file system (results, replays, hot laps).
- **Called by**: Game state machine (higher-level orchestrator), UI menu flow (post-race redirects via `FUN_0046fc30`).

---

## Data Structures

### VehicleStruct (param_1 — per-vehicle state block)

```c
// Size: 0x48C0 bytes.
// Accessed via DAT_007c54f0 (VehiclePtrArray) or derived from season DB stride 0x48c0.
struct VehicleStruct {
    /* +0x0000–0x07 */ void* vtable;                // MSVC object header
    
    // Position & orientation
    /* +0x0008 */ float  PositionX;
    /* +0x000C */ float  PositionY;
    /* +0x0010 */ float  PositionZ;
    /* +0x0014 */ float  Orientation[4];             // Quaternion (x,y,z,w)
    /* +0x0020–0x0040 */ float RotationMatrix[3][3]; // Column-major, 9 floats
    
    // Race/session state fields
    /* +0x403C */ int    SeasonPoints;               // Accumulated season points
    /* +0x4044 */ float  PenaltyFloat;               // Time penalty accumulator (float seconds)
    /* +0x4058 */ int    QualifyingPosition;          // Starting grid position
    /* +0x405C */ float  QualifyingTime;              // Best qualifying lap time
    /* +0x4060 */ int    FinishPosition;              // Final race position (1=winner)
    /* +0x4064 */ int    FinishState;                 // 0=running, 1=finished, 2=DNF, 3=DSQ
    /* +0x4068 */ int    ReasonCode;                  // Retirement/DNF reason code
    /* +0x409C */ float  BestLapTime;                 // Best lap time (seconds)
    /* +0x40B4 */ float  SessionTime;                 // Session elapsed time
    /* +0x40B8 */ float  RaceTime;                    // Total race time
    
    // Driver/vehicle identity
    /* +0x4620 */ char   DriverName[64];              // Driver display name
    /* +0x4678 */ char   VehicleDescription[128];     // Vehicle file name/desc
    /* +0x46F8 */ char   DriverNameAlt[16];           // Alternative driver name
    /* +0x4894 */ int    TeamID;                      // Team identifier (-1=unassigned)
    /* +0x489C */ int    DriverNumber;                // Driver number (-1=unset)
    
    // Physics/position (used by steward for jumped start detection)
    /* +0x34F8 */ float  VelocityZ;                   // Velocity/position component
    /* +0x34FC */ float  VelocityY;
    /* +0x3500 */ float  VelocityX;
    /* +0x34C4 */ float  GridForwardDirX;             // Grid forward direction
    /* +0x34D0 */ float  GridForwardDirY;
    /* +0x34DC */ float  GridForwardDirZ;
    
    // AI/session fields
    /* +0x39FC */ float  SessionSubType;              // Sub-type selector for events
    /* +0x4354 */ int    AIStateFlags;                // AI behavior flags (80 bytes)
    /* +0x406C */ int    PenaltyCounter;              // Incremented per penalty event
};
// Accessed via: DAT_007c54f0 (VehiclePtrArray), param_1 pattern in most steward functions
```

### PenaltyRecord

```c
struct PenaltyRecord {
    int   type;             // 0=none, 1=stop/go pending, 3=DSQ
    float timer;            // Countdown/accumulated time
    int   reasonCode;       // Reason for penalty (maps to string table)
};
// Stored per-vehicle at offsets identified in steward functions
// Penalty array managed by steward init/cleanup
```

### SessionConfigBitfield

```c
struct SessionConfigBitfield {
    // Packed at param_1+0x76, spans ~4 bytes
    uint8_t bit0  : 1;  // DAT_007ce874 flag
    uint8_t bit1  : 1;  // DAT_007ce88c flag
    uint8_t bit2  : 1;  // TireModelMode (DAT_007ce958)
    uint8_t bit3  : 1;  // DAT_007ce97c flag
    uint8_t bit4  : 1;  // Fuel level (DAT_007d108c, converted short)
    uint8_t bit10 : 1;  // DAT_007ced44
    uint8_t bit11 : 1;  // DAT_007cee40
    uint8_t bit12 : 1;  // DAT_007cef3c
    // ... additional config bits
    
    /* +0x78 */ uint16_t ReconPitOpen;   // Pit window open lap
    /* +0x7A */ uint16_t ReconPitClosed; // Pit window close lap
};
// Built by FUN_00461610 (SessionConfigBuilder)
// Written back to globals by FUN_00461900 (SessionConfigWriteback)
```

### SessionStruct (steward/session state)

```c
// Observed across steward and session functions. Confidence: high.
struct SessionStruct {
    /* +0x14 */ int   ActiveFlag;           // Non-zero = session active
    /* +0x24 */ int   Count1;
    /* +0x30 */ int   Count2;
    /* +0x3C */ int   Count3;
    /* +0x44 */ ptr   ListHead;             // Session entries list
    /* +0x48 */ int   Count;
    /* +0x4C */ int   Count;
    /* +0x50 */ int   Count;
    /* +0x54 */ int   Count4;
    /* +0x60 */ int   Count5;
    /* +0xAC */ int   BestTime;             // 0x7fffffff = DNF
    /* +0xB8 */ float MaxSessionTime;       // 7200.0 (2 hours)
    /* +0xBC */ float TimeMultiplier;       // 1.0
    /* +0x128 */ int   SectorFlags[26];     // Initialized to -1
    /* +0x180 */ byte  StateFlag;
    /* +0x184 */ int   SessionState;        // 0=idle, 1=active, 4=finished
    /* +0x190 */ short LapCount;            // 0xffff = invalid
    /* +0x192 */ byte  CurrentSector;       // 0xff = invalid
    /* +0x280 */ int   PitWindowHistory[52]; // Zeroed
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007c56a4 | int | SessionType | 7=race 6=quali 0-5=practice; written by session enter functions |
| DAT_007c56a8 | int | RacePhase | 0-8 phase indicator; written by steward dispatch |
| DAT_007d0308 | int | RaceActiveFlag | Written by session start/end |
| DAT_008acf8c | int | TotalRaceLaps | Written by session config loader |
| DAT_008acf90 | int | RaceTimeOffset | Written by steward |
| DAT_008acf94 | int | RaceTimeThreshold | Written by steward |
| DAT_008acfa0 | byte | HalfDistanceFlag | Written by lap completion (FUN_004bc4e0) |
| DAT_007cec30 | float | ReconPitOpen | Pit window open time; written by FUN_0059d74e / FUN_004b1190 |
| DAT_007cec54 | float | ReconPitClosed | Pit window close time; written by FUN_0059d74e / FUN_004b1190 |
| DAT_007cef84 | int | PenaltiesEnabled | Gate for all penalty enforcement |
| DAT_0083ee60 | int | PenaltyCount | Max 0x3ff, incremented per penalty event |
| DAT_008aae64 | int | PenaltyHistoryStride | Advances by 0x1b0 per penalty |
| DAT_007ce254 | byte | DisableHUDFlag | When set, HUD rendering is skipped |
| DAT_007d2dd4 | int | PlayerStarts | Career stat |
| DAT_007d2dd8 | float | AvgStartPosition | Career stat |
| DAT_007d2de0 | int | Wins | Career stat |
| DAT_007d2de8 | int | LapRecords | Career stat |
| DAT_007d2dec | int | PolePositions | Career stat |
| DAT_007d2df0 | int | Points | Career stat |
| DAT_007d2df4 | float | AvgFinishPosition | Career stat |
| DAT_007d2e00 | int | DriversChampionships | Career stat |
| DAT_005cc9e8 | int | SessionInitState | -1/0/1; drives session setup flow |
| DAT_007ce269 | char | SessionInitGate | One-time init gate |
| DAT_007ce26c | float | RaceTimerValue | Initialized to 5.0f |
| DAT_007ce2e8 | int | SessionCatchupFlag | Enables catchup logic |

---

## Public API — Entry Points

### FUN_0046dc60 — Session State Machine

**Inferred signature:** `int SessionStateMachine(SessionStruct* session)`
**Called from:** Game state machine, post-init flow.
**Called by (from callers.json):** Not found in callers graph (may be called via function pointer or vtable dispatch).

**What it does:**
1. Checks if async loading is complete via `FUN_004a0590`
2. If SessionType == 5 (server session) AND FormationLag (DAT_007cebc4) is set: runs main session loop via `FUN_0046bf10`
3. Calls `FUN_004d2450` to activate first uninitialized vehicle
4. Sets `DAT_005cc9e8 = 4` when complete

**Side effects:**
- Writes: DAT_005cc9e8 (SessionInitState)
- Calls: FUN_0046bf10 (which loops until session done)

### FUN_0046bf10 — Main Session Execution Loop

**Inferred signature:** `int MainSessionLoop(SessionStruct* session)`
**Called from:** FUN_0046dc60 (Session State Machine)

**What it does:**
1. Sets time threshold based on SessionType
2. Enters loop calling `FUN_004beb10` (frame tick) each iteration
3. After loop exits: if race session, runs cleanup via DAT_005eb10c vtable
4. Returns 0 when session complete

**Side effects:**
- Runs the active session until timer or lap completion
- Calls: FUN_004be6f0, FUN_004c8d80, FUN_004988c0, FUN_004beb10 (per-frame), FUN_00496880, FUN_00497250, FUN_00496e90, FUN_004186a0, FUN_0041d630, FUN_004b0170

### FUN_004d4580 — Steward Update Main Dispatch

**Inferred signature:** `void StewardTick(StewardState* state)`
**Called from:** Per-frame tick loop, called each frame during active session.

**What it does:**
1. If param_1+0xa4: initializes session time
2. If param_1+0xa8: updates elapsed time
3. If SessionType < 7 (not race): computes remaining time, runs proximity update
4. If SessionType == 7 (race): switch on RacePhase (0-1, 2, 3, 4, 5-8):
   - Phases 0-1: pre-race initialization
   - Phase 2: formation lap handling
   - Phase 3: green flag / racing
   - Phase 4: pit window logic
   - Phases 5-8: post-race / cooldown

**Side effects:**
- Calls: FUN_004d0b20, FUN_00448330, FUN_004d2e50, FUN_004d1d80 (proximity), FUN_0044f460, FUN_0044f0e0, FUN_0045bde0, FUN_004d2260, FUN_0040dbc0, FUN_0040e170, FUN_004d2170, FUN_004d2300, FUN_00461cd0, FUN_004a0da0

### FUN_004bc4e0 — Lap Completion / Penalty Processing

**Inferred signature:** `void ProcessLapCompletion(VehicleStruct* vehicle, int param2, int param3, int isSector)`
**Called from:** Steward tick when vehicle crosses finish/sector line

**What it does:**
1. If param_4 != 0: sector timing — stores sector lap times, calls timing update
2. If param_4 == 0: lap completion
3. Session-specific dispatch (switch on SessionType DAT_007c56a4):
   - **Race (7):** Checks lap count vs TotalRaceLaps (DAT_008acf8c). Handles formation lap. DSQ for ignored Stop/Go penalties. Updates penalty countdown timers.
   - **Qualifying (6):** DSQ if exceeding time limit
   - **Practice (0):** Simple lap update
4. Sets DAT_008acfa0 (half-distance flag) when lap >= (total+1)/2
5. Updates param_1[0x10] penalty countdown array (stride 8, max param_1[0xf])

**Side effects:**
- Writes: DAT_008acfa0 (HalfDistanceFlag)
- Reads: DAT_008acf8c (TotalRaceLaps), DAT_008acf90 (RaceTimeOffset), DAT_008acf94 (RaceTimeThreshold), DAT_007c56a4 (SessionType), DAT_007c56a8 (RacePhase), DAT_007ce814 (qualifying DSQ enabled)
- Struct mutations: VehicleStruct.FinishPosition, VehicleStruct.FinishState, VehicleStruct.PenaltyCounter

### FUN_004a0fd0 — Session State Machine / Pause Handler

**Inferred signature:** `int SessionPauseHandler(VehicleStruct* playerVehicle)`
**Called from:** Per-frame during race, handles input/state transitions

**What it does:**
1. Exit flag check: runs vehicle cleanup, save check, returns 4
2. Escape/pause check: returns 6
3. Options menu check: returns 6
4. HUD disable toggle: increments counter, checks input binding
5. Timer expiry: decrements timer, triggers state transition
6. Process input bindings: calls FUN_004a0cb0 for post-race flow

**Side effects:**
- Calls: FUN_004bc330, FUN_0042bc10, FUN_004ef5a0, FUN_00404b60, FUN_00485b90, FUN_004a0cf0, FUN_00404f00, FUN_00404f30, FUN_004a0cb0

### FUN_004b9890 — Race Tick Advance / Frame Dispatch

**Inferred signature:** `void RaceTickAdvance(float deltaTime)`
**Called from:** Main session execution loop (FUN_0046bf10) each frame

**What it does:**
1. Guards on DAT_007ce254 (0 = session active)
2. Captures timer, clamps delta time
3. Calls vehicle tick loop for all vehicles (physics, AI, state)
4. Calls FUN_0042bbd0, FUN_0040cde0 for post-tick sync

**Side effects:**
- Advances all vehicle states by deltaTime
- Calls: FUN_0042d210, FUN_0040cd60, FUN_004b87c0, FUN_004b9cd0, FUN_004b9ce0, FUN_0040cde0, FUN_004b8bd0, FUN_004c8650, FUN_004b8ae0, FUN_0042bbd0, FUN_004b8940, FUN_004c8d60/70

### FUN_004c29f0 — UpdateRaceStateScoring

**Inferred signature:** `void UpdateRaceScoring(int param)`
**Called from:** Per-tick scoring update during race

**What it does:**
1. Gate check: only runs if SessionType == 7
2. Reads player position from vehicle struct
3. Calls scoring update functions
4. AI pace adjustment using AIDifficultySlider (DAT_007d01a0)
5. Time scale update
6. If RaceMode 3/4 (championship) AND vehicle is first: triggers race-end

**Side effects:**
- Calls: FUN_0042bc10, FUN_004c2bf0, FUN_004c2c40, FUN_004c2dc0, FUN_004c2d30, FUN_004c2c30

### FUN_00461610 — SessionConfigBuilder

**Inferred signature:** `void BuildSessionConfig(SessionConfigBitfield* config)`
**Called from:** Session setup, before session enter

**What it does:**
1. Gets scene name, extracts filename (last segment after `\`)
2. Strips file extension
3. Packs game configuration booleans into bitfield at param_1+0x76:
   - Reads from: DAT_007d0a44, DAT_007d0fc4, DAT_007d0c18, DAT_007d0d14, DAT_007d0014, DAT_007ceb10, DAT_007ce874, DAT_007ce88c, DAT_007ce958, DAT_007ce97c, DAT_007ced44, DAT_007cee40, DAT_007cef3c
4. Stores pit timers at +0x78 (ReconPitOpen) and +0x7A (ReconPitClosed)
5. Sets fuel level from DAT_007d108c (clamped 0–65535)
6. Selects session detail level via switch on DAT_007d0e50 (default 6, cases 1-4 map to 8/12/14/32)
7. Clamps detail to min/max bounds

**Side effects:**
- Writes: all packed bitfield values, pit timers, fuel level, detail level
- Calls: FUN_00415c30, FUN_004c5690, FUN_004336d0, FUN_004618d0, FUN_004615c0

### FUN_004bccc0 — Penalty Mechanics Engine

**Inferred signature:** `void ProcessPenalties(PenaltyState* state)`
**Called from:** Steward dispatch during race phase

**What it does:**
- Gated by DAT_007cef84 (PenaltiesEnabled) — if 0, all penalties disabled
- **Cut track:** Score threshold check. Practice/quali: fine + lap invalidated. Race 1st offense: warning. Race 2nd+: Stop/Go (10s) if cut score <= threshold.
- **Speeding in pitlane:** Race = Stop/Go. Practice/quali = fine based on excess speed integral.
- **Blue flags:** 3-stage timer accumulated at param_1[0x37]. Stage 1 warning at threshold1, Stage 2 urgent at threshold2, DSQ at threshold3. Resets on compliance.
- **Wrong way:** DSQ when wrong-way score exceeds threshold.

### FUN_004bc0e0 — Disqualification Handler

**Inferred signature:** `int ApplyDSQ(VehicleStruct* vehicle, int reasonCode)`
**Called from:** Penalty system, jumped start detection

**What it does:**
1. Guards: vehicle not already DSQ (param_1[0xc] != 3) AND vehicle active
2. Sets param_1[0xc] = 3 (DSQ state)
3. Creates "Disqualified: <reason>" message string
4. Increments DAT_0083ee60 (penalty count, max 0x3ff)
5. Advances DAT_008aae64 by 0x1b0 (penalty history stride)
6. Calls FUN_004b33b0 (vehicle event, code 4=DSQ, 0x1c)
7. Calls FUN_0041a940 (apply DSQ to vehicle)

### FUN_004bbd60 — Stop/Go Penalty Handler

**Inferred signature:** `int ApplyStopGo(VehicleStruct* vehicle, int reasonCode, float penaltySeconds)`
**Called from:** Penalty system, jumped start detection, cut track enforcement

**What it does:**
1. Guards: param_1[0xc] == 0 (no existing penalty)
2. Creates "Stop/Go Penalty: <reason>" message
3. Same penalty history array as DSQ (DAT_0083ee60, DAT_008aae64)
4. Calls FUN_004b33b0 (code 4, 0x17=StopGo)
5. Stores param_3 (penalty seconds) at penalty record+8
6. Calls FUN_0041a720 (apply Stop/Go to vehicle)

### FUN_004bc9b0 — Jumped Start / Grid Penalty Detection

**Inferred signature:** `void CheckJumpedStart(VehicleStruct* vehicle, int mode)`
**Called from:** Steward pre-race phase

**What it does:**
1. Reads vehicle velocity from +0x3500/+0x34fc/+0x34f8
2. Computes velocity magnitude squared
3. If param_2 == 0 (jumped start check):
   - Compares velocity to threshold. If moving: computes grid relative position
   - Computes dot product vs grid forward direction
   - If velocity below thresholds AND forward movement below threshold: no penalty
   - If velocity above threshold: displays warning
   - If PenaltiesEnabled AND not in pit: calls Stop/Go or DSQ
4. If param_2 != 0 (grid alignment check):
   - Compares velocity AND position offset to thresholds
   - If off-grid: displays warning message

### FUN_004a4110 — AI Overtaking / Aggression Probability

**Inferred signature:** `int CheckAIOvertakeProbability()`
**Called from:** Per-tick steering/AI dispatch

**What it does:**
1. Iterates vehicles, removes invalid entries
2. If any active vehicle with low ability: return 0 (no overtaking)
3. Session 7 race: return 1 (always allow overtaking)
4. Multi-stage probability using early/mid/late race phase
5. Probability modified by population density, driver ability, track multiplier

### FUN_004d24d0 — Race Results File Writer

**Inferred signature:** `void WriteRaceResultsFile()`
**Called from:** Post-race cleanup

**What it does:**
1. Builds results path from `Results\` + timestamp filename
2. If multiplayer: writes race timestamp
3. If singleplayer race session or multiplayer:
   - Writes `[Header]`: Game="F1 Challenge 99-02", Version=1.0, TimeString
   - Writes `[Race]`: RaceMode, Scene, AIDB, Qualify Laps, Race Laps, Race Time, Track Length
   - If multiplayer: writes `[Local Settings]` with all drive aids
   - Writes `[Results]`: per-driver sorted by finish position:
     - Driver name (+0x4620), Vehicle name (+0x4678)
     - Qualifying position/time, race finish position
     - Lap times via FUN_004bc2a0/FUN_004bc270
     - Best lap time, finish state, reason code, gap to leader

### FUN_004c6b60 — SessionTickUpdate

**Inferred signature:** `void SessionPerFrameUpdate()`
**Called from:** Per-frame during active session

**What it does:**
1. Calls timer update, track position update, pause check
2. If on-track: AI driver update, player-specific update
3. If off-track: AI recovery logic
4. If session 7 AND race phase 3/4: pit update

---

## Penalty System — Complete Logic Flow

```
RacePhase dispatch (FUN_004d4580)
  |
  +-- Cut track detection → FUN_004bccc0
  |     +-- Practice/Quali: fine + invalidate lap
  |     +-- Race 1st: warning (FUN_004bbc60)
  |     +-- Race 2nd+: Stop/Go 10s (FUN_004bbd60)
  |
  +-- Speeding in pitlane → FUN_004bccc0
  |     +-- Race: Stop/Go (FUN_004bbd60)
  |     +-- Practice/Quali: fine (FUN_004bba90)
  |
  +-- Blue flag → 3-stage timer
  |     +-- Timer accumulates at param_1[0x37]
  |     +-- Stage 1: warning at _DAT_0059e5fc seconds
  |     +-- Stage 2: urgent at _DAT_0059e8ec seconds
  |     +-- DSQ at _DAT_0059e468 seconds (FUN_004bc0e0)
  |     +-- Reset on compliance (car moves over)
  |
  +-- Wrong way → DSQ when score > _DAT_005acd88 (FUN_004bc0e0)
  |
  +-- Jumped start (FUN_004bc9b0)
        +-- Pre-green movement → Stop/Go (FUN_004bbd60)
        +-- "Not Lined Up Properly" → warning (FUN_0045bde0)
```

---

## Session Type Codes

| Value | Session | Default Duration | Pit Speed Limit |
|-------|---------|-----------------|-----------------|
| 0 | TestDay | no limit | NormalPitKPH |
| 1 | Practice1 | 3600s (1h) | NormalPitKPH |
| 2 | Practice2 | 3600s | NormalPitKPH |
| 3 | Practice3 | 2700s (45min) | NormalPitKPH |
| 4 | Practice4 | 2700s | NormalPitKPH |
| 5 | Practice5 | 3600s | NormalPitKPH |
| 6 | Qualifying | 1800s (30min) | RacePitKPH |
| 7 | Race | laps-based (DAT_007d05a0) | RacePitKPH |

---

## Race Phase Codes

| Phase | Meaning |
|-------|---------|
| 0 | Pre-race / initialization |
| 1 | Grid formation |
| 2 | Formation lap |
| 3 | Green flag / racing |
| 4 | Pit window |
| 5 | Post-race / cooldown |
| 6-7 | Post-race / results |
| 8 | Race completed / ceremony |

---

## Internal Call Graph

```
FUN_0046dc60 — Session State Machine  [triggered by: game state machine post-init]
  +-- FUN_0046bf10 — Main Session Loop
  |     +-- FUN_004beb10 — Frame Tick (looped until session ends)
  |     |     +-- FUN_004b9890 — Race Tick Advance (frame dispatch)
  |     |     |     +-- FUN_004b87c0 — Session frame tick
  |     |     |     +-- FUN_004b9cd0 — Per-vehicle update
  |     |     |     +-- FUN_004c6b60 — Session tick update
  |     |     |     +-- FUN_004d4580 — Steward main dispatch
  |     |     |           +-- FUN_004d1d80 — Proximity/gap tracking
  |     |     |           |     +-- FUN_004e9630 — Position query
  |     |     |           |     +-- FUN_004d1730 — Penalty system logging
  |     |     |           +-- FUN_004d2170 — All clear check
  |     |     |           +-- FUN_004d2300 — Particle trigger
  |     |     |           +-- FUN_004a0da0 — Session advance
  |     |     +-- FUN_0040cde0 — Steward notify
  |     |     +-- FUN_0042bbd0 — Player index set
  |     +-- FUN_004c8d80 — Render/display update
  |     +-- FUN_004988c0 — Session render dispatch
  
FUN_004a0fd0 — Session Pause Handler  [triggered by: per-frame input during race]
  +-- FUN_004bc330 — Vehicle cleanup check
  +-- FUN_004ef5a0 — Timing freeze
  +-- FUN_004a0cb0 — Post-race check
        +-- FUN_004a0c60 — Advance session state

FUN_004bc4e0 — Lap Completion / Penalty Processing  [triggered by: finish/sector line]
  +-- FUN_004bc240 — Standings update (non-race)
  +-- FUN_0042d140 — Formation lap handler
  +-- FUN_004bc240 — State machine transition

FUN_004bccc0 — Penalty Mechanics Engine  [triggered by: steward phase dispatch]
  +-- FUN_004bbc60 — Warning handler (1st offense cut, blue flag stage 1)
  +-- FUN_004bbd60 — Stop/Go penalty handler (2nd+ cut, speeding, jumped start)
  +-- FUN_004bc0e0 — DSQ handler (blue flag stage 3, wrong way, ignored stop/go)

FUN_00461610 — SessionConfigBuilder  [triggered by: pre-session setup]
  +-- FUN_004c5690 — Scene config access
  +-- FUN_004336d0 — String processing
  +-- FUN_004618d0 — String processing
  +-- FUN_004615c0 — Vehicle ID setup
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 12 | FUN_004b1190 | Default RaceLaps |
| 5 | FUN_004b1190 | Default QualifyLaps |
| 15 | FUN_004b1190 | Default pit window width |
| 0x68 (104) | FUN_004c02d0, FUN_004c0260 | Max qualifying entries |
| 0x30 (48) | FUN_004c03f0 | Max races in standings |
| 103 | FUN_004c0cc0 | Max opponent entries per season |
| 0x3ff (1023) | FUN_004bc0e0 | Max penalty count / particle slots |
| 0x7fffffff | FUN_004d0f10 | DNF sentinel for BestTime |
| 7200.0 | FUN_004d0f10 | Max session time (2 hours) |
| 0x52 (82) | FUN_004d1670 | Pit/flag indicator slots |
| 600.0 | FUN_004be760 | Default finish time estimate |
| 1.15 | FUN_004be760 | 2nd car inclusion threshold |
| 0.97 | FUN_004be760 | Finish time floor clamp |
| 9000.0 | FUN_004be760 | Fastest lap sanity bound |
| 3 | FUN_004a47e0 | Pit service: WING type ID |
| 4 | FUN_004a47e0 | Pit service: DAMAGE type ID |
| 0x1b0 | FUN_004d24d0 | Penalty history stride |
| 0x48c0 | various | SeasonScoringDB entry stride |
| 0x424 | various | VehicleArray stride |
| 0x18c | various | SceneArray stride |
| 0x1230 | various | VehicleGridArray stride |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007d0410` (RaceMode) — from docs/12, controls championship vs single race flow
- `DAT_007d01a0` (AIDifficultySlider) — from docs/12, AI pace adjustment in scoring
- `DAT_007d0b28` (MultiplayerFlag) — from docs/12, gates multiplayer-specific code paths
- `DAT_007d0b64` (FuelMult) — from docs/12, written to results file
- `DAT_007d0c60` (TireWearMultiplier) — from docs/12, written to results file
- `DAT_007cea5c` (EngineWearMode) — from docs/12, written to results/config
- `DAT_007cebc4` (FormationLap) — from docs/12, gates formation lap logic
- `DAT_007ce958` (TireModelMode) — from docs/12, packed into session config bitfield
- `DAT_007cf080` (WeatherMode) — from docs/12, read in session config
- `DAT_007ce5d0` (CurrentTrackPath) — from docs/12, scene/track name for results
- `DAT_008acf9c` (TotalRaceLaps) — from docs/12, compared against completed laps
- `DAT_005ef9a0` (VehicleGridArray) — from docs/12, grid/position array for monitor
- `DAT_007c54f0` (VehiclePtrArray) — from docs/12, main vehicle access
- `DAT_005c329c` (VehicleCount) — from docs/12, iteration bound
- `DAT_007c54e8` (PlayerVehiclePtr) — from docs/12, player vehicle
- `DAT_005bf9b0` (DriverDataTable) — from docs/12, driver lookup for messages

**Calls into:**
- docs/04-tire-system: no direct calls (tire data referenced but called via physics dispatch)
- docs/03-engine-wear-damage: FUN_004a5c80, FUN_0041a940, FUN_0041a720 (penalty application on vehicle)
- docs/10-vehicle-physics: FUN_004ef5a0 (timing freeze), FUN_004e9630 (position query), FUN_004efb20 (world position)
- docs/19-renderer: FUN_004f9b70 (Bink video play), FUN_0049b370 (text render)
- docs/21-audio-network-internals: FUN_004b33b0 (audio event dispatch), FUN_004144f0/FUN_00418560 (commentary)
- docs/09-track-system: FUN_004c5840 (scene data), FUN_005679c0/FUN_00567970 (INI field read)
- docs/08-file-formats: FUN_00566940/FUN_00566b90/FUN_005668d0 (file I/O)
- docs/20-math-utilities: FUN_0058815f (format), FUN_0058957a (time conversion)

**Called by:**
- docs/01-engine-architecture: Game state machine calls session enter functions and state machine
- docs/07-pit-system: Pit stop handling interacts with steward penalty system
- docs/02-ai-system: AI overtaking calls into session position tracking

---

## Reimplementation Notes

1. **SessionType 7 (race) is the most complex path** — all penalty enforcement, lap counting, phase transitions, and scoring only run during race sessions. Non-race sessions (0-6) use simplified timers and no penalty dispatch.

2. **RacePhase state machine ordering matters** — Phase 2 (formation lap) must complete before Phase 3 (green flag). Phase 4 (pit window) must be entered after green flag. Phases 5-8 are post-race and irreversible.

3. **Penalty system is gated by a single global** — `DAT_007cef84` (PenaltiesEnabled). When 0, all penalty code paths are skipped. This must be checked before any penalty application.

4. **DAT_008acfa0 (HalfDistanceFlag)** is set in `FUN_004bc4e0` when lap >= (total+1)/2. This flag enables half-distance race finish rules and hotlap recording.

5. **Commentary system uses ring buffer (DAT_008aae70)** for variety. Commentary IDs are hardcoded per event type and per driver (player vs AI). The reimplementation can use a simpler event system.

6. **Stall/DNS mechanic** is evaluated per driver on race start laps 1-2. `StartStalls` from `.rcd` is a 0.0-1.0 probability. 10% of stall triggers become DNS (Did Not Start), 90% are regular grid stalls.

7. **Scripted events mode** (`DAT_007cea5c == 3`) reads `Script` field from `.rcd` pointing to a `RaceEvents` section. Each event type has a lap range. Failure types map to ISIMotor retirement codes.

8. **Session config bitfield** is built from globals and written back to globals. This two-step process (build + writeback) allows validation/clamping between stages.

9. **Replay system** has its own state machine with states 0-2. It opens VCR files, streams packet data, and manages replay buffers. The replay system is parallel to the live session system.

10. **The 107% rule is NOT implemented** — `FUN_004be760` is a finish time predictor, not a qualifying cutoff filter. No lap time minimum exists for AI race eligibility.

11. **Grid data structure** — `DAT_005ef9a0` is a vehicle grid array with stride 0x1230, indexed by team ID. Entry +0x57d bit 1 is a "monitored" flag for HUD display. Entries can be -1 (empty slot).

12. **SessionType 5** is a special server session used by multiplayer. It interacts with NetComm and peers.

---

## Completeness

- Full specs written: ~30 / ~845 total documented functions
- Functions primarily covered: all major entry points (state machine, steward dispatch, penalty system, session config, lap completion, AI overtaking, race results)
- Thunks/empty stubs omitted: ~50 (replay helpers, message display wrappers, format utilities)
- Omitted from spec: individual HUD rendering sub-functions (~80 tacho/display helpers), HTML results writers (~15 functions), commentary sub-functions (~20), file I/O wrappers (~30), timer formatting (~15), string/name helpers (~40)
- Confidence: **high** — core architecture is well-understood from 845 documented functions, call graph analysis, and cross-reference with docs/12 and docs/13
