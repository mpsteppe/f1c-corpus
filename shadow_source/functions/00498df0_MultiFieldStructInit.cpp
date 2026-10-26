// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498DF0
// Canonical corpus name: MultiFieldStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiFieldStructInit_00498df0.c

void UnknownObject::MultiFieldStructInit()
{
    // Constructor/initializer on an unknown object. Sets eight dword fields to literals (0x48, 0x4C, 0x50, 0x58, 0x5C, 0x60, 0x64, 0x68) with only field +0x60 initialized to 1 and the rest to 0, then zero-fills two 0x28-byte regions starting at this+0x6C and this+0x94. No reads, no globals, no callees; always returns 0. Invoked by InitWithVTableParam (00498D20) as a member initialization helper.
    // ASSIGNMENT: Initialize the first three dword fields to 0: this+0x48, this+0x4C, this+0x50 [field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, source:raw]
    // ASSIGNMENT: Initialize the next block of dword fields: this+0x64 and this+0x68 set to 0, this+0x58 set to 0, this+0x60 set to 1, this+0x5C set to 0 (write order follows the raw source) [field:this:0x00000064, field:this:0x00000068, field:this:0x00000058, field:this:0x00000060, field:this:0x0000005C, source:raw]
    // ASSIGNMENT: Zero-fill a 0x28u-byte block starting at this+27 dwords (this+0x6C) [source:raw]
    // ASSIGNMENT: Zero-fill a second 0x28u-byte block starting at this+37 dwords (this+0x94) [source:raw]
    // RETURN: Return the fixed value 0; called by InitWithVTableParam (00498D20) during object setup [caller:0x00498D20, function:0x00498DF0, source:raw]

    // Conservative worker pseudocode:
    //   this[0x48/4] = 0;
    //   this[0x4C/4] = 0;
    //   this[0x50/4] = 0;
    //   this[0x64/4] = 0;
    //   this[0x68/4] = 0;
    //   this[0x58/4] = 0;
    //   this[0x60/4] = 1;
    //   this[0x5C/4] = 0;
    //   memset(this + 27, 0, 0x28u);
    //   memset(this + 37, 0, 0x28u);
    //   return 0;
    // UNRESOLVED: The owning class is unknown; the field at this+0x60 initialized to 1 while its neighbors are zeroed has no documented meaning from this packet
    // UNRESOLVED: The two 0x28u-byte zero-fill regions (this+0x6C and this+0x94) are not represented in the packet field table and have no evidence references of their own
}
