// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0041B190
// Canonical corpus name: sub_41B190
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_41B190_0041b190.c

void UnknownObject::TeammateEventAudio77()
{
    // Emits a driver-table audio event (message ID 77) when a teammate-related session condition holds. Guards on dword_7D0308 (race-active flag) being non-zero, flt_7CF3C8 (track/condition state) being non-zero, and the team/constructor field at +0x4894 of the player vehicle (dword_7C54E8) matching the same field of the AI entrant a1. When all pass, DriverDataTableLookupAndTimeConversion fills a local 8-float struct with message ID 77 and sentinel defaults, then InsertDriverTableEntry(flt_5EA618, v1) inserts it into the shared driver table. Called by sub_49B9A0.
    // GUARD: If dword_7D0308 (race-active flag) is zero, return without emitting the event. [global:0x007D0308, source:raw]
    // GUARD: If flt_7CF3C8 (track/condition state) is 0.0, return without emitting the event. [global:0x007CF3C8, source:raw]
    // GUARD: If the player vehicle's team/constructor field at dword_7C54E8 + 0x4894 differs from the AI entrant's a1 + 0x4894, return (entrant is not a teammate). [global:0x007C54E8, field:this:0x00004894, source:raw]
    // CALL: DriverDataTableLookupAndTimeConversion(v1, 77, -1, -1, -1, -1, -2.0, -2.0) fills the local driver-data/time struct v1 with message ID 77 and sentinel default indices/floats. [callee:0x004144F0, source:raw]
    // CALL: InsertDriverTableEntry(flt_5EA618, v1) inserts the populated entry into the shared driver table. [callee:0x00418560, global:0x005EA618, source:raw]
    // RETURN: Void function; returns after emitting the event or when any guard fails. Called by sub_49B9A0. [function:0x0041B190, caller:0x0049B9A0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D0308 && flt_7CF3C8 != 0.0 && *(_DWORD*)(dword_7C54E8 + 18580) == *(_DWORD*)(a1 + 18580)) {
    //       DriverDataTableLookupAndTimeConversion(v1, 77, -1, -1, -1, -1, -2.0, -2.0);
    //       InsertDriverTableEntry(flt_5EA618, v1);
    //   }
    // UNRESOLVED: Global flt_59E440 is listed as a read global in the packet but never appears in the raw source text; its role (existing analysis labels it a zero threshold) cannot be placed from this packet.
}
