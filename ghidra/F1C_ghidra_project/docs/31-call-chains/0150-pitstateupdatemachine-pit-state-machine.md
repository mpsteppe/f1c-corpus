# Chain: PitStateUpdateMachine — Pit State Machine

Seed: FUN_004a6e50  |  System: docs/07-pit-system.md  |  Depth: 4  |  Functions: 10

---

## Overview

Triggered from Vehicle Physics Mode Dispatcher (`FUN_004e4930`). Main pit state machine managing vehicle pit entry, in-pit service, exit, and collision avoidance. States: 1 (entering), 2 (in pits), 3 (exiting), 4 (collision avoidance). Most complex sub-branch is the Pit Stop Progress/Completion Handler (`FUN_004a68b0`, 10 callees), which drives pit animation progression, wheel animation, and completion state.

## Call Tree

```
FUN_004a6e50 — PitStateUpdateMachine  [trigger: per-vehicle physics tick]
  +-- FUN_004a68b0 — PitStopProgressHandler  [10 callees]
  |     +-- FUN_004f1890 — Pit Animation Speed Interp
  |     +-- FUN_004f1ba0 — Wheel Animation
  |     +-- FUN_004a5c80 — StateChangeNotify
  |     +-- FUN_00424cd0 — AICommandQueueDispatch
  |     +-- FUN_004a34a0 — Event Trigger (same team)
  |     +-- FUN_004f1b50 — Pit Anim
  |     +-- FUN_004e0ed0 — Vehicle State
  |     +-- FUN_004d8760 — Pit Work Complete
  |     +-- FUN_0042a6f0 — Timer
  |     +-- FUN_0040d410 — Computation
  +-- FUN_004a6200 — PitStopReadyCheck  [7 callees]
  +-- FUN_004a5f20 — ExitingPitsUnderRedPenalty  [5 callees]
  +-- FUN_004a6b80 — CollisionAvoidanceCheck  [3 callees]
  +-- FUN_004a5c80 — StateChangeNotify  [2 callees, 3 globals]
  +-- 5 additional leaf callees omitted
```

## Step-by-Step Trace

### Level 0: FUN_004a6e50 — PitStateUpdateMachine

**Trigger:** Called from FUN_004e4930 (Vehicle Physics Mode Dispatcher, docs/06)
**Called by:** FUN_004e4930 — vehicle physics mode dispatcher
**Purpose:** Main pit state machine — entering/in-pits/exiting/collision avoidance.

**Key actions:**
1. State 1 (entering): timer check, transition to 0
2. State 2 (in pits): check work complete via FUN_004a68b0, clear flag, resume
3. State 3 (exiting): normal or emergency exit via FUN_004a5f20
4. State 4: collision avoidance check via FUN_004a6b80

**Struct offsets:** +0x60 (PitFlag), +0x61 (PitState), +0x62 (PitEntryTimer)

**Data passed to callees:** Vehicle struct with pit state fields at +0x60–+0x62.

### Level 1: FUN_004a68b0 — PitStopProgressHandler

**Trigger:** Called from pit state machine when in pits (state 2)
**Purpose:** Drives pit stop animation progression and completion.

**Key actions:**
1. Operation in progress: interpolated speed, wheel animation, left/right blend
2. Operation complete: clear pit state, stop animations, cleanup
3. If same team as player: trigger event via FUN_004a34a0

**Data passed to callees:** Vehicle struct, animation progress, wheel indices.

### Level 2: FUN_004f1890 — Pit Animation Speed Interp

**Trigger:** Called from progress handler
**Purpose:** Interpolates pit animation speed based on progress.

### Level 2: FUN_004f1ba0 — Wheel Animation

**Trigger:** Called from progress handler
**Purpose:** Animates wheel change during pit stop.

### Level 2: FUN_004a5c80 — StateChangeNotify

**Trigger:** Called from progress handler (and seed directly)
**Purpose:** Notifies state change with global flags.

**Globals:** Multiple referenced (3 total).

### Level 2: FUN_00424cd0 — AICommandQueueDispatch

**Trigger:** Called from progress handler
**Purpose:** Dispatches commands to AI driver command queue. 5 callees (FUN_004a46f0, FUN_0042adb0, FUN_004c6d90, FUN_004a5c80, FUN_00429ee0).

### Level 2: FUN_004a34a0 — Event Trigger

**Trigger:** Called from progress handler when same team as player
**Purpose:** Triggers pit event (audio/notification).

### Level 1: FUN_004a6200 — PitStopReadyCheck

**Trigger:** Called from pit state machine
**Purpose:** Checks if pit stop work is ready to begin. 7 callees.

### Level 1: FUN_004a5f20 — ExitingPitsUnderRedPenalty

**Trigger:** Called from pit state machine for emergency exit
**Purpose:** Handles exiting pits under red penalty conditions. 5 callees.

### Level 1: FUN_004a6b80 — CollisionAvoidanceCheck

**Trigger:** Called from pit state machine (state 4)
**Purpose:** Checks if collision avoidance is needed in pit lane. 3 callees.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004a6e50 | PitState (+0x61), PitFlag (+0x60) | State switch | State transition |
| FUN_004a68b0 | Animation progress | Speed interp + cleanup | Updated pit state |
| FUN_004a6200 | Vehicle state | Readiness check | Go/no-go for service |
| FUN_004a5f20 | Exit type | Emergency or normal exit | Exit animation |
| FUN_004a6b80 | Nearby vehicles | Proximity check | Avoid maneuver |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0b28 | MultiplayerFlag | via state notification | Multiplayer state |

## Notes

- Most complex callee: FUN_004a68b0 with 10 sub-callees — all documented above
- Pit state is stored in 3 bytes at vehicle offsets +0x60 (flag), +0x61 (state), +0x62 (timer)
- State 0 appears to be a transient "waiting" state between entering and in-pits
- FUN_004a6200 (PitStopReadyCheck) at 7 callees is the second most complex branch
- 5 additional leaf callees omitted from call tree

---
