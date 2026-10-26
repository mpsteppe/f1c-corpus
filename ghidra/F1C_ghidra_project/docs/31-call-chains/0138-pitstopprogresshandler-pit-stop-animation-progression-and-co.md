# Chain: PitStopProgressHandler — Pit stop animation progression and completion

Seed: FUN_004a68b0  |  System: docs/07-pit-system.md  |  Depth: 3  |  Functions: 10

---

## Overview

Drives pit stop animation progression — interpolates wheel animation speed (left/right blend), detects operation completion, clears pit state when done, stops animations, and cleans up. If same team as player, triggers UI event notification. Called from pit state machine (FUN_004a6e50) per pit stop operation tick.

## Call Tree

```
FUN_004a68b0 — PitStopProgressHandler  [trigger: per pit stop operation tick]
  +-- FUN_0040d410 — ShortComputation  [timer/state value read]  [leaf]
  +-- FUN_004f1890 — SpeedValueSetterWithGlobalMirror  [writes speed to global]  [leaf]
  +-- FUN_004f1ba0 — WheelForceParamSetterNonWet  [sets wheel force params, 1 callee]
  |     +-- FUN_004f1b50 — CameraModeSetter  [leaf]
  +-- FUN_004a5c80 — StateChangeNotify  [state change notification, 2 callees]
  |     +-- FUN_004a6200 — [undocumented]
  |     +-- FUN_004d8840 — [undocumented]
  +-- FUN_004d8760 — RaceStateTransition  [race state machine transition, 4 callees]
  |     +-- [subtree: 4 callees — docs/06]
  +-- FUN_0042a6f0 — PostPitCleanupExit  [AI post-pit cleanup, 1 callee]
  |     +-- FUN_004a6db0 — [undocumented]
  +-- FUN_00424cd0 — AICommandMessageQueueDispatcher  [AI message dispatch, 5 callees]
  |     +-- [subtree: 5 callees — docs/02]
  +-- FUN_004f1b50 — CameraModeSetter  [camera mode switch]  [leaf]
  +-- FUN_004a34a0 — PerElementConditionalActionDispatcher  [UI action dispatch, 2 callees]
  |     +-- [subtree: 2 callees — docs/20]
  +-- FUN_004e0ed0 — AudioSoundEffectController  [audio playback, 4 callees]
        +-- [subtree: 4 callees — docs/19]
```

## Step-by-Step Trace

### Level 0: FUN_004a68b0 — PitStopProgressHandler

**Trigger:** Per tick during pit stop — called from pit state machine (FUN_004a6e50) while vehicle is in pits
**Called by:** FUN_004a6e50 (from callers.json — pit state machine)
**Purpose:** Drives pit stop animation, detects completion, cleans up when done.

**Key actions:**
1. Operation in progress: interpolates wheel change/repair speed, blends left/right wheel animation
2. Reads state via FUN_0040d410 (timer/state value)
3. Sets wheel force parameters via FUN_004f1890/FUN_004f1ba0
4. On completion detected:
   - Clears pit state via FUN_004a5c80
   - Transitions race state via FUN_004d8760
   - Stops animations via FUN_0042a6f0 (post-pit cleanup)
   - Dispatches AI commands via FUN_00424cd0
   - Sets camera mode via FUN_004f1b50
5. If same team as player: triggers UI event (FUN_004a34a0)
6. Plays audio effects (FUN_004e0ed0)

**Data passed to callees:** vehicle struct pointer, pit state (active wheel, operation type, progress %)

### Level 1: Key callees

**FUN_004d8760 — RaceStateTransition (4 callees)**
Transitions race state machine: pit → running. Updates finish state, position tracking.

**FUN_00424cd0 — AICommandMessageQueueDispatcher (5 callees)**
Sends AI commands after pit completion — "resume racing", "exit pits", "catch up to pack".

**FUN_004e0ed0 — AudioSoundEffectController (4 callees)**
Plays pit exit/engine start audio effect.

**FUN_0042a6f0 — PostPitCleanupExit (1 callee)**
Handles AI-specific cleanup after exiting pit — resets AI follow target, gap tracking.

**FUN_004a5c80 — StateChangeNotify (2 callees)**
Notifies state change listeners (UI, steward) that pit operation is complete.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Progress | wheel animation time | interpolate speed | animation blend |
| Completion | state flag | detect done | cleanup trigger |
| State clear | pit state | zero flag | pit state = done |
| Race transition | race state | advance state | resumed |
| AI dispatch | AI state | send message | AI resumes |
| Audio | event type | play sound | pit exit audio |
| UI | team check | event trigger | UI notification |

## Notes

- FUN_004e0ed0 (audio controller) shared with LoadingPhase2 chain — general-purpose audio utility
- The wheel animation has left/right blend — pit crew works both sides simultaneously
- Team check for player notification: `if (param_1->teamID == playerTeamID) → trigger UI`

---
