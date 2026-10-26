// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00520F69
// Canonical corpus name: sub_520F69
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_520F69_00520f69.c

void UnknownObject::PackedVectorNormalize3DNow()
{
    // Straight-line 3DNow! packed-vector normalization with a zero-length guard. Computes the squared length of the packed input a2 as the pfacc of the component products, compares it against the tiny threshold literal 0x80000000800000LL with pfcmpgt, computes a reciprocal square root with pfrsqrt and refines it with one Newton-Raphson iteration (pfrsqit1/pfrcpit2), masks the components by the comparison result with pand, scales by the refined reciprocal, stores the normalized vector to a1, and exits the MMX state with _m_femms.
    // ASSIGNMENT: Read the two packed halves of input a2: first half a2->m64_u64 and second half v2 (a2[1]). [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALCULATION: Compute the sum of the squared components v3 (pfmul(a2->m64_u64, a2->m64_u64) + pfmul(v2, v2)) and horizontally accumulate it with pfacc into the length-squared value v5. [source:raw]
    // GUARD: Compare the length-squared v5 against the threshold literal 0x80000000800000LL with pfcmpgt into v7; near-zero inputs fail the comparison, so their pand mask zeroes the output and the division by a near-zero length is avoided. [source:raw]
    // CALCULATION: Compute the reciprocal square root of v5 with pfrsqrt into v6 and refine it with one Newton-Raphson iteration pfrsqit1/pfrcpit2 into v8. [source:raw]
    // ASSIGNMENT: Mask each input half with the comparison result v7 via pand and scale by the refined reciprocal v8, storing the result to a1->m64_u64 and a1[1].m64_u64. [field:this:0x00000000, field:this:0x00000008, source:raw]
    // CALL: Exit the MMX/3DNow! execution state with _m_femms. [source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   __m64 *PackedVectorNormalize3DNow(__m64 *out, const __m64 *v) {
    //     __m64 lo = v[0], hi = v[1];
    //     __m64 len2 = pfacc(pfadd(pfmul(lo, lo), pfmul(hi, hi)));
    //     __m64 ok = pfcmpgt(len2, 0x80000000800000LL);
    //     __m64 inv = pfrcpit2(pfrsqit1(len2, pfmul(pfrsqrt(len2), pfrsqrt(len2))), pfrsqrt(len2));
    //     out[0] = pfmul(pand(lo, ok), inv);
    //     out[1] = pfmul(pand(hi, ok), inv);
    //     _m_femms();
    //     return out;
    //   }
    // UNRESOLVED: qword_5AF970 appears in the packet globals but is absent from the raw decompiled text; the existing-analysis suggestion that it holds the length-squared threshold is DERIVED and unproven.
    // UNRESOLVED: The exact bit pattern of the threshold literal 0x80000000800000LL (interpreted as a tiny positive float threshold) is not explained by the packet.
    // UNRESOLVED: Whether the packed vector represents a 2D or a 4D quantity (treated as two independent pairs) is not determined by this function alone.
}
