// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005094E8
// Canonical corpus name: TextureEncoderRGBA8888Packed
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncoderRGBA8888Packed_005094e8.c

void UnknownObject::FloatVertexColorToRGBA64Packed()
{
    // Converts a run of floating-point vertex colors into a packed 64-bit format: each of the four channels is scaled by 65535.0, offset by a per-texel bias float from the this+0x2C bias array, truncated to int, and interleaved into a 64-bit quadword that is written to the output buffer (base this+0x18, indexed by a3/a2 with strides this+0x1054 and this+0x1050). Optionally converts the input vertex buffer format via DirectXVertexBufferFormatConversion when the this+0x1048 flag is set, calls UtilityFunction_7473 before the loop, and returns the global dword_8B009C.
    // GUARD: When the format-conversion flag at this+0x1048 is non-zero, convert the input vertex buffer format before processing; otherwise a4 is used as-is. [field:this:0x00001048, function:0x005094E8, source:raw]
    // CALL: DirectXVertexBufferFormatConversion(this, a4) is called on the flag path and its return value replaces the working input pointer a4. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Output quadword pointer v5 = *(this+0x18) + a3 * this[0x1054] + a2 * this[0x1050], using the two per-dimension stride fields. [field:this:0x00000018, field:this:0x00001054, field:this:0x00001050, source:raw]
    // CALCULATION: Bias pointer v16 = *(this+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)) selects the 4-float bias entry for the texel. [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() runs unconditionally before the texel loop. [callee:0x00507473, source:raw]
    // GUARD: Enter the texel loop only when the texel count at this+0x1058 is non-zero. [field:this:0x00001058, source:raw]
    // LOOP: Iterate v18 = 0 .. count-1; each step reads four consecutive floats (16 bytes) from the input pointer a4 and advances the output quadword pointer by 8 bytes. [field:this:0x00001058, source:raw]
    // CALCULATION: Bias float v17 = *(float*)(v16 + 4 * (v18 & 3)) is fetched from the bias array before each texel is scaled. [field:this:0x0000002C, source:raw]
    // CALCULATION: All four channels are computed as float * 65535.0 + v17 and truncated to int; the 65535.0 scale is the read global flt_59F120. [global:0x0059F120, source:raw]
    // ASSIGNMENT: Pack the four 16-bit channel ints into a 64-bit quadword via nested shifts (sign-extended third channel folded through v8) and store it to the output quadword pointer, advancing it. [source:raw]
    // RETURN: Return the read global dword_8B009C. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int FloatVertexColorToRGBA64Packed(DWORD* this, int x, int y, int a4) {
    //       if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //       QWORD* out = (QWORD*)(this[0x18] + y * this[0x1054] + x * this[0x1050]);
    //       float* bias = (float*)(this[0x2C] + 4 * ((y & 3) + 8 * (x & 3)));
    //       UtilityFunction_7473();
    //       for (unsigned i = 0, off = 0; i < this[0x1058]; i++) {
    //           float b = bias[i & 3];
    //           int c0 = (int)(*(float*)(off + a4 + 0)  * 65535.0f + b);
    //           int c1 = (int)(*(float*)(off + a4 + 4)  * 65535.0f + b);
    //           int c2 = (int)(*(float*)(off + a4 + 8)  * 65535.0f + b);
    //           int c3 = (int)(*(float*)(off + a4 + 12) * 65535.0f + b);
    //           *out++ = pack_64bit(c0, c1, c2, c3);
    //           off += 16;
    //       }
    //       return dword_8B009C;
    //   }
    // UNRESOLVED: The canonical ABI name RGBA8888Packed implies 8-bit channels, but the output is a 64-bit quadword of four 16-bit (65535-scaled) channels; the exact bit ordering inside the quadword, including the sign extension of the third channel via v10 >> 31, is not resolved.
    // UNRESOLVED: flt_59F120 is mapped to the 65535.0 scale by DERIVED inference from the read-only global list, not proven by a write site.
    // UNRESOLVED: Which physical channel (red/green/blue/alpha) each of the four input floats maps to is not established.
    // UNRESOLVED: UtilityFunction_7473 side effects on conversion state are unknown.
}
