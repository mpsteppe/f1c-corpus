// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D5C40
// Canonical corpus name: ShortComputation_5c40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_5c40_004d5c40.c

void UnknownObject::ShortComputation_5c40()
{
    // Trivial reset routine: zeroes two adjacent module globals (dword_8AD254, dword_8AD258) and returns 0. No arguments, no calls, no branches.
    // ASSIGNMENT: result = 0: seed the return value. [source:raw]
    // ASSIGNMENT: dword_8AD254 = 0: write-zero the first global. [global:0x008AD254, source:raw]
    // ASSIGNMENT: dword_8AD258 = 0: write-zero the adjacent second global. [global:0x008AD258, source:raw]
    // RETURN: Return result, which is 0. [source:raw]

    // Conservative worker pseudocode:
    //   int ShortComputation_5c40() {
    //     int result = 0;
    //     dword_8AD254 = 0;
    //     dword_8AD258 = 0;
    //     return result;
    //   }
    // UNRESOLVED: What dword_8AD254 and dword_8AD258 represent and who consumes the reset is unknown.
    // UNRESOLVED: Caller context and the intended state being cleared are not established.
}
