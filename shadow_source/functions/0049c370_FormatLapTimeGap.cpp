// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C370
// Canonical corpus name: sub_49C370
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C370_0049c370.c

void UnknownObject::FormatLapTimeGap()
{
    // Formats the time gap (or lap-count gap) between the current object and a target for HUD/debug text. Seeds the output buffer a1 with asc_5CCE54, then bails out when the suppression flag at dword_7C54E0 + 16484 is set or the target (at dword_7C54E0 + 16592) is null/suppressed or LapTimeGapCalculation fails. When behind, fabs + SpatialGridCell convert the gap into minutes/seconds formatted as "-%.2d:%06.3f". When ahead, picks a unit label (off_5CCE74 for exactly 1 lap, otherwise aLaps_0), resolves it through BinarySearchInStringTable into byte_5EC4CC, and formats " -%d %s".
    // ASSIGNMENT: strcpy(a1, asc_5CCE54): seed the output buffer a1 with the header string stored at 0x005CCE54. [global:0x005CCE54, source:raw]
    // GUARD: Guard: if the flag at dword_7C54E0 + 16484 is non-zero (display suppression on the current object), return 0 immediately. [global:0x007C54E0, source:raw]
    // CALL: Read the target object pointer at dword_7C54E0 + 16592; if it is null, its suppression flag at +16484 is set, or LapTimeGapCalculation(target, current, &gap, &lapCount) fails, return 0. [global:0x007C54E0, callee:0x0049B6D0, source:raw]
    // GUARD: Behind case: when the lap-count result <= 0, take fabs of the gap value, convert it with SpatialGridCell into minutes/seconds components, and format "-%.2d:%06.3f" into the buffer. [callee:0x0049B630, callee:0x0058815F, source:raw]
    // ASSIGNMENT: Ahead case: pick the unit label - off_5CCE74 when the lap count equals 1, otherwise aLaps_0. [global:0x005CCE74, global:0x005CCE6C, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, label, byte_5EC4CC) looks the label up in the sorted string table; on a match copy the label into byte_5EC4CC, otherwise clear byte_5EC4CC[0] to 0. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, source:raw]
    // CALL: Format " -%d %s" with the lap count and byte_5EC4CC via StringFormatWithBufferOverflowCheck. [callee:0x0058815F, global:0x005EC4CC, source:raw]
    // CALL: Invoked by sub_49D700 (0049d700) and DrawDebugTextOverlay (004dbb60) as part of HUD/debug text rendering. [caller:0x0049D700, caller:0x004DBB60]

    // Conservative worker pseudocode:
    //   int sub_49C370(char *out, int a2) {
    //     char *p = strcpy(out, asc_5CCE54);
    //     if (*(int *)(dword_7C54E0 + 16484)) return 0;
    //     int target = *(int *)(dword_7C54E0 + 16592);
    //     float gap; int laps;
    //     if (!target || *(int *)(target + 16484)) return 0;
    //     if (LapTimeGapCalculation(target, dword_7C54E0, &gap, &laps)) return 0;
    //     if (laps <= 0) {
    //       gap = fabsf(gap);
    //       SpatialGridCell(gap, &laps, &gap);
    //       StringFormatWithBufferOverflowCheck(p, "-%.2d:%06.3f", laps, gap);
    //       return 0;
    //     }
    //     const char *label = (laps == 1) ? (const char *)&off_5CCE74 : aLaps_0;
    //     if (BinarySearchInStringTable(byte_5EC4C0, label, byte_5EC4CC)) {
    //       if (label) strcpy(byte_5EC4CC, label);
    //       else byte_5EC4CC[0] = 0;
    //     }
    //     StringFormatWithBufferOverflowCheck(p, " -%d %s", laps, byte_5EC4CC);
    //     return 0;
    //   }
    // UNRESOLVED: Parameter a2 is unused in the raw source.
    // UNRESOLVED: Globals a2d063f (0x005CCE34) and aDS_1 (0x005CCE64) are flagged by packet facts but do not appear in the raw source text, so their roles are unresolved.
    // UNRESOLVED: The buffer a1 doubles as both the output string and the stack slot receiving the gap float via (float*)&a1; LapTimeGapCalculation's exact write order into gap/lapCount is not established from this packet.
}
