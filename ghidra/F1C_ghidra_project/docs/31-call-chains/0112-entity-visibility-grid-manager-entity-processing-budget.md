# Chain: Entity Visibility Grid Manager — Entity Processing Budget

Seed: 0x00465460  |  System: docs/18-physics-dynamics.md  |  Depth: 3  |  Functions: 13

---

## Overview

Entity Visibility Grid Manager allocates processing time across visible entities per frame. Called by 0x0045f4a0 (unknown), it reads entity type/ID filters, assembles work lists of matching entities, sorts them by distance/priority via merge sort, and iterates them within a per-vehicle time budget. The budget counter decrements per-entity and carries over to the next frame, implementing a soft real-time constraint on entity processing.

## Call Tree

```
FUN_00465460 — Entity Visibility Grid Manager  [trigger: per-frame entity processing]
  +-- FUN_00582290 — Conditional Free by Flag Check  [leaf]
  +-- FUN_00587bcf — Free Wrapper (Thunk to FUN_0058aa6f)  [memory free]
  +-- FUN_00464f50 — Division with Cap Computation  [leaf]
  +-- FUN_00464f90 — Threshold-to-Rank Classifier  [leaf]
  +-- FUN_00464bb0 — General utility  [leaf]
  +-- FUN_00464bd0 — Float Field Decrement with Clamp  [leaf]
  +-- FUN_00464ad0 — Dispatch Wrapper (Call with 1)  [leaf]
  +-- FUN_00464ae0 — Byte sign + compare  [leaf]
  +-- FUN_00464990 — Short Computation / Squared Distance  [leaf]
  +-- FUN_00465c70 — Merge Sort on Linked List (Float Key)
  |     +-- FUN_00465d70 — Recursive Linked List Merge Sort  [leaf]
  +-- FUN_00465d70 — Recursive Linked List Merge Sort  [leaf]
  +-- FUN_004b33b0 — ProgressBarEventEncode  [sound? — leaf]
  +-- FUN_004b2c80 — Vector-to-Short3 Conversion
```

## Step-by-Step Trace

### Level 0: FUN_00465460 — Entity Visibility Grid Manager

**Trigger:** Called per-frame from 0x0045f4a0
**Called by:** 0x0045f4a0 (unknown — likely main entity processing distributor)
**Purpose:** Manages linked lists of visible/active entities per frame with time budget counter.

**Key actions:**
1. Reads param_3 (entity type/ID filter), allocates 0xc-linked-list nodes for matching entities
2. Tracks two linked lists: +0xe5c0 (pending work list) and +0xe5b0 (current active list)
3. Uses integer budget counter `local_2c`, decremented per entity (cost from entity header)
4. Calls FUN_00465c70 (merge sort by float key — distance/priority) on active list
5. Iterates each entity via FUN_00464990 (squared distance check)
6. Stores remaining budget to `*(short *)(struct + iVar14*0x230 + 0x2b4)` for next frame carry-over

**Data passed to callees:** entity pointers, list heads, budget counter

### Level 1: FUN_00465c70 — Merge Sort on Linked List (Float Key)

**Trigger:** Called to sort active entity list before processing
**Purpose:** Sorts linked list nodes by float key (distance or priority)
**Key actions:** Delegates to FUN_00465d70 (recursive merge sort implementation)

### Level 1: FUN_00464990 — Squared Distance Between 3D Points

**Trigger:** Called per entity during processing loop
**Purpose:** Computes squared distance between entity position and reference point

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Grid Manager | param_3 (entity filter) | linked list assembly | work list at +0xe5c0 |
| Grid Manager | budget counter local_2c | decrement per entity | remaining budget |
| Grid Manager | active list | merge sort (float key) | sorted list at +0xe5b0 |
| Grid Manager | entity data | squared distance check | visibility decision |

## Globals Written in This Chain

- `DAT_005ec6d8` — per-entity config table (read)
- `DAT_005f0f88` — per-vehicle lookup index (read)
- `DAT_008afe90` — threshold/scale (read)

## Notes

- Budget carry-over mechanism implements frame-rate independent entity processing
- Merge sort (FUN_00465c70/FUN_00465d70) is the only non-leaf computation — rest are simple field ops
- FUN_004b33b0 (ProgressBarEventEncode) is a cross-system handoff to audio/sound progress reporting

---
