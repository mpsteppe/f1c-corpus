// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A0CF0
// Canonical corpus name: ConditionalInitGuard
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalInitGuard_004a0cf0.c

void UnknownObject::ConditionalInitGuard()
{
    // Gate-protected initialization: reads the gate byte_7CE254 into result, and when it is zero runs the session-state initialization routine sub_4A0250 and resets dword_7CE258 to zero. Returns the gate value (or the result of sub_4A0250 after it runs).
    // ASSIGNMENT: Read the gate value byte_7CE254 into result. [global:0x007CE254, source:raw]
    // GUARD: Guard on byte_7CE254 being zero; only then run the initialization path. [global:0x007CE254, source:raw]
    // CALL: Run the session-state initialization routine sub_4A0250 and take its result. [callee:0x004A0250, source:raw]
    // ASSIGNMENT: Reset dword_7CE258 to zero. [global:0x007CE258, source:raw]
    // RETURN: Return the gate value (or the initialization result when the path ran). [global:0x007CE254, source:raw]

    // Conservative worker pseudocode:
    //   char sub_4A0CF0() {
    //     char result = byte_7CE254;
    //     if (!byte_7CE254) {
    //       result = sub_4A0250();
    //       dword_7CE258 = 0;
    //     }
    //     return result;
    //   }
    // UNRESOLVED: unk_7CE24C is listed as a read global but is absent from the raw source; its role (likely adjacent session-state data) is unresolved.
    // UNRESOLVED: Semantics of byte_7CE254 (DisableHUDFlag per prior analysis) and dword_7CE258 are not grounded by the raw source alone.
    // UNRESOLVED: Purpose and signature of sub_4A0250 are unknown from this packet alone.
}
