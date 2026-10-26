// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508D2D
// Canonical corpus name: TextureColorCacheFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureColorCacheFill_00508d2d.c

void UnknownObject::TextureColorCacheFill()
{
    // Converts four float color channels per vertex into a packed 32-bit RGBA8888 word (scale 128.0 per channel). When this[0x1048] is set, passes the source buffer a4 through DirectXVertexBufferFormatConversion and uses the returned buffer. Computes a channel base pointer from this[0x2C] plus a selector derived from a2/a3, calls UtilityFunction_7473 unconditionally, then writes one 32-bit value per vertex to an output pointer while iterating this[0x1058] vertices. Returns dword_8B009C.
    // GUARD: If this[0x1048] (format-conversion flag) is non-zero, take the format-conversion path. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); its return value replaces a4 as the source buffer. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute channel base v15 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3)). [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473, source:raw]
    // GUARD: Skip the vertex loop entirely when this[0x1058] (vertex count) is zero. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[0x1058] vertices, advancing the source offset v6 by 16 and the counter v17 by 1 per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: Read four floats v11/v12/v13/v14 from (v6 + a4), (v6 + a4 + 4), (v6 + a4 + 8), (v6 + a4 + 12), each scaled by 128.0 and added to shared base v16 = *(float *)(v15 + 4 * (v17 & 3)); pack truncated byte values into one 32-bit RGBA8888 value written via the output pointer. [source:raw]
    // RETURN: Return dword_8B009C. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int TextureColorCacheFill(this, char a2, char a3, int a4) {
    //     if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int base = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     for (i = 0; i < this[0x1058]; i++) {
    //       float c = *(float *)(base + 4 * (i & 3));
    //       int r = (int)(*(float *)(a4 + i*16)     * 128.0 + c);
    //       int g = (int)(*(float *)(a4 + i*16 + 4) * 128.0 + c);
    //       int b = (int)(*(float *)(a4 + i*16 + 8) * 128.0 + c);
    //       int a = (int)(*(float *)(a4 + i*16 + 12) * 128.0 + c);
    //       *out++ = (unsigned char)r | ((unsigned char)g << 8) | ((unsigned char)b << 16) | ((int)a << 24);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Output pointer v5 is used uninitialized in the decompiled text; its provenance is not visible in this packet.
    // UNRESOLVED: Purpose of UtilityFunction_7473 is unknown.
    // UNRESOLVED: Meaning of the a2/a3 low-two-bit selectors that index the channel base is unresolved.
    // UNRESOLVED: flt_59E6FC is listed as an evidence global but does not appear in the raw source; its use here is unproven.
}
