// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049A250
// Canonical corpus name: PatternedFieldInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PatternedFieldInit_0049a250.c

void UnknownObject::PatternedFieldInit()
{
    // Initializes seven consecutive dword fields (this+0x0 through this+0x18) with an alternating 0, -1 pattern: 0, -1, 0, -1, 0, -1, 0. No reads, no globals, no callees; returns this. Matches the template prelabel category ctor_init.
    // ASSIGNMENT: Write the alternating pattern 0, -1, 0, -1, 0, -1, 0 into dwords this+0x0, this+0x4, this+0x8, this+0xC, this+0x10, this+0x14 and this+0x18. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, source:raw]
    // RETURN: Return this (result is the object pointer itself). [function:0x0049A250, source:raw]

    // Conservative worker pseudocode:
    //   this[0] = 0; this[1] = -1;
    //   this[2] = 0; this[3] = -1;
    //   this[4] = 0; this[5] = -1;
    //   this[6] = 0;
    //   return this;
    // UNRESOLVED: The semantic meaning of the alternating 0/-1 field pattern (e.g. an on/off or two-state flag array) is not evidenced.
    // UNRESOLVED: The owning object type is unknown; the single caller ResourceLookupOrCreate (0x0049A3B0) is not evidenced as the only usage.
    // UNRESOLVED: The legacy ABI lead name describes the literal write pattern, not a semantic role.
}
