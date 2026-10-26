// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004972A6
// Canonical corpus name: ByteFlagSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ByteFlagSetter_004972a6.c

void UnknownObject::ByteFlagSetter()
{
    // Trivial __thiscall byte-flag setter: copies the incoming byte parameter a2 into the byte field at offset 0x25 of this and returns the stored value. Unconditional write, no guards, globals, or callees. Structurally a twin of ByteFieldSetter (00497250), which writes the same offset.
    // ASSIGNMENT: Copy the incoming byte parameter a2 into the local result value. [source:raw]
    // ASSIGNMENT: Store a2 into the byte field at offset 0x25 of this (this[0x25]). [source:raw, field:this:0x00000025]
    // RETURN: Return the stored byte value (result == a2). [source:raw]

    // Conservative worker pseudocode:
    //   char __thiscall sub_4972A6(_BYTE *this, char a2) {
    //     char result = a2;
    //     this[0x25] = a2;
    //     return result;
    //   }
    // UNRESOLVED: Semantic role of the byte field at offset 0x25 (state flag vs. mode selector) is not determinable from this function alone; it is written unconditionally and read elsewhere.
    // UNRESOLVED: No callers are recorded in the packet, so the object type and the purpose of the flag write are unknown.
}
