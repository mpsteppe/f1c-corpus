## SolverDispatch_0043b930 — Solver type dispatcher

**Summary:** Dispatches to different solver functions based on an operation type ID. Routes to spring evaluation, constraint solving, force/torque computation, or delta tracking. Part of the physics constraint solver dispatch system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConditionalMathDispatch (004f1860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0043b9d8 | jpt_43B947 | R | Jump table for switch-case dispatch |
| 0043b9f8 | byte_43B9F8 | R | Jump table index data |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00436470 | QuadraticSpringEval | Evaluates quadratic spring function (cases 9, 10) |
| 0043ba20 | ConstraintForceSolver | Solves constraint forces (case 14) |
| 0043bb00 | DeltaUpdateTracking | Tracks delta update for smoothing (case 3) |
| 0043bb30 | QuadFunctionEval | Evaluates quadratic function (case 27) |
| 0043bb80 | QuadraticForceTorqueCalculator | Computes quadratic force/torque (case 28) |
| 0043bbd0 | SpringDamperCompute | Computes spring-damper force (case 29) |

**Guard conditions:** Default case returns immediately (no-op for unrecognized type). Only cases 3, 9, 10, 14, 27, 28, 29 execute dispatch.
