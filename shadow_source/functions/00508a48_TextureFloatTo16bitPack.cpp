// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00508A48
// Canonical corpus name: TextureFloatTo16bitPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextureFloatTo16bitPack_00508a48.c

void UnknownObject::TextureFloatTo16bitPack()
{
    // Converts two float color channels per vertex into a packed 16-bit word with two 8-bit channels (scale 128.0 per channel). When this[0x1048] is set, passes the source buffer a4 through DirectXVertexBufferFormatConversion and uses the returned buffer. Computes a channel base pointer from this[0x2C] plus a selector derived from a2/a3, calls UtilityFunction_7473 unconditionally, then writes one 16-bit word per vertex to an output pointer while iterating this[0x1058] vertices. Returns dword_8B009C.
    // GUARD: If this[0x1048] (format-conversion flag) is non-zero, take the format-conversion path. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); its return value replaces a4 as the source buffer. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute channel base v5 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3)). [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473, source:raw]
    // GUARD: Skip the vertex loop entirely when this[0x1058] (vertex count) is zero. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[0x1058] vertices, advancing the source offset v8 by 16 and the counter v7 by 1 per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: v12 = *(float *)(v8 + a4) * 128.0 + *(float *)(v5 + 4 * (v7 & 3)); v11 = *(float *)(v8 + a4 + 4) * 128.0 + *(float *)(v5 + 4 * (v7 & 3)); store LOBYTE(v12) as low byte and HIBYTE(v11) as high byte of one 16-bit word via the output pointer. [source:raw]
    // RETURN: Return dword_8B009C. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int TextureFloatTo16bitPack(this, char a2, char a3, int a4) {
    //     if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int base = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     for (i = 0; i < this[0x1058]; i++) {
    //       char lo = (int)(*(float *)(a4 + i*16) * 128.0 + *(float *)(base + 4 * (i & 3)));
    //       char hi = (int)(*(float *)(a4 + i*16 + 4) * 128.0 + *(float *)(base + 4 * (i & 3)));
    //       *out++ = (unsigned char)lo | ((unsigned char)hi << 8);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Output pointer v6 is used uninitialized in the decompiled text; its provenance is not visible in this packet.
    // UNRESOLVED: Purpose of UtilityFunction_7473 is unknown.
    // UNRESOLVED: Meaning of the a2/a3 low-two-bit selectors that index the channel base is unresolved.
    // UNRESOLVED: flt_59E6FC is listed as an evidence global but does not appear in the raw source; its use here is unproven.
}
