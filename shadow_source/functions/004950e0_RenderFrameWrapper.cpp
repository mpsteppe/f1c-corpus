// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004950E0
// Canonical corpus name: RenderFrameWrapper
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RenderFrameWrapper_004950e0.c

void UnknownObject::RenderFrameWrapper()
{
    // Minimal render frame wrapper: initializes conditional/timing state at unk_8AFE18, performs the render/draw operation via sub_553700 using the render-device pointer dword_8B8DC8, then resets the conditional state at unk_8AFE18. No guards; all steps run unconditionally.
    // CALL: Call ConditionalInit(&unk_8AFE18) to initialize the timing/conditional state before the render step. [global:0x008AFE18, callee:0x004F9F00, source:raw]
    // CALL: Call sub_553700(dword_8B8DC8) to perform the render/draw operation via the render device. [global:0x008B8DC8, callee:0x00553700, source:raw]
    // CALL: Call ConditionalStateReset(&unk_8AFE18) to reset the conditional state, returning its result. [global:0x008AFE18, source:raw]
    // RETURN: Return the result of ConditionalStateReset(&unk_8AFE18). [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4950E0() {
    //     ConditionalInit(&unk_8AFE18);
    //     sub_553700(dword_8B8DC8);
    //     return ConditionalStateReset(&unk_8AFE18);
    //   }
    // UNRESOLVED: The purpose of dword_7CDE18 (DERIVED SurfaceRef2) is not referenced by this function's code path.
    // UNRESOLVED: The identity and behavior of sub_553700 (render operation) is not resolved here.
    // UNRESOLVED: Whether this wrapper is invoked from SceneEntityCleanup and under what frame conditions is not established by the evidence.
}
