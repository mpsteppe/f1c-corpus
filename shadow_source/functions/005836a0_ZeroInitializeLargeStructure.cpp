// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005836A0
// Canonical corpus name: LargeStructureZeroInitialization
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeStructureZeroInitialization_005836a0.c

void UnknownObject::ZeroInitializeLargeStructure()
{
    // Constructor/initializer that zero-fills a large object: clears dwords at offsets 0x0, 0x4, 0x8, 0x10, 0x14, 0x18, 0x1C, the byte at 0xC, zeroes a 0xFC-byte block from this[8] with memset, then clears the word at offset 0x11C, the byte at offset 0x11E and the dword at offset 0x120. Returns this. Called by sub_5837F0 (0x005837F0).
    // ASSIGNMENT: Zero the first three dwords this[0], this[1], this[2] (offsets 0x0, 0x4, 0x8). [source:raw, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Zero the byte at offset 0xC. [source:raw, field:this:0x0000000C]
    // ASSIGNMENT: Zero dwords this[4], this[5], this[6], this[7] (offsets 0x10, 0x14, 0x18, 0x1C). [source:raw, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C]
    // CALL: memset(this + 8, 0, 0xFC): zero the 0xFC-byte dword block starting at this[8]. [source:raw]
    // ASSIGNMENT: Zero the word at offset 0x11C (this[142] as _WORD*). [source:raw, field:this:0x0000011C]
    // ASSIGNMENT: Zero the byte at offset 0x11E (this[286] as _BYTE*). [source:raw, field:this:0x0000011E]
    // ASSIGNMENT: Zero the dword at offset 0x120 (this[72]). [source:raw, field:this:0x00000120]
    // RETURN: Return the this pointer. [source:raw, function:0x005836A0]

    // Conservative worker pseudocode:
    //   _DWORD* sub_5836A0(_DWORD* this) {
    //     this[0] = 0; this[1] = 0; this[2] = 0;
    //     *((_BYTE*)this + 12) = 0;
    //     this[4] = 0; this[5] = 0; this[6] = 0; this[7] = 0;
    //     memset(this + 8, 0, 0xFC);
    //     *((_WORD*)this + 142) = 0;
    //     *((_BYTE*)this + 286) = 0;
    //     this[72] = 0;
    //     return this;
    //   }
    // UNRESOLVED: The owning object type and the meaning of the fields being zeroed (offsets 0x0..0x120) are unknown; this packet only shows the initialization writes.
    // UNRESOLVED: Relationship of the 0xFC-byte memset block to the explicitly cleared fields at 0x11C/0x11E/0x120 is not established.
}
