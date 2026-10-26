// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583A80
// Canonical corpus name: Destructor_3a80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Destructor_3a80_00583a80.c

void UnknownObject::scalarDeletingDestructor()
{
    // MSVC-style scalar deleting destructor: invokes the real destructor sub_583AE0 on this, then, if flag a2 has bit 0 set, frees the object via FreeWrapper_7bcf. Returns the this pointer.
    // CALL: Call destructor sub_583AE0 (0x00583AE0) with this as argument. [source:raw, callee:0x00583AE0]
    // GUARD: Check whether (a2 & 1) != 0 before deciding to free. [source:raw]
    // CALL: If the guard holds, call FreeWrapper_7bcf (0x00587BCF) with this to release the object memory. [source:raw, callee:0x00587BCF]
    // RETURN: Return this. [source:raw, function:0x00583A80]

    // Conservative worker pseudocode:
    //   sub_583AE0(this);
    //   if (a2 & 1) FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The concrete type of this (class owning the destructor) is unknown.
    // UNRESOLVED: Whether sub_583AE0 is a plain destructor or performs additional teardown is unproven.
    // UNRESOLVED: Relationship between the class here and the sibling destructor chain (0x00583AE0) is unknown.
}
