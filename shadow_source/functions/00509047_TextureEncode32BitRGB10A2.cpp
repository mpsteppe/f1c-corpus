// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00509047
// Canonical corpus name: TextureEncode32BitRGB10A2
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureEncode32BitRGB10A2_00509047.c

void UnknownObject::TextureEncode32BitRGB10A2()
{
    // Encodes per-vertex float color data into packed 32-bit RGB10A2 format: after an optional DirectXVertexBufferFormatConversion, computes a per-sub-tile float offset, calls UtilityFunction_7473, then for this[1046] vertices scales the R/G/B channels by 512.0, adds the shared offset, truncates, masks each to 10 bits (0x3FF), doubles the alpha channel, packs the four channels into one dword written via v5, and returns dword_8B009C.
    // GUARD: Guard on the format-conversion flag: if this[0x1048] (this[1042]) is non-zero, DirectXVertexBufferFormatConversion(this, a4) is called and its result replaces a4 as the source vertex pointer. [field:this:0x00001048, callee:0x00506CE2, source:raw]
    // CALCULATION: v15 = this[0x2C] (this[11]) + 4 * ((a3 & 3) + 8 * (a2 & 3)); the masked a2/a3 sub-tile indices select a per-sub-tile float offset stored below the this base. [field:this:0x0000002C, source:raw]
    // CALL: UtilityFunction_7473() is called unconditionally after computing v15; its purpose is unknown. [callee:0x00507473, source:raw]
    // LOOP: do-while loop over this[0x1058] (this[1046]) vertices: per vertex read four floats at a4 with a 16-byte stride, scale R/G/B by 512.0 (presumed flt_5ACCB4), add the shared sub-tile offset v16, truncate to int and mask with 0x3FF (10 bits), double the alpha channel by adding it to itself, then pack the result as an RGB10A2 dword. [field:this:0x00001058, global:0x005ACCB4, source:raw]
    // RETURN: Returns dword_8B009C (global 0x008B009C); the meaning of the returned value is not established. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int TextureEncode32BitRGB10A2(this, a2, a3, a4) {
    //     if (this[1042]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     v15 = this[11] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     for (v17 = 0; v17 < this[1046]; v17++) {
    //       v16 = *(float*)(v15 + 4 * (v17 & 3));
    //       R = (int)(*(float*)(a4 + v6) * 512.0 + v16) & 0x3FF;
    //       G = (int)(*(float*)(a4 + v6 + 4) * 512.0 + v16) & 0x3FF;
    //       B = (int)(*(float*)(a4 + v6 + 8) * 512.0 + v16) & 0x3FF;
    //       A = (int)(*(float*)(a4 + v6 + 12) + *(float*)(a4 + v6 + 12) + v16);
    //       *v5++ = R | ((G | (((A << 10) | B) << 10)) << 10);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: The write target v5 (DWORD* in edx) is used uninitialized in the decompiled source; the actual destination buffer of the packed RGB10A2 dwords is unknown.
    // UNRESOLVED: The semantics of dword_8B009C (0x008B009C) as a return value (state flag / HResult-style) are not established.
    // UNRESOLVED: flt_5ACCB4 (0x005ACCB4) is presumed to hold the 512.0 scale constant, but the binding is inferred, not proven.
}
