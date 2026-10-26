// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005087A2
// Canonical corpus name: DXTColorEncoder_87a2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DXTColorEncoder_87a2_005087a2.c

void UnknownObject::RGBToLuminanceByte()
{
    // Converts float RGB vertex data to a single luminance byte for DXT/S3TC encoding. When the format-conversion flag at this+0x1048 is set, first runs a4 through DirectXVertexBufferFormatConversion and uses the converted pointer. Computes a tile base at this+0x2C offset by the (a2,a3) 4x4 block position, calls UtilityFunction_7473, then for each of this+0x1058 vertices computes the BT.709-weighted luminance of the RGB floats at a4 (+8,+4,+0) scaled by 255 and added to the tile value at +4*(i&3), writing one byte per vertex. Returns the conversion-state global dword_8B009C.
    // GUARD: Guard on this[1042] (offset 0x1048): when non-zero, call DirectXVertexBufferFormatConversion(this, a4) and replace a4 with its returned pointer. [field:this:0x00001048, callee:0x00506CE2, source:raw]
    // CALCULATION: Compute tile base pointer v6 = this[11] (offset 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)); this encodes a 4x4 color block position from the masked (a2,a3) indices. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473, source:raw]
    // LOOP: For i in [0, this[1046]) (offset 0x1058 vertex count): compute v10 = (float at a4+v4+8 * 0.0721 + float at a4+v4+4 * 0.7154 + float at a4+v4 * 0.2125) * 255 + float at v6+4*(i&3); write (int)v10 as one byte via *v7++; v4 advances by 16 each iteration. [field:this:0x00001058, source:raw]
    // RETURN: Return dword_8B009C (conversion-state global) as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   v4 = 0;
    //   v11 = this;
    //   if (this[1042]) {
    //     a4 = DirectXVertexBufferFormatConversion(this, a4);
    //   }
    //   v6 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //   UtilityFunction_7473();
    //   for (i = 0; i < v11[1046]; v4 += 16) {
    //     v10 = (*(float*)(v4 + a4 + 8) * 0.0721
    //          + *(float*)(v4 + a4 + 4) * 0.7154
    //          + *(float*)(v4 + a4) * 0.2125) * 255.0
    //          + *(float*)(v6 + 4 * (i & 3));
    //     *v7++ = (int)v10;
    //     ++i;
    //   }
    //   return dword_8B009C;
    // UNRESOLVED: Globals flt_59FEC8, flt_5ADB18, flt_5ADB1C, flt_5ADB20 are flagged as read (R) in the packet facts but do not appear in the raw decompiled source, which uses inline float literals; their role here cannot be verified.
    // UNRESOLVED: The BT.709 weighting coefficients (0.0721/0.7154/0.2125) and the 255.0 scale are inline literals in the raw source; the per-vertex stride of 16 bytes is DERIVED from the loop increment.
}
