// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041E920
// Canonical corpus name: BestLapEntrantFinder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BestLapEntrantFinder_0041e920.c

void UnknownObject::BestLapEntrantFinder()
{
    // Scans the standings sort buffer (dword_7D2DB0) and returns the entry with the highest value at field offset 408, optionally restricted to entries whose name matches a caller-supplied filter via sub_588410. In strict mode (a2 == 0) the caller expects a unique best: the function returns 0 if the best value is also held by any other entry, including the first entry. Entry name pointers default to byte_5EA438 when null.
    // ASSIGNMENT: Initialize the best-value accumulator v3 to -1 and the best-entry pointer v4 to null before any list scan. [function:0x0041E920, source:raw]
    // GUARD: Proceed only when LinkedListDereference(&dword_7D2DB0) yields a non-null standings node; otherwise skip all work and fall through to the return. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: When the name filter a1 is null the first entry is adopted directly; otherwise the first entry is adopted only if its name matches a1. [source:raw]
    // ASSIGNMENT: Resolve the first entry's name as *(char **)FixedOffsetReturn(firstNode), defaulting to &byte_5EA438 when the pointer is null. [callee:0x004C1390, global:0x005EA438, source:raw]
    // CALL: Compare the filter name against the entry name with sub_588410(a1, entryName). [callee:0x00588410, source:raw]
    // GUARD: Adopt the first entry only when its value at offset 408 is greater than -1. [source:raw]
    // ASSIGNMENT: Record the first entry as the current best: v4 = FixedOffsetReturn(firstNode) and v3 = *(v4 + 408). [callee:0x004C1390, source:raw]
    // LOOP: Scan every standings entry from index 0 while index < ActiveEntityCounter(list). [callee:0x004C1370, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALCULATION: Resolve the entry pointer at index v10 with ShortComputation_13a0(v10). [callee:0x004C13A0, source:raw]
    // GUARD: Consider an entry as a new best only when its value at offset 408 strictly exceeds the current best v3. [source:raw]
    // GUARD: In the scan the same name filter applies: when a1 is non-null the entry must match via sub_588410, with the entry name defaulting to &byte_5EA438 when null. [callee:0x00588410, global:0x005EA438, source:raw]
    // ASSIGNMENT: Replace the best candidate with the current entry: v4 = entry, v3 = *(entry + 408). [source:raw]
    // GUARD: Strict mode (a2 == 0) enters the uniqueness check; when a2 is non-zero the best entry is returned as-is. [source:raw]
    // GUARD: Strict check requires a best entry to exist (v4 != null), otherwise the function returns 0. [source:raw]
    // GUARD: Compare the best value against the first entry's value at offset 408; an equal value on a different entry forces a return of 0. [callee:0x004C1390, source:raw]
    // LOOP: Rescan every entry to detect any entry other than the best whose value at offset 408 equals v3. [callee:0x004C1370, callee:0x004C13A0, callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: Return 0 when a duplicate best value exists, otherwise return the best entry pointer v4. [function:0x0041E920, source:raw]

    // Conservative worker pseudocode:
    //   int BestLapEntrantFinder(char *nameFilter, char strict) {
    //     int bestValue = -1;
    //     int bestEntry = 0;
    //     if (!LinkedListDereference(&dword_7D2DB0)) return bestEntry;
    //     if (!nameFilter || NameMatches(nameFilter, FirstEntryName())) {
    //       if (FirstEntryValueAt408() > -1) {
    //         bestEntry = FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0));
    //         bestValue = *(int *)(bestEntry + 408);
    //       }
    //     }
    //     for (int i = 0; i < ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)); i++) {
    //       int entry = ShortComputation_13a0(i);
    //       if (*(int *)(entry + 408) > bestValue) {
    //         if (nameFilter && !NameMatches(nameFilter, EntryName(entry))) continue;
    //         bestEntry = entry;
    //         bestValue = *(int *)(entry + 408);
    //       }
    //     }
    //     if (!strict) {
    //       if (!bestEntry) return 0;
    //       if (bestEntry != FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0))
    //           && bestValue == *(int *)(FixedOffsetReturn(LinkedListDereference(&dword_7D2DB0)) + 408)) return 0;
    //       for (int j = 0; j < ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0)); j++) {
    //         if (bestEntry != ShortComputation_13a0(j)
    //             && bestValue == *(int *)(ShortComputation_13a0(j) + 408)) return 0;
    //         if (j + 1 >= ActiveEntityCounter(LinkedListDereference(&dword_7D2DB0))) return bestEntry;
    //       }
    //     }
    //     return bestEntry;
    //   }
    // UNRESOLVED: The meaning of the value at entry offset 408 (a best-lap time, index, or counter) is not established; only its comparison behavior is known.
    // UNRESOLVED: The exact comparison semantics of sub_588410 (exact match vs prefix) are not defined here.
    // UNRESOLVED: byte_5EA438 acts as a fallback default name/path when an entry's name pointer is null; its concrete content is unknown.
    // UNRESOLVED: Callers SeasonDisplayIDResolver (0x0041DAF0) and sub_4203F0 (0x004203F0) show how this helper is reached but not the meaning of the name and strict arguments they pass.
}
