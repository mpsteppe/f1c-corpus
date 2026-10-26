// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB6F0
// Canonical corpus name: PositionOrderNameDisplay
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PositionOrderNameDisplay_004db6f0.c

void UnknownObject::PositionOrderNameDisplay()
{
    // Renders a position or gear indicator text at screen coordinates. For a1 == -1 resolves and copies the localized error string (byte_5CCEC4) into byte_5EC4CC and then into the display buffer; for a1 == 0 does the same with the localized neutral string aN; otherwise formats the numeric value a1 with "%d" into the display buffer. When sub_49B7A0(&unk_7CE234) & 0xF equals 0xF the text color becomes red (16711680) instead of the default yellow (16776960), and UITextRenderWithScale draws the buffer with scale and alignment parameters.
    // ASSIGNMENT: Default render color v3 set to yellow 16776960. [source:raw]
    // GUARD: Branch on a1 == -1 for the error/invalid position display. [source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC) resolves the localized error string. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCEC4, source:raw]
    // LOOP: Copy the byte_5CCEC4 error string into byte_5EC4CC one byte at a time until the NUL terminator. [global:0x005CCEC4, global:0x005EC4CC, source:raw]
    // CALL: sub_587DD0(v9, byte_5EC4CC, 9) safe-copies the resolved string into the 9-byte display buffer v9. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // GUARD: Branch on a1 == 0 for the neutral position display. [source:raw]
    // CALL: BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC) resolves the localized neutral "N" string. [callee:0x00423A00, global:0x005EC4C0, global:0x005C36FC, source:raw]
    // LOOP: Copy the aN string into byte_5EC4CC one byte at a time until the NUL terminator. [global:0x005C36FC, global:0x005EC4CC, source:raw]
    // CALL: StringFormatWithBufferOverflowCheck(v9, "%d", a1) formats the positive numeric value into the display buffer. [callee:0x0058815F, source:raw]
    // GUARD: Check the flag from sub_49B7A0(&unk_7CE234): when masked with 0xF it equals 0xF, select the failure color. [callee:0x0049B7A0, global:0x007CE234, source:raw]
    // ASSIGNMENT: Set render color v3 to red 16711680 when the appearance flag matches. [source:raw]
    // RETURN: UITextRenderWithScale(v9, a2, a3, v3, 2, 0, 1.25, 1.5) renders the text buffer at the given coordinates with color, alignment and scale. [callee:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   int PositionOrderNameDisplay(int value, int x, int y) {
    //     char buf[9]; char extra;
    //     int color = 16776960;
    //     if (value == -1) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, byte_5CCEC4, byte_5EC4CC)) {
    //         int i = 0; do { byte_5EC4CC[i] = byte_5CCEC4[i]; } while (byte_5CCEC4[i++]);
    //       }
    //       sub_587DD0(buf, byte_5EC4CC, 9); extra = 0;
    //     } else if (value == 0) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aN, byte_5EC4CC)) {
    //         int i = 0; do { byte_5EC4CC[i] = aN[i]; } while (aN[i++]);
    //       }
    //       sub_587DD0(buf, byte_5EC4CC, 9); extra = 0;
    //     } else {
    //       StringFormatWithBufferOverflowCheck(buf, "%d", value);
    //     }
    //     if ((sub_49B7A0(&unk_7CE234) & 0xF) == 0xF) color = 16711680;
    //     return UITextRenderWithScale(buf, x, y, color, 2, 0, 1.25, 1.5);
    //   }
    // UNRESOLVED: The exact role of global aD_1 in this function is not shown by the raw source.
    // UNRESOLVED: The meaning of the sub_49B7A0 flag mask 0xF and which appearance state it indicates is derived, not confirmed.
    // UNRESOLVED: The semantics of the alignment (2) and anchor (0) parameters of UITextRenderWithScale are not explained here.
}
