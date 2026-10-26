// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7020
// Canonical corpus name: StructInitWithSentinels
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithSentinels_004d7020.c

void UnknownObject::StructInitWithSentinels()
{
    // Constructor/initializer for a small struct. Clears fields at 0x0, 0xC, 0x14 and 0x18 to zero, writes a -1 sentinel into 0x4 and 0x1C, then runs ArrayBlockCleanup(this) as a final array-reset pass and returns the object pointer. Invoked by TireBrandLoader while building the tire brand table.
    // ASSIGNMENT: Zero the field at this+0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write the -1 sentinel into the field at this+0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the field at this+0xC. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Zero the field at this+0x14. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Zero the field at this+0x18. [field:this:0x00000018, source:raw]
    // ASSIGNMENT: Write the -1 sentinel into the field at this+0x1C. [field:this:0x0000001C, source:raw]
    // CALL: Run ArrayBlockCleanup(this) on the same object as a final cleanup pass. [callee:0x004D7050, source:raw]
    // RETURN: Return the this pointer (fluid-style constructor result). [source:raw]
    // CALL: Invoked by TireBrandLoader during tire brand table construction. [caller:0x004D7660, source:raw]

    // Conservative worker pseudocode:
    //   DWORD *sub_4D7020(DWORD *this) {
    //     this[1] = -1;
    //     this[0] = 0;
    //     this[7] = -1;
    //     this[6] = 0;
    //     this[3] = 0;
    //     this[5] = 0;
    //     ArrayBlockCleanup(this);
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the -1 sentinels at 0x4/0x1C and of the ArrayBlockCleanup array reset is not established from this packet.
}
