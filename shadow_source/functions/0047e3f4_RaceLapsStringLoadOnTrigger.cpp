// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047E3F4
// Canonical corpus name: RaceLapsStringLoadOnTrigger
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceLapsStringLoadOnTrigger_0047e3f4.c

void UnknownObject::RaceLapsStringLoadOnTrigger()
{
    // Display trigger for the race-laps string. The prologue increments a byte at a2+95 by a1 and then executes a corrupted indirect call with an icebp trap, both flagged by the decompiler as unreliable due to bad/positive stack pointer values. The reliable core looks up the season races section via SeasonRacesSectionFinder, searches it for the "racelaps" string key through StringKeyedLinkedListSearch, reads the entry data with DataEntryAccessor, and feeds the result to UIStringComparison. Always returns 0.
    // CALCULATION: Increment the byte at a2+95 by the register-passed value a1; this prologue operates on a corrupted stack frame whose layout is not trustworthy. [source:raw]
    // UNKNOWN: Indirect call at v5-117 followed by an icebp trap; v5 is an uninitialized local and the decompiler reports bad/positive sp values, so this call target and its effect are unknowable from the raw source. [source:raw]
    // GUARD: Only proceed when SeasonRacesSectionFinder(0) returns a nonzero season races section. [callee:0x004C5840, source:raw]
    // CALL: Search the season data linked list for the "racelaps" string key with StringKeyedLinkedListSearch(aRacelaps). [callee:0x005679C0, global:0x005C7444, source:raw]
    // GUARD: Only continue when the "racelaps" node v2 was found (nonzero). [source:raw]
    // CALL: Extract the entry data from the found node via DataEntryAccessor(v2). [callee:0x00567970, source:raw]
    // CALL: Pass the extracted data to UIStringComparison(v3) to display the race-laps string. [callee:0x00488B40, source:raw]
    // RETURN: Return 0 unconditionally. [function:0x0047E3F4, source:raw]

    // Conservative worker pseudocode:
    //   int __usercall sub_47E3F4(char a1@<bl>, int a2@<ebp>) {
    //     *(char*)(a2 + 95) += a1;
    //     // corrupted indirect call at (v5 - 117) and icebp: unreliable, omitted
    //     if (SeasonRacesSectionFinder(0)) {
    //       void *node = StringKeyedLinkedListSearch(aRacelaps);
    //       if (node) {
    //         void *data = DataEntryAccessor(node);
    //         UIStringComparison(data);
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The prologue (a2+95 increment, corrupted indirect call, icebp) is a decompiler artifact from bad/positive stack pointer detection; the true call graph of this function is uncertain.
    // UNRESOLVED: unk_8AC368 is listed in the packet globals but never referenced by the raw source of this function; its role here is unknown.
    // UNRESOLVED: The argument to UIStringComparison and the exact display effect are not established here.
    // UNRESOLVED: The identity of a2 (frame pointer used as a base) and the meaning of the byte at +95 are not established.
}
