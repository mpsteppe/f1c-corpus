## F_3DNowTransformationMatrixConstruction_00522952 — 3DNow! construct 4x4 transformation matrix from angle parameter

**Summary:** Loads single float parameter a2 into mm0, expands via PackedFloatingPointMath to populate both dword halves, then builds a 4x4 transformation matrix in a1 with identity-like rotation elements, the parameter and its negated copy (XOR 0x80000000) placed at specific matrix cells, forming an axis-specific rotation or shear transformation.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1065353216 → 1.0f | Matrix row 0 col 0 (identity/rotation diagonal) |
| this | 0x8 | R | — | Matrix row 0 col 2-3 (zeroed) |
| this | 0x10 | R | — | Matrix row 1 col 0-1 (one cell = float parameter) |
| this | 0x18 | R | — | Matrix row 1 col 2-3 (shifted parameter copy) |
| this | 0x20 | R | — | Matrix row 2 col 0-1 (one cell = negated parameter) |
| this | 0x28 | R | — | Matrix row 2 col 2-3 (parameter copy, zero) |
| this | 0x30 | R | — | Matrix row 3 col 0-1 (zeroed) |
| this | 0x38 | R | — | Matrix row 3 col 2-3 ({0, 1.0} homogeneous row) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af978 | qword_5AF978 | R | MMX_QuatInitConst_AF978 [DERIVED] |
| 005af9c0 | qword_5AF9C0 | R | ThreeDNowIdentityConst [DERIVED] |
| 005af9c8 | qword_5AF9C8 | R | MMatrixConstants [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005295e0 | PackedFloatingPointMath | Expands single float parameter into both halves of mm0 for matrix construction |

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
