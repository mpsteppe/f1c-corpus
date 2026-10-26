// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E342
// Canonical corpus name: sub_50E342
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_50E342_0050e342.c

void UnknownObject::BlendWeightedTransform()
{
    // Blends two transforms derived from the source buffer a2 with integer parameters a3 and a4, weighted by floats a5 and a6. Computes the total weight v10 = a5 + a6; when FloatRangeCheck reports it is within tolerance of 0.0, copies the four DWORDs of a2 into the output a1 verbatim (or no-ops when a1 == a2). Otherwise builds two intermediate transforms with ThunkToFUN0050e174 using a3 and a4 against the total weight, then blends them into a1 with the normalized weight a6 / v10. Returns a1.
    // CALCULATION: Compute v10 = a5 + a6, the total weight of the blend. [source:raw]
    // CALL: Call FloatRangeCheck(v10, 0.0) to test whether the total weight is within tolerance of zero. [callee:0x0050C042, source:raw]
    // GUARD: When the total weight is near zero, skip blending and copy a2 verbatim into a1 (four DWORDs), skipping the copy only when a1 == a2. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // CALL: Call ThunkToFUN0050e174(v8, a2, a3, v10) to build the first intermediate transform from a2 and parameter a3 at the total weight. [callee:0x0050E198, source:raw]
    // CALL: Call ThunkToFUN0050e174(v9, a2, a4, v10) to build the second intermediate transform from a2 and parameter a4 at the total weight. [callee:0x0050E198, source:raw]
    // CALCULATION: Compute v7 = a6 / v10, the fraction of the total weight contributed by a6. [source:raw]
    // CALL: Call ThunkToFUN0050e174(a1, v8, v9, v7) to blend the two intermediate transforms into the output buffer using the normalized weight. [callee:0x0050E198, source:raw]
    // RETURN: Return the output pointer a1. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD* BlendWeightedTransform(_DWORD* a1, _DWORD* a2, int a3, int a4, float a5, float a6) {
    //     float v10 = a5 + a6;
    //     if (FloatRangeCheck(v10, 0.0f)) {
    //       if (a1 != a2) { a1[0] = a2[0]; a1[1] = a2[1]; a1[2] = a2[2]; a1[3] = a2[3]; }
    //       return a1;
    //     }
    //     int v8[4];
    //     int v9[4];
    //     ThunkToFUN0050e174(v8, a2, a3, v10);
    //     ThunkToFUN0050e174(v9, a2, a4, v10);
    //     float v7 = a6 / v10;
    //     ThunkToFUN0050e174(a1, v8, v9, v7);
    //     return a1;
    //   }
    // UNRESOLVED: The semantics of ThunkToFUN0050e174 (0x0050E198) - whether it constructs, scales, or interpolates the four-DWORD transform - are not described by this packet.
    // UNRESOLVED: The meaning of the integer parameters a3 and a4 (indices, angles, or other transform selectors) is not grounded in this packet.
    // UNRESOLVED: The ABI lead name Quaternion_SLERP (LEGACY trust) suggests the four DWORDs may be a quaternion, but this is not confirmed by the raw source.
}
