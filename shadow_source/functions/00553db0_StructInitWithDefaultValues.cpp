// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00553DB0
// Canonical corpus name: StructInitWithDefaultValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithDefaultValues_00553db0.c

void UnknownObject::StructInitWithDefaultValues()
{
    // Constructor-style initializer on a _DWORD this pointer: writes 7 to the field at byte offset 0x20 and zeroes the seven adjacent DWORD fields at offsets 0x24, 0x28, 0x2C, 0x30, 0x34, 0x38 and 0x3C, then returns the this pointer. Called by seven sites including AudioBufferFormatSetup and StructZeroInitConstructor.
    // ASSIGNMENT: Set the DWORD field at byte offset 0x20 (index 8) to the literal 7. [field:this:0x00000020, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x24 (index 9) to 0. [field:this:0x00000024, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x28 (index 10) to 0. [field:this:0x00000028, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x2C (index 11) to 0. [field:this:0x0000002C, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x30 (index 12) to 0. [field:this:0x00000030, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x34 (index 13) to 0. [field:this:0x00000034, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x38 (index 14) to 0. [field:this:0x00000038, source:raw]
    // ASSIGNMENT: Set the DWORD field at byte offset 0x3C (index 15) to 0. [field:this:0x0000003C, source:raw]
    // RETURN: Return the this pointer. [function:0x00553DB0, source:raw]

    // Conservative worker pseudocode:
    //   this[8] = 7;
    //   this[9] = 0;
    //   this[10] = 0;
    //   this[11] = 0;
    //   this[12] = 0;
    //   this[13] = 0;
    //   this[14] = 0;
    //   this[15] = 0;
    //   return this;
    // UNRESOLVED: The object type and the semantic meaning of the literal 7 at offset 0x20 are unknown.
    // UNRESOLVED: Only offsets 0x20-0x3C of the struct are touched; the full struct layout is unknown.
    // UNRESOLVED: The relationship between the seven caller sites and this initializer's purpose is unexplored.
}
