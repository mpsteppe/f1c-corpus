// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B2840
// Canonical corpus name: FloatToByteShortEncoding
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToByteShortEncoding_004b2840.c

void UnknownObject::EncodeIndexedFixedPoint()
{
    // Encodes two floats into fixed-point fields at index a2 of the byte buffer this. a3 is clamped to [-0.49599999, 0.49599999], scaled by 256.0 and stored as a byte at this[a2 + 18]. a4 is clamped to [-327.67001, 327.67001], scaled by 100.0 and stored as a 16-bit value at this[2*a2 + 22]; the function returns that encoded short. Used by SetupCarLightingAndRender (004C71C0) for indexed parameter packing.
    // GUARD: Two-sided range guard on a3: in-range path is a3 <= 0.49599999 and a3 >= -0.49599999; otherwise clamp. [source:raw]
    // CALCULATION: In-range path scales a3 by 256.0 and truncates to a byte value v4. [source:raw]
    // ASSIGNMENT: Clamp low: a3 below -0.49599999 encodes to -127. [source:raw]
    // ASSIGNMENT: Clamp high: a3 above 0.49599999 encodes to 127. [source:raw]
    // ASSIGNMENT: Write the encoded byte v4 to this[a2 + 18]. [source:raw]
    // GUARD: Two-sided range guard on a4: in-range path is a4 <= 327.67001 and a4 >= -327.67001; otherwise clamp. [source:raw]
    // CALCULATION: In-range path scales a4 by 100.0 and truncates to a 16-bit short value v8. [source:raw]
    // ASSIGNMENT: Clamp low: a4 below -327.67001 encodes to -32767. [source:raw]
    // ASSIGNMENT: Clamp high: a4 above 327.67001 encodes to 0x7FFF. [source:raw]
    // ASSIGNMENT: Write the encoded short to this[2*a2 + 22]; result carries the encoded value. [source:raw]
    // RETURN: Return the encoded short value as result. [source:raw]
    // CALL: Invoked by SetupCarLightingAndRender (004C71C0). [caller:0x004C71C0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_4B2840(BYTE* this, int a2, float a3, float a4) {
    //     char v4;
    //     if (a3 <= 0.49599999f) {
    //       if (a3 >= -0.49599999f) v4 = (char)(a3 * 256.0f);
    //       else v4 = -127;
    //     } else {
    //       v4 = 127;
    //     }
    //     this[a2 + 18] = v4;
    //     int v8; int result;
    //     if (a4 <= 327.67001f) {
    //       if (a4 >= -327.67001f) { v8 = (int)(a4 * 100.0f); result = (short)v8; }
    //       else { result = -32767; v8 = -32767; }
    //     } else {
    //       result = 0x7FFF; v8 = 0x7FFF;
    //     }
    //     *(WORD*)&this[2*a2 + 22] = v8;
    //     return result;
    //   }
    // UNRESOLVED: Six read-only globals (flt_59E6F8, flt_59F10C, flt_5ACCC0, flt_5ACCC4, flt_5ACCC8, flt_5ACCCC) are flagged by packet facts but appear nowhere in the raw source; skeleton-fill labels (SignedShortScale, SignedByteScale, quantization thresholds) are unverifiable from this packet and the constants in source are literal floats.
    // UNRESOLVED: Field layout of the destination buffer this (base + a2*? + 18/22) is indexed only; the owning object and element stride are outside this packet.
}
