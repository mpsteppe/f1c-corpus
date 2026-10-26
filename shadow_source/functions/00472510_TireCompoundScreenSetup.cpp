// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472510
// Canonical corpus name: sub_472510
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_472510_00472510.c

void UnknownObject::TireCompoundScreenSetup()
{
    // Unconditional UI screen-setup for tire compound selection: stores the race mode global dword_7D0410 into this+0x324, binds the tire compound data pointer dword_7CFFCC into this+0x320, fetches the indexed list entry via UIListIndexedAccessor, formats it into a local buffer, clamps the compound config byte_7CE498, and updates the edit-buffer string. Returns 0.
    // ASSIGNMENT: Store the current race/championship mode global dword_7D0410 into the field at this+0x324 (this[201]). [source:raw, field:this:0x00000324, global:0x007D0410]
    // ASSIGNMENT: Bind the tire compound data pointer dword_7CFFCC into the field at this+0x320 (this[200]). [source:raw, field:this:0x00000320, global:0x007CFFCC]
    // CALL: Fetch the indexed list entry v2 via UIListIndexedAccessor(this, dword_7CFFCC). [source:raw, callee:0x00487010, global:0x007CFFCC]
    // CALL: Format the indexed value v2 into the local buffer via StringFormatWithBufferOverflowCheck with overflow protection. [source:raw, callee:0x0058815F]
    // CALL: Clamp the tire compound config data byte_7CE498 to a valid range via TireCompoundClamp. [source:raw, callee:0x004AF220, global:0x007CE498]
    // CALL: Update the UI edit buffer string from the formatted buffer via EditBufferStringUpdate(this, buf). [source:raw, callee:0x0048B810]
    // RETURN: Return the constant 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_472510(_DWORD *this) {
    //     char buf[32];
    //     this[201] = dword_7D0410;
    //     this[200] = &dword_7CFFCC;
    //     char *v = UIListIndexedAccessor(this, dword_7CFFCC);
    //     StringFormatWithBufferOverflowCheck(buf, (int)v);
    //     TireCompoundClamp(byte_7CE498);
    //     EditBufferStringUpdate(this, buf);
    //     return 0;
    //   }
    // UNRESOLVED: How UIListIndexedAccessor selects the index and how dword_7CFFCC relates to the tire compound list are not visible in this function.
    // UNRESOLVED: Layout of the config data byte_7CE498 passed to TireCompoundClamp is defined by that callee.
    // UNRESOLVED: Meaning of the data pointer bound at this+0x320 vs. the formatted string path is unverified.
}
