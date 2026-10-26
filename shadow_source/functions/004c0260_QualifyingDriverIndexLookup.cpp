// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C0260
// Canonical corpus name: sub_4C0260
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C0260_004c0260.c

void UnknownObject::QualifyingDriverIndexLookup()
{
    // Looks up a driver name string a1 in the season's Qualifying section and returns its 1-based grid position (v2 + 1). Locates the season races section with SeasonRacesSectionFinder(0), finds the Qualifying key with StringKeyedLinkedListSearch, then linearly scans up to 104 list entries comparing each entry's string (via StringPointerAccessor) against a1 with sub_588410. Returns 104 (max vehicle count sentinel) when a1 is NULL, the section or key is missing, or no match is found.
    // GUARD: Guard on a1: a NULL driver-name pointer returns 104 immediately. [source:raw]
    // CALL: v1 = SeasonRacesSectionFinder(0) locates the season races data section. [callee:0x004C5840, source:raw]
    // GUARD: Guard on v1 and the Qualifying key: if the section is NULL or StringKeyedLinkedListSearch(v1, aQualifying) fails, return 104. [callee:0x005679C0, global:0x005D2640, source:raw]
    // LOOP: Linear scan over slots v2 = 0 upward, bounded at 104 entries. [source:raw]
    // CALL: v3 = NullCheckWrapper(v2) fetches the entry at slot v2 with a null check. [callee:0x005679A0, source:raw]
    // GUARD: Guard on v3 being non-null before the entry is dereferenced. [source:raw]
    // CALL: v4 = StringPointerAccessor(v3) extracts the string pointer from the list entry. [callee:0x00499E20, source:raw]
    // GUARD: Compare the driver name with sub_588410(a1, v4); when it returns 0 the entry matches and the scan breaks. [callee:0x00588410, source:raw]
    // GUARD: Terminate with 104 when the counter reaches 104 without a match. [source:raw]
    // RETURN: Return v2 + 1, the 1-based qualifying grid position of the matched entry. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4C0260(char* driver) {
    //     if (!driver) return 104;
    //     sec = SeasonRacesSectionFinder(0);
    //     if (!sec || !StringKeyedLinkedListSearch(sec, aQualifying)) return 104;
    //     for (v2 = 0; v2 < 104; ++v2) {
    //       ent = NullCheckWrapper(v2);
    //       if (ent && !sub_588410(driver, StringPointerAccessor(ent))) return v2 + 1;
    //     }
    //     return 104;
    //   }
    // UNRESOLVED: Global unk_8AC368 is listed in the packet but never appears in the raw source; its role here is unconfirmed.
    // UNRESOLVED: The legacy ABI name 'Qualifying_Driver_Index_Lookup' (abi:lead) is adopted as the proposed name but is not independently confirmed.
    // UNRESOLVED: The structure of the season races section and the meaning of the value 0 passed to SeasonRacesSectionFinder are not established by the packet.
}
