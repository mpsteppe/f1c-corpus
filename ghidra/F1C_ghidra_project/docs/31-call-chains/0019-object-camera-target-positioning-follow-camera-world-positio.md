# Chain: Object/Camera Target Positioning — Follow camera world position + yaw computation

Seed: FUN_00458df0  |  System: docs/10-vehicle-physics.md  |  Depth: 4  |  Functions: 12

---

## Overview

FUN_00458df0 computes world position and yaw orientation for a follow camera or attached object. Called during camera update loop. Adds offset to base position, normalizes direction, computes yaw via arctan, applies camera shake, clamps FOV/zoom, filters collision response offset, and applies final camera transform.

The chain is shallow (4 direct callees, max depth 4 via the collision response filter path). Two callees are simple math leaves; one is a float conversion wrapper.

---

## Call Tree

```
FUN_00458df0 — Object/Camera Target Positioning  [docs/10-vehicle-physics.md]
  |
  +-- FUN_00456040 — Double Field Getter at +0x30/+0x34  [triage: math_util] LEAF
  |
  +-- FUN_004584c0 — CollisionResponseFilter (contact velocity resolution)  [docs/17-physics-collision.md]
  |     +-- FUN_00455f90 — AngleWrap  [docs/17-physics-collision.md] LEAF
  |     +-- FUN_00455fd0 — Angle Normalization / Wrap  [docs/17-physics-collision.md] LEAF
  |     +-- FUN_00567030 — Quaternion from Euler Angles  [docs/18-physics-dynamics.md] LEAF
  |     +-- FUN_00567580 — [undocumented / triage-only] LEAF
  |     +-- FUN_00567010 — File/Stream Cleanup Wrapper  [triage: Math]
  |           +-- FUN_00566f40 — 3x3 Rotation Matrix from Quaternion  [docs/18-physics-dynamics.md] LEAF
  |           +-- FUN_00566ee0 — RotationMatrixToEuler  [docs/18-physics-dynamics.md] LEAF
  |
  +-- FUN_00456130 — Vector Copy (3 floats)  [triage: math_util] LEAF
  |
  +-- FUN_00588570 — Float80-to-Double Conversion / Norm Helper  [triage: Math / float math] LEAF
```

---

## Step-by-Step Trace

### Level 0 — Seed
**FUN_00458df0 — Object/Camera Target Positioning** (docs/10-vehicle-physics.md):
- Adds input offset (param_2) to base position at param_1+0xc/0x10/0x14
- Normalizes resulting direction vector (reciprocal sqrt via SIMD)
- Computes yaw via fpatan2 of x/z components
- Checks flag at +0x74 bit 0: if set, applies camera shake via FUN_00456040 (reads double at +0x30/+0x34)
- Clamps FOV/zoom ratio at +0x38/+0x3c
- If +0xa4 > 0: calls FUN_004584c0 for offset adjustment (collision response filtering)
- Calls FUN_00456130 to copy final camera transform (3-float vector copy)
- Calls FUN_00588570 (float80→double conversion / norm helper)

### Level 1 — Direct Callees

**1. FUN_00456040 — Double Field Getter at +0x30/+0x34** (triage: math_util)
- Reads two double/float fields from param_1+0x30 and +0x34
- Used to apply camera shake perturbation
- Leaf function — no further calls in call_graph

**2. FUN_004584c0 — CollisionResponseFilter (contact velocity resolution)** (docs/17-physics-collision.md)
- Computes relative velocity from ABS differences
- Scales by restitution factor at *(param_1+0xa4)
- If velocity < scaled AND velocity > epsilon: computes ratio, clamps to 1.0, applies impulse via transforms
- Else: copies source velocity to output
- Calls 5 sub-functions for angle wrapping and quaternion/matrix math

**3. FUN_00456130 — Vector Copy (3 floats)** (triage: math_util)
- Copies 3 consecutive float values (x, y, z or equivalent)
- Used for final camera transform copy
- Leaf function

**4. FUN_00588570 — Float80-to-Double Conversion / Norm Helper** (triage: Math)
- Converts float80 to double, then calls two sub-functions
- Used as normalization/magnitude helper
- Called ~25 times across codebase in physics and rendering paths
- Leaf function in call_graph (no further tracked callees)

### Level 2 — From FUN_004584c0

**FUN_00455f90 — AngleWrap** (docs/17-physics-collision.md)
- Wraps angle to [-bound, bound] range
- If *param_1 > DAT_0059efa4 (PI): *param_1 -= DAT_0059efa8 (2*PI)
- If *param_1 < -DAT_0059efa4 (PI): *param_1 += DAT_0059efa8 (2*PI)
- Leaf function

**FUN_00455fd0 — Angle Normalization / Wrap** (docs/17-physics-collision.md)
- Normalizes angle to [-pi, pi] range using reflection wrap
- If > PI: result = 2*PI - angle
- If < -PI: result = 2*PI + angle
- Leaf function

**FUN_00567030 — Quaternion from Euler Angles** (docs/18-physics-dynamics.md)
- Converts yaw, pitch, roll Euler angles to quaternion
- Multiplies each by DEG_TO_RAD constant (DAT_0059e450)
- Computes sin/cos per axis, builds 4-component quaternion via standard formula
- Calls fcos, fsin (math library)
- Leaf function

**FUN_00567580 — [undocumented / triage-only]**
- No doc entry exists; only referenced as callee in call_graph
- Leaf function (no further callees tracked)

**FUN_00567010 — File/Stream Cleanup Wrapper** (triage: Math)
- Dual math call wrapper — converts and transforms orientation data
- Calls FUN_00566f40 (quaternion→matrix) and FUN_00566ee0 (matrix→euler)

### Level 3 — Termination leaves

**From FUN_00567010:**
**FUN_00566f40 — 3x3 Rotation Matrix from Quaternion** (docs/18-physics-dynamics.md)
- Converts quaternion to 3x3 rotation matrix
- Standard quaternion-to-matrix formula
- Leaf function

**FUN_00566ee0 — RotationMatrixToEuler** (docs/18-physics-dynamics.md)
- Extracts Euler angles (pitch, yaw, roll) from 3x3 rotation matrix
- Handles gimbal lock case (threshold at DAT_005b8968)
- pitch = atan2(-m[2][1], sqrt(m[2][0]^2 + m[2][2]^2))
- Uses fpatan for extraction
- Leaf function

---

## Data Flow Summary

```
Input: base_position (param_1+0xc/0x10/0x14) + offset (param_2)
                        │
                        ├── normalize direction vector
                        ├── compute yaw via fpatan2(x, z)
                        │
                        ├── if flag at +0x74 bit 0:
                        │     └──→ FUN_00456040 (shake from +0x30/+0x34)
                        │
                        ├── clamp FOV/zoom at +0x38/+0x3c
                        │
                        ├── if +0xa4 > 0:
                        │     └──→ FUN_004584c0 (collision response filter)
                        │           │
                        │           ├──→ FUN_00455f90 (angle wrap)
                        │           ├──→ FUN_00455fd0 (angle normalize)
                        │           ├──→ FUN_00567030 (euler → quaternion)
                        │           ├──→ FUN_00567580 (undocumented)
                        │           └──→ FUN_00567010 (orientation cleanup)
                        │                 ├──→ FUN_00566f40 (quaternion → matrix)
                        │                 └──→ FUN_00566ee0 (matrix → euler)
                        │
                        ├──→ FUN_00456130 (copy 3-float transform)
                        └──→ FUN_00588570 (float80→double norm helper)
```

**Key struct (param_1, camera/object):**
| Offset | Field | Type | Purpose |
|--------|-------|------|---------|
| +0x0c | PosX | float | Base position X |
| +0x10 | PosY | float | Base position Y |
| +0x14 | PosZ | float | Base position Z |
| +0x30 | ShakeDouble | double | Camera shake magnitude (via FUN_00456040) |
| +0x34 | ShakeFloat | float | Camera shake secondary |
| +0x38 | FOV/Zoom | float | Field of view or zoom ratio |
| +0x3c | FOV/Zoom clamp | float | Clamp value |
| +0x74 | Flags | uint | Bit 0 = camera shake enabled |
| +0xa4 | RestitutionFactor | float | Collision response restitution |

---

## Globals Written

| Address | Name | What |
|---------|------|------|
| DAT_0059efa4 | PI constant | Read by FUN_00455f90, FUN_00455fd0 |
| DAT_0059efa8 | 2*PI constant | Read by FUN_00455f90, FUN_00455fd0 |
| DAT_0059e450 | DEG_TO_RAD | Read by FUN_00567030 |
| DAT_005b8968 | Gimbal lock singularity threshold | Read by FUN_00566ee0 |

---

## Notes

- **Max depth = 4**: Seed → FUN_004584c0 → FUN_00567010 → FUN_00566f40 / FUN_00566ee0
- **Two math sub-chains**: Angle wrapping (FUN_00455f90 / FUN_00455fd0) and quaternion↔matrix conversion (FUN_00567030 / FUN_00566f40 / FUN_00566ee0)
- **Undocumented callees**: FUN_00567580 has no doc entry — triage-only
- **FUN_00588570 discrepancy**: Triaged as float80 conversion helper but used as norm/random helper across 25+ physics and collision sites
- **FUN_00567010 misleading name**: Despite "File/Stream Cleanup" triage label, actually called as dual math wrapper (quaternion→matrix→euler) within collision response context
- **Documentation spread**: Chain spans docs/10 (seed), docs/17 (collision response + angle math), docs/18 (quaternion/matrix math), and triage-only callees
- **Configurable physics**: Restitution (DAT_0059e440/DAT_0059e43c) and PI constants are moddable; camera shake flag, FOV values are per-camera config
