# Chain: GlobalListTripleCleanup — Three linked list cleanup with timer removal

Seed: FUN_00414210  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 6

---

## Overview

Shutdown/resource cleanup function that destroys three global linked lists with different destructor strategies. Pre-cleanup via FUN_004150c0, then destroys DAT_005ea608 list with FUN_00414420 (5-pointer free), DAT_005ea5f8 list with FUN_00414380 (multi-field free), DAT_005ea5e8 list with timer removal (4 timers per node via FUN_004149a0) plus freed data. Zeros all list heads after cleanup.

## Call Tree

```
FUN_00414210 — GlobalListTripleCleanup  [trigger: shutdown or resource cleanup]
  +-- FUN_004150c0 — DrawableResourceCleanup  [pre-cleanup, 6 callees]
  |     +-- [subtree: 6 callees — docs/06, render cleanup]
  +-- FUN_00414420 — MultiPointerFree(5)  [frees data ptr + 4 additional ptrs in node]  [leaf]
  |     [called iteratively for each node in DAT_005ea608 list]
  +-- FUN_00414380 — MultiFieldPointerFree  [frees multi-field node struct]  [leaf]
  |     [called iteratively for each node in DAT_005ea5f8 list]
  +-- FUN_004149a0 — TextFormatStructInitLarge  [timer struct init per node, 1 callee]
  |     [called 4× per node in DAT_005ea5e8 list — removes 4 timers]
  |     +-- FUN_005895a2 — [undocumented]
  +-- FUN_00401030 — ArrayDestructorIterator  [array iteration destructor]  [leaf]
  +-- FUN_00587bcf — FreeWrapper  [frees node memory after data destruction]  [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_00414210 — GlobalListTripleCleanup

**Trigger:** Game shutdown or subsystem cleanup — registered as callback by FUN_00414200
**Called by:** No callers found (callers.json — 0 callers). Registered as atexit/callback via FUN_00587b3e.
**Purpose:** Clean up three global resource linked lists with specialized per-list destructors.

**Key actions:**
1. Calls FUN_004150c0 — pre-cleanup (drawable/resource cleanup, 6 callees)
2. Destroys DAT_005ea608 list:
   - Iterates list nodes
   - Calls FUN_00414420 on each node's data (frees data + 4 additional pointers)
   - Calls FUN_00587bcf to free node memory
3. Destroys DAT_005ea5f8 list:
   - Iterates list nodes
   - Calls FUN_00414380 on each node's data (frees multi-field struct)
   - Calls FUN_00587bcf to free node memory
4. Destroys DAT_005ea5e8 list:
   - Iterates list nodes
   - Removes 4 timers per node via FUN_004149a0 (×4)
   - Calls FUN_00414420 on node data
   - Calls FUN_00587bcf to free node memory
5. Zeros all three list heads (DAT_005ea608 = DAT_005ea5f8 = DAT_005ea5e8 = 0)

**Data passed to callees:** linked list head pointers (3 globals), per-node data pointers

### Level 1: Callees

**FUN_004150c0 — DrawableResourceCleanup (6 callees)**
Pre-cleanup pass for drawable/renderer resources. Handles texture, mesh, and shader cleanup before the main list destruction.

**FUN_00414420 — MultiPointerFree [leaf]**
Frees a data pointer plus 4 additional pointers stored within a node struct. Used for complex nodes with multiple allocation fields.

**FUN_00414380 — MultiFieldPointerFree [leaf]**
Frees multiple fields within a different struct layout. Different field pattern from FUN_00414420.

**FUN_004149a0 — TextFormatStructInitLarge (1 callee)**
Despite name, used here for timer removal — called 4 times per node to remove 4 timer entries associated with each node in list 3.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Pre-cleanup | renderer state | 6 callees | resources released |
| List 1 | DAT_005ea608 | 5-ptr free per node | list destroyed |
| List 2 | DAT_005ea5f8 | multi-field free per node | list destroyed |
| List 3 | DAT_005ea5e8 | 4× timer remove + free | list destroyed |
| Final | 3 heads | zeroed | clean state |

## Globals Modified

| Global | Name | Modification |
|--------|------|-------------|
| DAT_005ea608 | DestroyLinkedListHead1 | Zeroed after cleanup |
| DAT_005ea5f8 | ResourceList_Geom | Zeroed after cleanup |
| DAT_005ea5e8 | MemoryCleanupList3 | Zeroed after cleanup |

## Notes

- Three different destructor strategies suggest three different resource types:
  - List 1 (DAT_005ea608): Complex nodes with 5 allocatable pointers each
  - List 2 (DAT_005ea5f8): Renderer geometry resources (multi-field struct)
  - List 3 (DAT_005ea5e8): Timed resources with 4 timer slots per node
- Registered as cleanup callback by FUN_00414200 via FUN_00587b3e
- The 4-timer-per-node pattern in list 3 suggests audio or animation resources with scheduled events

---
