# Chain: SolverDispatch — Physics Solver Type Selector

Seed: FUN_0043b930  |  System: docs/18-physics-dynamics.md  |  Depth: 1  |  Functions: 6 callees

---

## Overview

Dispatches to physics solver implementations based on solver type code (param_1). Switch on 7 cases: type 3, 9, 10, 14, 27, 28, 29 — each calls a different solver function. All 6 callees are leaf functions with no further call chains.

## Call Tree

```
FUN_0043b930 — SolverDispatch  [trigger: physics step, called by constraint solver pipeline]
  +-- FUN_0043bb00 — Solver type 3 (wheel/constraint solver)         [leaf]
  +-- FUN_00436470 — Solver type 9 and 10 (shared handler)           [leaf]
  +-- FUN_0043ba20 — Solver type 14                                   [depth 1: HAS 0 callees]
  +-- FUN_0043bb30 — Solver type 27                                   [leaf]
  +-- FUN_0043bb80 — Solver type 28                                   [leaf]
  +-- FUN_0043bbd0 — Solver type 29                                   [leaf]
```

## Step-by-Step Trace

### Level 0: FUN_0043b930 — SolverDispatch

**Trigger:** Per-physics-step, called from constraint solver pipeline.
**Called by:** Unknown (callers.json shows 1 caller — from physics integration loop)
**Purpose:** Route solver type code to specific physics solver implementation.

**Key actions:**
1. Switch on param_1 (solver type code):
   - case 3 → FUN_0043bb00 (wheel/constraint solver)
   - case 9 → FUN_00436470 (shared with case 10)
   - case 10 → FUN_00436470
   - case 14 (0xe) → FUN_0043ba20
   - case 27 (0x1b) → FUN_0043bb30
   - case 28 (0x1c) → FUN_0043bb80
   - case 29 (0x1d) → FUN_0043bbd0

**Data passed to callees:** Solver-specific parameters from caller.

### Level 1: Callees

All callees are physics solver implementations:
- **FUN_0043bb00** — Solver for wheel constraints (type 3)
- **FUN_00436470** — Shared solver for types 9 and 10
- **FUN_0043ba20** — Solver type 14 (has 0 further callees)
- **FUN_0043bb30** — Solver type 27
- **FUN_0043bb80** — Solver type 28
- **FUN_0043bbd0** — Solver type 29

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| FUN_0043b930 | type code | switch dispatch | solver execution |
| FUN_0043bb00 | params | constraint solve | updated constraint |

## Globals Written in This Chain

None.

## Notes

Chain depth = 1 for all callees except FUN_0043ba20 (depth 1 with 0 further callees). Solver type codes 3, 9, 10, 14, 27-29 map to specific constraint solver algorithms inside the physics engine.

---
