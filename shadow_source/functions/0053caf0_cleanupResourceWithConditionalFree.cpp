// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CAF0
// Canonical corpus name: sub_53CAF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_53CAF0_0053caf0.c

void UnknownObject::cleanupResourceWithConditionalFree()
{
    // Runs TwoListCleanup on a1. If a1 is non-null, runs EmptyStub_7470 and then FreeWrapper_7bcf on it. Always returns 0.
    // CALL: TwoListCleanup(a1) — two-list cleanup performed on the resource [callee:0x00547420]
    // GUARD: If a1 is non-null, the empty-stub and free path is taken [source:raw]
    // CALL: EmptyStub_7470(a1) — stub operation on the non-null resource [callee:0x00557470]
    // CALL: FreeWrapper_7bcf(a1) — frees the resource wrapper [callee:0x00587BCF]
    // RETURN: Always returns 0 regardless of path taken [source:raw]

    // Conservative worker pseudocode:
    //   int cleanupResourceWithConditionalFree(void* a1) {
    //     TwoListCleanup(a1);
    //     if (a1) {
    //       EmptyStub_7470(a1);
    //       FreeWrapper_7bcf(a1);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Semantics of TwoListCleanup (0x00547420) and EmptyStub_7470 (0x00557470) are unknown.
    // UNRESOLVED: Object type of a1 is unknown; caller ReleaseSceneNode (0x005437E0) suggests scene-node resource teardown but this is not established.
    // UNRESOLVED: Why a null a1 still receives TwoListCleanup while the free path is null-guarded is unexplained.
}
