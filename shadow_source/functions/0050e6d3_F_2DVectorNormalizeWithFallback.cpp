// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E6D3
// Canonical corpus name: F_2DVectorNormalizeWithFallback
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DVectorNormalizeWithFallback_0050e6d3.c

void UnknownObject::F_2DVectorNormalizeWithFallback()
{
    // Normalizes a 2D vector a2 to unit length, writing the result to a1. If the squared length is already approximately 1.0 (per FloatRangeCheck), the vector is copied verbatim. Otherwise, if the squared length exceeds the FLT_MIN threshold, each component is scaled by 1/sqrt(sq_len). If the squared length is at or below the degenerate threshold, both output components are zeroed. Returns the output pointer a1.
    // CALCULATION: Compute squared length of input vector: sq_len = in[0]*in[0] + in[1]*in[1], reading the X and Y components at this+0x0 and this+0x4. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // CALL: Call FloatRangeCheck(sq_len, 1.0) to test whether the vector is already approximately unit length. [callee:0x0050C042, source:raw]
    // GUARD: If FloatRangeCheck(sq_len, 1.0) returns true (already unit length), take the verbatim copy path. [callee:0x0050C042, source:raw]
    // ASSIGNMENT: Copy the X component of the source vector into out[0] (this+0x0). [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Copy the Y component of the source vector into out[1] (this+0x4). [field:this:0x00000004, source:raw]
    // GUARD: If sq_len is greater than the FLT_MIN threshold (1.1754944e-38, the float constant backed by global flt_59E43C), take the true normalization path. [global:0x0059E43C, source:raw]
    // CALCULATION: Compute the reciprocal length factor: v5 = 1.0 / sqrt(sq_len). [source:raw]
    // CALCULATION: Scale each input component by the reciprocal length factor, producing normalized X (v7) and normalized Y (v6) from this+0x0 and this+0x4. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write the normalized X and Y components into out[0] and out[1] (this+0x0 and this+0x4). [field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Degenerate fallback: when sq_len does not exceed the FLT_MIN threshold, write 0.0 into both out[0] and out[1] (this+0x0 and this+0x4). [field:this:0x00000000, field:this:0x00000004, source:raw]
    // RETURN: Return the output pointer a1 in all paths. [function:0x0050E6D3, source:raw]

    // Conservative worker pseudocode:
    //   float *normalize_2d(float *out, float *in) {
    //       float sq_len = in[0] * in[0] + in[1] * in[1];
    //       if (FloatRangeCheck(sq_len, 1.0f)) {
    //           out[0] = in[0];
    //           out[1] = in[1];
    //       } else if (sq_len > FLT_MIN) {
    //           float inv = 1.0f / sqrt(sq_len);
    //           out[0] = in[0] * inv;
    //           out[1] = in[1] * inv;
    //       } else {
    //           out[0] = 0.0f;
    //           out[1] = 0.0f;
    //       }
    //       return out;
    //   }
    // UNRESOLVED: Decompiler aliases the source pointer between parameters a2 and an uninitialized register variable v2 (ecx); evidence is consistent with a single input pointer but the exact aliasing is not determinable from the raw source.
    // UNRESOLVED: Global flt_5ADE40 (NearZeroEpsilonPtr, DERIVED) is read but its exact role in this function is not visible in the raw pseudocode; it is plausibly consumed inside FloatRangeCheck or as the unit-length tolerance, but this is not proven here.
}
