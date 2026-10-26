## QuadraticForceTorqueCalculator_0043bb80 — Quadratic force-torque calculator

**Summary:** Evaluates two quadratic functions at input value and stores results as force and torque components. Uses coefficients from the physics struct. Part of the vehicle dynamics force/torque computation system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), PhysicsAccumulatorIntegrate (0043eae0), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x17D8 | R | — | Quadratic coefficient 'c' (constant term) for first curve |
| this | 0x17E0 | R | — | Quadratic coefficient 'b' (linear term) for first curve |
| this | 0x17E8 | R | — | Quadratic coefficient 'a' (x^2 term) for first curve |
| this | 0x17F0 | R | — | Quadratic coefficient 'c' (constant term) for second curve |
| this | 0x17F8 | R | — | Quadratic coefficient 'b' (linear term) for second curve |
| this | 0x1800 | R | — | Quadratic coefficient 'a' (x^2 term) for second curve |
| this | 0x1A0C | RW | — | Output result of first quadratic evaluation |
| this | 0x1ABC | RW | — | Output result of second quadratic evaluation |
| this | 0x1C38 | RW | — | Input value storage |

**Written-by note (persistence):**
- this 0x1A0C: recalc every frame — external poke does NOT persist
- this 0x1ABC: recalc every frame — external poke does NOT persist
- this 0x1C38: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes, simple quadratic evaluation.
