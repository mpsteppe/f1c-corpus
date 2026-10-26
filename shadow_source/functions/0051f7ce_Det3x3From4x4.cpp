// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F7CE
// Canonical corpus name: Det3x3From4x4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Det3x3From4x4_0051f7ce.c

void UnknownObject::Det3x3From4x4()
{
    // Computes the determinant of the upper-left 3x3 submatrix of a 4x4 matrix whose four rows are read as 16-byte vectors from a1. An alignment guard chooses between aligned __m128 row loads at byte offsets 0x0, 0x10, 0x20 and 0x30 and unaligned upper-64-bit-half loads (_mm_loadh_ps) at byte offsets +8, +24, +40 and +56. The determinant is evaluated with SSE shuffle/multiply/subtract/add cofactor expansion, horizontally reduced, and returned as a double. Pure SSE math helper; no calls, no globals.
    // GUARD: Alignment guard on the matrix pointer: if (a1 & 0xF) != 0 the pointer is not 16-byte aligned and the unaligned load path is taken; otherwise the aligned __m128 path is used. [source:raw]
    // CALCULATION: Aligned path: load the four 16-byte rows of the 4x4 matrix as __m128 at byte offsets 0x0, 0x10, 0x20 and 0x30 into v1, v2, v3 and v4 respectively. [field:this:0x00000000, field:this:0x00000010, field:this:0x00000020, field:this:0x00000030, source:raw]
    // CALCULATION: Unaligned path: load each row's upper 64 bits via _mm_loadh_ps from byte offsets +8, +24, +40 and +56 into v2, v1, v3 and v4 respectively. [source:raw]
    // CALCULATION: First determinant stage over rows v3 and v4: v5 = shuffle(v3, 57); v6 = v4 * v5; v7 = shuffle(v4, 78); v8 = shuffle(v7, 57); v9 = v7 * v5; v10 = v5 * v8; v11 = shuffle(v10, 78) - v10. [source:raw]
    // CALCULATION: Second determinant stage folding in row v2 and v1: v12 = shuffle(v2, 57); v13 = shuffle(v12, 57); v14 = (v12 * (shuffle(v9, 57) - shuffle(v6, 78)) + v11 * v13 + shuffle(v13, 57) * (v9 - shuffle(v6, 57))) * v1. [source:raw]
    // CALCULATION: Horizontal reduction of the SSE determinant result: v15 = v14 + movehl(v14); scalar = v15[0] - shuffle(v15, v15, 1)[0]. [source:raw]
    // RETURN: Return the scalar determinant of the upper-left 3x3 submatrix widened to a double. [source:raw, function:0x0051F7CE]

    // Conservative worker pseudocode:
    //   double sub_51F7CE(int a1) {
    //     __m128 v1, v2, v3, v4;
    //     if ((a1 & 0xF) != 0) {
    //       // unaligned: upper 64-bit halves at a1+8, +24, +40, +56 via _mm_loadh_ps
    //       v2 = _mm_loadh_ps((const double *)(a1 + 24)); v1 = _mm_loadh_ps((const double *)(a1 + 8));
    //       v3 = _mm_loadh_ps((const double *)(a1 + 40)); v4 = _mm_loadh_ps((const double *)(a1 + 56));
    //     } else {
    //       // aligned: rows at a1+0x0, +0x10, +0x20, +0x30
    //       v1 = *(__m128 *)a1; v2 = *(__m128 *)(a1 + 16); v3 = *(__m128 *)(a1 + 32); v4 = *(__m128 *)(a1 + 48);
    //     }
    //     // SSE 3x3 cofactor expansion over v1..v4, then horizontal reduce to a float
    //     return (double)(float)determinant;
    //   }
    // UNRESOLVED: Exact semantics of the unaligned _mm_loadh_ps path (whether the lower 64 bits of each row vector are zero-filled) are decompiler-dependent; only the upper halves at a1+8, +24, +40 and +56 are observed being loaded.
    // UNRESOLVED: The caller's matrix layout is unproven: rows are read at 16-byte stride from a1 and the first three columns are treated as the 3x3 submatrix, but no caller or static call site establishes the concrete structure.
    // UNRESOLVED: Owner is unknown (pure math helper); no class or module attribution is available from the packet.
}
