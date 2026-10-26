// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C8D60
// Canonical corpus name: ArithmeticComparison_8d60
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArithmeticComparison_8d60_004c8d60.c

void UnknownObject::DispatchGlobalVtableSlot20()
{
    // Thin virtual dispatch helper: when the global object pointer dword_8AC4C4 is non-null, calls the method at vtable offset 20 of that object as a __thiscall with the pointer as this, and returns its integer result. When the pointer is null the function falls through and returns the uninitialized local result, which is undefined behavior.
    // GUARD: Read the global object pointer dword_8AC4C4 and continue only when it is non-zero. [global:0x008AC4C4]
    // CALL: Invoke the virtual method at vtable offset 20 of the object pointed to by dword_8AC4C4 as a __thiscall, passing dword_8AC4C4 as this. [global:0x008AC4C4, source:raw]
    // RETURN: Return the integer result of the virtual call when the object pointer is present. [source:raw]
    // RETURN: Fall-through path returns the uninitialized local result when the object pointer is null. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C8D60() {
    //     int result;
    //     if (dword_8AC4C4)
    //       return (*(int (__thiscall **)(int))(*(_DWORD *)dword_8AC4C4 + 20))(dword_8AC4C4);
    //     return result;
    //   }
    // UNRESOLVED: Identity and purpose of the object stored in dword_8AC4C4, and which virtual method lives at vtable offset 20.
    // UNRESOLVED: The fall-through return of an uninitialized local result is undefined behavior; the caller contract for that path is unknown.
}
