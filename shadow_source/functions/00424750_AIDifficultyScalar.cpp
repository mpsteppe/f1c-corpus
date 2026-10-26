// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424750
// Canonical corpus name: AIDifficultyScalar
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AIDifficultyScalar_00424750.c

void UnknownObject::AIDifficultyScalar()
{
    // Maps the AI difficulty slider value (dword_7D01A0) to a scalar. If the slider is >= 95, returns 1.0 directly (maximum ability); otherwise returns a linear interpolation (double)(dword_7D01A0 - 70) * 0.039999999 * 0.25 + 0.75, spanning roughly 0.75 to below 1.0.
    // GUARD: Guard: if dword_7D01A0 is >= 95, take the early-return path with the flat maximum scalar. [global:0x007D01A0, source:raw]
    // RETURN: Return 1.0 when the difficulty slider is at or above 95. [global:0x007D01A0, source:raw]
    // CALCULATION: Compute scaled difficulty value: (double)(dword_7D01A0 - 70) * 0.039999999 * 0.25 + 0.75. [global:0x007D01A0, source:raw]
    // RETURN: Return the computed scalar when the slider is below 95. [global:0x007D01A0, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7D01A0 >= 95)
    //     return 1.0;
    //   else
    //     return (double)(dword_7D01A0 - 70) * 0.039999999 * 0.25 + 0.75;
    // UNRESOLVED: Four globals (0x0059E43C, 0x0059E7F8, 0x0059E7FC, 0x0059E860) are listed as read in the packet but do not appear in the raw decompiled source; their role in this function is not evidenced.
}
