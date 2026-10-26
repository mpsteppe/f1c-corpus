// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00521712
// Canonical corpus name: MMX3DNowVectorTransform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MMX3DNowVectorTransform_00521712.c

void UnknownObject::MMX3DNowVectorTransform()
{
    // 3DNow vector transformation helper. Adds the two scalar inputs a5 and a6 into v11, then normalizes a3 and a4 relative to base vector a2 using v11 as the factor, producing two intermediate vectors v9 and v10. Finally normalizes v9 relative to v10 using a scale factor of a6 times the reciprocal of v11 and stores the result in a1, which is also returned.
    // STATE_TRANSITION: Emit _m_femms() before and after the MMX/3DNow arithmetic to exit the MMX state. [source:raw]
    // CALCULATION: Compute v11 as the packed float add of the scalar arguments a5 and a6, truncated back to a scalar via the low lane. [source:raw]
    // CALL: Call SIMDVectorNormalization(v9, a2, a3, v11) to normalize a3 relative to a2 with factor v11 into the local buffer v9. [callee:0x005215DB, source:raw]
    // CALL: Call SIMDVectorNormalization(v10, a2, a4, v11) to normalize a4 relative to a2 with factor v11 into the local buffer v10. [callee:0x005215DB, source:raw]
    // CALCULATION: Build a refined reciprocal approximation of v11 via the pfrcp, pfrcpit1, pfrcpit2 sequence. [source:raw]
    // CALL: Call SIMDVectorNormalization(a1, v9, v10, scale) where scale is a6 multiplied by the reciprocal of v11, normalizing v9 relative to v10 into the output a1. [callee:0x005215DB, source:raw]
    // RETURN: Return the output pointer a1. [function:0x00521712, source:raw]

    // Conservative worker pseudocode:
    //   __m64 *MMX3DNowVectorTransform(__m64 *out, __m64 *base, __m64 *v1, __m64 *v2, unsigned int s1, unsigned int s2) {
    //     _m_femms();
    //     float v11 = (float)(s1) + (float)(s2);
    //     __m64 tmp1[2], tmp2[2];
    //     SIMDVectorNormalization(tmp1, base, v1, v11);
    //     SIMDVectorNormalization(tmp2, base, v2, v11);
    //     float scale = (float)(s2) / v11;
    //     SIMDVectorNormalization(out, tmp1, tmp2, scale);
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Semantic meaning of the three normalized vectors (base, v1, v2) is caller-defined; the function composes two normalization steps into one output.
    // UNRESOLVED: a2, a3, a4 are untyped __m64 buffers; their element counts and layout are not evidenced here.
}
