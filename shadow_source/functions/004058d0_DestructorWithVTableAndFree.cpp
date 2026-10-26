// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004058D0
// Canonical corpus name: DestructorWithVTableAndFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithVTableAndFree_004058d0.c

void UnknownObject::DestructorWithVTableAndFree()
{
    // Thiscall destructor: overwrites the vtable pointer at this+0x0 with the global vtable off_59E4B4, frees the child allocation pointed to by this+0x4 when non-null, then frees the object itself when deallocation flag bit 0 (a2 & 1) is set. Returns the object pointer.
    // ASSIGNMENT: Set vtable pointer at this+0x0 to off_59E4B4 (swap vtable). [field:this:0x00000000, global:0x0059E4B4]
    // GUARD: Branch when the child allocation pointer at this+0x4 is non-null. [field:this:0x00000004]
    // CALL: Free the child allocation this+0x4 via FreeWrapper_7bcf. [callee:0x00587BCF]
    // GUARD: Branch when deallocation flag bit 0 is set ((a2 & 1) != 0). [abi:lead, source:raw]
    // CALL: Free the object itself via FreeWrapper_7bcf when the flag is set. [callee:0x00587BCF]
    // RETURN: Return the this pointer. [abi:lead, function:0x004058D0]

    // Conservative worker pseudocode:
    //   LPVOID* DestructorWithVTableAndFree(LPVOID* this, char a2) {
    //     this->vtable = &off_59E4B4;
    //     if (this[1])
    //       FreeWrapper_7bcf(this[1]);
    //     if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Concrete class type owning vtable 0x0059E4B4 is not identified.
    // UNRESOLVED: Meaning of a2 flag bits beyond bit 0 (object deallocation) is unknown.
}
