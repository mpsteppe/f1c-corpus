# Chain: Collision Object List Management — Collision proxy sorting and processing

Seed: FUN_004b4b50  |  System: docs/17-physics-collision.md  |  Depth: 4  |  Functions: ~12

---

## Overview

Collision Object List Management (FUN_004b4b50) manages 4 linked lists of collision proxy objects. It finds the minimum distance across all lists, removes objects within tolerance of the minimum, creates collision tree nodes, processes collisions via FUN_004b42e0, and performs post-collision cleanup via FUN_004bb490. Returns count of processed collisions. Called from FUN_004b7860 (Render Batch Node Allocator).

## Call Tree

```
FUN_004b4b50 — Collision Object List Management  [trigger: collision processing pass]
  +-- FUN_004bab20 — Unidentified Logic (Merge Sort — Linked List)  [tree node alloc]
  +-- FUN_004bac20 — Short Computation / Collision Proxy Node Creator  [proxy]
  +-- FUN_004b42e0 — Binary Data Reader  [collision response]
  +-- FUN_004bb490 — Linked List Insert (Head)  [post-collision]
  +-- FUN_004ba790 — Double Pointer Accessor  [list cleanup]
  +-- FUN_004b4470 — File Handle + Close Registration  [handle mgmt]
  +-- FUN_0049af30 — Linked List Free  [free]
  +-- FUN_00582290 — Conditional Free by Flag Check  [conditional free]
  +-- FUN_00587bcf — Free Wrapper  [heap free]
  +-- FUN_004646f0 — Conditional Destructor  [destructor]
```

## Step-by-Step Trace

### Level 0: FUN_004b4b50 — Collision Object List Management

**Trigger:** Collision processing pass — called from FUN_004b7860 (Render Batch Node Allocator)
**Called by:** FUN_004b7860 (Render Batch Node Allocator)
**Purpose:** Manage 4 collision proxy lists, sort by distance, process collisions

**Key actions:**
1. Initialize 4 collision lists at param_1+0x70 (stride 4 ints, head/tail/current ptrs, count at +0x7c)
2. Find minimum distance across all lists (local_1c = 1e38f start)
3. Iterate each list, remove objects within DAT_005acd0c tolerance of minimum
4. Create collision tree nodes via operator_new(0xc) → temp linked list
5. Call FUN_004b42e0 (collision response) and FUN_004bb490 (collision cleanup)
6. Free processed nodes via FUN_00582290/FUN_00587bcf

## Notes

- All callees are leaf or near-leaf utility functions — no subtrees beyond free wrapper
- FUN_00587bcf (Free Wrapper → FUN_0058aa6f) is a recurring leaf pattern across all chains
- DAT_005acd0c (tolerance) controls collision distance filtering

---
