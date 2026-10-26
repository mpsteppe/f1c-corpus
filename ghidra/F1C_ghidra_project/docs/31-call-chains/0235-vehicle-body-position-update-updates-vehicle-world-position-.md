# Chain: Vehicle Body Position Update — Updates vehicle world position with suspension travel check

Seed: FUN_0045a8e0  |  System: docs/10-vehicle-physics.md  |  Depth: 6  |  Functions: ~10

---

## Overview

FUN_0045a8e0 updates the vehicle's world position with suspension travel check and orientation computation. It compares input against travel limits, computes position from double-precision struct values, checks orientation and velocity thresholds, and resets state when motion settles. The most significant callee is FUN_00459ae0 (Vehicle Physics Velocity/Angular-Velocity Integrator) which has 11 sub-callees.

## Call Tree

```
FUN_0045a8e0 — Vehicle Body Position Update  [trigger: per-vehicle physics tick]
  +-- FUN_00569280 — Copy 6 Dwords to Struct + Call  [sub: 1]
  +-- FUN_0054b3b0 — Three-Field Setter with Sub-Call  [sub: 1]
  +-- FUN_0054c030 — Flag Field Bit Manipulation  [leaf]
  +-- FUN_0054b4d0 — [PARTIAL] Unknown  [leaf]
  +-- FUN_00588570 — Float80-to-double conversion  [leaf]
  +-- FUN_00459ae0 — Vehicle Physics Velocity/Angular-Velocity Integrator  [11 callees]
        +-- FUN_004361d0 — 3D Vector Transform by 3x3 Matrix (Double)  [leaf]
        +-- FUN_0054fa00 — Network Packet Data Writer  [leaf]
        +-- FUN_00588570 — Float80-to-double conversion  [leaf, reused]
        +-- FUN_0054b4d0 — [PARTIAL] Unknown  [leaf, reused]
        +-- FUN_004be4e0 — Sprite Grid Render  [sub: 1]
        +-- [6 additional callees omitted]
```

## Step-by-Step Trace

### Level 0: FUN_0045a8e0 — Vehicle Body Position Update

**Called by:** None documented (likely called from vehicle dynamics loop)
**Purpose:** Updates vehicle world position with suspension travel check and orientation computation.

**Key actions:**
1. Compares input throttle/ride height against min/max travel limits
2. Accesses DAT_007d0ab0 as ride height tolerance/offset
3. Computes position (3 doubles at +0x36, +0x38, +0x3a) output as floats
4. Uses fpatan on quaternion/rotation components
5. Checks velocity magnitude thresholds
6. Checks dot product of orientation vectors for stability
7. Resets state and calls FUN_00569280 when motion below threshold

### Level 1: FUN_00459ae0 — Vehicle Physics Velocity/Angular-Velocity Integrator

**Called by:** FUN_0045a8e0 (velocity integration)
**Purpose:** Integrates vehicle velocity and angular velocity, applies transforms.

**Key actions:**
1. Transforms vectors by 3x3 matrix (FUN_004361d0)
2. Writes network packet data (FUN_0054fa00)
3. Converts float80 to double (FUN_00588570)
4. Renders sprite grid (FUN_004be4e0)
5. [6 additional operations]

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045a8e0 | Vehicle state struct | Position computation + orientation check | Updated world position + orientation |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_007d0ab0 | Ride height tolerance | FUN_0045a8e0 | Suspension travel offset |

## Notes

- Cross-system: FUN_00459ae0 has a network packet writer (docs/06-session-race-logic) and sprite render (docs/19-renderer).
- FUN_00588570 (float80→double) and FUN_0054b4d0 are reused by both the seed and FUN_00459ae0.

---
