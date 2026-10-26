// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00485B20
// Canonical corpus name: ScalarDeletingDestructor
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScalarDeletingDestructor_00485b20.c

void UnknownObject::ScalarDeletingDestructor()
{
    // Scalar-deleting destructor: frees two sub-resources pointed to by this[95] (offset 0x17C) and this[93] (offset 0x174) when non-null, runs the base cleanup FunctionCallWrapper_9440, then frees this when the a2 bit 0 (scalar-deletion) flag is set.
    // GUARD: Test this[95] (offset 0x17C) for non-null before freeing the first sub-resource. [field:this:0x0000017C]
    // CALL: Free the sub-resource at this[95] via FreeWrapper_7bcf when non-null. [field:this:0x0000017C, callee:0x00587BCF]
    // GUARD: Test this[93] (offset 0x174) for non-null before freeing the second sub-resource. [field:this:0x00000174]
    // CALL: Free the sub-resource at this[93] via FreeWrapper_7bcf when non-null. [field:this:0x00000174, callee:0x00587BCF]
    // CALL: Run base-class/common cleanup FunctionCallWrapper_9440 on this. [callee:0x00489440]
    // GUARD: When (a2 & 1) != 0, the scalar-deleting flag is set. [source:raw]
    // CALL: Free this via FreeWrapper_7bcf when the scalar-deleting flag is set. [callee:0x00587BCF]
    // RETURN: Return this. [function:0x00485B20]

    // Conservative worker pseudocode:
    //   if (this[95] != NULL)
    //       FreeWrapper_7bcf(this[95]);
    //   if (this[93] != NULL)
    //       FreeWrapper_7bcf(this[93]);
    //   FunctionCallWrapper_9440(this);
    //   if ((a2 & 1) != 0)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: The concrete object type and the identities of the two freed sub-resources are not established by static evidence alone.
    // UNRESOLVED: What FunctionCallWrapper_9440 tears down is outside this function.
}
