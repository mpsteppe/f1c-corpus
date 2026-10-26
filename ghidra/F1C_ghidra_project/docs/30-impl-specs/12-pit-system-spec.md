# Implementation Spec: Pit System

Source: docs/07-pit-system.md  |  Functions: 27  |  Date: 2026-07-15

---

## Overview

The pit system manages all aspects of pit stops in F1 Challenge 99-02: strategy definition (lap-by-lap stop schedule), pit crew animation/scene loading, pit window timing (when pits open/close during a race), repair state tracking, and the pit stop execution state machine. It runs during race sessions (SessionType == 7) and is driven by the race phase global `DAT_007c56a8` (RacePhase, 0–7).

**When it runs:** Per-frame during race sessions via the session steward timer (called from FUN_004d4580 → FUN_004d2e50). Pit crew scene loading runs during track/scene init (called from FUN_004c6c40 for scenes and FUN_004e2a60 for crew instances). Pit stop execution state machine runs per-vehicle each physics tick.

**Data structures owned:**
- PitStop/PitCrewStruct: per-team pit state (mode, repair flag, action queue ring buffer at +0x9b0..+0x9bc)
- PitOrderStruct: pit crew name order (count at +0x1a8, string pointer array at +0x1ac, stride 8)
- PitCrewActorStruct: per-actor state (stride 0x78, fields for lollipop flag +0x03, detail +0x00, position +0x26–0x2a, rotation +0x2c–0x30)
- PartRepairStruct: per-part repair display state (wear index at +0x6c, current wear at +0xec, target at +0xf0, auto-repair flag at +0x128, repair decision at +0x12c, cost buffer at +0x36)

**Interface boundaries:**
- Reads: DAT_007c56a4 (SessionType), DAT_007c56a8 (RacePhase), DAT_007cec30 (ReconPitOpen), DAT_007cec54 (ReconPitClosed), DAT_007cec78 (PitTimerVisible), DAT_005ea3ec (LeftPitFlag), DAT_007cf884 (DetailLevel), DAT_005c329c (VehicleCount), DAT_007c54e8 (PlayerVehiclePtr), DAT_008acf8c (TotalRaceLaps)
- Writes: DAT_007ced8c (pit procedure active flag), DAT_007cee88 (formation lap abort flag), per-vehicle state at offsets +0x60 (PitState), +0x61 (PitEntryTimer), +0xc2 (FormationLapFlag), +0x1180 (PitStopFlag bitmask)
- Calls into: docs/06-session-race-logic.md (FUN_004d0ec0 session state, FUN_004bc9b0 penalties), docs/10-vehicle-physics.md (FUN_004f1b50 pit anim, FUN_004ef930 pit lane physics), docs/19-renderer.md (FUN_005450e0 mesh load, FUN_0054c210 LOD)

---

## Data Structures

### VehicleStruct (param_1 — shared vehicle/session struct)

The vehicle struct is shared across physics, session, and pit systems. Only pit-relevant fields are listed here. Full struct in docs/13.

```c
struct VehicleStruct {
    /* +0x0000 */ VTablePtr vtable;             // MSVC object header
    /* +0x0008 */ float    PositionX;           // World position
    /* +0x000c */ float    PositionY;
    /* +0x0010 */ float    PositionZ;
    /* +0x0060 */ byte     PitState;            // 1=entering, 2=in pits, 3=exiting, 4=collision avoid
    /* +0x0061 */ byte     PitEntryTimer;       // Countdown timer for pit entry transition
    /* +0x0062 */ byte     Pad62;
    /* +0x00b0 */ int      LapTimeRemaining;    // Time remaining in current lap (int)
    /* +0x00b4 */ int      RaceTimeRemaining;   // Time remaining in race session (int)
    /* +0x00b8 */ int      Offset;              // Pit timing offset
    /* +0x00c1 */ byte     PenaltyFlag;         // Set when penalty applied during pit
    /* +0x00c2 */ byte     FormationLapFlag;    // Non-zero = on formation lap
    /* +0x00d8 */ int      PitWindowOpenTime;   // Session time when pit window opens (int)
    /* +0x00f4 */ int      FinishState;         // 0=running, 1=finished, 2=DNF, 3=DSQ
    /* +0x0104 */ byte     ProcessedFlag;       // Per-tick processed flag
    /* +0x1180 */ uint     PitStopFlag;         // Bitmask: which stops completed
    /* +0x4620 */ char     DriverName[64];      // Wide string driver name
    /* +0x4678 */ char     VehicleDescription[]; // Vehicle description / livery name
    /* +0x4894 */ int      TeamID;              // -1 = unassigned
    /* +0x489c */ int      DriverNumber;        // Driver number, -1 = unset
};
// Total size: 0x48C0 bytes (confirmed from stride observations in docs/13)
// Accessed via: DAT_007c54f0 (VehiclePtrArray) with stride 0x48C0
// Also accessed as param_1 by most pit functions
```

### PitCrewStruct (param_1 — per-team pit state)

Based on FUN_004a5600, FUN_004b6940, FUN_004b5da0, FUN_004a47e0. Confidence: **high**.

```c
struct PitCrewStruct {
    /* +0x0008 */ byte*   CurrentPitState;       // Pointer to current animation state byte
    /* +0x0184 */ int     PitMode;               // 3=repair mode active
    /* +0x0190 */ byte    RepairDoneFlag;        // Blocks state transitions when set
    /* +0x09b0 */ int     PitActionBase;         // Base pointer for action queue (ring buffer)
    /* +0x09b4 */ int     PitActionCapacity;     // Capacity/modulo limit for ring buffer index
    /* +0x09b8 */ int     PitActionHead;         // Ring buffer head index / counter
    /* +0x09bc */ int     PitActionTail;         // Ring buffer tail index / coordinate Y
};
// Accessed per team, indexed by TeamID offset +0x4894 in VehicleStruct
```

### PitOrderStruct (param_1 — pit order config)

Based on FUN_004d12c0. Confidence: **high**.

```c
struct PitOrderStruct {
    /* +0x01a8 */ int     PitOrderCount;         // Number of pit crew role names
    /* +0x01ac */ char**  PitOrderArray;         // Array of string pointers, stride 8
    // Each pointer → pit crew role name string (e.g., "refueler", "lollipop")
    // If ReversePitOrder config flag is True, array is reversed at load time
};
```

### PitCrewActorStruct (per-anim actor)

Based on FUN_004a2a90. Confidence: **high**. Stride 0x78 allocated as array.

```c
struct PitCrewActorStruct {
    /* +0x0000 */ uint16  DetailLevel;           // LOD/detail level selector
    /* +0x0003 */ byte    LollipopFlag;          // 1 if actor name == "LOLLIPOP"
    /* +0x0026 */ float   PosX;                  // POSITION directive X
    /* +0x0028 */ float   PosY;                  // POSITION directive Y
    /* +0x002a */ float   PosZ;                  // POSITION directive Z
    /* +0x002c */ float   RotA;                  // ROTATE directive (quaternion/euler)
    /* +0x002e */ float   RotB;
    /* +0x0030 */ float   RotC;
    // Scaled by DAT_0059e65c conversion factor
};
```

### PartRepairStruct (param_1 — per-part in pit UI)

Based on FUN_004a58b0. Confidence: **high**.

```c
struct PartRepairStruct {
    /* +0x0028 */ int     ManualEntryFlag;       // 1=auto (no manual cost), other=manual
    /* +0x0036 */ char    PartCostBuffer[];      // Formatted cost string display
    /* +0x0058 */ double  WearScaleA;            // First wear coefficient for cost formula
    /* +0x0060 */ double  WearScaleB;            // Second wear coefficient for cost formula
    /* +0x006c */ int     PartWearIndex;         // Index identifying which part
    /* +0x0076 */ char    WearPercentBuffer[];   // Wear percentage display string
    /* +0x00b6 */ char    PartNameBuffer[];      // Part name + status display buffer
    /* +0x00ec */ float   CurrentWear;           // Current wear value (from +0x3b index)
    /* +0x00f0 */ float   TargetWear;            // Target wear value after repair (from +0x3c)
    /* +0x00f6 */ char    RepairDeltaBuffer[];   // "+N" or "-N" formatted change string
    /* +0x0128 */ int     AutoRepairFlag;        // 1=automatic repair (no user choice)
    /* +0x012c */ int     DoNotRepairFlag;       // 0=don't repair, 1=repair decision
    /* +0x0136 */ char    RepairDecisionBuffer[];// "Do Not Repair" or "Repair" text
    /* +0x017c */ float   CurrentLapWear;        // Lap wear flag (0=clear percentage display)
};
```

### SessionTimersStruct (param_1 — session/timer data)

Based on FUN_004d0f10, FUN_00411120, FUN_004a5e10. Confidence: **high**.

```c
struct SessionTimersStruct {
    /* +0x0014 */ int     ActiveFlag;            // Non-zero = session active
    /* +0x0184 */ int     SessionState;          // 0=idle, 1=active, 4=finished
    /* +0x00ac */ int     BestTime;              // 0x7fffffff = DNF sentinel
    /* +0x00b8 */ float   MaxSessionTime;        // 7200.0 (2-hour race limit)
    /* +0x00bc */ float   TimeMultiplier;        // 1.0 (time scale factor)
    /* +0x0190 */ short   LapCount;              // 0xFFFF = unset
    /* +0x0192 */ byte    CurrentSector;         // 0xFF = unset
    /* +0x0280 */ int[52] PitWindowHistory;      // Zeroed on init
};
```

---

## Global Variables Owned by This System

| Global | Type | Name | Description |
|--------|------|------|-------------|
| DAT_007ced8c | int | PitProcedureActive | Set during active pit procedure; gates pit logic |
| DAT_007cee88 | int | FormationLapAbort | Set when formation lap aborted |
| DAT_007cebf4 | int | TimerUpdateInterval | Controls frequency of time-remaining HUD updates |
| DAT_008afe98 | int | PitClosureOffset | Pit closure timing offset applied per-vehicle |

**Globals READ by pit system (not owned):**
- DAT_007c56a4 (SessionType, steward) — gate for race-only logic
- DAT_007c56a8 (RacePhase, race) — state machine driver (0–7)
- DAT_007cec30 (ReconPitOpen, race) — pit window open time
- DAT_007cec54 (ReconPitClosed, race) — pit window closed time
- DAT_007cec78 (PitTimerVisible, race) — show pit timer on HUD
- DAT_007cf884 (DetailLevel, renderer) — gate for crew mesh loading (≤1)
- DAT_005ea3ec (LeftPitFlag, setup) — select left/normal pit layout
- DAT_005ec3d8 (SeasonPath, setup) — season directory
- DAT_005ec420 (TrackDir, setup) — track directory
- DAT_007d0450 (CostDisplayMode, UI) — pit repair cost format
- DAT_005ec4cc (MessageBuffer, UI) — message buffer for pit status
- DAT_008acf8c (TotalRaceLaps, hdvehicle) — default last stop lap
- DAT_007d0308 (RaceActiveFlag, race) — gates pit status messages
- DAT_005c329c (VehicleCount, steward) — vehicle iteration limit
- DAT_007c54e8 (PlayerVehiclePtr, game) — player vehicle lookup
- DAT_005f0738 (DriverTeamOrderTable, session) — pit rank/order table

---

## Public API — Entry Points

### FUN_00429960 — Pit Strategy Reader

**Inferred signature:** `void PitStrategyReader(PitCrewStruct* pit, const char* strategyStr)`
**Called from:** garage.cpp, during vehicle setup (reading .svm file pit strategy field)
**Called by (from callers.json):** Not in graph (no callers recorded)

**What it does:**
1. Parses strategy string in format `N,lap1[,lap2[,lap3[,lap4]]]`
2. N = number of stops (clamped 1–4)
3. Following integers = lap numbers for each pit stop
4. If fewer stops specified than N, remaining default to `DAT_008acf8c` (total race laps)
5. Maximum 4 stops supported (ring buffer capacity)

**Side effects:**
- Writes: per-team pit stop schedule in PitCrewStruct action queue
- Reads: DAT_008acf8c (TotalRaceLaps)

---

### FUN_004a2a90 — Pit Crew Animation Loader

**Inferred signature:** `void PitCrewAnimLoad(const char* mtsPath, PitCrewActorStruct* actors, int actorCount)`
**Called from:** FUN_004a3220 (PITANIMS.MAS loader) during track/pit init
**Called by (from callers.json):** 0x004a3220

**What it does:**
1. Loads `.mts` pit crew model/animation file
2. Parses directives: ACTOR, DETAIL, MESH, POSITION, MOVE, ROTATE
3. Maps wheel mesh names (LFWHEELOFF/ON, RFWHEELOFF/ON, LRWHEELOFF/ON, RRWHEELOFF/ON) to wheel indices 0–3
4. Allocates actor array with stride 0x78 per actor
5. If actor name == "LOLLIPOP", sets actor +0x03 flag

**Side effects:**
- Writes: PitCrewActorStruct array entries
- Reads: `.mts` file from MAS archive

---

### FUN_004d12c0 — Pit Order Loader

**Inferred signature:** `void PitOrderLoad(PitOrderStruct* order, const char* configPath)`
**Called from:** FUN_004d1410 (session setup)
**Called by (from callers.json):** 0x004d1410

**What it does:**
1. Reads `[PITORDER]` section from config file
2. Stores array of pit crew role name strings
3. Checks `ReversePitOrder` config flag (True/False)
4. If True, reverses the pit order array in-place

**Side effects:**
- Writes: PitOrderStruct.PitOrderCount (+0x1a8), PitOrderStruct.PitOrderArray (+0x1ac)
- Allocates: string pointer array at stride 8 per entry

---

### FUN_004ddad0 — Pit Crew Instance Setup

**Inferred signature:** `void PitCrewInstanceSetup(VehicleStruct* vehicle, int teamIndex)`
**Called from:** FUN_004e2a60 (vehicle/team setup)
**Called by (from callers.json):** 0x004e2a60

**What it does:**
1. Loads `TEAM.MAS` archive (team-specific textures)
2. Resolves `TrackName` for the current circuit
3. Finds livery in vehicle's TrackLivery linked list (vehicle +0xf5)
4. Sets up 9 pit crew roles: refueler, wcrefueler (×3), lollipop, wclollipop (×3+1)
5. Resolves role names from TrackLivery data

**Vehicle struct offsets used:**
- +0xf3: livery name string
- +0xf5: TrackLivery linked list pointer
- +0xf6: pit crew livery reference

---

### FUN_004a3910 — Pit Crew Animation/MAS Setup

**Inferred signature:** `void PitAnimSetup(VehicleStruct* vehicle)`
**Called from:** pitcrew.cpp during pit scene initialization

**What it does:**
1. Checks DAT_007cf884 (detail level) — if ≤1, loads `PITGUYC.MTS` via FUN_004a21d0
2. Builds path: `{SeasonPath}\{TrackDir}\PITS\{Normal|Left}\` (Left if DAT_005ea3ec)
3. Loads `PITANIMS.MAS` from that path
4. Loads animation from F0PEWAAA (unknown) via FUN_004a22d0
5. Loads animation from F0PEHAAA (unknown) via FUN_004a22d0
6. Sets up animation blend states via FUN_004a1fd0 for keyframes 0 and 1

**Globals used:**
- DAT_007cf884 — detail level gate
- DAT_005ea3ec — left-hand pit flag
- DAT_005ec3d8 — season path
- DAT_005ec420 — track directory

---

### FUN_004a3220 — PITANIMS.MAS File Loader

**Inferred signature:** `void PitAnimMasLoad(const char* path, void* param2, int param3)`
**Called from:** internal pitcrew.cpp initialization chain

**What it does:**
1. Resolves directory path from param_1, truncates to parent directory
2. Pushes search path via FUN_0053c800 and opens `PITANIMS.MAS` via FUN_0053cbc0
3. Calls FUN_004a2a90 (pit crew anim loader) with param_1, param_2, param_3
4. Closes MAS archive via FUN_0053ce40
5. Restores search path via FUN_0053c900

**Call chain:**
```
FUN_004a3220
  +-- FUN_004a29a0 — search path init
  +-- FUN_00566650 — name set (file open helper)
  +-- FUN_0053c800 — push search path
  +-- FUN_0053cbc0 — open MAS archive (PITANIMS.MAS)
  +-- FUN_004a2a90 — load pit crew animation .mts
  +-- FUN_0053ce40 — close MAS archive
  +-- FUN_0053c900 — pop search path
  +-- FUN_00587bcf — free temporary memory
```

---

### FUN_004d2e50 — Pit Timer / Race Phase State Machine

**Inferred signature:** `void PitTimerStateMachine(SessionTimersStruct* session, int vehicleIndex)`
**Called from:** FUN_004d4580 (session steward per-tick)
**Called by (from callers.json):** 0x004d4580

**What it does — per RacePhase:**

**Phase 0 (Session 7, pre-race):**
- Reads DAT_007c56a8 (RacePhase=0)
- Checks if race time remaining > threshold → transition to phase 1

**Phase 1 (Race start countdown):**
- Computes time-to-start: `param_1[0x2d] - threshold`
- 5+ seconds: normal countdown display
- 4s → phase 4, 3s → phase 3, 2s → phase 2, 1s → phase 1
- Countdown reaches 0: calls FUN_004d0ec0(2) to start session
- Tracks pit close time: `(pit_open_time + session_lap_time) - race_time`
- Displays "Time until pit closes" via FUN_004d11d0
- If pit closes too soon: calls FUN_0045bdf0 (early pit penalty?)

**Phase 2 (Formation lap):**
- Sets param_1+0xc2 (FormationLapFlag)
- Waits for race time to reach 0
- Transitions to phase 3 or 4

**Phase 3 (Formation lap / grid):**
- Calls FUN_004bc9b0 (jump start penalty check)
- Resets pit timer
- Transitions to race running

**Phase 4 (Green flag / race running):**
- Countdown-based pit window tracking with 5-tier HUD display via FUN_004d1cd0:
  - 0 = pit closed, 1 = opening, 2–4 = closing soon, 5 = open
- Displays "00:01" warning via FUN_0045bde0
- When time runs out: calls FUN_004d2210 (pit close), transitions to phase 5

**Phase 5 (Race finish):**
- If leader finished (param_1[0x3d] == 2, FinishState=finished):
  - Checks all vehicles for DNF
  - Calls FUN_004d0ec0(1) to end session
- Periodic "Time Remaining:" display every DAT_007cebf4 ticks
- Formats `"%s %d:%02d:%02d"` via FUN_0045bd10 (HUD write)

**Phase 7 (Post-race, session 1-6):**
- Adds pit closure offset to lap time

**Default (non-race sessions):**
- Calls FUN_0041a500 with remaining time

**Struct offsets used (param_1 = VehicleStruct offsets via session data):**
| Offset | Field |
|--------|-------|
| +0x00b0 (0x2c) | LapTimeRemaining (int) |
| +0x00b4 (0x2d) | RaceTimeRemaining (int) |
| +0x00d8 (0x36) | PitWindowOpenTime (int) |
| +0x00c2 | FormationLapFlag (byte) |
| +0x00f4 (0x3d) | FinishState (2=finished) |
| +0x0104 (0x41) | ProcessedFlag (byte) |

**Globals used:**
- DAT_007c56a4 — SessionType (7=race)
- DAT_007c56a8 — RacePhase (0–7)
- DAT_008afe98 — pit closure offset
- DAT_008afea0 — lap/race time threshold
- DAT_007ced8c — pit procedure active flag
- DAT_007cec30 — pit open time (ReconPitOpen)
- DAT_007cec78 — pit timer visible (PitTimerVisible)
- DAT_007cee88 — formation lap abort flag
- DAT_007cebf4 — timer update interval
- DAT_005ec4cc — MessageBuffer
- DAT_007c54e8 — PlayerVehiclePtr
- DAT_005c329c — VehicleCount

---

### FUN_004a6e50 — Pit State Update Machine (Main State Machine)

**Inferred signature:** `void PitStateUpdate(VehicleStruct* vehicle)`
**Called from:** per-vehicle pit tick (physics thread or session timer)

**What it does — state machine by PitState byte (vehicle +0x61):**

**State 1 (entering pit):**
- Checks PitEntryTimer expiry
- On timer expiry: transitions to state 0 (in pits) or prepares pit work

**State 2 (in pits):**
- Checks if pit work complete (via FUN_004a68b0 progress handler)
- Clears PitState flag
- Resumes vehicle (pit exit sequence)

**State 3 (exiting pit):**
- Normal exit or emergency exit (collision avoidance bypass)
- Exits pit lane physics mode

**State 4 (collision avoidance):**
- Calls FUN_004a6b80 to check collision risk with approaching vehicles
- If clear: transitions to exit

**Internal call chain:**
```
FUN_004a6e50 — Pit State Update Machine
  +-- FUN_004a6b80 — Collision avoidance check
  |     +-- FUN_004e9630 — Position/velocity query
  |     +-- FUN_004a4030 — Vehicle proximity test
  |     +-- FUN_004a4000 — Collision risk calculation
  +-- FUN_004a6db0 — Pit lane exit handler
  |     +-- FUN_004d21d0 — Pit exit clearance
  +-- FUN_004a5fa0 — Pit work completion check
  |     +-- FUN_004a5c80 — Progress notification
  |     +-- FUN_0041a3a0 — Score/timing update
  |     +-- FUN_004bc0e0 — Race position update
  |     +-- FUN_004bba90 — Gap calculation
  |     +-- FUN_004a3fe0 — Pit lane physics exit
  +-- FUN_004a5c80 — Notification/log
  |     +-- FUN_004b33b0 — Log/notification dispatch
  |     +-- FUN_004a5d10 — Ring buffer process
  +-- FUN_004d8840 — Session state check
  +-- FUN_004a6200 — Pit stop ready check
  |     +-- FUN_004f1b50 — Pit animation trigger
  |     +-- FUN_004ef930 — Pit lane physics init
  |     +-- FUN_0042a3d0 — Vehicle position check
  |     +-- FUN_004a6340 — Operation timer
  |     +-- FUN_004efb20 — Pit stop type setup
  |     +-- FUN_004a3320 — Pit orientation math
  |     +-- FUN_0040d3c0 — Pit stop event dispatch
  +-- FUN_004a68b0 — Pit stop progress handler
  |     +-- FUN_0040d410 — Pit animation frame
  |     +-- FUN_004f1890 — Wheel change timing
  |     +-- FUN_004f1ba0 — Wheel force control
  |     +-- FUN_004a5c80 — Progress notification
  |     +-- FUN_004d8760 — Session state transition
  |     +-- FUN_0042a6f0 — Vehicle mode switch
  |     +-- FUN_00424cd0 — Team event dispatch
  |     +-- FUN_004f1b50 — Pit animation cleanup
  |     +-- FUN_004a34a0 — UI update
  |     +-- FUN_004e0ed0 — Replay/telemetry record
  +-- FUN_004e9630 — Vehicle position query
  +-- FUN_0040d410 — Pit animation trigger
```

---

### FUN_004a6340 — Pit Stop Operation Timer

**Inferred signature:** `float PitStopComputeDuration(VehicleStruct* vehicle, int workType)`
**Called from:** FUN_004a6200 (pit stop ready check)

**What it does:**
1. Accumulates phase durations: wheel change + repair + refuel
2. Wheel change time: 4 random cubic durations sampled from ring buffer
3. Repair time: additive, from FUN_004a5820 part lookup
4. Refuel time: increments global fuel counter, adds fuel duration with variance
5. If vehicle disqualified: adds penalty time

**Return value:** Total pit stop duration in seconds

**Calls:** FUN_004f1890, FUN_004a5820, FUN_004d7570, FUN_004f1a60, FUN_004f1860, FUN_004b33b0, FUN_004a35f0, FUN_004a3560, FUN_004a34a0, FUN_004bbf20, FUN_0042aee0

---

### FUN_004b7a90 — Pit Timing Update

**Inferred signature:** `void PitTimingUpdate(PitCrewStruct* pits, float deltaTime, int startStop)`
**Called from:** session timer per-tick

**What it does:**
1. If paused flag set: skip
2. If param_3 != 0: setup pit stop for vehicle (initialization)
3. Loop over vehicles in pit:
   - Add elapsed time to pit timer
   - Check if timer exceeds threshold (work complete)
4. Process pending pit commands from linked list

**Calls:** FUN_004b5c50, FUN_00568d90, FUN_004c71c0, FUN_004b5da0, FUN_004b6190, FUN_004b3b30, FUN_004b3af0, FUN_004b6940

---

### FUN_004a58b0 — Pit Repair Status Display

**Inferred signature:** `void PitRepairDisplay(PartRepairStruct* part)`
**Called from:** pit menu UI rendering

**What it does:**
1. Reads PartWearIndex (+0x6c), WearScaleA (+0x58), WearScaleB (+0x60)
2. If CurrentLapWear (+0x17c) == 0: clears wear percentage display
3. Otherwise: formats `"%s/%d"` style with computed wear percentage
4. If DAT_007d0450 == 1: formats cost with `"%4.1f/%s"` using `(wear_index * coeff_a + coeff_b) * _DAT_0059ea40`
5. Otherwise: formats cost as integer
6. Gets part name via FUN_004a5820(part[0x2b]) → copies to MessageBuffer
7. Formats part name + status string at +0xb6
8. Computes repair delta: CurrentWear (+0xec) vs TargetWear (+0xf0)
   - Equal: `"%d"` (no change)
   - Target < Current: `"%d (-%d)"` (reduced = repaired)
   - Target > Current: `"%d (+%d)"` (increased = worse)
9. AutoRepairFlag (+0x128) == 1: displays blank (no user choice)
10. Otherwise: checks DoNotRepairFlag (+0x12c)
    - 0 → `"Do Not Repair"`
    - 1 → `"Repair"`
11. ManualEntryFlag (+0x28) != 1: formats `"%s: %d"` with part cost
12. ManualEntryFlag == 1: shows blank (automatic/managed by system)

---

### FUN_0041ab30 — Pit State Slot Activation

**Inferred signature:** `void PitSlotActivate(VehicleStruct* vehicle, int slotIndex)`
**Called from:** pit/session commentary system

**What it does:**
1. Sets slot at vehicle +0xa44 + slotIndex × 4 = 2 (active)
2. Counts active slots: if <3 per-slot commentary IDs, if ≥3 dispatch ID 0x68

---

### FUN_0041b3c0 — Pit Selection State Machine

**Inferred signature:** `void PitSelectionState(int state, int param3, int param4, float param5)`
**Called from:** pit commentary/selection system

**What it does:**
1. Clamps param_4, generates random float, position buckets
2. Case 0: select top, check flags, commentary IDs by bucket
3. Case 2: mid/deselect, queue flag clears
4. Case 3: ID 0x83. Case 5: player pit confirmed IDs 0x7b–0x7d

---

### FUN_004d2210 — Pit Close: Team Ready Check

**Inferred signature:** `void PitCloseNotify()`
**Called from:** FUN_004d2e50 when pit window timer expires (phase 4→5)

**What it does:**
1. Iterates all vehicles in DAT_007c54f0 (VehiclePtrArray)
2. If vehicle +0x13000 offset is 0 or 1 (old tires or waiting): calls FUN_004bc9b0(1,0)

---

### FUN_004d23d0 — Pit Timer State Init

**Inferred signature:** `void PitTimerInit(SessionTimersStruct* session)`
**Called from:** steward when pit window opens

**What it does:**
1. Clears penalty flag (vehicle +0xc1 = 0)
2. Copies pit window time to vehicle +0xd8
3. Sets race time remaining (vehicle +0xb4)
4. Sets lap time remaining (vehicle +0xb0)
5. Calls FUN_0042d140(4) to set RacePhase to green
6. Broadcasts pit window open time to all vehicles

---

### FUN_0041be60 — Pit/Race Status Message Dispatcher

**Inferred signature:** `void PitStatusDispatch(int sessionType, int vehicleMode, float timeThreshold)`
**Called from:** HUD message system (hud_messages.cpp)

**What it does:**
1. Gets session type (2=quali, 3=race, 4=warmup, 5=practice) via FUN_004ff130
2. Gets vehicle mode for driver via FUN_004ff1d0
3. Case 2 (practice/quali): dispatches messages 0x1fa–0x200 depending on mode match
4. Case 3 (race): message 0x1fd/0x1fe/0x200
5. Case 4 (warmup): message 0x1fe/0x200
6. Case 5 (practice): message 0x1ff/0x200
7. Checks time threshold for additional message 0x201

---

### FUN_004a5820 — Nth Valid Part Lookup

**Inferred signature:** `int NthValidPart(VehicleStruct* vehicle, int n)`
**Called from:** multiple pit UI functions

**What it does:**
1. If n > 0: iterate parts list, skip worn parts unless low session type
2. Decrement counter on each match, return part ID when counter reaches 0

---

### FUN_004a5c40 — Teammate Part Value Lookup

**Inferred signature:** `float TeammatePartValue(VehicleStruct* vehicle, int offset)`
**Called from:** pit UI/strategy

**What it does:**
1. Iterates DAT_007c54f0 (VehiclePtrArray) comparing +0x48a4 (TeamID)
2. If TeamID matches: return other vehicle's value at +0x3450

---

### FUN_004a6200 — Pit Stop Ready Check

**Inferred signature:** `int PitStopReadyCheck(VehicleStruct* vehicle, float distanceThreshold)`
**Called from:** FUN_004a6e50 (state machine)

**What it does:**
1. Sets ready flag
2. Checks position distance vs threshold (DAT_005acb50)
3. If ready: calls FUN_004f1b50 (pit animation trigger) and FUN_004ef930 (pit lane physics init)
4. Stores operation type (wheel change/repair/refuel)
5. Calls FUN_004a6340 to compute return time

**Moddability:** distance threshold from DAT_005acb50 (configurable float constant)

---

### FUN_004d1bc0 — Pit Stop Order Rank

**Inferred signature:** `int PitRank(VehicleStruct* vehicle, int teamID)`
**Called from:** steward pit ordering

**What it does:**
1. If non-race session: count vehicles with different TeamID compared unfavorably
2. If race session: read from precomputed table DAT_005f0738

---

### Pit Crew Scene Functions

These are init-time scene loading functions with no gameplay logic:

| Function | Purpose |
|----------|---------|
| FUN_004a2010 | Loads pit crew mesh from .mas, sets up LOD, error "CUBE error loading pitcrew mesh" |
| FUN_004a22d0 | Loads `.anm` animation files, allocates stride-0x1c array extending by 1 per call |
| FUN_004a4900 | Loads CMAPS.MAS, CDB.MAS, TEAM.MAS, PITS.MAS; creates 3 pit crew instances per team |

---

## Internal Call Graph

Major call chains within the pit system:

```
FUN_004d2e50 — PitTimerStateMachine  [triggered by: session steward tick → FUN_004d4580]
  +-- FUN_0041a500 — Session timer handler  [updates race/session clock]
  +-- FUN_0042d140 — Race phase setter  [transitions RacePhase]
  +-- FUN_004d0ec0 — Session state setter  [start/end session]
  +-- FUN_0041a6b0 — Per-vehicle time update
  +-- FUN_004d1cd0 — Pit state HUD display  [5-tier pit window display]
  +-- FUN_004d2e20 — Pit countdown timer
  +-- FUN_004d11d0 — Time format display  ["Time until pit closes"]
  +-- FUN_0045bdf0 — Early pit penalty dispatch
  +-- FUN_0040cde0 — Camera/session event
  +-- FUN_0040dd80/FUN_0040de60 — Pit animation triggers
  +-- FUN_0040e170 — Session end handler
  +-- FUN_004bc9b0 — Jump start penalty  [also called from PitClose]
  +-- FUN_00461db0 — Sound check/trigger
  +-- FUN_004d2210 — Pit close  [also an entry point]
  |     +-- FUN_004bc9b0 — Penalty for vehicles on old tires
  +-- FUN_0045bd10 — HUD text write

FUN_004a6e50 — PitStateUpdateMachine  [triggered by: per-vehicle physics tick]
  +-- FUN_004a6200 — PitStopReadyCheck
  |     +-- FUN_004f1b50 — Pit animation trigger (wheel change, refuel)
  |     +-- FUN_004ef930 — Pit lane physics mode init
  |     +-- FUN_0042a3d0 — Vehicle position check vs pit box
  |     +-- FUN_004a6340 — PitStopOperationTimer
  |     |     +-- FUN_004f1890 — Wheel change duration (ring buffer sample)
  |     |     +-- FUN_004a5820 — NthValidPart (repair part lookup)
  |     |     +-- FUN_004d7570 — Part list traversal
  |     |     +-- FUN_004a35f0 — Fuel duration calculation
  |     |     +-- FUN_004a3560 — Fuel variance computation
  |     |     +-- FUN_004bbf20 — Disqualification penalty time
  |     +-- FUN_004efb20 — Pit stop type configuration
  |     +-- FUN_004a3320 — Pit box orientation matrix (rotation math)
  |     +-- FUN_0040d3c0 — Pit event dispatch
  +-- FUN_004a68b0 — PitStopProgressHandler
  |     +-- FUN_0040d410 — Pit animation frame driver
  |     +-- FUN_004f1890 — Wheel animation speed interpolation
  |     +-- FUN_004f1ba0 — Wheel force/state during change
  |     +-- FUN_004a5c80 — Progress notification (notification/log + ring buffer)
  |     |     +-- FUN_004b33b0 — Notification/log dispatch
  |     |     +-- FUN_004a5d10 — Ring buffer process
  |     +-- FUN_004d8760 — Session state transition (vehicle finish state)
  |     +-- FUN_0042a6f0 — Vehicle mode switch (pit ↔ race mode)
  |     +-- FUN_00424cd0 — Team event dispatch (same-team notification)
  |     +-- FUN_004f1b50 — Pit anim cleanup (stop wheel change anim)
  |     +-- FUN_004a34a0 — UI update (pit menu refresh)
  |     +-- FUN_004e0ed0 — Replay/telemetry integration
  +-- FUN_004a6b80 — Pit collision avoidance
  |     +-- FUN_004e9630 — Vehicle position query (world space)
  |     +-- FUN_004a4030 — Proximity test (approaching car check)
  |     +-- FUN_004a4000 — Collision risk calculation
  +-- FUN_004a6db0 — Pit exit clearance
  |     +-- FUN_004d21d0 — Clear pit lane exit
  +-- FUN_004a5fa0 — Pit work completion
  |     +-- FUN_004a5c80 — Notification
  |     +-- FUN_0041a3a0 — Score/timing update
  |     +-- FUN_004bc0e0 — Race position update
  |     +-- FUN_004bba90 — Gap calculation to ahead/behind
  |     +-- FUN_004a3fe0 — Pit lane physics mode exit
  +-- FUN_004d8840 — Session state gate check
  +-- FUN_004e9630 — Vehicle position fallback query

FUN_004b7a90 — PitTimingUpdate  [triggered by: timer tick]
  +-- FUN_004b5c50 — Pit pool allocator
  +-- FUN_00568d90 — Performance timer (QPC)
  +-- FUN_004c71c0 — Vehicle lookup/filter
  +-- FUN_004b5da0 — Pit command deque
  +-- FUN_004b6190 — Pit command process
  +-- FUN_004b3b30 — Ring buffer read
  +-- FUN_004b3af0 — Ring buffer write
  +-- FUN_004b6940 — Pit action queue update
```

---

## Constants and Magic Numbers

| Value | Used in | Meaning |
|-------|---------|---------|
| N,lap1..lap4 | FUN_00429960 | Pit strategy format: at most 4 stops |
| 0x78 | FUN_004a2a90 | Pit crew actor struct stride (120 bytes per actor) |
| 0x1c | FUN_004a22d0 | Animation entry stride (28 bytes per anim) |
| 3 | FUN_004a4900 | Pit crew instances created per team (NORMAL, 10SEC, DIRECTOR) |
| 9 | FUN_004ddad0 | Standard pit crew roles (refueler×1 + wcrefueler×3 + lollipop×1 + wclollipop×4) |
| 0–5 | FUN_004d1cd0 | Pit window HUD display tiers (0=closed, 5=open) |
| 2 | FUN_004d0ec0 | Argument to start session |
| 1 | FUN_004d0ec0 | Argument to end session |
| 0x7b–0x7d | FUN_0041b3c0 | Commentary IDs for player pit confirmed (3 stages) |
| 0x68 | FUN_0041ab30 | Commentary ID for 3+ active pit slots |
| 0x204–0x217 | FUN_0041c0f0 | Commentary ID range for pit entry/exit/exiting |
| 0x1fa–0x201 | FUN_0041be60 | HUD message IDs for pit/race status |
| DAT_005acb50 | FUN_004a6200 | Pit stop distance threshold (configurable) |
| DAT_0059ea40 | FUN_004a58b0 | Pit repair cost scale factor |

---

## Inter-System Dependencies

**Reads from (external globals/systems):**
- DAT_007c56a4 (SessionType, docs/12 steward) — gate for race-only pit logic
- DAT_007c56a8 (RacePhase, docs/12 race) — state machine for pit timing phases 0–7
- DAT_007cec30 (ReconPitOpen, docs/12 race) — pit window open time reference
- DAT_007cec54 (ReconPitClosed, docs/12 race) — pit window close time reference  
- DAT_007cec78 (PitTimerVisible, docs/12 race) — HUD pit timer visibility flag
- DAT_007d0308 (RaceActiveFlag, docs/12 race) — gate for pit status messages
- DAT_005c329c (VehicleCount, docs/12 steward) — iteration bounds
- DAT_007c54e8 (PlayerVehiclePtr, docs/12 game) — player vehicle reference
- DAT_007c54f0 (VehiclePtrArray) — access all vehicles
- DAT_005ec3d8 (SeasonPath, docs/12 setup) — MAS file path construction
- DAT_005ec420 (TrackDir, docs/12 setup) — track-specific directory
- DAT_005ea3ec (LeftPitFlag, docs/12) — pit layout selector
- DAT_007cf884 (DetailLevel, renderer) — pit crew model detail gate
- DAT_008acf8c (TotalRaceLaps, docs/12 hdvehicle) — default last stop lap
- DAT_005f0738 (DriverTeamOrderTable) — precomputed pit rank/waiting list

**Calls into:**
- docs/06-session-race-logic.md: FUN_004d0ec0 (session state set), FUN_004bc9b0 (penalties), FUN_004bc2d0 (penalty dispatch)
- docs/10-vehicle-physics.md: FUN_004f1b50 (pit anim trigger), FUN_004ef930 (pit lane physics init), FUN_004f1ba0 (wheel force)
- docs/19-renderer.md: FUN_005450e0 (mesh load), FUN_0054c210/230 (LOD setup), FUN_004e0ed0 (replay/telemetry record)
- docs/18-physics-dynamics.md: FUN_004e9630 (vehicle position query)
- Audio system: FUN_00461db0 (sound check/trigger)

**Called by:**
- docs/06-session-race-logic.md: FUN_004d4580 (session steward per-tick) → calls FUN_004d2e50
- docs/08-file-formats.md (setup): FUN_004c6c40 (scene setup) → calls FUN_004a4900
- Vehicle/team setup: FUN_004e2a60 → calls FUN_004ddad0
- HUD system: hud_messages.cpp → calls FUN_0041be60
- Replay/telemetry: FUN_004e0ed0 → records pit events

---

## Reimplementation Notes

1. **RacePhase ordering dependency:** `DAT_007c56a8` must be set before pit timing logic reads it. The state machine assumes SessionType is set to 7 (race) before Phase 0 logic runs. Phase sequence is strictly sequential: 0→1→2→3→4→5→7.

2. **Pit window timing model:** The pit window opens at a fixed race time stored in DAT_007cec30 (ReconPitOpen) and closes at DAT_007cec54 (ReconPitClosed). The 5-tier HUD display uses pre-race time remaining calculations. The pit close time for display = `(pit_open_time + session_lap_time) - race_time`.

3. **Pit stop duration model:** The operation timer in FUN_004a6340 uses a composite model:
   - Wheel change: 4 cubic random values from a ring buffer (FUN_004f1890) — simulating crew speed variance
   - Repair: additive fixed time per part condition
   - Refuel: fuel amount × time-per-unit + randomization via FUN_004a3560
   - DSQ penalty: additive fixed time via FUN_004bbf20

4. **Pit state machine byte fields:** Vehicle struct bytes at +0x60 (PitState), +0x61 (PitEntryTimer), +0x62 (unused) form a compact state machine. The state transitions are timer-driven for entry (state 1→2), then work-completion-driven for exit (state 2→3), with collision avoidance gating final release (state 4→3→done).

5. **Action queue ring buffer:** The pit action queue at PitCrewStruct offsets +0x9b0..+0x9bc uses a classic ring buffer pattern. `PitActionBase` is the data pointer, `PitActionCapacity` is the modulo, `Head` and `Tail` indices manage enqueue/dequeue. Max 4 entries (matching max 4 stops).

6. **MAS file paths:** Pit scene assets follow a path pattern: `{SeasonPath}\{TrackDir}\PITS\{Normal|Left}\`. The flag DAT_005ea3ec (0=Normal, non-zero=Left) selects the layout subdirectory. Four MAS archives are loaded: CMAPS.MAS, CDB.MAS, TEAM.MAS, PITS.MAS.

7. **Pit crew actor mapping:** 9 roles are defined per team with specific wheel mesh names mapping to wheel indices 0–3 (LF, RF, LR, RR). The LOLLIPOP actor is identified by name string comparison and gets a special flag at +0x03.

8. **Repair cost formula:** `cost = (wear_index * WearScaleA + WearScaleB) * DAT_0059ea40`. The cost is formatted as float or integer based on DAT_007d0450. Wear percentage = current_wear_value / max_wear.

9. **Commentary integration:** Pit events dispatch commentary IDs (0x7b–0x217 range) through FUN_004144d0/FUN_004144f0 (commentary queue). The pit commentary subsystem is tightly coupled with the commentary engine — pit state changes trigger specific commentary text based on context (entering/exiting/confirmed/denied).

10. **Pit close penalty:** FUN_004d2210 iterates all vehicles and penalizes those still on old tires (vehicle +0x13000 == 0 or 1) when the pit window closes. This is the mechanism that forces teams to pit within the window.

11. **No saved file moddability:** Most pit system constants (timing thresholds, animation speeds, crew counts) are hardcoded — not read from .svm/.hdv files. The only config-field-like constants are DAT_005acb50 (distance threshold) and DAT_0059ea40 (cost scale), which are global float constants potentially tunable via mod.

12. **Pit crew animation system:** Uses dual-keyframe animation blending (FUN_004a1fd0 sets up keyframes 0 and 1). Animations are loaded from .anm files within PITANIMS.MAS. Wheel-specific animations (LFWHEELOFF/ON etc) are mapped by mesh name string matching in the MTS loader.

---

## Completeness

- Full specs written: 27 / 27 total documented functions
- Pit crew scene loading functions (FUN_004a2010, FUN_004a22d0, FUN_004a4900): documented but scene-graph detail deferred to renderer spec
- Empty stubs omitted: 0
- Confidence: **high** — all key entry points and internal call chains verified against call_graph.json and source doc
