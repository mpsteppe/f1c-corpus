// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052035E
// Canonical corpus name: VectorNormalizeThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VectorNormalizeThreshold_0052035e.c

void UnknownObject::VectorNormalizeThreshold()
{
    // Conditionally normalizes a 3-component float vector (a2 -> a1). Computes squared length v5 and, when v5 >= dword_8D6180 (threshold global), scales the components by a Newton-Raphson refined reciprocal square root using globals dword_8D6184 (scale) and dword_8D6188 (subtractive constant); otherwise writes 0.0 to all three output components. Returns the output pointer a1.
    // ASSIGNMENT: Seed result = a1 and load input components v3 = a2[1], v4 = a2[2]. [source:raw, field:this:0x00000004, field:this:0x00000008]
    // CALCULATION: Compute squared length v5 = a2[0]^2 + v3^2 + v4^2 over the three components. [source:raw, field:this:0x00000000]
    // GUARD: Guard on v5 against global threshold: when dword_8D6180 <= v5 the vector is normalized, otherwise the output is zeroed. [source:raw, global:0x008D6180]
    // CALCULATION: Normalize branch: compute reciprocal square root v6 = 1.0 / fsqrt(v5). [source:raw]
    // CALCULATION: Normalize branch: apply Newton-Raphson refinement v7 = dword_8D6184 * v6 * (dword_8D6188 - v5 * v6 * v6). [source:raw, global:0x008D6184, global:0x008D6188]
    // ASSIGNMENT: Normalize branch: store a1[0..2] = v7 * a2[0..2] for the three components. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Zero branch: store a1[0..2] = 0.0 for the three components. [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   float *sub_52035E(float *out, float *v) {
    //     float y = v[1], z = v[2];
    //     float len2 = v[0]*v[0] + y*y + z*z;
    //     if (dword_8D6180 <= len2) {
    //       float inv = 1.0f / fsqrt(len2);
    //       float scale = dword_8D6184 * inv * (dword_8D6188 - len2 * inv * inv);
    //       out[0] = scale*v[0]; out[1] = scale*y; out[2] = scale*z;
    //     } else {
    //       out[0] = 0.0f; out[1] = 0.0f; out[2] = 0.0f;
    //     }
    //     return out;
    //   }
    // UNRESOLVED: Identity of the math-library object owning this helper is unknown; the packet carries no owner evidence.
    // UNRESOLVED: Runtime values of globals dword_8D6180, dword_8D6184 and dword_8D6188 are not present in the packet.
    // UNRESOLVED: fsqrt appears in the decompiled source; whether it is a compiler intrinsic or a library call is not resolvable from the packet.
}
