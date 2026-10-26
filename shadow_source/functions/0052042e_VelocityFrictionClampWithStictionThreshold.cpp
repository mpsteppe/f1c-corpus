// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052042E
// Canonical corpus name: VelocityFrictionClampWithStictionThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VelocityFrictionClampWithStictionThreshold_0052042e.c

void UnknownObject::VelocityFrictionClampWithStictionThreshold()
{
    // 4-component velocity clamp that zeros the vector below a squared-length stiction threshold. Computes the squared length of input a2 over its X, Y and Z components. When the squared length reaches the global threshold dword_8D618C, applies a Newton-Raphson refined reciprocal-sqrt scale (using dword_8D6190 and dword_8D6194) to all four components, including W, and writes the result into output a1. When the squared length falls below the threshold, writes all zeroes to the output. Returns the output pointer a1. Structurally identical to VectorNormalizeWithThreshold (0051EE7E) but uses a distinct set of globals (0x008D618C/90/94).
    // CALCULATION: Compute squared length v5 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2]. [source:raw]
    // GUARD: Threshold guard: if dword_8D618C <= v5, scale; otherwise fall through to the zeroing branch. The threshold is read from the global at 0x008D618C. [global:0x008D618C, source:raw]
    // CALCULATION: v6 = 1.0 / fsqrt(v5), then Newton-Raphson refinement: v7 = dword_8D6190 * v6 * (dword_8D6194 - v5 * v6 * v6), reading refinement constants at 0x008D6190 and 0x008D6194. [global:0x008D6190, global:0x008D6194, source:raw]
    // ASSIGNMENT: Write scaled components to the output: a1[0] = v7 * a2[0], a1[1] = v7 * a2[1], a1[2] = v7 * a2[2], a1[3] = v7 * a2[3] (W also scaled). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Below-threshold branch: zero all four output components a1[0..3] (stiction case). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_52042E(float *out, float *in) {
    //     float lenSq = in[0]*in[0] + in[1]*in[1] + in[2]*in[2];
    //     if (dword_8D618C <= lenSq) {
    //       float inv = 1.0 / fsqrt(lenSq);
    //       float scale = dword_8D6190 * inv * (dword_8D6194 - lenSq * inv * inv);
    //       out[0] = scale * in[0]; out[1] = scale * in[1];
    //       out[2] = scale * in[2]; out[3] = scale * in[3];
    //     } else {
    //       out[0] = 0.0; out[1] = 0.0; out[2] = 0.0; out[3] = 0.0;
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Actual values of the threshold dword_8D618C and the refinement constants dword_8D6190/dword_8D6194 are unknown; only their roles in the scaling are established.
    // UNRESOLVED: Whether the W component (a2[3]) is part of a velocity 3-vector plus padding, or a genuine 4-vector, is unresolved.
    // UNRESOLVED: The owning class/module of this math helper is unidentified; the canonical name implies velocity/stiction use but that is not evidenced here.
}
