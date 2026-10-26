// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041C440
// Canonical corpus name: sub_41C440
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41C440_0041c440.c

void UnknownObject::StandingsMessageDispatcher()
{
    // Dispatches a race standings/championship status audio message: when the race is active and the track condition is initialized, initializes a driver table entry buffer, computes a driver index (queried from the standings sort buffer, plus one, but only in championship mode 4, otherwise -1), computes a message ID via sub_420000, populates the entry with DriverDataTableLookupAndTimeConversion, and inserts it into the shared driver data table via InsertDriverTableEntry.
    // GUARD: Outer guard: proceed only when dword_7D0308 (race active) is non-zero AND flt_7CF3C8 (track condition) is not equal to 0.0; otherwise the whole dispatch is skipped. [source:raw, global:0x007D0308, global:0x007CF3C8]
    // CALL: Call StructInitWithSentinelValues(v3) to initialize the local driver-table entry buffer with sentinel/default values. [source:raw, callee:0x004144D0]
    // ASSIGNMENT: Seed v0 with the default sentinel value -1 before the championship-mode check. [source:raw]
    // GUARD: Guard on dword_7D0410 (championship mode) equal to 4; only then is a real driver index computed. [source:raw, global:0x007D0410]
    // CALL: Query the standings sort buffer dword_7D2DB0 via sub_4C2990 and add 1 to convert the returned position into v0. [source:raw, callee:0x004C2990, global:0x007D2DB0]
    // ASSIGNMENT: Move the computed index v0 into v2, the position argument passed to the table lookup. [source:raw]
    // CALL: Call sub_420000() and store its return as v1, the message ID argument. [source:raw, callee:0x00420000]
    // CALL: Call DriverDataTableLookupAndTimeConversion(v3, v1, v2, -1, -1, -1, -2.0, -2.0) to populate the entry with the computed message ID and position plus sentinel arguments. [source:raw, callee:0x004144F0]
    // CALL: Call InsertDriverTableEntry(flt_5EA618, v3) to push the populated entry into the shared driver data table. [source:raw, callee:0x00418560, global:0x005EA618]
    // RETURN: Implicit return; function returns void after the guarded dispatch completes or the outer guard fails. [source:raw, function:0x0041C440]

    // Conservative worker pseudocode:
    //   void sub_41C440()
    //   {
    //     int v0 = -1;
    //     float v3[8];
    //     if ( dword_7D0308 && flt_7CF3C8 != 0.0 )
    //     {
    //       StructInitWithSentinelValues(v3);
    //       if ( dword_7D0410 == 4 )
    //         v0 = sub_4C2990(&dword_7D2DB0) + 1;
    //       v2 = v0;
    //       v1 = sub_420000();
    //       DriverDataTableLookupAndTimeConversion(v3, v1, v2, -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v3);
    //     }
    //   }
    // UNRESOLVED: Meaning of the sentinel arguments -1, -1, -1 and -2.0, -2.0 passed to DriverDataTableLookupAndTimeConversion is not derivable from this function alone.
    // UNRESOLVED: Semantics of championship mode value 4 and the +1 adjustment on the sub_4C2990 result are caller- and data-dependent.
    // UNRESOLVED: Exact purpose and return semantics of sub_420000 (message ID) require that function's own analysis.
    // UNRESOLVED: Why a driver index is only supplied in championship mode 4 and what the -1 default represents (no position) is unverified.
    // UNRESOLVED: Relation of the caller sub_40DE60 and the frame path that reaches this dispatcher is not established.
}
