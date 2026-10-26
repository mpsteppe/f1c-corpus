// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053CE10
// Canonical corpus name: ErrorHandlerSet
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ErrorHandlerSet_0053ce10.c

void UnknownObject::ErrorHandlerSet()
{
    // Wrapper around the MAS file loader sub_53CBC0. Calls sub_53CBC0(a1, a2) and returns its result. On success (result == 0), when a1 is non-null, dereferences a1 to obtain the loaded object pointer and sets bit 3 (value 8) in the flags dword at offset 0x114 of that object, marking it for error-handling state. Any non-zero loader result short-circuits before the flag write.
    // CALL: Call the MAS loader sub_53CBC0(a1, a2) and store its return value as result. [callee:0x0053CBC0, source:raw]
    // GUARD: Guard on result == 0; a non-zero loader result skips the flag write. [source:raw]
    // GUARD: Guard on a1 being non-null before dereferencing it. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Dereference a1 to get the loaded object pointer, then OR bit value 8 into the flags dword at offset 0x114 (276) of that object. [field:obj:0x00000114, field:this:0x00000000, source:raw]
    // RETURN: Return the loader result unchanged. [function:0x0053CE10, source:raw]

    // Conservative worker pseudocode:
    //   int __stdcall sub_53CE10(_DWORD *a1, CHAR *a2) {
    //     int result = sub_53CBC0(a1, a2);
    //     if (!result) {
    //       if (a1)
    //         *(_DWORD *)(*a1 + 276) |= 8u;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: What sub_53CBC0 allocates into *a1 and the object type of that pointer are not visible here.
    // UNRESOLVED: Meaning of the bit-3 flag at offset 0x114 (error-handling state) is inferred from prior analysis, not from this function alone.
    // UNRESOLVED: String parameter a2 is passed through to sub_53CBC0 without interpretation.
}
