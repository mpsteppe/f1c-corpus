// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052004E
// Canonical corpus name: F_34MatrixTransformWithSSE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_34MatrixTransformWithSSE_0052004e.c

void UnknownObject::F_34MatrixTransformWithSSE()
{
    // Transforms a 3-component source vector at a2 through a matrix at a3 whose rows include an unweighted translation row, then divides all components by the w lane using an SSE reciprocal refined by one Newton-Raphson iteration, and stores the resulting 3 components at a1. Matrix pointer alignment (a3 & 0xF) selects between unaligned 8-byte half-row loads and aligned __m128 row loads. Returns a1.
    // GUARD: Dispatch on matrix pointer alignment: when (a3 & 0xF) != 0 the matrix rows are loaded as 8-byte halves, otherwise rows are read as aligned 16-byte __m128 values at offsets 0, 16, 32, 48. [function:0x0052004E, source:raw]
    // CALCULATION: Combine four row contributions: x*row0 + y*row1 + z*row2 plus an unweighted fourth matrix row (translation contribution) at offset 48 (aligned) or 56 (unaligned). [source:raw]
    // CALCULATION: Compute the reciprocal of the w lane with _mm_rcp_ps and refine it with one Newton-Raphson iteration (2*r - vec*r*r), then broadcast the refined reciprocal to multiply all lanes of the transformed vector. [source:raw]
    // ASSIGNMENT: Write the normalized result to a1: the low 8 bytes hold the first two components and the upper 4 bytes at a1+8 hold the third component. [field:this:0x00000008, source:raw]
    // RETURN: Return a1, the destination vector pointer. [source:raw]

    // Conservative worker pseudocode:
    //   float* sub_52004E(float* dst, const float* src, const float* m) {
    //     if ((unsigned int)m & 0xF) { /* unaligned path: rows loaded as 8-byte halves * / }
    //     else { /* aligned path: rows loaded as __m128 at m+0, m+16, m+32, m+48 * / }
    //     /* v = x*row0 + y*row1 + z*row2 + translation(row3); * /
    //     /* r = rcp(v.w); r refined by one Newton-Raphson iteration; * /
    //     /* dst[0..1] = v*r, dst[2] = upper component of v*r * /
    //     return dst;
    //   }
    // UNRESOLVED: Matrix convention (row-major vs column-major) and the semantic meaning of the fourth row are caller-defined.
    // UNRESOLVED: The unaligned branch's 8-byte half-row loads are the decompiler's rendering of unaligned row access; exact lane mapping inferred from shuffle immediates.
}
