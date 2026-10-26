# Chain: Bezier Patch Tessellation — Surface Subdivision

Seed: FUN_0044b370  |  System: docs/19-renderer.md  |  Depth: 2  |  Functions: 13

---

## Overview

Subdivides 4-point Bezier patches into triangle meshes with smoothing. Processes patches read from param_1[0], subdivides each using De Casteljau's algorithm (FUN_004493a0), evaluates subdivision quality (FUN_0044b110), and allocates vertex buffers. Supports B-spline and Bezier evaluation modes. Final smoothing averages adjacent vertex positions.

## Call Tree

```
FUN_0044b370 — Bezier Patch Tessellation  [called from collision/render pipeline]
  +-- FUN_004492b0 — CollisionShapeInit
  |     +-- FUN_00449340 — PhysicsBufferFree
  |           +-- FUN_00587bcf — Free
  |           +-- FUN_00448570 — collision shape free
  +-- FUN_004492d0 — Collision Contact Buffer Allocator
  |     +-- FUN_00449340 — PhysicsBufferFree
  |     +-- FUN_00448e90 — buffer alloc
  +-- FUN_004493a0 — resizable container [De Casteljau subdivision step]
  +-- FUN_00448ee0 — RGB Color Packing
  +-- FUN_00449340 — PhysicsBufferFree
  |     +-- FUN_00587bcf — Free
  |     +-- FUN_00448570 — collision shape free
  +-- FUN_00449700 — Collision Contact Response
  |     +-- FUN_00448da0 — contact resolve
  |     +-- FUN_00448de0 — contact normal
  |     +-- FUN_00448480 — impulse apply
  +-- FUN_0044b110 — ConstraintValidator3Way (quality eval)
  |     +-- FUN_00448ee0 — color pack
  |     +-- FUN_0044af20 — CollisionFaceVerticesGather
  |     +-- FUN_0044af60 — Axis permutation matrix read
  |     +-- FUN_0044b040 — Collision Capsule/Shape Copy to Pipeline
  |     +-- FUN_0044b090 — validator sub
  +-- FUN_0044b040 — Collision Capsule/Shape Copy to Pipeline
  |     +-- FUN_00448e90 — buffer alloc
  |     +-- FUN_00448ec0 — shape copy
  |     +-- FUN_00449a80 — HAT Polygon Surface Fit
  +-- FUN_0044af20 — CollisionFaceVerticesGather (leaf)
  +-- FUN_0044af60 — Axis permutation matrix read (leaf)
  +-- FUN_00449a80 — HAT Polygon Surface Fit
  |     +-- FUN_004ce8d0 — gaussian elimination
  |     +-- FUN_005677b0 — math utility
  +-- FUN_00587bcf — Free Wrapper
        +-- FUN_0058aa6f — free
```

## Step-by-Step Trace

### Level 0: FUN_0044b370 — Bezier Patch Tessellation

**Trigger:** Called from collision/render pipeline (FUN_0044bb60 apply matrix).
**Called by:** FUN_0044bb60 (collision geometry apply matrix).
**Purpose:** Subdivides Bezier patches into triangle meshes.

**Key actions:**
1. Reads count of patches from param_1[0]
2. For each patch: calls FUN_004493a0 (De Casteljau subdivision) 4 times
3. Builds 4 intermediate vertices per sub-patch
4. Evaluates quality via FUN_0044b110 (tangent continuity)
5. Allocates vertex buffer on subdivision complete
6. Smooths by averaging adjacent vertex positions

### Level 1: FUN_004493a0 — De Casteljau Subdivision Step

**Trigger:** Called 4× per patch.
**Purpose:** Single subdivision step on 4 control points — produces refined curve/surface.

### Level 1: FUN_0044b110 — ConstraintValidator3Way (quality eval)

**Trigger:** Evaluates subdivision quality.
**Purpose:** Checks tangent continuity across patch boundaries. If below threshold, continues subdividing.

**Key actions:**
1. Calls FUN_00448ee0 — color pack (visual debug)
2. Calls FUN_0044af20 — gather face vertices
3. Calls FUN_0044af60 — read axis permutation matrix
4. Calls FUN_0044b040 — copy shape to pipeline
5. Calls FUN_0044b090 — validator sub

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Patch count | param_1[0] | read | n_patches |
| Subdivision | 4 control points | De Casteljau 4× | 4 intermediate vertices |
| Quality check | tangent continuity | FUN_0044b110 | subdivide/stop |
| Buffer alloc | vertex count | operator_new | vertex buffer |
| Smoothing | vertex positions | average neighbors | smoothed mesh |

## Notes

- 12 callees, mostly collision/render utility functions (color pack, shape copy, alloc/free).
- Cross-system: FUN_0044b110 is in docs/06 (session logic) but used here for patch quality.
- Deeper functions called via FUN_00449a80 (Gaussian elimination for surface fit).
- Several callees are physics/collision functions reused for vertex data manipulation.

---
