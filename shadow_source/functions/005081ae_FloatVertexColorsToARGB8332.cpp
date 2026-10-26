// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005081AE
// Canonical corpus name: F_15BitTo16BitTextureDithering
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_15BitTo16BitTextureDithering_005081ae.c

void UnknownObject::FloatVertexColorsToARGB8332()
{
    // Converts floating-point RGBA vertex colors into packed 16-bit ARGB8332 words (alpha 8 bits, red 3, green 3, blue 2) using a 4-entry dither offset table. If the format-conversion flag this[1042] (field 0x1048) is set, calls DirectXVertexBufferFormatConversion to normalize the source format first; then unconditionally calls UtilityFunction_7473. For each of this[1046] (field 0x1058) vertices it reads four floats from the row base this[11] (field 0x2C) plus a 4*(v7 & 3) dither offset, quantizes red and green by 7.0, blue by 3.0 and alpha by 255.0 (each plus the dither offset), packs them into an ARGB8332 word and stores it to the destination buffer. Returns dword_8B009C.
    // ASSIGNMENT: Save the this pointer to a local so it survives the format-conversion call. [source:raw]
    // GUARD: If this[1042] (field 0x1048) is non-zero, the source vertex format must be converted before processing. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4) and replace the working vertex pointer/format a4 with its result. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Compute the texel/row base pointer as this[11] (field 0x2C) plus 4 * ((a3 & 3) + 8 * (a2 & 3)). [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473 unconditionally before the encode loop. [callee:0x00507473, source:raw]
    // GUARD: If the vertex count this[1046] (field 0x1058) is zero, skip the dither/encode loop entirely. [field:this:0x00001058, source:raw]
    // LOOP: Iterate v7 from 0 up to the vertex count this[1046], consuming 16 input bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Read a dither offset from the float table at the row base plus 4*(v7 & 3), then quantize each of four float channels: red and green scaled by 7.0, blue by 3.0 and alpha by 255.0, each plus the dither offset, truncated to int. [field:this:0x0000002C, global:0x0059E478, global:0x0059E864, global:0x0059FEC8, source:raw]
    // ASSIGNMENT: Pack the four quantized channels into a 16-bit ARGB8332 word as v11 | (4 * (v12 | (8 * (v9 | (8 * v16))))) and store it into consecutive destination words. [source:raw]
    // RETURN: Return the value of dword_8B009C. [function:0x005081AE, global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   saved_this = this;
    //   if (this[1042]) {
    //       a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       this = saved_this;
    //   }
    //   row = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   v7 = 0;
    //   if (this[1046]) {
    //       v8 = 0;
    //       do {
    //           dither = *(float*)(row + 4 * (v7 & 3));
    //           r = (int)(*(float*)(v8 + a4) * 7.0 + dither);
    //           g = (int)(*(float*)(v8 + a4 + 4) * 7.0 + dither);
    //           b = (int)(*(float*)(v8 + a4 + 8) * 3.0 + dither);
    //           a = (int)(*(float*)(v8 + a4 + 12) * 255.0 + dither);
    //           v8 += 16;
    //           *out_word++ = (short)(b | (4 * (g | (8 * (r | (8 * a))))));
    //           ++v7;
    //       } while (v7 < this[1046]);
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: The destination word pointer v6 (EDX) is written but its initialization is not visible in the decompiled text; the output buffer base is not evidenced here.
    // UNRESOLVED: The mapping from the float globals flt_59E478, flt_59E864 and flt_59FEC8 to the literal channel scales 7.0/7.0/3.0/255.0 is not directly evidenced (Hex-Rays folded the globals into literals). The existing_analysis labels (SteeringCenterBoost, ColorQuantScale, AlphaChannelMultiplier) are DERIVED and unverified.
    // UNRESOLVED: The purpose of UtilityFunction_7473 is unknown from this function alone.
    // UNRESOLVED: The meaning of a4 after DirectXVertexBufferFormatConversion (converted buffer pointer vs format id) is not evidenced.
}
