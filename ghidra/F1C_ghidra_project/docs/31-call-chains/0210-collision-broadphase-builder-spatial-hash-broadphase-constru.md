# Chain: Collision Broadphase Builder — Spatial hash broadphase construction

Seed: FUN_00490ee0  |  System: docs/17-physics-collision.md  |  Depth: 6  |  Functions: ~20

---

## Overview

Collision Broadphase Builder (FUN_00490ee0) queries collision proxies via AABB overlap testing, builds linked lists of intersecting proxies, removes stale entries, and reindexes the spatial hash. Called from FUN_004918d0 (Render Surface Fill/Copy). The deepest subtree is FUN_00490d00 (SpatialHashReindex) with 10 callees including AABB neighbor queries, node alloc/dealloc, and linked list operations.

## Call Tree

```
FUN_00490ee0 — Collision Broadphase Builder  [trigger: collision pass]
  +-- FUN_00490940 — Resource Pool Node Alloc/Dealloc  [pool alloc/free]
  |     +-- FUN_00490930 — Global Data Read
  |     |     +-- FUN_004906e0 — Custom Memory Pool Allocator Init
  |     |           +-- FUN_004912f0 (thunk to 00491330) — Short Array Zero-Init
  |     |           +-- FUN_00491710 — Object Alloc/Init with vtable
  |     |           +-- FUN_00587b3e — Boolean-to-Int Conversion (register cleanup)
  |     +-- FUN_00491d30 — Linked List Node Removal by Value
  |     +-- FUN_004912f0 (thunk) — Array Zero-Init
  |     +-- FUN_00491e40 — Conditional Data Free (Flag-Gated)
  |     +-- FUN_00587bcf — Free Wrapper
  |     +-- [4 additional leaf callees]
  +-- FUN_00491680 — AABB Overlap Test  [broadphase test]
  +-- FUN_00491350 — Rectangle Clipping  [rect clip]
  +-- FUN_00490aa0 — Linked List Node Prepend  [list prepend]
  +-- FUN_004bac20 — Collision Proxy Node Creator  [proxy]
  +-- FUN_00490d00 — SpatialHashReindex  [spatial hash rebuild]
  |     +-- FUN_00491350 — Rectangle Clipping  [neighbor query]
  |     |     +-- FUN_00490940 — Pool Alloc/Dealloc  [rect allocator]
  |     |           +-- [same subtree as above]
  |     +-- FUN_00587bcf — Free Wrapper  [node free]
  |     +-- FUN_00491e10 — Free Internal Buffer  [event A]
  |     +-- FUN_00491e40 — Conditional Data Free  [event B]
  |     +-- FUN_004915a0 — AABB Overlap Test (Short-Coordinate)  [broadphase A]
  |     +-- FUN_00491680 — AABB Overlap Test  [broadphase B]
  |     +-- FUN_004bac20 — New Node Alloc  [proxy]
  |     +-- FUN_004ba780 — Short Computation (Linked List Peek)  [callback]
  |     +-- FUN_00490aa0 — Linked List Node Prepend  [post-reindex]
  |     +-- FUN_00581780 — Linked List Node Advance  [list traversal]
  +-- FUN_00434030 — Doubly-Linked List Append  [list append]
  +-- FUN_00581780 — Linked List Node Advance  [list advance]
  +-- FUN_00491db0 — Linked List Destructor (Conditional Free)  [destructor]
  |     +-- FUN_00587bcf — Free Wrapper → FUN_0058aa6f
```

## Step-by-Step Trace

### Level 0: FUN_00490ee0 — Collision Broadphase Builder

**Trigger:** Collision broadphase pass — called from FUN_004918d0 (Render Surface Fill/Copy)
**Called by:** FUN_004918d0 (Render Surface Fill/Copy)
**Purpose:** Build linked list of intersecting collision proxies for narrowphase

**Key actions:**
1. Query collision proxies via FUN_00490940/00491680/00491350
2. Build linked list of intersecting proxies (allocates 0xc nodes via operator_new)
3. Remove stale entries by matching iVar7
4. Notify via FUN_00491e10
5. Build temp list via FUN_004bac20
6. Merge/reindex via FUN_00490d00 (SpatialHashReindex)
7. Iterate results via FUN_00434030/FUN_00581780

### Level 1: FUN_00490d00 — SpatialHashReindex

**Trigger:** Called from Broadphase Builder to rebuild spatial hash
**Called by:** FUN_00490ee0
**Purpose:** Reindex collision proxies into spatial hash grid

**Key actions:**
1. Neighbor query via FUN_00491350 (rectangle clipping)
2. Node cleanup via FUN_00587bcf (free), FUN_00491e10 (buffer free), FUN_00491e40 (conditional free)
3. Broadphase tests via FUN_004915a0, FUN_00491680
4. New node allocation via FUN_004bac20
5. Linked list operations via FUN_00490aa0, FUN_00581780

### Level 2: FUN_00490940 — Resource Pool Node Alloc/Dealloc

**Trigger:** Called by multiple functions for pool memory management
**Called by:** FUN_00490ee0, FUN_00491350, FUN_00490d00
**Purpose:** Allocate/deallocate nodes from a custom memory pool

**Key actions:**
1. Pool init via FUN_004906e0 (Custom Memory Pool Allocator Init) → array zero-init, object constructor with vtable, register cleanup
2. Node removal via FUN_00491d30 → free wrapper
3. Array zero-init via FUN_004912f0
4. Flag-gated data free via FUN_00491e40

## Notes

- FUN_00490940 is the most deeply reused utility in this chain — called from 3 different ancestors
- FUN_004906e0 (Custom Memory Pool Allocator Init) is a 3-callee subtree shared between pool init paths
- FUN_00587bcf (Free Wrapper → FUN_0058aa6f) recurses 7 times across this chain
- The FUN_00491350 → FUN_00490940 path recurs: FUN_00490ee0 calls FUN_00490940 directly, and FUN_00491350 calls it again

---
