// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00522B5B
// Canonical corpus name: F_3x3MatrixInverse3DNow
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3x3MatrixInverse3DNow_00522b5b.c

void UnknownObject::F_3x3MatrixInverse3DNow()
{
    // Computes the inverse of the 3x3 rotation submatrix read from the two packed-float rows of input a2 (a2[0], a2[1]) and writes it into the top-left 3x3 of the output __m64 buffer a1 using 3DNow! intrinsics (pfadd, pfmul, pfsub/pfsubr, pfacc, punpck). Uses the packed identity constants 0x3F8000003F800000 (1.0/1.0) and 1065353216 (1.0f). Sets a1[6] = 0 and a1[7] = {0, 1.0f} for the homogeneous last row. No conditional branches; always executes the full inverse computation and returns the output pointer.
    // CALCULATION: Load the two input packed rows a2[0] and a2[1], double their elements with pfadd (v4 = a2[0]+a2[0], second pfadd on a2[1]), and permute lanes with punpckhdq/punpckldq (v6, v7, v9) to prepare the cross-term computation of the inverse. [source:raw]
    // CALCULATION: Compute the pfmul products (v8, v10, v11, v12, v13) and the pfsub/pfadd cross terms (v14, v15, v18, v19, v20, v21) that form the 2x2 cofactor/minor products of the 3x3 inverse. [source:raw]
    // CALCULATION: Evaluate the identity-minus-accumulation terms with pfacc and pfsubr against the packed constant 0x3F8000003F800000 (1.0/1.0): v16 = 1.0 - (punpckldq(v11,v11) + v8) and the a1[5] scalar element = 1.0 - pfacc(v8,v8). [global:0x005AF900, source:raw]
    // ASSIGNMENT: Zero the homogeneous row 3 col 0-1: a1[6] = 0 (this+0x30). [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Write the inverse rotation rows: a1[0] (this+0x0) = punpckhdq(v16, punpckldq(v21,v21)), a1[1] (this+0x8) = punpckhdq(v20,0), a1[2] (this+0x10) = punpckldq(v20,v16), a1[3] (this+0x18) = punpckldq(v18,0). [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write the remaining inverse columns: a1[4] (this+0x20) = punpckldq(punpckhdq(v21,v21), v19), a1[5] (this+0x28) = punpckldq(pfsubr(pfacc(v8,v8), 0x3F8000003F800000), 0). [field:this:0x00000020, field:this:0x00000028, global:0x005AF900, source:raw]
    // ASSIGNMENT: Write the homogeneous last row a1[7] (this+0x38) = punpckldq(0, 1065353216), i.e. {0, 1.0f}. [field:this:0x00000038, global:0x005AF900, source:raw]
    // RETURN: Emit _m_femms() to exit MMX state and return the output matrix pointer a1. [function:0x00522B5B, source:raw]

    // Conservative worker pseudocode:
    //   __m64 *F_3x3MatrixInverse3DNow(__m64 *a1, __m64 *a2) {
    //     // read two packed input rows, double and permute lanes
    //     double_rows  = pfadd(a2[0], a2[0]);
    //     // cross-term products
    //     // v8..v13: pfmul of doubled/permuted rows
    //     // v14,v15,v20,v21: pfsub/pfadd cross terms
    //     // identity terms
    //     v16 = 1.0 - (punpckldq(v11,v11) + v8);
    //     a1[6] = 0;
    //     a1[0] = punpckhdq(v16, punpckldq(v21,v21));
    //     a1[1] = punpckhdq(v20, 0);
    //     a1[2] = punpckldq(v20, v16);
    //     a1[3] = punpckldq(v18, 0);
    //     a1[4] = punpckldq(punpckhdq(v21,v21), v19);
    //     a1[5] = punpckldq(1.0 - pfacc(v8,v8), 0);
    //     a1[7] = {0, 1.0f};          // homogeneous last row
    //     _m_femms();
    //     return a1;
    //   }
    // UNRESOLVED: The read-only global qword_5AF900 is flagged as read, but the raw decompiled source renders the constants inline (0x3F8000003F800000 and 1065353216); the exact global-to-constant mapping is not established.
    // UNRESOLVED: Whether this computes the true inverse or an adjugate/cofactor result without a final division is not established from the packet alone.
    // UNRESOLVED: The packed lane layout of the 3x3 inverse within the eight __m64 output slots is inferred from punpck order, not verified against a consumer.
    // UNRESOLVED: The owner object is unknown; the function has no static callers or callees.
}
