# Chain: Recursive Triangle Edge Subdivision for Collision — BSP/Collision Mesh Refinement

Seed: 0x0044aae0  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 4

---

## Overview

Recursively subdivides a collision triangle along its longest edge until all edges are below a length threshold, then processes each sub-triangle for collision. Triggered during collision mesh preprocessing/refinement. Output: collision-processed sub-triangles after BSP-style subdivision.

## Call Tree

```
0x0044aae0 — Recursive Triangle Edge Subdivision  [trigger: collision mesh refinement]
  +-- 0x004484c0 — Vec3Subtract (3-component float vector subtraction)  [computes edge vectors, leaf]
  +-- 0x004484f0 — Empty Function  [length squared, leaf]
  +-- 0x00448480 — Weighted Average Interpolation  [midpoint of longest edge, leaf]
  +-- 0x004493a0 — Triangle Collision Processor  [resizable container insertion, leaf]
```

## Step-by-Step Trace

### Level 0: 0x0044aae0 — Recursive Triangle Edge Subdivision for Collision

**Trigger:** Collision mesh refinement during initialization or dynamic collision processing.
**Called by:** 0x0044acb0 (collision BVH/build system).
**Purpose:** Recursively subdivides triangle along longest edge until edges below threshold, processing each sub-triangle.

**Key actions:**
1. Takes 3 triangle vertices (param_1, param_2, param_3) plus 2 output parameters
2. Computes squared edge lengths using FUN_004484c0 (edge vector) + FUN_004484f0 (length squared)
3. Finds the longest edge among the 3
4. If longest edge > _DAT_0059ef38 (subdivision threshold): splits that edge at midpoint via FUN_00448480, creates 2 sub-triangles, recurses
5. If all edges <= threshold: calls FUN_004493a0 to process the triangle (collision test/insertion)

**Data passed to callee:** Three vertex positions (float[3] each), output container pointer, recursion depth baked into stack.

### Level 1: All callees are leaf functions

**0x004484c0** — Vec3Subtract. Computes edge vector = v[i] - v[j] (3-component float subtraction).
**0x004484f0** — Empty Function. Returns squared length of edge vector. Labeled empty but returns length².
**0x00448480** — Weighted Average Interpolation. Computes midpoint of longest edge: (v[i] + v[j]) / 2.
**0x004493a0** — Triangle Collision Processor. Inserts processed triangle into resizable collision container.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004484c0 | 2 vertices | subtract | edge vector |
| FUN_004484f0 | edge vector | length² | squared length |
| FUN_00448480 | 2 vertices | average | midpoint vertex |
| FUN_0044aae0 | 3 vertices, threshold | recurse | sub-triangles |
| FUN_004493a0 | sub-triangle | insert | container entry |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_0059ef38 | subdivision threshold | read | max edge length for recursion halt |

## Notes

Standard BSP-style subdivision. Recursion terminates when triangle edges are small enough for collision testing. The threshold (DAT_0059ef38, configurable in docs/12) controls mesh refinement level — smaller values = more triangles = more accurate collision but higher cost. All 4 callees are leaf math functions. The recursion depth is bounded by the initial triangle size vs threshold ratio.
