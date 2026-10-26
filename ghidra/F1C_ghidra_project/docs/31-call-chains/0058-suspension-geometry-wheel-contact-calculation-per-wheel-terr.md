# Chain: Suspension Geometry & Wheel Contact Calculation — Per-Wheel Terrain Contact

Seed: 0x004423b0  |  System: docs/18-physics-dynamics.md  |  Depth: 4  |  Functions: 7

---

## Overview

Computes per-wheel suspension geometry: contact patch position relative to chassis, spring compression, and lateral/longitudinal force projection from terrain heightmap. Triggered per-vehicle per-frame during physics simulation. Reads terrain heightmap, samples height at wheel locations, computes suspension compression via trigonometric functions, generates contact forces (normal, friction, restitution), applies damage-conditional suspension constraints.

## Call Tree

```
0x004423b0 — Suspension Geometry & Wheel Contact  [trigger: per-vehicle per-frame physics tick]
  +-- 0x004e9630 — PositionChangeMonitor  [reads terrain heightmap, 1 sub-call]
  |     +-- 0x00403640 — Nearest Neighbor Spatial Search  [docs/20]
  +-- 0x004fd7e0 — 1D Table Lookup with Lerp  [samples height coefficients, leaf]
  +-- 0x00435e00 — Matrix3x3VectorMultiply  [transforms wheel to world frame, leaf]
  +-- 0x0044c4c0 — SpatialGridQuery  [terrain collision — gets contact triangle, 2 sub-calls]
  |     +-- 0x0044a070 — Narrow-Phase Check  [leaf]
  |     +-- 0x0044aa30 — BVHTreeTraversal  [docs/17, 1 sub-call, broadphase]
  +-- 0x00436870 — Collision Contact Generation & Friction Response  [6 sub-calls]
  |     +-- 0x0044c4c0 — SpatialGridQuery  [recurse: sub-call for contact gen]
  |     +-- 0x0056c640 — Plane-Line Intersection  [leaf]
  |     +-- 0x004366e0 — Best-Fit Plane Fitting  [docs/17]
  |     |     +-- 0x004365e0 — [leaf]
  |     +-- 0x00588570 — Random  [leaf]
  |     +-- 0x004d6830 — Cubic Hermite Interpolation  [docs/20, penalty force]
  |     |     +-- 0x004d6810 — [leaf]
  |     +-- 0x00569a20 — Apply Impulse to Body  [leaf]
  +-- 0x0043aee0 — TransformApply3D  [suspension arm matrix, leaf]
  +-- 0x00569ad0 — Accumulate Angular Momentum  [cross product, leaf]
```

## Step-by-Step Trace

### Level 0: 0x004423b0 — Suspension Geometry & Wheel Contact Calculation

**Trigger:** Per-vehicle per-frame physics simulation tick.
**Called by:** No callers documented (called from vehicle dynamics integration loop).
**Purpose:** Computes per-wheel suspension contact: terrain height, compression, contact forces.

**Key actions:**
1. If DAT_008afeec == DAT_008afee8 (no terrain data): sets all 4 wheel contact distances to default
2. Otherwise: reads terrain heightmap via FUN_004e9630; samples 4 height samples per wheel location
3. Computes signed distance from wheel hub to terrain surface using 3 heightmap coefficients
4. Transforms wheel position into world frame via FUN_00435e00
5. Queries terrain collision via FUN_0044c4c0 — gets contact triangle index
6. If contact found: retrieves surface normal from triangle; computes suspension compression via fsin
7. When compressed below _DAT_0059e430 (threshold): triggers contact response
8. Computes contact impulse: normal, friction, and restitution using triangle normal and penetration depth
9. Accumulates contact forces into wheel force buffers (offset 0x171c/0x1720)
10. If wheel has damage flag (0x1724): computes additional suspension constraint forces via cross products
11. Updates wheel hub (FUN_00436870) and suspension arm matrix (FUN_0043aee0)

**Data passed to callees:** Vehicle struct pointer, wheel index, terrain heightmap data, wheel position vectors.

### Level 1: Key Sub-functions

**0x004e9630 — PositionChangeMonitor**
Reads terrain heightmap and returns height samples at wheel location. Uses nearest-neighbor spatial search (0x00403640) for efficient lookups in a spatial data structure.

**0x0044c4c0 — SpatialGridQuery**
Performs collision broadphase query on terrain spatial grid. Returns contact triangle index. Traverses BVH tree (0x0044aa30) for acceleration.

**0x00436870 — Collision Contact Generation & Friction Response**
6 sub-calls. Generates contact response: re-queries spatial grid, computes plane-line intersection for edge contacts, fits best-fit plane to contact region, adds random perturbation (for tire noise?), computes penalty force via cubic Hermite interpolation, applies impulse to rigid body.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004423b0 | wheel state, terrain | terrain sample | height at wheel |
| FUN_004e9630 | wheel pos, heightmap | spatial search | 4 height samples |
| FUN_00435e00 | wheel pos, matrix | transform | world-space wheel pos |
| FUN_0044c4c0 | world pos, grid | spatial query | contact triangle index |
| FUN_00436870 | contact data, wheel state | impulse gen | contact forces |
| FUN_0043aee0 | suspension data | matrix compute | suspension arm transform |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_0059e430 | ZeroSentinel | read | compression threshold gate |

## Notes

This is the core suspension contact pipeline. The 0x00436870 subtree is a self-contained collision response generator that uses spatial grid query recursively. The damage-conditional path (0x1724 flag) adds extra constraint forces for damaged suspension geometry. Contact forces accumulate into wheel force buffers for integration by the rigid body solver.

---
