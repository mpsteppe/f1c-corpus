// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004144D0
// Canonical corpus name: StructInitWithSentinelValues
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithSentinelValues_004144d0.c

void UnknownObject::StructInitWithSentinelValues()
{
    // Constructor/initializer that writes sentinel defaults into seven dword fields of the pointed object: -1 at offsets 0x0, 0x10, 0x14, 0x18 and 0x1C, -1.0 (stored as -1082130432) at 0x8, and 0 at 0xC. Returns the constant -1. No reads, no globals, no branches, no calls.
    // ASSIGNMENT: Write -1 into the dword at offset 0x0 of the object. [field:this:0x00000000]
    // ASSIGNMENT: Write the float -1.0 (bit pattern stored as the dword -1082130432) into the dword at offset 0x8. [field:this:0x00000008]
    // ASSIGNMENT: Write 0 into the dword at offset 0xC. [field:this:0x0000000C]
    // ASSIGNMENT: Write -1 into the dword at offset 0x10. [field:this:0x00000010]
    // ASSIGNMENT: Write -1 into the dword at offset 0x14. [field:this:0x00000014]
    // ASSIGNMENT: Write -1 into the dword at offset 0x18. [field:this:0x00000018]
    // ASSIGNMENT: Write -1 into the dword at offset 0x1C. [field:this:0x0000001C]
    // RETURN: Return the constant -1 (the same value written into the first field). [source:raw, function:0x004144D0]

    // Conservative worker pseudocode:
    //   *this = -1;
    //   this[2] = -1.0f;
    //   this[3] = 0;
    //   this[4] = -1;
    //   this[5] = -1;
    //   this[6] = -1;
    //   this[7] = -1;
    //   return -1;
    // UNRESOLVED: The type of the pointed object is unknown; owner is UnknownObject.
    // UNRESOLVED: Semantic meaning of each sentinel field (-1 dwords, -1.0f float, zero dword) is unknown.
    // UNRESOLVED: Dword at offset 0x4 (this[1]) is deliberately not initialized by this function.
}
