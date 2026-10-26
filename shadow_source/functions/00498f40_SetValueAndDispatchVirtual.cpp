// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00498F40
// Canonical corpus name: SetterVirtualCall
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SetterVirtualCall_00498f40.c

void UnknownObject::SetValueAndDispatchVirtual()
{
    // Conditional field setter followed by an unconditional virtual dispatch. If argument a2 is non-zero, stores a2 into this+0x50 (this[20]); regardless of the guard outcome, dispatches the virtual method at vtable offset 44 with argument 1 and returns its result.
    // GUARD: If a2 is zero, skip the field write entirely and fall through to the virtual call; if non-zero, proceed to store it. [function:0x00498F40, source:raw]
    // ASSIGNMENT: this[20] = a2; store the argument into the field at this+0x50. Executed only when a2 is non-zero. [field:this:0x00000050, function:0x00498F40, source:raw]
    // CALL: Dispatch the virtual method at vtable offset 44 (*(*this + 44)) with this and argument 1, unconditionally after the guarded write. [field:this:0x00000000, function:0x00498F40, source:raw]
    // RETURN: Return the integer result produced by the virtual method call. [function:0x00498F40, source:raw]

    // Conservative worker pseudocode:
    //   int SetValueAndDispatchVirtual(void* this, int a2) {
    //     if (a2)
    //       this[20] = a2;
    //     return (*(int (**)(void*, int)) *this[0] + 44)(this, 1);
    //   }
    // UNRESOLVED: The vtable offset 44 target is unknown; it is resolved dynamically and cannot be named statically.
    // UNRESOLVED: The meaning of the constant argument 1 passed to the virtual method is unknown.
    // UNRESOLVED: field:obj:0x0000002C (read, base obj) is not referenced by the decompiled source and its role is unidentified.
    // UNRESOLVED: The identity of the owning object type is unknown; callers are LinkedListSearchWithAction (004974a0) and UtilityFunction_7890 (00497890).
}
