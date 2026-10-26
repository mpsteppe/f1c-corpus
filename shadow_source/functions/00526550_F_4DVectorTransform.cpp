// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526550
// Canonical corpus name: F_4DVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_4DVectorTransform_00526550.c

void UnknownObject::F_4DVectorTransform()
{
    // 3DNow! 4D vector transform helper (__stdcall). Reads a 4-component input vector a2 (two __m64 words), pairs the components via punpckldq/punpckhdq, accumulates SIMD products against the coefficient table a3[0..7] (pfmul/pfadd), divides through the w component using a refined 3DNow reciprocal (pfrcp/pfrcpit1/pfrcpit2), writes the transformed result into a1 (a1[0] as a full __m64 product, a1[1].m64_i32[0] as a truncated 32-bit value) and returns a1. Emits _m_femms() at entry and exit.
    // CALL: Emit the 3DNow state transition _m_femms() at entry and again before returning. [source:raw]
    // ASSIGNMENT: Load the input vector: m64_u64 = a2[0] and v5 = a2[1].m64_u32[0], the two words of the 4D input vector. [field:this:0x00000008, source:raw]
    // CALCULATION: Duplicate vector components into paired words with punpckldq/punpckhdq, building v4, v6 and v7 for the subsequent SIMD multiply-accumulates. [source:raw]
    // CALCULATION: Accumulate v8 = a3[2]*v6 + a3[4]*v7 via pfmul/pfadd. [source:raw]
    // CALCULATION: Accumulate v9 = a3[1]*v4 + a3[7] + a3[3]*v6 + a3[5]*v7 via nested pfmul/pfadd. [source:raw]
    // CALCULATION: Compute the reciprocal of v9's paired component with the 3DNow refinement sequence pfrcp, pfrcpit1, pfrcpit2 into v12. [source:raw]
    // ASSIGNMENT: Write the transformed result: a1[0] = (a3[0]*v4 + a3[6] + v8) * v12 as a full __m64, and a1[1].m64_i32[0] = (v9 * v12) truncated to a 32-bit integer. [field:this:0x00000000, source:raw]
    // RETURN: Restore x87/MMX state with _m_femms() and return the output pointer a1. [source:raw]
    // CALL: Invoked by QuaternionTransformComposition (0x005267A7), MatrixInterpolationBlend (0x0052692F) and F_3DNowVectorTransform (0x00526B55) to apply a 3DNow 4D vector transform. [caller:0x005267A7, caller:0x0052692F, caller:0x00526B55, source:raw]

    // Conservative worker pseudocode:
    //   m64 *F_4DVectorTransform(m64 *out, m64 *in, m64 *coeff) {
    //     _m_femms();
    //     m64 m = in[0];
    //     m64 v4 = _m_punpckldq(m, m);
    //     m64 v5 = _mm_cvtsi32_si64(in[1].m64_u32[0]);
    //     m64 v6 = _m_punpckhdq(m, m);
    //     m64 v7 = _m_punpckldq(v5, v5);
    //     m64 v8 = _m_pfadd(_m_pfmul(v6, coeff[2]), _m_pfmul(v7, coeff[4]));
    //     m64 v9 = _m_pfadd(_m_pfadd(_m_pfmul(v4, coeff[1]), coeff[7]),
    //                       _m_pfadd(_m_pfmul(v6, coeff[3]), _m_pfmul(v7, coeff[5])));
    //     m64 w = _m_punpckhdq(v9, v9);
    //     m64 r = _m_pfrcp(w);
    //     m64 r2 = _m_pfrcpit2(_m_pfrcpit1(w, r), r);
    //     out[0] = _m_pfmul(_m_pfadd(_m_pfadd(_m_pfmul(v4, coeff[0]), coeff[6]), v8), r2);
    //     out[1].m64_i32[0] = _mm_cvtsi64_si32(_m_pfmul(v9, r2));
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Precise meaning of the a3 coefficient layout (a3[0..7]) and which components of a2 map to x/y/z/w is unverified; a3 is the transform coefficient table.
    // UNRESOLVED: The a1[1].m64_i32[0] 32-bit truncation suggests a fixed-point or screen-space result, but the interpretation is unconfirmed.
    // UNRESOLVED: Derived-offset names (e.g. 420, 24) belong to a different function and are not present here; no such evidence exists in this packet.
}
