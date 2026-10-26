// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053D470
// Canonical corpus name: SystemInitAllocatorWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SystemInitAllocatorWrapper_0053d470.c

void UnknownObject::SystemInitAllocatorWrapper()
{
    // __fastcall allocation-and-init wrapper: allocates a 48-byte block via OperatorNewNhMallocWrapper, initializes it through EngineInitBlock, stores the resulting block pointer into the caller-provided output slot *a1, and on success returns 0 when RenderUISystemGlobalInit(v8, a2, a3, a4, a5) returns 0 (else -1); on allocation failure stores 0 and returns -1. Called by VidMan_Enter.
    // CALL: Allocate a 48-byte block with OperatorNewNhMallocWrapper(48); null result yields v8 = 0. [callee:0x00587C03, source:raw]
    // GUARD: Branch on the allocated block: when non-null run EngineInitBlock(v7), otherwise keep v8 null. [source:raw]
    // CALL: Initialize the allocated block with EngineInitBlock(v7); the returned pointer becomes v8. [callee:0x0053C2C0, source:raw]
    // ASSIGNMENT: Store the engine block pointer into the caller's output slot: *a1 = v8. [source:raw]
    // CALL: On a valid block, call RenderUISystemGlobalInit(v8, a2, a3, a4, a5) to perform the global render-UI system initialization. [callee:0x0053C360, source:raw]
    // RETURN: Return 0 when RenderUISystemGlobalInit returned 0, otherwise return -1; a failed allocation also returns -1. [source:raw]
    // CALL: Invoked by VidMan_Enter (0x004FA000) as part of the video manager entry path. [caller:0x004FA000, source:raw]

    // Conservative worker pseudocode:
    //   int sub_53D470(int* a1, int a2, int a3, int a4, char a5) {
    //     int v7 = (int)OperatorNewNhMallocWrapper(48);
    //     int v8 = v7 ? (int)EngineInitBlock(v7) : 0;
    //     *a1 = v8;
    //     if (v8) return RenderUISystemGlobalInit(v8, a2, a3, a4, a5) != 0 ? -1 : 0;
    //     return -1;
    //   }
    // UNRESOLVED: Roles of the pass-through arguments a2, a3, a4, a5 handed to RenderUISystemGlobalInit are unknown.
    // UNRESOLVED: Owner/class identity is unknown; it is an allocator-style wrapper in the render/UI system.
    // UNRESOLVED: The exact failure semantics of returning -1 on both init failure and allocation failure are inferred, not stated by evidence.
}
