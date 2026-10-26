// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044D850
// Canonical corpus name: ThunkToFUN00587b3e_d850
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ThunkToFUN00587b3e_d850_0044d850.c

void UnknownObject::ThunkToFUN00587b3e_d850()
{
    // Trivial thunk: reads the nullsub_143 stub function pointer at 0x0044D860, casts it to an int, passes it to BooleanToIntConversion at 0x00587B3E, and returns the boolean-to-int result directly. The declared/abi name carries only a thunk-to-helper hint; the wrapped stub target has no executable body to analyze.
    // CALL: Read the nullsub_143 function pointer at 0x0044D860, cast it to an int, and pass it as the argument to BooleanToIntConversion. [source:raw, global:0x0044D860, callee:0x00587B3E]
    // RETURN: Return the integer produced by BooleanToIntConversion. [source:raw]

    // Conservative worker pseudocode:
    //   int ThunkToFUN00587b3e_d850() {
    //     return BooleanToIntConversion((int)nullsub_143);
    //   }
    // UNRESOLVED: nullsub_143 is an empty stub; its intended behavior is unrecoverable from this packet.
    // UNRESOLVED: The thunk/registration intent is carried only by the declared and abi names (LEGACY trust); no static caller or field evidence grounds what is being routed through BooleanToIntConversion.
    // UNRESOLVED: Whether BooleanToIntConversion invokes the passed function pointer or only converts its numeric value is not established from this packet.
}
