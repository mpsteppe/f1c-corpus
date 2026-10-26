// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004856F0
// Canonical corpus name: ObjectConstructor_56f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ObjectConstructor_56f0_004856f0.c

void UnknownObject::DestructorWithConditionalFree_5A9660()
{
    // Scalar-deleting destructor for the object whose vtable is off_5A9660. Writes the vtable into this[0], runs the common InitWithVTableCleanup teardown, then frees this when the a2 bit 0 (scalar-deletion) flag is set.
    // ASSIGNMENT: Set this[0] to &off_5A9660, installing the object vtable. [field:this:0x00000000, global:0x005A9660]
    // CALL: Invoke common cleanup/teardown dispatcher InitWithVTableCleanup on this. [callee:0x00487250]
    // GUARD: When (a2 & 1) != 0, the scalar-deleting flag is set. [source:raw]
    // CALL: Free this via FreeWrapper_7bcf when the scalar-deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this. [function:0x004856F0]

    // Conservative worker pseudocode:
    //   this[0] = &off_5A9660;
    //   InitWithVTableCleanup(this);
    //   if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The concrete object type owning off_5A9660 is not established by static evidence alone.
    // UNRESOLVED: Despite the packet's declared_name, the raw source shows the same teardown-plus-conditional-free shape as a scalar-deleting destructor, not a plain constructor.
}
