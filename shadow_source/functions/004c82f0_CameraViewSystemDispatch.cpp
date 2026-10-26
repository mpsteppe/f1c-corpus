// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C82F0
// Canonical corpus name: sub_4C82F0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C82F0_004c82f0.c

void UnknownObject::CameraViewSystemDispatch()
{
    // If the global object pointer dword_8AC4C4 is non-null, call its vtable method at offset 56 with argument 2, then call the vtable method at offset 4 with hWnd. A non-zero return clears dword_8AC4C4 to 0; otherwise call the vtable methods at offsets 44 (argument 1065353216) and 52 (argument dword_7CF230).
    // GUARD: Skip all work when dword_8AC4C4 is null. [global:0x008AC4C4, source:raw, function:0x004C82F0]
    // CALL: Call the object's vtable method at offset 56 (thiscall on dword_8AC4C4) with argument 2. [global:0x008AC4C4, source:raw]
    // CALL: Call the object's vtable method at offset 4 with hWnd; the return value selects the branch. [global:0x008AC4C4, global:0x007CE2DC, source:raw]
    // STATE_TRANSITION: When the offset-4 call returns non-zero, clear dword_8AC4C4 to 0. [global:0x008AC4C4, source:raw]
    // CALL: Else branch: call the vtable method at offset 44 with argument 1065353216. [global:0x008AC4C4, source:raw]
    // CALL: Else branch: call the vtable method at offset 52 with argument dword_7CF230. [global:0x008AC4C4, global:0x007CF230, source:raw]

    // Conservative worker pseudocode:
    //   void Dispatch() {
    //     if (!dword_8AC4C4) return;
    //     dword_8AC4C4->vtable[56](dword_8AC4C4, 2);
    //     if (dword_8AC4C4->vtable[4](dword_8AC4C4, hWnd)) {
    //       dword_8AC4C4 = 0;
    //     } else {
    //       dword_8AC4C4->vtable[44](dword_8AC4C4, 1065353216);
    //       dword_8AC4C4->vtable[52](dword_8AC4C4, dword_7CF230);
    //     }
    //   }
    // UNRESOLVED: Object type at dword_8AC4C4 is unknown; every call is an indirect vtable dispatch.
    // UNRESOLVED: Legacy ABI label Camera_View_System_Dispatch is uncorroborated; the only static caller is Sound_Enter (0x004C8A20).
    // UNRESOLVED: Semantics of the method arguments 2, 1065353216, and dword_7CF230 are unknown.
    // UNRESOLVED: The vtable methods may mutate the object, but the object stays live except when the offset-4 call returns non-zero.
}
