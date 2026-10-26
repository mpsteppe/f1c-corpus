// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048E0B0
// Canonical corpus name: DestructorWithConditionalFree_e0b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DestructorWithConditionalFree_e0b0_0048e0b0.c

void UnknownObject::DestructorWithConditionalFree_e0b0()
{
    // Scalar-deleting destructor: runs sub_48E0D0 on the object, then, when the deletion-flag bit a2&1 is set, frees the object through FreeWrapper_7bcf. Returns the this pointer unchanged.
    // CALL: Calls sub_48E0D0(this) to run the object teardown body before any free. [callee:0x0048E0D0]
    // GUARD: Tests the low bit of the a2 flag parameter; the freeing path is taken only when (a2 & 1) is non-zero. [source:raw]
    // CALL: Calls FreeWrapper_7bcf(this) to release the object storage when the deletion flag is set. [callee:0x00587BCF]
    // RETURN: Returns the original this pointer to the caller regardless of which branch ran. [source:raw]

    // Conservative worker pseudocode:
    //   sub_48E0D0(this);
    //   if (a2 & 1)
    //       FreeWrapper_7bcf(this);
    //   return this;
    // UNRESOLVED: Object type and the teardown performed by sub_48E0D0 are unknown; no fields or globals are accessed at this level.
    // UNRESOLVED: No callers in the packet, so the destroy sequence context is unobserved.
}
