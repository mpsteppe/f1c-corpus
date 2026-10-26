// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052020E
// Canonical corpus name: F_4x4MatrixMultiply_020e
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixMultiply_020e_0052020e.c

void UnknownObject::F_4x4MatrixMultiply()
{
    // SIMD 4x4 matrix multiply: the left matrix a2 (16 dwords, read as four rows of four) is multiplied component-wise against four column vectors loaded from the right matrix a3 (via _mm_loadh_ps at a3+1, a3+3, a3+5, a3+7), each row summed into a result vector that is stored into the output matrix a1 (eight _mm_storel_ps/_mm_storeh_ps pairs). Returns the output pointer a1. The canonical corpus name F_4x4MatrixMultiply_020e retains an address-derived suffix.
    // ASSIGNMENT: Preserve the output pointer: result = a1 (returned at the end). [source:raw]
    // CALCULATION: Load the four column vectors of the right-hand matrix into SIMD registers v5..v8 with _mm_loadh_ps from a3+1, a3+3, a3+5, a3+7. [source:raw]
    // CALCULATION: Row 0 of a2 (elements a2[0..3], each broadcast via _mm_shuffle_ps with mask 0) multiplied component-wise by v5..v8 and summed into v9. [source:raw]
    // CALCULATION: Row 1 of a2 (elements a2[4..7], broadcast) multiplied by v5..v8 and summed into v10. [source:raw]
    // CALCULATION: Row 2 of a2 (elements a2[8..11], broadcast) multiplied by v5..v8 and summed into v11. [source:raw]
    // CALCULATION: Row 3 of a2 (elements a2[12..15]) combined the same way: partial sums v12, v13 plus the broadcast of a2[15] against v8, summed into v15. [source:raw]
    // ASSIGNMENT: Store the four result rows into the output matrix a1 using _mm_storel_ps / _mm_storeh_ps pairs at a1, a1+1 .. a1+7. [source:raw]
    // RETURN: Return the output pointer a1. [function:0x0052020E, source:raw]

    // Conservative worker pseudocode:
    //   double *F_4x4MatrixMultiply(double *out, const unsigned int *left, const double *right) {
    //     v5 = loadh(right + 1); v6 = loadh(right + 3); v7 = loadh(right + 5); v8 = loadh(right + 7);
    //     v9  = bcast(left[0])*v5 + bcast(left[1])*v6 + bcast(left[2])*v7 + bcast(left[3])*v8;
    //     v10 = bcast(left[4])*v5 + bcast(left[5])*v6 + bcast(left[6])*v7 + bcast(left[7])*v8;
    //     v11 = bcast(left[8])*v5 + bcast(left[9])*v6 + bcast(left[10])*v7 + bcast(left[11])*v8;
    //     v15 = bcast(left[12])*v5 + bcast(left[13])*v6 + bcast(left[14])*v7 + bcast(left[15])*v8;
    //     store out[0], out[1] from v9;  store out[2], out[3] from v10;
    //     store out[4], out[5] from v11; store out[6], out[7] from v15;
    //     return out;
    //   }
    // UNRESOLVED: Exact physical layout of inputs: a2 holds 16 dwords and a3 is read as doubles at byte offsets a3+1, a3+3, a3+5, a3+7 (two floats per _mm_loadh_ps), so the caller-side element packing of the two 4x4 matrices is not fully resolved.
    // UNRESOLVED: Whether output cells a1[] are the game's double-width storage of a float 4x4 product is inferred from the double* signature, not proven.
}
