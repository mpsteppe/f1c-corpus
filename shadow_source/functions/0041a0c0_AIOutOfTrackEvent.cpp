// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A0C0
// Canonical corpus name: AIOutOfTrackEvent
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIOutOfTrackEvent_0041a0c0.c

void UnknownObject::AIOutOfTrackEvent()
{
    // AI off-track event handler. Guards on race-active flag and track-condition state, toggles the off-track driver-table flag for index 264, then, for a non-player/offending vehicle, initializes a driver-table entry, converts it from the driver data row, and inserts it.
    // GUARD: Proceed only when dword_7D0308 is non-zero (race active) and flt_7CF3C8 != 0.0 (track condition state valid). [global:0x007D0308, global:0x007CF3C8, source:raw]
    // CALL: BooleanOROfTwoChecks(flt_5EA618, 264): set/query the boolean flag for index 264 on the driver table anchored at flt_5EA618. [callee:0x00418A20, global:0x005EA618, source:raw]
    // GUARD: Skip the entry insertion when a1 equals the dword at current-vehicle-array-entry + 18580: dword_7C54F0[dword_7C54E4] + 18580. Offsetting 18580 from the vehicle pointer array (dword_7C54F0) indexed by dword_7C54E4. [global:0x007C54F0, global:0x007C54E4, source:raw]
    // CALL: StructInitWithSentinelValues(v1): initialize the local driver-table entry struct with sentinel values before the lookup. [callee:0x004144D0, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v1, 264, dword_5F0F74[4656 * a1], -1, -1, -1, -2.0, -2.0): resolve driver data row for driver a1 (row stride 4656) and fill entry v1 for index 264. [callee:0x004144F0, global:0x005F0F74, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v1): insert the filled entry v1 into the driver table anchored at flt_5EA618. [callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Implicit return after the conditional block. [source:raw]

    // Conservative worker pseudocode:
    //   void AIOutOfTrackEvent(int a1)
    //   {
    //       float v1[8];
    //       if (dword_7D0308 && flt_7CF3C8 != 0.0)
    //       {
    //           BooleanOROfTwoChecks(flt_5EA618, 264);
    //           if (a1 != *(_DWORD *)(dword_7C54F0[dword_7C54E4] + 18580))
    //           {
    //               StructInitWithSentinelValues(v1);
    //               DriverDataTableLookupAndTimeConversion(v1, 264, dword_5F0F74[4656 * a1], -1, -1, -1, -2.0, -2.0);
    //               InsertDriverTableEntry(flt_5EA618, v1);
    //           }
    //       }
    //   }
    // UNRESOLVED: Semantics of the index 264 constant (off-track event per existing analysis prose; not independently grounded here).
    // UNRESOLVED: Meanings of the -1, -1, -1, -2.0, -2.0 literal arguments to DriverDataTableLookupAndTimeConversion are not established.
    // UNRESOLVED: The 18580-byte offset read from the current-vehicle entry (team/current-driver comparison) is not named; no packet field evidence exists.
    // UNRESOLVED: flt_59E440 appears in the packet globals but is absent from the raw source text; no operation assigned.
}
