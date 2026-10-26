// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052243A
// Canonical corpus name: F_4x4MatrixMultiply_243a
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixMultiply_243a_0052243a.c

void UnknownObject::F_4x4MatrixMultiply_243a()
{
    // 3DNow! 4x4 matrix multiply: computes a1 = a2 * a3. Transposes a3 into column-major __m64 halves via punpckldq/punpckhdq, then for each of the eight output __m64 slots a1[i] (offsets 0x00..0x38) accumulates the dot product of one a2 row-half against four a3 column-halves using pfmul/pfacc/pfadd. Pure register/vector math, no memory access, no guards, no callees.
    // STATE_TRANSITION: Emit _m_femms() at function entry and again before return to exit MMX/3DNow state. [source:raw]
    // CALCULATION: Transpose a3 into column-major halves: v20/v22 = punpckl/hdq(a3[0], a3[2]), v24/v26 = punpckl/hdq(a3[5], a3[7]), v8/v25 = punpckl/hdq(a3[1], a3[3]), v21/v23 = punpckl/hdq(a3[4], a3[6]). [source:raw]
    // LOOP: For each of the eight output slots a1[0..7], accumulate the dot product of one a2 row-half against the four a3 column-halves via _m_pfmul (pairwise multiply), _m_pfacc (pairwise accumulate) and _m_pfadd (pairwise add). [source:raw]
    // ASSIGNMENT: Write each accumulated 2-float result into the output matrix a1 across its eight __m64 slots at offsets 0x00, 0x08, 0x10, 0x18, 0x20, 0x28, 0x30, 0x38. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038]
    // RETURN: Return a1, the pointer to the resulting 4x4 matrix. [source:raw]

    // Conservative worker pseudocode:
    //   _m_femms();
    //   // column-major halves of a3
    //   v20=punpckldq(a3[0],a3[2]); v22=punpckhdq(a3[0],a3[2]);
    //   v24=punpckldq(a3[5],a3[7]); v26=punpckhdq(a3[5],a3[7]);
    //   v8 =punpckldq(a3[1],a3[3]); v25=punpckhdq(a3[1],a3[3]);
    //   v21=punpckldq(a3[4],a3[6]); v23=punpckhdq(a3[4],a3[6]);
    //   // eight 2-float dot products: each a1[i] = a2 row-half . a3 column-halves
    //   a1[0] = pfadd(pfacc(pfmul(a2[0],v20),pfmul(a2[0],v22)), pfacc(pfmul(a2[1],v21),pfmul(a2[1],v23)));
    //   a1[1] = pfadd(pfacc(pfmul(a2[0],v8 ),pfmul(a2[0],v25)), pfacc(pfmul(a2[1],v24),pfmul(a2[1],v26)));
    //   a1[2] = pfadd(pfacc(pfmul(a2[2],v20),pfmul(a2[2],v22)), pfacc(pfmul(a2[3],v21),pfmul(a2[3],v23)));
    //   a1[3] = pfadd(pfacc(pfmul(a2[2],v8 ),pfmul(a2[2],v25)), pfacc(pfmul(a2[3],v24),pfmul(a2[3],v26)));
    //   a1[4] = pfadd(pfacc(pfmul(a2[4],v20),pfmul(a2[4],v22)), pfacc(pfmul(a2[5],v21),pfmul(a2[5],v23)));
    //   a1[5] = pfadd(pfacc(pfmul(a2[4],v8 ),pfmul(a2[4],v25)), pfacc(pfmul(a2[5],v24),pfmul(a2[5],v26)));
    //   a1[6] = pfadd(pfacc(pfmul(a2[6],v20),pfmul(a2[6],v22)), pfacc(pfmul(a2[7],v21),pfmul(a2[7],v23)));
    //   a1[7] = pfadd(pfacc(pfmul(a2[6],v8 ),pfmul(a2[6],v25)), pfacc(pfmul(a2[7],v24),pfmul(a2[7],v26)));
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: No static callers or callees are evidenced; the calling context that supplies the two 4x4 matrices is unknown
    // UNRESOLVED: The owner type of the matrix object (this/a1) is unknown; only its eight __m64 slots at offsets 0x00..0x38 are evidenced
    // UNRESOLVED: a3's row-major layout is assumed from the punpck transpose pattern; not independently verified
}
