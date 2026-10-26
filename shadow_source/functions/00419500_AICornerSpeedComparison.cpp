// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00419500
// Canonical corpus name: AICornerSpeedComparison
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AICornerSpeedComparison_00419500.c

void UnknownObject::AICornerSpeedComparison()
{
    // AI corner-speed comparison handler for a vehicle (a1) at corner index a2 (1 or 2). Gated on race active (dword_7D0308), nonzero track condition (flt_7CF3C8) and race phase != 8. Reads a reference corner speed from flt_5F0780 indexed by 4656 * sub_4D1B50(0) + a2 and compares it against the vehicle's own corner speed at a1 + 4*a2 + 16460; when the vehicle is faster it selects driver-behavior-table entry 13/14 (corners 1/2) and when slower entry 19/20, via DriverDataTableLookupAndTimeConversion, then inserts the resulting entry into the driver table via InsertDriverTableEntry(flt_5EA618, v4). On corner 2 while the vehicle's field at +0x3450 equals 1, it triggers AIVehicleDamageEvent(a1).
    // GUARD: Outer gate: proceed only when dword_7D0308 (race active) is nonzero, flt_7CF3C8 (track condition) is nonzero, and dword_7C56A8 (race phase) != 8. [global:0x007D0308, global:0x007CF3C8, global:0x007C56A8, source:raw]
    // CALL: StructInitWithSentinelValues(v4) initializes the local 8-float behavior-entry buffer with sentinel values before the table lookup. [callee:0x004144D0, source:raw]
    // GUARD: Proceed only when session type dword_7C56A4 == 5 and the player vehicle's field at dword_7C54E8 + 18580 equals this vehicle's field at a1 + 18580 (same-car identity check via offset 0x4894). [global:0x007C56A4, global:0x007C54E8, field:this:0x00004894, source:raw]
    // CALL: sub_4D1B50(0) returns a driver/vehicle index v2 used to select the reference speed row. [callee:0x004D1B50, source:raw]
    // GUARD: Bounds-check: only continue when v2 < 0x68 (104). [source:raw]
    // CALCULATION: v3 = flt_5F0780[4656 * v2 + a2]: reference corner speed for this car, one entry per car (stride 4656) and per corner index a2. [global:0x005F0780, source:raw]
    // GUARD: Only compare when the reference speed v3 > 0.0. [source:raw]
    // GUARD: Compare the vehicle's current corner speed *(float*)(a1 + 4*a2 + 16460) against v3; the direction selects which behavior entry to look up. [source:raw]
    // STATE_TRANSITION: Select the driver-behavior-table index: when the vehicle speed exceeds v3, a2 == 1 selects 13 and a2 == 2 selects 14; otherwise a2 == 1 selects 19 and a2 == 2 selects 20. [source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v4, selectedIndex, -1, -1, -1, -1, -2.0, -2.0) fills the behavior entry buffer for the chosen index. [callee:0x004144F0, source:raw]
    // GUARD: If the lookup left v4[0] != -1 (entry is not the sentinel), insert the entry into the driver table. [callee:0x00418560, global:0x005EA618, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v4) records the looked-up behavior entry into the driver table. [callee:0x00418560, global:0x005EA618, source:raw]
    // GUARD: Trigger condition for the damage event: a2 == 2 and *(int*)(a1 + 13392) == 1 (field at offset 0x3450, interpreted as pitting status). [field:this:0x00003450, guard:0, source:raw]
    // CALL: AIVehicleDamageEvent(a1) is raised on corner 2 while the vehicle is pitting. [callee:0x0041A170, source:raw]

    // Conservative worker pseudocode:
    //   void sub_419500(int veh, int corner) {
    //     if (raceActive && trackCondition != 0.0 && racePhase != 8) {
    //       float entry[8];
    //       StructInitWithSentinelValues(entry);
    //       if (sessionType == 5 && *(int*)(playerVeh + 0x4894) == *(int*)(veh + 0x4894)) {
    //         unsigned int idx = sub_4D1B50(0);
    //         if (idx < 0x68) {
    //           double ref = flt_5F0780[4656 * idx + corner];
    //           if (ref > 0.0) {
    //             int tableIdx = (*(float*)(veh + 4*corner + 0x404C) > ref)
    //                 ? (corner == 1 ? 13 : 14)   /* faster: overtaking * /
    //                 : (corner == 1 ? 19 : 20);  /* slower: overtaken * /
    //             DriverDataTableLookupAndTimeConversion(entry, tableIdx, -1, -1, -1, -1, -2.0, -2.0);
    //           }
    //         }
    //         if (entry[0] != -1) InsertDriverTableEntry(flt_5EA618, entry);
    //       }
    //       if (corner == 2 && *(int*)(veh + 0x3450) == 1) AIVehicleDamageEvent(veh);
    //     }
    //   }
    // UNRESOLVED: Globals flt_59E440 and dword_8ACEE0 are listed as read but absent from the raw source; existing analysis suggests zero-threshold and force-feedback base respectively, both unverified against the decompilation.
    // UNRESOLVED: Caller LapCompletion (0x004BC4E0) comes from the callgraph only; no static frame path from the tick root was found, so call frequency is unknown.
    // UNRESOLVED: Offsets 18580 (0x4894, compared equal between player and this vehicle) and 16460 (0x404C, per-corner speed array) are read in the decompilation but 16460 is not present in the packet field table; their struct semantics are DERIVED.
    // UNRESOLVED: sub_4D1B50(0) identity and the meaning of the 0x68 (104) index bound are not established by packet evidence.
    // UNRESOLVED: Driver-behavior-table indices 13/14/19/20 being overtake vs overtaken entries is DERIVED from the speed-comparison direction, not confirmed.
    // UNRESOLVED: Field at +0x3450 is treated as pitting status by existing analysis (guard:0); that reading is DERIVED.
}
