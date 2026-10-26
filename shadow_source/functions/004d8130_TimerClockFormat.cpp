// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D8130
// Canonical corpus name: TimerClockFormat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerClockFormat_004d8130.c

void UnknownObject::TimerClockFormat()
{
    // Builds a text string and renders it at a fixed screen position with a configurable alpha. The string is seeded by copying a null-terminated sequence from byte_5EA438, then appending dword_5D4A64 characters whose base code is selected by the a2 flag (byte_5D4A61 when a2 == 0, byte_5D4A60 otherwise). Each suffix character is formatted with StringFormatWithBufferOverflowCheck and appended with strcat. Finally the assembled string is rendered by UITextRenderWithScale at (640, 974) in white (0xFFFFFF), size 2, layer 3, scale 1.0, alpha a1. Alpha is clamped to 0.001 when a1 <= 0.0.
    // ASSIGNMENT: Select the base character for the suffix sequence: byte_5D4A61 when a2 == 0, byte_5D4A60 otherwise. [source:raw, global:0x005D4A60, global:0x005D4A61]
    // LOOP: Copy the null-terminated string from byte_5EA438 into the local text buffer, stopping when a zero byte is read. [source:raw, global:0x005EA438]
    // LOOP: When dword_5D4A64 > 0, append that many suffix characters: each is base char + offset v5, formatted via StringFormatWithBufferOverflowCheck into a scratch buffer and appended to the text buffer with strcat. [source:raw, global:0x005D4A64, callee:0x0058815F]
    // GUARD: Clamp alpha a1 to 0.001 when a1 <= 0.0 to avoid a zero-alpha render. [source:raw]
    // CALL: Render the assembled text with UITextRenderWithScale at position (640, 974), color 0xFFFFFF, size 2, layer 3, scale 1.0, alpha a1. [source:raw, callee:0x004D7E40]
    // RETURN: Return the UITextRenderWithScale result. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_4D8130(float alpha, char baseCharSel) {
    //     char buf[32] = { 0 };
    //     char ch;
    //     int i = 0;
    //     do { ch = byte_5EA438[i]; buf[i++] = ch; } while (ch);
    //     char base = baseCharSel ? byte_5D4A60 : byte_5D4A61;
    //     for (int n = 0; n < dword_5D4A64; ++n) {
    //       char tmp[8];
    //       StringFormatWithBufferOverflowCheck(tmp, "%c", base + n);
    //       strcat(buf, tmp);
    //     }
    //     if (alpha <= 0.0f) alpha = 0.001f;
    //     return UITextRenderWithScale(buf, 640, 974, 0xFFFFFF, 2, 3, 1.0f, alpha);
    //   }
    // UNRESOLVED: Globals flt_59E440 (0x0059E440) and aC (0x005CCEF0) are listed in the deterministic fact table but do not appear in the raw decompiled body; their role here cannot be confirmed from the packet.
    // UNRESOLVED: Meaning of the assembled string (clock/time text) and the suffix character sequence is caller-dependent; caller is PhaseBasedAudioParticleEnvelope (0x004D7FF0).
}
