// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00474510
// Canonical corpus name: sub_474510
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_474510_00474510.c

void UnknownObject::updateSeasonDisplay()
{
    // Straight-line UI refresh method: stores the global dword_7D0410 value into field this+0x320 and the address of the global pointer dword_7CFDE8 into field this+0x324, retrieves a display value with UIListIndexedAccessor(dword_7CFDE8), formats it into a stack string buffer with StringFormatWithBufferOverflowCheck, pushes the formatted text into the UI edit buffer via EditBufferStringUpdate, and returns 0. Called by sub_474440; a legacy ABI lead names it SessionEnter_Alt.
    // ASSIGNMENT: Stores the global dword_7D0410 value (championship/race mode) into field this+0x320. [field:this:0x00000320, global:0x007D0410]
    // ASSIGNMENT: Stores the address of the global pointer dword_7CFDE8 into field this+0x324. [field:this:0x00000324, global:0x007CFDE8]
    // CALL: UIListIndexedAccessor(dword_7CFDE8) retrieves the display value for the season path reference into v1. [callee:0x00487010, global:0x007CFDE8]
    // CALL: StringFormatWithBufferOverflowCheck(v3, v1) formats the retrieved value into the stack buffer v3. [callee:0x0058815F]
    // CALL: EditBufferStringUpdate(v3) updates the UI edit/display buffer with the formatted string. [callee:0x0048B810]
    // RETURN: Returns 0. [function:0x00474510, abi:lead, source:raw]

    // Conservative worker pseudocode:
    //   int updateSeasonDisplay(UIObject* this) {
    //     this[200] = dword_7D0410;
    //     this[201] = &dword_7CFDE8;
    //     int v1 = UIListIndexedAccessor(dword_7CFDE8);
    //     char v3[32];
    //     StringFormatWithBufferOverflowCheck(v3, v1);
    //     EditBufferStringUpdate(v3);
    //     return 0;
    //   }
    // UNRESOLVED: The semantics of the two globals (dword_7D0410 as ChampionshipMode and dword_7CFDE8 as a season-path string pointer) come from the skeleton prose and a legacy ABI lead, not from evidence in this packet.
    // UNRESOLVED: The object type behind `this` and the meaning of fields +0x320 and +0x324 are not established; the legacy ABI name SessionEnter_Alt is not independently confirmed.
    // UNRESOLVED: The role of the formatted edit-buffer text (v3) and which UI element consumes it is outside this function's evidence.
}
