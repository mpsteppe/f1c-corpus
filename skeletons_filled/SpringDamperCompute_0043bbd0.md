## SpringDamperCompute_0043bbd0 — Spring-damper linear evaluation

**Summary:** Stores input value and evaluates three linear functions (result = a*x + b) for spring force, damper force, and combined output. Part of the spring-damper computation in the physics solver.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20), ClampedSpringIntegrator (0043e980), PhysicsForceVelocityClamping (0043ec80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1808 | R | — | Linear coefficient 'b' (constant term) for first curve |
| this | 0x1810 | R | — | Linear coefficient 'a' (x term) for first curve |
| this | 0x1818 | R | — | Linear coefficient 'b' (constant term) for second curve |
| this | 0x1820 | R | — | Linear coefficient 'a' (x term) for second curve |
| this | 0x1828 | R | — | Linear coefficient 'b' (constant term) for third curve |
| this | 0x1830 | R | — | Linear coefficient 'a' (x term) for third curve |
| this | 0x1ADC | RW | — | Output result of first linear evaluation |
| this | 0x1B94 | RW | — | Output result of second linear evaluation |
| this | 0x1C18 | RW | — | Input value storage |
| this | 0x1D9C | RW | — | Output result of third linear evaluation |

**Written-by note (persistence):**
- this 0x1ADC: recalc every frame — external poke does NOT persist
- this 0x1B94: recalc every frame — external poke does NOT persist
- this 0x1C18: recalc every frame — external poke does NOT persist
- this 0x1D9C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes, simple linear evaluation.
