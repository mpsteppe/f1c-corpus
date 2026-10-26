# Chain: PhysicsStepFrame — Single Physics Simulation Frame

Seed: FUN_00441600  |  System: docs/18-physics-dynamics.md  |  Depth: 2  |  Functions: 8

---

## Overview

Orchestrates one full physics simulation update step. Calls frame init, transform update, solver steps (two stages), constraint/contact resolver, and post-step cleanup. Returns computed solver value.

## Call Tree

```
FUN_00441600 — PhysicsStepFrame  [per-physics-frame call]
  +-- FUN_004412f0 — Wheel State History Shift [frame init]
  +-- FUN_0043f7f0 — Suspension/Wheel Dynamics Solver (Constraint-Based) [transform]
  |     +-- FUN_00438930 — suspension solve
  |     +-- FUN_005895a2 — math solver
  |     +-- FUN_00435290 — wheel force
  |     +-- FUN_005677b0 — math utility
  |     +-- FUN_0059d7b5 — constraint
  +-- FUN_0056ecf0 — physics solver step 1 [336 bytes]
  +-- FUN_0056ee40 — ConstraintForceAccumulator [solver step 2]
  |     +-- FUN_00569ad0 — force accumulate
  |     +-- FUN_00569b70 — constraint project
  +-- FUN_0056f090 — Iterate and Find Minimum Value from Function [solver/resolver]
  |     +-- FUN_00569de0 — min search
  +-- FUN_00441450 — PhysicsSubObjectFree [cleanup]
        +-- FUN_004389b0 — sub object free
```

## Step-by-Step Trace

### Level 0: FUN_00441600 — PhysicsStepFrame

**Trigger:** Called once per physics simulation frame (no callers in knowledge graph, likely called from main physics loop).
**Called by:** No callers in graph (likely called from Game::Post loop).
**Purpose:** Runs one complete physics step: init, transform, solver, resolver, cleanup.

**Key actions:**
1. Calls FUN_004412f0() — frame init (wheel state history shift)
2. Calls FUN_0043f7f0(param_1, param_2) — transform update (suspension/wheel dynamics)
3. Calls FUN_0056ecf0() — first solver step
4. Calls FUN_0056ee40() — constraint force accumulator
5. Calls FUN_0056f090(param_1, param_2) — minimum-search resolver
6. Calls FUN_00441450() — post-step cleanup
7. Returns computed value from solver

**Data passed to callees:** Physics state struct pointer (param_1), timestep (param_2).

### Level 1: FUN_0043f7f0 — Suspension/Wheel Dynamics Solver

**Trigger:** Called after frame init.
**Purpose:** Solves suspension and wheel dynamics constraints for all wheels.

**Key actions:**
1. Calls FUN_00438930 — suspension solve
2. Calls FUN_005895a2 — math solver (cholesky?)
3. Calls FUN_00435290 — wheel force computation
4. Calls FUN_005677b0 — general math utility
5. Calls FUN_0059d7b5 — constraint function

### Level 1: FUN_0056ee40 — ConstraintForceAccumulator

**Trigger:** Called after first solver step.
**Purpose:** Accumulates constraint forces from all active contacts.

**Key actions:**
1. Calls FUN_00569ad0 — accumulate force
2. Calls FUN_00569b70 — constraint projection

### Level 1: FUN_0056f090 — Solver Minimum Search

**Trigger:** Called for final constraint resolution.
**Purpose:** Iterates constraint solutions to find minimum energy/maximum stability state.

### Level 1: FUN_00441450 — PhysicsSubObjectFree

**Trigger:** Called for post-step cleanup.
**Purpose:** Frees temporary physics sub-objects allocated during the step.

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| Init | physics state | shift wheel history | prepped state |
| Transform | vehicle state | suspension solve | updated transforms |
| Solver 1 | transforms | constraint solve | intermediate forces |
| Solver 2 | forces | accumulate | constraint forces |
| Resolver | constraints | minimize | stable state |
| Cleanup | temp objects | free | clean state |

## Notes

- 6 callees, linear pipeline with well-defined stages.
- FUN_0043f7f0 is the deepest subtree (6 sub-callees) — the heavy physics computation.
- FUN_0056ecf0 and FUN_0056ee40 appear to be separate solver stages (likely velocity solve followed by position solve).

---
