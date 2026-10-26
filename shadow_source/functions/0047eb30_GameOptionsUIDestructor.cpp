// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047EB30
// Canonical corpus name: sub_47EB30
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47EB30_0047eb30.c

void UnknownObject::GameOptionsUIDestructor()
{
    // Destructor/cleanup for a game-options UI object: frees the dynamically allocated field at +0xEC when non-null, reinitializes the object through ConstructorWithVTableSet, then conditionally deallocates the whole object when the low bit of the flag argument is set. Returns the this pointer.
    // GUARD: Guard on field +0xEC being non-null before freeing it. [field:this:0x000000EC, source:raw]
    // CALL: Call FreeWrapper_7bcf on the field at +0xEC when it is non-null to release the owned resource. [callee:0x00587BCF, field:this:0x000000EC, source:raw]
    // CALL: Reinitialize the object by calling ConstructorWithVTableSet on this after owned resources are freed. [callee:0x00488B30, source:raw]
    // GUARD: Guard on flag bit 0 of argument a2 being set to decide whether to deallocate the object. [source:raw]
    // CALL: When flag bit 0 is set, call FreeWrapper_7bcf on this to deallocate the object itself. [callee:0x00587BCF, source:raw]
    // RETURN: Return the this pointer. [source:raw]

    // Conservative worker pseudocode:
    //   void *GameOptionsUIDestructor(void *this, char a2) {
    //     if (this[59]) FreeWrapper_7bcf(this[59]);
    //     ConstructorWithVTableSet(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Object type behind this is unknown; +0xEC resource semantics inferred only from the free-before-reinit pattern.
    // UNRESOLVED: Meaning of flag argument a2 beyond bit 0 (object deallocation) is unknown.
}
