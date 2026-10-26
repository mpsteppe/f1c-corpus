// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CB90
// Canonical corpus name: sub_53CB90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53CB90_0053cb90.c

void UnknownObject::CleanupObjectAndFree()
{
    // Object teardown wrapper: unconditionally runs a first-phase cleanup call sub_542E50(a1), then, only when a1 is non-null, runs a stub call and a free wrapper over the same pointer. Always returns 0. Caller names (AVIPlayerCleanup, MultiStageCleanupWithRepeatedCallCycle, AudioResourceCleanup, sub_4F9480) all sit on cleanup paths, consistent with a release/dealloc helper that takes an owning object pointer.
    // CALL: Call sub_542E50(a1) first, unconditionally, before any null check. [callee:0x00542E50, source:raw]
    // GUARD: Guard on a1 being non-null before running the stub and free calls. [source:raw]
    // CALL: When a1 is non-null, call EmptyStub_7470(a1). [callee:0x00557470, source:raw]
    // CALL: When a1 is non-null, call FreeWrapper_7bcf(a1). [callee:0x00587BCF, source:raw]
    // RETURN: Return 0 unconditionally. [function:0x0053CB90, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53CB90(void *a1) {
    //     sub_542E50(a1);
    //     if (a1) {
    //       EmptyStub_7470(a1);
    //       FreeWrapper_7bcf(a1);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Relationship between the unconditional sub_542E50(a1) phase and the null-guarded EmptyStub_7470/FreeWrapper_7bcf phase is not established by this packet; sub_542E50 may also null-check internally.
    // UNRESOLVED: What sub_542E50 does and whether it mutates or releases a1 before the guard is unknown; the null check after a sub_542E50 call is unusual for a pure free path.
    // UNRESOLVED: The four recorded callers are cleanup/AVI/audio lifecycle paths but their exact object type and ownership contract are not analyzed here.
    // UNRESOLVED: The ABI record is LEGACY with no prototype; the void* parameter and __stdcall convention come only from the raw source.
}
