// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004761A0
// Canonical corpus name: StringCopyWithGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringCopyWithGuard_004761a0.c

void UnknownObject::StringCopyWithGuard()
{
    // Guarded string-copy method on an unknown object. If the incoming source pointer a2 is non-null, it delegates to StringCopyWithBufferRealloc targeting the object's buffer at offset 80 and returns that copy's result; otherwise it returns the null source pointer unchanged.
    // ASSIGNMENT: Initialize result to (int)a2, the incoming source pointer. [source:raw]
    // GUARD: Guard: when a2 is non-null the copy path is taken; a null source returns early. [source:raw]
    // CALL: Call StringCopyWithBufferRealloc((int)this + 80, a2), copying a2 into the object's string buffer at offset 80, and return its result. [function:0x004761A0, source:raw]
    // RETURN: Return the copy result when a2 was non-null, otherwise return the saved source pointer a2 (null) unchanged. [source:raw]

    // Conservative worker pseudocode:
    //   result = (int)a2;
    //   if (a2)
    //     return StringCopyWithBufferRealloc((int)this + 80, a2);
    //   return result;
    // UNRESOLVED: Identity and layout of the owning object: only the string buffer at offset 80 is referenced, with no field evidence naming it.
    // UNRESOLVED: Signature, allocation policy and failure behavior of StringCopyWithBufferRealloc are outside this function; no callee facts are present in the packet.
}
