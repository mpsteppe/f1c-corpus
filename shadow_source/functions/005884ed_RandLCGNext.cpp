// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005884ED
// Canonical corpus name: RandLCGRandomNumberGenerator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandLCGRandomNumberGenerator_005884ed.c

void UnknownObject::RandLCGNext()
{
    // Linear congruential pseudo-random number generator. Retrieves the TLS state block via TLSValueRetrievalWithInit, advances the state dword at TLS+20 through the MSVCRT LCG recurrence state = 214013 * state + 2531011, stores it back, and returns the high 15 bits of the new state (HIWORD(state) & 0x7FFF). The legacy ABI label identifies it as the CRT rand(). Called from dozens of sites across AI, audio, physics, particle, damage and random-selection code paths.
    // CALL: Call TLSValueRetrievalWithInit to obtain the TLS state block base into v0. [callee:0x0058E0C7, source:raw]
    // CALCULATION: Compute v1 = 214013 * *(v0 + 20) + 2531011. [source:raw]
    // ASSIGNMENT: Store the new state back into the dword at v0 + 20. [source:raw]
    // RETURN: Return the high word of the new state masked to 15 bits: HIWORD(v1) & 0x7FFF. [function:0x005884ED, source:raw]

    // Conservative worker pseudocode:
    //   v0 = TLSValueRetrievalWithInit();
    //   v1 = 214013 * *(v0 + 20) + 2531011;
    //   *(v0 + 20) = v1;
    //   return HIWORD(v1) & 0x7FFF;
    // UNRESOLVED: Structure of the TLS state block (only the state dword at +20 is touched here) is unknown.
    // UNRESOLVED: Why the return uses HIWORD(state) & 0x7FFF rather than the classic (state / 65536) % 32768 spelling is a compiler artifact; both yield the same 15-bit value.
    // UNRESOLVED: Owner object is not applicable; the function is a free __cdecl CRT-style routine.
}
