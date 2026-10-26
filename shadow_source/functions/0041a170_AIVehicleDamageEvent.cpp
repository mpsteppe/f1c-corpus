// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041A170
// Canonical corpus name: AIVehicleDamageEvent
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIVehicleDamageEvent_0041a170.c

void UnknownObject::AIVehicleDamageEvent()
{
    // Handles an AI vehicle damage event (__stdcall on a vehicle index a1). Gated on race active (dword_7D0308) and track condition non-zero (flt_7CF3C8). Selects a driver-table behavior index: 52 when the session-status query sub_4C7BD0(a1) returns non-zero, else 196 only when session type dword_7C56A4 equals 7 (otherwise returns early). Initializes a local struct with sentinel values, fills it via DriverDataTableLookupAndTimeConversion using the driver team id read from the vehicle struct at offset 0x48A0, then inserts the entry into the driver action table via InsertDriverTableEntry keyed on flt_5EA618.
    // GUARD: Gate the whole handler on dword_7D0308 non-zero AND flt_7CF3C8 not equal to 0.0; otherwise do nothing. [global:0x007D0308, global:0x007CF3C8]
    // CALL: Call the session-status query sub_4C7BD0(a1); its byte result selects which damage index is used. [callee:0x004C7BD0, function:0x0041A170]
    // ASSIGNMENT: When sub_4C7BD0 returns non-zero, select behavior index 52 (non-race context). [source:raw]
    // GUARD: When sub_4C7BD0 returns zero and session type dword_7C56A4 is not 7, return without inserting an entry. [global:0x007C56A4, callee:0x004C7BD0]
    // ASSIGNMENT: When session type equals 7, select behavior index 196 (race context). [source:raw]
    // CALL: Initialize the local struct v2 with sentinel values before the table lookup. [callee:0x004144D0]
    // CALL: Look up the damage behavior entry: DriverDataTableLookupAndTimeConversion(v2, index, *(a1+18592), -1, -1, -1, -2.0, -2.0), where 18592 is the driver team id field at offset 0x48A0. [callee:0x004144F0, field:this:0x000048A0]
    // CALL: Insert the filled entry into the driver action table: InsertDriverTableEntry(flt_5EA618, v2). [callee:0x00418560, global:0x005EA618]

    // Conservative worker pseudocode:
    //   void __stdcall AIVehicleDamageEvent(int a1) {
    //     float v2[8];
    //     int index;
    //     if (dword_7D0308 && flt_7CF3C8 != 0.0) {
    //       if ((unsigned __int8)sub_4C7BD0(a1)) index = 52;
    //       else if (dword_7C56A4 == 7) index = 196;
    //       else return;
    //       StructInitWithSentinelValues(v2);
    //       DriverDataTableLookupAndTimeConversion(v2, index, *(int*)(a1 + 18592), -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v2);
    //     }
    //   }
    // UNRESOLVED: Semantics of sub_4C7BD0 (callers of a1) and why its non-zero result selects index 52 are not established here.
    // UNRESOLVED: Meaning of the literal sentinel arguments -1 and -2.0 passed to DriverDataTableLookupAndTimeConversion is unknown.
    // UNRESOLVED: Owner of the driver action table pointed to by flt_5EA618 is unresolved.
    // UNRESOLVED: The packet also lists global flt_59E440 as read, but the raw source does not reference it directly.
}
