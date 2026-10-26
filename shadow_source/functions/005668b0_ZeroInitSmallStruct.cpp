// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005668B0
// Canonical corpus name: ZeroInitSmallStruct
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ZeroInitSmallStruct_005668b0.c

void UnknownObject::ZeroInitSmallStruct()
{
    // Constructor/initializer for a small 25-byte struct. Zeroes DWORDs at offsets 0x0, 0x4, 0xC, 0x10 and 0x14, sets the DWORD at 0x8 to -1, zeroes the byte at 0x18, and returns the object pointer. No reads, no globals, no calls.
    // ASSIGNMENT: Set DWORD at offset 0x0 to 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Set DWORD at offset 0x4 to 0. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Set DWORD at offset 0x8 to -1. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set DWORD at offset 0xC to 0. [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Set DWORD at offset 0x10 to 0. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Set DWORD at offset 0x14 to 0. [field:this:0x00000014, source:raw]
    // ASSIGNMENT: Set byte at offset 0x18 to 0. [field:this:0x00000018, source:raw]
    // RETURN: Return the object pointer (this). [function:0x005668B0, source:raw]

    // Conservative worker pseudocode:
    //   this[1] = 0;
    //   this[2] = -1;
    //   this[0] = 0;
    //   this[3] = 0;
    //   this[4] = 0;
    //   this[5] = 0;
    //   *((unsigned char*)this + 0x18) = 0;
    //   return this;
    // UNRESOLVED: Struct type and the meaning of the -1 sentinel at offset 0x8 are unknown.
    // UNRESOLVED: Byte at offset 0x18 is initialized last and as a byte; exact field semantics unconfirmed.
}
