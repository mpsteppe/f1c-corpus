// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005257C0
// Canonical corpus name: F_4x4MatrixInversion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4x4MatrixInversion_005257c0.c

void UnknownObject::F_4x4MatrixInversion()
{
    // Inverts a 4x4 packed-float matrix using 3DNow! intrinsics. Reads all eight __m64 rows of input a3, builds the minor/cofactor cross products with pfmul/pfnacc/pswapd into stack staging v35..v42, accumulates the determinant term (pfacc of a pfnacc product), optionally stores the determinant as a 32-bit int through a2, computes its reciprocal with pfrcp and Newton-Raphson refinement (pfrcpit1/pfrcpit2) against the packed constant 0xBF8000003F800000 (-1.0f/1.0f), then scales the cofactors and writes the inverse into all eight output slots a1[0..7]. If the determinant is zero (pfcmpeq against 0), the store is skipped and a nonzero singular flag is returned; otherwise 0 is returned. Called by F_3DNowVectorTransform (00526b55).
    // CALCULATION: Read the input matrix rows a3[0..7] and build the minor/cofactor cross products with pfmul, pswapd and pfnacc (v6, v7, v8, v15, v16, v17), staging the cofactor results into the stack buffers v35..v42. [source:raw]
    // CALCULATION: Accumulate the determinant: v21 = pfnacc of products built from the staged cofactors, v22 = pfacc(v21, v21), so the summed scalar of v22 is the determinant of a3. [source:raw]
    // ASSIGNMENT: If a2 is non-null, store the determinant as a 32-bit int: *a2 = _mm_cvtsi64_si32(v22). [source:raw]
    // CALCULATION: Compute the reciprocal of the determinant with pfrcp and refine it via pfrcpit1/pfrcpit2, then multiply by the packed constant 0xBF8000003F800000 (-1.0f/1.0f) to produce the per-lane scale v25 and its lane-swapped copy v26. [global:0x005AF8F0, source:raw]
    // GUARD: Test the determinant against zero: result = _mm_cvtsi64_si32(_m_pfcmpeq(0, v22)); a nonzero result means the determinant was zero (singular) and the inverse store is skipped. [source:raw]
    // ASSIGNMENT: Non-singular path: scale each staged cofactor by the reciprocal (v25/v26) with pfmul and write the inverse matrix into all eight output slots a1[0] (this+0x0) through a1[7] (this+0x38) via punpckhdq/punpckldq row pairs. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // RETURN: Emit _m_femms() and return result (0 on success, nonzero when the determinant was zero). The produced inverse is consumed by the caller F_3DNowVectorTransform (0x00526B55). [caller:0x00526B55, function:0x005257C0, source:raw]

    // Conservative worker pseudocode:
    //   int F_4x4MatrixInversion(__m64 *a1, int *a2, __m64 *a3) {
    //     // build cofactor cross products from a3[0..7] into stack staging v35..v42
    //     v22 = pfacc(pfnacc(...));              // determinant of a3
    //     if (a2) *a2 = (int)v22;               // optional determinant output
    //     v25 = pfrcpit2(pfrcpit1(v22, pfrcp(v22)), pfrcp(v22)) * {-1.0f, 1.0f};
    //     if (pfcmpeq(0, v22) != 0) {
    //       // singular: no inverse written
    //       result = 1;
    //     } else {
    //       // scale cofactors by reciprocal and store all 8 output slots
    //       a1[0] = punpckhdq(v29, v27);  a1[1] = punpckhdq(v33, v31);
    //       a1[2] = punpckldq(v29, v27);  a1[3] = punpckldq(v33, v31);
    //       a1[4] = punpckhdq(v30, v28);  a1[5] = punpckhdq(v34, v32);
    //       a1[6] = punpckldq(v30, v28);  a1[7] = punpckldq(v34, v32);
    //       result = (int)a1;
    //     }
    //     _m_femms();
    //     return result;
    //   }
    // UNRESOLVED: The read-only global qword_5AF8F0 is flagged as read, but the raw decompiled source renders the constant inline (0xBF8000003F800000 = packed -1.0f/1.0f); the exact global-to-constant mapping is not established.
    // UNRESOLVED: The cluster prelabel (DERIVED) identifies this as a structural twin of sub_522B22 (identity-matrix builder, 00522b22), but the raw source performs a full determinant-based 4x4 inversion, so that twin claim is not supported by the evidence.
    // UNRESOLVED: The row/column-major layout of the inverse in the output slots is inferred from punpck lane order, not verified against a consumer.
    // UNRESOLVED: The exact sign handling of the returned singular flag and the a2 determinant encoding are inferred from the pfcmpeq/cvtsi64_si32 sequence.
    // UNRESOLVED: The owner object is unknown.
}
