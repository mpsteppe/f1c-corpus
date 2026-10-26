// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508B1D
// Canonical corpus name: VertexColorTransform_8b1d
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexColorTransform_8b1d_00508b1d.c

void UnknownObject::VertexColorToRGA565()
{
    // DXT color encoder helper (__thiscall): converts float RGBA vertex data into packed 16-bit words with R in the low 5 bits (scale 16.0), G in the middle 5 bits (scale 16.0) and A in the high 6 bits (scale 63.0); the B channel is not used. If the format-conversion flag this[1042] (byte 0x1048) is set, a4 is first replaced by the DirectXVertexBufferFormatConversion result. Computes a tile sample base at this[11] (byte 0x2C) offset by the (a2,a3) 4x4 block position, calls UtilityFunction_7473, then loops over this[1046] (byte 0x1058) vertices adding the tile sample to each scaled channel and writing one word per vertex. Returns the conversion-state global dword_8B009C.
    // ASSIGNMENT: Save the this pointer in v16 and initialize the vertex counter v4 to zero. [source:raw]
    // GUARD: Guard on the format-conversion flag this[1042] (byte 0x1048); when non-zero the source vertex buffer is remapped before conversion. [field:this:0x00001048, source:raw]
    // CALL: Invoke DirectXVertexBufferFormatConversion(this, a4), restore this from v16, and replace a4 with the returned converted pointer. [callee:0x00506CE2, field:this:0x00001048, source:raw]
    // CALCULATION: Compute the tile sample base v14 = this[11] (byte 0x2C) + 4 * ((a3 & 3) + 8 * (a2 & 3)), encoding the 4x4 block position from the masked a2/a3 indices. [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the conversion loop. [callee:0x00507473, source:raw]
    // GUARD: Guard on the vertex count this[1046] (byte 0x1058); when zero the do-while body is skipped. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[1046] (byte 0x1058) vertices, incrementing v4 and advancing the source offset v7 by 16 bytes per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Per vertex, read the tile sample v15 = float at v14 + 4*(v4 & 3) and form each scaled channel: v11 = float at a4+v7 * 16.0 + v15, v12 = float at a4+v7+4 * 16.0 + v15, v13 = float at a4+v7+12 * 63.0 + v15; mask the R and G results to 5 bits (0x1F). [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Assemble and write the packed word *v6++ = (v8 & 0x1F) | (32 * ((32 * (int)v13) | (v9 & 0x1F))): R in the low 5 bits, G in the middle 5 bits, A in the high 6 bits. [source:raw]
    // RETURN: Return the conversion-state global dword_8B009C as the function result. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int sub_508B1D(_DWORD* this, char a2, char a3, int a4) {
    //     unsigned int v4 = 0; _DWORD* v16 = this;
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int v14 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     if (v16[1046]) {
    //       int v7 = 0;
    //       do {
    //         float v15 = *(float*)(v14 + 4 * (v4 & 3));
    //         char v8 = (char)(int)(*(float*)(v7 + a4) * 16.0 + v15);
    //         char v9 = (char)(int)(*(float*)(v7 + a4 + 4) * 16.0 + v15);
    //         *v6++ = (unsigned __int16)(v8 & 0x1F | (32 * ((32 * (int)(*(float*)(v7 + a4 + 12) * 63.0 + v15)) | (v9 & 0x1F))));
    //         ++v4; v7 += 16;
    //       } while (v4 < v16[1046]);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Globals flt_59EED0 (0x0059EED0) and flt_5ACCD8 (0x005ACCD8) are flagged as read (R) in the packet facts but do not appear in the raw decompiled source, which inlines the scale literals 16.0 and 63.0; their role here cannot be verified.
    // UNRESOLVED: Purpose and side effects of UtilityFunction_7473 (0x00507473) are unknown.
    // UNRESOLVED: Meaning of the returned global dword_8B009C (0x008B009C) is unknown.
    // UNRESOLVED: The output word pointer v6 is uninitialized in the raw decompiled source, so the target of the packed writes is not established by the packet.
    // UNRESOLVED: The owning object type, the exact DXT/S3TC format, and the layout of the a2/a3 4x4 block coordinate space are unknown.
}
