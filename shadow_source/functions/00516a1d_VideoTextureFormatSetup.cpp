// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00516A1D
// Canonical corpus name: sub_516A1D
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_516A1D_00516a1d.c

void UnknownObject::VideoTextureFormatSetup()
{
    // Configures video texture/format allocation parameters for a texture-format state object. Verifies the stored width (this+0x10) against the expected constant 202, raising an error through the object vtable when it mismatches. Selects a power-of-two scale factor (8/4/2/1) from the raw width/height ratio, derives scaled allocation dimensions via CeilingDivision, then sizes every format entry in the array at *(this+0xC4): assigns each entry its optimal power-of-two scale and its allocation width/height. Finally resolves the output format count from the format-mode field and validates it via ComplexStateValidator, storing either the reference height (this+0x110) or 1.
    // GUARD: Guard on this+0x10 != 202: when the stored width is not the expected constant, enter the error path. [guard:0, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Error path: set the object behind this+0x0 to error code 18 (obj+0x14) and copy the offending width this+0x10 into obj+0x18. [field:obj:0x00000000, field:obj:0x00000014, field:obj:0x00000018, source:raw]
    // CALL: Error path: invoke the virtual error handler through the object vtable (**(void(__cdecl***)(int))this)(this). [field:obj:0x00000000, field:this:0x00000000, source:raw]
    // CALCULATION: Read raw width (this+0x2C) and raw height (this+0x30) to drive the scale-factor decision. [field:this:0x0000002C, field:this:0x00000030, source:raw]
    // CALCULATION: Select the power-of-two denominator by nested ratio tests (8*width>height, then 4*, then 2*): write this+0x5C = CeilingDivision(this+0x18, denom), compute scaled height via CeilingDivision(this+0x1C, denom), and store the denominator 8/4/2/1 at this+0x114. [callee:0x00515917, field:this:0x00000018, field:this:0x0000001C, field:this:0x0000005C, field:this:0x00000114, source:raw]
    // ASSIGNMENT: Store the scaled allocation height to this+0x60. [field:this:0x00000060, source:raw]
    // GUARD: Guard on this+0x20 <= 0 (guard:1) and this+0x20 > 0 (guard:2): the two per-entry loops run only when the entry count is positive. [guard:1, guard:2, field:this:0x00000020, source:raw]
    // LOOP: Per-entry optimal-scale loop over the array at *(this+0xC4) (entry pointer +12, stride 0x54): start i at this+0x114 and double up to 8, stopping when 2*i*entryWidth (entry+0x0C) exceeds i*this+0x10C or 2*i*entryHeight exceeds i*this+0x110; write the winning i into entry+0x24. [field:this:0x000000C4, field:*(this+0xC4):0x0000000C, field:*(this+0xC4):0x00000024, field:this:0x00000114, field:this:0x0000010C, field:this:0x00000110, source:raw]
    // LOOP: Per-entry alloc-size loop over the same array (entry pointer +36): write entry+0x28 = CeilingDivision(this+0x18 * entryWidth * entry[-7], 8*this+0x10C) and entry+0x2C = CeilingDivision(entryWidth * this+0x1C * entry[-6], 8*this+0x110). [callee:0x00515917, field:*(this+0xC4):0x00000028, field:*(this+0xC4):0x0000002C, field:this:0x00000018, field:this:0x0000001C, field:this:0x0000010C, field:this:0x00000110, source:raw]
    // CALCULATION: Resolve the output format count from the format mode this+0x28: mode 1 -> 1, modes 2/3 -> 3, modes 4/5 -> 4, otherwise the entry count this+0x20; write it to this+0x64. [field:this:0x00000028, field:this:0x00000064, field:this:0x00000020, source:raw]
    // ASSIGNMENT: Write this+0x68 = (byte at this+0x4A) ? 1 : (this+0x64). [field:this:0x0000004A, field:this:0x00000064, field:this:0x00000068, source:raw]
    // CALL: ComplexStateValidator(v14, this) validates the resolved format; on success write this+0x6C = this+0x110, otherwise this+0x6C = 1. [callee:0x005169AC, field:this:0x00000110, field:this:0x0000006C, source:raw]
    // RETURN: Return the validator result (v16). Called by sub_516C7B. [function:0x00516A1D, caller:0x00516C7B, source:raw]

    // Conservative worker pseudocode:
    //   char sub_516A1D(int this) {
    //     if (*(DWORD*)(this+16) != 202) {
    //       *(DWORD*)(*(DWORD*)this + 20) = 18;
    //       *(DWORD*)(*(DWORD*)this + 24) = *(DWORD*)(this+16);
    //       (**(void (__cdecl ***)(int))this)(this);
    //     }
    //     int w = *(DWORD*)(this+44), h = *(DWORD*)(this+48), allocH, denom;
    //     if (8*w > h) {
    //       if (4*w > h) {
    //         if (2*w > h) { *(DWORD*)(this+92) = *(DWORD*)(this+24); allocH = *(DWORD*)(this+28); denom = 8; }
    //         else { *(DWORD*)(this+92) = CeilingDivision(*(DWORD*)(this+24), 2); allocH = CeilingDivision(*(DWORD*)(this+28), 2); denom = 4; }
    //       } else { *(DWORD*)(this+92) = CeilingDivision(*(DWORD*)(this+24), 4); allocH = CeilingDivision(*(DWORD*)(this+28), 4); denom = 2; }
    //     } else { *(DWORD*)(this+92) = CeilingDivision(*(DWORD*)(this+24), 8); allocH = CeilingDivision(*(DWORD*)(this+28), 8); denom = 1; }
    //     *(DWORD*)(this+276) = denom; *(DWORD*)(this+96) = allocH;
    //     if (*(DWORD*)(this+32) > 0) {
    //       for (k = 0; k < *(DWORD*)(this+32); ++k) {
    //         DWORD *e = (DWORD*)(*(DWORD*)(this+196) + 12 + k*0x54);
    //         int i;
    //         for (i = denom; i < 8; i *= 2) {
    //           if (2*i*e[-1] > i**(DWORD*)(this+268)) break;
    //           if (2*i*e[0] > i**(DWORD*)(this+272)) break;
    //         }
    //         e[6] = i;
    //       }
    //       for (k = 0; k < *(DWORD*)(this+32); ++k) {
    //         DWORD *e = (DWORD*)(*(DWORD*)(this+196) + 36 + k*0x54);
    //         e[1] = CeilingDivision(*(DWORD*)(this+24)*e[0]*e[-7], 8**(DWORD*)(this+268));
    //         e[2] = CeilingDivision(e[0]**(DWORD*)(this+28)*e[-6], 8**(DWORD*)(this+272));
    //       }
    //     }
    //     int fmt = *(DWORD*)(this+40), fmtCount;
    //     if (fmt == 1) fmtCount = 1;
    //     else if (fmt == 2 || fmt == 3) fmtCount = 3;
    //     else if (fmt >= 4 && fmt <= 5) fmtCount = 4;
    //     else fmtCount = *(DWORD*)(this+32);
    //     *(DWORD*)(this+100) = fmtCount;
    //     *(DWORD*)(this+104) = *(BYTE*)(this+74) ? 1 : fmtCount;
    //     char ok = ComplexStateValidator(fmtCount, this);
    //     *(DWORD*)(this+108) = ok ? *(DWORD*)(this+272) : 1;
    //     return ok;
    //   }
    // UNRESOLVED: The legacy ABI label Audio_Sample_Rate_Conversion contradicts the video-texture semantics of the body; the packet carries it with LEGACY trust and it is not reflected in the operation model.
    // UNRESOLVED: The validator argument v14 passed to ComplexStateValidator is the 1/3 candidate (not the entry-count/4 fallback stored at this+0x64); the precise role of v14 versus the stored count is not grounded by the packet.
    // UNRESOLVED: The object behind this+0x0 (used only on the width-mismatch error path) has no type evidence in this packet.
    // UNRESOLVED: Field this+0x110 is both a scale-comparison bound and the value stored to this+0x6C on validator success; whether these are two independent meanings is DERIVED.
}
