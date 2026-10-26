// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EF5E
// Canonical corpus name: SSE4x4MatrixMultiply
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSE4x4MatrixMultiply_0051ef5e.c

void UnknownObject::SSE4x4MatrixMultiply()
{
    // SSE-vectorized 4x4 matrix multiply. Reads the first operand matrix from a2 as sixteen packed four-float rows, reads the second operand from a3 via _mm_loadh_ps at half-vector offsets (a3+1, a3+3, a3+5, a3+7), broadcasts rows with _mm_shuffle_ps and multiply-accumulates them into row sums, then recombines the sums with _mm_unpacklo_ps/_mm_unpackhi_ps and stores the resulting 4x4 matrix as sixteen doubles into the destination a1 (at a1, a1+1 .. a1+7). Returns the destination pointer a1.
    // ASSIGNMENT: Load four packed row vectors v5..v8 from the second operand a3 via _mm_loadh_ps at the half-vector offsets a3+1, a3+3, a3+5, a3+7. [source:raw, function:0x0051EF5E]
    // CALCULATION: Broadcast each row of the first operand a2 (rows 0..15 read as packed __m128 values with _mm_shuffle_ps(x, x, 0)) and multiply-accumulate against v5..v8, producing row sums v9, v10, v13 and v17. [abi:lead, source:raw]
    // CALCULATION: Recombine the row sums with _mm_unpacklo_ps/_mm_unpackhi_ps into v11/v12 and, for the final row pair, v19/v20, producing the interleaved double-precision result components. [source:raw]
    // ASSIGNMENT: Store the computed 4x4 result into the destination matrix a1 as sixteen doubles via _mm_storel_ps/_mm_storeh_ps pairs at a1, a1+1, .. a1+7. [source:raw]
    // RETURN: Return the destination pointer a1 (result pointer in eax). [source:raw]

    // Conservative worker pseudocode:
    //   double *SSE4x4MatrixMultiply(double *a1, unsigned int *a2, const double *a3) {
    //     v5 = loadh(a3 + 1); v6 = loadh(a3 + 3); v7 = loadh(a3 + 5); v8 = loadh(a3 + 7);
    //     v9  = broadcast(a2[4]).v5 + broadcast(a2[5]).v6 + broadcast(a2[6]).v7 + broadcast(a2[7]).v8;
    //     v10 = broadcast(a2[0]).v5 + broadcast(a2[1]).v6 + broadcast(a2[2]).v7 + broadcast(a2[3]).v8;
    //     v13 = broadcast(a2[8]).v5 + broadcast(a2[9]).v6 + broadcast(a2[10]).v7 + broadcast(a2[11]).v8;
    //     v17 = broadcast(a2[12]).v5 + broadcast(a2[13]).v6 + broadcast(a2[14]).v7 + broadcast(a2[15]).v8;
    //     v11 = unpacklo(v10, v9); v12 = unpackhi(v10, v9);
    //     storel(a1, v11);     storeh(a1 + 2, v11);
    //     storel(a1 + 4, v12); storeh(a1 + 6, v12);
    //     v19 = unpacklo(v13, v17);
    //     storel(a1 + 1, v19); storeh(a1 + 3, v19);
    //     v20 = unpackhi(v13, v17);
    //     storel(a1 + 5, v20); storeh(a1 + 7, v20);
    //     return a1;
    //   }
    // UNRESOLVED: Exact memory layout of both input matrices (row-major vs column-major, float vs double element type) is not resolved from the intrinsics alone.
    // UNRESOLVED: a3 is declared const double* yet is read at 32-bit granularity via _mm_loadh_ps; the true element type and row stride of a3 are ambiguous.
    // UNRESOLVED: Operand order of the multiplication (a2 * a3 vs a3 * a2) and the semantic role of the a2 packed rows are not proven.
    // UNRESOLVED: The canonical name SSE4x4MatrixMultiply derives from the corpus ABI lead name, not from independent runtime evidence.
}
