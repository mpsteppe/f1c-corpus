// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A430
// Canonical corpus name: CollisionObjectInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CollisionObjectInit_0044a430.c

void UnknownObject::CollisionObjectInit()
{
    // Collision-object constructor/initializer: zeroes this+0x0 and this+0x4, sets the 16-bit fields at this+0x8 to -3 and this+0xA to -1, zeroes this+0xC, and returns the this pointer. Pure literal writes; no reads, globals, or calls.
    // ASSIGNMENT: Set this[0] (this+0x0) to 0. [field:this:0x00000000]
    // ASSIGNMENT: Set this[1] (this+0x4) to 0. [field:this:0x00000004]
    // ASSIGNMENT: Set the 16-bit field at this+0x8 (word index 4) to -3. [field:this:0x00000008]
    // ASSIGNMENT: Set the 16-bit field at this+0xA (word index 5) to -1. [field:this:0x0000000A]
    // ASSIGNMENT: Set this[3] (this+0xC) to 0. [field:this:0x0000000C]
    // RETURN: Return the this pointer as the initialization result. [source:raw]
    // CALL: Invoked as an object initializer from sub_44BC50 (0x0044BC50) and HTreeTerrainFileFormatLoader (0x0044BE70). [caller:0x0044BC50, caller:0x0044BE70]

    // Conservative worker pseudocode:
    //   _DWORD *CollisionObjectInit(_DWORD *this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     *((_WORD *)this + 4) = -3;
    //     *((_WORD *)this + 5) = -1;
    //     this[3] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Object type for `this` is unconfirmed (UnknownObject); trust kept UNKNOWN.
    // UNRESOLVED: Meaning of the -3/-1 word sentinels at this+0x8 / this+0xA is not interpreted.
}
