## QuadraticSpringEval_00436470 — Quadratic spring function evaluation

**Summary:** Evaluates two quadratic spring functions at a given input value: result0 = a*x^2 + b*x + c for a set of spring coefficients. Computes both force and its derivative (damping) as quadratic functions. Part of the suspension spring model.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** SolverDispatch (0043b930), sub_43BC20 (0043bc20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | Constant term c for force (ax^2+bx+c) |
| this | 0xC | R | — | Linear coefficient b for force |
| this | 0x14 | R | — | Quadratic coefficient a for force |
| this | 0x1C | R | — | Constant term c for derivative (ax^2+bx+c) |
| this | 0x24 | R | — | Linear coefficient b for derivative |
| this | 0x2C | R | — | Quadratic coefficient a for derivative |
| this | 0x34 | W | — | Computed force result |
| this | 0x3C | W | — | Computed derivative result |

**Written-by note (persistence):**
- this 0x34: recalc every frame — external poke does NOT persist
- this 0x3C: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always executes, simple quadratic evaluation.
