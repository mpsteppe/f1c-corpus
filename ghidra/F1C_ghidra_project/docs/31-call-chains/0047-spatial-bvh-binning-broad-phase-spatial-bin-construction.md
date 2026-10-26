# Chain 46: Spatial BVH/Binning — Broad-phase spatial bin construction

Seed: FUN_004de610  |  System: docs/17-physics-collision.md  |  Depth: 2  |  Functions: 6 callees

---

## Overview

Triggered during collision broad phase. Builds spatial bins for collision detection by allocating per-object buckets, populating vertex data, sorting by Z coordinate with binary search, performing distance threshold checks, computing plane equations for backface culling, and building vertex adjacency.

## Call Tree

```
FUN_004de610 — Spatial BVH/Binning  [trigger: collision broad phase]
  +-- FUN_0054c210 — Scene Graph Child Count  [count objects]
  +-- FUN_0054c230 — Linked List Indexed Accessor  [access bucket data]
  +-- FUN_0054e100 — PackedArrayTotalSize  [mesh data size]
  +-- FUN_005890aa — Sort  [binary search sort by Z]
  +-- FUN_004dd9f0 — Plane Equation  [compute plane for backface culling]
  +-- FUN_004de5d0 — Indexed Struct Field Compute  [triangle fetch]
```

## Step-by-Step Trace

### Level 0: FUN_004de610 — Spatial BVH/Binning

**Trigger:** Collision broad phase per frame or on scene change.
**Called by:** Orphan (no callers recorded).
**Purpose:** Builds spatial bins for collision broad phase.

**Key actions:**
1. Allocates per-object buckets with FUN_0054c210/230
2. Populates vertex data from mesh (FUN_0054e100)
3. Binary search sort by Z coordinate (FUN_005890aa)
4. Distance threshold checks against DAT_005ad13c
5. Plane equation via FUN_004dd9f0 for backface culling
6. Vertex adjacency building for collision geometry (FUN_004de5d0)

**Globals:** DAT_005ad13c (distance threshold)

### Level 1: Key callees

**FUN_005890aa — Sort** — Binary search sort by Z coordinate. Leaf function.

**FUN_004dd9f0 — Plane Equation** — Computes plane equation for backface culling. Leaf.

**FUN_004de5d0 — Indexed Struct Field Compute** — Computes triangle fetch for adjacency building. Leaf.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0054c210 | Scene objects | Count objects | Object count |
| FUN_0054c230 | Bucket indices | Access bucket data | Bucket data |
| FUN_005890aa | Vertex Z values | Binary sort | Sorted vertex order |
| FUN_004dd9f0 | Triangle vertices | Plane equation | Plane normal+distance |
| FUN_004de5d0 | Vertex indices | Build adjacency | Adjacency list |

## Globals Written in This Chain

None directly.

## Notes

- Broad-phase spatial subdivision for collision detection
- `hardcoded`

---
