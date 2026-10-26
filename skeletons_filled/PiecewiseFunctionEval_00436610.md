## PiecewiseFunctionEval_00436610 — Piecewise function evaluation with boundary correction

**Summary:** Evaluates a 2-input piecewise function with multiple linear segments selected by sign and magnitude of inputs. Applies additional correction terms when the primary input exceeds defined range boundaries. Used for non-linear spring/damper characteristic curves in the constraint solver.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ConstraintEnforce (004380b0), sub_442C90 (00442c90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Primary input scaling coefficient |
| this | 0x8 | R | — | Piecewise coefficient for positive a3 (high segment) |
| this | 0x10 | R | — | Piecewise coefficient for positive a3 (low segment) |
| this | 0x18 | R | — | Threshold dividing positive a3 segments |
| this | 0x20 | R | — | Constant offset for positive a3 high segment |
| this | 0x28 | R | — | Piecewise coefficient for negative a3 (low magnitude) |
| this | 0x30 | R | — | Piecewise coefficient for negative a3 (high magnitude) |
| this | 0x38 | R | — | Threshold dividing negative a3 segments |
| this | 0x40 | R | — | Constant offset for negative a3 low magnitude segment |
| this | 0x48 | R | — | Boundary correction offset term |
| this | 0x50 | R | — | Boundary correction linear coefficient |
| this | 0x58 | R | — | Boundary correction offset term 2 |
| this | 0x60 | R | — | Boundary correction linear coefficient 2 |
| this | 0x68 | R | — | Upper boundary limit for a2 |
| this | 0x70 | R | — | Lower boundary limit for a2 |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Implicit — piecewise branching on a3 <= 0, a3 >= this[7], a3 <= this[3]; and on a2 <= this[14]. No early-return guards.
