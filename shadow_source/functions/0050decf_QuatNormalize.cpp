// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050DECF
// Canonical corpus name: QuatNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuatNormalize_0050decf.c

void UnknownObject::QuatNormalize()
{
    // Normalizes the quaternion a2 (x,y,z,w) to unit length and writes the result into a1 (in-place safe). Computes the squared norm v8 = a2[0]^2 + a2[1]^2 + a2[2]^2 + a2[3]^2; if FloatRangeCheck(v8, 1.0) passes the input is already unit length and is copied (or returned without copy when a1 == a2). Otherwise, when v8 exceeds 1.1754944e-38 the quaternion is scaled by 1/sqrt(v8); when v8 is at or below that threshold all four output components are zeroed. Every path writes all four output components, so an external poke to the output does not persist.
    // CALCULATION: Compute the squared norm v8 = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2] + a2[3]*a2[3]. [source:raw]
    // CALL: Call FloatRangeCheck(v8, 1.0) to test whether the squared norm is within the symmetric epsilon band of 1.0, i.e. whether the quaternion is already unit length. [callee:0x0050C042, source:raw]
    // GUARD: When FloatRangeCheck returns true the quaternion is already normalized: copy a2 into a1, or return immediately when a1 == a2 (in-place call). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // GUARD: When v8 > 1.1754944e-38 compute the scaling factor v5 = 1.0 / sqrt(v8) and build the normalized vector in a scratch buffer; when v8 <= 1.1754944e-38 skip normalization. [source:raw]
    // ASSIGNMENT: Write the four output components: on the normalization path each output equals v5 times the corresponding input component; on the too-small path all four outputs are zeroed; on the already-unit path they are a straight copy of the input. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Return the output buffer pointer a1. [function:0x0050DECF, source:raw]

    // Conservative worker pseudocode:
    //   float* QuatNormalize(float* a1, float* a2) {
    //     float sq = a2[0]*a2[0] + a2[1]*a2[1] + a2[2]*a2[2] + a2[3]*a2[3];
    //     if (FloatRangeCheck(sq, 1.0f)) {
    //       if (a1 != a2) { a1[0]=a2[0]; a1[1]=a2[1]; a1[2]=a2[2]; a1[3]=a2[3]; }
    //       return a1;
    //     }
    //     if (sq > 1.1754944e-38f) {
    //       float inv = 1.0f / sqrt(sq);
    //       float tmp[4] = { inv*a2[0], inv*a2[1], inv*a2[2], inv*a2[3] };
    //       a1[0]=tmp[0]; a1[1]=tmp[1]; a1[2]=tmp[2]; a1[3]=tmp[3];
    //     } else {
    //       a1[0]=0.0f; a1[1]=0.0f; a1[2]=0.0f; a1[3]=0.0f;
    //     }
    //     return a1;
    //   }
    // UNRESOLVED: The packet lists read-only globals flt_59E43C (0x0059E43C) and flt_5ADE40 (0x005ADE40); the raw source renders their loads as the folded literals 1.0 and 1.1754944e-38, but which global backs which literal is DERIVED and unproven.
    // UNRESOLVED: FloatRangeCheck is evidenced by the packet callee list; the exact epsilon literals it applies are defined in 0x0050C042, not in this packet.
}
