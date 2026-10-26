// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592647
// Canonical corpus name: sub_592647
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592647_00592647.c

void UnknownObject::DSTTransitionDateCalculator()
{
    // Computes a DST transition date (start or end) for a year and stores it together with a millisecond time-of-day into the DST globals at 0x5E77F0/0x5E77F8 (start) or 0x5E7800/0x5E7808 (end). Supports two rule modes: a weekday-based rule (a2 == 1) that computes a day-of-year from month a3, week a5, weekday a6 and a month-offset lookup indexed by year a4, or a fixed-date rule (a2 != 1) that adds a year-indexed month offset a7. The stored time-of-day is normalized across the 86400000 ms day boundary, rolling the stored day by one when it under/overflows. Called by sub_59249B (0059249b).
    // GUARD: Branches on a2: value 1 takes the weekday rule, any other value takes the fixed-date rule [source:raw]
    // CALCULATION: Selects the month-offset table by a3 & 3: dword_5E9AD0 or dword_5E9B04 indexed by year a4, giving v12 [global:0x005E9AD0, global:0x005E9B04, source:raw]
    // CALCULATION: Computes the day-of-week term v14 as (365*a3 + ((a3-1)>>2) + v12 + 1 - 25563) mod 7 [source:raw]
    // CALCULATION: Builds the transition day v15: if v14 > a6 then a6 + 7*a5 - v14 + v13 else v13 + a6 + 7*a5 - v14 - 7 [source:raw]
    // GUARD: Last-week correction: when a5 == 5, reads dword_5E9AD4 or dword_5E9B08 indexed by a4 and subtracts 7 from v15 if v15 exceeds that table value [global:0x005E9AD4, global:0x005E9B08, source:raw]
    // CALCULATION: Fixed-date rule: v15 = a7 + v17, where v17 is read from dword_5E9AD0 or dword_5E9B04 indexed by a4 [global:0x005E9AD0, global:0x005E9B04, source:raw]
    // GUARD: Branches on a1: value 1 selects the DST start-date path, otherwise the end-date path [source:raw]
    // ASSIGNMENT: Start path: writes a3 to dword_5E77F0 (start year) and v15 to dword_5E77F4 (start day-of-year) [global:0x005E77F0, global:0x005E77F4, source:raw]
    // CALCULATION: Start path: time-of-day in milliseconds = a11 + 1000*(a10 + 60*(a9 + 60*a8)) [source:raw]
    // ASSIGNMENT: Start path: writes the computed time-of-day to dword_5E77F8 and returns it [global:0x005E77F8, source:raw]
    // ASSIGNMENT: End path: writes v15 to dword_5E7804 (end day-of-year) [global:0x005E7804, source:raw]
    // CALCULATION: End path: time-of-day in milliseconds = a11 + 1000*(a10 + dword_5E7760 + 60*(a9 + 60*a8)), adding the read-only global as an offset [global:0x005E7760, source:raw]
    // ASSIGNMENT: End path: writes the summed time-of-day to dword_5E7808 [global:0x005E7808, source:raw]
    // STATE_TRANSITION: Day-boundary normalization: if the sum is negative, adds 86400000 and decrements v15; if it is at least 86400000, subtracts 86400000 and increments v15; the corrected value is written back to dword_5E7804 [global:0x005E7804, source:raw]
    // ASSIGNMENT: End path: writes a3 to dword_5E7800 (end year) and returns the normalized time-of-day [global:0x005E7800, source:raw]
    // CALL: Invoked by sub_59249B (0059249b), the only known caller in this packet [caller:0x0059249B, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 1) {
    //     table = (a3 & 3) ? dword_5E9B04 : dword_5E9AD0;
    //     v12 = table[a4];
    //     v14 = (365*a3 + ((a3-1) >> 2) + v12 + 1 - 25563) % 7;
    //     v15 = (v14 > a6) ? a6 + 7*a5 - v14 + v12 + 1 : v12 + 1 + a6 + 7*a5 - v14 - 7;
    //     if (a5 == 5) {
    //       v16 = (a3 & 3) ? dword_5E9B08[a4] : dword_5E9AD4[a4];
    //       if (v15 > v16) v15 -= 7;
    //     }
    //   } else {
    //     v17 = (a3 & 3) ? dword_5E9B04[a4] : dword_5E9AD0[a4];
    //     v15 = a7 + v17;
    //   }
    //   if (a1 == 1) {
    //     dword_5E77F0 = a3;
    //     dword_5E77F4 = v15;
    //     result = a11 + 1000*(a10 + 60*(a9 + 60*a8));
    //     dword_5E77F8 = result;
    //   } else {
    //     dword_5E7804 = v15;
    //     result = a11 + 1000*(a10 + dword_5E7760 + 60*(a9 + 60*a8));
    //     dword_5E7808 = result;
    //     if (result < 0) { result += 86400000; v15 -= 1; dword_5E7804 = v15; }
    //     else if (result >= 86400000) { result -= 86400000; v15 += 1; dword_5E7804 = v15; }
    //     dword_5E7800 = a3;
    //   }
    //   return result;
    // UNRESOLVED: The exact semantics of the two lookup-table pairs (dword_5E9AD0/dword_5E9AD4 vs dword_5E9B04/dword_5E9B08) and the rule constants 25563, 365, 7 and 86400000 are not derivable from this packet
    // UNRESOLVED: The read-only role of dword_5E7760 in the end-date time computation (fill suggests a DST offset, unverified) is unclear
    // UNRESOLVED: Why the weekday rule is gated on a2 == 1 while the fixed-date rule covers everything else is not justified by any packet evidence
}
