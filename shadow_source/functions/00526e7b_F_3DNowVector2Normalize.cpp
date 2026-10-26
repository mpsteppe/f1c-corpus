// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526E7B
// Canonical corpus name: sub_526E7B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526E7B_00526e7b.c

void UnknownObject::F_3DNowVector2Normalize()
{
    // 3DNow! 2-component vector normalize (__stdcall). Squares the input packed pair a2[0] lane-wise (pfmul), horizontally accumulates the two lanes with pfacc to produce the packed squared length, takes a packed reciprocal square root with pfrsqrt, refines it with a Newton-Raphson step (pfrsqit1 + pfrcpit2), masks the input against a near-zero guard produced by pfcmpgt against the threshold constant qword_5AF970 (0x80000000800000), and stores a1[0] = pfmul(pand(input, mask), refined_rsqrt) so degenerate/zero-length vectors are nulled. Emits _m_femms() before return and returns a1. Existing analysis (skeletons_filled/sub_526E7B_00526e7b.md) names it F_3DNowVector2Normalize; the threshold global binding follows that same analysis (DERIVED).
    // CALCULATION: Compute the per-lane square v2 = pfmul(a2[0], a2[0]). [field:this:0x00000000, source:raw]
    // CALCULATION: Horizontally accumulate both lanes v4 = pfacc(v2, v2), giving the packed squared length of the 2-component vector. [source:raw]
    // CALCULATION: Take the packed reciprocal square root v5 = pfrsqrt(v4). [source:raw]
    // GUARD: Build the degenerate-length mask with pfcmpgt(v4, 0x80000000800000): lanes where the squared length exceeds the near-zero threshold keep the input; smaller/zero lengths are masked out. The threshold constant is bound to global qword_5AF970 per the sibling normalize analysis (sub_527578). [global:0x005AF970, source:raw]
    // CALCULATION: Refine the reciprocal square root with a Newton-Raphson step: pfrcpit2(pfrsqit1(pfmul(v5, v5), v4), v5). [source:raw]
    // ASSIGNMENT: Store the normalized vector: a1[0] = pfmul(pand(a2[0], mask), refined_rsqrt), i.e. input masked by the length guard times the refined reciprocal root. [field:this:0x00000000, source:raw]
    // STATE_TRANSITION: Emit _m_femms() to exit MMX/3DNow state before returning. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x00526E7B, source:raw]

    // Conservative worker pseudocode:
    //   __m64* F_3DNowVector2Normalize(__m64* a1 /*out* /, __m64* a2 /*in: 2 floats* /) {
    //     __m64 v2 = _m_pfmul(a2[0], a2[0]);
    //     __m64 v4 = _m_pfacc(v2, v2);
    //     __m64 v5 = _m_pfrsqrt(v4);
    //     __m64 mask = _m_pfcmpgt(v4, qword_5AF970 /* 0x80000000800000 * /);
    //     __m64 refined = _m_pfrcpit2(_m_pfrsqit1(_m_pfmul(v5, v5), v4), v5);
    //     a1[0] = _m_pfmul(_m_pand(a2[0], mask), refined);
    //     _m_femms();
    //     return a1;
    //   }
    // UNRESOLVED: The binding of the inline threshold literal 0x80000000800000 to global qword_5AF970 is inherited from the existing analysis (DERIVED), not stated in the raw source.
    // UNRESOLVED: The packed lane order of the two components (x,y) within a2[0] is not recoverable from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers/callees.
}
