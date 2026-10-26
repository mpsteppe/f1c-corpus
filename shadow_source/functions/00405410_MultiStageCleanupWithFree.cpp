// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405410
// Canonical corpus name: MultiStageCleanupWithFree
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiStageCleanupWithFree_00405410.c

void UnknownObject::MultiStageCleanupWithFree()
{
    // Multi-stage cleanup/destructor: unconditionally runs ConditionalCleanupWithDualFree (0x004054A0), then sub-object cleanup sub_4D4860, then hands this+12 (element at +0x30) to VTableDestructorWrapperWithNullCheck (0x0052D8C0) and keeps its result. Finally reads the heap buffer pointer at this[1] (+0x4) and, if non-null, frees it via FreeWrapper_7bcf (0x00587BCF) returning that result; otherwise returns the earlier destructor result. Called from audio shutdown and general utility cleanup paths.
    // CALL: Call ConditionalCleanupWithDualFree (0x004054A0) unconditionally as the first cleanup stage [callee:0x004054A0, source:raw]
    // CALL: Call sub_4D4860 (0x004D4860) unconditionally as the second cleanup stage [callee:0x004D4860, source:raw]
    // CALL: Call VTableDestructorWrapperWithNullCheck (0x0052D8C0) with this+12 (element at +0x30); its result is stored and returned when the free path is skipped [callee:0x0052D8C0, source:raw]
    // ASSIGNMENT: Read this[1] (+0x4) into v3, the heap buffer pointer whose lifetime this destructor manages [field:this:0x00000004, source:raw]
    // GUARD: Proceed to the free path only while v3 (this[1], +0x4) is non-null; otherwise return the VTableDestructorWrapperWithNullCheck result [field:this:0x00000004, source:raw]
    // CALL: Call FreeWrapper_7bcf (0x00587BCF) with v3, freeing the heap buffer, and return its result [callee:0x00587BCF, source:raw]
    // RETURN: Return the VTableDestructorWrapperWithNullCheck result when the heap buffer at +0x4 is null [source:raw]
    // CALL: Invoked by AudioSystemShutdown (0x00406E50), LinkedListNodeInsert (0x00407520), and UtilityFunction (0x004081E0) [caller:0x00406E50, caller:0x00407520, caller:0x004081E0, source:raw]

    // Conservative worker pseudocode:
    //   ConditionalCleanupWithDualFree();
    //   sub_4D4860();
    //   result = VTableDestructorWrapperWithNullCheck(this + 12);
    //   v3 = this[1];
    //   if (v3)
    //       return FreeWrapper_7bcf(v3);
    //   return result;
    // UNRESOLVED: The +0x4 buffer's allocation site, the object type behind this+12, and the nature of ConditionalCleanupWithDualFree's global/static target are not evidenced in this packet
    // UNRESOLVED: Caller names (AudioSystemShutdown, LinkedListNodeInsert, UtilityFunction) are prelabel labels; their semantics are not evidenced here
}
