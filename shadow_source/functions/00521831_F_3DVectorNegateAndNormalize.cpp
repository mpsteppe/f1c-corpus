// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00521831
// Canonical corpus name: F_3DVectorNegateAndNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_3DVectorNegateAndNormalize_00521831.c

void UnknownObject::F_3DVectorNegateAndNormalize()
{
    // 3DNow! vector math helper: negates the packed float vector a2 and scales it by the reciprocal of its squared length. Squared length is computed with pfadd/pfmul and lane accumulation (pfacc), inverted with pfrcp plus a Newton-Raphson refinement (pfrcpit1/pfrcpit2), then gated by a threshold comparison (pfcmpgt against the 0x80000000800000 packed constant held in qword_5AF970) so near-zero vectors yield a zeroed output. Output is written to a1 and a1 is returned. Ends with _m_femms() to leave the MMX state.
    // CALCULATION: Load the second packed pair a2[1] (z, w components) into v2. [source:raw, function:0x00521831]
    // CALCULATION: Compute v3 = (x*x + z*z, y*y + w*w) via packed multiply of each input pair with itself followed by packed add. [source:raw, function:0x00521831]
    // CALCULATION: Accumulate the two lanes of v3 with pfacc into v4, the squared vector length, replicated into both lanes. [source:raw, function:0x00521831]
    // CALCULATION: v6 = pfrcp(v4): approximate reciprocal of the squared length. [source:raw, function:0x00521831]
    // GUARD: Guard: v7 = pfcmpgt(v4, 0x80000000800000) compares each lane of the squared length against the packed threshold constant 0x80000000800000 held in qword_5AF970. When the squared length is not greater than the threshold, v7 is all-zero and the subsequent AND masks the output to zero, avoiding a division by a near-zero length. [source:raw, global:0x005AF970, function:0x00521831]
    // CALCULATION: Refine the reciprocal with a Newton-Raphson step: v8 = pfrcpit2(pfrcpit1(v4, v6), v6). [source:raw, function:0x00521831]
    // ASSIGNMENT: Write the x/y output pair: a1->m64_u64 = (x, y) with sign bits flipped by XOR with the 0x8000000080000000 packed constant held in qword_5AF918, AND-masked by v7, then multiplied by the refined reciprocal v8. [source:raw, field:this:0x00000000, global:0x005AF918, function:0x00521831]
    // ASSIGNMENT: Write the z/w output pair: a1[1].m64_u64 = v2 with the low-lane sign bit flipped by XOR with 0x80000000 (held in qword_5AF9D0; the w lane is left untouched), AND-masked by v7, then multiplied by the refined reciprocal v8. [source:raw, field:this:0x00000008, global:0x005AF9D0, function:0x00521831]
    // CALL: _m_femms(): clear the MMX/3DNow! state after the packed-float operations. [source:raw, function:0x00521831]
    // RETURN: Return a1, a pointer to the written output vector. [source:raw, function:0x00521831]

    // Conservative worker pseudocode:
    //   __m64* sub_521831(__m64* out, __m64* in) {
    //     __m64 zw = in[1];
    //     __m64 sq = _m_pfadd(_m_pfmul(in[0], in[0]), _m_pfmul(zw, zw));
    //     __m64 lenSq = _m_pfacc(sq, sq);
    //     __m64 rc = _m_pfrcp(lenSq);
    //     __m64 mask = _m_pfcmpgt(lenSq, (__m64)0x80000000800000LL);
    //     __m64 rcRefined = _m_pfrcpit2(_m_pfrcpit1(lenSq, rc), rc);
    //     out[0] = _m_pfmul(_m_pand(_m_pxor(in[0], (__m64)0x8000000080000000uLL), mask), rcRefined);
    //     out[1] = _m_pfmul(_m_pand(_m_pxor(zw, (__m64)0x80000000LL), mask), rcRefined);
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: Whether the reciprocal-squared-length scale is a true normalize (1/sqrt(len^2)) or a distinct negate-and-scale-by-inverse-len^2 helper; the raw source divides by the squared length directly.
    // UNRESOLVED: The w lane of the input pair a2[1] is never sign-flipped or otherwise used; whether it is meaningful for this helper is unclear.
    // UNRESOLVED: When the squared length is not above the 0x80000000800000 threshold the output is zeroed; the caller's intended handling of near-zero vectors is unknown.
    // UNRESOLVED: Owner object is unassigned (UnknownObject/UNKNOWN); the math library or math subsystem this helper belongs to is not identified.
}
