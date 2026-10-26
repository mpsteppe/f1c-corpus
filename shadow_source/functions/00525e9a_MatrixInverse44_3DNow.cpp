// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00525E9A
// Canonical corpus name: sub_525E9A
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_525E9A_00525e9a.c

void UnknownObject::MatrixInverse44_3DNow()
{
    // 3DNow!-optimized 4x4 matrix operator. Reads an input matrix a3 as eight packed-float qwords (16 floats) and builds intermediate cofactor/row terms with 3DNow! multiply/subtract/add instructions, accumulating a scalar whose low 32 bits are exposed through a2 when a2 is non-null. When that scalar is non-zero, the cofactor terms are scaled by its reciprocal (pfrcp plus two-step refinement, sign-adjusted by the packed constant 0xBF8000003F800000) and written into the output matrix a1[0..7]. When the scalar is zero the output is left unmodified and -1 is returned. Called by F_3DNow44MatrixMultiplyWrapper and MatrixInterpolationBlend; structural twin of sub_522B22 per the cluster_copy prelabel.
    // CALCULATION: Load the input matrix a3 as eight packed-float qwords (a3[0..7], 16 floats) and compute intermediate cofactor/row terms (v5..v29, v44..v50) using 3DNow! mul/sub/add/pack sequences. [source:raw, abi:lead]
    // CALCULATION: Combine the packed terms into scalar v30 and horizontal-accumulate with _m_pfacc into v31; this scalar doubles as the divisor/scale term used by the inverse path. [source:raw]
    // ASSIGNMENT: When a2 is non-null, write the low 32 bits of the accumulated scalar v31 into *a2 (_mm_cvtsi64_si32 on v31). [source:raw]
    // GUARD: Compute a zero-compare of v31 (_m_pfcmpeq(0, v31)); when the result is non-zero (v31 == 0, degenerate matrix) skip the inversion block and return immediately. [source:raw]
    // CALCULATION: Compute a reciprocal approximation of v31 with _m_pfrcp and refine it via _m_pfrcpit1/_m_pfrcpit2, applying the packed sign constant 0xBF8000003F800000 (-1.0/+1.0) to the product. [source:raw]
    // ASSIGNMENT: Write the scaled result into output matrix a1[0..7] as eight qwords at byte offsets 0x0 (RW), 0x8, 0x10, 0x18, 0x20, 0x28, 0x30 and 0x38, each formed by packing the scaled row/column terms. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, field:this:0x00000018, field:this:0x00000020, field:this:0x00000028, field:this:0x00000030, field:this:0x00000038, source:raw]
    // RETURN: Return 0 when the scalar is non-zero (invertible path executed), or -1 when the scalar is zero (degenerate; output matrix left untouched). [source:raw]
    // CALL: Called by F_3DNow44MatrixMultiplyWrapper (0x005261CE) and MatrixInterpolationBlend (0x0052692F) as a 3DNow! 4x4 matrix operator; identified as a structural twin of sub_522B22 by the cluster_copy prelabel. [caller:0x005261CE, caller:0x0052692F, function:0x00525E9A, source:raw]

    // Conservative worker pseudocode:
    //   // 3DNow! 4x4 matrix scale/inverse; a3 in, a1 out, a2 optional scalar out.
    //   int sub_525E9A(__m64* a1, _DWORD* a2, __m64* a3) {
    //     __m64 scalar = accumulate_cofactor_terms(a3);
    //     if (a2) *a2 = low32(scalar);
    //     int degenerate = pfcmpeq(0, scalar);
    //     if (!degenerate) {
    //       __m64 recip = refine(pfrcp(scalar), sign_constant);
    //       for (i = 0; i < 8; ++i) a1[i] = pack_row(scale_terms(i, recip));
    //     }
    //     return degenerate ? -1 : 0;
    //   }
    // UNRESOLVED: Read-only global qword_5AF8F0 is present in the deterministic facts but not visible in the raw decompiled body; likely a 3DNow! constant operand or a reference the decompiler collapsed.
    // UNRESOLVED: The exact mathematical role of the scalar written to a2 (determinant vs. independent scale factor) is not provable from the raw body alone.
    // UNRESOLVED: Field R/W classification (0x0 RW, 0x8..0x38 R) does not match the unconditional writes to all eight output qwords; the discrepancy is kept as-is.
}
