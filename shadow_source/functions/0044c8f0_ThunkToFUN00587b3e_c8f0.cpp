// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C8F0
// Canonical corpus name: ThunkToFUN00587b3e_c8f0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00587b3e_c8f0_0044c8f0.c

void UnknownObject::ThunkToFUN00587b3e_c8f0()
{
    // Trivial thunk: reads the null-subroutine pointer nullsub_34 (0x0044C900), passes its address cast to int to BooleanToIntConversion (0x00587B3E), and returns the resulting 0/1 integer. The wrapped stub has no executable body, so this reports the stub's presence through the shared boolean-to-int helper rather than performing any work.
    // CALL: Read the nullsub_34 function pointer from global 0x0044C900 and call BooleanToIntConversion (0x00587B3E) with its address cast to int. [callee:0x00587B3E, global:0x0044C900, abi:lead, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [callee:0x00587B3E, function:0x0044C8F0, source:raw]

    // Conservative worker pseudocode:
    //   int ThunkToFUN00587b3e_c8f0() {
    //       return BooleanToIntConversion((int)nullsub_34);
    //   }
    // UNRESOLVED: nullsub_34 is an empty stub with no executable body; the intended behavior of this thunk is unrecoverable from this packet.
    // UNRESOLVED: Whether BooleanToIntConversion invokes the passed pointer or merely tests its value is not established by this packet.
}
