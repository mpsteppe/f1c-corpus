# Chain: Collision Contact Generation and Friction Response -- computes contact points, penetration depth, friction impulse

Seed: FUN_00436870  |  System: docs/17-physics-collision.md  |  Depth: 3  |  Functions: 9

---

## Overview

FUN_00436870 is the core collision response function in the physics engine. Called from FUN_004423b0 (Suspension Geometry & Wheel Contact Calculation, docs/18). Computes contact points between a rigid body and triangle mesh, evaluates penetration depth, applies Coulomb friction model, and resolves impulse/torque response. Operates on param_1 (vehicle rigid body struct) with 21 documented struct offsets.

The call graph is narrow (6 direct callees) and shallow (max depth 3). All 6 callees are leaf functions except FUN_0044c4c0 which has sub-callees.

## Call Tree

```
FUN_00436870 -- Collision Contact Generation and Friction Response  [docs/17, 6 callees]
|
+-- FUN_0044c4c0 -- SpatialGridQuery  [docs/17, 2 callees] [LEVEL 2]
|   +-- FUN_0044a070 -- QuadraticSurfaceCollisionTest  [docs/17, LEAF]
|   +-- FUN_0044aa30 -- BVHTreeTraversal  [docs/17, 1 callee] [LEVEL 3]
|       +-- FUN_0044a070 -- QuadraticSurfaceCollisionTest  [docs/17, LEAF]
|
+-- FUN_0056c640 -- Plane-Line Intersection  [docs/20, LEAF]
|
+-- FUN_004366e0 -- Best-Fit Plane Fitting  [docs/20, LEAF]
|
+-- FUN_00588570 -- FPE/float80-to-double random helper  [docs/20, LEAF]
|
+-- FUN_004d6830 -- Cubic Hermite Interpolation (penalty force)  [docs/20, LEAF]
|
+-- FUN_00569a20 -- Apply Impulse to Rigid Body with Torque  [docs/18, LEAF]
```

## Step-by-Step Trace

### Level 0 -- Seed
**FUN_00436870 -- Collision Contact Generation and Friction Response** (docs/17-physics-collision.md):
- Source: physics collision system
- Reads triangle vertices from param_1+0x15c (offset +0x1c, +0x34, +0x4c)
- Builds orthonormal basis (tangent, binormal, normal) from triangle edges
- Branch on DAT_007ce994: 5 contact points if non-zero, else 3
- Per contact point:
  1. Ray-triangle intersection via FUN_0044c4c0 (SpatialGridQuery)
  2. Contact depth via FUN_0056c640 (plane-line intersection) or FUN_004366e0 (best-fit plane)
  3. Random element via FUN_00588570 (float80->double random)
  4. Normal force computation (clamped to 0 if negative)
  5. Coulomb friction: slip/stick threshold, cos() falloff from param_1+0x2b0/0x2d0
  6. Penalty force via FUN_004d6830 (Cubic Hermite Interpolation)
  7. Impulse application via FUN_00569a20 (apply impulse + torque to body)
- Damping factor via _DAT_0059e880

### Level 1 -- Direct Callees

**1. FUN_0044c4c0 -- SpatialGridQuery** (docs/17):
- Ray-triangle intersection against spatial grid
- 2 callees: FUN_0044a070 (narrow-phase quadratic surface test), FUN_0044aa30 (broad-phase BVH traversal)

**2. FUN_0056c640 -- Plane-Line Intersection** (docs/20):
- Computes intersection of line with plane
- Used to determine contact penetration depth
- Leaf -- no further callees

**3. FUN_004366e0 -- Best-Fit Plane Fitting** (docs/20):
- Fits plane to contact region vertices
- Alternative contact depth computation
- Leaf -- no further callees

**4. FUN_00588570 -- FPE/float80-to-double random** (docs/20):
- Converts float80 to double, provides random element
- Used for stochastic contact variation
- Leaf -- no further callees

**5. FUN_004d6830 -- Cubic Hermite Interpolation (penalty force)** (docs/20):
- Spline interpolation from lookup table (param_1+0x14)
- Computes penalty-based contact force
- Leaf -- no further callees

**6. FUN_00569a20 -- Apply Impulse to Rigid Body with Torque** (docs/18):
- Applies computed impulse and torque to rigid body
- Cross-product-based torque accumulation
- Leaf -- no further callees

### Level 2 -- SpatialGridQuery sub-callees

**From FUN_0044c4c0:**
- FUN_0044a070 -- QuadraticSurfaceCollisionTest (docs/17): narrow-phase per-triangle check. Leaf.
- FUN_0044aa30 -- BVHTreeTraversal (docs/17): broad-phase BVH traversal. Calls FUN_0044a070 for leaf primitives.

## Data Flow Summary

```
FUN_00436870(param_1=VehicleBody*, DAT_007ce994 flag)
  |
  +--> FUN_0044c4c0  ray-triangle intersection
  |     +--> FUN_0044a070  narrow-phase quadratic surface test
  |     +--> FUN_0044aa30  broad-phase BVH traversal
  |           +--> FUN_0044a070  per-leaf test
  |
  +--> FUN_0056c640  plane-line intersection (contact depth)
  +--> FUN_004366e0  best-fit plane fitting (alt. depth)
  +--> FUN_00588570  random element
  +--> FUN_004d6830  penalty force (cubic Hermite spline)
  +--> FUN_00569a20  impulse + torque to rigid body
```

**Data flowing:**
- param_1: Vehicle rigid body struct with 21 tracked offsets (triangle data, contact force, penetration depth, friction accumulators, rotation matrix, restitution, damping, half-extent, friction curves, rolling resistance, contact area, etc.)
- DAT_007ce994: enables 5-contact-point mode (default 3)
- _DAT_0059e880: penetration correction damping factor

**Processing flow per contact:**
1. Read triangle vertices -> build orthonormal basis
2. SpatialGridQuery -> find triangle intersection
3. Compute contact depth (plane-line or best-fit plane)
4. Add random element
5. Clamp normal force
6. Apply Coulomb friction with cos() falloff
7. Compute penalty force via Hermite spline
8. Apply impulse + torque to rigid body

## Globals Written

| Address | Name | What |
|---------|------|------|
| DAT_007ce994 | ContactPointMode | Read -- enables 5-contact-point mode |
| _DAT_0059e880 | PenetrationDamping | Read -- damping factor for penetration correction |

No globals directly written by this chain. All outputs are struct-scoped to param_1.

## Notes

- **Max depth:** 3 (through SpatialGridQuery -> BVHTreeTraversal -> QuadraticSurfaceCollisionTest)
- **6 direct callees:** only 1 is non-leaf (FUN_0044c4c0)
- **Single caller:** FUN_004423b0 (Suspension Geometry & Wheel Contact Calculation) in docs/18
- **All callees are pure math:** collision detection, plane fitting, interpolation, impulse physics
- **No memory allocation:** no heap alloc/free; purely computational
- **21 struct offsets documented** on param_1 -- one of the most struct-heavy functions in the engine
- **Coverage:** spans docs/17 (seed + 3 callees), docs/18 (1 callee), docs/20 (4 callees)
- **Key algorithm:** ray-triangle intersection + Coulomb friction + impulse-based rigid body response
- **Moddability:** hardcoded -- friction curves and parameters are compile-time constants except table-driven penalty force (FUN_004d6830)

---
