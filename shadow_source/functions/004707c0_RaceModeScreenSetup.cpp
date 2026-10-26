// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004707C0
// Canonical corpus name: RaceModeScreenSetup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RaceModeScreenSetup_004707c0.c

void UnknownObject::RaceModeScreenSetup()
{
    // Race-mode screen parameter initializer: stores the RaceMode value dword_7D0410 into this at offset 0x324 and the address of the parameter float flt_7D122C into this at offset 0x320, then formats a display string and pushes it into the edit buffer. When flt_7D122C is 0.0 it formats the first UI list item (index 0) instead; otherwise it formats the float itself with the "%.1f" format string. Always returns 0.
    // ASSIGNMENT: Store (float)dword_7D0410 into this at offset 0x324 (byte 804, dword index 201). [field:this:0x00000324, global:0x007D0410, source:raw]
    // ASSIGNMENT: Store the address of flt_7D122C into this at offset 0x320 (byte 800, dword index 200). [field:this:0x00000320, global:0x007D122C, source:raw]
    // GUARD: Branch on whether the parameter float flt_7D122C equals 0.0: zero selects the UI-list formatting path, non-zero selects the float-formatting path. [global:0x007D122C, source:raw]
    // CALL: Zero branch: v2 = UIListIndexedAccessor(this, 0); fetch the UI list item at index 0. [callee:0x00487010, source:raw]
    // CALL: Zero branch: StringFormatWithBufferOverflowCheck(v4, v2); format the UI list item text into the local buffer. [callee:0x0058815F, source:raw]
    // CALL: Non-zero branch: StringFormatWithBufferOverflowCheck(v4, "%.1f", flt_7D122C); format the float value using the "%.1f" format string (the packet labels global a1f at 0x005C6E50 as this format string). [callee:0x0058815F, global:0x005C6E50, global:0x007D122C, source:raw]
    // CALL: EditBufferStringUpdate(this, v4); push the formatted display text into the edit buffer. [callee:0x0048B810, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int RaceModeScreenSetup(_DWORD *this) {
    //       *(float *)(this + 804) = (float)dword_7D0410;   // offset 0x324: RaceMode
    //       *(_DWORD *)(this + 800) = &flt_7D122C;          // offset 0x320: parameter float ptr
    //       char buf[32];
    //       if (flt_7D122C == 0.0)
    //           StringFormatWithBufferOverflowCheck(buf, UIListIndexedAccessor(this, 0));
    //       else
    //           StringFormatWithBufferOverflowCheck(buf, "%.1f", flt_7D122C);
    //       EditBufferStringUpdate(this, buf);
    //       return 0;
    //   }
    // UNRESOLVED: global:0x0059E440 (flt_59E440) is listed as a read global in the packet but the raw source text never references it; the compiled equality test flt_7D122C == 0.0 may fold against a shared zero-threshold float there. Not asserted.
    // UNRESOLVED: Whether the fields at offsets 0x320/0x324 (pointer binding plus race mode) are consumed by other UI code after this setup step is not evidenced.
    // UNRESOLVED: Return value 0 is unconditional; whether it is a status code is unknown.
}
