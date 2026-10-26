// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404FA0
// Canonical corpus name: sub_404FA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_404FA0_00404fa0.c

void UnknownObject::FilterNameByIndex()
{
    // Bounded lookup into the string table starting at global aLowpassFilter: for index a1 < 4 returns the address of the a1-th 32-byte-strided entry, otherwise returns NULL. The label aLowpassFilter and the caller MilesSoundSystemFilterOpenByIndex imply this maps a sound-filter index to a filter-name string, but only entry 0 is evidenced by the label.
    // GUARD: If a1 >= 4, bail out with a NULL result. [function:0x00404FA0, source:raw]
    // ASSIGNMENT: Initialize result to 0 before the range check. [function:0x00404FA0, source:raw]
    // CALCULATION: Address of entry = &aLowpassFilter[32 * a1], a 32-byte stride between table rows. [function:0x00404FA0, global:0x005BE720, source:raw]
    // RETURN: Return the entry pointer for a1 < 4, else NULL. [function:0x00404FA0, global:0x005BE720, source:raw]

    // Conservative worker pseudocode:
    //   result = 0;
    //   if (a1 < 4) return &aLowpassFilter[32 * a1];
    //   return result;
    // UNRESOLVED: Only table entry 0 is identifiable (the string label aLowpassFilter); the text of entries 1..3 is not evidenced in this packet.
    // UNRESOLVED: The 32-byte stride suggests fixed-size null-padded name records, but the record layout is not evidenced.
    // UNRESOLVED: How MilesSoundSystemFilterOpenByIndex (00405D70) consumes the returned name is outside this packet.
    // UNRESOLVED: The set of valid indexes (0..3, i.e. exactly 4 entries) is observed only from the a1 < 4 guard.
}
