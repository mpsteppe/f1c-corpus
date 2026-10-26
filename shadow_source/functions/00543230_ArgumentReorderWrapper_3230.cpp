// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00543230
// Canonical corpus name: ArgumentReorderWrapper_3230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArgumentReorderWrapper_3230_00543230.c

void UnknownObject::ArgumentReorderWrapper_3230()
{
    // __thiscall argument-reordering wrapper: forwards this (reinterpreted as int) and the two parameters a2, a3 to BitmaskVirtualDispatch with a3 promoted to the second argument and a2 demoted to the third, then returns the dispatch result unchanged.
    // CALL: Call BitmaskVirtualDispatch((int)this, a3, a2) with the second and third parameters swapped relative to the wrapper's signature. [source:raw, callee:0x00540150]
    // UNKNOWN: Global dword_8B78A0 is read somewhere in this call's path; the read is not visible in the wrapper's raw source body and is presumed to occur inside the dispatched callee. [global:0x008B78A0]
    // RETURN: Return the value produced by BitmaskVirtualDispatch. [source:raw]

    // Conservative worker pseudocode:
    //   int ArgumentReorderWrapper_3230(void *this, int a2, int a3) {
    //     return BitmaskVirtualDispatch((int)this, a3, a2);
    //   }
    // UNRESOLVED: Reason for swapping a2 and a3 before dispatch is unknown.
    // UNRESOLVED: The read of global dword_8B78A0 is not attributable to a specific statement in this function's body.
    // UNRESOLVED: Dispatch semantics selected by the bitmask / this pointer in BitmaskVirtualDispatch are unknown.
}
