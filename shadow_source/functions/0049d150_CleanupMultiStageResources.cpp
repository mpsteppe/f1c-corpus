// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D150
// Canonical corpus name: MultiStageCleanupWithRepeatedCallCycle
// Owner: HudOverlayManager [GUESS]
// Raw source: functions/MultiStageCleanupWithRepeatedCallCycle_0049d150.c

void HudOverlayManager::CleanupMultiStageResources()
{
    // Multi-stage teardown for an on-screen overlay object. Releases the two sub-resource pointers held at dword indices 6 and 7 (offsets 0x18, 0x1C) and the three linked-list pointers at indices 1-3 (offsets 0x4, 0x8, 0xC) when non-null, then runs a four-phase cleanup sequence (ShortComputation_ec40, SoundResourceCleanup, SingleFieldFreeWrapper, ConditionalFreeSubCall) on five sub-blocks addressed by dword offsets 24/43/62/81/100 relative to this. Finally zeroes the byte flag at 0x0 and all DWORD fields 0x4..0x5C, returning 0.
    // GUARD: If the pointer at dword index 6 (offset 0x18) is non-null, release it via sub_53CB90 and clear the field. [field:this:0x00000018, callee:0x0053CB90]
    // GUARD: If the pointer at dword index 7 (offset 0x1C) is non-null, release it via sub_53CB90 and clear the field. [field:this:0x0000001C, callee:0x0053CB90]
    // GUARD: If the pointer at dword index 1 (offset 0x4) is non-null, run StringCompareLinkedListSearch on it and clear the field. [field:this:0x00000004, callee:0x0053D130]
    // GUARD: If the pointer at dword index 2 (offset 0x8) is non-null, run StringCompareLinkedListSearch on it and clear the field. [field:this:0x00000008, callee:0x0053D130]
    // GUARD: If the pointer at dword index 3 (offset 0xC) is non-null, run StringCompareLinkedListSearch on it and clear the field. [field:this:0x0000000C, callee:0x0053D130]
    // CALL: Run the four-phase cleanup (ShortComputation_ec40, SoundResourceCleanup, SingleFieldFreeWrapper, ConditionalFreeSubCall) on the sub-block at dword offset 24. [callee:0x0049EC40, callee:0x0049EC60, callee:0x0049ECA0, callee:0x0049ECC0, source:raw]
    // CALL: Run the same four-phase cleanup sequence on the sub-block at dword offset 43. [callee:0x0049EC40, callee:0x0049EC60, callee:0x0049ECA0, callee:0x0049ECC0, source:raw]
    // CALL: Run the same four-phase cleanup sequence on the sub-block at dword offset 62. [callee:0x0049EC40, callee:0x0049EC60, callee:0x0049ECA0, callee:0x0049ECC0, source:raw]
    // CALL: Run the same four-phase cleanup sequence on the sub-block at dword offset 81. [callee:0x0049EC40, callee:0x0049EC60, callee:0x0049ECA0, callee:0x0049ECC0, source:raw]
    // CALL: Run the same four-phase cleanup sequence on the sub-block at dword offset 100. [callee:0x0049EC40, callee:0x0049EC60, callee:0x0049ECA0, callee:0x0049ECC0, source:raw]
    // ASSIGNMENT: Zero the byte flag at offset 0x0. [field:this:0x00000000]
    // ASSIGNMENT: Zero the remaining DWORD fields from offset 0x4 through offset 0x5C. [field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, field:this:0x00000020, field:this:0x00000024, field:this:0x00000028, field:this:0x0000002C, field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, field:this:0x00000040, field:this:0x00000044, field:this:0x00000048, field:this:0x0000004C, field:this:0x00000050, field:this:0x00000054, field:this:0x00000058, field:this:0x0000005C]
    // RETURN: Return the constant result 0. [source:raw]

    // Conservative worker pseudocode:
    //   int CleanupMultiStageResources() {
    //     for (int i = 6; i <= 7; ++i) if (this[i]) { sub_53CB90(this[i]); this[i] = 0; }
    //     for (int i = 1; i <= 3; ++i) if (this[i]) { StringCompareLinkedListSearch(this[i]); this[i] = 0; }
    //     for each sub in {this+24, this+43, this+62, this+81, this+100}:
    //       ShortComputation_ec40(sub); SoundResourceCleanup(sub); SingleFieldFreeWrapper(sub); ConditionalFreeSubCall(sub);
    //     *(_BYTE*)this = 0;
    //     for (int i = 1; i < 24; ++i) this[i] = 0;
    //     return 0;
    //   }
    // UNRESOLVED: The existing-analysis prose interprets the five cleanup sub-block offsets as byte offsets 24/43/62/81/100, while the raw decompile types this as _DWORD* and the arithmetic this+24/43/62/81/100 is therefore dword (4-byte) indexing. Raw source outranks the prose; the byte positions of the sub-blocks remain unproven.
    // UNRESOLVED: Global dword_8AFE64 is read (per packet globals) but has no visible use in the raw source body; purpose unconfirmed.
    // UNRESOLVED: Identity of the sub-resource and linked-list object types is unknown; sub_53CB90 and StringCompareLinkedListSearch are release-style helpers only by name.
}
