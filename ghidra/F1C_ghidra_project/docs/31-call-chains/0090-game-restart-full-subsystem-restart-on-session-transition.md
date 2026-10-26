# Chain: Game::Restart() — Full Subsystem Restart on Session Transition

Seed: FUN_0042d7a0  |  System: docs/01-engine-architecture.md  |  Depth: 1-2  |  Functions: 10 callees

---

## Overview

State 4 in game lifecycle. Called on session transition (e.g., entering race from menu). Sets internal state to 4, then calls Restart() on ALL subsystems: Sound, Steward, RaceTimer, HWInput, CamMan, Render, OnScreen, replay, VidMan, NetComm, OSMan, and scene rendering. Each subsystem Restart() clears state and reinitializes for new session.

## Call Tree

```
FUN_0042d7a0 — Game::Restart()  [trigger: session transition, state 4 in game lifecycle]
  +-- FUN_004c8b20 — Sound::Restart()                                [depth 1: HAS 0 callees]
  +-- FUN_004a40f0 — Steward::Restart() (race control)               [leaf]
  +-- FUN_004a0fb0 — RaceTimer::Restart()                            [leaf]
  +-- FUN_00455da0 — HWInput::Restart()                              [depth 1: HAS 0 callees]
  +-- FUN_0040c9e0 — CamMan::Restart()                               [depth 1: calls FUN_00408290]
  |     +-- FUN_00408290 — State init (camera state reset)           [leaf]
  +-- FUN_004b4060 — Render::Restart()                               [depth 1: HAS 0 callees]
  +-- FUN_0049f000 — OnScreen::Restart()                             [depth 1: calls 3 callees]
  |     +-- FUN_0045bdf0 — Clear display                            [leaf]
  |     +-- FUN_0049f150 — Display layer reset                      [leaf]
  |     +-- FUN_004d82a0 — Buffer flush                             [leaf]
  +-- FUN_004fa640 — VidMan::Restart()                               [depth 1: HAS 0 callees]
  +-- FUN_00464290 — NetComm::Restart()                              [depth 1: HAS 0 callees]
  +-- FUN_004c01a0 — Unknown subsystem restart                       [depth 1: HAS 0 callees]
```

## Step-by-Step Trace

### Level 0: FUN_0042d7a0 — Game::Restart()

**Trigger:** Game state machine transition to state 4 (Restart). Called from main loop after Setup → Init.
**Called by:** FUN_0045b200 (Game Main Entry) as part of lifecycle loop.
**Purpose:** Reset all game subsystems for new session.

**Key actions:**
1. Sets param_1[0] = 4 (Restart phase)
2. Profile entry trace via game.cpp
3. Calls 10+ subsystem Restart() functions:
   - NetComm (FUN_00464290) — network stack reset
   - Sound (FUN_004c8b20) — audio system reset
   - Steward (FUN_004a40f0) — race control reset
   - RaceTimer (FUN_004a0fb0) — lap/session timer reset
   - HWInput (FUN_00455da0) — input device reset
   - CamMan (FUN_0040c9e0) — camera system reset
   - Render (FUN_004b4060) — renderer reset
   - OnScreen (FUN_0049f000) — HUD/overlay reset
   - VidMan (FUN_004fa640) — video manager reset
4. Returns 0

**Data passed to callees:** Subsystem struct pointers from game manager.

### Level 1: Callees with Deeper Chains

- **FUN_0040c9e0 (CamMan::Restart):** Calls FUN_00408290 to reset camera state to defaults. Leaf.
- **FUN_0049f000 (OnScreen::Restart):** Calls FUN_0045bdf0 (clear display), FUN_0049f150 (display layer reset), FUN_004d82a0 (buffer flush). All leaf.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0042d7a0 | gameManager ptr | state=4, dispatch | all subsystems restarted |
| FUN_0040c9e0 | camManager ptr | reset state | camera ready |
| FUN_0049f000 | screenManager ptr | clear+reset+flush | display ready |

## Globals Written in This Chain

None documented — operates on subsystem struct fields.

## Notes

Chain depth 1-2. Most subsystem Restart() functions are documented as having no further callees in call_graph.json. CamMan::Restart goes 1 level deeper (FUN_00408290). OnScreen::Restart has 3 leaf callees.

---
