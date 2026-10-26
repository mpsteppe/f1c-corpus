// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485660
// Canonical corpus name: DestructorWithConditionalFree_5660
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_5660_00485660.c

void UnknownObject::DestructorWithConditionalFree_5AAFD0()
{
    // Scalar-deleting destructor for the object whose vtable is off_5AAFD0. Writes the vtable into this[0], runs the common InitWithVTableCleanup teardown, then frees this when the a2 bit 0 (scalar-deletion) flag is set.
    // ASSIGNMENT: Set this[0] to &off_5AAFD0, installing the object vtable. [field:this:0x00000000, global:0x005AAFD0]
    // CALL: Invoke common cleanup/teardown dispatcher InitWithVTableCleanup on this. [callee:0x00487250]
    // GUARD: When (a2 & 1) != 0, the scalar-deleting flag is set. [source:raw]
    // CALL: Free this via FreeWrapper_7bcf when the scalar-deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this. [function:0x00485660]

    // Conservative worker pseudocode:
    //   this[0] = &off_5AAFD0;
    //   InitWithVTableCleanup(this);
    //   if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The concrete object type owning off_5AAFD0 is not established by static evidence alone.
    // UNRESOLVED: What InitWithVTableCleanup tears down beyond the vtable write is outside this function.
}
