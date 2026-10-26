// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508C22
// Canonical corpus name: FloatToByteColorConverter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatToByteColorConverter_00508c22.c

void UnknownObject::VertexColorToRGA24()
{
    // DXT color encoder helper (__thiscall): converts float RGBA vertex data into packed 32-bit words with R, G and A each 8 bits (scales 128.0, 128.0 and 255.0); the B channel is not used. If the format-conversion flag this[1042] (byte 0x1048) is set, a4 is first replaced by the DirectXVertexBufferFormatConversion result. Computes a tile sample base at this[11] (byte 0x2C) offset by the (a2,a3) 4x4 block position, calls UtilityFunction_7473, then loops over this[1046] (byte 0x1058) vertices adding the tile sample to each scaled channel and writing one word per vertex (low byte R, next byte G, third byte A). Returns the conversion-state global dword_8B009C.
    // ASSIGNMENT: Save the this pointer in v17 and initialize the vertex counter v6 to zero. [source:raw]
    // GUARD: Guard on the format-conversion flag this[1042] (byte 0x1048); when non-zero the source vertex buffer is remapped before conversion. [field:this:0x00001048, source:raw]
    // CALL: Invoke DirectXVertexBufferFormatConversion(this, a4), restore this from v17, and replace a4 with the returned converted pointer. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Compute the tile sample base v15 = this[11] (byte 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), encoding the 4x4 block position from the masked a2/a3 indices. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the conversion loop. [callee:0x00507473, source:raw]
    // GUARD: Guard on the vertex count this[1046] (byte 0x1058); when zero the do-while body is skipped. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[1046] (byte 0x1058) vertices, incrementing v6 and advancing the source offset v7 by 16 bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Per vertex, read the tile sample v16 = float at v15 + 4*(v6 & 3) and form each scaled channel: v12 = float at a4+v7 * 128.0 + v16, v13 = float at a4+v7+4 * 128.0 + v16, v14 = float at a4+v7+12 * 255.0 + v16. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Pack the channels into a 32-bit word: low byte v8 = (int)v12, high byte of v9 = (int)v14, low byte of v9 = (int)v13, then write *v5++ = v8 | (v9 << 8); so R occupies the low byte, G the next byte, A the third byte. [source:raw]
    // RETURN: Return the conversion-state global dword_8B009C as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_508C22(_DWORD* this, char a2, char a3, int a4) {
    //     _DWORD* v17 = this;
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int v15 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     unsigned int v6 = 0;
    //     if (v17[1046]) {
    //       int v7 = 0;
    //       do {
    //         float v16 = *(float*)(v15 + 4 * (v6 & 3));
    //         unsigned __int8 v8 = (unsigned __int8)(int)(*(float*)(v7 + a4) * 128.0 + v16);
    //         int v11 = (int)(*(float*)(v7 + a4 + 4) * 128.0 + v16);
    //         unsigned __int16 v9 = (unsigned __int16)((unsigned __int8)(int)(*(float*)(v7 + a4 + 12) * 255.0 + v16) << 8) | (unsigned __int8)v11;
    //         v7 += 16;
    //         *v5++ = v8 | (v9 << 8);
    //         ++v6;
    //       } while (v6 < v17[1046]);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Globals flt_59E6FC (0x0059E6FC) and flt_59FEC8 (0x0059FEC8) are flagged as read (R) in the packet facts but do not appear in the raw decompiled source, which inlines the scale literals 128.0 and 255.0; their role here cannot be verified.
    // UNRESOLVED: Purpose and side effects of UtilityFunction_7473 (0x00507473) are unknown.
    // UNRESOLVED: Meaning of the returned global dword_8B009C (0x008B009C) is unknown.
    // UNRESOLVED: The output word pointer v5 is uninitialized in the raw decompiled source, so the target of the packed writes is not established by the packet.
    // UNRESOLVED: The owning object type, the exact DXT/S3TC format, and the layout of the a2/a3 4x4 block coordinate space are unknown.
}
