# Chain: InputCommandDispatch — Input Dispatch to Game Entities

Seed: FUN_0045f4a0  |  System: docs/01-engine-architecture.md  |  Depth: 3  |  Functions: 10

---

## Overview

Triggered from collision response status handler (`FUN_00463cd0`). Reads input buffer and dispatches commands to all active game entities. Most complex sub-branch is the Entity Visibility Grid Manager (`FUN_00465460`, 13 callees), which manages linked lists of visible entities with a per-frame time budget. Supporting callees handle ring buffer advancement, message dispatch allocation, and texture creation wrappers.

## Call Tree

```
FUN_0045f4a0 — InputCommandDispatch  [trigger: collision response status]
  +-- FUN_00465460 — Entity Visibility Grid Manager  [13 callees]
  |     +-- FUN_00464990 — Entity Iterator
  |     +-- FUN_00465c70 — Merge Sort by Float Key
  |     +-- FUN_00465d70 — List Manager
  |     +-- FUN_004b33b0 — Sound Trigger
  |     +-- FUN_00587bcf — Memory Free
  |     +-- 8 additional leaf callees omitted
  +-- FUN_00465300 — MessageDispatchNodeAllocator  [2 callees]
  +-- FUN_0057a730 — TwoStepInitSubCall  [2 callees]
  +-- FUN_00461440 — SessionFlagCheck  [reads globals]
  +-- 10 additional leaf callees omitted
```

## Step-by-Step Trace

### Level 0: FUN_0045f4a0 — InputCommandDispatch

**Trigger:** Called from FUN_00463cd0 (Collision Response Status, docs/17)
**Called by:** FUN_00463cd0 — collision response status handler
**Purpose:** Distributes input commands from input buffer to all active game entities.

**Key actions:**
1. Gets input state buffer, loops while input available
2. For each entity in list: skips self and checks mode
3. If mode != 3 or AI-controlled skip condition passed: dispatches command
4. Checks input flags: bit 28, bit 5, byte value
5. Second pass for active input state: dispatches per-entity lookups and sub-commands

**Data passed to callees:** Input buffer state, entity list pointers, command IDs.

### Level 1: FUN_00465460 — Entity Visibility Grid Manager

**Trigger:** Called from input command dispatch during entity processing
**Purpose:** Manages linked lists of visible/active entities with time budget counter.

**Key actions:**
1. Reads param_3 (entity type/ID filter), allocates 0xc-linked-list nodes for matching entities
2. Tracks two separate linked lists at +0xe5c0 and +0xe5b0
3. Uses integer budget counter decremented per entity
4. After list assembly, merge-sorts by float key via FUN_00465c70
5. Iterates entities via FUN_00464990
6. Stores remaining budget back to per-vehicle slot

**Struct offsets:** +0x6c (ListHead), +0xe5c0 (WorkListHead), +0xe5b0 (ActiveListHead), +0x2b4 (BudgetRemaining per vehicle, stride 0x230)

**Globals:** DAT_008afe90, DAT_005ec6d8, DAT_005f0f88

### Level 2: FUN_00464990 — Entity Iterator

**Trigger:** Called from Visibility Grid Manager after list assembly
**Purpose:** Iterates entities in active list, performs per-entity processing.

### Level 2: FUN_00465c70 — Merge Sort by Float Key

**Trigger:** Called from Visibility Grid Manager
**Purpose:** Sorts entity list using merge sort algorithm ordered by float comparison key.

### Level 2: FUN_00587bcf — Memory Free

**Trigger:** Called from Visibility Grid Manager for cleanup
**Purpose:** Frees allocated entity list nodes.

### Level 1: FUN_00465300 — MessageDispatchNodeAllocator

**Trigger:** Called from input command dispatch
**Purpose:** Allocates message dispatch nodes.

**Key actions:**
1. Allocates node from pool
2. Returns pointer for command dispatch

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0045f4a0 | Input buffer, entity list | Loop + dispatch | Per-entity commands |
| FUN_00465460 | Entity type filter, budget | List assembly + sort | Filtered entity active list |
| FUN_00464990 | Active entity list | Iteration | Per-entity processing |
| FUN_00465c70 | Unsorted entity list | Merge sort by float | Sorted entity list |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afe90 | (threshold/scale) | FUN_00465460 | Visibility threshold |
| DAT_005ec6d8 | Entity config table | FUN_00465460 | Per-entity config |
| DAT_005f0f88 | Vehicle lookup table | FUN_00465460 | Per-vehicle index |

## Notes

- Most complex callee is FUN_00465460 (Entity Visibility Grid Manager) with 13 sub-callees — 8 leaf callees omitted
- FUN_00461440 (SessionFlagCheck) references global state but has call_count=0 (no further callees)
- FUN_004b0170 is an empty stub (vtable slot) — effectively a no-op in the chain
- Chain depth limited to 3 levels — all deeper callees are leaf functions

---
