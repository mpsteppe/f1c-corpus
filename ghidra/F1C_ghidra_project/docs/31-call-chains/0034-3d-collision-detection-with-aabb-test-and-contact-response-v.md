# Chain: 3D Collision Detection with AABB Test and Contact Response — Vehicle Wheel-Terrain Collision

Seed: FUN_004ea040  |  System: docs/17-physics-collision.md  |  Depth: 3  |  Functions: 7

---

## Overview

Called from the collision/pipeline update (caller: FUN_0040f380). Tests a vehicle wheel position against collision geometry (AABB test). Reads wheel-relative contact position via FUN_004ea930, transforms to body space via rotation matrix (param_1+0x34b0). Tests AABB overlap against terrain bounding box. Iterates collision primitives via D3D device accessors (FUN_0054c230, FUN_0054e100, FUN_0054e120). On hit: computes penetration depth, contact normal, and raycasts against suspension geometry (FUN_004ed420). Computes collision impulse with restitution (DAT_0059e7e8).

## Call Tree

```
FUN_004ea040 — 3D Collision Detection with AABB Test  [collision pipeline: FUN_0040f380]
  +-- FUN_004ea930 — 3D Vector Subtraction  [docs/20: wheel-relative contact position]
  +-- FUN_004ea010 — Slot Allocator / Arithmetic-Comparison  [docs/20: hit tracking]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [docs/06: iterate collision primitives]
  +-- FUN_0054e100 — PackedArrayTotalSize  [docs/06: primitive count]
  +-- FUN_0054e120 — PackedArrayIndexLookup  [docs/06: get primitive by index]
  +-- FUN_004ed420 — VehicleGeometryProximityTest  [docs/06: raycast vs suspension]
  |     +-- FUN_004ea930 — 3D Vector Subtraction  [get rotation matrix]
  |     +-- FUN_004ed750 — 3D Cross Product  [get vector]
  |     +-- FUN_004ed710 — Vec3 Add  [get direction]
  |     +-- FUN_004ed380 — AnisoVectorTripleProduct  [dot/angle between vectors]
  |     +-- FUN_004ed7b0 — 3x3 Matrix x Vector Multiply  [contact point computation]
  +-- FUN_005694e0 — VehicleProjectedPosition  [docs/18: wheel projection]
```

## Step-by-Step Trace

### Level 0: FUN_004ea040 — 3D Collision Detection with AABB Test and Contact Response

**Trigger:** Called from collision pipeline update
**Called by:** FUN_0040f380 (docs/?? — unknown system)
**Purpose:** Tests vehicle wheel contact against collision geometry, computes penetration depth and contact normal.

**Key actions:**
1. Reads collision geometry AABB extents from param_2 (+0xc/+0x10/+0x14/+0x18)
2. Computes wheel-relative contact position via FUN_004ea930
3. Transforms contact point into body space via rotation matrix (param_1+0x34b0)
4. Tests AABB overlap against terrain bounding box with margin
5. Iterates all collision primitives via FUN_0054c230 then FUN_0054e100/FUN_0054e120
6. For each primitive: transforms to body space, tests inside AABB, tracks closest
7. On hit: computes penetration depth and contact normal
8. Transforms response direction back to world space
9. Raycasts against suspension geometry via FUN_004ed420
10. Computes collision impulse with restitution (DAT_0059e7e8 = TimeScalingConstant)

### Level 1: Primitive Iteration and Geometry Access

**FUN_0054c230 — Linked List Indexed Accessor** [docs/06-session-race-logic.md]
- Accessor for linked list data structure storing collision primitives
- Returns pointer to element at given index

**FUN_0054e100 — PackedArrayTotalSize** [docs/06-session-race-logic.md]
- Returns total element count in collision primitive array

**FUN_0054e120 — PackedArrayIndexLookup** [docs/06-session-race-logic.md]
- Returns pointer to specific primitive by index

### Level 1: Geometry Tests

**FUN_004ed420 — VehicleGeometryProximityTest** [docs/06-session-race-logic.md]
5 sub-callees — all math utilities:
- FUN_004ea930: 3D vector subtraction (rotation matrix extraction)
- FUN_004ed750: 3D cross product
- FUN_004ed710: Vec3 add
- FUN_004ed380: anisotropic vector triple product (dot/angle between vectors)
- FUN_004ed7b0: 3x3 matrix × vector multiply (contact point computation)

**FUN_005694e0 — VehicleProjectedPosition** [docs/18-physics-dynamics.md]
- Computes wheel's projected position for suspension contact model
- Leaf function (no further callees)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| param_2+0xc..0x18 | AABB extents | Read | Wheel bounding box |
| param_1+0x34b0 | rotation matrix | Transform | Body-space contact |
| FUN_0054e100/0120 | primitive array | Iterate | Closest primitive |
| FUN_004ed420 | wheel pos, geometry | Raycast | Contact point/normal |
| DAT_0059e7e8 | restitution | impulse calc | Collision response force |

## Notes

- DAT_0059e7e8 (TimeScalingConstant) used for collision impulse computation
- 7 callees, 5 are leaf utilities, 2 have sub-callees (FUN_004ed420 has 5 sub-callees)
- Cross-system: docs/17-collision → docs/06-session (FUN_0054c230, FUN_0054e100, FUN_0054e120), docs/18-physics (FUN_005694e0)

---
