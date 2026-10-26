// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C85A0
// Canonical corpus name: VTableDispatchViaGlobal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableDispatchViaGlobal_004c85a0.c

void UnknownObject::VTableDispatchViaGlobal()
{
    // Two-stage guarded virtual dispatch on a global object. When the object pointer dword_8AC4C8 is non-null, calls the vtable offset +8 __thiscall method (this = dword_8AC4C8) as a query; if that returns non-zero, invokes the vtable offset +16 __thiscall method (this = dword_8AC4C8) as the action. Called from FileLoadWithRetryLoop (004f9b70); paired with VTableMethodGuard (004c8580), which tests the same object and offset +8.
    // GUARD: Test whether the global object pointer dword_8AC4C8 is non-null before any dispatch. [source:raw, global:0x008AC4C8]
    // CALL: Indirect __thiscall through the vtable pointer at *dword_8AC4C8 + 8, passing dword_8AC4C8 as this, used as the query stage. [source:raw, global:0x008AC4C8]
    // GUARD: Proceed to the action stage only when the vtable offset +8 query returned non-zero. [source:raw, global:0x008AC4C8]
    // CALL: Indirect __thiscall through the vtable pointer at *dword_8AC4C8 + 16, passing dword_8AC4C8 as this, as the action stage. [source:raw, global:0x008AC4C8]

    // Conservative worker pseudocode:
    //   void VTableDispatchViaGlobal() {
    //     if (dword_8AC4C8) {
    //       if (((int (__thiscall **)(int))*(_DWORD *)dword_8AC4C8)[2](dword_8AC4C8))
    //         ((void (__thiscall **)(int))*(_DWORD *)dword_8AC4C8)[4](dword_8AC4C8);
    //     }
    //   }
    // UNRESOLVED: Object type behind the global dword_8AC4C8 is unknown, so the vtable layout and the meanings of offsets +8 (slot index 2, query) and +16 (slot index 4, action) cannot be named.
    // UNRESOLVED: The query/action roles of the two vtable slots are inferred from the call nesting and are not independently documented.
}
