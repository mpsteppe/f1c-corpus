// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005207CE
// Canonical corpus name: SSEVectorCross
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEVectorCross_005207ce.c

void UnknownObject::SSEVectorCross()
{
    // Computes the 3D cross product of two vectors loaded from a2 and a3 (with a3 also used as the sign/lane context) via SSE load/shuffle/multiply/subtract/add sequences, applies the XOR sign mask xmmword_5D8C20, and stores the result __m128 in the output at a1. An SSE math-library utility; the fourth argument a4 participates in the lane shuffle feeding the component products.
    // CALCULATION: Load vector component lanes from a3, a2, and a4 via _mm_loadh_ps and prepare shuffled variants (shuffle masks 57 and 78) used to align components for the cross-product multiply/subtract terms. [source:raw, function:0x005207CE]
    // CALCULATION: Build the three cross-product component terms by multiplying shuffled lane groups and subtracting crossed terms (_mm_mul_ps with _mm_sub_ps of shuffled operands), then summing them with _mm_add_ps. [source:raw, function:0x005207CE]
    // ASSIGNMENT: XOR the summed result with the sign mask xmmword_5D8C20 (right-hand-rule sign flip) and store the final __m128 into the output field this+0x0. [source:raw, global:0x005D8C20, field:this:0x00000000]
    // RETURN: Return the pointer to the output __m128 at a1. [source:raw, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   a = vec_from(a2);
    //   b = vec_from(a3);
    //   c = vec_from(a4);
    //   out = cross_terms(a, b, c) ^ kSignMask;
    //   return out;
    // UNRESOLVED: The exact operand ordering that determines sign convention of the cross product (right-hand rule) is stated by existing analysis but not independently verified from the mask bytes of xmmword_5D8C20.
    // UNRESOLVED: No static callers, so the argument roles of a2/a3/a4 versus a1 cannot be cross-checked beyond the raw instruction stream.
}
