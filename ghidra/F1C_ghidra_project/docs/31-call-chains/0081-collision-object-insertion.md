# Chain: Collision Object Insertion

Seed: FUN_004b48e0  |  System: docs/20-math-utilities.md  |  Depth: 3  |  Functions: 9

---

## Overview

Inserts a collision object node into the collision spatial data structure. Performs category validation, pre-insert callback, allocation check, node allocation, setup, param processing, and post-insert callback. Uses pre-allocated global pool (DAT_008ab708) if available, otherwise falls back to operator_new.

## Call Tree

```
FUN_004b48e0 — Collision Object Insertion  [trigger: collision object registration]
  +-- FUN_004b4760 — CategoryValidation  [validate object category]
  +-- FUN_004ba780 — PreInsertCallback  [pre-insert callback]
  +-- FUN_004bb6b0 — AllocCheck  [allocation check]
  +-- FUN_004ba950 — NodeAlloc  [node allocation]
  |     +-- operator_new
  +-- FUN_004bac40 — NodeSetup1  [node setup phase 1]
  |     +-- FUN_004bacf0 — NodeSetup2  [node setup phase 2]
  |           +-- FUN_004b3a90 — ParamProcessing  [param processing]
  |                 +-- FUN_004b47a0 — PostInsertCallback  [post-insert callback]
```

## Step-by-Step Trace

### Level 0: FUN_004b48e0 — Collision Object Insertion

**Trigger:** Called when a collision object needs to be registered in the collision space
**Called by:** Collision system, pit stall animation (docs/06)
**Purpose:** Inserts collision object node into spatial data structure.

**Key actions:**
1. Checks category via FUN_004b4760
2. Calls pre-insert callback via FUN_004ba780
3. Checks allocation availability via FUN_004bb6b0
4. Allocates node via FUN_004ba950 (operator_new or pool)
5. Sets up node via FUN_004bac40/FUN_004bacf0
6. Processes parameters via FUN_004b3a90
7. Calls post-insert callback via FUN_004b47a0

**Data passed to callees:** Collision object pointer, category, params

### Level 1: FUN_004bac40 — NodeSetup1

**Trigger:** After node allocation
**Called by:** FUN_004b48e0
**Purpose:** Sets up collision node, then delegates to phase 2.

### Level 2: FUN_004b3a90 — ParamProcessing

**Trigger:** After node setup
**Called by:** FUN_004bacf0
**Purpose:** Processes collision parameters, then calls post-insert callback.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b48e0 | Category enum | Validation check | Pass/fail |
| FUN_004b48e0 | DAT_008ab708 | Pool allocation or operator_new | Node pointer |
| FUN_004b48e0 | Collision params | Node setup and registration | Registered node |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008AB708 | GlobalAllocPoolNode | (read by FUN_004b48e0) | Pre-allocated pool node |

## Notes

- The function uses a pre-allocated global memory pool (DAT_008ab708) to avoid per-frame allocation
- Falls back to operator_new if pool is exhausted
- Category validation gates the entire insertion
- This function is called from pit stall animation setup (FUN_004b68c0 chain, docs/06)

---
