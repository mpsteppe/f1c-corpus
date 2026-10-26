// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00487740
// Canonical corpus name: RangeCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RangeCheck_00487740.c

void UnknownObject::RangeCheck()
{
    // Range check helper: delegates to ShortComputation_6720(this) to obtain an integer value and returns true only when that value lies in the inclusive range [2, 3]. No side effects; reads state only through the callee.
    // CALL: Call ShortComputation_6720(this) and store its integer result in v1. [callee:0x00486720, source:raw]
    // GUARD: Compare the delegated result: return true only when v1 >= 2 and v1 <= 3. [source:raw]
    // RETURN: Return the boolean result of the range comparison (v1 in [2, 3]). [source:raw]

    // Conservative worker pseudocode:
    //   bool sub_487740(void *this) {
    //     int v1 = ShortComputation_6720(this);
    //     return v1 >= 2 && v1 <= 3;
    //   }
    // UNRESOLVED: Meaning of the two guarded values (2 and 3): which range or state they represent is not established.
    // UNRESOLVED: Semantics of the value produced by ShortComputation_6720 are outside this function's packet.
}
