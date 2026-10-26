// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040ACC6
// Canonical corpus name: TripleFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TripleFieldSetter_0040acc6.c

void UnknownObject::TripleFieldSetter()
{
    // Bulk-assigns the same DWORD value a2 to three consecutive fields at this+0x0C, +0x10 and +0x14, then returns the this pointer. Unconditional; no guards, calls or globals. Every call overwrites all three fields.
    // ASSIGNMENT: Write a2 to this[3] (offset 0x0C). [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write a2 to this[4] (offset 0x10). [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write a2 to this[5] (offset 0x14). [field:this:0x00000014, source:raw]
    // RETURN: Return the this pointer (result). [function:0x0040ACC6, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_40ACC6(DWORD *result, int a2) {
    //     result[3] = a2; // +0x0C
    //     result[4] = a2; // +0x10
    //     result[5] = a2; // +0x14
    //     return result;
    //   }
    // UNRESOLVED: The semantics of a2 (flag, enum state, or scalar) and of the three overwritten fields are not described in the packet.
    // UNRESOLVED: The owning class of this method and its callers are unknown; the packet labels the owner UnknownObject and lists no callers.
}
