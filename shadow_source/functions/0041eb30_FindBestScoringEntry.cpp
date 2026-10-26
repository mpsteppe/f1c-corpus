// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041EB30
// Canonical corpus name: ScoringSessionStatsAggregator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScoringSessionStatsAggregator_0041eb30.c

void UnknownObject::FindBestScoringEntry()
{
    // Aggregates scoring values from the standings node at dword_7D2DB0: for each scoring category it accumulates the base entry's score into accumulator slot 0 and each indexed entry's score into its slot, then finds the entry with the highest accumulated total, optionally filtered by name via sub_588410 (with byte_5EA438 as the fallback name). Returns the best entry pointer, or 0 on a tie when the strict flag a2 is not set, or when the standings node is absent or the category count is less than 2.
    // CALL: Dereference the standings node from dword_7D2DB0 via LinkedListDereference; when absent, the function returns null. [callee:0x004C2850, global:0x007D2DB0]
    // CALL: Read the number of scoring categories from the node via FlagsGetter. [callee:0x004C11D0]
    // CALL: Count the active standings entries via ActiveEntityCounter. [callee:0x004C1370]
    // ASSIGNMENT: Zero the 26-slot score accumulator array. [source:raw]
    // GUARD: If the category count is less than 2, return 0. [source:raw]
    // LOOP: For each category, add the base entry's score (via FixedOffsetReturn and IndexedFieldGetter) into slot 0 and each indexed entry's score (via ShortComputation_13a0 and IndexedFieldGetter) into slot k+1. [callee:0x004C1390, callee:0x004C13A0, callee:0x0041ED20]
    // CALL: When a name filter a1 is given, compare the base entry's name against it via sub_588410, using byte_5EA438 when the entry's name pointer is null. [callee:0x00588410, global:0x005EA438]
    // ASSIGNMENT: Track the best accumulated total v16 and the best entry pointer v27. [source:raw]
    // LOOP: Scan the remaining entries; when an entry's accumulated total exceeds v16, re-apply the same name filter and update v27 and v16. [callee:0x004C13A0, callee:0x00588410, source:raw]
    // GUARD: Tie handling with the base/first entry: when the best entry differs from the base entry and ties its total, return the best pointer if the strict flag a2 is set, else 0. [source:raw]
    // LOOP: Scan every entry for a further tie with v16; on a tie return the best pointer if a2 is set, else 0, otherwise return the best pointer. [source:raw]
    // RETURN: Return the best entry pointer, or 0 when the standings node is absent. [source:raw]

    // Conservative worker pseudocode:
    //   int find_best(int name, char strict) {
    //       void *node = LinkedListDereference(&dword_7D2DB0);
    //       if (!node) return 0;
    //       int categories = FlagsGetter(node);
    //       int count = ActiveEntityCounter(node);
    //       int totals[26]; memset(totals, 0, sizeof(totals));
    //       if (categories < 2) return 0;
    //       for (i = 0; i < categories - 1; ++i) {
    //           totals[0] += IndexedFieldGetter(FixedOffsetReturn(node), i);
    //           for (k = 0; k < count; ++k)
    //               totals[k + 1] += IndexedFieldGetter(ShortComputation_13a0(k), i);
    //       }
    //       int bestTotal = (name ? match_name(base, name) : 1) ? totals[0] : 0;
    //       void *best = bestTotal ? FixedOffsetReturn(node) : 0;
    //       for (j = 0; j < count; ++j)
    //           if (totals[j + 1] > bestTotal && (name ? match_name(ShortComputation_13a0(j), name) : 1))
    //               { best = ShortComputation_13a0(j); bestTotal = totals[j + 1]; }
    //       if (best != FixedOffsetReturn(node) && bestTotal == totals[0]) return strict ? best : 0;
    //       for (k = 0; k < count; ++k)
    //           if (best != ShortComputation_13a0(k) && bestTotal == totals[k + 1]) return strict ? best : 0;
    //       return best;
    //   }
    // UNRESOLVED: How FlagsGetter's category count and IndexedFieldGetter's indices map to the standings columns.
    // UNRESOLVED: The fallback string byte_5EA438 used when an entry's name pointer is null.
    // UNRESOLVED: The external meaning of the strict flag a2; the tie behavior is rendered directly from the code but not confirmed by an independent source.
}
