// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F6F00
// Canonical corpus name: StructZeroInit_6f00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructZeroInit_6f00_004f6f00.c

void UnknownObject::StructZeroInit_6f00()
{
    // Constructor/initializer on an unknown object. Zeroes the first 0x20 bytes of the object: byte 0x0 and byte 0x10 are cleared as BYTE writes, dword fields at 0x4, 0x8, 0xC, 0x14, 0x18 and 0x1C are cleared as DWORD writes. No reads, no globals, no callees. Returns the original this pointer. Invoked by sub_4F6F20 (004F6F20).
    // ASSIGNMENT: Clear byte at this+0x0 and dword fields at this+0x4, this+0x8, this+0xC to 0 [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Clear byte at this+0x10 and dword fields at this+0x14, this+0x18, this+0x1C to 0 [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return the this pointer as the result; called by sub_4F6F20 (004F6F20) [caller:0x004F6F20, function:0x004F6F00, source:raw]

    // Conservative worker pseudocode:
    //   *(BYTE *)this = 0;
    //   this[0x4/4] = 0;
    //   this[0x8/4] = 0;
    //   this[0xC/4] = 0;
    //   *((BYTE *)this + 16) = 0;
    //   this[0x14/4] = 0;
    //   this[0x18/4] = 0;
    //   this[0x1C/4] = 0;
    //   return this;
    // UNRESOLVED: The owning class is unknown; byte-width clears at offsets 0x0 and 0x10 versus dword-width clears elsewhere suggest mixed-size fields, but their purpose is not documented in this packet
}
