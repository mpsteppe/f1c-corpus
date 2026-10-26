// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00526FEB
// Canonical corpus name: sub_526FEB
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_526FEB_00526feb.c

void UnknownObject::Normalize4DVector3DNow()
{
    // Normalizes a 4-component vector (two packed 3DNow! float pairs a2[0], a2[1]) into the output buffer a1. Computes the packed squared length via pfmul/pfadd then pfacc, takes a reciprocal square root (pfrsqrt), guards against degenerate/near-zero length with pfcmpgt against the threshold constant qword_5AF970 (0x80000000800000), refines the reciprocal root with a Newton-Raphson step (pfrsqit1 + pfrcpit2), and writes the masked input components multiplied by the refined reciprocal root to a1[0] and a1[1]. Clears MMX/3DNow state with _m_femms at entry and exit and returns a1. Structural twin of sub_520F69 per the packet prelabel (cluster_copy, DERIVED).
    // CALL: Clear MMX/3DNow state via _m_femms before the arithmetic sequence. [source:raw]
    // CALCULATION: Load the second packed component pair v2 = a2[1]. [field:this:0x00000008, source:raw]
    // CALCULATION: Compute the per-lane squared length v3 = pfadd(pfmul(a2[0], a2[0]), pfmul(v2, v2)). [field:this:0x00000000, source:raw]
    // CALCULATION: Horizontally accumulate both lanes with pfacc to produce the packed squared length v4. [source:raw]
    // CALCULATION: Take the packed reciprocal square root v6 = pfrsqrt(v4). [source:raw]
    // GUARD: Compare the squared length v4 against the near-zero threshold 0x80000000800000 (held by global qword_5AF970) with pfcmpgt; the mask v7 is non-zero only where the length exceeds the threshold, so degenerate vectors are nulled. [global:0x005AF970, source:raw]
    // CALCULATION: Refine the reciprocal square root with a Newton-Raphson step v8 = pfrcpit2(pfrsqit1(v4, pfmul(v6, v6)), v6). [source:raw]
    // ASSIGNMENT: Write the normalized first component pair a1[0] = pfmul(pand(a2[0], v7), v8): input masked by the length guard times the refined reciprocal root. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the normalized second component pair a1[1] = pfmul(pand(v2, v7), v8): input masked by the length guard times the refined reciprocal root. [field:this:0x00000008, source:raw]
    // CALL: Clear MMX/3DNow state via _m_femms after the arithmetic sequence. [source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x00526FEB, source:raw]

    // Conservative worker pseudocode:
    //   femms();
    //   __m64 v2 = a2[1];
    //   __m64 v3 = a2[0]*a2[0] + v2*v2;            // per-lane squares
    //   __m64 v4 = pfacc(v3, v3);                   // packed squared length
    //   __m64 v6 = pfrsqrt(v4);
    //   __m64 v7 = pfcmpgt(v4, threshold_5AF970);   // 0x80000000800000 guard
    //   __m64 v8 = refine_rsqrt(v4, v6);            // Newton-Raphson step
    //   a1[0] = (a2[0] & v7) * v8;
    //   a1[1] = (v2 & v7) * v8;
    //   femms();
    //   return a1;
    // UNRESOLVED: The binding of the immediate threshold 0x80000000800000 to global qword_5AF970 follows the naming used by sibling normalize functions (e.g. sub_527578) and is DERIVED, not stated in the raw source.
    // UNRESOLVED: The split of the four packed components into (x,y) and (z,w) is not recoverable from this function alone.
    // UNRESOLVED: Owner is UNKNOWN; the packet carries no owner evidence and no static callers.
}
