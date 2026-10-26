## QuadraticCubicPolynomialEvaluator_004f3190 — dual quadratic polynomial evaluator

**Summary:** Evaluates two quadratic polynomials (a2²*C2 + a2*C1 + C0) using double-precision coefficients stored in the struct. Outputs zero if the enable flag is clear.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** WheelForceAggregate (00430600), CollisionEnergy (004390a0), SuspensionAndWheelPhysics (004e5f60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | enable flag: non-zero = evaluate polynomials, zero = zero outputs |
| this | 0x4 | R | — | polynomial 1 constant term C0 (double) |
| this | 0xC | R | — | polynomial 1 linear coefficient C1 (double) |
| this | 0x14 | R | — | polynomial 1 quadratic coefficient C2 (double) |
| this | 0x1C | R | — | polynomial 2 constant term C0' (double) |
| this | 0x24 | R | — | polynomial 2 linear coefficient C1' (double) |
| this | 0x2C | R | — | polynomial 2 quadratic coefficient C2' (double) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Byte at this+0: non-zero → computes both quadratic outputs into *a3 and *a4. Zero → sets both outputs to 0.0.
