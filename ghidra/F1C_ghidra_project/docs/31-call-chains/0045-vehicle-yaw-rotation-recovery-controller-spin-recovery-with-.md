# Chain 44: Vehicle Yaw/Rotation Recovery Controller — Spin recovery with heading blend

Seed: FUN_004f1c40  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 8 callees

---

## Overview

Triggered during vehicle dynamics update per frame. Recovers vehicle yaw orientation after a spin by blending current heading toward a target heading. Uses speed-based gain, counts grounded wheels to determine recovery mode, and uses raycast collision checking during recovery. Gated by DAT_007d0af8 and multiple speed thresholds.

## Call Tree

```
FUN_004f1c40 — Vehicle Yaw/Rotation Recovery Controller  [trigger: per-frame vehicle dynamics]
  +-- FUN_004f2320 — Vehicle Dynamics State Reset  [full recovery: set heading directly]
  |     +-- FUN_0043e360 — Physics State Zeroing/Reset for Suspension  [reset suspension]
  +-- FUN_00566e40 — EulerToRotationMatrix  [convert heading to rotation matrix]
  +-- FUN_004efb20 — 3D Transform with Matrix Multiplication  [apply transform]
  +-- FUN_004ef7c0 — AI Vehicle Path Position Tracking  [track path position]
  |     +-- FUN_00566e40 — EulerToRotationMatrix  [get orientation from rotation]
  |     +-- FUN_004ef680 — RideHeightDelta  [ride height diff]
  |     +-- FUN_004e9bd0 — 3x3 Matrix Transform with Translation  [path transform]
  |     +-- FUN_0043e4b0 — RigidBodyConstraintSolve  [constraint solve — cross-system: docs/18]
  |           +-- 4 leaf callees omitted
  +-- FUN_004ed420 — VehicleGeometryProximityTest  [raycast collision check]
  |     +-- FUN_004ea930 — 3D Vector Subtraction  [docs/20]
  |     +-- FUN_004ed750 — 3D Cross Product  [docs/20]
  |     +-- FUN_004ed710 — Vec3 Add  [docs/20]
  |     +-- FUN_004ed380 — AnisoVectorTripleProduct  [docs/06]
  |     +-- FUN_004ed7b0 — 3x3 Matrix-Vector Multiply  [docs/18]
  +-- FUN_004ebc60 — Vehicle Contact Force Accumulation  [contact forces — cross-system: docs/06]
  |     +-- FUN_004ea930 — 3D Vector Subtraction  [reads global velocity]
  |     +-- FUN_0043e5d0 — AccumulateAngularImpulse  [docs/18]
  |     +-- FUN_004ec1a0 — Collision/Spark/Particle Effects  [docs/10]
  |     +-- FUN_00463dc0 — Conditional Stride Pointer Computation  [docs/20]
  |     +-- FUN_004b2580 — Short Vector to Float with Scale  [docs/20]
  |     +-- FUN_004b2480 — [docs/20 utility]
  |     +-- 3 additional leaf callees omitted
  +-- FUN_004ec080 — Vehicle Telemetry Position Accumulator  [position tracking — cross-system: docs/06]
  |     +-- FUN_004e23d0 — 3x3 Matrix Transform  [docs/20]
  |     +-- FUN_004e16c0 — [docs/20 utility]
  |     +-- FUN_0043e6a0 — RigidBodyTransformUpdate  [docs/18]
  |     +-- FUN_00463dc0 — Team Lookup by TeamID  [docs/20]
  |     +-- FUN_004b2420 — Float-to-Short Conversion  [docs/20]
  |     +-- FUN_004b2310 — Short-to-Float Conversion  [docs/20]
  +-- FUN_004f1fe0 — AI State Machine for Pursuit  [cross-system: docs/06]
        +-- 9 callees (AI pursuit state machine — see docs/06)
```

## Step-by-Step Trace

### Level 0: FUN_004f1c40 — Vehicle Yaw/Rotation Recovery Controller

**Trigger:** Per-frame vehicle dynamics update.
**Called by:** FUN_0042c690 (unknown caller context in engine architecture chain).
**Purpose:** Recovers vehicle yaw orientation after spin, blending toward target heading with speed-based gain.

**Key actions:**
1. Checks vehicle active flag (bit 3 of *param_1+0x48bc)
2. If DAT_007d0af8 == 1 and speed above DAT_005ad1c4 threshold: resets recovery timer
3. Otherwise accumulates recovery time from param_2 (delta time)
4. If speed low (below DAT_0059e8a0) and recovery time sufficient: triggers yaw correction
5. Computes target heading via atan2 of velocity components
6. Counts active wheels vs grounded wheels to determine recovery mode
7. Partial grip: blends heading toward stored target heading
8. Full recovery: calls FUN_004f2320, sets heading directly

**Globals:** DAT_007d0af8, DAT_005ad1c4, DAT_0059e8a0

### Level 1: Key callees

**FUN_004f2320 — Vehicle Dynamics State Reset** — Sets heading directly for full recovery. Calls FUN_0043e360 to reset suspension physics.

**FUN_004ed420 — VehicleGeometryProximityTest** — Raycast collision check during recovery. 5 callees: vector subtraction, cross product, add, triple product, matrix-vector multiply.

**FUN_004ebc60 — Vehicle Contact Force Accumulation** — Accumulates contact forces from wheels. 9 callees including collision effects, angular impulse, stride computation.

**FUN_004f1fe0 — AI State Machine for Pursuit** — AI pursuit logic with 9 callees. Cross-system handoff to docs/06.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004f1c40 | Vehicle state + DT | Check spin recovery condition | recovery mode |
| FUN_004f2320 | Vehicle heading | Set heading directly | Updated orientation |
| FUN_004ef7c0 | Path data | Track position on path | Path position |
| FUN_004ed420 | Vehicle geometry | Raycast collision check | Collision distance |
| FUN_004ebc60 | Wheel contacts | Accumulate forces | Updated force accumulators |
| FUN_004f1fe0 | AI state | Pursue/follow logic | AI behavior state |

## Globals Written in This Chain

None directly — reads DAT_007d0af8, DAT_005ad1c4, DAT_0059e8a0.

## Notes

- Cross-system handoffs to docs/06 (FUN_004ebc60, FUN_004ec080, FUN_004f1fe0)
- FUN_004ef7c0 also from docs/02-ai-system — dual system role
- `hardcoded`

---
