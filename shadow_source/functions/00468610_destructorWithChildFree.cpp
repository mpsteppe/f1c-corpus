// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00468610
// Canonical corpus name: DestructorWithFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithFree_00468610.c

void UnknownObject::destructorWithChildFree()
{
    // Object destructor: restores the vtable pointer at offset 0 to off_59F718, conditionally frees a heap sub-object held at offset 0x174 (this[93]) when non-null, then delegates to a cleanup wrapper and returns its result.
    // ASSIGNMENT: vtable pointer at offset 0 set to global off_59F718 [field:this:0x00000000, global:0x0059F718]
    // GUARD: test sub-object pointer at offset 0x174 (this[93]) for null before freeing [field:this:0x00000174]
    // CALL: free sub-object via FreeWrapper_7bcf when the pointer is non-null [callee:0x00587BCF, field:this:0x00000174]
    // RETURN: delegate to cleanup wrapper and return its value [function:0x00468610]

    // Conservative worker pseudocode:
    //   *this = &off_59F718;
    //   if (this[93])
    //       FreeWrapper_7bcf(this[93]);
    //   return cleanup_wrapper(this);
    // UNRESOLVED: Identity and purpose of the final cleanup wrapper function are not present in the packet evidence
}
