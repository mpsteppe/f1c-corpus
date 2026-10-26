// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004EC050
// Canonical corpus name: F_6FieldStructInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_6FieldStructInit_004ec050.c

void UnknownObject::F_6FieldStructInit()
{
    // Copies six parameters into the six consecutive dword fields of the object (offsets 0x0 through 0x14) and returns parameter a6. Structural twin of CollisionFaceVerticesGather (0044af20). Called from VehicleContactForceAccumulation (0x004EBC60); on the frame path.
    // ASSIGNMENT: Write *this (offset 0x0) = a2 [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Write this[1] (offset 0x4) = a3 [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Write this[2] (offset 0x8) = a4 [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Write this[3] (offset 0xC) = a5 [field:this:0x0000000C, source:raw]
    // ASSIGNMENT: Write this[4] (offset 0x10) = a6 [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Write this[5] (offset 0x14) = a7 [field:this:0x00000014, source:raw]
    // CALL: Invoked from VehicleContactForceAccumulation (0x004EBC60) [caller:0x004EBC60]
    // RETURN: Return a6 as the result [function:0x004EC050, source:raw]

    // Conservative worker pseudocode:
    //   int F_6FieldStructInit(DWORD* this, int a2, int a3, int a4, int a5, int a6, int a7) {
    //     this[0] = a2;
    //     this[1] = a3;
    //     this[2] = a4;
    //     this[3] = a5;
    //     this[4] = a6;
    //     this[5] = a7;
    //     return a6;
    //   }
    // UNRESOLVED: Semantic meaning of each stored value is unknown; the packet provides only the copy operation.
    // UNRESOLVED: Twin relationship to CollisionFaceVerticesGather (0044af20) is DERIVED, not confirmed as the same class.
}
