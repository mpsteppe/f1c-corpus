# Chain: Main Camera Director Update — Per-Frame Camera Director

Seed: FUN_0040ca30  |  System: docs/09-track-system.md  |  Depth: 3  |  Functions: 16

---

## Overview

Per-frame camera director update. Called every frame during the game loop (state 5, Game::Post). Updates camera target tracking, camera state machine, orientation, and scene node synchronization. Routes between on-track (follow vehicle) and off-track (pit camera) modes based on player state.

## Call Tree

```
FUN_0040ca30 — Main Camera Director Update  [per-frame, Game::Post]
  +-- FUN_0040c7a0 — Camera Target Update on Player Change
  |     +-- FUN_004e0ed0 — vehicle lookup
  |     +-- FUN_0040c8d0 — target set
  +-- FUN_0040c910 — Short Computation (Indirect Read)
  +-- FUN_00409890 — [undocumented, leaf]
  +-- FUN_00542460 — Triple Field Getter (Variant)
  +-- FUN_00542420 — Two-Call Delegation
  |     +-- FUN_00542490 — field get
  |     +-- FUN_00542460 — field get
  +-- FUN_004d8860 — Conditional Branch by Flag (scene update)
  |     +-- FUN_004d8880 — flag check
  +-- FUN_0040be70 — Keyboard Input Action Mapper
  |     +-- FUN_0040d290 — Camera Target: Race Leader
  |     +-- FUN_0040d340 — Camera Target: Current Tracked Vehicle
  |     +-- FUN_0040c720 — input decode
  |     +-- FUN_0040cde0 — camera mode switch
  +-- FUN_0040c070 — Timer-based state trigger with random outcome
  |     +-- FUN_0040c780 — timer check
  |     +-- FUN_0040cd60 — random selection
  |     +-- FUN_0040cde0 — mode switch
  |     +-- FUN_0040d290 — target leader
  |     +-- FUN_0040d360 — random target
  +-- FUN_0040c5b0 — Camera Mode Change Request
  |     +-- FUN_0040cde0 — mode switch
  +-- FUN_004f0d20 — Camera FOV / Zoom by Proximity
  |     +-- FUN_004d1140 — FOV calc
  |     +-- FUN_004efb20 — session state
  |     +-- FUN_004e2ca0 — zoom curve
  +-- FUN_0040c870 — short computation (leaf)
  +-- FUN_0053d450 — Short Computation / Call Wrapper
  |     +-- FUN_0055c9c0 — conditional
  +-- FUN_004ccdc0 — ParticlePositionAdd
        +-- FUN_004ccb30 — particle update
```

## Step-by-Step Trace

### Level 0: FUN_0040ca30 — Main Camera Director Update

**Trigger:** Called per-frame during Game::Post loop (state 5).
**Called by:** FUN_004b8ae0 (unknown caller in scenario/render loop).
**Purpose:** Updates all camera director state: target tracking, orientation, mode transitions.

**Key actions:**
1. Calls FUN_0040c7a0 for target update
2. Calls FUN_0040c910 for state computation
3. If not initialized: set flag, call FUN_00409890
4. Get orientation vectors, call FUN_004d8860 for scene update
5. If not skipping: read player position or vtable target, compute camera matrix
6. On-track: follow vehicle; Off-track: pit camera via vtable+0x1c

**Data passed to callees:** Camera director struct pointer (param_1), vehicle pointers, orientation vectors.

### Level 1: FUN_0040c7a0 — Camera Target Update on Player Change

**Trigger:** Called per-frame to update tracked target.
**Purpose:** Detects player vehicle change and updates camera target accordingly.

**Key actions:**
1. Calls FUN_004e0ed0 for vehicle lookup
2. Calls FUN_0040c8d0 to set target

### Level 1: FUN_0040be70 — Keyboard Input Action Mapper

**Trigger:** Processes keyboard input for camera mode changes.
**Called by:** Camera director update.
**Purpose:** Maps key presses to camera actions (target selection, mode switch).

**Key actions:**
1. Calls FUN_0040d290 — set target to race leader
2. Calls FUN_0040d340 — set target to current tracked vehicle
3. Calls FUN_0040c720 — decode input
4. Calls FUN_0040cde0 — switch camera mode

### Level 1: FUN_0040c070 — Timer-based State Trigger

**Trigger:** Auto-switch timer for camera director.
**Purpose:** Timer-driven camera mode cycling with random target selection.

**Key actions:**
1. Calls FUN_0040c780 — check timer
2. Calls FUN_0040cd60 — random selection
3. Calls FUN_0040cde0 — switch mode
4. Calls FUN_0040d290 — target leader
5. Calls FUN_0040d360 — random target

### Level 1: FUN_004f0d20 — Camera FOV / Zoom by Proximity

**Trigger:** Called per-frame to compute camera FOV.
**Purpose:** Adjusts camera FOV and zoom based on vehicle proximity/speed.

**Key actions:**
1. Calls FUN_004d1140 — FOV calculation
2. Calls FUN_004efb20 — session state check
3. Calls FUN_004e2ca0 — zoom curve evaluation

### Level 1: FUN_004ccdc0 — ParticlePositionAdd

**Trigger:** Updates particle positions relative to camera.
**Purpose:** Adds/updates particle effects relative to camera position.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Target update | PlayerChange flag | lookup vehicle | target vehicle ptr |
| Orientation | vehicle pos | compute matrix | camera matrix |
| FOV/Zoom | speed, proximity | curve eval | FOV value |
| Scene update | camera matrix | sync scene nodes | updated scene graph |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007c54e0 | PlayerVehiclePtr +8 | Camera director | current camera target |

## Notes

- 13 callees, depth 2-3. Deepest: FUN_0040c070 (timer trigger) with 5 sub-callees.
- Camera director is a state machine: keyboard input → mode switch → target update → matrix compute → scene sync.
- Cross-system: calls FUN_004f0d20 (docs/06 session logic) for FOV computation.

---
