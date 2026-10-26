## QuadFunctionEval_0043bb30 — Quadratic function evaluation

**Summary:** Evaluates two quadratic functions at input value: result = a*x^2 + b*x + c, and stores both input and results. Used for non-linear spring curve evaluation in the physics solver.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), SuspensionDamperForceAccumulation (0043e890), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17A8 | R | — | Quadratic coefficient 'c' (constant term) for first curve |
| this | 0x17B0 | R | — | Quadratic coefficient 'b' (linear term) for first curve |
| this | 0x17B8 | R | — | Quadratic coefficient 'a' (x^2 term) for first curve |
| this | 0x17C0 | R | — | Quadratic coefficient 'c' (constant term) for second curve |
| this | 0x17C8 | R | — | Quadratic coefficient 'b' (linear term) for second curve |
| this | 0x17D0 | R | — | Quadratic coefficient 'a' (x^2 term) for second curve |
| this | 0x1930 | RW | — | Output result of first quadratic evaluation |
| this | 0x19E8 | RW | — | Output result of second quadratic evaluation |
| this | 0x1C00 | RW | — | Input value storage |

**Written-by note (persistence):**
- this 0x1930: recalc every frame — external poke does NOT persist
- this 0x19E8: recalc every frame — external poke does NOT persist
- this 0x1C00: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes, simple quadratic evaluation.
