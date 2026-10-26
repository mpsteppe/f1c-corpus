// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005426A0
// Canonical corpus name: AudioEmitterCreate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioEmitterCreate_005426a0.c

void UnknownObject::AudioEmitterCreate()
{
    // Constructor-style initializer for an audio emitter object. Calls GlobalZeroInit_c2a0(this) to zero-initialize the object, then explicitly clears all fourteen dwords at offsets 0x0 through 0x34, with two non-zero defaults: this[11] (offset 0x2C) set to 1 and this[12] (offset 0x30) set to 6. Returns the initialized this pointer.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the object. [callee:0x0053C2A0]
    // ASSIGNMENT: Clear dword this[6] (offset 0x18) to 0. [field:this:0x00000018]
    // ASSIGNMENT: Clear dword this[0] (offset 0x0) to 0. [field:this:0x00000000]
    // ASSIGNMENT: Clear dword this[10] (offset 0x28) to 0. [field:this:0x00000028]
    // ASSIGNMENT: Clear dword this[9] (offset 0x24) to 0. [field:this:0x00000024]
    // ASSIGNMENT: Clear dword this[8] (offset 0x20) to 0. [field:this:0x00000020]
    // ASSIGNMENT: Clear dword this[7] (offset 0x1C) to 0. [field:this:0x0000001C]
    // ASSIGNMENT: Clear dword this[13] (offset 0x34) to 0. [field:this:0x00000034]
    // ASSIGNMENT: Clear dword this[1] (offset 0x4) to 0. [field:this:0x00000004]
    // ASSIGNMENT: Clear dword this[2] (offset 0x8) to 0. [field:this:0x00000008]
    // ASSIGNMENT: Clear dword this[3] (offset 0xC) to 0. [field:this:0x0000000C]
    // ASSIGNMENT: Clear dword this[4] (offset 0x10) to 0. [field:this:0x00000010]
    // ASSIGNMENT: Clear dword this[5] (offset 0x14) to 0. [field:this:0x00000014]
    // ASSIGNMENT: Set dword this[11] (offset 0x2C) to the non-zero default 1. [field:this:0x0000002C]
    // ASSIGNMENT: Set dword this[12] (offset 0x30) to the non-zero default 6. [field:this:0x00000030]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void *AudioEmitterCreate(void *this) {
    //     GlobalZeroInit_c2a0(this);
    //     ((DWORD *)this)[6] = 0;   // offset 0x18
    //     *(DWORD *)this = 0;       // offset 0x0
    //     ((DWORD *)this)[10] = 0;  // offset 0x28
    //     ((DWORD *)this)[9] = 0;   // offset 0x24
    //     ((DWORD *)this)[8] = 0;   // offset 0x20
    //     ((DWORD *)this)[7] = 0;   // offset 0x1C
    //     ((DWORD *)this)[13] = 0;  // offset 0x34
    //     ((DWORD *)this)[1] = 0;   // offset 0x4
    //     ((DWORD *)this)[2] = 0;   // offset 0x8
    //     ((DWORD *)this)[3] = 0;   // offset 0xC
    //     ((DWORD *)this)[4] = 0;   // offset 0x10
    //     ((DWORD *)this)[5] = 0;   // offset 0x14
    //     ((DWORD *)this)[11] = 1;  // offset 0x2C
    //     ((DWORD *)this)[12] = 6;  // offset 0x30
    //     return this;
    //   }
    // UNRESOLVED: The object type and the semantic roles of the two non-zero defaults this[11]=1 (offset 0x2C) and this[12]=6 (offset 0x30) are not established by this packet alone.
    // UNRESOLVED: GlobalZeroInit_c2a0 already zeroes the object, so the explicit zero writes may be redundant or may document per-field contracts not visible in this packet.
}
