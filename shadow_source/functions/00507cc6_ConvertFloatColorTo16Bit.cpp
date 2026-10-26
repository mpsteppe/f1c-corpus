// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507CC6
// Canonical corpus name: ConvertFloatColorTo16Bit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConvertFloatColorTo16Bit_00507cc6.c

void UnknownObject::ConvertFloatColorTo16Bit()
{
    // Packs floating-point color values into 16-bit RGB555 words (r<<10 | g<<5 | b) using a scale factor of 31.0 per channel. Matches the sibling 32-bit packer ColorValuePackingWithScaledFloatInput: a format-conversion flag at this+0x1048 (this[1042]) triggers DirectXVertexBufferFormatConversion on the input a4, a source offset is built from this+0x2C plus a 2D a2/a3 component index, an untyped utility call runs unconditionally, and a per-vertex loop scales the three channels by 31.0 (plus a cycling four-float bias) writing one word per vertex until the count at this+0x1058 (this[1046]) is reached. Returns the shared global dword_8B009C. A prior skeleton fill (existing_analysis) independently describes the same fields as vertex-count and format-conversion flag, consistent with this reading.
    // GUARD: Guard: if the format-conversion flag at this+0x1048 (this[1042]) is non-zero, transform the input format before packing. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); the returned buffer pointer replaces a4 for the rest of the function. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute the color-source offset v5 = *(this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)); the a2/a3 mask arithmetic selects a 2D component slot, each slot element being one float. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the packing loop; purpose not evidenced. [callee:0x00507473, source:raw]
    // LOOP: Iterate the vertex index v7 from 0 while v7 < the vertex count at this+0x1058 (this[1046]), storing one packed 16-bit word per vertex. [field:this:0x00001058, source:raw]
    // CALCULATION: Per-vertex bias v15 = *(float*)(v5 + 4 * (v7 & 3)) cycles through a four-float table selected by the vertex index. [source:raw]
    // ASSIGNMENT: For each vertex, scale three channels by 31.0 with the bias added: r=(int)(in[0]*31.0 + v15), g=(int)(in[1]*31.0 + v15), b=(int)(in[2]*31.0 + v15); pack and store b | (g << 5) | (r << 10) as one 16-bit RGB555 word (bit 15 unused). [source:raw]
    // RETURN: Return dword_8B009C (global at 0x008B009C), the shared color/texture scratch global. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int ConvertFloatColorTo16Bit(this, a2, a3, a4) {
    //       if (this->formatFlag /* +0x1048 * /) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       float* src = (float*)*(DWORD*)(this + 0x2C) + ((a3 & 3) + 8 * (a2 & 3));
    //       UtilityFunction_7473();
    //       for (v7 = 0; v7 < *(DWORD*)(this + 0x1058); ++v7) {
    //           float bias = src[v7 & 3];
    //           int r = (int)(a4[v7*4 + 0] * 31.0f + bias);
    //           int g = (int)(a4[v7*4 + 1] * 31.0f + bias);
    //           int b = (int)(a4[v7*4 + 2] * 31.0f + bias);
    //           *out++ = (WORD)(b | (g << 5) | (r << 10));
    //       }
    //       return dword_8B009C;
    //   }
    // UNRESOLVED: flt_5ACCD0 (0x005ACCD0) is listed as a read global by deterministic extraction but does not appear in the raw decompilation text; it is likely the backing store for the 31.0 scale constant, but that linkage is not evidenced.
    // UNRESOLVED: The destination 16-bit word pointer v6 is not evidenced; the buffer the packed words are written into is not visible from this packet.
    // UNRESOLVED: UtilityFunction_7473's purpose and effects are not evidenced from this packet.
    // UNRESOLVED: The purpose of the returned global dword_8B009C is not determinable from this packet alone; it is shared with the color/texture encoding cluster.
    // UNRESOLVED: The a2/a3 component-index semantics (the 2D layout of the four-float table) are inferred only from the mask/shift arithmetic.
}
