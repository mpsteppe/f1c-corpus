// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589CA4
// Canonical corpus name: UtilityFunction_9ca4
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_9ca4_00589ca4.c

void UnknownObject::ForwardWithDefaultedArgs()
{
    // Thin __cdecl forwarder: passes the incoming UINT uExitCode through to sub_589CC6(uExitCode, 0, 0) and returns its result. No other logic, fields, or globals are touched.
    // CALL: Forward uExitCode to sub_589CC6 with two zeroed trailing arguments and return its result. [callee:0x00589CC6, source:raw]
    // RETURN: Return the result of the delegated call unchanged. [source:raw]
    // CALL: Called by sub_493C80 (0x00493C80), sub_4986D0 (0x004986D0), ArithmeticComparison_166b (0x0051166B) and sub_58A19E (0x0058A19E). [caller:0x00493C80, caller:0x004986D0, caller:0x0051166B, caller:0x0058A19E, source:raw]

    // Conservative worker pseudocode:
    //   int sub_589CA4(UINT uExitCode) {
    //     return sub_589CC6(uExitCode, 0, 0);
    //   }
    // UNRESOLVED: Purpose of sub_589CC6 and the meaning of its two zero arguments are unknown from this packet.
    // UNRESOLVED: The semantics of the UINT exit-code parameter depend on each caller's context.
}
