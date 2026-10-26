// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A08E0
// Canonical corpus name: sub_4A08E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4A08E0_004a08e0.c

void UnknownObject::ClassificationScreenFileLoad()
{
    // Conditionally loads and displays classification/scoring screen data. When DelegatedFieldGetter on dword_7D2DB0 returns 3, LinkedListDereference yields a non-null vehicle node, and FixedOffsetReturn on that node is truthy, it resolves the scene name via SceneNameLookupBySeason into a local buffer. If PathFileComparisonCounter on that name returns 1 and dword_7D032C equals 1, it builds a path from dword_5EC418 (fallback byte_5EA438) plus aWinconstructor via StringFormatWithBufferOverflowCheck and loads it with FileLoadWithRetryLoop. Always calls ScoringClassificationDisplay and returns 0.
    // GUARD: DelegatedFieldGetter(&dword_7D2DB0) must equal 3 for any of the loading logic to run [callee:0x004C2760, global:0x007D2DB0, source:raw]
    // CALL: LinkedListDereference(&dword_7D2DB0) returns a node v0; processing continues only when v0 is non-null [callee:0x004C2850, global:0x007D2DB0, source:raw]
    // GUARD: FixedOffsetReturn(v0) must return a truthy value before the scene lookup runs [callee:0x004C1390, source:raw]
    // CALL: SceneNameLookupBySeason fills the 128-byte local buffer v3 with the resolved scene name [callee:0x004C0A20, source:raw]
    // GUARD: PathFileComparisonCounter(v3) must equal 1 AND dword_7D032C must equal 1 for the file load to proceed [callee:0x004C1450, global:0x007D032C, source:raw]
    // CALCULATION: Path base is dword_5EC418, falling back to byte_5EA438 when dword_5EC418 is null [global:0x005EC418, global:0x005EA438, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds "%s%s" from the path base and aWinconstructor into the v4 buffer; the aSS global is the packet's DERIVED label for this path-format string [callee:0x0058815F, global:0x005CD018, global:0x005BE860, source:raw]
    // CALL: FileLoadWithRetryLoop loads the constructed path with index 1 [callee:0x004F9B70, source:raw]
    // CALL: ScoringClassificationDisplay is called unconditionally after the guarded block [callee:0x0041E320, source:raw]
    // RETURN: Return literal 0; the function has no static callers in this packet [function:0x004A08E0, source:raw]

    // Conservative worker pseudocode:
    //   if (DelegatedFieldGetter(&dword_7D2DB0) == 3) {
    //     v0 = LinkedListDereference(&dword_7D2DB0);
    //     if (v0 && FixedOffsetReturn(v0)) {
    //       SceneNameLookupBySeason(v3, 128);
    //       if (PathFileComparisonCounter(v3) == 1 && dword_7D032C == 1) {
    //         base = dword_5EC418 ? dword_5EC418 : byte_5EA438;
    //         StringFormatWithBufferOverflowCheck(v4, "%s%s", base, aWinconstructor);
    //         FileLoadWithRetryLoop(v4, 1);
    //       }
    //     }
    //   }
    //   ScoringClassificationDisplay();
    //   return 0;
    // UNRESOLVED: Globals dword_5EB978 and unk_8AFE18 are listed by packet facts but appear nowhere in the raw decompiled source; their role is unverifiable from this packet
    // UNRESOLVED: The aSS global (005BE860) is not referenced by name in the raw source text; tying it to the "%s%s" path format is a DERIVED label from the existing analysis
    // UNRESOLVED: The exact meaning of the value 3 returned by DelegatedFieldGetter and the check dword_7D032C == 1 are not documented in this packet
}
