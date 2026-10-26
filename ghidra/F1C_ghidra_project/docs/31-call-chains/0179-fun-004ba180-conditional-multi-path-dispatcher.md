# Chain 178: FUN_004ba180 — Conditional Multi-Path Dispatcher

Seed: FUN_004ba180  |  System: docs/20-math-utilities.md  |  Depth: 2  |  Functions: 6

---

## Overview

A conditional state dispatcher — calls 6 callees in a chain where each callee may branch to a different path. Described as timing updates (engine-architecture docs). The chain forms: Validation → State Query → State Setter → Common Path → Set Float Constant → Alt Path. Used during frame timing to dispatch conditional state logic.

## Call Tree

```
FUN_004ba180 — Conditional Multi-Path Dispatcher  [called by: per-frame timing updates]
  +-- FUN_004b9a00 — [undocumented] Validation  [leaf]
  +-- FUN_004b8bd0 — [undocumented] State Query  [leaf]
  +-- FUN_004b8c40 — [undocumented] State Setter (3 callees)
  |     +-- FUN_004b8790 — [undocumented]
  |     +-- FUN_004b86e0 — [undocumented]
  |     +-- FUN_004c8d60 — [undocumented]
  +-- FUN_004b9d20 — [undocumented] Common Path  [leaf]
  +-- FUN_004c8dc0 — [undocumented] Set Float Constant  [leaf]
  +-- FUN_004b9e40 — [undocumented] Alt Path (3 callees)
        +-- FUN_004b87a0 — [undocumented]
        +-- FUN_004b86e0 — [undocumented]
        +-- FUN_004b9d00 — [undocumented]
```

## Step-by-Step Trace

### Level 0: FUN_004ba180 — Conditional Multi-Path Dispatcher

**Trigger:** Per-frame timing update in main loop
**Called by:** FUN_004b8ae0
**Purpose:** Dispatches conditional state logic across 6 ordered paths

**Key actions:**
1. Calls FUN_004b9a00 — validates precondition
2. Calls FUN_004b8bd0 — queries current state
3. Calls FUN_004b8c40 — sets state, may delegate further
4. Calls FUN_004b9d20 — common execution path
5. Calls FUN_004bc8dc0 — writes float constant to struct
6. Calls FUN_004b9e40 — alternative path with 3 sub-callees

## Data Flow Summary

| Step | Path | Operation |
|------|------|-----------|
| 1 | FUN_004b9a00 | Validation check |
| 2 | FUN_004b8bd0 | State query |
| 3 | FUN_004b8c40 | State mutation → 3 sub-callees |
| 4 | FUN_004b9d20 | Common processing |
| 5 | FUN_004c8dc0 | Float constant write |
| 6 | FUN_004b9e40 | Alt path → 3 sub-callees |

## Notes

- 0 of 6 callees are in functions.json — all from decompiled_full anonymous corpus
- Callee descriptions suggest state machine pattern: validation → query → setter → common → alt
- Mentioned in engine-architecture docs as timing update alongside FUN_00463ca0
- All callees are undocumented

---
