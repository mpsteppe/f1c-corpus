// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00550760
// Canonical corpus name: StructInitWithScaleDefaults
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StructInitWithScaleDefaults_00550760.c

void UnknownObject::StructInitWithScaleDefaults()
{
    // Constructor-style initializer: zero-initializes the object via GlobalZeroInit_c2a0, clears a one-byte flag at this+0x44, writes -1 into the first dword at this+0x0 (identity/invalid marker), memsets the 0x40 dwords from this[1] to zero, then assigns the scale-default 1.0f literals to this[1], this[6], this[11] and this[16] (offsets 0x4, 0x18, 0x2C, 0x40), clears dword this[33] (offset 0x84), and returns this.
    // CALL: Call GlobalZeroInit_c2a0(this) to zero-initialize the object. [callee:0x0053C2A0]
    // ASSIGNMENT: Clear the one-byte flag at this+0x44 to 0. [field:this:0x00000044]
    // ASSIGNMENT: Write -1 into the first dword at this+0x0 (identity/invalid marker). [field:this:0x00000000]
    // CALCULATION: Zero the 0x40 dwords from this[1] onward via memset. [source:raw]
    // ASSIGNMENT: Set dword this[6] (offset 0x18) to the float literal 1.0f. [field:this:0x00000018]
    // ASSIGNMENT: Set dword this[11] (offset 0x2C) to the float literal 1.0f. [field:this:0x0000002C]
    // ASSIGNMENT: Set dword this[16] (offset 0x40) to the float literal 1.0f. [field:this:0x00000040]
    // ASSIGNMENT: Set dword this[1] (offset 0x4) to the float literal 1.0f. [field:this:0x00000004]
    // ASSIGNMENT: Clear dword this[33] (offset 0x84) to 0. [field:this:0x00000084]
    // RETURN: Return the initialized this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void *StructInitWithScaleDefaults(void *this) {
    //     GlobalZeroInit_c2a0(this);
    //     *(BYTE *)((char *)this + 0x44) = 0;
    //     *(DWORD *)this = -1;
    //     memset((DWORD *)this + 1, 0, 0x40u);
    //     ((DWORD *)this)[6] = 1.0f;   // offset 0x18
    //     ((DWORD *)this)[11] = 1.0f;  // offset 0x2C
    //     ((DWORD *)this)[16] = 1.0f;  // offset 0x40
    //     ((DWORD *)this)[1] = 1.0f;   // offset 0x4
    //     ((DWORD *)this)[33] = 0;     // offset 0x84
    //     return this;
    //   }
    // UNRESOLVED: Identity of the object type and the semantic role of the -1 at this+0x0 and the four 1.0f scale fields are not established by this packet alone.
    // UNRESOLVED: The purpose of the cleared byte flag at this+0x44 is unknown.
}
