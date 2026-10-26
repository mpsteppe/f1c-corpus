## SymmetricTransformMatrix3DNow_005229b5 — 3DNow! construct symmetric 4x4 transformation matrix from parameter

**Summary:** Loads packed float parameter a2, masks low dword with pand(0xFFFFFFFF), shifts high dword via psrlqi(32), calls PackedFloatingPointMath for setup, then builds a 4x4 matrix in a1 with symmetric entries: parameter value at diagonal positions (a1[0]=a1[5]), negated high dword at a1[1], identity elements (0x3F800000=1.0f) at a1[2]/a1[7], and high dword at a1[4].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Matrix row 0 col 0 (parameter low dword) |
| this | 0x8 | R | — | Matrix row 0 col 2-3 (negated high dword) |
| this | 0x10 | R | — | Matrix row 1 col 0-1 ({0, 1.0} identity) |
| this | 0x18 | R | — | Matrix row 1 col 2-3 (zeroed) |
| this | 0x20 | R | — | Matrix row 2 col 0-1 (parameter high dword) |
| this | 0x28 | R | — | Matrix row 2 col 2-3 (parameter low dword, symmetric) |
| this | 0x30 | R | — | Matrix row 3 col 0-1 (zeroed) |
| this | 0x38 | R | — | Matrix row 3 col 2-3 ({0, 1.0} homogeneous row) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af950 | qword_5AF950 | R | SIMDQuadMask [DERIVED] |
| 005af978 | qword_5AF978 | R | MMX_QuatInitConst_AF978 [DERIVED] |
| 005af9c0 | qword_5AF9C0 | R | ThreeDNowIdentityConst [DERIVED] |
| 005af9c8 | qword_5AF9C8 | R | MMatrixConstants [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005295e0 | PackedFloatingPointMath | Setup for parameter expansion into matrix cells |

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
