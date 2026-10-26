// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D98A0
// Canonical corpus name: TimerCountdown
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerCountdown_004d98a0.c

void UnknownObject::TimerCountdown()
{
    // Countdown phase handler. Decrements the countdown timer at this+0x10 by the delta-time constant dbl_8AFE98 on every call and returns 1 once the timer drops below 0. While the current-player pointer dword_7C54E0 is non-null, renders the player's grid position character (from byte_5D4AE8 base), driver name string (dword_7C54E0+18168) and team/car name string (dword_7C54E0+18104) at fixed HUD positions, sanitizing each with sub_589901 before drawing.
    // GUARD: When the countdown timer this+0x10 is negative, treat the countdown as expired and return 1 without rendering. [field:this:0x00000010, source:raw]
    // ASSIGNMENT: Decrement the countdown timer this+0x10 by the delta-time constant dbl_8AFE98. [field:this:0x00000010, global:0x008AFE98, source:raw]
    // GUARD: The HUD rendering block runs only while the current-player vehicle pointer dword_7C54E0 is non-null. [global:0x007C54E0, source:raw]
    // CALCULATION: Compute the player's grid index as *(dword_7C54E0 + 16480) - 1 and only draw the position character when that index is at most 0x18. [global:0x007C54E0, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck builds the single position character from the base byte_5D4AE8 plus the computed index. [callee:0x0058815F, global:0x005D4AE8, source:raw]
    // CALL: UITextRenderWithScale draws the position character at HUD position (100, 818) with scale 3.0. [callee:0x004D7E40, source:raw]
    // LOOP: Copy the driver name string from dword_7C54E0+18168 into the SrcStr buffer. [global:0x007C54E0, source:raw]
    // CALL: sub_589901 sanitizes the driver name buffer before it is rendered. [callee:0x00589901, source:raw]
    // CALL: UITextRenderWithScale draws the driver name at HUD position (210, 818) with scale 1.0. [callee:0x004D7E40, source:raw]
    // LOOP: Copy the team/car name string from dword_7C54E0+18104 into the SrcStr buffer. [global:0x007C54E0, source:raw]
    // CALL: sub_589901 sanitizes the team/car name buffer before it is rendered. [callee:0x00589901, source:raw]
    // CALL: UITextRenderWithScale draws the team/car name at HUD position (210, 858) with color 0xFFFFFF and scale 1.0. [callee:0x004D7E40, source:raw]
    // RETURN: Return 0 to signal the countdown is still active; invoked by TimerDisplayRender (004D9DD0). [caller:0x004D9DD0, function:0x004D98A0, source:raw]

    // Conservative worker pseudocode:
    //   int TimerCountdown() {
    //     if (this[4] < 0.0) return 1;
    //     this[4] -= dbl_8AFE98;
    //     if (dword_7C54E0) {
    //       v3 = *(dword_7C54E0 + 16480) - 1;
    //       if (v3 <= 0x18) {
    //         StringFormatWithBufferOverflowCheck(SrcStr, "%c", v3 + byte_5D4AE8);
    //         UITextRenderWithScale(SrcStr, 100, 818, 0xFFFFFF, 0, 3, 3.0, 3.0);
    //       }
    //       copyString(dword_7C54E0 + 18168, SrcStr);
    //       sub_589901(SrcStr);
    //       UITextRenderWithScale(SrcStr, 210, 818, 0xFFFFFF, 0, 0, 1.0, 1.0);
    //       copyString(dword_7C54E0 + 18104, SrcStr);
    //       sub_589901(SrcStr);
    //       UITextRenderWithScale(SrcStr, 210, 858, 4762291, 0, 0, 1.0, 1.0);
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: flt_59E440, flt_5ACF60 and aC appear in the packet globals but are absent from the raw decompiled source text; their role here is unresolved.
    // UNRESOLVED: The owning class behind the countdown object (this+0x10) is unknown.
    // UNRESOLVED: The meanings of the two strings at dword_7C54E0+18168 and +18104 are inferred as driver name and team/car name from their rendering positions, not proven.
}
