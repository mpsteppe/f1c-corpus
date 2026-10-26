// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DA9E0
// Canonical corpus name: sub_4DA9E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DA9E0_004da9e0.c

void UnknownObject::RenderLapTimePositionText()
{
    // HUD text renderer. In a single-lap session (total laps read from a3+16480 == 1) it looks up the localized LAPS string and formats "<lap> <LAPS>". Otherwise it computes the remaining session time as the difference between a session total and a per-this value, decomposes the positive remainder into minutes and fractional seconds, and formats either "%.3f" or "%d:%06.3f". It then formats a position-suffix character from byte_5D4AE8 plus lap index, and renders the suffix and the lap/time text at successive positions with UITextRenderWithScale, storing both texts back into session/buffer slots.
    // ASSIGNMENT: Initialize both working buffers: copy byte_5EA438[0] into SrcStr[0] and v19[0], zero the remainder of SrcStr (126 bytes) and v19 (0x7C bytes), and zero scalars v18, v20, v21. [global:0x005EA438, source:raw]
    // CALL: Call SizeOffsetTableByMode(a2, &v14, &v16, &v13) to obtain HUD text positions and offsets for the given mode a2. [callee:0x004DAC30]
    // CALCULATION: Read total lap count v4 from (a3 + 16480) and compute v5 = v4 - 1. [source:raw]
    // GUARD: If v4 == 1 (single-lap session), take the lap-count text path; otherwise the elapsed-time path. [source:raw]
    // CALL: Call BinarySearchInStringTable(byte_5EC4C0, aLaps_0, byte_5EC4CC) to find the localized LAPS entry using string tables aLaps_0 and byte_5EC4C0, writing the result into byte_5EC4CC. [callee:0x00423A00, global:0x005EC4C0, global:0x005CCE6C, global:0x005EC4CC]
    // LOOP: When the string table lookup succeeds, copy the aLaps_0 string into byte_5EC4CC byte-by-byte until the terminating NUL. [global:0x005CCE6C, global:0x005EC4CC, source:raw]
    // CALL: Format lap text into v19: StringFormatWithBufferOverflowCheck(v19, "%d %s", this[9], byte_5EC4CC), where this[9] is the lap count at this+0x24 and byte_5EC4CC holds the LAPS string. [callee:0x0058815F, field:this:0x00000024, global:0x005EC4CC, source:raw]
    // CALL: Else path: v12 = ArithmeticComparison_ad50(this) obtains a per-this time value stored through a float view of v12. [callee:0x004DAD50, source:raw]
    // CALL: v8 = SingleFunctionCallWrapper_ad30(a3) obtains a session total time from a3. [callee:0x004DAD30, source:raw]
    // GUARD: If v8 > 0.0, compute the time remainder; otherwise skip time formatting. [source:raw]
    // CALCULATION: v9 = v8 - v12 and store the result back into v12 (remaining time). [source:raw]
    // GUARD: If v9 > 0.0, decompose and format the remaining time. [source:raw]
    // CALL: Call SpatialGridCell(v12, &v15, &v12) to split the float seconds into minutes (v15) and the fractional-seconds remainder kept in v12. [callee:0x0049B630, source:raw]
    // GUARD: Select format based on v15: "%.3f" when v15 <= 0, else "%d:%06.3f" with v15 as minutes. [source:raw]
    // CALL: Format the time text into v19 via StringFormatWithBufferOverflowCheck using "%.3f" or "%d:%06.3f" and the computed values. [callee:0x0058815F, source:raw]
    // CALL: Format position-suffix character into SrcStr: StringFormatWithBufferOverflowCheck(SrcStr, "%c", v5 + byte_5D4AE8), indexing a suffix table by lap index v5. [callee:0x0058815F, global:0x005D4AE8, source:raw]
    // CALL: Render the suffix text: UITextRenderWithScale(SrcStr, v14, v13, 0xFFFFFF, 0, 3, 1.0, 1.0). [callee:0x004D7E40]
    // CALL: Copy the rendered suffix into the session slot at (a3 + 18168): sub_587DD0(SrcStr, a3 + 18168, 127). [callee:0x00587DD0, source:raw]
    // CALL: Call sub_589901(SrcStr) on the suffix text; purpose of this helper is not established from the packet. [callee:0x00589901]
    // CALCULATION: Advance the x position: v14 += 40. [source:raw]
    // CALL: Render the lap/time text: UITextRenderWithScale(SrcStr, v14, v13, 0xFFFFFF, 0, 0, 1.0, 1.0). [callee:0x004D7E40]
    // CALL: Copy the lap/time text into v19: sub_587DD0(SrcStr, v19, 127). [callee:0x00587DD0]
    // RETURN: Return UITextRenderWithScale(SrcStr, v16, v13, 16776960, 1, 0, 1.0, 1.0), a final render using the alternate x position v16 and color literal 16776960. [callee:0x004D7E40, function:0x004DA9E0, source:raw]

    // Conservative worker pseudocode:
    //   init_buffers(SrcStr, v19);
    //   SizeOffsetTableByMode(a2, &v14, &v16, &v13);
    //   totalLaps = *(int*)(a3 + 16480);
    //   if (totalLaps == 1) {
    //       if (BinarySearchInStringTable(byte_5EC4C0, aLaps_0, byte_5EC4CC)) copy(aLaps_0, byte_5EC4CC);
    //       format(v19, "%d %s", this[9], byte_5EC4CC);
    //   } else {
    //       v12 = ArithmeticComparison_ad50(this);
    //       v8 = SingleFunctionCallWrapper_ad30(a3);
    //       if (v8 > 0.0) {
    //           v12 = v8 - v12;
    //           if (v12 > 0.0) {
    //               SpatialGridCell(v12, &v15, &v12);
    //               format(v19, v15 <= 0 ? "%.3f" : "%d:%06.3f", v15, v12);
    //           }
    //       }
    //   }
    //   format(SrcStr, "%c", (totalLaps - 1) + byte_5D4AE8);
    //   UITextRenderWithScale(SrcStr, v14, v13, 0xFFFFFF, 0, 3, 1.0, 1.0);
    //   sub_587DD0(SrcStr, a3 + 18168, 127);
    //   sub_589901(SrcStr);
    //   v14 += 40;
    //   UITextRenderWithScale(SrcStr, v14, v13, 0xFFFFFF, 0, 0, 1.0, 1.0);
    //   sub_587DD0(SrcStr, v19, 127);
    //   return UITextRenderWithScale(SrcStr, v16, v13, 16776960, 1, 0, 1.0, 1.0);
    // UNRESOLVED: Raw offsets a3 + 16480 (total laps) and a3 + 18168 (suffix storage slot) are read/written directly; no named field evidence exists in the packet for them.
    // UNRESOLVED: Semantics of sub_587DD0 (string copy into slot) and sub_589901 (call with SrcStr) are not established.
    // UNRESOLVED: Role of field this+0x24 beyond the lap-count integer used in the "%d %s" format is unknown.
    // UNRESOLVED: Six globals appear in the packet fact list but have no visible use in the raw decompiled text (possibly from skeleton facts or dead/disassembled code paths).
    // UNRESOLVED: Difference in color literals between renders (0xFFFFFF vs 16776960) and their intent is unconfirmed.
}
