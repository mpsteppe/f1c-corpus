// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567B10
// Canonical corpus name: sub_567B10
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_567B10_00567b10.c

void UnknownObject::StringTrimAndTruncate()
{
    // String sanitation helper: copies input a1 into output buffer a2, trims leading and trailing characters accepted by CharacterClassCheck, and truncates at the first occurrence of the delimiter stored at unk_5C30B8 (located by sub_587C20). Returns 1 when the resulting string is non-empty, 0 when a1 is NULL or the trimmed result is empty. Called by FileSettingsDataLoad while parsing settings data.
    // ASSIGNMENT: Initialize output buffer to empty: *a2 = 0. [source:raw]
    // GUARD: If input pointer a1 is NULL, return 0 immediately. [function:0x00567B10, source:raw]
    // LOOP: Leading trim: scan forward from the input's first byte (field this+0x0, the initial character) while it is non-zero and CharacterClassCheck accepts it; stop at the first rejected or NUL byte, leaving v2 pointing at the first kept character. [callee:0x005678F0, field:this:0x00000000, source:raw]
    // CALL: strcpy(a2, v2): copy the remaining (non-trimmed) portion of the input into the output buffer. [source:raw]
    // CALL: sub_587C20(a2, &unk_5C30B8): search the copied string for the delimiter character held at unk_5C30B8. [callee:0x00587C20, global:0x005C30B8, source:raw]
    // ASSIGNMENT: If the delimiter was found (returned pointer v4 non-NULL), write *v4 = 0 to truncate the string at that position. [global:0x005C30B8, source:raw]
    // LOOP: Trailing trim: walk backwards from a2[strlen(a2) - 1] down to a2, zeroing each byte CharacterClassCheck accepts until the first rejected byte. Raw source writes through the decompiler variable v6 (*v6 = 0, j = v6 - 1); the intent is to zero the currently examined byte. [callee:0x005678F0, source:raw]
    // RETURN: Set result = 1, but return 0 when strlen(a2) is 0; otherwise return 1. [function:0x00567B10, source:raw]

    // Conservative worker pseudocode:
    //   char __stdcall StringTrimAndTruncate(unsigned __int8 *input, char *out) {
    //     *out = 0;
    //     if (!input) return 0;
    //     const char *p = (const char *)input;
    //     for (unsigned __int8 ch = *p; ch && CharacterClassCheck(ch); ch = *++p) {}
    //     strcpy(out, p);
    //     char *delim = sub_587C20(out, &unk_5C30B8);
    //     if (delim) *delim = 0;
    //     char *q = &out[strlen(out) - 1];
    //     for (; q >= out && CharacterClassCheck(*q); --q) *q = 0;
    //     return strlen(out) ? 1 : 0;
    //   }
    // UNRESOLVED: Trailing-trim loop in the raw source writes through uninitialized v6 (*v6 = 0 and j = v6 - 1); this is a decompiler artifact and the intended store is to the currently examined byte.
    // UNRESOLVED: strcpy and strlen are imported CRT calls not listed in the packet callees; they are referenced via source:raw only.
    // UNRESOLVED: The exact delimiter value at unk_5C30B8 and the exact character class accepted by CharacterClassCheck are not established from this packet alone.
}
