// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00486AA0
// Canonical corpus name: GuardedFunctionDispatch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GuardedFunctionDispatch_00486aa0.c

void UnknownObject::GuardedFunctionDispatch()
{
    // Guard-gated dispatch accessor: when the guard flag at this[16] (offset 0x40) is non-zero, forwards argument a2 to LookupDispatch with sentinel -1 and returns its result; otherwise returns -1 immediately without dispatching.
    // GUARD: Guard on guard flag this[16] (byte offset 0x40): non-zero enables the dispatch path, zero short-circuits to -1. [field:this:0x00000040, source:raw]
    // CALL: When the guard flag is set, call LookupDispatch(a2, -1) and adopt its return value. [callee:0x00497940, source:raw]
    // RETURN: Return the LookupDispatch result when the guard is set, otherwise return the sentinel -1. [source:raw]

    // Conservative worker pseudocode:
    //   int GuardedFunctionDispatch(void *this, int a2) {
    //     if (this[16] != 0) return LookupDispatch(a2, -1);
    //     return -1;
    //   }
    // UNRESOLVED: Meaning of the dispatch key a2 and sentinel -1 depend on LookupDispatch's contract, which is external to this function.
    // UNRESOLVED: Callers GameMode (0x0046D6D0) and sub_46FC30 (0x0046FC30) supply the guarded object and key, but the caller-side semantic of the guard flag is not established.
}
