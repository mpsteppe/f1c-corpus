// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508007
// Canonical corpus name: TextureEncode8BitDXTS3TCQuantization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncode8BitDXTS3TCQuantization_00508007.c

void UnknownObject::TextureEncode8BitDXTS3TCQuantization()
{
    // Packs per-vertex floating-point color channels into 8-bit RGB332 bytes (B=2 bits, G=3 bits, R=3 bits) using scale factors 7.0 for R/G and 3.0 for B. When the format-conversion flag at this+0x1048 is set, first transforms the vertex buffer via DirectXVertexBufferFormatConversion and uses the returned address as the source base. Reads the vertex-data base at this+0x2C and the vertex count at this+0x1058, emits one packed byte per vertex through an output pointer carried in a register, then returns the global conversion-state dword at 0x008B009C.
    // ASSIGNMENT: Save original this into v16 and initialize the vertex counter v4 to 0 [source:raw]
    // GUARD: Format-conversion flag this[1042] (offset 0x1048) gates whether the vertex buffer is transformed first [field:this:0x00001048, source:raw]
    // CALL: DirectXVertexBufferFormatConversion(this, a4) transforms the vertex buffer; the returned address replaces a4 as the source base [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // ASSIGNMENT: Compute the source color-data base v6 = this[11] (offset 0x2C) + 4*((a3&3)+8*(a2&3)) from the grid indices a2/a3 [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() invoked unconditionally before the packing loop [callee:0x00507473, source:raw]
    // GUARD: Packing loop executes only while the vertex count v16[1046] (offset 0x1058) is non-zero [field:this:0x00001058, source:raw]
    // LOOP: One iteration per vertex, bounded by the vertex count read at this+0x1058 [field:this:0x00001058, source:raw]
    // ASSIGNMENT: Read the base color component v15 from the source base at v6 + 4*(v4&3) [source:raw]
    // CALCULATION: Scale-and-offset each channel and truncate to int: R/G floats at (v8+a4) and (v8+a4+4) scaled by 7.0, B float at (v8+a4+8) scaled by 3.0, each plus v15 [source:raw]
    // ASSIGNMENT: Pack one byte and write through the output pointer v7: (int)B | (4 * ((int)G | (8*(int)R))) — R in bits 5-7, G in bits 2-4, B in bits 0-1 (RGB332) [source:raw]
    // LOOP: Advance the source by 16 bytes per vertex and increment the vertex counter [source:raw]
    // RETURN: Return the global conversion-state dword_8B009C [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   v16 = this;
    //   if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   v6 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   for (v4 = 0; v4 < v16[0x1058]; ++v4) {
    //       base = *(float*)(v6 + 4 * (v4 & 3));
    //       r = (int)(*(float*)(v8 + a4) * 7.0 + base);
    //       g = (int)(*(float*)(v8 + a4 + 4) * 7.0 + base);
    //       b = (int)(*(float*)(v8 + a4 + 8) * 3.0 + base);
    //       *out8++ = b | (4 * (g | (8 * r)));   /* RGB332: B 2 bits, G 3 bits, R 3 bits * /
    //       v8 += 16;
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: The output byte pointer v7 (edx) is never assigned in the decompiled text; the real prototype must deliver the output buffer through a register or a hidden argument
    // UNRESOLVED: flt_59E478 and flt_59E864 are reported as referenced globals by the packet but never appear in the decompiled text, so the scale literals 7.0/3.0 cannot be confirmed to originate from them
    // UNRESOLVED: Semantics of the a2/a3 grid indices ((a3&3)+8*(a2&3)) and the layout behind this+0x2C are unconfirmed
}
