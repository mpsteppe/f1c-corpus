// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FC910
// Canonical corpus name: sub_4FC910
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FC910_004fc910.c

void UnknownObject::UnpackPacked16BitToFloats()
{
    // Unpacks six packed 16-bit integers from an input buffer into six floats in the output object. The first four are read as unsigned 16-bit values scaled by 0.000015259022 (1/65536) into this[0..3]; the last two are read as signed 16-bit values scaled by 0.0078125 (1/128) into this[4..5]. Returns the raw signed 16-bit value at input offset 18. Called by CarPositionTargetCheck (004FE060).
    // ASSIGNMENT: this[0] = (uint16)a2[+8] * 0.000015259022 (first unsigned channel, luminance-decode scale) [field:this:0x00000000, global:0x005AD290, source:raw]
    // ASSIGNMENT: this[1] = (uint16)a2[+10] * 0.000015259022 (second unsigned channel) [field:this:0x00000004, global:0x005AD290, source:raw]
    // ASSIGNMENT: this[2] = (uint16)a2[+12] * 0.000015259022 (third unsigned channel) [field:this:0x00000008, global:0x005AD290, source:raw]
    // ASSIGNMENT: this[3] = (uint16)a2[+14] * 0.000015259022 (fourth unsigned channel) [field:this:0x0000000C, global:0x005AD290, source:raw]
    // ASSIGNMENT: this[4] = (int16)a2[+16] * 0.0078125 (first signed component, short-to-float scale) [field:this:0x00000010, global:0x0059E774, source:raw]
    // ASSIGNMENT: this[5] = (int16)a2[+18] * 0.0078125 (second signed component); the raw signed value is also the return value [field:this:0x00000014, global:0x0059E774, source:raw]
    // RETURN: Return the raw signed 16-bit value read from input offset 18 [source:raw]
    // CALL: Invoked by CarPositionTargetCheck (004FE060) to decode packed 16-bit target data into floats [caller:0x004FE060]

    // Conservative worker pseudocode:
    //   void sub_4FC910(float *out, char *src) {
    //     out[0] = (uint16)(src[8])  * 0.000015259022;
    //     out[1] = (uint16)(src[10]) * 0.000015259022;
    //     out[2] = (uint16)(src[12]) * 0.000015259022;
    //     out[3] = (uint16)(src[14]) * 0.000015259022;
    //     out[4] = (int16)(src[16])  * 0.0078125;
    //     out[5] = (int16)(src[18])  * 0.0078125;
    //     return (int16)(src[18]);
    //   }
    // UNRESOLVED: Meaning of the six components (color/luminance vs position/normal) is inferred from the existing-analysis fill and the scale-factor globals; the packed input layout is not documented elsewhere
    // UNRESOLVED: The read-only globals flt_59E774 and flt_5AD290 do not appear literally in the decompiled source because the compiler folded them into the floating-point constants
}
