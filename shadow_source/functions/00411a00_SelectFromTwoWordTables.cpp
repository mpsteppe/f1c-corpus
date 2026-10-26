// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411A00
// Canonical corpus name: ShortComputation_1a00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortComputation_1a00_00411a00.c

void UnknownObject::SelectFromTwoWordTables()
{
    // Resolves a1 through TableLookupByIndex; special result values 9875 and 9876 pass through unchanged, and negative results are rejected. Otherwise returns the indexed WORD from one of two tables (word_5BEBB0 when a2 is 0, word_5BF2F8 when a2 is 1), or -1 for any other a2.
    // CALL: result = TableLookupByIndex(a1) — resolve the input to a table index or special value. [callee:0x004144C0, source:raw]
    // GUARD: If result equals 9875 or 9876, return result directly without table lookup. [source:raw]
    // GUARD: If result is negative (>= 0 fails), return -1 as an error. [source:raw]
    // RETURN: When a2 is 0, return the WORD word_5BEBB0[result] from the first table. [global:0x005BEBB0, source:raw]
    // RETURN: When a2 is 1, return the WORD word_5BF2F8[result] from the second table. [global:0x005BF2F8, source:raw]
    // RETURN: For any a2 other than 0 or 1, return -1. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_411A00(int a1, int a2) {
    //     int result = TableLookupByIndex(a1);
    //     if (result == 9875 || result == 9876) return result;
    //     if (result >= 0) {
    //       if (a2 == 0) return word_5BEBB0[result];
    //       if (a2 == 1) return word_5BF2F8[result];
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: The meanings of the 9875/9876 pass-through sentinels and of the two tables (which word is being selected, from a2) depend on the caller FontRenderingPrep, which is not analyzed in this packet.
}
