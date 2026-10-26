// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048FE90
// Canonical corpus name: ScalarDeletingDestructor_fe90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScalarDeletingDestructor_fe90_0048fe90.c

void UnknownObject::ScalarDeletingDestructor_fe90()
{
    // Scalar-deleting destructor: runs VTableSubInit on the object, then, when the deletion-flag bit a2&1 is set, frees the object through FreeWrapper_7bcf. Returns the this pointer unchanged.
    // CALL: Calls VTableSubInit(this) to run the vtable/teardown init path before any free. [callee:0x0048FEB0]
    // GUARD: Tests the low bit of the a2 flag parameter; the freeing path is taken only when (a2 & 1) is non-zero. [source:raw]
    // CALL: Calls FreeWrapper_7bcf(this) to release the object storage when the deletion flag is set. [callee:0x00587BCF]
    // RETURN: Returns the original this pointer to the caller regardless of which branch ran. [source:raw]

    // Conservative worker pseudocode:
    //   VTableSubInit(this);
    //   if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Object type and the work performed by VTableSubInit are unknown; no fields or globals are accessed at this level.
    // UNRESOLVED: No callers in the packet, so the destroy sequence context is unobserved.
}
