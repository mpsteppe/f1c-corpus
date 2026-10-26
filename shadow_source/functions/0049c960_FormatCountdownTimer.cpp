// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C960
// Canonical corpus name: sub_49C960
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C960_0049c960.c

void UnknownObject::FormatCountdownTimer()
{
    // Computes the remaining session time as the session-time threshold minus the elapsed session time, and formats it as a countdown clock string (" MM:SS.FFF") into a caller-supplied buffer. Suppressed when the session type is 7 (qualifying/time-attack) or championship mode is active, and when the remaining time is not positive or the race time offset has not yet been passed. Always returns 0.
    // ASSIGNMENT: Copy the format prefix string asc_5CCE54 into the output buffer a1 and retain the destination pointer for later formatting. [global:0x005CCE54, source:raw]
    // GUARD: Guard: if session type dword_7C56A4 equals 7 (qualifying/time-attack), return 0 without formatting. [global:0x007C56A4, source:raw]
    // GUARD: Guard: if championship mode dword_7D0410 equals 1, return 0 without formatting. [global:0x007D0410, source:raw]
    // CALCULATION: Compute remaining time v3 as flt_8ACF94 minus dbl_8AFEA0 and store it into the a1 buffer as a float value. [global:0x008ACF94, global:0x008AFEA0, source:raw]
    // GUARD: Guard: if remaining time v3 is not positive, or the race time offset flt_8ACF90 has reached the session time dbl_8AFEA0, return 0 without formatting. [global:0x008ACF90, global:0x008AFEA0, source:raw]
    // CALL: Call SpatialGridCell with the remaining time as float input, converting it into minute/second components held in local integer and float slots used for formatting. [callee:0x0049B630, source:raw]
    // CALL: Call StringFormatWithBufferOverflowCheck to format the buffer as " MM:SS.FFF" using the computed minute/second components and the remaining time. [callee:0x0058815F, source:raw]
    // RETURN: Return 0 on every path. [source:raw]

    // Conservative worker pseudocode:
    //   int FormatCountdownTimer(char *out, int unused) {
    //     char *dst = strcpy(out, asc_5CCE54);
    //     if (dword_7C56A4 == 7) return 0;
    //     if (dword_7D0410 == 1) return 0;
    //     float remaining = flt_8ACF94 - (float)dbl_8AFEA0;
    //     *(float *)out = remaining;
    //     if (remaining <= 0.0f || flt_8ACF90 >= dbl_8AFEA0) return 0;
    //     int minutes;
    //     SpatialGridCell(remaining, &minutes, (float *)out);
    //     StringFormatWithBufferOverflowCheck(dst, " %.2d:%06.3f", minutes, *(float *)out);
    //     return 0;
    //   }
    // UNRESOLVED: Identity and exact semantics of flt_59E440 and the string a2d063f_1 (0x005CCE24) are not visible in the raw source of this function.
    // UNRESOLVED: dbl_8AFEA0 is treated as a double here while the subtraction result is stored as a float; the exact type widening is not resolved.
    // UNRESOLVED: Return value is unconditionally 0, so the int return conveys no success/failure signal.
}
