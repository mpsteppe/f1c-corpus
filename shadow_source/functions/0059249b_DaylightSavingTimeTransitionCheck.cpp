// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0059249B
// Canonical corpus name: sub_59249B
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_59249B_0059249b.c

void UnknownObject::DaylightSavingTimeTransitionCheck()
{
    // Decides whether a timestamp falls inside Daylight Saving Time. Bails out with FALSE when the DST enable flag dword_5E775C is zero. When the timestamp year (a1[5]) no longer matches either cached transition year (dword_5E77F0 / dword_5E7800), recomputes the DST start/end transition dates by calling sub_592647 twice: once with the Windows TIME_ZONE_INFORMATION DaylightDate/StandardDate members when the timezone-init flag dword_8D3FC0 is set, otherwise with hardcoded April/October defaults. Then compares the day-of-year a1[7] against the cached day-of-year bounds dword_5E77F4/dword_5E7804, and on the boundary days compares the time-of-day value 1000*(h + 60*(m + 60*s)) against the cached boundary times dword_5E77F8/dword_5E7808. Invoked by CriticalSectionGuardedCall (0059247A).
    // GUARD: Guard on the DST enable flag dword_5E775C; when zero, DST is disabled. [global:0x005E775C, source:raw]
    // RETURN: Return FALSE immediately when DST is disabled. [source:raw]
    // ASSIGNMENT: Load the timestamp year from a1[5] (field this+0x14) into v2. [field:this:0x00000014, source:raw]
    // GUARD: Year-change guard: recompute transitions only when the year differs from the cached start/end years dword_5E77F0 and dword_5E7800. [global:0x005E77F0, global:0x005E7800, source:raw]
    // GUARD: Guard on the timezone-init flag dword_8D3FC0 selecting the Windows TIME_ZONE_INFORMATION path over the hardcoded default path. [global:0x008D3FC0, source:raw]
    // CALL: When DaylightDate.wYear is non-zero, compute the DST start transition via sub_592647(1, 0, year, wMonth, ..., wDay, wHour, wMinute, wSecond, wMilliseconds); otherwise call it with the absolute-date flag sub_592647(1, 1, year, wMonth, wDay, wDayOfWeek, ...) using the DaylightDate members. [callee:0x00592647, source:raw]
    // CALL: Compute the DST end transition from the StandardDate members: sub_592647(0, 0, year, ...) when StandardDate.wYear is non-zero, else sub_592647(0, 1, year, wMonth, wDay, wDayOfWeek, ...). [callee:0x00592647, source:raw]
    // CALL: Hardcoded default path: sub_592647(1, 1, year, 4, 1, 0, 0, 2, 0, 0, 0) for the April start and sub_592647(0, 1, year, 10, 5, 0, 0, 2, 0, 0, 0) for the October end, using a1[5] as the year. [callee:0x00592647, field:this:0x00000014, source:raw]
    // ASSIGNMENT: Load the day-of-year from a1[7] (field this+0x1C) into v3. [field:this:0x0000001C, source:raw]
    // CALCULATION: Build the time-of-day in milliseconds as 1000 * (a1[0] + 60 * (a1[1] + 60 * a1[2])) from fields this+0x0, this+0x4, this+0x8. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: Branch on the cached start/end day-of-year bounds dword_5E77F4 and dword_5E7804: a normal year has start below end. [global:0x005E77F4, global:0x005E7804, source:raw]
    // GUARD: Normal-year range test: v3 inside (start, end) returns TRUE, outside [start, end] returns FALSE, and the boundary days fall through to the time-of-day comparison. [global:0x005E77F4, global:0x005E7804, source:raw]
    // GUARD: Wrap-around year test when start >= end: v3 below end or above start returns TRUE, strictly inside (end, start) returns FALSE. [global:0x005E77F4, global:0x005E7804, source:raw]
    // RETURN: Boundary-day decisions: on the start day return whether v4 >= dword_5E77F8; on the end day return whether v4 < dword_5E7808. [global:0x005E77F8, global:0x005E7808, source:raw]
    // CALL: Invoked by CriticalSectionGuardedCall (0059247A) inside its guarded section. [caller:0x0059247A, source:raw]

    // Conservative worker pseudocode:
    //   BOOL sub_59249B(DWORD *t) {
    //     if (!dword_5E775C) return FALSE;
    //     int year = t[5];
    //     if (year != dword_5E77F0 || year != dword_5E7800) {
    //       if (dword_8D3FC0) {
    //         sub_592647(1, TimeZoneInformation.DaylightDate.wYear ? 0 : 1, year, DaylightDate members...);
    //         sub_592647(0, TimeZoneInformation.StandardDate.wYear ? 0 : 1, year, StandardDate members...);
    //       } else {
    //         sub_592647(1, 1, year, 4, 1, 0, 0, 2, 0, 0, 0);
    //         sub_592647(0, 1, year, 10, 5, 0, 0, 2, 0, 0, 0);
    //       }
    //     }
    //     int doy = t[7];
    //     int ms  = 1000 * (t[0] + 60 * (t[1] + 60 * t[2]));
    //     if (dword_5E77F4 < dword_5E7804) {
    //       if (doy < dword_5E77F4 || doy > dword_5E7804) return FALSE;
    //       if (doy > dword_5E77F4 && doy < dword_5E7804) return TRUE;
    //     } else {
    //       if (doy < dword_5E7804 || doy > dword_5E77F4) return TRUE;
    //       if (doy > dword_5E7804 && doy < dword_5E77F4) return FALSE;
    //     }
    //     if (doy == dword_5E77F4) return ms >= dword_5E77F8;
    //     return ms < dword_5E7808;
    //   }
    // UNRESOLVED: The raw source reads the global TIME_ZONE_INFORMATION DaylightDate/StandardDate members, but the packet's global facts encode individual byte globals (byte_8D400C..byte_8D401A, byte_8D4060..byte_8D406E) whose mapping onto those members is not proven by this packet.
    // UNRESOLVED: Ten byte globals at 0xFF00000000005455..0xFF00000000005466 are flagged by packet facts as read but appear nowhere in the raw decompiled source; they likely reflect mis-decoded members of the timezone configuration block, unverifiable from this packet.
    // UNRESOLVED: The exact contract of sub_592647 (argument roles: daylight flag, absolute-date flag, year, month, day, day-of-week, hour, minute, second, millisecond) is inferred from call sites only; its implementation is not in this packet.
}
