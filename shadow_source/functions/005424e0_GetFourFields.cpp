// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005424E0
// Canonical corpus name: sub_5424E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5424E0_005424e0.c

void UnknownObject::GetFourFields()
{
    // Reads four DWORD fields of the object and writes them through caller-supplied output pointers. a2 receives this[26] (offset 0x68), a3 receives this[25] (offset 0x64), a4 receives this[21] (offset 0x54) and a5 receives this[22] (offset 0x58); every output pointer is individually null-guarded, and the function returns the a5 output pointer.
    // GUARD: Guard the a2 output pointer: when a2 is non-null, write this[26] (field this + 0x68) into *a2; otherwise skip. [field:this:0x00000068, source:raw]
    // GUARD: Guard the a3 output pointer: when a3 is non-null, write this[25] (field this + 0x64) into *a3; otherwise skip. [field:this:0x00000064, source:raw]
    // GUARD: Guard the a4 output pointer: when a4 is non-null, write this[21] (field this + 0x54) into *a4; otherwise skip. [field:this:0x00000054, source:raw]
    // GUARD: Guard the a5 output pointer: when a5 is non-null, write this[22] (field this + 0x58) into *a5; otherwise skip. [field:this:0x00000058, source:raw]
    // RETURN: Return the a5 output pointer. [source:raw]

    // Conservative worker pseudocode:
    //   if (a2) *a2 = this[26];
    //   if (a3) *a3 = this[25];
    //   if (a4) *a4 = this[21];
    //   if (a5) *a5 = this[22];
    //   return a5;
    // UNRESOLVED: The viewport-dimension interpretation of the four fields (this+0x54 width, this+0x58 height, this+0x64/0x68 aliases) comes from the existing analysis fill at DERIVED trust and is not independently evidenced, so it is not adopted.
    // UNRESOLVED: The semantic role of the object and of fields this[21], this[22], this[25], this[26] is not established by the packet.
    // UNRESOLVED: The callers 0x004DC960, 0x00554B20 and 0x0055C070 are not resolved to a shared context, so the owner type remains unknown.
}
