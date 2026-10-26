// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0045BD10
// Canonical corpus name: TextLineWrappingAndRendering
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TextLineWrappingAndRendering_0045bd10.c

void UnknownObject::TextLineWrappingAndRendering()
{
    // Renders a text line with word wrap onto an output context. When the special color marker 16909060 is passed as the color parameter, maps it to a render color mask via IDToColorMaskMapper. While the remaining text is at least 80 characters, copies 79-character segments, cuts each at the last space boundary after position 40 (or at 79 when no space found), and renders the segment via UtilityFunction_b9c0. Finally renders the remaining text. Skips rendering when the width/size parameter exceeds the global bound dword_7D02E4. Part of the UI/text rendering subsystem.
    // GUARD: Return the default value (dword_7D02E4) without rendering when the width/size parameter a3 exceeds the global bound dword_7D02E4. [global:0x007D02E4, source:raw]
    // CALCULATION: When the color parameter a4 equals the special marker 16909060, map it to a render color mask via IDToColorMaskMapper(a3). [callee:0x0045BB60, source:raw]
    // LOOP: While the remaining text (a2 + offset) is at least 80 chars: copy a 79-char segment into the local buffer via sub_587DD0, null-terminate it, and scan backwards from position 78 to 40 for a space (0x20) break. [callee:0x00587DD0, source:raw]
    // CALCULATION: Choose the wrap point length: last space index + 1 when a space was found after position 40, otherwise the full 79-char segment. [source:raw]
    // CALL: Truncate the segment at the wrap point and render it via UtilityFunction_b9c0 with the output context (*this), color, fixed parameter 1084227584 and width parameter a3; advance the consumed text offset. [callee:0x0045B9C0, field:this:0x00000000, source:raw]
    // CALL: Render the remaining (final) text segment via UtilityFunction_b9c0 with the output context (*this). [callee:0x0045B9C0, field:this:0x00000000, source:raw]
    // RETURN: Return the result of the final segment render (or the default guard value when rendering was skipped). [function:0x0045BD10, source:raw]

    // Conservative worker pseudocode:
    //   if (a3 > dword_7D02E4) return dword_7D02E4;
    //   if (a4 == 16909060) a4 = IDToColorMaskMapper(a3);
    //   off = 0;
    //   while (strlen(a2 + off) >= 80) {
    //     sub_587DD0(buf, a2 + off, 79); buf[79] = 0;
    //     for (i = 78; i > 40; i--) if (buf[i] == ' ') break;
    //     n = (i == 40) ? 79 : i + 1;
    //     buf[n] = 0;
    //     off += n;
    //     UtilityFunction_b9c0(*this, buf, a4, 1084227584, a3);
    //   }
    //   return UtilityFunction_b9c0(*this, a2 + off, a4, 1084227584, a3);
    // UNRESOLVED: Global dword_59F07C is listed by the fact store but does not appear in the recovered source for this function; its role here is unconfirmed.
    // UNRESOLVED: Meaning of the fixed render parameter 1084227584 is unconfirmed.
    // UNRESOLVED: Exact meaning of the width/size parameter a3 and the bound dword_7D02E4 is unconfirmed.
}
