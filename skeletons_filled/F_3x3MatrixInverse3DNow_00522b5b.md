## F_3x3MatrixInverse3DNow_00522b5b — 3DNow! 3x3 matrix inverse (rotation submatrix) embedded in 4x4

**Summary:** Computes 3x3 inverse of rotation submatrix from input a2 using the adjugate/transpose method: doubles source elements (pfadd), unpacks for cross-term computation, computes cofactor-like products (pfmul) with 1.0 - trace/determinant (pfsubr 0x3F8000003F800000LL), reshuffles via punpck into the 3x3 output positions of a1. Sets a1[6] = 0 and a1[7] = {0, 1.0f} for homogeneous last row.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | Output matrix row 0 col 0-1 (inverse top-left) |
| this | 0x8 | R | — | Output matrix row 0 col 2-3 (inverse + zero) |
| this | 0x10 | R | — | Output matrix row 1 col 0-1 (inverse) |
| this | 0x18 | R | — | Output matrix row 1 col 2-3 (inverse + zero) |
| this | 0x20 | R | — | Output matrix row 2 col 0-1 (inverse) |
| this | 0x28 | R | — | Output matrix row 2 col 2-3 (inverse + zero) |
| this | 0x30 | R | — | Output matrix row 3 col 0-1 (zero) |
| this | 0x38 | R | — | Output matrix row 3 col 2-3 ({0, 1.0} homogeneous row) |

**Written-by note (persistence):**
- this 0x0: All 8 __m64 slots written once; purely output matrix, no persistence.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af900 | qword_5AF900 | R | AngleConstantPair1 [DERIVED] (SIMD constant for inverse computation) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** None — no conditional branches; always executes full inverse computation.
