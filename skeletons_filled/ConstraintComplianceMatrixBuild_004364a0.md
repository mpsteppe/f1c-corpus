## ConstraintComplianceMatrixBuild_004364a0 — Constraint compliance matrix build

**Summary:** Builds a 3x5 constraint compliance matrix from constraint parameters (inverse mass, geometric dimensions, damping). Computes matrix elements as products of input scalars and vector components. Returns true if any non-zero compliance exists. Part of the constraint solver setup.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_43C250 (0043c250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Compliance matrix element [0][0] |
| this | 0x8 | RW | — | Compliance matrix element [0][1] |
| this | 0x10 | RW | — | Compliance matrix element [0][2] |
| this | 0x18 | RW | — | Compliance matrix element [1][0] |
| this | 0x20 | RW | — | Compliance matrix element [1][1] |
| this | 0x28 | RW | — | Compliance matrix element [1][2] |
| this | 0x30 | RW | — | Compliance matrix element [2][0] |
| this | 0x38 | RW | — | Compliance matrix element [2][1] |
| this | 0x40 | RW | — | Compliance matrix element [2][2] |
| this | 0x48 | RW | — | Compliance matrix element [3][0] |
| this | 0x50 | RW | — | Compliance matrix element [3][1] |
| this | 0x58 | RW | — | Compliance matrix element [3][2] |
| this | 0x60 | RW | — | Compliance matrix element [4][0] |
| this | 0x68 | RW | — | Compliance matrix element [4][1] |
| this | 0x70 | RW | — | Compliance matrix element [4][2] |

**Written-by note (persistence):**
- this 0x0: recalc every frame — external poke does NOT persist
- this 0x8: recalc every frame — external poke does NOT persist
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x18: recalc every frame — external poke does NOT persist
- this 0x20: recalc every frame — external poke does NOT persist
- this 0x28: recalc every frame — external poke does NOT persist
- this 0x30: recalc every frame — external poke does NOT persist
- this 0x38: recalc every frame — external poke does NOT persist
- this 0x40: recalc every frame — external poke does NOT persist
- this 0x48: recalc every frame — external poke does NOT persist
- this 0x50: recalc every frame — external poke does NOT persist
- this 0x58: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0x68: recalc every frame — external poke does NOT persist
- this 0x70: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e430 | dbl_59E430 | R | ZeroSentinel [DERIVED] (also: ` (ZeroSentinel ~0.0) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — always builds the matrix. Return value indicates whether any compliance element is non-zero.
