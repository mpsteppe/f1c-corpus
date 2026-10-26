# Implementation Spec: Session and Race Logic (Part 1)

Source: docs/06-session-race-logic.md  |  Functions: 429 (Part 1: ~200)  |  Date: 2026-07-15

---

## Overview

The Session and Race Logic system manages the full lifecycle of game sessions — practice, qualifying, race, and post-race — across singleplayer and multiplayer modes. It owns the steward/referee logic (penalties, timing, standing computation), replay save/load, race results output, session configuration, and all HUD/monitor/renderer integration for race-state display.

**When it runs:** Session logic executes throughout the game loop — per-frame updates (race tick, steward dispatch, AI state checks), on-event triggers (lap completion, overtakes, penalties), session entry/exit transitions, and file I/O for results/replay.

**Key globals it owns:** `DAT_007c56a4` (SessionType, 0-7), `DAT_007c56a8` (RacePhase, 0-8), `DAT_007cef84` (PenaltiesEnabled), `DAT_007d0410` (RaceMode), `DAT_007d0308` (RaceActiveFlag), `DAT_007cebc4` (FormationLap), `DAT_008acf9c` (TotalRaceLaps), `DAT_007d0b28` (MultiplayerFlag), `DAT_007d0b64` (FuelMult), `DAT_007d0c60` (TireWearMultiplier).

**Data structures:** The VehicleStruct (stride 0x48C0) holds per-vehicle race state: finish position (+0x4060), finish state (+0x4064, 0=running/1=finished/2=DNF/3=DSQ), reason code (+0x4068), best lap time (+0x409c), season points (+0x403c), qualifying position/time (+0x4058/0x405c), driver name (+0x4620), team ID (+0x4894). The ScoringDB/StandingsEntry (stride 0x1B4, max 103 entries) holds season-wide data. The SessionStruct holds timer state, active flag, and sector flags.

**Interface with other systems:** AI system (reads ability scores at +0x1130-0x1140, overtaking probability), physics (reads velocity/position at +0x3500), audio (fire commentary events via ring buffer), renderer (HUD text/tacho), file I/O (results.txt, replay VCR, hot lap .HOT), network (multiplayer session sync).

---

## Data Structures

### VehicleStruct (param_1 pattern, stride 0x48C0)

The primary per-vehicle data structure. Used by ~50+ functions in session/race logic.

```c
struct VehicleStruct {
    /* +0x0000 */ void* vtable;            // MSVC object header
    /* +0x0008 */ float PositionX;          // World position
    /* +0x000C */ float PositionY;
    /* +0x0010 */ float PositionZ;
    /* +0x0014 */ float Orientation[4];     // Quaternion (x,y,z,w)
    /* +0x0020 */ float RotationMatrix[3][3]; // Column-major, 9 floats
    
    // --- AI/Driver Data ---
    /* +0x1130 */ float QualifyingAbility;  // AI driver ability
    /* +0x1138 */ float RaceAbility;
    /* +0x1140 */ float RainAbility;
    /* +0x1142 */ byte   LapTypeFlag;
    /* +0x114F */ float  LiveLapRatio;
    /* +0x11F0 */ float  TrackAggression;
    /* +0x1200 */ float  CorneringAdd;
    /* +0x1208 */ float  CorneringMult;
    
    // --- Race State ---
    /* +0x34F8 */ float VelocityZ;          // World velocity component
    /* +0x34FC */ float VelocityY;
    /* +0x3500 */ float VelocityX;
    /* +0x3990 */ float CurrentSpeed;
    /* +0x39F8 */ int    TireStateFlag;
    
    // --- Session/Race Fields ---
    /* +0x403C */ int    SeasonPoints;       // Championship points
    /* +0x4044 */ float  PenaltyFloat;       // Accumulated penalty time
    /* +0x4058 */ int    QualifyingPosition; // Starting grid position
    /* +0x405C */ float  QualifyingTime;     // Best qualifying lap
    /* +0x4060 */ int    FinishPosition;     // 1=winner, 0=dnf
    /* +0x4064 */ int    FinishState;        // 0=running,1=finished,2=DNF,3=DSQ
    /* +0x4068 */ int    ReasonCode;         // Retirement reason code
    /* +0x406C */ int    PenaltyCounter;     // Accumulated penalty count
    /* +0x409C */ float  BestLapTime;        // Fastest lap
    
    // --- Identity ---
    /* +0x4620 */ char   DriverName[64];     // Wide string
    /* +0x4678 */ char   VehicleDescription[]; // Car description
    /* +0x46F8 */ char   DriverNameAlt[];
    /* +0x4710 */ uint   NameHash;
    /* +0x4714 */ char   FilePath[];         // Path to vehicle file
    /* +0x4894 */ int    TeamID;             // -1=unassigned
    /* +0x489C */ int    DriverNumber;
};
// Total size: 0x48C0 bytes (confirmed from stride)
// Accessed via: DAT_007c54f0 (VehiclePtrArray, stride 8) or param_1 pattern
```

### ScoringDB / StandingsEntry (Season data, stride 0x1B4)

```c
struct StandingsEntry {
    /* +0x000 */ int    CategoryID;          // -1=unset
    /* +0x004 */ int    Reserved0;
    /* +0x010 */ float  Weight;              // ~1.875
    /* +0x018 */ int    FinishPosition[48];  // Max 48 races
    /* +0x0D8 */ int    FinishPoints[48];    // Points per race
    /* +0x198 */ int    SeasonPoints;        // Accumulator A
    /* +0x19C */ int    PointsPosition;      // Accumulator B
    /* +0x1A0 */ int    PolesTaken;          // Accumulator C
    /* +0x1A4 */ int    OriginalGridPosition;
    /* +0x1A8 */ int    CurrentGridPosition;
    /* +0x1AC */ int    ControlType;
    /* +0x1B0 */ byte   Active;              // Bool, stride 0x1B4
};
// Base: DAT_007d2e48 (SeasonScoringDB), stride 0x48C0 between entries
```

### SessionStruct / Timers

```c
struct SessionStruct {
    /* +0x14 */  int    ActiveFlag;          // Non-zero = active
    /* +0x24 */  int    Count1;
    /* +0x30 */  int    Count2;
    /* +0x3C */  int    Count3;
    /* +0x44 */  void*  ListHead;            // Session entries list
    /* +0x48 */  int    ListCount;
    /* +0xAC */  int    BestTime;            // 0x7FFFFFFF = DNF
    /* +0xB8 */  float  MaxSessionTime;      // 7200.0 (2 hours)
    /* +0xBC */  float  TimeMultiplier;      // 1.0
    /* +0x128 */ int    SectorFlags[26];     // Initialized to -1
    /* +0x180 */ byte   StateFlag;
    /* +0x184 */ int    SessionState;        // 0=idle, 1=active, 4=finished
    /* +0x190 */ short  LapCount;
    /* +0x192 */ byte   CurrentSector;
    /* +0x280 */ int    PitWindowHistory[52]; // Zeroed
};
```

### ReplaySaveStruct

```c
struct ReplaySaveStruct {
    /* +0x6C0 */ void*  ListHead;            // Sorted linked list anchor
    /* +0x6C4 */ void*  ListTail;
    /* +0x6C8 */ void*  ListCursor;          // Iterator position
    /* +0x6CC */ int    ListCount;
    /* +0x6D0 */ byte   DirtyFlag;           // 1=sorted, set on change
    /* +0x6E4 */ int    ReplayDataPresent;   // Flag
    /* +0x700 */ int    SaveState;           // 0/1
    /* +0x70C */ char   TrackName[];         // File path base
    /* +0x714 */ void*  EntryLinkedListHead;
    /* +0x71C */ void*  EntryLinkedListTail;
    /* +0x9A4 */ int    SubfolderIndex;      // 0-4
    /* +0xF30 */ float  LapTimeStart;
    /* +0xF34 */ float  LapTimeEnd;
    /* +0xF94 */ char   OutputFilePath[];
};
```

### PenaltyStruct (per-vehicle penalty state)

```c
struct PenaltyState {
    /* +0x00 */ int    State;      // 0=none, 1=stop/go pending, 3=DSQ
    /* +0x04 */ int    OffenseCount; // Number of cut-track offenses
    /* +0x08 */ float  BlueFlagTimer; // Accumulated time ignoring blue flags
    /* +0x0C */ int    Enabled;
    /* +0x10 */ int    PenaltyCountdown[8]; // Stride 8, max entries from param_1[0xF]
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007c56a4 | int | SessionType | 7=race, 6=quali, 0-5=practice |
| DAT_007c56a8 | int | RacePhase | 0-8 race phase state machine |
| DAT_007cef84 | int | PenaltiesEnabled | 0=penalties disabled |
| DAT_007d0410 | int | RaceMode | 3/4=championship, 5=multiplayer |
| DAT_007d0308 | int | RaceActiveFlag | 1=race session active |
| DAT_007cebc4 | int | FormationLap | 1=formation lap enabled |
| DAT_008acf9c | int | TotalRaceLaps | Configured in session setup |
| DAT_008acf90 | int | RaceTimeOffset | Time offset for session timing |
| DAT_008acf94 | int | RaceTimeThreshold | Time threshold for race end |
| DAT_008acfa0 | byte | HalfDistanceFlag | Set at lap >= (total+1)/2 |
| DAT_007d0b28 | int | MultiplayerFlag | Non-zero = active multiplayer |
| DAT_007d0b64 | float | FuelMult | Fuel consumption multiplier |
| DAT_007d0c60 | float | TireWearMultiplier | Tire wear rate multiplier |
| DAT_007cec30 | float | ReconPitOpen | Pit window open time (s) |
| DAT_007cec54 | float | ReconPitClosed | Pit window close time (s) |
| DAT_0083ee60 | int | PenaltyHistoryCount | Count of penalty events (max 0x3FF) |
| DAT_008aae64 | int | PenaltyHistoryOffset | Stride 0x1B0 per entry |
| DAT_007d2e48 | ptr | SeasonScoringDB | Base of standings database |
| DAT_005ef9a0 | int[] | VehicleGridArray | Stride 0x1230, grid positions |
| DAT_007c54dc | int | CurrentPlayerIndex | Index into VehiclePtrArray |
| DAT_007c54e4 | int | PlayerVehicleIndexAlt | Alternate vehicle index |
| DAT_007c54e8 | ptr | PlayerVehiclePtr | Pointer to player vehicle |
| DAT_007c54f0 | ptr[] | VehiclePtrArray | Array of vehicle pointers (max 0x68) |
| DAT_005c329c | int | VehicleCount | Number of vehicles in session |
| DAT_007ce254 | byte | DisableHUDFlag | Set to skip HUD rendering |
| DAT_007d0b10 | int | MultiplayerPenaltyFlag | Singleplayer/multiplayer fine mode |
| DAT_007ce814 | int | QualifyingDSQEnabled | Qualifying time-limit DSQ |
| DAT_007cf3c8 | int | TrackConditionState | Track state (affects tire model) |

---

## Public API — Entry Points

### FUN_0046dc60 — Session State Machine (Main Session Orchestrator)

**Inferred signature:** `int SessionStateMachine(SessionStruct* session)`
**Called by:** Game state machine per tick during active session
**Called from (callers.json):** (check callers.json)

**What it does:**
1. Checks if async loading complete (FUN_004c8d80)
2. If SessionType 5 (Qualifying) + FormationLap flag: runs session via FUN_0046bf10, then calls FUN_004d2450 (first uninitialized vehicle activation)
3. Sets DAT_005cc9e8 = 4 when session completes
4. Guards: FUN_00461db0 (check async operations), FUN_0042d210 (input disable)

**Side effects:**
- Writes: DAT_005cc9e8 (session init state) = 4 on completion
- Reads: SessionType (DAT_007c56a4), FormationLap (DAT_007cebc4)
- Delegates to: FUN_0046bf10 (main execution loop), FUN_004a0590 (session type dispatch), FUN_00462850 (transition guard)

**Calls (from call_graph.json):** FUN_004c8d80, FUN_00461db0, FUN_0042d210, FUN_0046bf10, FUN_004d2450, FUN_00497250, FUN_004a0590, FUN_00461dc0, FUN_00462850

---

### FUN_0046bf10 — Main Session Execution Loop

**Inferred signature:** `int SessionRunLoop()`
**Called by:** FUN_0046dc60 (session state machine)

**What it does:**
1. Sets time threshold based on SessionType (practice/quali have time limits, race has lap count)
2. Loops calling FUN_004beb10 (frame tick) until session completion
3. If race mode: cleanup via DAT_005eb10c vtable dispatch
4. Returns 0 when done

**Side effects:**
- Runs full game frame tick (physics, AI, rendering, steward)
- Writes session time completion

**Calls (from call_graph.json):** FUN_004be6f0, FUN_004c8d80, FUN_004988c0, FUN_004beb10, FUN_00496880, FUN_00497250, FUN_00496e90, FUN_004186a0, FUN_0041d630, FUN_004b0170

---

### FUN_004d4580 — Steward Update Main Dispatch

**Inferred signature:** `int StewardUpdate(SessionStruct* param_1)`
**Called by:** Main game frame tick per-frame during session

**What it does:**
- Main steward tick: manages session start, pit timer, penalty, phase logic
- If param_1+0xA4: session time init
- If param_1+0xA8: elapsed time update
- If SessionType < 7 (non-race): compute remaining time, proximity update
- If SessionType 7 (race): switch on RacePhase (0-1, 2, 3, 4, 5-8) — handles formation lap, FCY, green flag, pit window, post-race

**Calls (14 total):** FUN_004d0b20, FUN_00448330, FUN_004d2e50, FUN_004d1d80, FUN_0044f460, FUN_0044f0e0, FUN_0045bde0, FUN_004d2260, FUN_0040dbc0, FUN_0040e170, FUN_004d2170, FUN_004d2300, FUN_00461cd0, FUN_004a0da0

---

### FUN_004c6b60 — Session Tick Update (Per-Frame Dispatch)

**Inferred signature:** `int SessionTickUpdate()`
**Called by:** Main game loop per frame during active session

**What it does:**
- Per-frame update: timer, track position, pause check
- On-track branch: AI driver update, player-specific update
- Off-track branch: AI recovery path
- If SessionType 7 + phase 3/4: pit update

**Calls (11 total):** FUN_004bb8e0, FUN_004d1180, FUN_004bc9b0, FUN_004ef7c0, FUN_004e9600, FUN_004f1c00, FUN_004a5e60, FUN_004a5e80, FUN_0040d100, FUN_00424b20, FUN_004efa40

---

### FUN_004a0fd0 — Session Pause/Exit Handler

**Inferred signature:** `int SessionPauseHandler()`
**Called by:** Main game loop, handles user input during race

**What it does:**
- Exit flag check: vehicle cleanup, save check, return 4
- Escape/pause: return 6
- Options menu: return 6
- HUD toggle: increment counter, check input
- Timer expiry: decrement, transition
- Process input bindings, call FUN_004a0cb0 (post-race check)

**Calls:** FUN_004bc330, FUN_0042bc10, FUN_004ef5a0, FUN_00404b60, FUN_00485b90, FUN_004a0cf0, FUN_00404f00, FUN_00404f30, FUN_004a0cb0

---

### FUN_004bc4e0 — Lap Completion / Penalty Processing

**Inferred signature:** `int ProcessLapComplete(VehicleStruct* vehicle, int param2, int param3, int param4)`
**Called by:** Steward system on lap completion events

**What it does:**
- param_4 != 0: sector timing — stores lap times, calls timing update
- param_4 == 0: lap completion
- Session-specific handling (switch on DAT_007c56a4):
  - **Race (7):** Check lap count vs DAT_008acf8c (total laps). Handle formation lap (FUN_0042d140). DSQ for ignored Stop/Go penalties ("Ignored Stop/Go Penalty"). Update penalty countdown timers.
  - **Qualifying (5):** DSQ if exceeding time limit
  - **Practice (0):** Simple lap update
- Sets DAT_008acfa0 (half-distance flag) when lap >= (total+1)/2
- Updates param_1[0x10] penalty countdown array (stride 8, max param_1[0xF])
- Calls FUN_004bc240 (standings update)

**Moddability:** `configurable` — penalty thresholds, lap count

---

### FUN_004bccc0 — Race Penalties Engine

**Inferred signature:** `int ApplyPenalties(PenaltyState* state, VehicleStruct* vehicle)`
**Source:** steward.cpp
**Gate:** DAT_007cef84 (PenaltiesEnabled) — 0 = fully disabled

**What it does:**
- **Cut track:** Score threshold at _DAT_0059e944. Practice/Qualifying: fine + lap invalidated. Race 1st offense: warning only. 2nd+ offense (param_1[0x34] >= 2 and cut score <= _DAT_005acb30): Stop/Go (10s)
- **Speeding in pitlane:** Race: Stop/Go (10s). Practice/Qualifying: fine = excess_speed_integral * rate + base_fine
- **Blue flags (3-stage timer):** param_1[0x37] accumulates time. Stage 1 (warning) at _DAT_0059e5fc, Stage 2 (urgent) at _DAT_0059e8ec, DSQ at _DAT_0059e468. Counter resets on compliance.
- **Wrong way:** DSQ when wrong-way score exceeds _DAT_005acd88

**Constants:** Stop/Go duration = 10 seconds (hardcoded)

---

### FUN_004bc0e0 — Disqualification Handler

**Inferred signature:** `int ApplyDSQ(PenaltyState* state, VehicleStruct* vehicle, char* reason)`

**What it does:**
- Only if not already DSQ (param_1[0xC] != 3) AND vehicle active
- Sets param_1[0xC] = 3 (DSQ state)
- Creates "Disqualified: <reason>" message
- Increments DAT_0083ee60 (penalty count, max 0x3FF)
- Advances DAT_008aae64 by 0x1B0 (penalty history stride)
- Calls FUN_004b33b0 (vehicle event, code 4=DSQ, 0x1C)
- Calls FUN_0041a940 (apply DSQ to vehicle)

---

### FUN_004bbd60 — Stop/Go Penalty Handler

**Inferred signature:** `int ApplyStopGo(PenaltyState* state, VehicleStruct* vehicle, char* reason)`

**What it does:**
- Only if param_1[0xC] == 0 (no existing penalty)
- Creates "Stop/Go Penalty: <reason>" message
- Same penalty history array as DSQ
- Calls FUN_004b33b0 (code 4, 0x17=StopGo)
- Stores param_3 at penalty record+8
- Calls FUN_0041a720 (apply Stop/Go to vehicle)

---

### FUN_004bc9b0 — Jumped Start / Grid Penalty Detection

**Inferred signature:** `int CheckJumpedStart(VehicleStruct* vehicle, int checkMode, int param3)`

**What it does:**
- param_2 == 0 (jumped start check): reads velocity at +0x3500, compares to threshold _DAT_0059e43c. If moving: computes dot product of movement vs grid forward direction. Multi-threshold system with _DAT_005acd70 (stopped), _DAT_0059f124 (forward movement), _DAT_0059e908 (reverse direction). Calls FUN_004bbd60 or FUN_004bc0e0 with "Jumped start" when PenaltiesEnabled != 0.
- param_2 != 0 (grid alignment check): compares velocity and position offset to threshold. Displays "Not Lined Up Properly" warning.

**Vehicle offsets read:** +0x34F8 (VelocityZ), +0x34FC (VelocityY), +0x3500 (VelocityX), +0x34C4 (GridForwardX), +0x34D0 (GridForwardY), +0x34DC (GridForwardZ)

---

### FUN_004ba1f0 — Replay Playback Loader

**Inferred signature:** `int ReplayLoad(ReplaySaveStruct* replay)`
**Called from:** Game UI when user selects "Watch Replay"

**State machine (param_1[0]):**
- **0/1:** Check conditions — if FUN_00404f10() false and (DAT_007d0038 != 0 or DAT_007d005c != 0), set state=1 and return
- **2:** Active loading:
  1. Assert via FUN_004d7a50
  2. Open VCR file via FUN_00566b20 from path at param_1[2]+0xF94
  3. Display "Prepping Replay" + Sleep(250ms)
  4. Allocate replay buffer (0x80 bytes)
  5. Open output file via FUN_00566940
  6. Loop: FUN_00566c00 (read) → FUN_00566bd0 (process packet)
  7. Close files
  8. If success: set state=2, call FUN_004b9da0(5)
  9. Call FUN_004b87a0 / FUN_004b86e0 for replay data init

**Calls (from call_graph.json, 19 total):** FUN_004d7a50, FUN_00566b20, FUN_00566940, FUN_00423a00, FUN_004a0e70, FUN_004b9830, FUN_00568540, FUN_004b97d0, FUN_004b9810, FUN_004b9da0, FUN_004b9820, FUN_0042bbd0, FUN_0042bc40, FUN_004b87a0, FUN_004b86e0, FUN_00566c00, FUN_00566bd0

---

### FUN_004b7500 — Replay Save State Machine

**Inferred signature:** `int ReplaySave(ReplaySaveStruct* replay)`

**What it does:**
- Guards on replay data present flag (+0x6E4)
- **First-time save** (+0x700 == 1): 0x68 iterations of FUN_004b6190 (car state capture), FUN_004b7a00 (header), then if conditions met: display "Saving Replay" + Sleep(100ms), open file, write lap data, stream car states, close
- **Flag set** (+0x700 != 1 AND +0x6D0 != 0): clear flag, display message, open file at +0xF94 path, write header, iterate linked list at +0x714 writing each entry
- **Flag not set** (+0x700 != 1 AND +0x6D0 == 0): close file, no-op
- Final: clear +0x700, call FUN_004b5f60

---

### FUN_00461610 — Session Config Builder

**Inferred signature:** `int BuildSessionConfig(void* configStruct)`

**What it does:**
- Gets scene name (last segment after `\`, stripped after `.`)
- Packs game configuration booleans into bitfield at param_1+0x76 (driving aids, TireModelMode, damage multiplier)
- Stores pit timers at +0x78 (ReconPitOpen) and +0x7A (ReconPitClosed)
- Sets fuel level from DAT_007d108c (clamped 0-65535)
- Selects session detail level: switch on DAT_007d0e50 (default 6, cases 1-4 → 8/12/14/32)
- Writes remaining session config globals

**Globals read (22+):** DAT_007d0a44, DAT_007d0fc4, DAT_007d0c18, DAT_007d0d14, DAT_007d0014, DAT_007ceb10, DAT_007ce874, DAT_007ce88c, DAT_007ce958 (TireModelMode), DAT_007ce97c, DAT_007ced44, DAT_007cee40, DAT_007cef3c, DAT_007cec30, DAT_007cec54, DAT_007d108c, DAT_007d0e50, DAT_007d0e98, DAT_007d0ea0, DAT_007d0ea4

**Moddability:** `configurable` — all values read from setup globals

---

### FUN_004d24d0 — Race Results File Writer

**Inferred signature:** `int WriteRaceResults()`

**What it does:**
- Builds results path as `Results\YYYY_MM_DD_HH_MM_SS.txt`
- Writes `[Header]`: Game, Version, TimeString
- Writes `[Race]`: RaceMode, Scene, AIDB, QualifyLaps, RaceLaps, RaceTime, TrackLength
- If multiplayer: writes `[Local Settings]` with all drive aids, MechFail rate, multipliers
- Writes `[Results]` per driver sorted by finish position: driver name, vehicle, qualifying position/time, finish position, lap times, best lap, finish state, gap to leader
- Reads vehicle struct fields: +0x4620 (name), +0x4678 (vehicle), +0x4058/0x405C (quali pos/time), +0x4060 (finish pos), +0x409C (best lap), +0x4064 (finish state), +0x4068 (reason), +0x40B8 (race time)

---

### FUN_004c29f0 — Update Race State Scoring (Per-Tick)

**Inferred signature:** `int RaceScoringTick()`

**What it does:**
- Gate check, SessionType 7 only
- Reads player position, calls scoring update
- AI adjustment via AIDifficultySlider, time scale update
- If RaceMode 3/4 and player first: race-end trigger

**Calls:** FUN_0042bc10, FUN_004c2bf0, FUN_004c2c40, FUN_004c2dc0, FUN_004c2d30, FUN_004c2c30

---

### FUN_004c1050 — Init All Drivers (Session Start)

**Inferred signature:** `int InitAllDrivers(ScoringDB* db)`

**What it does:**
- Resets UI theme, calls FUN_004c0850 (copy driver data to scoring DB)
- Loops 103 sub-slots, clears unused scoring slots
- Stores GameState from param_1+0xB14C
- Loads path strings for validation

**Calls:** FUN_004c11d0, FUN_004c11e0, FUN_004c55b0, FUN_004c54f0, FUN_004c0850, FUN_004c1370, FUN_004ef5a0, FUN_004b1190, FUN_00566650, FUN_00415730

---

### FUN_004b1190 — Session Config Loader (RaceLaps, QualifyLaps, Pit Window)

**Inferred signature:** `int LoadSessionConfig(VehicleStruct* vehicle)`

**What it does:**
- Sets defaults: RaceLaps=12, QualifyLaps=5, Pits field width=15
- Reads string at param_1+0x154 (track name)
- Looks up INI keys: "QualifyLaps", "RaceLaps", "Recon_Pit_Open", "Recon_Pit_Closed", "RaceTime"
- Clamps values to min/max bounds

**Writes globals:** DAT_007cec30 (pit open), DAT_007cec54 (pit close)

---

### FUN_004a4110 — AI Overtaking / Aggression Probability

**Inferred signature:** `int AIOvertakeProbability()`

**What it does:**
- Iterates vehicles, removes invalid entries
- If any active with low ability: return 0
- Session 7 (race): return 1 (always overtake)
- Multi-stage probability: early/mid/late race
- Probability modified by population, ability, track multiplier

**Calls:** FUN_0042add0, FUN_00426cc0, FUN_0042ae90, _rand

**Moddability:** `configurable` — many probability constants

---

### FUN_004a0760 — Win Videos Playback

**Inferred signature:** `int PlayWinVideos()`

**What it does:**
- If escape not pressed, player mode==1, videos enabled (DAT_007d032c==1):
  - Builds `<track_path>\winRace.bik` and plays via FUN_004f9b70
- If championship won: builds `<track_path>\windrivers.bik` and plays
- Calls championship check via FUN_004c2850 / FUN_004c15a0

**Bink video patterns:** `<track_dir>\winRace.bik`, `<track_dir>\windrivers.bik`, `<track_dir>\FIAShort.bik`, `<track_dir>\winconstructors.bik`

---

### FUN_0041ac50 / 0041ad80 / 0041afd0 / 0041b190 / 0041b250 — Commentary System

**Source:** session/commentary. Fires audio commentary events based on race events.

**Key dispatch:**
- FUN_0041ac50: Race event sound — IDs 0xD0, 0xD3-0xD9, 0xDC based on event type
- FUN_0041ad80: Overtake/position swap — random select ID 0x72 (passed) or 0x73 (was passed)
- FUN_0041afd0: Per-car event commentary — player: IDs 0x6A-0x6F, AI: IDs 0xDD-0xDF
- FUN_0041b190: Race-end commentary — ID 0x4D
- FUN_0041b250: Penalty reason commentary — player ReasonCode mapping, AI mapping

**Core pattern:** FUN_004144d0 (audio dispatch) → FUN_004144f0 (check guard) → FUN_00418560 (queue event)

---

### FUN_0049d5d0 / 0049de40 / 0049e670 / 0049e7b0 / 0049f170 — HUD Tachometer System

**Source:** game_logic/HUD. Tachometer rendering pipeline.

**Key dispatch:**
- FUN_0049d5d0: Dispatch switch on DAT_007ce048 display mode → routes to sub-renderers
- FUN_0049de40: Full tacho draw — RPM bar segments with color thresholds at +0xCD4/+0xD14/+0xD18/+0xD58, tick marks, gear indicator
- FUN_0049e670: 3-segment RPM bar — green for AI, colored for player
- FUN_0049e7b0: Single tacho tick — normalized, clamped. Color: value ≤ threshold → red, > threshold2 → yellow, else → green
- FUN_0049f170: Gear display cycle — increment/decrement with wrap 0↔4, stride 0x40

---

## Internal Call Graph

Major call chains within Session/Race Logic:

```
FUN_0046dc60 — SessionStateMachine  [triggered by: game state machine per tick]
  +-- FUN_004c8d80 — Check async loading complete
  +-- FUN_00461db0 — Check async operations
  +-- FUN_0042d210 — Input disable
  +-- FUN_0046bf10 — MainSessionLoop  [core game loop]
  |     +-- FUN_004beb10 — Frame tick (physics + render + AI)
  |     +-- FUN_00496880 — Game update dispatch
  |     +-- FUN_00497250 — Render/UI update
  |     +-- FUN_004c8d80 — Session completion check
  +-- FUN_004d2450 — Activate uninitialized vehicle
  +-- FUN_004a0590 — SessionType dispatch
  +-- FUN_00462850 — Session transition guard

FUN_004a0fd0 — SessionPauseHandler  [triggered by: per-frame input check]
  +-- FUN_004bc330 — Session type condition check
  +-- FUN_0042bc10 — Scoring gate check
  +-- FUN_004ef5a0 — Session state transition
  +-- FUN_004a0cb0 — Post-race check
  |     +-- FUN_004a0c60 — Session/menu mode switch

FUN_004d4580 — StewardUpdate  [triggered by: steward tick per frame]
  +-- FUN_004d0b20 — 3D distance check + accumulate
  +-- FUN_00448330 — (unknown, session physics)
  +-- FUN_004d2e50 — (unknown, steward phase logic)
  +-- FUN_004d1d80 — Proximity / gap tracking (3 phases)
  |     +-- FUN_004e9630 — Position change monitor
  |     +-- FUN_004d0c20 — Driver standing comparator
  |     +-- FUN_004d1730 — Penalty system logging
  |     +-- FUN_004b33b0 — Vehicle event dispatch
  +-- FUN_004d2170 — All-clear check (before race start)
  +-- FUN_004d2300 — Session particle trigger
  +-- FUN_004a0da0 — (session state check)

FUN_004c6b60 — SessionTickUpdate  [triggered by: per-frame update]
  +-- FUN_004bb8e0 — State reset on session condition
  +-- FUN_004d1180 — Steward session type dispatch
  |     +-- FUN_004d10e0 — (race phase render)
  |     +-- FUN_004d1140 — (non-race render)
  +-- FUN_004bc9b0 — Jumped start / grid penalty detection
  |     +-- FUN_004d10e0 — Grid position lookup
  |     +-- FUN_004efb20 — Vehicle world position
  |     +-- FUN_004bbd60 — Stop/go penalty
  |     +-- FUN_004bc0e0 — DSQ
  |     +-- FUN_0045bd10 — HUD display
  +-- FUN_004ef7c0 — (AI update)
  +-- FUN_004e9600 — (suspension state)
  +-- FUN_004a5e60 — State/phase setter
  +-- FUN_004a5e80 — Object state clear

FUN_004bc4e0 — LapCompletion  [triggered by: steward lap event]
  +-- Race branch (SessionType==7):
  |     +-- Check lap count vs DAT_008acf8c
  |     +-- FUN_0042d140 — Formation lap handling
  |     +-- DSQ for ignored Stop/Go ("Ignored Stop/Go Penalty")
  +-- Quali branch (SessionType==5):
  |     +-- DSQ if exceeding time limit
  +-- Practice branch (SessionType==0):
  |     +-- Simple lap update
  +-- Set DAT_008acfa0 half-distance flag
  +-- FUN_004bc240 — Standings update (state machine non-race transition)

FUN_004bccc0 — ApplyPenalties  [triggered by: steward penalty check]
  +-- Cut track: _DAT_0059e944 threshold → fine/lap invalidated/warning/StopGo
  +-- Speeding pitlane: StopGo (race) or fine (practice/quali)
  +-- Blue flags: 3-stage timer (_DAT_0059e5fc → warning, _DAT_0059e8ec → urgent, _DAT_0059e468 → DSQ)
  +-- Wrong way: _DAT_005acd88 threshold → DSQ

FUN_00461610 — SessionConfigBuilder  [triggered by: session setup]
  +-- FUN_00415c30 — Scene name extraction
  +-- FUN_004c5690 — Scene validation
  +-- FUN_004336d0 — String processing
  +-- FUN_004618d0 — String processing
  +-- FUN_004615c0 — Vehicle ID setup
  +-- Packs 22+ globals into bitfield

FUN_004c29f0 — RaceScoringTick  [triggered by: per-frame scoring during race]
  +-- FUN_0042bc10 — Scoring gate check
  +-- FUN_004c2bf0 — Scoring update
  +-- FUN_004c2c40 — AI scoring adjustment
  +-- FUN_004c2dc0 — Time scale update
  +-- FUN_004c2d30 — Standings computation
  +-- FUN_004c2c30 — Race-end trigger (when player first in championship)

FUN_004ba1f0 — ReplayLoad  [triggered by: user selects watch replay]
  +-- FUN_004d7a50 — Assert
  +-- FUN_00566b20 — Open VCR file
  +-- FUN_004a0e70 — Display message
  +-- FUN_004b9830 — Replay buffer alloc
  +-- FUN_00568540 — Timer/sync
  +-- FUN_004b97d0 / 004b9810 — Replay data checks
  +-- FUN_004b9da0 — State update
  +-- FUN_004b87a0 / 004b86e0 — Replay data init
  +-- FUN_00566c00 / 00566bd0 — Packet streaming

FUN_004b7500 — ReplaySave  [triggered by: user initiates replay recording]
  +-- FUN_004b6190 — Car state capture (0x68 iterations)
  +-- FUN_004b7a00 — Replay header init
  +-- FUN_00566940 — File open/write
  +-- FUN_004b6a10 — Lap data format
  +-- FUN_00566b20 / 00566c00 / 00566bd0 — Packet stream
  +-- FUN_004b8010 — Replay save finalize
  +-- FUN_004b5f60 — Cleanup

FUN_004d24d0 — RaceResultsWriter  [triggered by: race end]
  +-- FUN_00566650 — String write (path build)
  +-- FUN_00589671 — mkdir
  +-- FUN_005896ee — fopen
  +-- FUN_00589e6c — Get time
  +-- FUN_00566940 — File status
  +-- FUN_00566c30 — Write header/section
  +-- Iterates VehiclePtrArray writing per-driver results
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| 10.0 | FUN_004bccc0 | Stop/Go penalty duration (seconds) |
| 0x3FF (1023) | FUN_004bc0e0, FUN_004d2300 | Max penalty history / particle slots |
| 0x1B0 (432) | FUN_004bc0e0, FUN_004d2300 | Penalty history stride per entry |
| 0x68 (104) | FUN_004c02d0, FUN_004c0260 | Max qualifying driver entries |
| 0x80 (128) | FUN_004bb810 | Max vehicle array buffer size |
| 0x30 (48) | FUN_004c03f0 | Max races in season standings |
| 0x1B4 (436) | FUN_004c0cc0 | Standings entry stride |
| 0x48C0 (18624) | FUN_0042bbd0 | Vehicle struct / season entry stride |
| 0x1230 (4656) | FUN_0049f870 | Vehicle grid array stride |
| 7200.0 | SessionStruct+0xB8 | Max session time (2 hours) |
| 9000.0 | FUN_004be760 | Fastest lap sanity bound |
| 1.15 | FUN_004be760 | 2nd car inclusion threshold (115%) |
| 0.97 | FUN_004be760 | Finish time floor clamp (97% of fastest) |
| 0.15 | FUN_004be760 | Extrapolation rate |
| 600.0 | FUN_004be760 | Default initial prediction (10 min) |
| 5.0 | FUN_004a0fd0 | RaceTimerValue init |
| 12 | FUN_004b1190 | Default RaceLaps |
| 5 | FUN_004b1190 | Default QualifyLaps |
| 15 | FUN_004b1190 | Pit field width |
| 52 | FUN_004c6f10 | Grid column count |
| 25 | FUN_004d88d0 | Init entries at +0x10 |
| 3 | FUN_004d88d0 | Init entries at +0x74 |
| 7 | FUN_004aa270 | FailureRate slots count |
| 0.0-1.0 | FUN_00424080 | StartStalls probability range |
| 10% | FUN_00424080 | DNS probability given stall (1 in 10) |
| 0x4D | FUN_0041b190 | Race-end commentary ID |
| 0x6A-0x6F | FUN_0041afd0 | Player event commentary IDs |
| 0xDD-0xDF | FUN_0041afd0 | AI event commentary IDs |
| 0x72/0x73 | FUN_0041ad80 | Overtake commentary IDs |
| 0xD0 | FUN_0041ac50 | Race event sound ID |
| 0x1C | FUN_004bc0e0 | Vehicle event code (DSQ) |
| 0x17 | FUN_004bbd60 | Vehicle event code (StopGo) |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- `DAT_007cea5c` (EngineWearMode) — from docs/01, determines scripted events mode
- `DAT_007d01a0` (AIDifficultySlider) — from docs/02, AI scoring adjustment
- `DAT_007cf080` (WeatherMode) — from docs/05, track condition state
- `DAT_007ce958` (TireModelMode) — from docs/04, packed in session config
- `DAT_007c54f0` (VehiclePtrArray) — from docs/01, per-vehicle access
- `DAT_007d00ec` (GameState) — from docs/01, game state checks
- `DAT_005ea3fc` — session total time (for timer arrays)

**Calls into:**
- docs/04-tire-system: tire model mode checks
- docs/07-pit-system: pit stop logic, pit window handling
- docs/10-vehicle-physics: vehicle physics state reads
- docs/19-renderer: HUD font/surface rendering
- docs/21-audio-network-internals: commentary events, Bink playback

**Called by:**
- docs/01-engine-architecture: Game::MainLoop calls session state machine
- docs/02-ai-system: AI driver scoring reads session state
- docs/07-pit-system: pit timing reads session config
- docs/08-file-formats: replay file load/save chain

---

## Reimplementation Notes

1. **SessionType enum is fundamental:** The value at `DAT_007c56a4` drives branching across ~40+ functions. Must be set before any session logic runs. Values 0-5=practice, 6=qualifying, 7=race.

2. **RacePhase state machine:** `DAT_007c56a8` has values 0-8 governing race flow: 0-1=pre-race, 2=formation, 3-4=racing, 5-7=post-race, 8=finished.

3. **Penalty system gate:** All penalty enforcement passes through `DAT_007cef84`. When 0, penalties completely disabled — but commentary still fires.

4. **Replay file format:** VCR files contain packed vehicle state packets. The streaming loop (`FUN_00566c00` → `FUN_00566bd0`) processes one packet per iteration with a 250ms Sleep between chunks.

5. **Stall probability model:** `StartStalls` from .rcd is a direct 0.0-1.0 probability evaluated per-driver via `rand()%10000 < StartStalls*10000`. 10% of stall triggers become DNS.

6. **Scripted events mode:** When `DAT_007cea5c == 3`, events are driven by .rcd `Script` → `RaceEvents` section with 7 event types (Engine, Brakes, Gearbox, Suspension, Stall, Stall___DNS, DNS) each having lap ranges.

7. **Results file:** Written as UTF-8 text. Must ensure `Results\` directory exists before writing. Filename uses timestamp format `%d_%02d_%02d_%02d_%02d_%02d.txt`.

8. **Blue flag timer:** Counts time from a single monotonic source (`_DAT_008afea0`). Resets to 0 when the overtaken car complies. Three-stage escalation: warning → urgent → DSQ.

9. **Half-distance flag:** `DAT_008acfa0` computed as `lap >= (total_laps + 1) / 2`. Gates race results in championship mode.

10. **Vehicle index vs struct pointer:** Two mappings exist — DAT_007c54f0 (pointer array, stride 8) and DAT_005ef9a0 (grid array, stride 0x1230). Both index the same logical vehicle set but with different data layouts.

11. **Commentary audio IDs:** IDs are routed through FUN_004144d0/FUN_004144f0 which implement a ring buffer for audio event dispatch. The ring buffer counter at DAT_008aae70 provides variety.

---

## Completeness

- Full specs written: ~60 major entry points / 429 total documented functions
- Minor/thunk functions omitted: ~300 (trivial wrappers, getters, state flags)
- Utility/data functions: ~70 (hash, sort, linked list, buffer ops)
- Commentary functions: 6 major dispatchers
- HUD functions: 5 tachometer chain
- Session entry hooks: 10 (FUN_00472510-00474ab0 family)
- Confidence: **high** — all major system boundaries are documented and cross-referenced with docs/12 globals and docs/13 struct offsets

**Part 1 covers:** Replay system, penalty engine (DSQ/StopGo/Warning/JumpStart/BlueFlag), session config, steward main tick, lap completion processing, session state machine, video playback, qualifying lookup, career standings, race results writer, monitor/overlay renderer, session entry hooks, commentary system, HUD tachometer, AI overtaking probability, season points check.

**Part 2 (docs/06 continuation) covers:** Track limit zones, grid scene init, pit penalties, steward dispatch, remaining utility functions (sort, list, buffer ops), scoring gate, tire/force models, audio mixing, texture encoding, and all remaining leaf functions.
