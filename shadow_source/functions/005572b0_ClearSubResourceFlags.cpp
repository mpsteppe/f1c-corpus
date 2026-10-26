// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005572B0
// Canonical corpus name: sub_5572B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5572B0_005572b0.c

void UnknownObject::ClearSubResourceFlags()
{
    // Zeros a per-element flag dword at byte offset 520 in each of four arrays of sub-resource records (element stride 132 dwords, 528 bytes). Each array is guarded by its element count and driven by its base pointer. No calls; used during render/scene cleanup.
    // GUARD: First array element count at this+0x1B4 is non-zero. [field:this:0x000001B4]
    // LOOP: Zero the flag dword at byte offset 520 of each element of the first array (base pointer at this+0x1B8, element stride 132 dwords). [field:this:0x000001B4, field:this:0x000001B8]
    // GUARD: Second array element count at this+0x1C4 is non-zero. [field:this:0x000001C4]
    // LOOP: Zero the flag dword at byte offset 520 of each element of the second array (base pointer at this+0x1C8, element stride 132 dwords). [field:this:0x000001C4, field:this:0x000001C8]
    // GUARD: Third array element count at this+0x1BC is non-zero. [field:this:0x000001BC]
    // LOOP: Zero the flag dword at byte offset 520 of each element of the third array (base pointer at this+0x1C0, element stride 132 dwords). [field:this:0x000001BC, field:this:0x000001C0]
    // GUARD: Fourth array element count at this+0x1CC is non-zero. [field:this:0x000001CC]
    // LOOP: Zero the flag dword at byte offset 520 of each element of the fourth array (base pointer at this+0x1D0, element stride 132 dwords). [field:this:0x000001CC, field:this:0x000001D0]
    // RETURN: Return the last array pointer / result value. [function:0x005572B0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_5572B0(_DWORD *this) {
    //     int v1 = this[109];
    //     if (v1) { _DWORD *p = (_DWORD*)(this[110] + 520); do { *p = 0; p += 132; } while (--v1); }
    //     int v3 = this[113];
    //     if (v3) { _DWORD *p = (_DWORD*)(this[114] + 520); do { *p = 0; p += 132; } while (--v3); }
    //     int v5 = this[111];
    //     _DWORD *r = (_DWORD*)this[112];
    //     if (v5) { r += 130; do { *r = 0; r += 132; } while (--v5); }
    //     int v7 = this[115];
    //     if (v7) { _DWORD *p = (_DWORD*)(this[116] + 520); int n = v7; do { *p = 0; p += 132; } while (--n); }
    //     return r;
    //   }
    // UNRESOLVED: Fields this+0x3C0, this+0x3D0 and this+0x3D8 are listed by static extraction but are not accessed in this function body; their roles are unconfirmed.
    // UNRESOLVED: Element type and the meaning of the zeroed flag at byte offset 520 depend on the caller's record layout, not visible here.
}
