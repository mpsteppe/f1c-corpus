// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00411AB0
// Canonical corpus name: RandomRangeTableInitializer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RandomRangeTableInitializer_00411ab0.c

void UnknownObject::RandomRangeTableInitializer()
{
    // Two-phase initialization of a 537-entry table of 16-bit pairs behind the this pointer. Phase 1 writes (1, 0) into every pair. Phase 2, for indices 1..290 (table word_5BEBB0) and 293..535 (table word_5BF2F8), asks TableLookupByIndex for a per-index table offset v5; when v5 >= 0 it computes a range size v7 = table[v5+1] - table[v5] and, when v7 > 0, stores (v7, RandLCGRandomNumberGenerator() % v7) as (range, random offset) into the pair. Indices {0, 291, 292, 536} keep the default (1, 0). Returns 0. Called by WrapperReturning0 (0x004116B0).
    // LOOP: Phase 1: for i in 0..536 set this[2*i] = 1 and this[2*i+1] = 0, giving every pair a default (range=1, offset=0) [source:raw]
    // LOOP: Phase 2: for j in 0..536 decide per index whether the default pair is replaced with a randomized one [source:raw]
    // GUARD: Edge indices keep the default: j == 0 and j == 536 are skipped; j == 291 and j == 292 are continued past without modification [source:raw]
    // CALL: TableLookupByIndex(j) at 0x004144C0 returns the per-index offset v5 used to address the range-boundary table [callee:0x004144C0, source:raw]
    // GUARD: Indices whose lookup returns v5 < 0 are skipped; the boundary table is selected by index band: word_5BEBB0 for j in 1..290, word_5BF2F8 for j in 293..535 (with a redundant continue guard j <= 292 || j >= 536) [global:0x005BEBB0, global:0x005BF2F8, source:raw]
    // CALCULATION: Range size v7 = v6[v5 + 1] - v6[v5]; the pair is only overwritten when v7 > 0 [source:raw]
    // CALL: RandLCGRandomNumberGenerator() at 0x005884ED produces the pseudo-random value for the offset draw [callee:0x005884ED, source:raw]
    // CALCULATION: Random offset v8 = RandLCGRandomNumberGenerator() % v7, bounded to [0, v7) [source:raw]
    // ASSIGNMENT: Store the pair this[2*j] = v7 (range) and this[2*j + 1] = v8 (random offset within the range) [source:raw]
    // RETURN: Returns 0 after both phases complete [function:0x00411AB0, source:raw]
    // CALL: Invoked by WrapperReturning0 (0x004116B0) to populate the randomized range table at startup [caller:0x004116B0]

    // Conservative worker pseudocode:
    //   for (i = 0; i < 537; ++i) {
    //       this[2*i] = 1;
    //       this[2*i + 1] = 0;
    //   }
    //   for (j = 0; j < 537; ++j) {
    //       if (j == 0 || j == 536) continue;
    //       if (j == 291 || j == 292) continue;
    //       v5 = TableLookupByIndex(j);
    //       if (v5 < 0) continue;
    //       v6 = (j >= 1 && j <= 290) ? word_5BEBB0 : word_5BF2F8;
    //       v7 = v6[v5 + 1] - v6[v5];
    //       if (v7 <= 0) continue;
    //       v8 = RandLCGRandomNumberGenerator() % v7;
    //       this[2*j] = v7;
    //       this[2*j + 1] = v8;
    //   }
    //   return 0;
    // UNRESOLVED: The meaning of the 537-entry (range, offset) table and the consumer that later reads it is unknown; the fill names it driver-random-range related but that is DERIVED prose, not evidenced here
    // UNRESOLVED: The purpose of the boundary indices {291, 292} and the two index bands (1..290 vs 293..535) is unexplained
    // UNRESOLVED: The contents of word_5BEBB0 and word_5BF2F8 (16-bit range boundaries) and how TableLookupByIndex maps an index to v5 are not documented in this function
}
