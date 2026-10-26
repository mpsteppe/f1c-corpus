# Chain: SteeringGeometryUpdate — Updates steering/suspension geometry per wheel corner

Seed: FUN_00442060  |  System: docs/10-vehicle-physics.md  |  Depth: 6  |  Functions: ~5

---

## Overview

FUN_00442060 updates steering and suspension geometry for each wheel corner. Called from the vehicle physics update, it computes steering angle from input, applies per-wheel steering offsets with random variation from ring buffer (DAT_008aae70), clamps to max angle (12.6°), iterates suspension components to apply steering rotation, and accumulates steering angle for damage detection. Sets ReasonCode=4 when accumulated angle exceeds damage threshold.

## Call Tree

```
FUN_00442060 — SteeringGeometryUpdate  [trigger: per-vehicle physics tick]
  +-- FUN_00441450 — PhysicsSubObjectFree  [sub: 1]
  +-- FUN_00435e00 — Matrix3x3VectorMultiply  [leaf]
  +-- FUN_004388d0 — Mat3x3MulVec  [leaf]
  +-- FUN_0056d020 — 3x3 Matrix Inverse & Coordinate Transform  [sub: 1]
```

## Step-by-Step Trace

### Level 0: FUN_00442060 — SteeringGeometryUpdate

**Called by:** FUN_004ec1a0 (vehicle physics update)
**Purpose:** Updates steering/suspension geometry per wheel corner.

**Key actions:**
1. Computes steering angle: `param_3 * _DAT_0059ed78`
2. Calculates per-wheel steering offset (0=FL, 1=FR, 2=RL, 3=RR):
   - Front wheels (0,3): add sin(random) * steering
   - Rear wheels (1,2): subtract
3. Clamp to max steering angle (±0.22 radians ≈ 12.6°)
4. Compute cos(random) * steering for caster offset
5. Calls FUN_00441450 for geometry refresh
6. Iterates suspension components (stride 0x30):
   - Matches corners by wheel ID
   - Applies steering rotation to wheel position/orientation
   - Transforms by local rotation matrix
7. Accumulates steering angle at param_1+0x1e0
8. If accumulated > threshold and ReasonCode==0: sets ReasonCode=4 (steering damage)

**Struct offsets:** param_1+0x15c0 (suspension component array), param_1+0x15bc (count), param_1+0x141c (alternate geometry), param_1+0x1e0 (accumulated steering angle), param_1+0x4068 (ReasonCode)

**Globals:** DAT_008aae70, DAT_008aae74 (random ring buffer), DAT_0059ed78 (steering scale), DAT_0059ed60 (damage threshold)

### Level 1: FUN_00441450 — PhysicsSubObjectFree

**Called by:** FUN_00442060 (geometry refresh)
**Purpose:** Refreshes physics sub-object after geometry change.

### Level 1: FUN_00435e00 / FUN_004388d0 — Matrix multiply helpers

**Called by:** FUN_00442060 (coordinate transforms)
**Purpose:** Multiply 3x3 matrix by vector for wheel orientation transforms.

### Level 1: FUN_0056d020 — 3x3 Matrix Inverse & Coordinate Transform

**Called by:** FUN_00442060 (transform computation)
**Purpose:** Computes inverse of 3x3 matrix for coordinate system transforms.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00442060 | Steering input, wheel index, suspension array | Steering angle computation + rotation transform | Updated wheel positions + accumulated steering damage |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008aae70 | Random ring buffer | FUN_00442060 | Per-frame random values for steering variation |
| param_1+0x1e0 | AccumulatedSteeringAngle | FUN_00442060 | Cumulative steering angle for damage detection |
| param_1+0x4068 | ReasonCode | FUN_00442060 | Set to 4 when steering damage threshold exceeded |

## Notes

- This is the most moddable chain seed: max steering angle and damage threshold are configurable in .svm files.
- Cross-system: All callees are math/physics functions from docs/18-physics-dynamics.md.
- The random ring buffer (DAT_008aae70) provides per-frame steering variation for realistic geometry.

---
