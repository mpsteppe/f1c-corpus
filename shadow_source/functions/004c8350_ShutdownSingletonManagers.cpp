// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8350
// Canonical corpus name: ArithmeticComparison_8350
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_8350_004c8350.c

void UnknownObject::ShutdownSingletonManagers()
{
    // Teardown dispatch for four global singleton pointers. For dword_8AC4C8, dword_8AC4CC and dword_8AC4D0: when the pointer is non-null, call the object's method through vtable slot 0 passing the constant 1, then clear the global to null. For dword_8AC4C4: when non-null, call its method through the vtable slot at byte offset 12 with only the object argument, then clear the global to null. Returns the result of the last executed call.
    // GUARD: Guard: dword_8AC4C8 non-null before dispatching to the first singleton. [global:0x008AC4C8, source:raw]
    // CALL: Indirect __thiscall through the object's vtable slot 0 with argument 1; store the return value. [global:0x008AC4C8, source:raw]
    // ASSIGNMENT: Clear the global pointer dword_8AC4C8 to null. [global:0x008AC4C8, source:raw]
    // GUARD: Guard: dword_8AC4CC non-null before dispatching to the second singleton. [global:0x008AC4CC, source:raw]
    // CALL: Indirect __thiscall through the object's vtable slot 0 with argument 1; store the return value. [global:0x008AC4CC, source:raw]
    // ASSIGNMENT: Clear the global pointer dword_8AC4CC to null. [global:0x008AC4CC, source:raw]
    // GUARD: Guard: dword_8AC4D0 non-null before dispatching to the third singleton. [global:0x008AC4D0, source:raw]
    // CALL: Indirect __thiscall through the object's vtable slot 0 with argument 1; store the return value. [global:0x008AC4D0, source:raw]
    // ASSIGNMENT: Clear the global pointer dword_8AC4D0 to null. [global:0x008AC4D0, source:raw]
    // GUARD: Guard: dword_8AC4C4 non-null before dispatching to the fourth singleton. [global:0x008AC4C4, source:raw]
    // CALL: Indirect __thiscall through the vtable slot at byte offset 12 with only the object argument; store the return value. [global:0x008AC4C4, source:raw]
    // ASSIGNMENT: Clear the global pointer dword_8AC4C4 to null. [global:0x008AC4C4, source:raw]
    // RETURN: Return the result of the last executed indirect call; reachable from ListDestructorWithSubFree (004C8210) and InitWithStatusCheck (004C82C0). [caller:0x004C8210, caller:0x004C82C0, source:raw]

    // Conservative worker pseudocode:
    //   int ShutdownSingletonManagers() {
    //     if (dword_8AC4C8) { result = dword_8AC4C8->slot0(dword_8AC4C8, 1); dword_8AC4C8 = 0; }
    //     if (dword_8AC4CC) { result = dword_8AC4CC->slot0(dword_8AC4CC, 1); dword_8AC4CC = 0; }
    //     if (dword_8AC4D0) { result = dword_8AC4D0->slot0(dword_8AC4D0, 1); dword_8AC4D0 = 0; }
    //     if (dword_8AC4C4) { result = dword_8AC4C4->slot12(dword_8AC4C4); dword_8AC4C4 = 0; }
    //     return result;
    //   }
    // UNRESOLVED: Identity of the four singleton object types and the dispatched methods behind the vtable slots is not statically known.
    // UNRESOLVED: The constant 1 passed to the first three vtable methods is a parameter whose meaning is unknown.
    // UNRESOLVED: The last call passes no second argument while the first three do; reason unknown.
}
