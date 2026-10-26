# Chain: ParticleEffectUpdateDispatch — Per-Frame Particle Processing

Seed: FUN_004eb430  |  System: docs/19-renderer.md  |  Depth: 4  |  Functions: 12

---

## Overview

Triggered per frame from Main Game Tick Update (`FUN_0042c690`). Processes all 17 active particle effect slots per vehicle — wind/force modulation, rain detection, intensity thresholding, spawn/deletion, and decay timing. Most complex sub-branches handle vehicle contact force accumulation (for collision particle triggers) and collision detection system queries.

## Call Tree

```
FUN_004eb430 — ParticleEffectUpdateDispatch  [trigger: per-frame main game tick]
  +-- FUN_004ebc60 — VehicleContactForceAccumulation  [9 callees — collision force → particles]
  |     +-- FUN_004ea930 — Read Global Velocity
  |     +-- FUN_0043e5d0 — Contact Geometry
  |     +-- FUN_004ec1a0 — Collision Sound
  |     +-- FUN_004b2580 — Debris Effect Trigger
  |     +-- 5 additional leaf callees omitted
  +-- FUN_004ea970 — CollisionDetectionSystem  [8 callees]
  +-- FUN_004ec080 — VehicleTelemetryPosAccumulator  [6 callees, 11 struct offsets]
  +-- FUN_004e9980 — ComputeSlipVelocityNorm  [vehicle struct +0x00–0x20, 8 offsets]
  +-- FUN_004e96c0 — VehicleWheelContactProximityCheck  [4 struct offsets]
  +-- FUN_004f8850 — VisualEffectSpawner  [spawns with direction/distance]
  +-- FUN_0040f4b0 — ModeDispatchSwitch  [3 callees]
  +-- FUN_0040f550 — UI/CameraModeDispatch  [2 callees, 3 offsets]
  +-- 5 additional leaf callees omitted
```

## Step-by-Step Trace

### Level 0: FUN_004eb430 — ParticleEffectUpdateDispatch

**Trigger:** Called from FUN_0042c690 (Main Game Tick Update, docs/01)
**Called by:** FUN_0042c690 — main game tick update
**Purpose:** Main particle update loop — processes all active effects per frame.

**Key actions:**
1. Resets flags, checks vehicle mode (`*param_1 + 0x48bc` bit 0)
2. Clears expired effect slots (17 slots, stride 7)
3. Gets wind/force via FUN_004e9980 + FUN_004be340
4. Gets rain via FUN_004e96c0 + FUN_004be4e0
5. Normalizes effect weights by max intensity
6. Switches on effect type (0–5, impact/continuous/debris/smoke/fire)
7. If intensity > threshold: computes world-space offset from vehicle rotation
8. Calls FUN_004f8850 to spawn visual effect
9. Updates effect timers (decay by delta)
10. Calls FUN_004ec080 + FUN_0040f550 for decay
11. Handles wind vector normalization

**Globals:** DAT_008adaf8, DAT_008ad400, DAT_008aae70, DAT_008ab274, DAT_007cf728, DAT_007d0c60 (TireWearMultiplier)

**Data passed to callees:** Vehicle struct pointer, effect slot array (17 slots), wind/force vectors, rain state.

### Level 1: FUN_004ebc60 — VehicleContactForceAccumulation

**Trigger:** Called from particle dispatch during collision effect processing
**Purpose:** Accumulates wheel contact forces, branches on collision type for particle effects.

**Key actions:**
1. Reads 3x3 rotation matrix at param_1+0x34b0–0x34d0
2. Reads reference velocity via FUN_004ea930
3. Computes local-space force and torque contributions
4. Accumulates force at +0x34f8–0x3500, torque at +0x3504–0x350c
5. Reads collision type at +0x32bc:
   - Type 0: processes contact position/velocity, calls FUN_004ec050, FUN_0043e5d0
   - Type 0/1 with param_3 != 0: calls FUN_004ec1a0 (collision sound)
   - Type 2: triggers debris/particle via FUN_00463dc0, FUN_004b2580, FUN_0045eb00

### Level 2: FUN_004ea930 — Read Global Velocity

**Trigger:** Called from ContactForceAccumulation
**Purpose:** Reads global velocity vector from vehicle struct for force computation.

### Level 2: FUN_0043e5d0 — Contact Geometry

**Trigger:** Called from ContactForceAccumulation for type 0 collisions
**Purpose:** Processes contact point geometry for collision response.

### Level 2: FUN_004b2580 — Debris Effect Trigger

**Trigger:** Called from ContactForceAccumulation for type 2 collisions
**Purpose:** Triggers debris particle effect from collision.

### Level 1: FUN_004ea970 — CollisionDetectionSystem

**Trigger:** Called from particle dispatch for collision-aware effects
**Purpose:** Queries collision detection system for particle spawning context.

### Level 1: FUN_004ec080 — VehicleTelemetryPosAccumulator

**Trigger:** Called from particle dispatch for telemetry
**Purpose:** Accumulates vehicle position telemetry. 11 struct offsets.

### Level 1: FUN_004e9980 — ComputeSlipVelocityNorm

**Trigger:** Called from particle dispatch for wind/force
**Purpose:** Computes slip velocity norm from wheel contact data (8 struct offsets).

### Level 1: FUN_004e96c0 — VehicleWheelContactProximityCheck

**Trigger:** Called from particle dispatch for rain detection
**Purpose:** Checks wheel contact proximity for rain spray effect.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004eb430 | Vehicle state, wind, rain | Effect slot iteration | Updated particles |
| FUN_004ebc60 | Wheel contact forces | Force accumulation + type switch | Collision sounds, debris |
| FUN_004e9980 | Wheel contact data | Slip norm computation | Wind/force vector |
| FUN_004e96c0 | Wheel proximity | Contact check | Rain intensity |
| FUN_004f8850 | Effect type, position, direction | Spawn | Visual effect instance |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008adaf8 | EffectCount | FUN_004eb430 | Active effect counter |
| DAT_008ad400 | EffectArray | FUN_004eb430 | Effect data array |
| DAT_007d0c60 | TireWearMultiplier | FUN_004eb430 (reader) | Tire wear scaling |

## Notes

- Most complex callee: FUN_004ebc60 (9 callees) handles collision-force-to-particle routing
- Second most complex: FUN_004ea970 (8 callees) is the collision detection system query
- Wind and rain detection are separate sub-chains feeding into the main dispatch
- FUN_004eb430 references DAT_007d0c60 (TireWearMultiplier) — links particle effects to tire wear state
- 5 additional leaf callees omitted from call tree

---
