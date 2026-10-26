// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8D90
// Canonical corpus name: GlobalVTableDispatchByParam
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalVTableDispatchByParam_004c8d90.c

void UnknownObject::GlobalVTableDispatchByParam()
{
    // Global-object vtable dispatcher. When global dword_8AC4C4 is non-null, reads the object's vtable pointer and makes an indirect __stdcall call through vtable slot +60, passing 1 when a1 == 1 and 0 otherwise, and returns its result. When dword_8AC4C4 is null the function falls through and returns an uninitialized result value.
    // GUARD: Test whether the global pointer dword_8AC4C4 is null; the dispatch only runs when it is non-null. [source:raw, global:0x008AC4C4]
    // GUARD: Test whether the selector a1 equals 1 to choose the dispatched argument (1 vs. 0). [source:raw]
    // CALL: Indirect __stdcall call through the vtable pointer at *dword_8AC4C4 + 60, passing argument 1. [source:raw, global:0x008AC4C4]
    // CALL: Indirect __stdcall call through the vtable pointer at *dword_8AC4C4 + 60, passing argument 0 (the a1 != 1 path). [source:raw, global:0x008AC4C4]
    // RETURN: Return the dispatched call's result; on the null-global path return the uninitialized local result. [source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_4C8D90(int a1) {
    //     if (dword_8AC4C4) {
    //       void **vtable = *(void **)dword_8AC4C4;
    //       if (a1 == 1)
    //         return ((int (__stdcall *)(int))vtable[15])(1);
    //       else
    //         return ((int (__stdcall *)(int))vtable[15])(0);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The indirect dispatch target at vtable slot +60 is not statically resolvable and does not appear in the packet callee list; its identity and the semantic toggle implied by passing 1 vs. 0 are unknown.
    // UNRESOLVED: Object type behind the global dword_8AC4C4 is unknown, so the vtable layout and slot +60's meaning cannot be named.
    // UNRESOLVED: The null-global return path reads an uninitialized local; the effective return value in that case is undefined.
}
