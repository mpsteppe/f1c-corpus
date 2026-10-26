// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559A40
// Canonical corpus name: LargeBufferZeroInit_9a40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LargeBufferZeroInit_9a40_00559a40.c

void UnknownObject::LargeBufferZeroInit_9a40()
{
    // Constructor/initializer for a large object buffer: zeroes a 0x180-byte span starting at this+0xC via memset, zeroes the leading fields at 0x0, 0x4 and 0x8, zeroes two trailing fields at 0x30C and 0x310, and returns this.
    // CALL: memset(this + 0xC, 0, 0x180): zero the 0x180-byte body region starting at offset 0xC. [source:raw]
    // ASSIGNMENT: Zero the field at offset 0x0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Zero the field at offset 0x4. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Zero the field at offset 0x8. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Zero the field at offset 0x30C (this[195]). [field:this:0x0000030C, source:raw]
    // ASSIGNMENT: Zero the field at offset 0x310 (this[196]). [field:this:0x00000310, source:raw]
    // RETURN: Return this. [source:raw]
    // CALL: Called by SceneFileTopLevelParser (0x0055B200) and sub_55B8C0 (0x0055B8C0) to initialize a large per-scene buffer object. [caller:0x0055B200, caller:0x0055B8C0, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_559A40(_DWORD *this) {
    //     memset(this + 3, 0, 0x180u);
    //     *this = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[195] = 0;
    //     this[196] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Concrete owning class is unknown; the packet marks owner as UnknownObject/UNKNOWN.
    // UNRESOLVED: The purpose of the trailing fields at 0x30C and 0x310 (outside the memset span) is not evidenced.
}
