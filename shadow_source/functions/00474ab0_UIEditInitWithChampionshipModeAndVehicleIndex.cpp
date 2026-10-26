// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474AB0
// Canonical corpus name: sub_474AB0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_474AB0_00474ab0.c

void UnknownObject::UIEditInitWithChampionshipModeAndVehicleIndex()
{
    // Initializes a UI edit control: stores a pointer to the visible-vehicle-index global (dword_7CFC8C) at this+0x320 and a snapshot copy of the championship/race-mode global (dword_7D0410) at this+0x324, formats the vehicle index into a local buffer with the "%d" format string, and pushes the formatted text into the edit buffer via EditBufferStringUpdate. Returns 0. Invoked by UIListInitWithDefault (00474A10).
    // ASSIGNMENT: Store snapshot copy of global dword_7D0410 (championship/race mode) into this+0x324 (this[201]) [field:this:0x00000324, global:0x007D0410, source:raw]
    // ASSIGNMENT: Store pointer to global dword_7CFC8C (visible vehicle index) into this+0x320 (this[200]) as a pointer copy for later UI binding [field:this:0x00000320, global:0x007CFC8C, source:raw]
    // CALL: Format the vehicle index into local buffer v3 via StringFormatWithBufferOverflowCheck using the "%d" format string global aD_1 and value dword_7CFC8C [callee:0x0058815F, global:0x005C3280, global:0x007CFC8C, source:raw]
    // CALL: Push the formatted string v3 into the edit buffer of this via EditBufferStringUpdate [callee:0x0048B810, source:raw]
    // RETURN: Return 0 (success) unconditionally; no guards in the function body [function:0x00474AB0, source:raw]
    // CALL: Invoked by UIListInitWithDefault (00474A10) as part of initializing a UI list's default edit control [caller:0x00474A10, source:raw]

    // Conservative worker pseudocode:
    //   this[201] = dword_7D0410;
    //   this[200] = &dword_7CFC8C;
    //   StringFormatWithBufferOverflowCheck(v3, "%d", dword_7CFC8C);
    //   EditBufferStringUpdate(this, v3);
    //   return 0;
    // UNRESOLVED: The semantic labels ChampionshipMode (dword_7D0410) and VisibleVehicleIndex (dword_7CFC8C) come from the packet's existing-analysis prose and are not independently proven by packet facts alone
}
