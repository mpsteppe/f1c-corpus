// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004735B0
// Canonical corpus name: UIFrontendCounterDisplayUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIFrontendCounterDisplayUpdate_004735b0.c

void UnknownObject::UIFrontendCounterDisplayUpdate()
{
    // UI frontend counter display update. Reads global dword_7D0110; if it equals the cached value at this[199] (offset 0x31C) it returns 0 immediately without updating. Otherwise it caches the new value, then chooses a display string: if the value is zero it formats the string returned by UIListIndexedAccessor(0); if the value differs from the second comparison global dword_7D011C it formats the raw integer via '%d'; otherwise it formats the string returned by UIListIndexedAccessor(1). In every branch the formatted buffer is pushed through EditBufferStringUpdate and 0 is returned.
    // GUARD: If dword_7D0110 equals the cached index at this[199] (offset 0x31C), return 0 immediately with no display update. [global:0x007D0110, field:this:0x0000031C, source:raw]
    // ASSIGNMENT: Cache the current dword_7D0110 value into this[199] (offset 0x31C). [field:this:0x0000031C, source:raw]
    // GUARD: Branch on the new value: zero selects the list-string path via accessor(0); a value not equal to the second global dword_7D011C selects the raw integer path; otherwise the list-string path via accessor(1) is taken. [source:raw]
    // CALL: UIListIndexedAccessor(0) fetches the display string for index zero. [callee:0x00487010, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the list string into a 32-byte stack buffer. [callee:0x0058815F, source:raw]
    // CALL: EditBufferStringUpdate pushes the formatted string to the UI display buffer. [callee:0x0048B810, source:raw]
    // CALL: UIListIndexedAccessor(1) fetches the display string for the special-value index. [callee:0x00487010, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck formats the current index as a raw integer via the '%d' format literal (packet read-global aD_1 at 0x005C3280 plausibly backs that literal) when it does not match the special value. [callee:0x0058815F, global:0x005C3280, source:raw]
    // RETURN: Return 0 from every display path. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4735B0(_DWORD* this) {
    //     char buf[32];
    //     int v = dword_7D0110;
    //     if (v == this[199]) return 0;
    //     this[199] = v;
    //     if (!v) {
    //       StringFormatWithBufferOverflowCheck(buf, UIListIndexedAccessor(0));
    //     } else if (v != dword_7D011C) {
    //       StringFormatWithBufferOverflowCheck(buf, "%d", v);
    //     } else {
    //       StringFormatWithBufferOverflowCheck(buf, UIListIndexedAccessor(1));
    //     }
    //     EditBufferStringUpdate(buf);
    //     return 0;
    //   }
    // UNRESOLVED: The second comparison global dword_7D011C appears in the raw source but has no global entry in this packet's evidence; its identity and the special value it marks are unknown.
    // UNRESOLVED: Whether the packet read-global aD_1 (0x005C3280) is exactly the '%d' format literal is not directly confirmed by the raw source shown; it is a DERIVED association.
    // UNRESOLVED: The contents and meaning of the UI list strings returned by UIListIndexedAccessor are unknown.
    // UNRESOLVED: The object owning this and the purpose of the displayed counter are unknown.
}
