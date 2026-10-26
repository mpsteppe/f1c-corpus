// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005423E0
// Canonical corpus name: ColorPack
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ColorPack_005423e0.c

void UnknownObject::ColorPack()
{
    // Packs three byte-like components a2, a3, a4 into a single dword as (a2 << 16) | (a3 << 8) | a4, stores the packed value at this[31] (dword offset 0x7C), and returns it. Unconditional: no guards. Callers are anonymous (sub_548AD0, sub_55A060, sub_560C10); the owning render/UI object is unknown.
    // CALCULATION: Pack the three components into one dword: result = a4 + ((a3 + (a2 << 8)) << 8), which places a2 in the most significant byte position. [source:raw]
    // ASSIGNMENT: Store the packed color value at this[31], the dword at offset 0x7C. [field:this:0x0000007C, source:raw]
    // RETURN: Return the packed color value. [source:raw]

    // Conservative worker pseudocode:
    //   int ColorPack(int* this, int r, int g, int b) {
    //     int packed = b + ((g + (r << 8)) << 8);
    //     this[31] = packed;
    //     return packed;
    //   }
    // UNRESOLVED: The channel order is unconfirmed: a2 occupies the most significant byte, so the assignment of R/G/B among a2, a3, a4 is not established.
    // UNRESOLVED: Callers are anonymous and the owning object is unknown, so the meaning of offset 0x7C in the caller's object is unresolved.
    // UNRESOLVED: No guard is present; the packed value is always written to offset 0x7C and returned.
}
