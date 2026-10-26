# Chain: Suspension/Wheel Dynamics Solver (Constraint-Based) — Semi-Implicit Euler Suspension Solver

Seed: 0x0043f7f0  |  System: docs/10-vehicle-physics.md  |  Depth: 1  |  Functions: 6

---

## Overview

Called from physics init (0x004412f0) and physics step (0x0045a4d0) per frame. Core suspension solver implementing semi-implicit Euler integration with constraint solving. Computes spring/damper forces from non-linear curve tables, selects wheel grouping by SolverMode (0=axle pair, 1=four-wheel, 2=alternate), solves velocity+position constraints with Jacobian computation and minimum-stable-timestep selection. Sub-steps if needed. All 6 callees are leaf math utilities (RNG, sqrt, comparison, Cholesky solver, error handlers).

## Call Tree

```
0x0043f7f0 — Suspension/Wheel Dynamics Solver (Constraint-Based)  [trigger: per-frame physics step]
  +-- 0x00438930 — rng  [grip variation noise]
  +-- 0x005895a2 — sqrt/math  [vector magnitude]
  +-- 0x00435290 — comparison gate  [threshold checks]
  +-- 0x005677b0 — cholesky/matrix solve  [constraint matrix solve]
  +-- 0x0059d7b5 — error handler  [division-by-zero]
  +-- 0x0059d928 — error handler  [constraint failure]
```

## Step-by-Step Trace

### Level 0: 0x0043f7f0 — Suspension/Wheel Dynamics Solver (Constraint-Based)

**Trigger:** Called per physics frame from physics step loop
**Called by:** 0x004412f0 (physics init), 0x0045a4d0 (physics step)
**Purpose:** Semi-implicit Euler integration with constraint solving for suspension

**Key actions:**
1. Reads timestep dt (param_2) from caller
2. Generates random noise via 0x00438930 for grip variation
3. Interpolates non-linear spring/damper curves from table at param_1+0x1cfc:
   - Linear interpolation of float table (stride 8 bytes: [x0,y0],[x1,y1])
   - Stores SpringForce at +0x1d00, DamperForce at +0x1d04
4. Selects wheel grouping via SolverMode at +0x1e14:
   - 0: axle pair (2 wheels)
   - 1: full vehicle (4 wheels)
   - 2: alternate pair
5. Per-wheel arrays at stride 0x464: reads position/force/velocity/mass/bias
6. Constraint solve: computes candidate timesteps:
   - dStack_2c0 from velocity constraint
   - dStack_2b8 from position/penetration constraint
   - Selects minimum stable timestep
7. Jacobian computation: negative ratio of bias/effective mass per wheel
8. Applies forces to param_1+0x15f0 (WheelForceTarget) at +0x14c/+0x154/+0x15c
9. Sub-stepping: if computed timestep < dt, loops remaining time
10. Error handlers: 0x0059d7b5 (div-by-zero), 0x0059d928 (constraint failure)

## Data Flow Summary

| Step | Input | Operation | Output |
|------|-------|-----------|--------|
| 0x00438930 | — | Random noise | grip variation offset |
| param_1+0x1cfc | SpringCurveTable | Linear interpolate | SpringForce/DamperForce |
| param_1+0x1e14 | SolverMode | Select wheel group | 0/1/2 axle config |
| 0x005677b0 | constraint matrix | Cholesky solve | Jacobian forces |
| 0x0043f7f0 | Jacobians | Apply forces | wheel force accumulator (+0x15f0) |

## Globals Written in This Chain

None — all state on vehicle suspension struct (param_1)

## Notes

- All 6 callees are leaf math/error utilities
- Cholesky solver (0x005677b0) is shared across physics (also used in HAT polygon surface fit)
- Solver uses goto chains for sub-stepping loop — MSVC optimization artifact
- Non-linear spring curves come from setup file data
---
