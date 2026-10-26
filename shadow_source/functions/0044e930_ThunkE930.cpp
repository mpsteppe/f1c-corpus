// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044E930
// Canonical corpus name: Thunk_e930
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_e930_0044e930.c

void UnknownObject::ThunkE930()
{
    // Minimal thunk wrapper: returns BooleanToIntConversion((int)nullsub_188). The nullsub_188 global (a stub function pointer at 0x0044E940) is read, cast to an integer, and passed to the BooleanToIntConversion helper (0x00587B3E), whose normalized result is returned directly. The stub target has no body to analyze.
    // CALL: Read the nullsub_188 function pointer at 0x0044E940, cast it to an int, and pass it as the argument to BooleanToIntConversion. [source:raw, global:0x0044E940, callee:0x00587B3E]
    // RETURN: Return the integer produced by BooleanToIntConversion. [source:raw]

    // Conservative worker pseudocode:
    //   int ThunkE930() {
    //     return BooleanToIntConversion((int)nullsub_188);
    //   }
    // UNRESOLVED: nullsub_188 is an empty stub (its target contains no executable body); its intended behavior is unrecoverable from this packet.
    // UNRESOLVED: The thunk role is carried only by the canonical/abi name (LEGACY trust); no caller or field evidence grounds what is being wrapped.
    // UNRESOLVED: Whether BooleanToIntConversion invokes the passed pointer or merely tests/coerces its value is not established by this packet.
}
