// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00415060
// Canonical corpus name: StructZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInit_00415060.c

void UnknownObject::StructZeroInit()
{
    // Constructor-style initializer that zeroes a 12-dword member struct: writes 0 to every dword from this+0x0 through this+0x2C inclusive, then returns the this pointer. No reads, no globals and no callees.
    // ASSIGNMENT: Zero the twelve contiguous dword members at this+0x0, this+0x4, this+0x8, this+0xC, this+0x10, this+0x14, this+0x18, this+0x1C, this+0x20, this+0x24, this+0x28 and this+0x2C [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, source:raw]
    // RETURN: Return the this pointer as the function result [function:0x00415060, source:raw]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 12; ++i) this[i] = 0;
    //   return this;
    // UNRESOLVED: The owning type of the zeroed struct is unknown; no caller or vtable evidence is present in the packet
}
