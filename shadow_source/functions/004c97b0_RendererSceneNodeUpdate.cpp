// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C97B0
// Canonical corpus name: RendererSceneNodeUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RendererSceneNodeUpdate_004c97b0.c

void UnknownObject::RendererSceneNodeUpdate()
{
    // Scene node render update. Gated on the virtual state check (enters only when VirtualStateCheckViaIndex returns 0), it resets the state field at this+0x1C to 0, then, if the sub-object at this+0x20 is present and the race-phase global dword_7C56A8 is not 2, zeroes a 12-byte scratch array and dispatches the vtable entry at offset 4 of that sub-object with a transform and two fixed literals (1065353216, 1). Always returns 0.
    // GUARD: Enter the update body only when VirtualStateCheckViaIndex() returns 0; a non-zero return suppresses the whole update [callee:0x004C9820, source:raw]
    // ASSIGNMENT: Reset the state field: *(this + 28) = 0 [field:this:0x0000001C, function:0x004C97B0]
    // GUARD: The render sub-object at this+0x20 must be non-null before any dispatch is attempted [field:this:0x00000020]
    // GUARD: Dispatch only while the race-phase global dword_7C56A8 differs from 2 [global:0x007C56A8]
    // CALCULATION: Zero the 12-byte scratch array v3 via memset before passing it to the vtable method [source:raw]
    // CALL: Dispatch stdcall vtable entry 4 of the sub-object at this+0x20 with arguments (0, this+8, v3, flt_7CF2CC, 1065353216, 1) [field:*(this+0x20):0x00000000, field:*(*(this+0x20)+0x0):0x00000004, global:0x007CF2CC, function:0x004C97B0, source:raw]
    // RETURN: Returns the constant 0 in all paths [function:0x004C97B0]

    // Conservative worker pseudocode:
    //   if (!VirtualStateCheckViaIndex()) {
    //     *(this + 28) = 0;
    //     if (*(this + 32) && dword_7C56A8 != 2) {
    //       memset(v3, 0, sizeof(v3));
    //       (*(vtable(*(this + 32))[4]))(0, this + 8, v3, flt_7CF2CC, 1065353216, 1);
    //     }
    //   }
    //   return 0;
    // UNRESOLVED: Meaning of the race-phase value 2 for dword_7C56A8 is not evidenced; only the inequality check appears in the source
    // UNRESOLVED: The object type behind the sub-object vtable at this+0x20 and its method at vtable offset 4 are unknown
    // UNRESOLVED: Semantics of the fixed literals 1065353216 and 1 passed to the vtable method are not asserted
}
