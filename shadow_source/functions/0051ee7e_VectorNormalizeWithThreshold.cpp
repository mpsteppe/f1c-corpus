// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051EE7E
// Canonical corpus name: VectorNormalizeWithThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorNormalizeWithThreshold_0051ee7e.c

void UnknownObject::VectorNormalizeWithThreshold()
{
    // 4-component vector normalizer with a squared-length threshold. Computes the squared length of input a2 over its X, Y and Z components. When the squared length reaches the global threshold dword_8D600C, computes a Newton-Raphson refined reciprocal-sqrt of the squared length (using dword_8D6010 and dword_8D6014) and writes all four scaled components (including W) into output a1. When the squared length falls below the threshold, zeroes all four output components. Returns the output pointer a1.
    // CALCULATION: Compute squared length v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2]. [source:raw]
    // GUARD: Threshold guard: if dword_8D600C <= v5, normalize; otherwise fall through to the zeroing branch. The threshold is read from the global at 0x008D600C. [global:0x008D600C, source:raw]
    // CALCULATION: v6 = 1.0 / fsqrt(v5), then Newton-Raphson refinement: v7 = dword_8D6010 * v6 * (dword_8D6014 - v5 * v6 * v6), reading refinement constants at 0x008D6010 and 0x008D6014. [global:0x008D6010, global:0x008D6014, source:raw]
    // ASSIGNMENT: Write normalized components to the output: a1[0] = v7 * a2[0], a1[1] = v7 * a2[1], a1[2] = v7 * a2[2], a1[3] = v7 * a2[3] (W also scaled). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Threshold-miss branch: zero all four output components a1[0..3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_51EE7E(float *out, float *in) {
    //     float lenSq = in[0]*in[0] + in[1]*in[1] + in[2]*in[2];
    //     if (dword_8D600C <= lenSq) {
    //       float inv = 1.0 / fsqrt(lenSq);
    //       float scale = dword_8D6010 * inv * (dword_8D6014 - lenSq * inv * inv);
    //       out[0] = scale * in[0]; out[1] = scale * in[1];
    //       out[2] = scale * in[2]; out[3] = scale * in[3];
    //     } else {
    //       out[0] = 0.0; out[1] = 0.0; out[2] = 0.0; out[3] = 0.0;
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Actual values of the threshold dword_8D600C and the Newton-Raphson constants dword_8D6010/dword_8D6014 are unknown; only their roles in the normalization are established.
    // UNRESOLVED: Caller context and whether W (a2[3]) participates in length (it does not here, only in scaling) are unresolved.
    // UNRESOLVED: The owning class/module of this SSE math helper is unidentified.
}
