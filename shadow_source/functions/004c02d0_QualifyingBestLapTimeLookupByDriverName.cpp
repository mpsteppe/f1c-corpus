// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C02D0
// Canonical corpus name: sub_4C02D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4C02D0_004c02d0.c

void UnknownObject::QualifyingBestLapTimeLookupByDriverName()
{
    // Looks up a driver name in the season's Qualifying section and returns the qualifying time/score value. Finds the season races section, searches it for the "Qualifying" string key, then linearly scans up to 104 list entries comparing the driver name via sub_588410. On a match it reads the data entry and returns sub_58850F's value, rejecting results below 10.0; any failure path returns -1.0.
    // GUARD: Return -1.0 immediately when the driver-name argument a1 is NULL. [source:raw]
    // CALL: SeasonRacesSectionFinder(0) locates the season races data section, stored in v1. [callee:0x004C5840, source:raw]
    // GUARD: Return -1.0 if v1 is NULL or StringKeyedLinkedListSearch(v1, aQualifying) fails, i.e. no Qualifying section is present. [callee:0x005679C0, global:0x005D2640, source:raw]
    // LOOP: Infinite scan loop over list indexes v2; NullCheckWrapper(v2) returns each entry v3 (or NULL). [callee:0x005679A0, source:raw]
    // CALL: StringPointerAccessor(v3) retrieves the entry name string v5. [callee:0x00499E20, source:raw]
    // GUARD: When sub_588410(a1, v5) returns zero the driver name matches and the scan breaks. [callee:0x00588410, source:raw]
    // GUARD: Loop bound: return -1.0 when the index v2 reaches 104 without a match. [source:raw]
    // CALL: DataEntryAccessor(v4) yields the qualifying data entry, then sub_58850F(v7) reads its value into result. [callee:0x00567970, callee:0x0058850F, source:raw]
    // GUARD: Return -1.0 when the qualifying value is below 10.0 (invalid/minimum threshold). [source:raw]
    // RETURN: Return the qualifying time/score value on success, or -1.0 on every failure path. [source:raw]

    // Conservative worker pseudocode:
    //   double sub_4C02D0(_BYTE *driverName) {
    //     if (!driverName) return -1.0;
    //     void *races = SeasonRacesSectionFinder(0);
    //     if (!races || !StringKeyedLinkedListSearch(races, aQualifying)) return -1.0;
    //     int i = 0;
    //     for (;;) {
    //       void *entry = NullCheckWrapper(i);
    //       if (entry) {
    //         if (sub_588410(driverName, StringPointerAccessor(entry)) == 0) break;
    //       }
    //       if (++i >= 104) return -1.0;
    //     }
    //     double value = sub_58850F(DataEntryAccessor(entry));
    //     if (value < 10.0) return -1.0;
    //     return value;
    //   }
    // UNRESOLVED: Packet lists globals flt_59E5FC, flt_59E670 and unk_8AC368 as read, but none appears in the raw source text; their role here is unresolved.
    // UNRESOLVED: Exact semantics of the sub_588410 driver-name comparison and of the sub_58850F value (time versus score) are not resolved from this scope.
    // UNRESOLVED: Meaning of the 10.0 rejection threshold is inferred from prior analysis, not proven here.
    // UNRESOLVED: Owning object is UnknownObject; the only known caller is sub_4BFF70 (0x004BFF70).
}
