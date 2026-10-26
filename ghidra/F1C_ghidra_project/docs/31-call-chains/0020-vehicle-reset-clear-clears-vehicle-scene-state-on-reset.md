# Chain: Vehicle Reset/Clear -- clears vehicle scene state on reset

Seed: FUN_004e09e0  |  System: docs/10-vehicle-physics.md  |  Depth: 3  |  Functions: 18

---

## Overview

FUN_004e09e0 (Vehicle Reset/Clear) resets vehicle scene state during grid reset. Called from FUN_004c6e80 (ResetDriverGridState, docs/06). Checks global flag DAT_008afe88. Dispatches to 7 callees spanning scene node init, 3D sound cleanup, status field management, timer processing, array cleanup, and memory zeroing.

Call graph is wide (7 direct callees) but shallow (max depth 3). Most branches terminate at leaf utilities, with only 0x004e0db0 and 0x00545150 extending deeper.

## Call Tree

```
FUN_004e09e0 -- Vehicle Reset/Clear  [docs/10-vehicle-physics.md, 7 callees]
|
+-- FUN_004e0db0 -- Multi-system struct initializer  [docs/06, 1 callee] [LEVEL 2]
|   +-- FUN_004e0d00 -- LazyInitCallback  [docs/06, 4 callees] [LEVEL 3]
|       +-- FUN_0054ba00 -- Doubly-Linked List Node Mover  [docs/06, LEAF]
|       +-- FUN_0054b4d0 -- [PARTIAL] Unknown  [docs/20, LEAF]
|       +-- FUN_004e0ed0 -- Audio/Sound Effect Controller  [docs/19, LEAF]
|       +-- FUN_00411440 -- ScoringGate vehicle lookup  [docs/06, LEAF]
|
+-- FUN_00545150 -- 3D Sound Source Destructor  [docs/06, 6 callees] [LEVEL 2]
|   +-- FUN_0054a770 -- Scene Graph / Object Tree Cleanup  [docs/06, LEAF]
|   +-- FUN_00560e50 -- Multi-Field Object Destructor  [docs/01, LEAF]
|   +-- FUN_005459d0 -- LinkedListRemove  [docs/06, LEAF]
|   +-- FUN_00587bcf -- Free wrapper  [docs/01, 1 callee] [LEVEL 3]
|   |   +-- FUN_0058aa6f -- Heap deallocation  [docs/20, LEAF]
|   +-- FUN_005452b0 -- LinkedListRemove  [docs/06, LEAF]
|   +-- FUN_0054a710 -- Two Function Call Chain  [docs/20, 2 callees] [LEVEL 3]
|       +-- FUN_0053b160 -- (untracked, LEAF)
|       +-- FUN_004b0170 -- destructor/pit system  [docs/06, LEAF]
|
+-- FUN_00411570 -- Status Field Copy  [docs/20, 1 callee] [LEVEL 2]
|   +-- FUN_0040e710 -- Short Computation (Switch Dispatch)  [docs/20, LEAF]
|
+-- FUN_004e38d0 -- Timer Clamp and Process  [docs/06, 1 callee] [LEVEL 2]
|   +-- FUN_004ded20 -- Dual Array Destructor  [docs/06, LEAF]
|
+-- FUN_004e3050 -- Array Cleanup (4 entries, stride 0x128)  [docs/18, LEAF]
|
+-- FUN_004dfa50 -- 17-Element Zero-Init Loop  [docs/20, LEAF]
|
+-- FUN_004b33b0 -- ProgressBarEventEncode  [docs/20, LEAF]
```

## Step-by-Step Trace

### Level 0 -- Seed
**FUN_004e09e0 -- Vehicle Reset/Clear** (docs/10-vehicle-physics.md):
- Source: vehicle_reset.cpp
- Checks DAT_008afe88 flag (vehicle reset guard)
- Calls 7 init/cleanup functions in sequence
- Resets vehicle scene state: scene nodes, sound sources, status fields, timers, arrays
- All operations are struct-internal (param_1 vehicle struct)

### Level 1 -- Direct Callees

**1. FUN_004e0db0 -- Multi-system struct initializer** (docs/06):
- Initializes vehicle sub-systems
- Single callee: FUN_004e0d00 (LazyInitCallback)

**2. FUN_00545150 -- 3D Sound Source Destructor** (docs/06):
- Source: audio system
- Destructs 3D sound emitter attached to vehicle
- 6 callees: scene graph cleanup (FUN_0054a770), object destructor (FUN_00560e50), two linked-list removes (FUN_005459d0, FUN_005452b0), free wrapper (FUN_00587bcf), two-function call chain (FUN_0054a710)
- Most complex callee in the chain -- 6 sub-operations

**3. FUN_00411570 -- Status Field Copy** (docs/20):
- Copies a status field value
- Calls FUN_0040e710 (switch-dispatch field setter)

**4. FUN_004e38d0 -- Timer Clamp and Process** (docs/06):
- Source: likely hdvehicle/hdvehicle
- Clamps timer value and runs per-tick processing
- Calls FUN_004ded20 (Dual Array Destructor)

**5. FUN_004e3050 -- Array Cleanup** (docs/18):
- Cleans up 4-entry array with stride 0x128
- Leaf -- no further callees

**6. FUN_004dfa50 -- 17-Element Zero-Init Loop** (docs/20):
- Zero-initializes 17 elements
- Leaf -- no further callees

**7. FUN_004b33b0 -- ProgressBarEventEncode** (docs/20):
- Encodes progress bar event for loading screen
- Leaf -- no further callees

### Level 2 -- Deepest branches

**From FUN_004e0db0:**
- FUN_004e0d00 -- LazyInitCallback (docs/06): 4 callees -- list node mover, unknown partial, audio controller, scoring gate lookup. All leaves.

**From FUN_00545150:**
- FUN_00587bcf -- Free wrapper (docs/01): thunk to FUN_0058aa6f (heap deallocation). Depth 3.
- FUN_0054a710 -- Two Function Call Chain (docs/20): calls FUN_0053b160 + FUN_004b0170 (destructor). Depth 3.

### Level 3 -- Termination
- FUN_0058aa6f -- Heap deallocation (from FUN_00587bcf)
- FUN_0053b160 -- untracked (from FUN_0054a710)
- FUN_004b0170 -- destructor (from FUN_0054a710)

## Data Flow Summary

```
FUN_004e09e0(param_1=VehicleStruct*, DAT_008afe88 flag)
  |
  +--> FUN_004e0db0  init sub-systems
  |     +--> FUN_004e0d00  lazy init -> list/audio/scoring setup
  |
  +--> FUN_00545150  destroy 3D sound source
  |     +--> FUN_0054a770  scene graph node cleanup
  |     +--> FUN_00560e50  multi-field destructor
  |     +--> FUN_005459d0  linked-list remove
  |     +--> FUN_00587bcf -> FUN_0058aa6f  free heap
  |     +--> FUN_005452b0  linked-list remove
  |     +--> FUN_0054a710 -> FUN_0053b160 + FUN_004b0170  call chain
  |
  +--> FUN_00411570 -> FUN_0040e710  status field copy
  +--> FUN_004e38d0 -> FUN_004ded20  timer clamp + array destruct
  +--> FUN_004e3050  array cleanup (stride 0x128)
  +--> FUN_004dfa50  17-element zero-init
  +--> FUN_004b33b0  progress bar encode
```

**Data flowing:**
- param_1: Vehicle struct -- all operations target this struct or its sub-objects
- DAT_008afe88: global flag checked by seed, controls reset behavior
- No file I/O -- purely in-memory struct reset/cleanup

## Globals Written

| Address | Name | What |
|---------|------|------|
| DAT_008afe88 | VehicleResetFlag | Checked by seed -- controls reset path |

No game-state globals directly written by callees. Operations are struct-scoped to param_1 (vehicle instance).

## Notes

- **Max depth:** 3 (through sound destructor free chain and two-function call chain)
- **7 direct callees:** only 2 are non-leaf (FUN_004e0db0, FUN_00545150)
- **Sound destructor (FUN_00545150):** dominant branch -- 6 sub-callees, 2 reaching depth 3
- **No file I/O:** purely in-memory struct initialization/cleanup
- **Single caller:** FUN_004c6e80 (ResetDriverGridState) in docs/06
- **Coverage:** spans docs/01, docs/06, docs/10, docs/18, docs/19, docs/20 -- 6 doc files
- **Predominant system:** docs/06-session-race-logic.md (9 of 18 functions)

---
