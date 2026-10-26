// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00590440
// Canonical corpus name: ShortInRangeCheckAgainstStaticTable
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ShortInRangeCheckAgainstStaticTable_00590440.c

void UnknownObject::ShortInRangeCheckAgainstStaticTable()
{
    // Linear membership scan of a static 16-bit table starting at unk_5E7204 and bounded by off_5E7218 (exclusive). Returns 0 when the 16-bit argument a1 matches a table word, and 1 after the pointer walks past the end bound. Used as a range/validity check by LocaleEnumProc (0x0058FFEC) and sub_59033A (0x0059033A).
    // ASSIGNMENT: Start of scan: v1 = &unk_5E7204, the base of the static 16-bit table [global:0x005E7204, source:raw]
    // LOOP: while (a1 != *v1) advance v1 one word at a time, comparing the argument against each table entry [source:raw]
    // GUARD: When the incremented pointer passes &off_5E7218 (the table end bound), the value is not present and the function returns 1 [global:0x005E7218, source:raw]
    // RETURN: Returns 0 when a match is found (a1 equals a table word); returns 1 when the scan exits past the end bound [function:0x00590440, source:raw]
    // CALL: Called by LocaleEnumProc (0x0058FFEC) and by sub_59033A (0x0059033A) to filter a 16-bit value against the static range table [caller:0x0058FFEC, caller:0x0059033A]

    // Conservative worker pseudocode:
    //   v1 = &unk_5E7204;
    //   while (a1 != *v1) {
    //       ++v1;
    //       if ((int)v1 >= (int)&off_5E7218)
    //           return 1;
    //   }
    //   return 0;
    // UNRESOLVED: The meaning of the table words between unk_5E7204 and off_5E7218 is unknown; only the bound addresses are evidenced, not the intended value domain
    // UNRESOLVED: The semantics of the return code (0 = present) relative to the callers' expectations is unproven here
    // UNRESOLVED: off_5E7218 is named as a pointer but the decompiler treats table elements as 16-bit words; whether the endpoint is itself a member of the data is ambiguous
}
