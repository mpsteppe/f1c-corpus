// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BE50
// Canonical corpus name: sub_49BE50
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BE50_0049be50.c

void UnknownObject::FormatSectorTimeDifference()
{
    // Formats the gap between two timing values as a signed "+/-MM:SS.mmm" string into the output buffer a1. Copies an empty prefix (asc_5CCE18) into the buffer, then requires the race-state struct at dword_7C54E0 to be in state 2 (offset +16532). When byte_7CFFF0 bit 2 (ghost/replay comparison) is set it resolves the ghost car index via sub_4D1B50(0) and reads the reference time from the ghost lap-time array flt_5F0780[4656*index + field]; otherwise it reads the reference time directly from the race struct (+16552). It then reads the live value at +16460, returns 0 early when either time is not positive, computes the difference, decomposes its absolute value into minutes/seconds via SpatialGridCell, and prints "-" or "+" formatted output through StringFormatWithBufferOverflowCheck. Always returns 0.
    // CALL: Copy the prefix string asc_5CCE18 into output buffer a1 via strcpy; v2 keeps the buffer pointer for the later format call. [global:0x005CCE18, source:raw]
    // GUARD: Guard: if the race-state struct at dword_7C54E0 is not in state 2 (*(dword_7C54E0 + 16532) != 2), return 0 immediately. [global:0x007C54E0, source:raw]
    // GUARD: Guard: when byte_7CFFF0 bit 2 is set the ghost/replay comparison branch is taken; otherwise the direct race-struct branch is used. [global:0x007CFFF0, source:raw]
    // CALL: Ghost branch: resolve the ghost/replay car index with sub_4D1B50(0); if it returns 255 (invalid), return 0. [callee:0x004D1B50, source:raw]
    // CALCULATION: Read the time-slot index v5 from the race struct at +16448, then load the reference time: from flt_5F0780[4656 * ghostIndex + v5] in the ghost branch, or from *(dword_7C54E0 + 4 * v5 + 16552) otherwise. [global:0x005F0780, global:0x007C54E0, source:raw]
    // GUARD: Guard: if the reference time v6 <= 0.0, return 0. [source:raw]
    // CALCULATION: Read the comparison time v7 from *(v3 + 4 * v5 + 16460) where v3 is the race-state base. [global:0x007C54E0, source:raw]
    // GUARD: Guard: if the comparison time v7 <= 0.0, return 0. [source:raw]
    // CALCULATION: Compute the signed difference v8 = v7 - v6 and its absolute value v10 = fabs(v8) for display. [source:raw]
    // CALL: Decompose the absolute seconds value into minutes/seconds components via SpatialGridCell(v10, &v11, &a1). [callee:0x0049B630, source:raw]
    // CALL: Format the result into v2 with StringFormatWithBufferOverflowCheck using "-%.2d:%06.3f" when the difference is negative and "+%.2d:%06.3f" otherwise. [callee:0x0058815F, source:raw]
    // RETURN: Return 0 on every path, including the success path after formatting. [function:0x0049BE50, source:raw]
    // CALL: Invoked from UtilityFunction_d8b0 (0x0049D8B0) and MultiColorTextRender (0x004DBF90), i.e. lap/sector timing HUD display paths. [caller:0x0049D8B0, caller:0x004DBF90]

    // Conservative worker pseudocode:
    //   int FormatSectorTimeDifference(char *a1, int a2) {
    //     char *dst = strcpy(a1, asc_5CCE18);
    //     int base = dword_7C54E0;
    //     if (*(int *)(base + 16532) != 2) return 0;
    //     if ((byte_7CFFF0 & 2) != 0) {
    //       int g = sub_4D1B50(0);
    //       if (g == 255) return 0;
    //       int idx = *(int *)(dword_7C54E0 + 16448);
    //       double ref = flt_5F0780[4656 * g + idx];
    //     } else {
    //       int idx = *(int *)(dword_7C54E0 + 16448);
    //       double ref = *(float *)(dword_7C54E0 + 4 * idx + 16552);
    //     }
    //     if (ref <= 0.0) return 0;
    //     double cur = *(float *)(base + 4 * idx + 16460);
    //     if (cur <= 0.0) return 0;
    //     double diff = cur - ref;
    //     float abs = fabs(diff);
    //     int mins; float secs;
    //     SpatialGridCell(abs, &mins, &secs);
    //     if (diff < 0.0)
    //       StringFormatWithBufferOverflowCheck(dst, "-%.2d:%06.3f", mins, secs);
    //     else
    //       StringFormatWithBufferOverflowCheck(dst, "+%.2d:%06.3f", mins, secs);
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440 is listed in the deterministic global facts but does not appear in the decompiled body; likely a constant-pool float (zero threshold) feeding one of the timing values.
    // UNRESOLVED: a2d063f (0x005CCE34) and a2d063f_0 (0x005CCE44) are listed as globals read but do not appear in the decompiled body; likely adjacent string literals / format helpers in the same data region as asc_5CCE18.
    // UNRESOLVED: dword_8ACEE0 is listed as a global read but is absent from the decompiled body.
    // UNRESOLVED: SpatialGridCell is decompiler-named and its exact output layout (minutes int + seconds float) is DERIVED from the format string '%.2d:%06.3f'; the second output is passed through the reused stack slot of parameter a1.
}
