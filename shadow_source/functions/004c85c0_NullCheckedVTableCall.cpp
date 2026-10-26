// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C85C0
// Canonical corpus name: NullCheckedVTableCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NullCheckedVTableCall_004c85c0.c

void UnknownObject::NullCheckedVTableCall()
{
    // Null-guarded indirect dispatch. If the global interface pointer dword_8AC4C8 is nonzero, loads the vtable base through the object it points to, invokes the member at byte offset 20 (0x14) past that vtable base as a __thiscall with dword_8AC4C8 as the this argument, and returns the call result. Otherwise falls through to the return statement and yields the uninitialized local result. Invoked from FileLoadWithRetryLoop.
    // GUARD: Guard on dword_8AC4C8 being nonzero; the dispatch is skipped entirely when the interface pointer is null. [global:0x008AC4C8, source:raw]
    // CALL: Indirect __thiscall through the vtable of the object referenced by dword_8AC4C8; the target pointer is read from the vtable base plus byte offset 20 (0x14) and invoked with dword_8AC4C8 as the implicit this argument. [global:0x008AC4C8, source:raw]
    // RETURN: Return the vtable-call result when the guard passes. [function:0x004C85C0, source:raw]
    // CALL: Invoked by FileLoadWithRetryLoop (caller 0x004F9B70) as part of its file-load retry path. [caller:0x004F9B70]

    // Conservative worker pseudocode:
    //   if (dword_8AC4C8)
    //     return (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C8 + 20))(dword_8AC4C8);
    //   return result;
    // UNRESOLVED: The concrete object type behind dword_8AC4C8 and the purpose of the vtable method at byte offset 20 (0x14) are unknown; only the guarded indirection is visible.
    // UNRESOLVED: On the null path the decompiler returns the local result uninitialized; its runtime value is undefined.
}
