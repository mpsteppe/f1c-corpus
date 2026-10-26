// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9F30
// Canonical corpus name: ConditionalStateReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalStateReset_004f9f30.c

void UnknownObject::ConditionalStateReset()
{
    // Conditional reset of the one-time init flag byte_8AFE71, the counterpart to ConditionalInit. First obtains a non-zero status from StructFieldGetter(&dword_8B78A0); only then is the flag consulted. When the flag is set (1), it is cleared to 0 and a further dispatch/getter on dword_8B78A0 runs, whose return value becomes the result. When the flag was already clear, the current flag value is returned. Clearing the flag marks the initialization as not-yet-done so the next ConditionalInit call re-runs its setup. Invoked from main-loop, 2D screen-quad render, options setup, and video-manager enter paths.
    // CALL: Call StructFieldGetter(&dword_8B78A0) and store the result in the working value. [callee:0x0055C9B0, global:0x008B78A0]
    // GUARD: Guard: only proceed when the StructFieldGetter result is non-zero. [source:raw]
    // ASSIGNMENT: Load byte_8AFE71 into the low byte of the working value (becomes the fallback return). [global:0x008AFE71]
    // GUARD: Guard: only proceed when byte_8AFE71 is non-zero (init flag still set). [global:0x008AFE71]
    // ASSIGNMENT: Clear the init-done flag: byte_8AFE71 = 0. [global:0x008AFE71]
    // CALL: Run the follow-up dispatch/getter on dword_8B78A0 and place its result in the low byte of the working value; the dispatch target (VTableDispatchGetter) is not listed among packet callees. [global:0x008B78A0, source:raw]
    // RETURN: Return the working value (dispatch result when reset ran, else the prior flag state). [source:raw]

    // Conservative worker pseudocode:
    //   char sub_4F9F30() {
    //     int v0 = StructFieldGetter(&dword_8B78A0);
    //     if (v0) {
    //       v0 = byte_8AFE71;
    //       if (byte_8AFE71) {
    //         byte_8AFE71 = 0;
    //         v0 = VTableDispatchGetter(&dword_8B78A0);
    //       }
    //     }
    //     return v0;
    //   }
    // UNRESOLVED: Identity and address of the VTableDispatchGetter dispatch target is not present in the packet callee list; only its decompiled name appears in the raw source text.
    // UNRESOLVED: Meaning of StructFieldGetter(&dword_8B78A0) non-zero result and of the object at dword_8B78A0 are unknown here.
}
