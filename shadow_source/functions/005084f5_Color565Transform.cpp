// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005084F5
// Canonical corpus name: Color565Transform
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Color565Transform_005084f5.c

void UnknownObject::Color565Transform()
{
    // Converts two float color channels per vertex into a packed 32-bit word with two 16-bit channels (scale 65535.0 per channel). When this[0x1048] is set, passes the source buffer a4 through DirectXVertexBufferFormatConversion and uses the returned buffer. Computes a channel base pointer from this[0x2C] plus a selector derived from a2/a3, calls UtilityFunction_7473 unconditionally, then writes one 32-bit value per vertex to an output pointer while iterating this[0x1058] vertices. Returns dword_8B009C.
    // GUARD: If this[0x1048] (format-conversion flag) is non-zero, take the format-conversion path. [field:this:0x00001048, source:raw]
    // CALL: Call DirectXVertexBufferFormatConversion(this, a4); its return value replaces a4 as the source buffer. [callee:0x00506CE2, source:raw]
    // CALCULATION: Compute channel base v6 = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3)). [field:this:0x0000002C, source:raw]
    // CALL: Call UtilityFunction_7473() unconditionally before the vertex loop. [callee:0x00507473, source:raw]
    // GUARD: Skip the vertex loop entirely when this[0x1058] (vertex count) is zero. [field:this:0x00001058, source:raw]
    // LOOP: do-while loop over this[0x1058] vertices, advancing the source offset v8 by 16 and the counter v4 by 1 per iteration. [field:this:0x00001058, source:raw]
    // CALCULATION: v11 = *(float *)(v8 + a4) * 65535.0 + *(float *)(v6 + 4 * (v4 & 3)); v10 = *(float *)(v8 + a4 + 4) * 65535.0 + *(float *)(v6 + 4 * (v4 & 3)); store (int)v11 | ((int)v10 << 16) as one 32-bit value via the output pointer. [source:raw]
    // RETURN: Return dword_8B009C. [global:0x008B009C, source:raw]

    // Conservative worker pseudocode:
    //   int Color565Transform(this, char a2, char a3, int a4) {
    //     if (this[0x1048]) a4 = DirectXVertexBufferFormatConversion(this, a4);
    //     int base = this[0x2C] + 4 * ((a3 & 3) + 8 * (a2 & 3));
    //     UtilityFunction_7473();
    //     for (i = 0; i < this[0x1058]; i++) {
    //       float lo = *(float *)(a4 + i*16) * 65535.0 + *(float *)(base + 4 * (i & 3));
    //       float hi = *(float *)(a4 + i*16 + 4) * 65535.0 + *(float *)(base + 4 * (i & 3));
    //       *out++ = (int)lo | ((int)hi << 16);
    //     }
    //     return dword_8B009C;
    //   }
    // UNRESOLVED: Output pointer v7 is used uninitialized in the decompiled text; its provenance is not visible in this packet.
    // UNRESOLVED: Purpose of UtilityFunction_7473 is unknown.
    // UNRESOLVED: Meaning of the a2/a3 low-two-bit selectors that index the channel base is unresolved.
    // UNRESOLVED: flt_59F120 is listed as an evidence global but does not appear in the raw source; its use here is unproven.
}
