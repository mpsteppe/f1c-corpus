# Chain: Vehicle Instance List Builder — Vehicle Object Construction

Seed: FUN_004b5c50  |  System: docs/10-vehicle-physics.md  |  Depth: 2  |  Functions: 8

---

## Overview

Called during session initialization to build the linked list of all active vehicle instances. Iterates the vehicle array (stride 0x48c0, 104 entries max). For each active slot (offset 13000 != -1), allocates a new vehicle object (FUN_004baa50), calls per-vehicle init (FUN_004baf10), sets parameter at +0x84 from DAT_008afea0, finishes init (FUN_004bb0c0), and appends to the linked list. Checks vehicle active state via FUN_004b5120 and runs vehicle update (FUN_004b51e0) post-construction.

## Call Tree

```
FUN_004b5c50 — Vehicle Instance List Builder  [trigger: session init — build vehicle list]
  +-- FUN_004baa50 — Alloc  [allocates new vehicle object]
  +-- FUN_004baf10 — Init  [per-vehicle initialization]
  +-- FUN_004bb0c0 — Finish Init  [completes vehicle setup]
  +-- FUN_004b51e0 — Vehicle Update  [post-construct update call]
  +-- FUN_004b5120 — Vehicle Active Check  [checks if vehicle slot is active]
  +-- FUN_004ba830 — Object Query  [query vehicle object state]
```

## Step-by-Step Trace

### Level 0: FUN_004b5c50 — Vehicle Instance List Builder

**Trigger:** Called once during session initialization to create vehicle objects.
**Called by:** Session setup code (callers: 1).
**Purpose:** Builds linked list of active vehicle instances from vehicle array.

**Key actions:**
1. Iterates vehicle array by +0x48c0 per step (104 iterations max)
2. For each iteration: advances a node pointer chain
3. If current node is empty AND vehicle at offset 13000 != -1 (active):
   - Allocates new object via FUN_004baa50
   - Creates list node, calls per-vehicle init via FUN_004baf10
   - Sets parameter at +0x84 from DAT_008afea0 (race time)
   - Calls FUN_004bb0c0 (finish init)
   - Appends to linked list, increments count
4. Checks active state via FUN_004b5120
5. Calls FUN_004b51e0 (vehicle update) and FUN_004ba830 (object query)

**Globals:** DAT_008afea0 (race time)

**Data passed to callees:** param_1 (vehicle array base pointer), linked list head pointer

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_004b5c50 | vehicle array | Iterate 104 slots | Active vehicle count |
| FUN_004baa50 | slot index | Allocate | New vehicle object |
| FUN_004baf10 | vehicle struct | Init | Initialized vehicle |
| FUN_004bb0c0 | vehicle struct | Finish init | Ready vehicle |
| FUN_004b5120 | vehicle slot | Check active | Boolean active flag |

## Globals Written in This Chain

| Global | Name | Written by | Value meaning |
|--------|------|-----------|---------------|
| DAT_008afea0 | RaceTime | (read by seed) | Written to vehicle +0x84 |

## Notes

- Stride 0x48c0 matches SeasonScoringDB stride from docs/12
- 104 iteration limit = max grid size for 1999-2002 F1 (26 cars × 4 seasons)
- The linked list built here is iterated by the physics/renderer each frame

---

---
