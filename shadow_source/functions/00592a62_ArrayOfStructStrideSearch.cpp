// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592A62
// Canonical corpus name: ArrayOfStructStrideSearch
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ArrayOfStructStrideSearch_00592a62.c

void UnknownObject::ArrayOfStructStrideSearch()
{
    // Linear search over an array of fixed-stride records: each record occupies 3 DWORDs (12 bytes) and is identified by its first DWORD. Searches for a record whose key equals a1, bounded by the record count in global dword_5E7894. Returns a pointer to the matching record, or 0 when no record matches.
    // ASSIGNMENT: Seed result with a2, the start of the record array. [source:raw]
    // GUARD: If the first record's key (*a2) already equals a1, skip the search loop. [source:raw]
    // LOOP: Advance result by 3 DWORDs (one 12-byte record) while result stays below the array end bound a2 + 3 * dword_5E7894 and the current record's key differs from a1. [source:raw, global:0x005E7894]
    // GUARD: If result reached the end bound or the final record's key still differs from a1, report not-found. [source:raw, global:0x005E7894]
    // RETURN: Return 0 when the key was not found. [source:raw]
    // RETURN: Return the pointer to the matching record when found. [source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *sub_592A62(int a1, _DWORD *a2) {
    //     _DWORD *result = a2;
    //     if (*a2 != a1) {
    //       do result += 3;
    //       while (result < &a2[3 * dword_5E7894] && *result != a1);
    //     }
    //     if (result >= &a2[3 * dword_5E7894] || *result != a1) return 0;
    //     return result;
    //   }
    // UNRESOLVED: Record layout beyond the key DWORD; the other two DWORDs per stride are never touched here.
    // UNRESOLVED: How the record count in dword_5E7894 is maintained.
    // UNRESOLVED: Identity of the record type and the caller sub_592924's array semantics.
}
