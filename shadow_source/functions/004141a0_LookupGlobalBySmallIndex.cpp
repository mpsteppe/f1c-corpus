// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004141A0
// Canonical corpus name: ShortComputation_41a0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_41a0_004141a0.c

void UnknownObject::LookupGlobalBySmallIndex()
{
    // Indexed lookup over a two-entry set of module globals. For a1 == 0 returns dword_5BF8CC, for a1 == 1 returns dword_5BF8D4, and for any a1 > 1 returns -1. The parameter is an unsigned small index that selects between two adjacent global dwords.
    // ASSIGNMENT: Initialize the default result to -1 before the range check. [source:raw]
    // GUARD: Guard on a1 <= 1; only indices 0 and 1 reach the lookup, everything larger falls through to the -1 default. [source:raw]
    // GUARD: Nested guard on a1 being non-zero; separates the a1 == 1 path from the a1 == 0 path. [source:raw]
    // RETURN: Return dword_5BF8CC when a1 == 0. [source:raw]
    // RETURN: Return dword_5BF8D4 when a1 == 1. [source:raw]
    // RETURN: Return the default -1 for any a1 > 1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4141A0(unsigned int idx) {
    //     if (idx <= 1) {
    //       if (idx != 0) return dword_5BF8D4;  // idx == 1
    //       return dword_5BF8CC;                // idx == 0
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The packet global list names 0x005BF8C8 (read) while the raw source reads dword_5BF8CC and dword_5BF8D4; these addresses are adjacent, suggesting one small table anchored near 0x005BF8C8, but the exact base and layout are unconfirmed.
    // UNRESOLVED: Semantic role is context-dependent: called by DriverNameIDLookup, TrackNameDisplayIDLookup and two unnamed callers, so the selected dwords likely feed a name/ID display lookup, but the mapping is unconfirmed.
}
