// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8900
// Canonical corpus name: GlobalDispatchWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalDispatchWithGuard_004c8900.c

void UnknownObject::globalDispatchWithGuard()
{
    // Guarded indirect dispatch: if the global pointer dword_8AC4C8 (0x008AC4C8) is non-null, calls through the object vtable entry at byte offset +28 with the object as `this` and the argument a1, returning the call result. When the global is null the function returns the uninitialized local `result`. Reached from UILoadingPercentDisplay (0047C860) and Sound_Enter (004C8A20), suggesting a shared global dispatch target used by both UI and audio paths.
    // GUARD: Guard on global dword_8AC4C8: only proceed with the indirect call when it is non-null; a null value short-circuits to the fallback return [global:0x008AC4C8, source:raw]
    // CALL: Indirect thiscall through the vtable entry at byte offset +28 of the object pointed to by dword_8AC4C8, forwarding a1; the object pointer is passed as `this` [global:0x008AC4C8, source:raw]
    // RETURN: Return the indirect call result when the guard passes; return the uninitialized local `result` when the global is null [source:raw]
    // CALL: Invoked by UILoadingPercentDisplay (0047C860) and Sound_Enter (004C8A20) to dispatch an argument through the shared global object [caller:0x0047C860, caller:0x004C8A20]

    // Conservative worker pseudocode:
    //   int globalDispatchWithGuard(int a1) {
    //     if (dword_8AC4C8) {
    //       return (*(int (**)(int, int))(*(int*)dword_8AC4C8 + 28))(dword_8AC4C8, a1);
    //     }
    //     return result; /* indeterminate when the guard fails * /
    //   }
    // UNRESOLVED: The identity and type of the object behind dword_8AC4C8 and the meaning of its vtable method at offset +28 are not established by packet evidence.
    // UNRESOLVED: The null-guard path returns the uninitialized local `result`; the resulting behavior when dword_8AC4C8 is null is undefined and not documented.
    // UNRESOLVED: The single global dispatch object is shared by a UI loading caller and an audio-entry caller; the shared semantic role is unknown.
}
