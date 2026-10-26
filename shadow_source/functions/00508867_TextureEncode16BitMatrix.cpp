// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508867
// Canonical corpus name: TextureEncode16BitMatrix
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncode16BitMatrix_00508867.c

void UnknownObject::TextureEncode16BitMatrix()
{
    // Structural twin of RGBToLuminanceByte (005087A2) that writes a 16-bit texel per vertex instead of a single byte. When this+0x1048 is set, a4 is first replaced by the DirectXVertexBufferFormatConversion result. Computes a tile base at this+0x2C offset by the (a2,a3) 4x4 block position, calls UtilityFunction_7473, then for each of this+0x1058 vertices builds a word whose low byte is the BT.709 luminance of the RGB floats at a4 (+8,+4,+0) scaled by 255 and whose high byte is the alpha channel float at a4+12 scaled by 255, both added to the tile value at +4*(v4&3). Returns the conversion-state global dword_8B009C.
    // GUARD: Guard on this[1042] (offset 0x1048): when non-zero, call DirectXVertexBufferFormatConversion(this, a4) and replace a4 with its returned pointer. [field:this:0x00001048, callee:0x00506CE2, source:raw]
    // CALCULATION: Compute tile base pointer v6 = this[11] (offset 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)); this encodes a 4x4 color block position from the masked (a2,a3) indices. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473, source:raw]
    // LOOP: If this[1046] (offset 0x1058 vertex count) is non-zero, do-while loop over v4: compute v12 = (float at a4+v8+8 * 0.0721 + float at a4+v8+4 * 0.7154 + float at a4+v8 * 0.2125) * 255 + float at v6+4*(v4&3), and v11 = float at a4+v8+12 * 255 + float at v6+4*(v4&3); assemble the word with low byte (int)v12 and high byte (int)v11, write *v7++, advance v8 by 16; repeat while v4 < this+0x1058. [field:this:0x00001058, source:raw]
    // RETURN: Return dword_8B009C (conversion-state global) as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   v4 = 0;
    //   v13 = this;
    //   if (this[1042]) {
    //     a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   }
    //   v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   if (v13[1046]) {
    //     v8 = 0;
    //     do {
    //       v12 = (*(float*)(v8 + a4 + 8) * 0.0721
    //            + *(float*)(v8 + a4 + 4) * 0.7154
    //            + *(float*)(v8 + a4) * 0.2125) * 255.0
    //            + *(float*)(v6 + 4 * (v4 & 3));
    //       v11 = *(float*)(v8 + a4 + 12) * 255.0 + *(float*)(v6 + 4 * (v4 & 3));
    //       v9 = (int)v12 | ((int)v11 << 8);
    //       v8 += 16;
    //       *v7++ = v9;
    //       ++v4;
    //     } while (v4 < v13[1046]);
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: Globals flt_59FEC8, flt_5ADB18, flt_5ADB1C, flt_5ADB20 are flagged as read (R) in the packet facts but do not appear in the raw decompiled source, which uses inline float literals; their role here cannot be verified.
    // UNRESOLVED: The BT.709 weighting coefficients (0.0721/0.7154/0.2125) and the 255.0 scale are inline literals in the raw source; the per-vertex stride of 16 bytes is DERIVED from the loop increment.
    // UNRESOLVED: The cluster_copy prelabel (trust DERIVED) notes this function as a structural twin of 005087A2; the 16-bit word layout (low byte luminance, high byte alpha) is DERIVED from the source's v9 assembly.
    // UNRESOLVED: The alpha channel reads the float at a4+v8+12; the exact DXT format this encodes into is not stated in the packet.
}
