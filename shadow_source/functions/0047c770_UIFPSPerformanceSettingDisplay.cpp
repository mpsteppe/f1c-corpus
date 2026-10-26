// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047C770
// Canonical corpus name: UIFPSPerformanceSettingDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIFPSPerformanceSettingDisplay_0047c770.c

void UnknownObject::UIFPSPerformanceSettingDisplay()
{
    // Reads the global framerate counter dword_7CF230, selects a performance setting tier (0 when the counter is at or below 16, otherwise 2) into the field at this+0x310, formats the counter as a decimal string into a stack buffer using the %d format literal, then updates the UI edit buffer with that string.
    // CALCULATION: Read global framerate counter value into v1 [global:0x007CF230]
    // GUARD: When the framerate counter is at or below 16, write performance tier 0 into the field at this+0x310 [global:0x007CF230, field:this:0x00000310]
    // ASSIGNMENT: When the framerate counter exceeds 16, write performance tier 2 into the field at this+0x310 [global:0x007CF230, field:this:0x00000310]
    // CALL: Format the framerate counter into the stack buffer using the %d format literal via StringFormatWithBufferOverflowCheck [callee:0x0058815F, global:0x005C3280, global:0x007CF230]
    // CALL: Update the UI edit buffer with the formatted string via EditBufferStringUpdate [callee:0x0048B810]
    // RETURN: Return the result of EditBufferStringUpdate [callee:0x0048B810, function:0x0047C770]

    // Conservative worker pseudocode:
    //   v1 = dword_7CF230;
    //   this[0x310] = (v1 <= 16) ? 0 : 2;
    //   StringFormatWithBufferOverflowCheck(v3, aD_1, v1);
    //   return EditBufferStringUpdate(v3);
    // UNRESOLVED: Meaning of the performance tier values (0 and 2) and whether the field at this+0x310 is persisted by callers is not established.
}
