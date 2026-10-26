## F_4x4TransformMatrixFrom3Ints_00522a6c — 3DNow! construct diagonal 4x4 scale matrix from 3 integer-reinterpreted floats

**Summary:** Constructs a 4x4 diagonal scale matrix in a1 from three parameters (a2, a3, a4): a2 placed as low dword of a1[0], a3 shifted left 32 bits to high dword of a1[2], a4 as low dword of a1[5], with identity homogeneous row (0, 0, 0, 1.0) at a1[7] and zeros elsewhere. Forms 3-axis scaling matrix with 1.0 at bottom-right.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Scale factor X |
| this | 0x8 | R | — | Zero |
| this | 0x10 | R | — | Scale factor Y (shifted to high dword) |
| this | 0x18 | R | — | Zero |
| this | 0x20 | R | — | Zero |
| this | 0x28 | R | — | Scale factor Z |
| this | 0x30 | R | — | Zero |
| this | 0x38 | R | — | Homogeneous row (0, 1.0) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af9c0 | qword_5AF9C0 | R | ThreeDNowIdentityConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full matrix construction.
