// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0058801D
// Canonical corpus name: StringStreamReadWithMaskCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/StringStreamReadWithMaskCheck_0058801d.c

void UnknownObject::StringStreamReadWithMaskCheck()
{
    // Cdecl stream-read wrapper: writes the 8-byte result of FileIOThreeStepSequence(a1) into a2, then performs a failure check on the two dwords of the written qword. Returns 0 when (a2[4] & a2[0]) != -1, otherwise returns -1. Callers: ArrayStateRead (0x004D47E0), LocaleEncodingStateQuery (0x005991C3) and sub_59A221 (0x0059A221).
    // CALL: Call FileIOThreeStepSequence(a1) and store the returned 8-byte value at a2 as a single qword. [callee:0x0058C7FC, source:raw]
    // ASSIGNMENT: Seed the default result to -1 before the mask check. [source:raw]
    // GUARD: Guard on (*(_DWORD*)(a2+4) & *(_DWORD*)a2) != -1; when the AND of the two written dwords is not all-ones the function takes the success path. [source:raw]
    // RETURN: Return 0 when the mask check passes, otherwise return the default -1. [function:0x0058801D, source:raw]
    // CALL: Invoked by ArrayStateRead (0x004D47E0), LocaleEncodingStateQuery (0x005991C3) and sub_59A221 (0x0059A221) to read stream data and report a masked all-ones failure. [caller:0x004D47E0, caller:0x005991C3, caller:0x0059A221]

    // Conservative worker pseudocode:
    //   int StringStreamReadWithMaskCheck(int a1, int a2) {
    //     *(_QWORD *)a2 = FileIOThreeStepSequence(a1);
    //     if ((*(_DWORD *)(a2 + 4) & *(_DWORD *)a2) != -1) return 0;
    //     return -1;
    //   }
    // UNRESOLVED: Meaning of the all-ones condition on (a2[4] & a2[0]) is not established here; it likely encodes a sentinel/EOF pattern from the FileIOThreeStepSequence path.
    // UNRESOLVED: Field offsets within the 8-byte output (a2) are accessed via raw pointer arithmetic and have no named field evidence in this packet.
}
