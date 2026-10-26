// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00472930
// Canonical corpus name: sub_472930
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_472930_00472930.c

void UnknownObject::CarPartVisibilityScreenSetup()
{
    // UI screen element setup for car part visibility selection. Stores the championship/race mode global into this+0x324 (this[201]) and binds the car part data pointer global into this+0x320 (this[200]), reads the indexed list entry via UIListIndexedAccessor, formats it into a stack buffer, then drives CarPartVisibilityController with the config data global and updates the edit buffer string. Always returns 0.
    // ASSIGNMENT: Store dword_7D0410 (championship/race mode) into this[201] (this+0x324). [field:this:0x00000324, global:0x007D0410, source:raw]
    // ASSIGNMENT: Bind the address of dword_7CFF60 (car part data pointer) into this[200] (this+0x320). [field:this:0x00000320, global:0x007CFF60, source:raw]
    // CALL: UIListIndexedAccessor(this, dword_7CFF60) fetches the indexed entry string from the UI list bound to the car part data pointer. [callee:0x00487010, global:0x007CFF60, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the indexed entry string into the stack buffer v4. [callee:0x0058815F, source:raw]
    // CALL: CarPartVisibilityController((int)byte_7CE498) applies car part visibility with the config data pointer. [callee:0x004AE490, global:0x007CE498, source:raw]
    // CALL: EditBufferStringUpdate(this, v4) pushes the formatted string into the edit buffer of this screen element. [callee:0x0048B810, source:raw]
    // RETURN: Return 0 unconditionally. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_472930(ScreenElement* this) {
    //     this->dataSlot = &dword_7CFF60;       // this[200]
    //     this->modeSlot = dword_7D0410;        // this[201]
    //     char buf[32];
    //     char* entry = UIListIndexedAccessor(this, dword_7CFF60);
    //     StringFormatWithBufferOverflowCheck(buf, entry);
    //     CarPartVisibilityController((int)byte_7CE498);
    //     EditBufferStringUpdate(this, buf);
    //     return 0;
    //   }
    // UNRESOLVED: Identity and layout of the screen element object (this) are unknown; only offsets +0x320/+0x324 are evidenced.
    // UNRESOLVED: Semantics of byte_7CE498 config pointer passed to CarPartVisibilityController are unconfirmed.
    // UNRESOLVED: No static frame-path callers were found in the packet.
}
