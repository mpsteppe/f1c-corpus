// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8580
// Canonical corpus name: VTableMethodGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VTableMethodGuard_004c8580.c

void UnknownObject::VTableMethodGuard()
{
    // Boolean predicate over a global object: returns true only when the object pointer dword_8AC4C8 is non-null and the indirect __thiscall through its vtable offset +8 (with this = dword_8AC4C8) returns non-zero. Called from FileLoadWithRetryLoop (004f9b70), where it appears to gate a follow-up action.
    // GUARD: Test whether the global object pointer dword_8AC4C8 is non-null; the vtable query only runs when it is. [source:raw, global:0x008AC4C8]
    // CALL: Indirect __thiscall through the vtable pointer at *dword_8AC4C8 + 8, passing dword_8AC4C8 as this. [source:raw, global:0x008AC4C8]
    // RETURN: Short-circuit AND: return the truthiness of the vtable +8 call result only when dword_8AC4C8 was non-null. Consumed by caller FileLoadWithRetryLoop. [source:raw, caller:0x004F9B70]

    // Conservative worker pseudocode:
    //   bool VTableMethodGuard() {
    //     return dword_8AC4C8 && ((bool (__thiscall **)(int))*(_DWORD *)dword_8AC4C8)[2](dword_8AC4C8);
    //   }
    // UNRESOLVED: Object type behind the global dword_8AC4C8 is unknown, so the vtable layout and the meaning of offset +8 (slot index 2) cannot be named.
    // UNRESOLVED: The semantic role of the +8 slot method (query/check) is inferred from its boolean use in this predicate and is not independently documented.
}
