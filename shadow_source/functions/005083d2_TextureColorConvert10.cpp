// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005083D2
// Canonical corpus name: TextureColorConvert10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureColorConvert10_005083d2.c

void UnknownObject::TextureColorConvert10()
{
    // Packs per-vertex floating-point color channels into packed 32-bit RGB10A2 values (R/G/B scaled by 1023.0, alpha by 3.0). When the format-conversion flag at this+0x1048 is set, first transforms the vertex buffer via DirectXVertexBufferFormatConversion and uses the returned address as the source base. Reads the vertex-data base at this+0x2C and the vertex count at this+0x1058, emits one 32-bit word per vertex through an output pointer carried in a register, then returns the global conversion-state dword at 0x008B009C.
    // ASSIGNMENT: Save original this into v18 and initialize the vertex counter v7 to 0 [source:raw]
    // GUARD: Format-conversion flag this[1042] (offset 0x1048) gates whether the vertex buffer is transformed first [field:this:0x00001048, source:raw]
    // CALL: DirectXVertexBufferFormatConversion(this, a4) transforms the vertex buffer; the returned address replaces a4 as the source base [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // ASSIGNMENT: Compute the source color-data base v5 = this[11] (offset 0x2C) + 4*((a3&3)+8*(a2&3)) from the grid indices a2/a3 [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() invoked unconditionally before the packing loop [callee:0x00507473, source:raw]
    // GUARD: Packing loop executes only while the vertex count v18[1046] (offset 0x1058) is non-zero [field:this:0x00001058, source:raw]
    // LOOP: One iteration per vertex, bounded by the vertex count read at this+0x1058 [field:this:0x00001058, source:raw]
    // ASSIGNMENT: Read the base color component v17 from the source base at v5 + 4*(v7&3) [source:raw]
    // CALCULATION: Scale-and-offset each channel and truncate to int: R/G/B floats at (v8+a4), (v8+a4+4), (v8+a4+8) scaled by 1023.0, alpha float at (v8+a4+12) scaled by 3.0, each plus v17 [source:raw]
    // ASSIGNMENT: Pack one 32-bit word and write through the output pointer v6: v11 | ((v12 | ((v9 | ((int)v16 << 10)) << 10)) << 10) — R in bits 0-9, G in bits 10-19, B in bits 20-29, A in bits 30-31 (RGB10A2) [source:raw]
    // LOOP: Advance the source by 16 bytes per vertex and increment the vertex counter [source:raw]
    // RETURN: Return the global conversion-state dword_8B009C [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   v18 = this;
    //   if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   v5 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   for (v7 = 0; v7 < v18[0x1058]; ++v7) {
    //       base = *(float*)(v5 + 4 * (v7 & 3));
    //       r = (int)(*(float*)(v8 + a4) * 1023.0 + base);
    //       g = (int)(*(float*)(v8 + a4 + 4) * 1023.0 + base);
    //       b = (int)(*(float*)(v8 + a4 + 8) * 1023.0 + base);
    //       a = (int)(*(float*)(v8 + a4 + 12) * 3.0 + base);
    //       *out32++ = r | ((g | ((b | (a << 10)) << 10)) << 10);   /* RGB10A2 * /
    //       v8 += 16;
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: The output 32-bit word pointer v6 (edx) is never assigned in the decompiled text; the real prototype must deliver the output buffer through a register or a hidden argument
    // UNRESOLVED: flt_59E478 and flt_5ADBA0 are reported as referenced globals by the packet but never appear in the decompiled text, so the scale literals 1023.0/3.0 cannot be confirmed to originate from them
    // UNRESOLVED: Semantics of the a2/a3 grid indices ((a3&3)+8*(a2&3)) and the layout behind this+0x2C are unconfirmed
}
