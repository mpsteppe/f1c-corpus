// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049C670
// Canonical corpus name: sub_49C670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49C670_0049c670.c

void UnknownObject::FormatLapCounterString()
{
    // Formats a lap-count display string into destination buffer a1. Computes the current lap as the value at dword_7C54E0 + 16444 (decimal, +0x403C) plus 1, clamps it to the total lap count dword_8ACF8C, and calls StringFormatWithBufferOverflowCheck either with the unlimited-lap format string (aDD_1, " %d/--") when dword_8ACF8C equals 0x7FFFFFFF or with the normal format (aD_2, " %d/%d") plus the total otherwise. Always returns 0. The second argument a2 is not referenced in the body.
    // CALCULATION: v2 = *(_DWORD *)(dword_7C54E0 + 16444) + 1 reads the lap counter (decimal offset 16444 = +0x403C) inside the object pointed to by dword_7C54E0 and adds 1 [global:0x007C54E0, source:raw]
    // GUARD: If v2 > dword_8ACF8C clamp v2 down to dword_8ACF8C [global:0x008ACF8C, source:raw]
    // GUARD: Branch on whether dword_8ACF8C equals 0x7FFFFFFF (unlimited-lap sentinel) [global:0x008ACF8C, source:raw]
    // CALL: Unlimited path: StringFormatWithBufferOverflowCheck(a1, aDD_1, v2) formats the " %d/--" string [callee:0x0058815F, global:0x005CCE80, source:raw]
    // CALL: Normal path: StringFormatWithBufferOverflowCheck(a1, aD_2, v2, dword_8ACF8C) formats the " %d/%d" string [callee:0x0058815F, global:0x005CCE88, global:0x008ACF8C, source:raw]
    // RETURN: Return 0 [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49C670(int a1, int a2) {
    //     int lap = *(_DWORD *)(dword_7C54E0 + 16444) + 1;
    //     if (lap > dword_8ACF8C) lap = dword_8ACF8C;
    //     if (dword_8ACF8C == 0x7FFFFFFF)
    //       StringFormatWithBufferOverflowCheck(a1, aDD_1, lap);
    //     else
    //       StringFormatWithBufferOverflowCheck(a1, aD_2, lap, dword_8ACF8C);
    //     return 0;
    //   }
    // UNRESOLVED: The lap counter at dword_7C54E0 + 16444 (+0x403C) has no packet field evidence reference (packet fields list is empty); the decimal offset spelling 16444 is preserved from the raw source
    // UNRESOLVED: The format-string globals aDD_1 (0x005CCE80) and aD_2 (0x005CCE88) are inferred from the existing analysis to be the " %d/--" and " %d/%d" literals respectively (DERIVED)
    // UNRESOLVED: Argument a2 is present in the signature but never used in the body; its role is unknown
    // UNRESOLVED: The four callers are UI/text render routines; frame-path membership is NOT_FOUND
}
