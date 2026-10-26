## Det3x3From4x4_0051f7ce — SSE3x3DeterminantFrom4x4Matrix

**Summary:** Computes the determinant of the upper-left 3x3 submatrix extracted from a 4x4 matrix (4 rows of __m128 at 16-byte stride). Uses SSE shuffle/multiply/subtract/add with alignment-aware load path (unaligned via _mm_loadh_ps if address not 16-byte aligned). Returns determinant as double. Part of SSE math library.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | Row 0 of 4x4 matrix (first 3 columns used for determinant) |
| this | 0x10 | R | — | Row 1 of 4x4 matrix |
| this | 0x20 | R | — | Row 2 of 4x4 matrix |
| this | 0x30 | R | — | Row 3 of 4x4 matrix |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Checks `(a1 & 0xF) != 0` — alignment guard only. PASSES (uses unaligned _mm_loadh_ps loads) when address not 16-byte aligned. BLOCKED (uses aligned __m128 loads) when address is 16-byte aligned. Not a semantic guard.
