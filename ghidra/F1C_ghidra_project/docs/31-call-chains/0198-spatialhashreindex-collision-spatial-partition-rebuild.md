# Chain 197: SpatialHashReindex — Collision Spatial Partition Rebuild

Seed: FUN_00490d00  |  System: docs/17-physics-collision.md  |  Depth: 3  |  Functions: 10 callees

---

## Overview

FUN_00490d00 rebuilds the spatial hash partition for collision detection. It iterates collision proxies in a source linked list, tests each against bounds via broadphase tests (FUN_004915a0, FUN_00491680), queries neighbors (FUN_00491350), and reassigns proxies to correct spatial buckets. Stale entries are freed. Triggered by FUN_00490ee0 or FUN_00491ad0 during collision scene changes. The chain includes AABB overlap tests (short-coordinate), rectangle clipping, linked list operations, and event notification.

## Call Tree

```
FUN_00490d00 — SpatialHashReindex  [trigger: collision scene change via 0x00490ee0/0x00491ad0]
  +-- FUN_004915a0 — AABB Overlap Test (Short-Coordinate)  [leaf, docs/20]
  +-- FUN_00491680 — Axis-Aligned Bounding Box Overlap Test  [leaf, docs/20]
  +-- FUN_00491350 — Rectangle Clipping / Neighbor Query  [docs/19]
  |     +-- FUN_004912f0 — Thunk to FUN_00491330  [docs/20]
  |           +-- FUN_00491330 — Short Array Zero-Init  [leaf]
  +-- FUN_004bac20 — Short Computation / Collision Proxy Node Creator  [leaf, docs/17]
  +-- FUN_004ba780 — First-Insert Callback  [leaf, docs/20]
  +-- FUN_00587bcf — Node Free (operator delete)  [leaf]
  +-- FUN_00490aa0 — Linked List Node Prepend / Post-Reindex Hook  [leaf, docs/01]
  +-- FUN_00581780 — Linked List Node Advance / List Traversal  [leaf, docs/01]
  +-- FUN_00491e10 — Free Internal Buffer / Event A  [docs/01]
  |     +-- FUN_00499ae0 — Free If Non-Null  [docs/20]
  +-- FUN_00491e40 — Conditional Data Free (Flag-Gated) / Event B  [docs/20]
        +-- FUN_00491d30 — Linked List Node Removal by Value  [docs/20]
```

## Step-by-Step Trace

### Level 0: FUN_00490d00 — SpatialHashReindex

**Trigger:** Called by FUN_00490ee0 or FUN_00491ad0 when collision proxies change buckets.
**Called by:** FUN_00490ee0, FUN_00491ad0
**Purpose:** Rebuilds spatial partition: moves collision proxies to correct spatial buckets.

**Key actions:**
1. Takes source and destination linked lists (param_1, param_2)
2. Iterates source list via short[4] bounding box (x1,y1,x2,y2)
3. For each proxy: tests broadphase A (FUN_004915a0) and B (FUN_00491680)
4. If both pass: proxy is in correct bucket — keeps, queries neighbors, inserts into new bucket
5. If A passes but B fails: proxy stale — removes and frees via FUN_00587bcf
6. Maintains insertion count, triggers FUN_004ba780 on first insert
7. Post-reindex hook via FUN_00490aa0

**Data passed to callees:** Collision proxy linked list pointers, short[4] bounding boxes

### Level 1: FUN_004915a0 — AABB Overlap Test (Short-Coordinate)

**Trigger:** Called per proxy to test if it belongs in current bucket.
**Purpose:** Broadphase AABB overlap test using short-coordinate bounding boxes.

**Key actions:**
1. Reads 4 shorts (x1,y1,x2,y2) from proxy struct
2. Compares against bucket bounds
3. Returns overlap result

### Level 1: FUN_00491350 — Rectangle Clipping / Neighbor Query

**Trigger:** Called for proxies in correct bucket to find neighbors.
**Purpose:** Finds neighboring collision objects within spatial region.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_00490d00 | Source list + dest list | Iteration + test | Reindexed spatial buckets |
| FUN_004915a0 | short[4] bounds | AABB overlap test | Pass/fail |
| FUN_00491680 | short[4] bounds | AABB overlap test | Pass/fail |
| FUN_00491350 | Bucket neighbors | Rectangle clip | Neighbor list |
| FUN_004bac20 | Collision proxy data | Node creation | New spatial node |

## Notes

- 10 callees spanning docs/17 (collision), docs/20 (math_util), docs/19 (renderer), docs/01 (engine)
- FUN_004915a0 and FUN_00491680 are both leaf AABB overlap tests (docs/20) — likely short and full-precision variants
- FUN_00491e10 and FUN_00491e40 are event notification hooks at end of reindex

---
