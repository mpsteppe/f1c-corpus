## F_3DNowQuaternionFromEncodedAxisAngle_00522a13 — 3DNow! decode axis-angle parameter to 4x4 transformation matrix

**Summary:** Loads encoded axis-angle value a2 into mm0, expands via PackedFloatingPointMath, then builds a 4x4 matrix in a1: the encoded value goes to a1[0], a negated reshuffled copy (via punpckhdq/punpckldq with XOR 0x80000000) to a1[2], identity 1.0f elements at a1[5] and a1[7], and zeros elsewhere.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Matrix row 0 col 0-1 (decoded axis-angle component) |
| this | 0x8 | R | — | Matrix row 0 col 2-3 (zeroed) |
| this | 0x10 | R | — | Matrix row 1 col 0-1 (negated shuffled parameter) |
| this | 0x18 | R | — | Matrix row 1 col 2-3 (zeroed) |
| this | 0x20 | R | — | Matrix row 2 col 0-1 (zeroed) |
| this | 0x28 | R | — | Matrix row 2 col 2-3 ({1.0, 0} identity) |
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
| 005295e0 | PackedFloatingPointMath | Expands encoded axis-angle parameter for matrix placement |

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
