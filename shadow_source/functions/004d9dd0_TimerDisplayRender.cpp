// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D9DD0
// Canonical corpus name: TimerDisplayRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerDisplayRender_004d9dd0.c

void UnknownObject::TimerDisplayRender()
{
    // Timer HUD render (__thiscall, returns the countdown status). Delegates countdown logic to TimerCountdown(this); while the countdown is active (TimerCountdown returns 0) it formats a single separator character into a local buffer via StringFormatWithBufferOverflowCheck, renders it twice with UITextRenderWithScale as a red left element at (924, 858) and a green right element at (1180, 858), then if BinarySearchInStringTable reports the default path string (byte_5EA438) is present in the search buffer it copies that string byte-by-byte into the display buffer byte_5EC4CC, copies it into the local buffer with sub_587DD0 (max 127), null-terminates, and renders the centered track/venue label in yellow at (1052, 858). Returns the TimerCountdown result (non-zero when the timer is no longer active).
    // CALL: v1 = TimerCountdown(this): delegate countdown handling and read its status. [callee:0x004D98A0, source:raw]
    // GUARD: When v1 is non-zero the timer is no longer active and the whole rendering block is skipped; return v1 early. [callee:0x004D98A0, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v5, aC, byte_5D4AE9): format the separator character byte_5D4AE9 with the format string at aC ("%c") into the local buffer v5. [callee:0x0058815F, global:0x005CCEF0, global:0x005D4AE9, source:raw]
    // CALL: UITextRenderWithScale(v5, 924, 858, 16711680, 0, 3, 1.0, 1.0): render the separator buffer as the red left element at screen position (924, 858). [callee:0x004D7E40, source:raw]
    // CALL: UITextRenderWithScale(v5, 1180, 858, 65280, 1, 3, 1.0, 1.0): render the separator buffer as the green right element at screen position (1180, 858). [callee:0x004D7E40, source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, byte_5EA438, byte_5EC4CC): test whether the default directory/path string byte_5EA438 is found relative to the search buffer byte_5EC4C0, using byte_5EC4CC as the working buffer. [callee:0x00423A00, global:0x005EC4C0, global:0x005EA438, global:0x005EC4CC, source:raw]
    // GUARD: Only when BinarySearchInStringTable returns true does the code copy the path string into the display buffer before rendering the center label. [callee:0x00423A00, source:raw]
    // LOOP: Character copy loop: starting at index 0, copy byte_5EA438[index] into byte_5EC4CC[index] and increment until the copied character is the null terminator. [global:0x005EA438, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v5, byte_5EC4CC, 127): copy the display buffer byte_5EC4CC into the local buffer v5 with a maximum length of 127. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: v6 = 0: write a null terminator for the local text buffer. [source:raw]
    // CALL: UITextRenderWithScale(v5, 1052, 858, 16776960, 2, 0, 1.0, 1.0): render the buffer as the yellow centered label at screen position (1052, 858). [callee:0x004D7E40, source:raw]
    // RETURN: Return v1, the TimerCountdown result (non-zero when the countdown timer is no longer active). [callee:0x004D98A0, function:0x004D9DD0, source:raw]

    // Conservative worker pseudocode:
    //   int TimerDisplayRender(this) {
    //     int status = TimerCountdown(this);
    //     if (status == 0) {
    //       StringFormatWithBufferOverflowCheck(v5, aC, byte_5D4AE9);
    //       UITextRenderWithScale(v5, 924, 858, 16711680, 0, 3, 1.0, 1.0);
    //       UITextRenderWithScale(v5, 1180, 858, 65280, 1, 3, 1.0, 1.0);
    //       if (BinarySearchInStringTable(byte_5EC4C0, byte_5EA438, byte_5EC4CC)) {
    //         for (i = 0; (byte_5EC4CC[i] = byte_5EA438[i]) != 0; ++i);
    //       }
    //       sub_587DD0(v5, byte_5EC4CC, 127);
    //       v6 = 0;
    //       UITextRenderWithScale(v5, 1052, 858, 16776960, 2, 0, 1.0, 1.0);
    //     }
    //     return status;
    //   }
    // UNRESOLVED: The rendering arguments (screen coordinates 924/1180/1052, 858 and the color literals 16711680/65280/16776960) are described only as HUD element placement; the alignment/index flags (0, 1, 2, 3) are not decoded.
    // UNRESOLVED: The relationship and purpose of byte_5EC4C0, byte_5EA438 and byte_5EC4CC (corpus names EmptyStringBuffer / default directory / MessageDisplayBuffer, DERIVED) rest on existing analysis naming, not on evidence in this packet.
    // UNRESOLVED: The semantics of BinarySearchInStringTable's return and why a matched string is re-copied byte-by-byte are inferred from the branch and copy loop.
    // UNRESOLVED: sub_587DD0's exact operation is taken from its corpus naming (string copy with a max length of 127), not proven here.
    // UNRESOLVED: v6 is written immediately before the last render call; its use as a null terminator is inferred.
}
