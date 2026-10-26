// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041F220
// Canonical corpus name: ChampionshipPointsAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ChampionshipPointsAccumulator_0041f220.c

void UnknownObject::AccumulateChampionshipPointsByName()
{
    // Accumulates championship scoring points for a named entrant across a category count. Dereferences the RaceStandingsSortBuffer wrapper dword_7D2DB0, caches the active standings-entry count, then for each category column i sums IndexedFieldGetter(entry, i) over every active standings entry whose resolved scene name matches the input name a1. A null name pointer returns -1; a category count of -1 bypasses the per-category loops and returns the alternate total-points answer from sub_4C13C0.
    // CALL: LinkedListDereference(&dword_7D2DB0) dereferences the RaceStandingsSortBuffer list wrapper to fetch the current standings node. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Initialize the accumulator v5 = 0 before any accumulation. [source:raw]
    // CALL: ActiveEntityCounter(v4) counts the active standings entries into v13; this count becomes the inner-loop bound. [callee:0x004C1370, source:raw]
    // GUARD: Guard: when the name pointer a1 is null, return -1 immediately. [source:raw, function:0x0041F220]
    // GUARD: Guard: when the category count a2 is -1, return sub_4C13C0(a1) - the alternate total-points-for-entrant lookup that bypasses the per-category accumulation. [callee:0x004C13C0, source:raw]
    // LOOP: Outer loop over category index i in [0, a2): each iteration accumulates the category-i scoring column for matching standings entries. [source:raw, function:0x0041F220]
    // CALL: Re-dereference the standings wrapper and take the first/base entry pointer via FixedOffsetReturn; the result is discarded at the call site, suggesting side-effect state consumed by the name lookup. [callee:0x004C2850, callee:0x004C1390, source:raw]
    // CALL: SceneNameLookupBySeason(v15, 80) fills the 80-byte stack buffer with the scene/track name associated with the current standings entry. [callee:0x004C0A20, source:raw]
    // GUARD: sub_566810(v15, a1) compares the resolved scene name against the input name; on match the first/base-entry column value is accumulated. [callee:0x00566810, source:raw]
    // CALCULATION: v5 += IndexedFieldGetter(firstEntry, i): add the scoring value at category column i for the first/base entry. [callee:0x0041ED20, callee:0x004C1390, source:raw]
    // LOOP: Inner loop over entry index j in [0, v13): iterate every active standings entry for the current category. [callee:0x004C1370, source:raw]
    // CALL: ShortComputation_13a0(j) resolves the standings entry pointer for index j; the result is discarded at this call site, again implying shared side-effect state. [callee:0x004C13A0, source:raw]
    // CALL: SceneNameLookupBySeason(v15, 80) fills the scene-name buffer for the per-entry state. [callee:0x004C0A20, source:raw]
    // GUARD: sub_566810(v15, a1) name-match test for the per-entry lookup; matched entries contribute to the accumulator. [callee:0x00566810, source:raw]
    // CALCULATION: v5 += IndexedFieldGetter(entryJ, i): add the scoring value at category column i for entry j. [callee:0x0041ED20, callee:0x004C13A0, source:raw]
    // RETURN: Return the accumulated v5 total, or -1 when the null-name guard fired, or sub_4C13C0's total when a2 was -1. [source:raw, function:0x0041F220]
    // CALL: Called by ScoringClassificationDisplay (0041E320), sub_41F340 (0041F340), sub_41F5D0 (0041F5D0), ConstructorChampionshipClinchDetection (0041F8A0), TimingDifferenceChecker (0041FDB0), ConstructorStandingsParser (00420820) and GdbSeasonSelector (00420CF0) to total championship points for a named entrant. [caller:0x0041E320, caller:0x0041F340, caller:0x0041F5D0, caller:0x0041F8A0, caller:0x0041FDB0, caller:0x00420820, caller:0x00420CF0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_41F220(char *name, int categoryCount) {
    //     standings = LinkedListDereference(&dword_7D2DB0);
    //     total = 0;
    //     activeCount = ActiveEntityCounter(standings);
    //     if (!name) return -1;
    //     if (categoryCount == -1) return sub_4C13C0(name);
    //     for (i = 0; i < categoryCount; ++i) {
    //       LinkedListDereference(&dword_7D2DB0);
    //       FixedOffsetReturn();
    //       SceneNameLookupBySeason(v15, 80);
    //       if (sub_566810(v15, name)) {
    //         first = FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0));
    //         total += IndexedFieldGetter(first, i);
    //       }
    //       for (j = 0; j < activeCount; ++j) {
    //         LinkedListDereference(&dword_7D2DB0);
    //         ShortComputation_13a0(j);
    //         SceneNameLookupBySeason(v15, 80);
    //         if (sub_566810(v15, name)) {
    //           entry = ShortComputation_13a0(LinkedListDereference(&dword_7D2DB0));
    //           total += IndexedFieldGetter(entry, i);
    //         }
    //       }
    //     }
    //     return total;
    //   }
    // UNRESOLVED: The discarded return values of LinkedListDereference and FixedOffsetReturn / ShortComputation_13a0 suggest those calls drive shared side-effect state that SceneNameLookupBySeason consumes, but the mechanism is not visible inside this function.
    // UNRESOLVED: The first/base-entry accumulation for a category runs before the full per-entry scan of the same category, so a matching first entry may be counted twice per category unless FixedOffsetReturn and ShortComputation_13a0(j) resolve distinct nodes.
    // UNRESOLVED: a1 is a pointer compared by sub_566810; its concrete type (driver vs constructor name) is not established by this packet.
}
