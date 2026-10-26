// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041E890
// Canonical corpus name: AIEntrantLookupByName
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIEntrantLookupByName_0041e890.c

void UnknownObject::AIEntrantLookupByName()
{
    // Searches the standings sort buffer (dword_7D2DB0) for the first entry whose name matches the input name string `this`, and returns that entry's value at offset 408 (the entrant ID/index). Iterates candidate indices 0..102; each candidate is resolved through ShortComputation_13a0, its name pointer is read from entry offset 0 (defaulting to &byte_5EA438 when null), and sub_588410 compares it against the input. Returns 0 when no match is found within 103 entries.
    // ASSIGNMENT: Initialize the candidate index v2 to 0 before the search loop. [function:0x0041E890, source:raw]
    // LOOP: Iterate candidate indices from 0 upward; the loop exits on a name match or when the index reaches 103. [function:0x0041E890, source:raw]
    // GUARD: Proceed with the candidate only when LinkedListDereference(&dword_7D2DB0) resolves a non-null standings node; otherwise skip to the index advance. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // CALL: Re-resolve the standings node with LinkedListDereference(&dword_7D2DB0) before fetching the candidate entry. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: Continue only when ShortComputation_13a0(v2) yields a non-null entry pointer for the current index. [callee:0x004C13A0, source:raw]
    // CALL: Re-resolve the standings node with LinkedListDereference(&dword_7D2DB0) before reading the entry name. [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // ASSIGNMENT: Read the candidate name pointer v3 = *(char **)ShortComputation_13a0(v2) (entry offset 0), defaulting to &byte_5EA438 when the pointer is null. [callee:0x004C13A0, global:0x005EA438, source:raw]
    // CALL: Compare the candidate name v3 against the input name `this` with sub_588410(v3, this); a zero return (match) breaks the search loop. [callee:0x00588410, source:raw]
    // GUARD: Advance the candidate index; when ++v2 reaches 103 the search is exhausted and returns 0. [function:0x0041E890, source:raw]
    // CALL: On a name match, re-resolve the standings node with LinkedListDereference(&dword_7D2DB0). [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // RETURN: Return *(_DWORD *)(ShortComputation_13a0(v2) + 408), the matched entry's value at offset 408 (entrant ID/index). [callee:0x004C13A0, function:0x0041E890, source:raw]
    // RETURN: Return 0 when the loop exhausts all 103 candidate indices without a name match. [function:0x0041E890, source:raw]

    // Conservative worker pseudocode:
    //   int AIEntrantLookupByName(const char *inputName) {
    //     int i = 0;
    //     for (;;) {
    //       if (LinkedListDereference(&dword_7D2DB0)) {
    //         LinkedListDereference(&dword_7D2DB0);
    //         void *entry = ShortComputation_13a0(i);
    //         if (entry) {
    //           LinkedListDereference(&dword_7D2DB0);
    //           const char *name = *(const char **)entry;
    //           if (!name) name = &byte_5EA438;
    //           if (NameCompare(name, inputName) == 0) break;
    //         }
    //       }
    //       if (++i >= 103) return 0;
    //     }
    //     LinkedListDereference(&dword_7D2DB0);
    //     return *(int *)((char *)ShortComputation_13a0(i) + 408);
    //   }
    // UNRESOLVED: The meaning of the returned value at entry offset 408 (entrant ID/index per existing analysis) is not proven by this packet.
    // UNRESOLVED: sub_588410's exact comparison semantics (equality vs prefix) are not defined here; only that a zero return triggers a match/break.
    // UNRESOLVED: byte_5EA438 acts as a fallback default name when an entry's name pointer is null; its concrete content is unknown.
    // UNRESOLVED: The 103-entry bound and the relationship between the entry index and the returned value at offset 408 are not explained by the packet alone.
}
