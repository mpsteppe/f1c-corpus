// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E3E0
// Canonical corpus name: Vector4NormalizeWithLengthThreshold
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Vector4NormalizeWithLengthThreshold_0050e3e0.c

void UnknownObject::Vector4NormalizeWithLengthThreshold()
{
    // Normalizes a vector with a length threshold. Computes the squared length v7 over the three spatial components a2[0..2]; if FloatRangeCheck(v7, 1.0) passes the vector is already unit length and all four components of a2 are copied into a1 (or the function returns immediately when a1 == a2). Otherwise, when v7 exceeds 1.1754944e-38, all four components including a2[3] are scaled by v5 = 1.0/sqrt(v7); when v7 is at or below that threshold all four output components are zeroed. Every path writes all four output components, so an external poke to the output does not persist.
    // CALCULATION: Compute the squared length v7 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2], using only the three spatial components. [source:raw]
    // CALL: Call FloatRangeCheck(v7, 1.0) to test whether the squared length is within the symmetric epsilon band of 1.0, i.e. whether the vector is already unit length. [callee:0x0050C042, source:raw]
    // GUARD: When FloatRangeCheck returns true the vector is already normalized: copy all four components a2[0..3] into a1, or return immediately when a1 == a2 (in-place call). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: When v7 > 1.1754944e-38 compute the scaling factor v5 = 1.0 / sqrt(v7) and scale each input component by it; when v7 <= 1.1754944e-38 the output components are zeroed instead. [source:raw]
    // ASSIGNMENT: Write the four output components: on the already-unit path a straight copy of the input; on the normalization path a1[0..2] = v5 * a2[0..2] and a1[3] = v5 * a2[3]; on the too-small path all four components are zeroed. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x0050E3E0, source:raw]

    // Conservative worker pseudocode:
    //   float* Vector4NormalizeWithLengthThreshold(float* a1, float* a2) {
    //     float sq = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2];
    //     if (FloatRangeCheck(sq, 1.0f)) {
    //       if (a1 != a2) { a1[0]=a2[0]; a1[1]=a2[1]; a1[2]=a2[2]; a1[3]=a2[3]; }
    //       return a1;
    //     }
    //     if (sq > 1.1754944e-38f) {
    //       float inv = 1.0f / sqrt(sq);
    //       a1[0]=inv*a2[0]; a1[1]=inv*a2[1]; a1[2]=inv*a2[2]; a1[3]=inv*a2[3];
    //     } else {
    //       a1[0]=0.0f; a1[1]=0.0f; a1[2]=0.0f; a1[3]=0.0f;
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: The packet lists read-only globals flt_59E43C (0x0059E43C) and flt_5ADE40 (0x005ADE40); the raw source renders their loads as the folded literals 1.0 and 1.1754944e-38, but which global backs which literal is DERIVED and unproven.
    // UNRESOLVED: FloatRangeCheck is evidenced by the packet callee list; the exact epsilon literals it applies are defined in 0x0050C042, not in this packet.
    // UNRESOLVED: The unit-length test and the too-small test are computed over the three spatial components a2[0..2] only, yet the normalize scaling and the zeroing are applied to all four components including a2[3]; the intent behind mixing a three-component length test with a four-component scale is DERIVED and unexplained by the packet.
}
