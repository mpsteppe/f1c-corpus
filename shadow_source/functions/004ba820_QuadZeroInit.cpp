// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BA820
// Canonical corpus name: QuadZeroInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/QuadZeroInit_004ba820.c

void UnknownObject::QuadZeroInit()
{
    // Thiscall initializer that zeroes the first four DWORD fields of an object (offsets 0x0, 0x4, 0x8, 0xC) and returns the object pointer. Structural twin of sub_4A1F60. Called by CarPhysicsStateInitializer (004B57F0) and sub_5837F0.
    // ASSIGNMENT: Clear DWORD at this+0x0 to 0. [field:this:0x00000000]
    // ASSIGNMENT: Clear DWORD at this+0x4 to 0. [field:this:0x00000004]
    // ASSIGNMENT: Clear DWORD at this+0x8 to 0. [field:this:0x00000008]
    // ASSIGNMENT: Clear DWORD at this+0xC to 0. [field:this:0x0000000C]
    // RETURN: Return the object pointer this. [source:raw]

    // Conservative worker pseudocode:
    //   void* sub_4BA820(DWORD *this) {
    //     this[0] = 0;
    //     this[1] = 0;
    //     this[2] = 0;
    //     this[3] = 0;
    //     return this;
    //   }
    // UNRESOLVED: Semantic meaning of the four zeroed fields and the object type are unknown; callers indicate a car-physics-related context.
}
