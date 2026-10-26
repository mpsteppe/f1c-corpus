// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00589E6C
// Canonical corpus name: sub_589E6C
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_589E6C_00589e6c.c

void UnknownObject::TimeSecondsToBrokenDownTime()
{
    // Converts an input time value to a broken-down time structure obtained from sub_592787. Values above 259200 seconds are treated as an absolute timestamp: the timezone bias dword_5E7758 is subtracted, and when the DST flag dword_5E775C is set and CriticalSectionGuardedCall reports DST active, the DST offset dword_5E7760 is subtracted and the resulting time structure is flagged (index 8 set to 1). Smaller offsets take the time-of-day path: subtract the DST offset when active, subtract the timezone bias, then normalize seconds (mod 60), minutes (mod 60), hours (mod 24) and days with negative-value correction, advancing day-of-month/day-of-year/weekday and handling a month underflow by rolling to December (index 5 decremented, index 7 = 364, index 4 = 11).
    // GUARD: Early return 0 when the input time value at this+0x0 is negative (invalid input) [field:this:0x00000000, guard:0, source:raw]
    // CALL: LazyInitSingletonWithFlagGuard ensures timezone/DST data is initialized before reading the timezone globals [callee:0x005921C5, source:raw]
    // GUARD: Branch to the absolute-timestamp path when the input value at this+0x0 is greater than 259200 and below 2147224447; otherwise take the time-of-day offset path [field:this:0x00000000, guard:1, source:raw]
    // CALCULATION: Absolute path: subtract the timezone bias dword_5E7758 from the input value to obtain the adjusted time [global:0x005E7758, source:raw]
    // CALL: Absolute path: sub_592787 retrieves or allocates the broken-down time structure for the adjusted value [callee:0x00592787, source:raw]
    // GUARD: Absolute path: when dword_5E775C (DST-active flag) is non-zero, test whether DST applies for this time [global:0x005E775C, source:raw]
    // CALL: Absolute path: CriticalSectionGuardedCall checks whether DST is currently in effect for the time structure [callee:0x0059247A, source:raw]
    // CALCULATION: Absolute path: when DST applies, subtract dword_5E7760 (DST offset) and re-retrieve the structure via sub_592787, then set its index 8 to 1 as a DST marker [callee:0x00592787, global:0x005E7760, source:raw]
    // RETURN: Absolute-timestamp path returns the broken-down time structure pointer [source:raw]
    // CALCULATION: Time-of-day path: retrieve the structure via sub_592787, read its index 0, and subtract dword_5E7760 when CriticalSectionGuardedCall reports DST not active (result comparison to 0) [callee:0x00592787, callee:0x0059247A, global:0x005E7760, source:raw]
    // CALCULATION: Time-of-day path: subtract the timezone bias dword_5E7758 and normalize the seconds field (structure index 0) with modulo 60, adding 60 and carrying when negative [global:0x005E7758, source:raw]
    // CALCULATION: Time-of-day path: normalize the minutes field (structure index 1) with modulo 60 on the accumulated minutes, adding 60 and carrying when negative [source:raw]
    // CALCULATION: Time-of-day path: normalize the hours field (structure index 2) with modulo 24 on the accumulated hours, adding 24 and carrying when negative [source:raw]
    // CALCULATION: Time-of-day path: convert remaining value to whole days, add to the day-of-month field (index 3), update the weekday field (index 6) modulo 7, and add the days to the day-of-year field (index 7) [source:raw]
    // CALCULATION: Time-of-day path, negative-day underflow: decrement the month field (index 5), add 31 to day-of-month (index 3), set day-of-year (index 7) to 364 and month index 4 to 11 (roll to end of the prior year) [source:raw]
    // RETURN: Time-of-day path returns the normalized broken-down time structure pointer [source:raw]
    // CALL: Function is invoked by sub_4D24D0 as a time-to-broken-down conversion entry point [caller:0x004D24D0, source:raw]

    // Conservative worker pseudocode:
    //   if (this[0] < 0) return 0;
    //   LazyInitSingletonWithFlagGuard();
    //   value = this[0];
    //   if (value > 259200 && value < 2147224447) {
    //       adjusted = value - dword_5E7758;
    //       tm = sub_592787(&adjusted);
    //       if (dword_5E775C) {
    //           if (CriticalSectionGuardedCall(tm)) {
    //               adjusted -= dword_5E7760;
    //               tm = sub_592787(&adjusted);
    //               tm[8] = 1;
    //           }
    //       }
    //       return tm;
    //   }
    //   tm = sub_592787(this);
    //   applyDst = CriticalSectionGuardedCall(tm) == 0;
    //   seconds = tm[0];
    //   if (!applyDst) seconds -= dword_5E7760;
    //   carry = seconds - dword_5E7758;
    //   tm[0] = carry % 60; if (tm[0] < 0) { tm[0] += 60; carry -= 60; }
    //   carry = tm[1] + carry / 60;
    //   tm[1] = carry % 60; if (tm[1] < 0) { tm[1] += 60; carry -= 60; }
    //   carry = tm[2] + carry / 60;
    //   tm[2] = carry % 24; if (tm[2] < 0) { tm[2] += 24; carry -= 24; }
    //   days = carry / 24; negative = days < 0; carry /= 24;
    //   if (carry <= 0) {
    //       if (!negative) return tm;
    //       tm[6] = (tm[6] + days + 7) % 7;
    //       tm[3] += carry;
    //       if (tm[3] <= 0) {
    //           tm[5]--;
    //           tm[3] += 31;
    //           tm[7] = 364;
    //           tm[4] = 11;
    //           return tm;
    //       }
    //   } else {
    //       tm[6] = (days + tm[6]) % 7;
    //       tm[3] += carry;
    //   }
    //   tm[7] += carry;
    //   return tm;
    // UNRESOLVED: The structure returned by sub_592787 (indices 0-8) is not described by any packet field evidence ref; only this+0x0 (the input) is evidenced.
    // UNRESOLVED: dword_5E7758 is interpreted as a timezone bias in seconds from context; its exact unit is unproven.
    // UNRESOLVED: The 2147224447 upper bound (close to 2^31-1 minus 86401) has no documented purpose in the packet.
    // UNRESOLVED: Absolute-timestamp and time-of-day paths overlap in effect but are structurally separate; the threshold 259200 (3 days) intent is DERIVED.
}
