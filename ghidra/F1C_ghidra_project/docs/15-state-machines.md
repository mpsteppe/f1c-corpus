# State Machine Analysis

## Overview

F1 Challenge uses eight global state variables to control game flow, stored in a contiguous
struct starting at `0x007c569c`. Three are true state machines (GameState, RacePhase,
InternalState) with defined transitions. The rest are mode selectors and flags set during
initialization.

**Key architectural discovery (runtime-confirmed):** The GameState setter `FUN_0042cf10`
(`game.cpp`) writes `*(this + 8) = new_state` where `this` = `0x007c569c` (InternalState
address), meaning offset `+8` = `0x007c56a4` — the same address as SessionType. During
loading transitions, SessionType is **temporarily overwritten** with GameState values (1-7
in lockstep), then set to its correct final value by session init.

**Game State Struct (0x007c569c):**
```
+0x00 (7c569c): InternalState — main loop dispatch control
+0x04 (7c56a0): SessionSubMode — online/host mode flag
+0x08 (7c56a4): SessionType / raw game state — dual-use field
+0x0c (7c56a8): RacePhase — race progression
+0x10 (7c56ac): PauseFlag — freezes all state machines
```

Extracted from 282+ static references across 6,800+ .c files.
Validated by 4 runtime traces (state polling at 20ms, 2026-07-16).

---

## GameState (DAT_007d00ec)

Primary game flow control. Values 1-7. This is the **clamped public copy** — the raw
value is written to `*(this + 8)` = `0x007c56a4` first, then clamped to
`[DAT_007d00f4, DAT_007d00f8]` and stored at `DAT_007d00ec`.

### Transition Graph (runtime-confirmed)

```
                    +-----------+
                    |  1: INIT  |
                    +-----+-----+
                          |  ~1s
                          v
                    +-----+-----+
              +---->|  2: MENU  |<---------+
              |     +-----+-----+          |
              |           |  ~0.5s         |
              |           v                |
              |     +-----+-----+          |
              |     | 3: LOADING|          |
              |     +-----+-----+          |
              |           |  ~1s           |
              |           v                |
              |     +-----+-----+          |
              |     |  4: SETUP |          |
              |     +-----+-----+          |
              |           |  ~1s           |
              |           v                |
              |     +-----+------+         |
              |     |  5: RUNNING|         |
              |     +-----+------+         |
              |           |  ~1s           |
              |           v                |
              |     +-----+------+         |
              |     |6: PRE_RACE |         |
              |     +-----+------+         |
              |           |  ~1s           |
              |           v                |  InternalState
              |     +-----+------+         |  6 (SESSION_END)
              |     |  7: RACE   |---------+
              |     +------------+
              |           |
              +---<-------+ (session cleanup → back to INIT)
```

**Runtime timing:** Each transition takes ~100-500ms. Full 1→7 loading sequence: ~15s.
Each step has a **pulse pattern**: PauseFlag toggles 0→1→0 and InternalState toggles
5→4→5, creating synchronization barriers between phases.

### Setter: FUN_0042cf10 (game.cpp)

`void __thiscall FUN_0042cf10(int this, int new_state)`

Single setter. `this` = `0x007c569c` (game state struct base).

**Write path:**
1. `*(this + 8) = new_state` — writes raw value to struct (clobbers SessionType address)
2. `DAT_007d00ec = clamp(new_state, DAT_007d00f4, DAT_007d00f8)` — clamped public copy

**Transition side effects:**
| From | To | Side effect |
|------|----|-------------|
| any | 2, 3, 4 | FUN_004c01a0 (session cleanup) |
| 4 | 5 | FUN_004c01a0 (session cleanup) |
| 5 | 6 | Formation lap init: iterates VehicleCount, calls FUN_004bc320 per vehicle. Championship (RaceMode==4): calls FUN_004c2830(1) for grid setup |
| 6 | 7 | Multiplayer: logs "setting vehicle places for RACE", calls FUN_00462e20/FUN_00462a10. All modes: FUN_004bc330 + FUN_004c6f10 per vehicle |

### Main Loop Consumer: FUN_004a0fd0 (SessionStateMachine)

Called each frame. Return value drives main loop:
| Return | Meaning | Trigger |
|--------|---------|---------|
| 4 | Exit game | DAT_007ce25d flag (ESC/quit) |
| 5 | Continue running | Normal operation (returns InternalState) |
| 6 | Session end | DAT_007ce25e/DAT_007ce260 flags, or post-race return-to-menu |

### Runtime Evidence

**Trace: full race lifecycle** (state_full_race.log, state_formation_race.log):
```
GameState: 7→1→2→3→4→5→6→7  (loading sequence, ~15s)
SessionType mirrors exactly:  1→2→3→4→5→6→7  (same timestamps)
```
Each transition paired with PauseFlag pulse and InternalState 5↔4 toggle.

**Trace: race exit** (both traces):
```
InternalState: 5→6 (SESSION_END) → 6→2  (triggers return to menu)
GameState: 7→1  (race → init, starts next loading cycle)
```

---

## InternalState (DAT_007c569c)

Main loop dispatch control variable. Base of game state struct (`this` pointer).

### Value Table (runtime-confirmed)

| Value | Name | Observed context |
|-------|------|-----------------|
| 2 | IDLE | Resting state between sessions |
| 3 | LOADING | Active during load sequence (briefly) |
| 4 | PROCESSING | Synchronization barrier — active between each GameState step |
| 5 | READY | Normal running state — returned by SessionStateMachine as "continue" |
| 6 | SESSION_END | Post-race return-to-menu trigger. NOT an error — fires every normal race end |

### Pulse Pattern (runtime-confirmed)

During loading, each GameState transition produces:
```
InternalState: 5 (READY) → 4 (PROCESSING)
  GameState advances (e.g. 3→4)
  PauseFlag: 0→1 (brief pause)
InternalState: 4 (PROCESSING) → 5 (READY)
  PauseFlag: 1→0 (resume)
```
This creates synchronization barriers ensuring each loading phase completes before the next.

---

## SessionType (DAT_007c56a4)

Session mode selector. **Dual-use address:** also receives raw GameState values during
loading transitions (see GameState setter). Final value set by session initialization
after loading completes.

### Runtime Discovery

During loading: SessionType mirrors GameState values 1→2→3→4→5→6→7 (temporary clobber).
After loading stabilizes: holds correct session mode value for the rest of the session.

Values 0-5 in static analysis (PRACTICE_FP1 through SERVER) are the **real session types**
checked by game logic — NOT the transient loading values.

### Value Table

| Value | Name | Usage count | Key checkers |
|-------|------|-------------|-------------|
| 0 | PRACTICE_FP1 | 3 | FUN_004d3cf0 (SessionDataLoad) |
| 1 | PRACTICE_FP2 | 2 | FUN_0042c1a0 (DynMan::Init), FUN_004fb910 |
| 2 | PRACTICE_FP3 | — | Inferred from enum |
| 3 | PRACTICE_FP4 | 2 | FUN_004a4110 (AI Overtaking Aggression) |
| 4 | PRACTICE_FP5 | — | Inferred from enum |
| 5 | SERVER/ONLINE | 17 | 13 functions: AI corner speed, overtake, session phase, timer, hotlap |
| 6 | QUALIFYING | — | Steward dispatch, penalty system |
| 7 | RACE | 87 | 47+ functions: AI, sound, steering, pit, scoring |
| 9 | ? | 3 | FUN_004beb10 (AI Overtake/Collision Detection) |

**Branching patterns:**
- `SessionType < 7`: practice/qualifying (time-limited)
- `SessionType == 7`: race (lap-limited, pit stops, formation lap)
- `SessionType == 5`: multiplayer/online checks
- `SessionType != 7`: skip race-only features

### Cross-Dependencies

SessionType gates which state machines are active:
- **RacePhase**: Only ticks when SessionType == 7. Steward dispatch (FUN_004d4580)
  checks `if (SessionType != 7) return` before RacePhase switch.
- **FormationLap**: Only relevant for SessionType == 7.
- **Pit system**: Full logic only for SessionType == 7.

---

## RacePhase (DAT_007c56a8)

Race progression state machine. Values 0-8. Only active when SessionType == 7.
Offset `+0x0c` in game state struct.

### Transition Graph (runtime-confirmed)

```
  +-------------+                         +---------------+
  | 0: PRE_START|--- init sets directly ->| 2: GRID_READY |
  +-------------+                         +-------+-------+
                                                  |
  +-------------+                    formation lap period
  | 1: (unused) |                    (~15s observed)
  +-------------+                                 |
                                                  v
                                          +-------+-------+
                                          | 3: GREEN_FLAG |
                                          +-------+-------+
                                                  |
                                           2.5+ min racing
                                                  |
                                                  v
                                          +-------+-------+
                                          | 4: COOLDOWN   |
                                          +-------+-------+
                                                  |
                                              ~8-10s
                                                  v
                                          +-------+-------+
                                          | 5: FINISHING  |
                                          +-------+-------+
                                                  |
                                            ~45s post-race
                                                  |
                                                  v
                                          +-------+-------+
                                          |   8: DONE     |
                                          +---------------+
                                     (skips 6, 7 — never observed)
```

### Runtime-Confirmed Phase Names

Static analysis names were partially wrong. Runtime reveals actual meanings:

| Value | Static name | Runtime name | Evidence |
|-------|-------------|-------------|----------|
| 0 | PRE_START | PRE_START | Set during init, transitions immediately to 2 |
| 1 | FORMATION | (not observed) | Never seen in 4 traces, even with formation lap ON |
| 2 | GREEN_FLAG | **GRID_READY** | Formation lap happens IN this phase (15.4s before 2→3). Not the green flag moment |
| 3 | RACING | **GREEN_FLAG** | Actual green flag / race start. 2→3 marks lights out |
| 4 | CAUTION | **COOLDOWN** | Post-leader-finish phase. ~8s duration |
| 5 | RED_FLAG | **FINISHING** | Remaining vehicles finishing. ~45s duration |
| 6 | CHECKERED | (not observed) | Never reached in any trace — may be dead code |
| 7 | POST_RACE | (not observed) | Never reached in any trace — may be dead code |
| 8 | DONE | DONE | Session complete. Most-checked value (28 refs). Direct jump from 5 |

### Steward Dispatch: FUN_004d4580

Main RacePhase consumer. `switch(DAT_007c56a8)` cases:

| Case | Logic |
|------|-------|
| 0, 1 | Wait for start flag (`param+0xc1`). When set: play start sound, display timer. If `UIRacePhaseFlag != 0`: queue transition to phase 2 |
| 2 | Formation/grid phase. Check start conditions + elapsed time. Triggers lights out (FUN_0040e170). If `PhaseGateFlag`/`DAT_007cee88 != 0`: `FUN_0042d140(3)` → GREEN_FLAG. **Else: `FUN_0042d140(4)` directly → COOLDOWN, skipping green flag entirely** (raw decompile `FUN_004d2e50`, see docs/41; live-confirmed 2026-07-22: `DAT_007cee88` stayed 0 through the full gridwalk and RacePhase went 2→4 with no 3 in between) |
| 3 | Racing. Check all vehicles completed (FUN_004d2170 iterates VehicleCount). If all done → FUN_004d2300 (queue next phase) |
| 4 | Wait for `param+0xd8 == 0x7f7fffff` (FLT_MAX sentinel). Then advance |
| 5-8 | Post-race: compute remaining time, proximity logic, check multiplayer end |

### Command Queue Pattern

Transitions enqueued, not direct writes:
- **FUN_004d2260(phase, time)** — "set phase" command (type 0x15). Called with phase=2, 3.
- **FUN_004d2300()** — "advance phase" command (type 0x14). 3.0s delay (single) / 2.5s (multiplayer).

### Runtime Evidence

**Trace: mid-race (state_race_start.log):**
```
RacePhase: 2→3  @ +12.4s  (green flag)
RacePhase: 3→4  @ +157s   (leader finished)
RacePhase: 4→5  @ +167s   (cooldown complete, +9.8s)
```

**Trace: full lifecycle (state_formation_race.log):**
```
RacePhase: 0→2  @ init    (direct set during loading)
RacePhase: 2→3  @ +15.4s after unpause  (formation lap was ~15s in phase 2)
RacePhase: 3→4  @ +167s   (leader finished)
RacePhase: 4→5  @ +175s   (+8.2s cooldown)
RacePhase: 5→8  @ +221s   (+45.4s finishing period, skips 6/7)
```

Phase 1 never observed. Phase 6, 7 never observed. May be checked by code but never set,
or reserved for features not in this build (safety car restart? red flag restart?).

---

## WeatherMode (DAT_007cf080)

Weather condition selector. Set during session init. Stable at 0 (DRY) in all traces.

| Value | Name | Checkers |
|-------|------|----------|
| 0 | DRY | FUN_004fcaa0, FUN_004fcc30 |
| 1 | LIGHT_RAIN | FUN_004fcc30 |
| 2 | RAIN | Inferred |
| 3 | HEAVY_RAIN | FUN_004fcc30 |
| 4 | STORM | FUN_004fcc30 |
| 5 | VARIABLE | FUN_004fcc30 — dynamic weather, may trigger runtime changes |

---

## RaceMode (DAT_007d0410)

Session structure selector. Set from menu UI.

| Value | Name | Eq checks |
|-------|------|-----------|
| 0 | SINGLE_RACE | 1 |
| 1 | WEEKEND | 1 |
| 2 | QUICK_RACE | 2 |
| 3 | CHAMPIONSHIP | 1 |
| 4 | CHAMPIONSHIP_ALT | 12 |
| 5 | MULTIPLAYER | 12 |
| 6 | MONITOR | 1 |

**Runtime:** Observed as 3 (CHAMPIONSHIP) across all traces. Value 3 vs 4: likely
3 = championship menu, 4 = championship session active. Stable during gameplay.

**Backup/restore:** DAT_007d0418 and DAT_007d041c serve as backup registers.

---

## RaceActiveFlag (DAT_007d0308)

**NOT a boolean** as originally assumed. Runtime observed value = 3 during active race,
stable throughout. Likely a bitfield or multi-state enum.

Static analysis: 19 functions check `== 0`, 24 check `!= 0`. All comparisons are
against zero — non-zero means "active" regardless of specific value.

No transitions observed in any trace (stable at 3 throughout race lifecycle).

---

## Supporting Flags

### PauseFlag (DAT_007c56ac)

| Value | Meaning |
|-------|---------|
| 0 | RUNNING |
| 1 | PAUSED |

**Runtime behavior:** Pulses 0→1→0 during each GameState loading transition
(synchronization barrier). Also set to 1 during ESC/pause menu.

Checked by FUN_004d4580 (steward dispatch): if paused, skip all phase logic.

### FormationLapFlag (DAT_007cebc4)

| Value | Meaning |
|-------|---------|
| 0 | NO |
| 1 | YES |

**Runtime:** Stable at 1 when formation lap enabled. Formation lap period occurs
during RacePhase 2 (GRID_READY), NOT in a separate RacePhase 1.

---

## Auxiliary State Variables (runtime-discovered)

### TimingMode (DAT_008ab6e4)

| Value | Observed |
|-------|----------|
| 0 | Outside race session |
| 1 | During race session (set at load start, cleared after results) |

Branched in steward dispatch (FUN_004d4580): value 2 = special timing path.

### NetworkActive (DAT_007ce254)

Toggle pattern around session boundaries:
```
Load start:  0→1
Race start:  1→0  (synchronized with unpause)
Race end:    0→1
After results: 1→0
```
Despite the name, likely an internal session-readiness flag, not actual network activity.

### PlayerVehPtr (DAT_007c54e8)

Vehicle pointer. Set to 0 during cleanup, allocated (~0x5EC2D8) during init.
Changes once per session load.

---

## Cross-Variable Dependencies

```
RaceMode (set from menu)
   |
   +-- determines --> SessionType (set at session init, after loading clobber clears)
   |                    |
   |                    +-- == 7 (RACE) --> enables RacePhase state machine
   |                    |                    |
   |                    |                    +-- RaceActiveFlag (non-zero guard)
   |                    |                    +-- FormationLapFlag (grid phase behavior)
   |                    |                    +-- PauseFlag (freezes phase machine)
   |                    |
   |                    +-- < 7 (practice/qualifying) --> time-based session
   |
   +-- == 4 (CHAMPIONSHIP) --> enables Season Scoring
       == 5 (MULTIPLAYER)  --> enables network sync
```

**Loading orchestration:**
```
InternalState 2 (IDLE)
  --> 3 (LOADING) + TimingMode 0→1 + NetworkActive 0→1
  --> GameState steps 1→2→3→4→5→6→7 (each with PauseFlag + InternalState pulse)
  --> RacePhase set to 2, PlayerVehPtr allocated, TotalRaceLaps set
  --> InternalState 4→5 (READY) + PauseFlag 1→0 + NetworkActive 1→0
  --> Race begins

Session end:
  --> InternalState 5→6 (SESSION_END)
  --> InternalState 6→2 (IDLE)
  --> TimingMode 1→0 + NetworkActive toggle
  --> GameState 7→1 (back to INIT for next cycle)
```

---

## Runtime Validation Summary

### Traces Captured

| File | Duration | Scenario | Key transitions |
|------|----------|----------|----------------|
| `trace_20260715_231511.log` | 0.5s | Pre-start (22 vehicles) | None (stable) |
| `trace_20260715_232044_3000frames.log` | 26.6s | Mid-race | None (stable) |
| `state_race_start.log` | 3.6 min | Mid-race → pause | RacePhase 2→3→4→5 |
| `state_full_race.log` | 4.4 min | Menu → race → menu (CTRL+T skip) | Full GameState cycle, RacePhase 0→2→4→5→8 |
| `state_formation_race.log` | 4.4 min | Menu → full race → menu | Full GameState cycle, RacePhase 0→2→3→4→5→8 |

### Confirmed

- Single-threaded (TID 32488)
- GameState/SessionType lockstep during loading (shared struct write at `this+8`)
- Loading pulse pattern (PauseFlag + InternalState synchronization)
- RacePhase 2 = formation/grid phase (formation lap happens here, ~15s)
- RacePhase 3 = actual green flag / racing start
- RacePhase 5→8 direct jump (phases 6, 7 never observed)
- Phase 1 never observed (even with formation lap ON)
- InternalState 6 = normal session end (not error)
- RaceActiveFlag = 3 during active race (not boolean)
- TotalRaceLaps stored as float

### Not Yet Captured

- Session type changes (practice → qualifying within Weekend mode)
- Qualifying session behavior (SessionType=6 steady state)
- Weather mode changes during VARIABLE mode
- RaceActiveFlag transitions (never changed in any trace)
- Multiplayer session behavior
- Values 6, 7 of RacePhase — may be dead code or require specific race conditions
