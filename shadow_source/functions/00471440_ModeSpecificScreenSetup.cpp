// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471440
// Canonical corpus name: ModeSpecificScreenSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ModeSpecificScreenSetup_00471440.c

void UnknownObject::ModeSpecificScreenSetup()
{
    // Sets up a UI screen element indexed by a mode. Computes a list pointer as 36 * dword_7D0410 + 8187528, stores it into this[200] (this+0x320), reads the indexed entry via UIListIndexedAccessor, formats it into a local buffer with StringFormatWithBufferOverflowCheck, and pushes it into the edit-buffer string display via EditBufferStringUpdate. Always returns 0. The legacy ABI symbol names it Mode_Specific_Screen_Setup but carries no prototype.
    // CALCULATION: Compute v1 = 36 * dword_7D0410 + 8187528: base-address plus 36-stride element offset keyed by global dword_7D0410 [global:0x007D0410, function:0x00471440, source:raw]
    // ASSIGNMENT: Store the computed list pointer into this[200] (this+0x320) [field:this:0x00000320, source:raw]
    // CALL: UIListIndexedAccessor(*v1): fetch the indexed entry from the mode-specific list; result captured into v2 [callee:0x00487010, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v4, v2): format the indexed value into the local buffer with an overflow check [callee:0x0058815F, source:raw]
    // CALL: EditBufferStringUpdate(v4): update the UI string display from the formatted buffer [callee:0x0048B810, source:raw]
    // RETURN: Return 0 unconditionally [function:0x00471440, source:raw]

    // Conservative worker pseudocode:
    //   v1 = (void *)(36 * dword_7D0410 + 8187528);
    //   this[200] = v1;
    //   v2 = UIListIndexedAccessor(*v1);
    //   StringFormatWithBufferOverflowCheck(v4, v2);
    //   EditBufferStringUpdate(v4);
    //   return 0;
    // UNRESOLVED: The 36-stride table base (8187528) and element layout are raw literals in source; the underlying array type is not defined in this packet
    // UNRESOLVED: dword_7D0410 is described in the existing analysis as ChampionshipMode/RaceMode but that naming is not independently established by this packet's evidence
    // UNRESOLVED: What the formatted string at this+0x320 represents on screen (e.g. a mode name) is inferred, not evidenced
    // UNRESOLVED: The v4 buffer's role in EditBufferStringUpdate is not detailed in this packet
}
