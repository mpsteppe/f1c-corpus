// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047F230
// Canonical corpus name: sub_47F230
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47F230_0047f230.c

void UnknownObject::VehicleDriverNationalityMatcher()
{
    // Iterates season entries in SeasonScoringDB matching each against all vehicle files; calls NationalityDriverInfoLoader(0) when all vehicle files match a season or when a season has no vehicle files. Guarded by VehicleArray being non-null.
    // GUARD: Guard on VehicleArray (dword_8AC394) being non-null; when it is null the entire body is skipped and the function returns early. [global:0x008AC394, source:raw]
    // ASSIGNMENT: Read the first vehicle-file name pointer from the VehicleArray; if it is null use the default path byte_5EA438. [global:0x008AC394, global:0x005EA438, source:raw]
    // GUARD: Guard on VehicleCount (dword_5C329C) being greater than zero; when it is zero or negative the loop is skipped. [global:0x005C329C, source:raw]
    // LOOP: do-while loop countdown over VehicleCount seasons, advancing through SeasonScoringDB (dword_7D2E48) by stride 18624 per iteration and addressing each season entry at an offset of 18196 from the row start. [global:0x005C329C, global:0x007D2E48, source:raw]
    // GUARD: Guard on VehicleFileCount (dword_8AC390); when it is zero or negative, fall through to the loader call for this season (no files to match). [global:0x008AC390, source:raw]
    // LOOP: Inner loop over VehicleFileCount vehicle files, advancing through the VehicleArray by stride 1060 per iteration. [global:0x008AC390, global:0x008AC394, source:raw]
    // ASSIGNMENT: Read the current vehicle-file name pointer at the inner offset within the VehicleArray; if it is null use the default path byte_5EA438. [global:0x008AC394, global:0x005EA438, source:raw]
    // CALL: Call sub_588410(seasonEntry, vehicleFileName) to test whether the vehicle file matches the season entry; a non-zero return keeps matching, a zero return means no match. [callee:0x00588410, source:raw]
    // GUARD: When sub_588410 returns zero for this season entry, break out of the inner vehicle loop so the loader call is skipped for that season. [callee:0x00588410, source:raw]
    // STATE_TRANSITION: Call NationalityDriverInfoLoader(0) when every vehicle file matched the season, or immediately when the season has no vehicle files; the call is guarded on the saved default path pointer v6 being non-null. [callee:0x004C78F0, source:raw]
    // RETURN: Return the loop result value (initialized from VehicleCount, decremented to zero, or the early VehicleArray guard value when skipped). [function:0x0047F230, source:raw]

    // Conservative worker pseudocode:
    //   int sub_47F230() {
    //     int result = dword_8AC394;
    //     if (dword_8AC394) {
    //       char* v6 = *(char**)dword_8AC394;
    //       if (!v6) v6 = byte_5EA438;
    //       result = dword_5C329C;
    //       if (dword_5C329C > 0) {
    //         int i = 0;
    //         int count = dword_5C329C;
    //         do {
    //           int season = dword_7D2E48 + i + 18196;
    //           int matched = 0;
    //           if (dword_8AC390 <= 0) {
    //             if (v6) NationalityDriverInfoLoader(0);
    //           } else {
    //             int k = 0;
    //             for (;;) {
    //               char* file = *(char**)(k + dword_8AC394);
    //               if (!file) file = byte_5EA438;
    //               if (!sub_588410(season, file)) break;
    //               ++matched;
    //               k += 1060;
    //               if (matched >= dword_8AC390) { if (v6) NationalityDriverInfoLoader(0); break; }
    //             }
    //           }
    //           i += 18624;
    //           result = --count;
    //         } while (count);
    //       }
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Exact return convention of sub_588410 (match vs mismatch) is inferred from this call site and should be corroborated at 0x00588410.
    // UNRESOLVED: Semantics of the 18196 sub-offset within each SeasonScoringDB row are not defined by this packet.
    // UNRESOLVED: Relationship of a season entry to the vehicle files it must match is caller-supplied data, not established here.
    // UNRESOLVED: The LEGACY abi label VehicleArraySearchAndReset conflicts with the observed match-and-load behavior.
}
