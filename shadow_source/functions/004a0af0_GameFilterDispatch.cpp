// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0AF0
// Canonical corpus name: sub_4A0AF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A0AF0_004a0af0.c

void UnknownObject::GameFilterDispatch()
{
    // Feature-gated dispatch helper. First invokes the virtual method at vtable offset +28 on the interface object pointed to by global dword_7CD8C0, passing argument 23, as an availability gate. If the gate returns non-zero, resolves a dispatch target from the game-filter string aGameFilter via ConditionalDispatch_81f0 and runs it through SingleFunctionDispatch_6f90, returning that result. If the gate returns zero, returns zero immediately without dispatching. Called from AutoJoinRetryLoop and MultiplayerSessionJoinHandler, consistent with multiplayer session-join setup.
    // CALL: Call the virtual method at vtable offset +28 on dword_7CD8C0 with argument 23; the return value gates the dispatch. [global:0x007CD8C0, source:raw]
    // GUARD: Guard on the gate result; a zero return skips the dispatch and is returned as-is. [source:raw]
    // CALL: Resolve a dispatch target from the aGameFilter string via ConditionalDispatch_81f0. [callee:0x005681F0, global:0x005C7130, source:raw]
    // CALL: Dispatch the resolved target through SingleFunctionDispatch_6f90. [callee:0x00476F90, source:raw]
    // RETURN: Return the dispatch result, or the gate result when the gate returned zero. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4A0AF0() {
    //     int result = (*(int (__thiscall **)(int, int))(*(int *)dword_7CD8C0 + 28))(dword_7CD8C0, 23);
    //     if (result) {
    //       char *target = (char *)ConditionalDispatch_81f0(aGameFilter);
    //       return SingleFunctionDispatch_6f90(target);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The identity and purpose of the dword_7CD8C0 interface and its vtable+28 method (argument 23) are unknown.
    // UNRESOLVED: The meaning of the aGameFilter string and the dispatch mechanism in ConditionalDispatch_81f0 / SingleFunctionDispatch_6f90 are ungrounded here.
    // UNRESOLVED: Global dword_8AD3B4 appears in the packet global evidence but is absent from the raw source body; its role is ungrounded.
}
