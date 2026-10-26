// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00592787
// Canonical corpus name: sub_592787
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_592787_00592787.c

void UnknownObject::SecondsToCalendarTime()
{
    // Converts a seconds-since-epoch value pointed to by a1 into a broken-down calendar-time struct stored in a per-thread buffer (TLS slot, defaulting to the static unk_8D4080). Computes year, month index, day-of-month, day-of-year, weekday, hour, minute and second, handling the four-year leap cycle via the tables at dword_5E9AD4 / dword_5E9B08. Returns the filled struct pointer, or 0 when the input is negative. Called by sub_589E6C.
    // ASSIGNMENT: v1 = *a1: read the input seconds-since-epoch value from the caller-provided pointer. [field:this:0x00000000, source:raw]
    // GUARD: if (v1 < 0) return 0: reject negative timestamps and return a null pointer. [field:this:0x00000000, function:0x00592787, source:raw]
    // CALL: v4 = TLSValueRetrievalWithInit(): obtain the per-thread context pointer that holds the reusable calendar-time buffer. [callee:0x0058E0C7, source:raw]
    // GUARD: if (v4[16] is unset): the TLS slot at index 16 has not been initialized yet. [source:raw]
    // CALL: v6 = MallocWrapperForNhMalloc(36): allocate a 36-byte calendar-time struct on first use; on allocation failure fall back to the static default unk_8D4080. [callee:0x0058A935, global:0x008D4080, source:raw]
    // ASSIGNMENT: v4[16] = v6: cache the allocated (or default) calendar-time struct pointer in TLS slot 16; v7 = (int *)v4[16] selects the effective output pointer. [source:raw]
    // CALCULATION: v8 = v1 / 126230400, v9 = v1 % 126230400: split the timestamp into whole four-year blocks and the remainder of the current block. [source:raw]
    // CALCULATION: v10 = 4 * v8 + 70: compute the calendar year from the four-year block count. [source:raw]
    // CALCULATION: Adjust year and remainder through the leap cycle: subtract 31536000 (non-leap year) up to twice, and 31622400 (leap year) once, incrementing v10 and tracking the leap flag v2 accordingly. [source:raw]
    // ASSIGNMENT: v7[5] = v10 (year); v7[7] = v9 / 86400 (day of year); v12 = v9 % 86400 (seconds within the day). [source:raw]
    // ASSIGNMENT: v11 = dword_5E9AD4 by default; if the year is not a leap year (v2 clear) v11 = dword_5E9B08: select the month-length lookup table. [global:0x005E9AD4, global:0x005E9B08, source:raw]
    // LOOP: Scan the selected month table v11 from v11 + 1 while table values stay below v7[7], accumulating v13 to find the month index for the computed day of year. [source:raw]
    // ASSIGNMENT: v7[4] = v13 - 1 (month index); v7[3] = v7[7] - v11[v16] (day of month); v7[6] = (*a1 / 86400 + 4) % 7 (weekday). [source:raw]
    // ASSIGNMENT: v7[2] = v12 / 3600 (hour); v7[1] = (v12 % 3600) / 60 (minute); *v7 = (v12 % 3600) % 60 (second); v7[8] = 0 (unused slot). [source:raw]
    // RETURN: return v7: return the pointer to the filled calendar-time struct. [function:0x00592787, source:raw]

    // Conservative worker pseudocode:
    //   struct CalendarTime *sub_592787(int *a1) {
    //     int secs = *a1;
    //     if (secs < 0) return 0;
    //     int *ctx = TLSValueRetrievalWithInit();
    //     if (!ctx[16]) {
    //       int *buf = MallocWrapperForNhMalloc(36);
    //       ctx[16] = buf ? (int)buf : (int)&unk_8D4080;
    //     }
    //     int *out = (int *)ctx[16];
    //     int blocks = secs / 126230400;
    //     int rem = secs % 126230400;
    //     int year = 4 * blocks + 70;
    //     int leap = 0;
    //     if (rem >= 31536000) { rem -= 31536000; year = 4 * blocks + 71; }
    //     if (rem >= 31536000) { rem -= 31536000; year = 4 * blocks + 72; }
    //     if (rem >= 31622400) { year = 4 * blocks + 73; rem -= 31622400; }
    //     else { leap = 1; }
    //     int *months = dword_5E9AD4;
    //     if (!leap) months = dword_5E9B08;
    //     out[5] = year;
    //     out[7] = rem / 86400;
    //     int daysecs = rem % 86400;
    //     int m = 1;
    //     for (int *p = months + 1; *p < out[7]; ++p) ++m;
    //     out[4] = m - 1;
    //     out[3] = out[7] - months[m - 1];
    //     out[6] = (*a1 / 86400 + 4) % 7;
    //     out[2] = daysecs / 3600;
    //     int s = daysecs % 3600;
    //     out[1] = s / 60;
    //     out[8] = 0;
    //     out[0] = s % 60;
    //     return out;
    //   }
    // UNRESOLVED: Layout of the 36-byte calendar-time struct is inferred from v7[N] indices only; field names are not established.
    // UNRESOLVED: The constants 126230400 / 31536000 / 31622400 as year lengths are derived from the source but the epoch base (year 70) is unverified.
    // UNRESOLVED: Why the weekday uses + 4 offset is not established from this function alone.
}
