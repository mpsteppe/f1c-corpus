// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F9B30
// Canonical corpus name: StateFlagComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StateFlagComputation_004f9b30.c

void UnknownObject::StateFlagComputation()
{
    // Computes a state flag value as 2 minus the result of sub_4F9B20, ORs in bit 4 when the parameter a1 is non-zero or byte_7CE254 (DisableHUD flag) is set, dispatches the value through CallWrapper_c060, and records a -2 dispatch result in byte_8AFE72 (audio init success flag). Returns the dispatch status code.
    // CALCULATION: Compute the base flag value v1 = 2 - sub_4F9B20(). [callee:0x004F9B20, source:raw]
    // GUARD: If parameter a1 is non-zero OR byte_7CE254 (DisableHUD flag) is set, OR bit 4 into the flag value v1. [global:0x007CE254, source:raw]
    // CALL: Dispatch the computed flag value through CallWrapper_c060 and store its returned status code as result. [callee:0x0055C060, function:0x004F9B30, source:raw]
    // STATE_TRANSITION: If the dispatch returns -2, set byte_8AFE72 (audio init success flag) to 1. [global:0x008AFE72, source:raw]
    // RETURN: Return the dispatch status code. [source:raw]

    // Conservative worker pseudocode:
    //   int result = CallWrapper_c060(2 - sub_4F9B20() | ((a1 || byte_7CE254) ? 4 : 0));
    //   if (result == -2)
    //       byte_8AFE72 = 1;
    //   return result;
    // UNRESOLVED: dword_8AFE64 (0x008AFE64) appears in the packet globals list but is never referenced in the raw source text; treated as a packet-level association only, no usage recovered.
}
