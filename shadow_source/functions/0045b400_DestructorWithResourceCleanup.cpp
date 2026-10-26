// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045B400
// Canonical corpus name: DestructorWithResourceCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithResourceCleanup_0045b400.c

void UnknownObject::DestructorWithResourceCleanup()
{
    // Object destructor. Restores the vtable pointer at this+0x0 to the off_59F080 table, cleans up the sub-object at this+0x4, frees the heap allocation held at this+0x2C when non-null, then performs resource cleanup on the sub-object and returns its result.
    // ASSIGNMENT: Restore vtable pointer at this+0x0 to the off_59F080 table. [field:this:0x00000000, global:0x0059F080]
    // CALL: Clean up the sub-object at this+0x4 via ShortComputation_d000. [callee:0x004DD000, function:0x0045B400]
    // GUARD: If the heap allocation pointer at this+0x2C is non-null. [field:this:0x0000002C]
    // CALL: Free the heap allocation at this+0x2C via FreeWrapper_7bcf. [callee:0x00587BCF, field:this:0x0000002C]
    // RETURN: Perform resource cleanup on the sub-object at this+0x4 (routine named ResourceCleanup_cd10 in raw source; no callee address present in packet) and return its result. [source:raw]

    // Conservative worker pseudocode:
    //   v1 = this + 1;
    //   *this = &off_59F080;
    //   ShortComputation_d000(this + 1);
    //   if (v1[10]) FreeWrapper_7bcf(v1[10]);
    //   return cleanup_on(v1);
    // UNRESOLVED: The cleanup routine invoked for the return value (named ResourceCleanup_cd10 in the raw source) has no callee address in the packet; its identity and the sub-object type at this+0x4 are unverified.
    // UNRESOLVED: The vtable at off_59F080 suggests a UI/render-object owner, but owner identity is not confirmed by packet evidence.
}
