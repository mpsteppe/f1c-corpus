// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044C9B0
// Canonical corpus name: Thunk_c9b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/Thunk_c9b0_0044c9b0.c

void UnknownObject::Thunk_c9b0()
{
    // Registration thunk returning the integer conversion of a function pointer stored in nullsub_36 (0x0044C9C0). The global holds a null-subroutine pointer; the function forwards it to BooleanToIntConversion (0x00587B3E) and returns the resulting 0/1 int. No arguments, branches, or fields. The wrapped no-op target has no body to analyze; semantics beyond the raw body are not evidenced by the packet.
    // CALL: Call BooleanToIntConversion with the nullsub_36 function pointer (read from global 0x0044C9C0, cast to int) as its argument. [callee:0x00587B3E, global:0x0044C9C0, abi:lead, source:raw]
    // RETURN: Return the integer result produced by BooleanToIntConversion. [callee:0x00587B3E, function:0x0044C9B0]

    // Conservative worker pseudocode:
    //   int Thunk_c9b0() {
    //       return BooleanToIntConversion((int)nullsub_36);
    //   }
    // UNRESOLVED: What nullsub_36 represents (no-op function pointer) and why its integer conversion is returned; no caller or registration-site evidence in the packet.
}
