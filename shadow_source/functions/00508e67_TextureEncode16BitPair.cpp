// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508E67
// Canonical corpus name: TextureEncode16BitPair
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncode16BitPair_00508e67.c

void UnknownObject::TextureEncode16BitPair()
{
    // Encodes two float color channels into packed 32-bit words: each channel is scaled by 32768.0 and stored as a 16-bit unsigned value (first channel in low 16 bits, second in high 16 bits). If the format-conversion flag is set, the vertex buffer format is converted first. Encodes a count of vertices given by this[1046] in a do-while loop, returning a conversion-state global.
    // GUARD: Guard on this[1042] (+0x1048): if non-zero, vertex buffer format conversion runs before encoding. [field:this:0x00001048]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4) to transform the input vertex buffer format. [callee:0x00506CE2]
    // ASSIGNMENT: Replace vertex data pointer a4 with the format-conversion result. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute texel base v6 = this[11] (+0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), selecting an element from the 4x4 texel block addressed by the low 2 bits of a2/a3. [field:this:0x0000002C]
    // CALL: Call UtilityFunction_7473 unconditionally before the encode loop. [callee:0x00507473]
    // GUARD: Guard on vertex count this[1046] (+0x1058): if zero, the do-while body never executes. [field:this:0x00001058]
    // LOOP: Do-while loop over this[1046] (+0x1058) vertices; counter v4 increments, byte offset v8 advances by 16 each iteration. [field:this:0x00001058]
    // CALCULATION: Per vertex: v11 = float(a4+v8) * 32768.0 + float(v6 + 4*(v4&3)) and v10 = float(a4+v8+4) * 32768.0 + float(v6 + 4*(v4&3)); emit (u16)v11 | ((u16)v10 << 16) into the output stream. [source:raw]
    // RETURN: Return conversion-state global dword_8B009C (+0x008B009C). [global:0x008B009C]

    // Conservative worker pseudocode:
    //   int TextureEncode16BitPair(_DWORD *this, char a2, char a3, int a4) {
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     if (this[1046]) {
    //       int v8 = 0;
    //       for (unsigned v4 = 0; v4 < this[1046]; ++v4, v8 += 16) {
    //         float v11 = *(float*)(v8 + a4) * 32768.0f + *(float*)(v6 + 4 * (v4 & 3));
    //         float v10 = *(float*)(v8 + a4 + 4) * 32768.0f + *(float*)(v6 + 4 * (v4 & 3));
    //         *(int*)out++ = (u16)v11 | ((u16)v10 << 16);
    //       }
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Role of global flt_5ACC84 is not visible in the raw text (candidate color-channel multiplier); the scale literal 32768.0 is used in the raw source.
    // UNRESOLVED: Origin of the output stream pointer v7 is not established by the evidence.
    // UNRESOLVED: Layout of the texel block referenced by v6 and the meaning of the 2-bit a2/a3 indices are unconfirmed.
    // UNRESOLVED: Meaning of this[11] (+0x2C) as a base offset is a DERIVED reading from the address arithmetic.
}
