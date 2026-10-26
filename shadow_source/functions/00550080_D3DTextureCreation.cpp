// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550080
// Canonical corpus name: D3DTextureCreation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/D3DTextureCreation_00550080.c

void UnknownObject::D3DTextureCreation()
{
    // D3D texture creation entry point with mip-level computation and size scaling. Computes mip levels from the requested dimensions via base-2 logarithms, caps/clamps them against the stored mip field at this+0x50, halves the dimensions while the mip count is being reduced (subject to the flag bit at this+0x44 and the sound manager's size limits), selects a texture format from argument flags and device capability queries, optionally sets a colour key, writes the computed mip count into the texture descriptor, and calls the underlying creation routine. On any failure it runs the destructor path and returns -1.
    // CALL: Call sub_54FE50 on this receiver with the name argument a2 (initial string handling). [callee:0x0054FE50]
    // GUARD: Call sub_5427D0(a2, &v22, &v21, 0) to parse dimensions; if it returns -1 jump to the destructor error path. [callee:0x005427D0]
    // CALL: On failure call DestructorWithConditionalFreeFlagClear on this receiver. [callee:0x005502C0]
    // RETURN: Return -1 on the failure path. [source:raw]
    // CALCULATION: Compute mip levels: v7 = round(log2(v22)), v8 = round(log2(v21)) via CRTFtol applied to __FYL2X__ times 1.442695036924675 plus 0.5. [callee:0x00587BDC]
    // GUARD: Guard on the stored mip value at this+0x50 being zero or greater than the computed levels; if so, take the smaller of v7/v8 as the new mip count and store it at this+0x50. [field:this:0x00000050]
    // GUARD: Guard on bit 0 of the flags byte at this+0x44 being clear before entering the size-scaling block. [field:this:0x00000044]
    // CALL: Query the sound manager: SimpleFieldGetter_bfc0(dword_8B78A0) for an index and IndexedArrayAccess_d890(dword_8B78A0, index) for the limit entry. [callee:0x0055BFC0, global:0x008B78A0, callee:0x0053D890]
    // LOOP: Halve v22/v21 while either exceeds the limit entry's dimensions at offsets 284 and 288, decrementing the mip field at this+0x50 each step (floor of 1) and incrementing the scale counter v5. [field:this:0x00000050]
    // GUARD: If the scale counter stayed zero, apply the global mip-LOD bias dword_8B8E4C: halve v22/v21 that many times while also decrementing the mip field at this+0x50 (floor of 1). [global:0x008B8E4C, field:this:0x00000050]
    // GUARD: Guard on the format flag: if (a4 & unk_800000) is non-zero select the direct format index 8. [global:0x00800000]
    // GUARD: Guard on renderer state: if dword_8B8E2C is zero or MaskedFieldGetter(dword_8B78A0) is zero, take the fallback format-selection path. [global:0x008B8E2C, callee:0x0055C9A0, global:0x008B78A0]
    // GUARD: If flag bit 0x800 of a4 is set select format index 5. [source:raw]
    // GUARD: If flag bit 0x40000 of a4 is set jump to the KeyEventDispatchToSubHandlers(0x200000) format path. [source:raw]
    // CALL: Fallback: GetVTableParamBasedOnFlagBits(dword_8B8DC8) selects the format via the render device pointer. [callee:0x0055C3C0, global:0x008B8DC8]
    // GUARD: If bit 0 of the flags byte at this+0x44 is clear and both v22 and v21 are at least 8, select format index 9. [field:this:0x00000044]
    // CALL: Call KeyEventDispatchToSubHandlers(0x200000) to obtain the format on the 0x40000-flag path. [callee:0x0055C7F0]
    // GUARD: If flag bit 0x800 of a4 is set, call sub_5435C0 on the texture object at this+0x54 with a3, defaulting to 16711935 when a3 is zero (colour-key write). [field:this:0x00000054, callee:0x005435C0]
    // ASSIGNMENT: Write the mip count from this+0x50 into the texture descriptor field at offset 44 of the object pointed to by this+0x54. [field:*(this+0x54):0x0000002C, field:this:0x00000050, field:this:0x00000054]
    // CALCULATION: If dword_8B8E28 is zero, OR flag 0x1000000 into the format argument v17. [global:0x008B8E28]
    // GUARD: Call sub_5429B0(texture object at this+0x54, a2, v22, v21, format, v17); a non-zero return jumps to the destructor error path. [callee:0x005429B0, field:this:0x00000054]
    // ASSIGNMENT: Copy the mip count back from the descriptor field at offset 44 into this+0x50. [field:this:0x00000050, field:*(this+0x54):0x0000002C, field:this:0x00000054]
    // RETURN: Return 0 on the success path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_550080(int this, const char* a2, int a3, int a4) {
    //     int v21, v22;
    //     sub_54FE50((const CHAR*)this, a2);
    //     if (sub_5427D0((int)a2, (int)&v22, (int)&v21, 0) == -1) {
    //       DestructorWithConditionalFreeFlagClear(this); return -1;
    //     }
    //     v7 = CRTFtol(__FYL2X__(v22, 0.6931471805599453094) * 1.442695036924675 + 0.5);
    //     v8 = CRTFtol(__FYL2X__(v21, 0.6931471805599453094) * 1.442695036924675 + 0.5);
    //     if (!*(this+0x50) || *(this+0x50) > v7 || *(this+0x50) > v8) {
    //       if (v7 < v8) v8 = v7;
    //       *(this+0x50) = v8;
    //     }
    //     if ((*(this+0x44) & 1) == 0) {
    //       v11 = IndexedArrayAccess_d890(dword_8B78A0, SimpleFieldGetter_bfc0(dword_8B78A0));
    //       if (v11) {
    //         while (v22 > *(v11+284) || v21 > *(v11+288)) {
    //           v22 >>= 1; v21 >>= 1; ++v5;
    //           if (*(this+0x50) > 1) --*(this+0x50);
    //         }
    //         if (!v5 && dword_8B8E4C) {
    //           v16 = *(this+0x50);
    //           do { v22 >>= 1; v21 >>= 1; if (v16 > 1) --v16; } while (--dword_8B8E4C);
    //           *(this+0x50) = v16;
    //         }
    //       }
    //     }
    //     if ((a4 & unk_800000) != 0) v18 = 8;
    //     else if (!dword_8B8E2C || !MaskedFieldGetter(dword_8B78A0)) {
    //       if ((a4 & 0x800) != 0) v18 = 5;
    //       else if ((a4 & 0x40000) == 0) v18 = GetVTableParamBasedOnFlagBits(dword_8B8DC8);
    //       else v18 = KeyEventDispatchToSubHandlers(0x200000);
    //     } else {
    //       if ((*(this+0x44) & 1) == 0 && v22 >= 8 && v21 >= 8) v18 = 9;
    //       else if ((a4 & 0x800) != 0) v18 = 5;
    //       else if ((a4 & 0x40000) == 0) v18 = GetVTableParamBasedOnFlagBits(dword_8B8DC8);
    //       else v18 = KeyEventDispatchToSubHandlers(0x200000);
    //     }
    //     if ((a4 & 0x800) != 0) sub_5435C0(*(this+0x54), a3 ? a3 : 16711935);
    //     *(*(this+0x54)+44) = *(this+0x50);
    //     if (!dword_8B8E28) v17 = a4 | 0x1000000;
    //     if (sub_5429B0(*(this+0x54), a2, v22, v21, v18, v17)) {
    //       DestructorWithConditionalFreeFlagClear(this); return -1;
    //     }
    //     *(this+0x50) = *(*(this+0x54)+44);
    //     return 0;
    //   }
    // UNRESOLVED: Globals dbl_59E880, dbl_5B8908, dword_8B8DC8's exact role and the meaning of the descriptor field at offset 44 of the this+0x54 object are not fully established.
    // UNRESOLVED: The format indices 5, 8, 9 and the flag masks 0x800, 0x40000, 0x200000, 0x1000000 have no authoritative enum mapping.
}
