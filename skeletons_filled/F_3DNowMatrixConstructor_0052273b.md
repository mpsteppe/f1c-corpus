## F_3DNowMatrixConstructor_0052273b — 3DNow! construct 4x4 transformation matrix from 3 components

**Summary:** Initializes a 4x4 matrix (8 __m64 values) in a1 with identity-like rotation (1.0/0 constants at specific cells) and packs three float parameters (a2, a3, a4) plus 1.0 into the last row via punpckldq to form the translation part of a transformation matrix.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1065353216 → 1.0f | Matrix row 0 col 0 (identity element) |
| this | 0x8 | R | — | Matrix row 0 col 1-2 (set to zero) |
| this | 0x10 | R | — | Matrix row 1 col 0-1 (one cell = 1.0f) |
| this | 0x18 | R | — | Matrix row 1 col 2-3 (set to zero) |
| this | 0x20 | R | — | Matrix row 2 col 0-1 (set to zero) |
| this | 0x28 | R | — | Matrix row 2 col 2-3 (one cell = 1.0f) |
| this | 0x30 | R | — | Translation component X, Y |
| this | 0x38 | R | — | Translation component Z + 1.0 homogeneous |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af9c0 | qword_5AF9C0 | R | ThreeDNowIdentityConst [DERIVED] |
| 005af9c8 | qword_5AF9C8 | R | MMatrixConstants [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
