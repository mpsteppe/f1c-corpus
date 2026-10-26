// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507DC7
// Canonical corpus name: TextureEncode16Bit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncode16Bit_00507dc7.c

void UnknownObject::TextureEncode16Bit()
{
    // Packs floating-point color values into 16-bit ARGB1555 texture words (a<<15 | r<<10 | g<<5 | b). Structural twin of ConvertFloatColorTo16Bit but with a fourth alpha channel: three channels are scaled by 31.0 (plus a cycling four-float bias) while the alpha channel at in[3] is added unscaled, then all four components are packed into one 16-bit word. Shares the sibling control flow: format flag at this+0x1048 (this[1042]) gates DirectXVertexBufferFormatConversion on a4, source offset from this+0x2C plus a 2D a2/a3 index, unconditional UtilityFunction_7473 call, and a per-vertex loop bounded by the count at this+0x1058 (this[1046]). Returns the shared global dword_8B009C.
    // GUARD: Guard: if the format-conversion flag at this+0x1048 (this[1042]) is non-zero, transform the input format before packing. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); the returned buffer pointer replaces a4 for the rest of the function. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute the color-source offset v5 = *(this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)); the a2/a3 mask arithmetic selects a 2D component slot, each slot element being one float. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the packing loop; purpose not evidenced. [callee:0x00507473, source:raw]
    // LOOP: Iterate the vertex index v7 from 0 while v7 < the vertex count at this+0x1058 (this[1046]), storing one packed 16-bit word per vertex. [field:this:0x00001058, source:raw]
    // CALCULATION: Per-vertex bias v17 = *(float*)(v5 + 4 * (v7 & 3)) cycles through a four-float table selected by the vertex index. [source:raw]
    // ASSIGNMENT: For each vertex, scale three channels by 31.0 with the bias added: r=(int)(in[0]*31.0 + v17), g=(int)(in[1]*31.0 + v17), b=(int)(in[2]*31.0 + v17), and take the alpha channel unscaled: a=(int)(v17 + in[3]); pack and store b | (g << 5) | (r << 10) | (a << 15) as one 16-bit ARGB1555 word. [source:raw]
    // RETURN: Return dword_8B009C (global at 0x008B009C), the shared color/texture scratch global. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int TextureEncode16Bit(this, a2, a3, a4) {
    //       if (this->formatFlag /* +0x1048 * /) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       float* src = (float*)*(DWORD*)(this + 0x2C) + ((a3 & 3) + 8 * (a2 & 3));
    //       UtilityFunction_7473();
    //       for (v7 = 0; v7 < *(DWORD*)(this + 0x1058); ++v7) {
    //           float bias = src[v7 & 3];
    //           int r = (int)(a4[v7*4 + 0] * 31.0f + bias);
    //           int g = (int)(a4[v7*4 + 1] * 31.0f + bias);
    //           int b = (int)(a4[v7*4 + 2] * 31.0f + bias);
    //           int a = (int)(bias + a4[v7*4 + 3]);
    //           *out++ = (WORD)(b | (g << 5) | (r << 10) | (a << 15));
    //       }
    //       return dword_8B009C;
    //   }
    // UNRESOLVED: flt_5ACCD0 (0x005ACCD0) is listed as a read global by deterministic extraction but does not appear in the raw decompilation text; it is likely the backing store for the 31.0 scale constant, but that linkage is not evidenced.
    // UNRESOLVED: The destination 16-bit word pointer v6 is not evidenced; the buffer the packed words are written into is not visible from this packet.
    // UNRESOLVED: UtilityFunction_7473's purpose and effects are not evidenced from this packet.
    // UNRESOLVED: The purpose of the returned global dword_8B009C is not determinable from this packet alone; it is shared with the color/texture encoding cluster.
    // UNRESOLVED: The alpha channel is not scaled by 31.0 in the raw source; whether that is intentional (1-bit alpha) or a decompiler artifact is not evidenced.
    // UNRESOLVED: The a2/a3 component-index semantics (the 2D layout of the four-float table) are inferred only from the mask/shift arithmetic.
}
