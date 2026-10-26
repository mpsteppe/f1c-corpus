// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00462140
// Canonical corpus name: ShortComputation_2140
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_2140_00462140.c

void UnknownObject::consumeRefreshFlag()
{
    // Test-and-clear helper for a single global refresh flag. If byte_7CD2A0 is clear it returns 0 without touching it; otherwise it clears the flag and returns 1, so each set flag is consumed exactly once by the poller (the known caller is ConditionalChain).
    // GUARD: Guard on byte_7CD2A0: when the flag is clear (0) the function returns 0 and does not clear it. [global:0x007CD2A0, source:raw]
    // ASSIGNMENT: Clear the refresh flag: byte_7CD2A0 = 0. [global:0x007CD2A0, source:raw]
    // RETURN: Return 1 when the flag was set (and is now consumed), or 0 when it was already clear. [source:raw]

    // Conservative worker pseudocode:
    //   char consumeRefreshFlag() {
    //     if (!byte_7CD2A0)
    //       return 0;
    //     byte_7CD2A0 = 0;
    //     return 1;
    //   }
    // UNRESOLVED: Which subsystem sets byte_7CD2A0 and what re-evaluation it requests is not established; the single known consumer is ConditionalChain (0x00475570).
}
