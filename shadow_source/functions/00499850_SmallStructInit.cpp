// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00499850
// Canonical corpus name: SmallStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SmallStructInit_00499850.c

void UnknownObject::SmallStructInit()
{
    // Struct initializer (__thiscall): writes literal 3 into the first dword at offset 0x0, a zero byte at offset 0x4, then zeroes three dwords at offsets 0x8, 0xC, 0x10, 0x14. No reads, no globals, no callees. Returns 0.
    // ASSIGNMENT: Write literal 3 to dword at this+0x0 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write literal 0 to byte at this+0x4 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write literal 0 to dword at this+0x8 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write literal 0 to dword at this+0xC [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write literal 0 to dword at this+0x10 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write literal 0 to dword at this+0x14 [field:this:0x00000014, source:raw]
    // RETURN: Return constant 0 [function:0x00499850, source:raw]

    // Conservative worker pseudocode:
    //   int SmallStructInit(byte* this) {
    //     *(dword*)(this + 0x0) = 3;
    //     this[4] = 0;
    //     *(dword*)(this + 0x8) = 0;
    //     *(dword*)(this + 0xC) = 0;
    //     *(dword*)(this + 0x10) = 0;
    //     *(dword*)(this + 0x14) = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Field at this+0x4 is written as a single byte (this[4]) while all other fields are written as dwords; the struct layout/purpose is unknown.
    // UNRESOLVED: Semantic role of the literal 3 at offset 0x0 is unknown.
}
