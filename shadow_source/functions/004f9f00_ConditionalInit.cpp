// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9F00
// Canonical corpus name: ConditionalInit
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalInit_004f9f00.c

void UnknownObject::ConditionalInit()
{
    // Conditional one-time initialization guarded by global flag byte_8AFE71. First obtains a non-zero status from StructFieldGetter(&dword_8B78A0); only then is the flag consulted. When the flag is clear (0), it is set to 1 and a further dispatch/getter on dword_8B78A0 runs, whose return value becomes the result. When the flag was already set, the current flag value is returned. The flag thus records that the initialization path has already been taken. Invoked from many frame/setup paths (main loop, 2D screen-quad render, options setup, video-manager enter).
    // CALL: Call StructFieldGetter(&dword_8B78A0) and store the result in the working value. [callee:0x0055C9B0, global:0x008B78A0]
    // GUARD: Guard: only proceed when the StructFieldGetter result is non-zero. [source:raw]
    // ASSIGNMENT: Load byte_8AFE71 into the low byte of the working value (becomes the fallback return). [global:0x008AFE71]
    // GUARD: Guard: only proceed when byte_8AFE71 is zero (init not yet done). [global:0x008AFE71]
    // ASSIGNMENT: Set the init-done flag: byte_8AFE71 = 1. [global:0x008AFE71]
    // CALL: Run the follow-up dispatch/getter on dword_8B78A0 and place its result in the low byte of the working value; the dispatch target (VTableGetterWrapper) is not listed among packet callees. [global:0x008B78A0, source:raw]
    // RETURN: Return the working value (dispatch result when init ran, else the prior flag state). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4F9F00() {
    //     int v0 = StructFieldGetter(&dword_8B78A0);
    //     if (v0) {
    //       v0 = byte_8AFE71;
    //       if (!byte_8AFE71) {
    //         byte_8AFE71 = 1;
    //         v0 = VTableGetterWrapper(&dword_8B78A0);
    //       }
    //     }
    //     return v0;
    //   }
    // UNRESOLVED: Identity and address of the VTableGetterWrapper dispatch target is not present in the packet callee list; only its decompiled name appears in the raw source text.
    // UNRESOLVED: Meaning of StructFieldGetter(&dword_8B78A0) non-zero result and of the object at dword_8B78A0 are unknown here.
}
