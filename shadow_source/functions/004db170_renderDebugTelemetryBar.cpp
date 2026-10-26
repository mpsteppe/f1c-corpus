// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DB170
// Canonical corpus name: SteeringAckermannComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringAckermannComputation_004db170.c

void UnknownObject::renderDebugTelemetryBar()
{
    // Gated debug HUD renderer: draws a path/name label string and a 41-segment color-coded bar indicator (white vs red on a threshold). Gated by the flt_5EA4E8 telemetry-enable flag; bar block additionally requires the packed flag at dword_8AB6EC and flt_5EA4E8 == 1.0. The ABI lead 'Steering_Ackermann_Computation' (LEGACY) does not match the body, which performs no steering-geometry math.
    // GUARD: Early-exit guard: if flt_5EA4E8 is not positive (<= 0.0), skip the whole overlay and return 1. [global:0x005EA4E8, source:raw]
    // CALL: Call ShortComputation_8490 with the address of flt_5EA4E8; the returned double feeds the text positions. [callee:0x00408490, global:0x005EA4E8, source:raw]
    // CALL: Convert the computed double to int via CRTFtol for the label vertical offset (v9). [callee:0x00587BDC, source:raw]
    // CALL: Convert the computed double to int via CRTFtol a second time for the bar row offset (v4). [callee:0x00587BDC, source:raw]
    // ASSIGNMENT: Initialize horizontal cursor v3 to 128. [source:raw]
    // ASSIGNMENT: Load display-name pointer v5 from this[4] (byte offset 0x10); fall back to the default path string byte_5EA438 when null. [field:this:0x00000010, global:0x005EA438, source:raw]
    // GUARD: If the display-name string v5 differs from the default path string byte_5EA438 (strcmp nonzero), draw the label. [global:0x005EA438, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Reload the display-name pointer v6 from this[4] (byte offset 0x10); fall back to byte_5EA438 when null. [field:this:0x00000010, global:0x005EA438, source:raw]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, v6, byte_5EC4CC) to test whether the name v6 is present in the string table. [callee:0x00423A00, global:0x005EC4C0, global:0x005EC4CC, field:this:0x00000010, source:raw]
    // ASSIGNMENT: On a table hit, copy the name v6 into byte_5EC4CC via strcpy, or clear byte_5EC4CC to an empty string when v6 is null. [global:0x005EC4CC, field:this:0x00000010, source:raw]
    // CALL: Call sub_587DD0 to copy up to 127 bytes (0x7F) of byte_5EC4CC into the local 127-byte display buffer v12. [callee:0x00587DD0, global:0x005EC4CC, source:raw]
    // ASSIGNMENT: Null-terminate the 128-byte stack region by clearing the local byte v13 that follows the 127-byte buffer v12. [source:raw]
    // CALL: Render the label buffer with UITextRenderWithScale at x=100, y=v9, white color 0xFFFFFF, scale 1.0 x 1.0. [callee:0x004D7E40, source:raw]
    // GUARD: Bar-block guard: proceed only if PackedFlagRead_9a00(&dword_8AB6EC) is set and flt_5EA4E8 equals 1.0. [callee:0x004B9A00, global:0x008AB6EC, global:0x005EA4E8, source:raw]
    // CALL: Call sub_4B9A10 on dword_8AB6EC to obtain the threshold value v11 that selects the bar segment color. [callee:0x004B9A10, global:0x008AB6EC, source:raw]
    // CALL: Format a single character taken from byte_5D4AEC into v12 via StringFormatWithBufferOverflowCheck using the '%c' format string. [callee:0x0058815F, global:0x005D4AEC, source:raw]
    // LOOP: Loop over 41 bar segments (segment index v7 from 0 to 40), advancing horizontal cursor v3 by 25 per segment; v10 tracks the segment index as a double-scaled value. [source:raw]
    // CALL: Render each segment with UITextRenderWithScale at (v3, v4), white 0xFFFFFF when v10 * 0.025 exceeds v11, else red 16711680, scale 1.0 x 1.0. [callee:0x004D7E40, source:raw]
    // RETURN: Return 1 on the early-exit path when the telemetry flag flt_5EA4E8 is not positive. [global:0x005EA4E8, source:raw]
    // RETURN: Return 0 after the label and bar overlay have been rendered. [source:raw]

    // Conservative worker pseudocode:
    //   if (flt_5EA4E8 <= 0.0) return 1;
    //   value = ShortComputation_8490(&flt_5EA4E8);
    //   labelY = barRowY = CRTFtol(value);
    //   barCursorX = 128;
    //   name = this[4] ? (const char*)this[4] : byte_5EA438;
    //   if (strcmp(name, byte_5EA438) != 0) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, name, byte_5EC4CC)) {
    //           name ? strcpy(byte_5EC4CC, name) : (byte_5EC4CC[0] = 0);
    //       }
    //       sub_587DD0(buffer, byte_5EC4CC, 0x7F); buffer[127] = 0;
    //       UITextRenderWithScale(buffer, 100, labelY, 0xFFFFFF, 0, 0, 1.0, 1.0);
    //   }
    //   if (PackedFlagRead_9a00(&dword_8AB6EC) && flt_5EA4E8 == 1.0) {
    //       threshold = sub_4B9A10(&dword_8AB6EC);
    //       StringFormatWithBufferOverflowCheck(buffer, "%c", byte_5D4AEC);
    //       for (i = 0; i <= 40; ++i) {
    //           color = (i * 0.025 > threshold) ? 0xFFFFFF : 16711680;
    //           UITextRenderWithScale(buffer, barCursorX, barRowY, color, 0, 3, 1.0, 1.0);
    //           barCursorX += 25;
    //       }
    //   }
    //   return 0;
    // UNRESOLVED: The packet lists seven read globals (0x0059E43C, 0x0059E440, 0x0059E828, 0x0059E87C, 0x0059E8A0, 0x005ACEE4, 0x005CCEF0) that do not appear in the raw source text; no operation could be grounded on them.
    // UNRESOLVED: strcmp and strcpy in the label branch are compiler-inlined CRT helpers with no callee entries in the packet, so they have no dedicated callee evidence refs.
    // UNRESOLVED: The exact semantics of the threshold produced by sub_4B9A10 and the 0.025 scale applied to the segment index are not established from the packet alone.
    // UNRESOLVED: The '%c' character source byte_5D4AEC and the display-name field this[4] (byte offset 0x10) have no type/role evidence beyond the raw reads.
    // UNRESOLVED: The ABI lead 'Steering_Ackermann_Computation' does not match the rendered body; no steering-geometry operation is present.
}
