// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004894D0
// Canonical corpus name: StrlenOverwrite
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StrlenOverwrite_004894d0.c

void UnknownObject::StrlenOverwrite()
{
    // Writes the fixed two-byte global word_5C692C over the two bytes at the end of the null-terminated string a1 (at a1[strlen(a1)], i.e. at the terminator position), returning 0. If a1 is null, returns -1 without writing. Invoked by results, standings, message-buffer, career-stats HTML and related UI writers to stamp a shared value onto the tail of name/text buffers.
    // GUARD: Null guard: if the string pointer a1 is null, return -1 immediately without touching memory. [source:raw, function:0x004894D0]
    // CALCULATION: Compute the end of the string via strlen(a1) so the write lands at the terminator position a1[strlen(a1)]. [source:raw]
    // ASSIGNMENT: Store the two-byte global word_5C692C at the computed position (*(WORD*)&a1[strlen(a1)] = word_5C692C), overwriting the terminator and the following byte with the fixed value. [global:0x005C692C, source:raw]
    // RETURN: Return 0 after the write succeeds. [source:raw]
    // CALL: Invoked by results, standings, message and HTML-writing paths including sub_469900, ResultsPageBuilder, StandingsDisplay, MessageNameBufferUpdate, sub_475150, sub_47C360, sub_47D800, DriverCareerStatsHTMLWriter and sub_47E0A0. [caller:0x00469900, caller:0x00469FB0, caller:0x0046A560, caller:0x0046AD50, caller:0x00475150, caller:0x0047C360, caller:0x0047D800, caller:0x0047DD10, caller:0x0047E0A0, source:raw]

    // Conservative worker pseudocode:
    //   int StrlenOverwrite(const char* a1) {
    //     if (!a1) return -1;
    //     *(WORD*)&a1[strlen(a1)] = word_5C692C;
    //     return 0;
    //   }
    // UNRESOLVED: The purpose and value of the fixed word global 0x005C692C are unknown; the overwrite lands on the NUL terminator (and the byte after it), which would normally break the string, so the caller must treat the buffer as a fixed-size field rather than a C string afterwards.
    // UNRESOLVED: Whether the two bytes replace the terminator or are appended into reserved space depends on the caller's buffer layout, which is not evidenced in this packet.
    // UNRESOLVED: Caller names are prelabel labels; their semantics are not evidenced here.
}
