// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004732D0
// Canonical corpus name: sub_4732D0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4732D0_004732d0.c

void UnknownObject::DrivingModeUIDisplayUpdate()
{
    // Straight-line UI display updater. Stores the global mode flag dword_7D0410 into this+0x324 (offset 804) and the list-index data pointer &unk_7D0158 into this+0x320 (offset 800). It applies driving-mode parameters from the config byte_7CE498 via DrivingModeParameterSetup, reads a list value through the double-dereferenced index pointer stored at this+0x320, formats it into a stack buffer with overflow checking, and updates the UI edit buffer with the formatted string. Returns 0.
    // ASSIGNMENT: Store the global mode flag dword_7D0410 into this+0x324 (offset 804). [field:this:0x00000324, global:0x007D0410]
    // ASSIGNMENT: Store the list-index data pointer &unk_7D0158 into this+0x320 (offset 800). [field:this:0x00000320, global:0x007D0158]
    // CALL: Apply driving-mode parameters from the config byte_7CE498 via DrivingModeParameterSetup. [callee:0x004ADF10, global:0x007CE498]
    // CALL: Fetch the list value whose index pointer is read by dereferencing this+0x320 and reading its first dword via UIListIndexedAccessor(this, ...). [callee:0x00487010, field:*(this+0x320):0x00000000]
    // CALL: Format the fetched value into the stack buffer v4 with overflow protection via StringFormatWithBufferOverflowCheck. [callee:0x0058815F]
    // CALL: Update the UI edit buffer with the formatted string via EditBufferStringUpdate. [callee:0x0048B810]
    // RETURN: Return 0. [function:0x004732D0]

    // Conservative worker pseudocode:
    //   int DrivingModeUIDisplayUpdate(int this) {
    //     char buf[32];
    //     *(int*)(this + 0x320) = &unk_7D0158;
    //     *(int*)(this + 0x324) = dword_7D0410;
    //     DrivingModeParameterSetup((int)byte_7CE498);
    //     int idx = **(int**)(this + 0x320);
    //     char* val = UIListIndexedAccessor((int*)this, idx);
    //     StringFormatWithBufferOverflowCheck(buf, (int)val);
    //     EditBufferStringUpdate((int*)this, buf);
    //     return 0;
    //   }
    // UNRESOLVED: Semantic identity of the data at this+0x320 (offset 800) and the meaning of its first dword as a list index are not proven by this packet.
    // UNRESOLVED: Whether dword_7D0410 is a ChampionshipMode/RaceMode selector or another mode flag is not proven by this packet.
    // UNRESOLVED: Meaning of the stack buffer content produced by StringFormatWithBufferOverflowCheck is not proven by this packet.
}
