// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586C90
// Canonical corpus name: CounterIncrementWithCapCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CounterIncrementWithCapCheck_00586c90.c

void UnknownObject::CounterIncrementWithCapCheck()
{
    // __thiscall that increments the 32-bit counter at this+0 by one and persists the new value. It returns a boolean derived from the pre-increment and post-increment values: the sign flag of (oldValue - 5) XOR the signed-overflow flag of (newValue - 6). For ordinary counter ranges (no overflow) the result is true while the counter has not reached 6 and false once it does, so the caller-facing meaning is a cap/boundary check. The exact interpretation by callers and the intent of the constants 5 and 6 are not established.
    // CALCULATION: Read the current counter *this and compute v1 = *this + 1. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute v2 = (*this - 5) < 0, the sign flag of the pre-increment value below 5. [source:raw]
    // ASSIGNMENT: Persist the incremented counter: *this = v1. [source:raw, field:this:0x00000000]
    // CALCULATION: Combine the sign flag with the signed-overflow flag of (v1 - 6): result = v2 ^ __OFSUB__(v1, 6). [source:raw]
    // RETURN: Return the combined sign/overflow flag as the boolean result. [source:raw]

    // Conservative worker pseudocode:
    //   char CounterIncrementWithCapCheck(int *this) {
    //     int v1 = *this + 1;
    //     bool v2 = (*this - 5) < 0;
    //     *this = v1;
    //     return (char)(v2 ^ __OFSUB__(v1, 6));
    //   }
    // UNRESOLVED: Caller-facing meaning of the returned flag (under-cap versus cap-reached) is not established; the boolean inverts at counter value 6 for non-overflowing ranges.
    // UNRESOLVED: Constants 5 and 6 appear as literals in the compiler-generated sign/overflow idioms; their domain significance is unknown.
    // UNRESOLVED: The prelabel cluster_copy proposal marks this as a structural twin of FloatClamp (004646c0) at DERIVED trust; no independent evidence links the two routines.
    // UNRESOLVED: The LEGACY ABI entry FAIL_586c90 provides no prototype and does not establish a caller contract.
}
