// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00404FC0
// Canonical corpus name: sub_404FC0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_404FC0_00404fc0.c

void UnknownObject::LowpassCutoffTableEntry()
{
    // Bounded table getter over the low-pass cutoff string table at 0x005BE7A0. Returns a pointer to the a1-th entry (each entry is 32 bytes) when a1 is less than 4, otherwise NULL. Called by MilesSoundSampleProcessorSetup (004060C0), which indexes the four built-in low-pass filter cutoff presets.
    // ASSIGNMENT: Initialize the result pointer to 0 (NULL); this is the value returned for any out-of-range index [source:raw]
    // GUARD: Accept the index only when a1 < 4; otherwise keep the NULL result [source:raw]
    // CALCULATION: Compute the entry address as aLowpassCutoff + 32 * a1, treating the table as an array of 32-byte entries [global:0x005BE7A0, source:raw]
    // RETURN: Return the selected table entry for a valid index, or NULL otherwise; consumed by MilesSoundSampleProcessorSetup [function:0x00404FC0, global:0x005BE7A0, caller:0x004060C0, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 < 4)
    //     return &aLowpassCutoff[32 * a1];
    //   return 0;
    // UNRESOLVED: The element layout of the 32-byte table entries is not established from this packet; only the stride and entry count are evidenced
}
