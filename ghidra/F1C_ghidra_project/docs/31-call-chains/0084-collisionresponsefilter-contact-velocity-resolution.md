# Chain: CollisionResponseFilter — Contact velocity resolution

Seed: FUN_004584c0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 6

---

## Overview

Applies restitution/penalty impulse on contact. Computes relative velocity, scales by restitution factor (param_1+0xa4), and if velocity exceeds scaled threshold, applies impulse via transforms using clamping logic. Otherwise copies source velocity straight to output.

## Call Tree

```
FUN_004584c0 — CollisionResponseFilter  [trigger: collision contact resolution]
  +-- FUN_00455f90 — TransformOp1  [vector transform — leaf]
  +-- FUN_00455fd0 — TransformOp2  [vector transform — leaf]
  +-- FUN_00567030 — VelocityOp1  [velocity operation — leaf]
  +-- FUN_00567580 — VelocityOp2  [velocity operation — leaf]
  +-- FUN_00567010 — VelocityOp3  [velocity operation — leaf]
```

## Step-by-Step Trace

### Level 0: FUN_004584c0 — CollisionResponseFilter

**Trigger:** Called during collision contact resolution
**Called by:** Collision response pipeline
**Purpose:** Applies restitution/penalty impulse on contact.

**Key actions:**
1. Relative velocity = ABS(v3-v4)+ABS(v1-v2)
2. Scaled: param_5 = fVar1 * *(param_1+0xa4) * param_5
3. If velocity < scaled AND velocity > epsilon: compute ratio, clamp to 1.0, apply impulse via transforms
4. Else: copy source velocity to output

**Data passed to callees:** Velocity vectors, transform parameters

### Level 1: All 5 callees

All callees are vector math and velocity operation helpers — all leaf functions.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004584c0 | v1-v4 (contact velocities) | Relative velocity computation | relVel |
| FUN_004584c0 | param_1+0xa4 (restitution) | Scale threshold | scaledThreshold |
| FUN_004584c0 | relVel vs threshold | Apply impulse or passthrough | Output velocity |

## Struct Offsets Used

| Offset | Field | Notes |
|--------|-------|-------|
| +0xa4 | RestitutionFactor | float restitution coefficient |

## Notes

- All 5 callees are leaf vector math functions
- Uses epsilon from _DAT_0059e440 and _DAT_0059e43c
- Restitution factor is configurable from material properties

---
