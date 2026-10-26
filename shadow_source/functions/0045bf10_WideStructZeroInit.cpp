// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BF10
// Canonical corpus name: WideStructZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/WideStructZeroInit_0045bf10.c

void UnknownObject::WideStructZeroInit()
{
    // Initializer that zeroes scattered DWORD fields of a wide object and clears a 0x28-byte middle region with a single memset. Returns 0.
    // ASSIGNMENT: Zero the DWORD at offset 0x8. [field:this:0x00000008]
    // ASSIGNMENT: Zero the DWORD at offset 0xC. [field:this:0x0000000C]
    // CALCULATION: memset the 0x28-byte block starting at dword index 4 (byte offset 0x10) to zero, clearing the middle region. [source:raw]
    // ASSIGNMENT: Zero the tail DWORDs at offsets 0x38, 0x3C, 0x40, 0x44, 0x48, 0x4C and 0x50. [field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int WideStructZeroInit(DWORD* this) {
    //     this[2] = 0;
    //     this[3] = 0;
    //     memset(this + 4, 0, 0x28);
    //     this[14] = 0;
    //     this[15] = 0;
    //     this[16] = 0;
    //     this[17] = 0;
    //     this[18] = 0;
    //     this[19] = 0;
    //     this[20] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: Owner object and the meaning of the head (0x8/0xC), memset-covered middle and tail (0x38..0x50) regions are unknown.
    // UNRESOLVED: Whether this is a constructor or a reset invoked during AVIPlayerCleanup (0x0045BED6) is unknown.
}
