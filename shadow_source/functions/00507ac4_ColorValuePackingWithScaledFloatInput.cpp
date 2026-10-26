// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00507AC4
// Canonical corpus name: ColorValuePackingWithScaledFloatInput
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorValuePackingWithScaledFloatInput_00507ac4.c

void UnknownObject::ColorValuePackingWithScaledFloatInput()
{
    // Packs floating-point color values into 32-bit XRGB8888 words (r<<16 | g<<8 | b). If the format-conversion flag at this+0x1048 (this[1042]) is non-zero, the input buffer a4 is first transformed by DirectXVertexBufferFormatConversion. A color-source offset is derived from the base pointer at this+0x2C plus a 2D component index built from the a2/a3 element selectors. An untyped utility call runs unconditionally, then a per-vertex loop scales each of three channels by 255.0 (each with a per-component bias read from a cycling four-float table) and stores one packed word per vertex until this+0x1058 (this[1046]) vertices are processed. Returns the shared global dword_8B009C.
    // GUARD: Guard: if the format-conversion flag at this+0x1048 (this[1042]) is non-zero, transform the input format before packing. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); the returned buffer pointer replaces a4 for the rest of the function. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute the color-source offset v5 = *(this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)); the a2/a3 mask arithmetic selects a 2D component slot, each slot element being one float. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the packing loop; purpose not evidenced. [callee:0x00507473, source:raw]
    // LOOP: Iterate the vertex index v7 from 0 while v7 < the vertex count at this+0x1058 (this[1046]), storing one packed word per vertex. [field:this:0x00001058, source:raw]
    // CALCULATION: Per-vertex bias v15 = *(float*)(v5 + 4 * (v7 & 3)) cycles through a four-float table selected by the vertex index. [source:raw]
    // ASSIGNMENT: For each vertex, scale three channels by 255.0 with the bias added: r=(int)(in[0]*255.0 + v15), g=(int)(in[1]*255.0 + v15), b=(int)(in[2]*255.0 + v15); pack and store b | (g << 8) | (r << 16) as one 32-bit XRGB8888 word. [source:raw]
    // RETURN: Return dword_8B009C (global at 0x008B009C), the shared color/texture scratch global. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int ColorValuePackingWithScaledFloatInput(this, a2, a3, a4) {
    //       if (this->formatFlag /* +0x1048 * /) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       float* src = (float*)*(DWORD*)(this + 0x2C) + ((a3 & 3) + 8 * (a2 & 3));
    //       UtilityFunction_7473();
    //       for (v7 = 0; v7 < *(DWORD*)(this + 0x1058); ++v7) {
    //           float bias = src[v7 & 3];
    //           int r = (int)(a4[v7*4 + 0] * 255.0f + bias);
    //           int g = (int)(a4[v7*4 + 1] * 255.0f + bias);
    //           int b = (int)(a4[v7*4 + 2] * 255.0f + bias);
    //           *out++ = b | (g << 8) | (r << 16);
    //       }
    //       return dword_8B009C;
    //   }
    // UNRESOLVED: flt_59FEC8 (0x0059FEC8) is listed as a read global by deterministic extraction but does not appear in the raw decompilation text; it is likely the backing store for the 255.0 scale constant, but that linkage is not evidenced.
    // UNRESOLVED: The destination word pointer v6 is not evidenced; the buffer the packed words are written into is not visible from this packet.
    // UNRESOLVED: UtilityFunction_7473's purpose and effects are not evidenced from this packet.
    // UNRESOLVED: The purpose of the returned global dword_8B009C is not determinable from this packet alone; it is shared with the color/texture encoding cluster.
    // UNRESOLVED: The a2/a3 component-index semantics (the 2D layout of the four-float table) are inferred only from the mask/shift arithmetic.
}
