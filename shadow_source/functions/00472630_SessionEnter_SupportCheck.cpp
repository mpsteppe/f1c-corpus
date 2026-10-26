// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472630
// Canonical corpus name: sub_472630
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_472630_00472630.c

void UnknownObject::SessionEnter_SupportCheck()
{
    // UI screen setup: stores the race-mode global into this+0x324 and a pointer to the dword_7CFFA8 global into this+0x320, fetches the indexed list entry string via UIListIndexedAccessor, formats it into a local 32-byte buffer with StringFormatWithBufferOverflowCheck, calls sub_4AE9F0 with the byte_7CE498 config global, then sets this+0x310 to 0 or 2 depending on whether the dereferenced step counter (*(this+0x320) - 1) is at or below dword_5EC4A8. Finally commits the buffer through EditBufferStringUpdate and returns 0.
    // ASSIGNMENT: Store the race/mode global: this[201] (this+0x324) = dword_7D0410. [source:raw, field:this:0x00000324, global:0x007D0410]
    // ASSIGNMENT: Store pointer to the global: this[200] (this+0x320) = &dword_7CFFA8. [source:raw, field:this:0x00000320, global:0x007CFFA8]
    // CALL: UIListIndexedAccessor(this, dword_7CFFA8) fetches the indexed list entry string. [source:raw, callee:0x00487010, global:0x007CFFA8]
    // CALL: StringFormatWithBufferOverflowCheck(v4, entry) formats the entry into the 32-byte buffer v4. [source:raw, callee:0x0058815F]
    // CALL: sub_4AE9F0(byte_7CE498) passes the config byte global to an unknown helper. [source:raw, callee:0x004AE9F0, global:0x007CE498]
    // GUARD: Compare the dereferenced step counter minus one, *(this[200]) - 1, against dword_5EC4A8. [source:raw, global:0x005EC4A8]
    // ASSIGNMENT: When the guard holds (at or below the step bound), this[196] (this+0x310) = 0. [source:raw, field:this:0x00000310]
    // ASSIGNMENT: Otherwise this[196] (this+0x310) = 2 (can step further). [source:raw, field:this:0x00000310]
    // CALL: EditBufferStringUpdate(this, v4) commits the formatted string to the UI edit buffer. [source:raw, callee:0x0048B810]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_472630(void* this) {
    //     char buf[32];
    //     this[201] = dword_7D0410;
    //     this[200] = &dword_7CFFA8;
    //     char* entry = UIListIndexedAccessor(this, dword_7CFFA8);
    //     StringFormatWithBufferOverflowCheck(buf, (int)entry);
    //     sub_4AE9F0((int)byte_7CE498);
    //     this[196] = (*(int*)this[200] - 1 <= dword_5EC4A8) ? 0 : 2;
    //     EditBufferStringUpdate(this, buf);
    //     return 0;
    //   }
    // UNRESOLVED: Identity and purpose of sub_4AE9F0 and its byte_7CE498 argument are unknown.
    // UNRESOLVED: Semantic meaning of the this+0x310 flag values 0 and 2 is inferred, not confirmed.
    // UNRESOLVED: Function-name leads conflict: the LEGACY abi lead is 'SessionEnter_SupportCheck', while prior analysis labels it a camera-index screen setup; ownership stays UNKNOWN.
    // UNRESOLVED: No static callers were recorded for this function.
}
