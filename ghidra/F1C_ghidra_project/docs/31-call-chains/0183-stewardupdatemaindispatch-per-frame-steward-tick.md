# Chain 182: StewardUpdateMainDispatch — Per-Frame Steward Tick

Seed: FUN_004d4580  |  System: docs/06-session-race-logic.md  |  Depth: 3  |  Functions: 14 direct + sub-callees

---

## Overview

Main steward dispatch function called per-frame during a session. Checks session start timing, elapsed time, session type, and race phase to dispatch the appropriate steward logic: formation lap, FCY (full course yellow), green flag, pit window management, and post-race procedures. Reads/writes session state fields on param_1 (steward struct at +0xa4/+0xa8).

## Call Tree

```
FUN_004d4580 — StewardUpdateMainDispatch  [per-frame, called by Game::Restart loop]
  +-- FUN_004d0b20 — 3D Distance Check + Accumulate  [session time init at +0xa4]
  +-- FUN_00448330 — AudioDSPStateUpdate  [audio state sync, 7 sub-callees]
  +-- FUN_004d2e50 — Pit Timer / Race Phase State Machine  [18 callees — core race logic]
  |     +-- FUN_0041a500 — Session Timer  [time tracking]
  |     +-- FUN_0042d140 — Race Phase Set  [advances RacePhase global]
  |     +-- FUN_004d0ec0 — Session State  [state machine]
  |     +-- FUN_0041a6b0 — Time Update  [elapsed time]
  |     +-- FUN_004d1cd0 — Pit State Display  [HUD update]
  |     +-- FUN_004d2e20 — Pit Countdown  [pit window timer]
  |     +-- FUN_004d11d0 — Time Format Display  [string format]
  |     +-- FUN_0045bdf0 — Early Pit Penalty?  [pit exit penalty]
  |     +-- FUN_0040cde0 — Camera/Session  [state machine]
  |     +-- FUN_0040de60 — Pit Animation  [crew animation trigger]
  |     +-- FUN_0040e170 — Session End  [race finish check]
  |     +-- FUN_004bc9b0 — Jump Start Penalty  [penalty logic]
  |     +-- FUN_00461db0 — Sound Check  [audio trigger]
  |     +-- FUN_004d2210 — Pit Close  [pit lane closure]
  |     +-- FUN_0045bd10 — HUD Write  [on-screen display]
  |     +-- FUN_0058957a — Random/Check  [random number]
  +-- FUN_004d1d80 — Steward: Proximity / Gap Tracking  [6 callees — vehicle spacing]
  |     +-- FUN_004e9630 — [vehicle proximity]
  |     +-- FUN_005890aa — [math utility]
  |     +-- FUN_004d0c20 — [session lookup]
  |     +-- FUN_004d0cf0 — [position tracking]
  |     +-- FUN_004d1730 — [gap computation]
  |     +-- FUN_004b33b0 — [shared utility]
  +-- FUN_0044f460 — PackedFlagRead  [reads packed flag bits]
  +-- FUN_0044f0e0 — CollisionProxyUnregister  [shape removal]
  +-- FUN_0045bde0 — Short Computation (Delegation Wrapper)  [math helper]
  +-- FUN_004d2260 — Progress Bar + Data Store  [session progress]
  +-- FUN_0040dbc0 — Mode Validation Check  [validates mode]
  +-- FUN_0040e170 — Tick/Update Dispatch  [session update, 3 callees]
  |     +-- FUN_004347c0 — [physics update]
  |     +-- FUN_004186a0 — Session Update  [AI/driver update]
  |     +-- FUN_0040da30 — [session helper]
  +-- FUN_004d2170 — All Clear Check for Warning  [safety car/warning check]
  |     +-- FUN_004bc9b0 — Jump Start Penalty  [penalty evaluation]
  +-- FUN_004d2300 — SessionParticleTrigger  [2 callees — weather/particle]
  |     +-- FUN_00461db0 — Sound Check  [audio trigger]
  |     +-- FUN_004b33b0 — [shared utility]
  +-- FUN_00461cd0 — Session State Check  [session type validation]
  +-- FUN_004a0da0 — Set DAT_007ce25d = 1  [init guard flag]
```

## Step-by-Step Trace

### Level 0: FUN_004d4580 — StewardUpdateMainDispatch

**Trigger:** Called per-frame during active session from the game loop.

**Called by:** Game::Restart (FUN_0042d7a0, docs/01-engine-architecture.md) — part of the per-frame update dispatch.

**Purpose:** Main steward tick — manages session start, pit timer, penalty, and race phase logic. Central dispatch for all race stewardship functions.

**Key actions:**
1. Checks param_1+0xa4 — if set, performs session time initialization
2. Checks param_1+0xa8 — if set, updates elapsed time
3. If SessionType < 7 (non-race): computes remaining time, proximity update
4. If SessionType == 7 (race): switches on RacePhase (0-1, 2, 3, 4, 5-8)
   - Phase 0-1: Formation lap handling
   - Phase 2: FCY (full course yellow) / safety car
   - Phase 3: Green flag racing
   - Phase 4: Pit window management
   - Phase 5-8: Post-race / checkered flag

**Data passed to callees:** param_1 (steward context struct), session type, race phase

### Level 1: Key Callees

**FUN_004d2e50 — Pit Timer / Race Phase State Machine**
- 18 callees — the largest sub-tree in this chain
- Central race phase state machine: manages pit window open/close, formation lap countdown, race start sequence
- Calls session timer (FUN_0041a500), phase advancement (FUN_0042d140), pit state display, penalty checks
- Cross-system to audio (FUN_00461db0), camera (FUN_0040cde0), HUD (FUN_0045bd10)

**FUN_004d1d80 — Steward: Proximity / Gap Tracking**
- 6 callees — vehicle spacing and proximity monitoring
- Computes distance between vehicles, tracks gaps for overtaking and safety car detection
- Calls math utilities and position tracking functions

**FUN_0040e170 — Tick/Update Dispatch**
- 3 callees — dispatches to physics update (FUN_004347c0) and driver/AI update (FUN_004186a0)
- Part of the per-frame simulation cascade

**FUN_004d2300 — SessionParticleTrigger**
- 2 callees — triggers weather/particle effects based on session state
- Coordinates with audio system via FUN_00461db0

### Note on Remaining Callees

FUN_0044f460 (PackedFlagRead), FUN_0044f0e0 (CollisionProxyUnregister), FUN_0045bde0 (Short Computation), FUN_004d2260 (Progress Bar), FUN_0040dbc0 (Mode Validation), FUN_004d2170 (All Clear Check), FUN_00461cd0 (Session State Check), FUN_004a0da0 (Set Init Guard) are all leaf functions or shallow wrappers — no significant sub-trees.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004d4580 | param_1 steward ctx | Read +0xa4/+0xa8 timing fields | Session timing state |
| SessionType check | DAT_007c56a4 | Branch on <7 vs ==7 | Race vs non-race path |
| RacePhase switch | param_1 phase field | Dispatch to 0-1,2,3,4,5-8 | Phase-specific logic |
| FUN_004d2e50 | steward ctx + race phase | State machine tick | Pit state, penalties, timer |
| FUN_004d1d80 | vehicle position data | Gap computation | Vehicle spacing array |

## Globals Read in This Chain

| Global | Name | Used by | Purpose |
|--------|------|---------|---------|
| DAT_007c56a4 | SessionType | FUN_004d4580 | Branch on race vs practice/quali |
| DAT_007c56a8 | RacePhase | FUN_004d4580 | Phase dispatch |

## Notes

- FUN_004d2e50 is the most complex sub-tree (18 callees) — core race state machine
- Audio (FUN_00448330), camera (FUN_0040cde0), and HUD (FUN_0045bd10) subsystems are called from within steward dispatch
- The progression is: time init → proximity tracking → race phase machine → particle triggers → guard flags
- This function is the central "tick" for the steward/race director module

---
