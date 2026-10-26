# Chain 173: FUN_0040adb0 — Camera Shake / Nearby Vehicle Detection

Seed: FUN_0040adb0  |  System: docs/09-track-system.md  |  Depth: 2  |  Functions: 10

---

## Overview

Per-frame camera update that detects fast-moving vehicles near the player's vehicle and triggers camera shake (with optional sound). Computes scaled world position from camera array, iterates all vehicles checking proximity + speed thresholds. If triggered: applies random-direction camera shake. If not triggered: clears shake state. Always updates player camera orientation and rendering regardless of shake state.

## Call Tree

```
FUN_0040adb0 — Camera Shake / Nearby Vehicle Detection  [called by: per-frame camera update]
  +-- FUN_0040c780 — Scoring Gate Condition Check
  |     +-- FUN_004b9cf0 — returns float value
  +-- FUN_00457a00 — Collision Response with Random Perturbation
  |     +-- FUN_00457b00 — State-Activated Position Save/Restore
  |     +-- FUN_00456010 — rand
  |     +-- FUN_00456130 — apply impulse
  +-- FUN_00457b00 — State-Activated Position Save/Restore
  |     +-- FUN_00456130 — restore/process backup data
  +-- FUN_004084a0 — Short Computation / Float Global Reader  [leaf]
  +-- FUN_00541cd0 — Utility Function (Dual Dispatch)
  |     +-- FUN_00541db0 — handler (last 3 args)
  |     +-- FUN_00541d10 — handler (first 3 args)
  +-- FUN_00456060 — Two-Field Accessor  [leaf]
  +-- FUN_00456080 — Short Computation (Two-Field Accessor)  [leaf]
  +-- FUN_00542050 — CameraProjectionSetup  [leaf]  [cross-system: docs/19]
  +-- FUN_005423c0 — Two-Field Setter + Call  [leaf]
  +-- FUN_00542680 — Conditional Float Setter  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0040adb0 — Camera Shake / Nearby Vehicle Detection

**Trigger:** Per-frame camera update
**Called by:** (no callers registered in callers.json — likely called from main camera loop)
**Purpose:** Detects nearby fast vehicles and triggers camera shake

**Key actions:**
1. Computes scaled world position from camera array
2. If camera active and shake mode enabled:
   a. Iterates all vehicles checking proximity + speed thresholds
   b. If triggered: random direction via FUN_00457a00, camera shake intensity
   c. No trigger: clear shake via FUN_00457b00
3. Always updates player camera orientation via renderer calls (FUN_00542050, FUN_005423c0, FUN_00542680)
4. Checks scoring gate condition via FUN_0040c780

**Vehicle offsets read:** +0x58..0x60 (Velocity), +0x704..0x70c (Orientation), +0x744..0x74c (World position)

### Level 1: FUN_00457a00 — Collision Response with Random Perturbation

**Purpose:** Generates random-direction shake perturbation

**Key actions:**
1. Calls FUN_00457b00 to save current state
2. Calls FUN_00456010 (rand) for random direction
3. Calls FUN_00456130 to apply impulse

### Level 1: FUN_00542050 — CameraProjectionSetup

**Purpose:** Sets up camera projection matrix
**Cross-system:** docs/19-renderer.md

**Key actions:**
- Updates camera projection parameters

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Vehicle proximity | +0x744 (WorldPos) | distance check | trigger/clear |
| Vehicle speed | +0x58 (Velocity) | speed threshold check | intensity |
| Shake triggered | random seed | FUN_00457a00 | random direction impulse |
| Camera update | orientation data | FUN_00542050 | updated projection |

## Notes

- FUN_00542050 is a cross-system handoff to renderer (docs/19)
- Vehicle proximity detection reads documented struct offsets for velocity, orientation, world position
- Collision response chain (FUN_00457a00 → FUN_00457b00 → FUN_00456130) is shared with physics collision system (docs/17)
- 5 of 10 callees are leaf utilities

---
