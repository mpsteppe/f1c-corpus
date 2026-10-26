// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485600
// Canonical corpus name: DestructorWithConditionalFree_5600
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_5600_00485600.c

void UnknownObject::ScalarDeletingDtor_5AB130()
{
    // Scalar deleting destructor for the object whose vtable pointer is off_5AB130. Writes the vtable address into this+0, chains to the common cleanup dispatcher InitWithVTableCleanup(this), then frees this itself when bit 0 of the a2 flag is set, and returns this.
    // ASSIGNMENT: Write the vtable pointer off_5AB130 into this+0x0 at entry. [field:this:0x00000000, global:0x005AB130]
    // CALL: Chain to the common destructor/cleanup dispatcher InitWithVTableCleanup(this). [callee:0x00487250]
    // GUARD: Free this itself only when bit 0 of the a2 flag is set (conditional self-delete). [source:raw, function:0x00485600]
    // CALL: Deallocate this via FreeWrapper_7bcf when the a2 guard holds. [callee:0x00587BCF]
    // RETURN: Return this. [source:raw]

    // Conservative worker pseudocode:
    //   LPVOID *sub_485600(LPVOID *this, char a2) {
    //     *this = &off_5AB130;
    //     InitWithVTableCleanup(this);
    //     if (a2 & 1) FreeWrapper_7bcf(this);
    //     return this;
    //   }
    // UNRESOLVED: Identity of the object owning the vtable off_5AB130.
    // UNRESOLVED: What InitWithVTableCleanup(0x00487250) performs beyond this function.
    // UNRESOLVED: Meaning of a2 bits other than bit 0.
}
