## F_4x4MatrixMultiply_243a_0052243a — 3DNow! 4x4 matrix multiply

**Summary:** Multiplies two 4x4 matrices (a2 * a3) using 3DNow! intrinsics: transposes a3 into column-major halves via punpckldq/punpckhdq, then multiplies each of a2's 8 row-halves by the 4 column-halves of a3 with pfacc/pfmul/pfadd accumulation, writing the result 4x4 matrix to a1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Row 0, columns 0-1 (first __m64 pair) of 4x4 matrix |
| this | 0x8 | R | — | Row 0, columns 2-3 (second __m64 pair) of 4x4 matrix |
| this | 0x10 | R | — | Row 1, columns 0-1 of 4x4 matrix |
| this | 0x18 | R | — | Row 1, columns 2-3 of 4x4 matrix |
| this | 0x20 | R | — | Row 2, columns 0-1 of 4x4 matrix |
| this | 0x28 | R | — | Row 2, columns 2-3 of 4x4 matrix |
| this | 0x30 | R | — | Row 3, columns 0-1 of 4x4 matrix |
| this | 0x38 | R | — | Row 3, columns 2-3 of 4x4 matrix |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full matrix multiplication.
