// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00471DC0
// Canonical corpus name: TransmissionAIDifficultyScreenSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TransmissionAIDifficultyScreenSetup_00471dc0.c

void UnknownObject::TransmissionAIDifficultyScreenSetup()
{
    // Transmission/AI difficulty screen parameter initializer: stores the race-mode value dword_7D0410 into this at offset 0x324 and the address of the audio race-mode flag global dword_7D1FD8 into this at offset 0x320, fetches the UI list item indexed by dword_7D1FD8, formats it into a local buffer via StringFormatWithBufferOverflowCheck, pushes the text into the edit buffer via EditBufferStringUpdate, and always returns 0. No guards; every step executes unconditionally.
    // ASSIGNMENT: this[201] = dword_7D0410; store the race-mode value at offset 0x324 (byte 804). [field:this:0x00000324, global:0x007D0410, source:raw]
    // ASSIGNMENT: this[200] = &dword_7D1FD8; store the address of the audio race-mode flag global at offset 0x320 (byte 800). [field:this:0x00000320, global:0x007D1FD8, source:raw]
    // CALL: v2 = UIListIndexedAccessor(this, dword_7D1FD8); fetch the UI list item indexed by the flag value. [callee:0x00487010, global:0x007D1FD8, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v4, v2); format the fetched list item into the local 32-byte buffer. [callee:0x0058815F, source:raw]
    // CALL: EditBufferStringUpdate(this, v4); push the formatted display text into the edit buffer. [callee:0x0048B810, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int TransmissionAIDifficultyScreenSetup(_DWORD *this) {
    //       this[201] = dword_7D0410;             // offset 0x324: race mode
    //       this[200] = &dword_7D1FD8;            // offset 0x320: audio race-mode flag ptr
    //       char *item = UIListIndexedAccessor(this, dword_7D1FD8);
    //       char buf[32];
    //       StringFormatWithBufferOverflowCheck(buf, item);
    //       EditBufferStringUpdate(this, buf);
    //       return 0;
    //   }
    // UNRESOLVED: The ABI record is FAIL_471dc0; the owning object and the meaning of the pointer stored at offset 0x320 are not established.
    // UNRESOLVED: Whether the fields at offsets 0x320/0x324 are consumed elsewhere after this setup step is not evidenced.
}
