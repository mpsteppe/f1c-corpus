// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005262C2
// Canonical corpus name: sub_5262C2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5262C2_005262c2.c

void UnknownObject::Vector2D3DNowNormalize()
{
    // MMX/3DNow! 2-component vector normalizer. Reads a packed pair at a2, squares both lanes, horizontally adds them (pfacc) into both lanes to form the squared magnitude, computes a reciprocal square-root estimate (pfrsqrt), guards against a near-zero magnitude with a packed compare against the constant 0x80000000800000, refines the estimate with one Newton-Raphson step (pfrsqit1/pfrcpit2), and writes the masked normalized pair to a1. Exits MMX state with _m_femms() on entry and before returning a1. The packet's structural-twin prelabel identifies sub_520F69 (00520f69) as an equivalent routine, and the LEGACY ABI lead labels the logic SIMD/3DNow vector normalization; both callers (Media3DNowMathOperation, SIMDQuaternionRotationArithmetic) use it to normalize a packed pair in place.
    // CALL: Execute _m_femms() on entry to leave MMX state and restore x87-style FPU operation. [source:raw]
    // ASSIGNMENT: Load the second component: v2 = cvtsi32_si64(a2[1].m64_u32[0]) from the high pair slot at this+0x8. [field:this:0x00000008, source:raw]
    // CALCULATION: Square both components packed: v3 = pfadd(pfmul(a2->m64_u64, a2->m64_u64), pfmul(v2, v2)) reading the low pair slot at this+0x0. [field:this:0x00000000, source:raw]
    // CALCULATION: Horizontal add: v4 = pfacc(v3, v3) so both lanes hold the squared magnitude (x*x + y*y). [source:raw]
    // CALCULATION: Reciprocal square-root estimate v5 = pfrsqrt(v4) (3DNow! approximate 1/sqrt). [source:raw]
    // CALCULATION: Zero-guard compare: v6 = pfcmpgt(v4, 0x80000000800000) masks lanes whose squared magnitude is at or below the threshold (near-zero vector); qword_5AF970 is flagged read by the packet and is presumed to hold this comparison constant (rendered inline by Hex-Rays), but that mapping is not directly evidenced. [global:0x005AF970, source:raw]
    // CALCULATION: Newton-Raphson refinement of the reciprocal square root: v8 = pfrcpit2(pfrsqit1(v4, pfmul(v5, v5)), v5). [source:raw]
    // ASSIGNMENT: Write the normalized low lane: a1->m64_u64 = pfmul(pand(a2->m64_u64, v6), v8) (input masked by the zero-guard, scaled by the refined 1/sqrt). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the normalized high lane: a1[1].m64_i32[0] = cvtsi64_si32(pfmul(pand(v2, v6), v8)) into the output pair slot at this+0x8. [field:this:0x00000008, source:raw]
    // RETURN: Execute _m_femms() and return the output pointer a1. [function:0x005262C2, source:raw]

    // Conservative worker pseudocode:
    //   // MMX/3DNow! normalize of a 2-component packed pair. a1 = output, a2 = input.
    //   _m_femms();
    //   y = cvtsi32_si64(a2[1].m64_u32[0]);      // second component
    //   s = pfadd(pfmul(a2->m64_u64, a2->m64_u64), pfmul(y, y)); // (x*x, y*y)
    //   s = pfacc(s, s);                          // both lanes = x*x + y*y
    //   r = pfrsqrt(s);                           // 1/sqrt(len2) estimate
    //   active = pfcmpgt(s, 0x80000000800000);    // zero/near-zero guard
    //   r = pfrcpit2(pfrsqit1(s, pfmul(r, r)), r); // Newton refinement
    //   a1->m64_u64      = pfmul(pand(a2->m64_u64, active), r);  // normalized x
    //   a1[1].m64_i32[0] = cvtsi64_si32(pfmul(pand(y, active), r)); // normalized y
    //   _m_femms();
    //   return a1;
    // UNRESOLVED: qword_5AF970 is flagged as read by the packet but does not appear by name in the raw decompiled source; it is presumed to hold the 0x80000000800000 comparison constant (inlined by Hex-Rays), but the exact global-to-constant mapping is not established.
    // UNRESOLVED: Packet field base 'this' conflates the two distinct pointers (a1 output pair, a2 input pair); the field-to-parameter assignment (this+0x0 = pair slot, this+0x8 = second slot) is DERIVED from the raw source indexing, not proven by the fact table alone.
    // UNRESOLVED: The two callers (Media3DNowMathOperation at 0x0052156F, SIMDQuaternionRotationArithmetic at 0x00524553) invoke this as a packed-pair normalizer; their exact argument layouts and use of the result are established only by their own packets.
}
