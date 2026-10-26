// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049BFF0
// Canonical corpus name: sub_49BFF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49BFF0_0049bff0.c

void UnknownObject::formatNextLapTimeString()
{
    // Formats the next lap time into an output buffer for HUD/replay display. Computes the next lap index (current lap counter at dword_7C54E0+16448 incremented by 1, wrapped 2->0), copies the empty prefix string asc_5CCE18 into the buffer, then selects the time source: when byte_7CFFF0 bit 0 is set it resolves the ghost car index via sub_4D1B50(0) (returning 0 without formatting when the index is 255/invalid) and reads flt_5F0780[4656*index+lap]; otherwise it reads the float at dword_7C54E0+4*lap+16552. The float is written into the first 4 bytes of the output buffer, and when it is positive the value is split via SpatialGridCell and appended with StringFormatWithBufferOverflowCheck as " %.2d:%06.3f".
    // CALCULATION: v2 = (lap counter at dword_7C54E0+16448) + 1, wrapped to 0 when the counter equals 2; selects the next lap index. [global:0x007C54E0]
    // CALL: strcpy copies the empty prefix string asc_5CCE18 into the output buffer a1; v3 retains the buffer pointer for the later append. [global:0x005CCE18, source:raw]
    // GUARD: When byte_7CFFF0 bit 0 is set, use the ghost/replay timing source; otherwise read the race-struct lap time. [global:0x007CFFF0]
    // CALL: Resolve the ghost/replay car index via sub_4D1B50(0). [callee:0x004D1B50]
    // GUARD: If the ghost index is 255 (invalid), return 0 without formatting anything. [callee:0x004D1B50]
    // ASSIGNMENT: v5 = flt_5F0780[4656 * ghostIndex + nextLapIndex]; the ghost lap time selected by car index and lap index. [global:0x005F0780]
    // ASSIGNMENT: v5 = *(float*)(dword_7C54E0 + 4*nextLapIndex + 16552); the race-struct lap time for the next lap. [global:0x007C54E0]
    // ASSIGNMENT: Write v5 as a float into the first 4 bytes of the output buffer a1. [source:raw]
    // GUARD: Formatting is only attempted when v5 > 0.0 (a valid lap time). [source:raw]
    // CALL: SpatialGridCell splits the float seconds value into minute/second components used for display. [callee:0x0049B630]
    // CALL: Append the formatted string via StringFormatWithBufferOverflowCheck(v3, " %.2d:%06.3f", minutes, seconds) into the buffer. [callee:0x0058815F]
    // RETURN: Return 0 (success) in all non-guard paths. [source:raw]

    // Conservative worker pseudocode:
    //   int formatNextLapTimeString(char* out, int unused) {
    //     int lap = lapCounter(dword_7C54E0) + 1;
    //     if (lapCounter(dword_7C54E0) == 2) lap = 0;
    //     char* buf = strcpy(out, emptyPrefix);
    //     float seconds;
    //     if (byte_7CFFF0 & 1) {
    //       int ghost = sub_4D1B50(0);
    //       if (ghost == 255) return 0;
    //       seconds = flt_5F0780[4656 * ghost + lap];
    //     } else {
    //       seconds = *(float*)(dword_7C54E0 + 4 * lap + 16552);
    //     }
    //     *(float*)out = seconds;
    //     if (seconds > 0.0) {
    //       int minutes;
    //       SpatialGridCell(seconds, &minutes, (float*)out);
    //       StringFormatWithBufferOverflowCheck(buf, " %.2d:%06.3f", minutes, seconds);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440, a2d063f_1 and dword_8ACEE0 are listed as packet globals but do not appear in the raw source; their role is unknown.
    // UNRESOLVED: Meaning of the hardcoded offsets 16448 / 16552 and the 4656 stride are inferred (lap counter / lap-time array); not independently confirmed.
    // UNRESOLVED: Literal character '\' (backslash) is used as the strcpy prefix; the exact content of asc_5CCE18 was not verified.
}
