// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00591EDF
// Canonical corpus name: sub_591EDF
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_591EDF_00591edf.c

void UnknownObject::LocalTimeToTimestamp()
{
    // Local date/time to timestamp conversion with DST adjustment. Rejects years outside 1970..2038 (a1-1900 < 70 or > 138) by returning -1. Computes a cumulative day count from the day a3 plus the month-offset table dword_5E9B04[a2], applying a leap-day increment when the year is divisible by 4 and the month is past February. Lazily initializes timezone data via LazyInitSingletonWithFlagGuard, builds a local time description used by the DST check, then computes the timestamp as dword_5E7758 + 60*(minute + 60*(hour + 24*(days + 365*year))) + second + 2085978496. When a7 is 1, or a7 is -1 with dword_5E775C set and CriticalSectionGuardedCall returning non-zero, adds the DST offset dword_5E7760. Called by sub_5896EE and sub_59B760.
    // GUARD: Year range check: if a1 - 1900 < 70 or a1 - 1900 > 138, return -1 (year outside 1970..2038). [function:0x00591EDF, source:raw]
    // CALCULATION: Cumulative day count v8 = a3 (day) + dword_5E9B04[a2] (month offset table). [global:0x005E9B04, source:raw]
    // CALCULATION: Leap-day adjustment: if (year & 3) == 0 and month a2 > 2, increment v8. [source:raw]
    // CALL: Lazily initialize the timezone singleton data: LazyInitSingletonWithFlagGuard(). [callee:0x005921C5, source:raw]
    // ASSIGNMENT: Build the local time description fields (v16 = dayCount, v15 = year, v13 = a4, v14 = a2 - 1) that back the DST check. [source:raw]
    // CALCULATION: Timestamp base: v9 = dword_5E7758 + 60*(a5 + 60*(a4 + 24*(((a1 - 1901) >> 2) + v8 + 365*(a1 - 1900)))) + a6 + 2085978496. [global:0x005E7758, source:raw]
    // CALL: DST adjustment: if a7 == 1, or (a7 == -1 and dword_5E775C is set and CriticalSectionGuardedCall(v12) is non-zero), add dword_5E7760 to v9. [callee:0x0059247A, global:0x005E775C, global:0x005E7760, source:raw]
    // RETURN: Return v9 (the timestamp, with optional DST offset applied). [function:0x00591EDF, source:raw]

    // Conservative worker pseudocode:
    //   int sub_591EDF(int a1 /*year* /, int a2 /*month* /, int a3 /*day* /, int a4 /*hour* /, int a5 /*min* /, int a6 /*sec* /, int a7 /*dst flag* /) {
    //     int year = a1 - 1900;
    //     if (year < 70 || year > 138) return -1;
    //     int dayCount = a3 + dword_5E9B04[a2];
    //     if ((year & 3) == 0 && a2 > 2) dayCount++;
    //     LazyInitSingletonWithFlagGuard();
    //     /* build local time description (v16 = dayCount, v15 = year, v13 = a4, v14 = a2-1) for the DST check * /
    //     int v9 = dword_5E7758 + 60*(a5 + 60*(a4 + 24*(((a1 - 1901) >> 2) + dayCount + 365*year))) + a6 + 2085978496;
    //     if (a7 == 1 || (a7 == -1 && dword_5E775C && CriticalSectionGuardedCall(&desc))) v9 += dword_5E7760;
    //     return v9;
    //   }
    // UNRESOLVED: Meaning of the constant 2085978496 (epoch/era offset) is not established.
    // UNRESOLVED: Meaning of a7 (explicit DST force vs auto) and how dword_5E775C with CriticalSectionGuardedCall(v12) cooperate is inferred from existing analysis (DERIVED).
    // UNRESOLVED: The layout of the local time description struct built into the v12/v13..v16 stack locals and passed to CriticalSectionGuardedCall is unverified.
    // UNRESOLVED: Owner class is unknown; the function is a free __cdecl local-time conversion helper.
}
