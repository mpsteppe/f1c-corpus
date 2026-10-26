// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405880
// Canonical corpus name: DestructorWithConditionalFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_00405880.c

void UnknownObject::DestructorWithConditionalFree()
{
    // Scalar-deleting destructor for an unknown object. Invokes the object's destructor body (callee 0x004058A0) on this, then, when the deleting flag a2 has bit 0 set, releases the object's memory via FreeWrapper (0x00587BCF). Returns this unchanged, matching the MSVC scalar-deleting-destructor calling convention.
    // CALL: Call the destructor body at 0x004058A0 (ObjectConstructorWithVTableAndSubFree) with this as the __thiscall receiver. [callee:0x004058A0, abi:lead]
    // GUARD: Guard on the deleting flag a2: when (a2 & 1) != 0 the object memory is freed; otherwise this is returned without freeing. [source:raw]
    // CALL: Call FreeWrapper at 0x00587BCF with this to release the object allocation when the deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this, keeping the object pointer valid as required by the scalar-deleting destructor convention. [function:0x00405880, source:raw]

    // Conservative worker pseudocode:
    //   void* DestructorWithConditionalFree(void* this, char a2) {
    //     ObjectConstructorWithVTableAndSubFree(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: The object class that this destructor belongs to is not evidenced in this packet; the owner is UnknownObject.
    // UNRESOLVED: The callee name ObjectConstructorWithVTableAndSubFree (0x004058A0) is decompiler-derived; its exact vtable/state work is outside this function.
}
