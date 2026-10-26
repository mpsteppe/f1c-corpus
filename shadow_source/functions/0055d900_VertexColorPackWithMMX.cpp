// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0055D900
// Canonical corpus name: sub_55D900
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_55D900_0055d900.c

void UnknownObject::VertexColorPackWithMMX()
{
    // Two-path vertex color fill. When bit 0x20 at byte this[1]+156 is set, copies a color dword per vertex directly from the source array (base this[3], stride 48) into the destination array (base this[8], stride 64) at offset +24. Otherwise computes colors through D3D-device vtable methods at offsets +24 and +20 (device at dword_8B8F24, context at dword_8B8F28), scales alpha at this[1]+80 by 255.0, packs RGBA via MMX _m_packuswb against qword_8B6C20, and writes the single packed color to every vertex of the destination array.
    // GUARD: Bit 0x20 at byte this[1]+156 selects the direct copy path. [field:this:0x00000004, source:raw]
    // GUARD: Vertex count this[2] is greater than zero. [guard:0, field:this:0x00000008]
    // LOOP: Copy the color dword at offset +24 from source vertex i (base this[3], stride 48) to destination vertex i (base this[8], stride 64) for count = this[2]. [field:this:0x0000000C, field:this:0x00000020, field:this:0x00000008]
    // CALL: Invoke D3D-device vtable method at offset +24 on dword_8B8F24 (context dword_8B8F28, node pointer at dword_8B8F28 + 288, render state this[1]), storing result in v15. [global:0x008B8F24, global:0x008B8F28, field:this:0x00000004]
    // CALL: Invoke D3D-device vtable method at offset +20 on dword_8B8F24 (render state this[1]), storing result in v14. [global:0x008B8F24, field:this:0x00000004]
    // CALCULATION: Scale alpha at this[1]+80 by 255.0 (constant flt_59FEC8) and combine with the v14/v15 channel sums. [global:0x0059FEC8, field:this:0x00000004]
    // CALCULATION: Pack the combined color components to bytes via MMX _m_packuswb against qword_8B6C20 and extract with _mm_cvtsi64_si32; clear MMX state with _m_empty. [global:0x008B6C20]
    // GUARD: Vertex count this[2] is greater than zero (computed-color path). [guard:0, field:this:0x00000008]
    // LOOP: Write the single packed color to offset +24 of every vertex in the destination array (base this[8], stride 64) for count = this[2]. [field:this:0x00000020, field:this:0x00000008]
    // RETURN: Return the final count / result value. [function:0x0055D900, source:raw]

    // Conservative worker pseudocode:
    //   int sub_55D900(_DWORD *this, int a2) {
    //     if (*(_BYTE*)(this[1] + 156) & 0x20) {
    //       int n = this[2];
    //       for (int i = 0; i < n; i++)
    //         *(_DWORD*)(this[8] + i*64 + 24) = *(_DWORD*)(this[3] + i*48 + 24);
    //       return n;
    //     }
    //     int ctx = *(_DWORD*)(dword_8B8F28 + 288);
    //     (*(void (__thiscall **)(int, int, int, _DWORD, float*))(*(_DWORD*)dword_8B8F24 + 24))(
    //         dword_8B8F24, dword_8B8F28, ctx, this[1], v15);
    //     (*(void (__thiscall **)(int, int, _DWORD, float*))(*(_DWORD*)dword_8B8F24 + 20))(
    //         dword_8B8F24, ctx, this[1], v14);
    //     __m64 v13 = pack16s((short)((float)*(float*)(this[1] + 80) * 255.0),
    //         (short)(v14[0] + v15[0]), (short)(v14[1] + v15[1]), (short)(v14[2] + v15[2]));
    //     int color = _mm_cvtsi64_si32(_m_packuswb(v13, qword_8B6C20));
    //     _m_empty();
    //     int n = this[2];
    //     for (int i = 0; i < n; i++)
    //       *(_DWORD*)(this[8] + i*64 + 24) = color;
    //     return n;
    //   }
    // UNRESOLVED: Fields this+0x54 and this+0xA0 are listed by static extraction but are not accessed in this function body; their roles are unconfirmed.
    // UNRESOLVED: The two indirect D3D vtable calls (offsets +24 and +20) are dispatched through dword_8B8F24 and have no resolved callee address in this packet.
    // UNRESOLVED: Exact meaning of the direct-copy path when bit 0x20 is set (same-structure copy vs. lighting bypass) is not proven.
}
