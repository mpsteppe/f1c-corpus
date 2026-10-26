// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051CD3E
// Canonical corpus name: PhysicsObjectStateSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsObjectStateSetter_0051cd3e.c

void UnknownObject::PhysicsObjectStateSetter()
{
    // Loads the sub-object pointer at a1+0x19C, clears its byte flag at +0x24 to 0, copies the DWORD at a1+0x60 into the sub-object's +0x2C, and returns the sub-object pointer.
    // ASSIGNMENT: result = *(a1 + 0x19C): load the pointer to the physics/vehicle sub-object. [field:this:0x0000019C, source:raw]
    // ASSIGNMENT: Clear the sub-object byte state flag: *(result + 0x24) = 0. [field:*(this+0x19C):0x00000024, source:raw]
    // ASSIGNMENT: Copy the source value into the sub-object: *(result + 0x2C) = *(a1 + 0x60). [field:*(this+0x19C):0x0000002C, field:this:0x00000060, source:raw]
    // RETURN: Return the sub-object pointer (result). [source:raw]

    // Conservative worker pseudocode:
    //   int PhysicsObjectStateSetter(int a1) {
    //     int sub = *(int*)(a1 + 0x19C);
    //     *(char*)(sub + 0x24) = 0;
    //     *(int*)(sub + 0x2C) = *(int*)(a1 + 0x60);
    //     return sub;
    //   }
    // UNRESOLVED: Owner object type is unknown; the fill labels the sub-object as a physics/vehicle sub-struct (DERIVED).
    // UNRESOLVED: Meaning of the cleared flag at +0x24 and of the copied DWORD at +0x2C is not confirmed.
}
