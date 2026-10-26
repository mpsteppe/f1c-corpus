// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DC0B0
// Canonical corpus name: UIDebugOverlayRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UIDebugOverlayRender_004dc0b0.c

void UnknownObject::UIDebugOverlayRender()
{
    // Renders a debug overlay by filling a 64-byte local buffer with SeasonNameLookup, then drawing it with UITextRenderWithScale in white (0xFFFFFF) passes at x = a1, y = 10. The lap-count line (sub_49C670) is drawn at the same position, followed by DoubleRenderPass(a1, 50) for the mid overlay row, then two more format/render pairs at y = 90 (sub_49C700 and sub_49C770). Returns the result of the final UITextRenderWithScale call. Structural twin of MultiColorTextRender (004dbf90) per cluster prelabel.
    // CALL: Call SeasonNameLookup(v2, 64) to fill the local 64-byte buffer with the season name. [callee:0x0049C600, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1, 10, 0xFFFFFF, 1, 2, 1.0, 1.0) to render the season-name text in white at x = a1, y = 10. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49C670(v2, 64) to format lap-count text into the buffer. [callee:0x0049C670, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1, 10, 0xFFFFFF, 0, 1, 1.0, 1.0) to render a second white pass of the lap-count row at the same position. [callee:0x004D7E40, source:raw]
    // CALL: Call DoubleRenderPass(a1, 50) to render the paired mid overlay text at x = a1, y = 50. [callee:0x004DC1A0, source:raw]
    // CALL: Call sub_49C700(v2, 64) to format secondary text field 1 into the buffer. [callee:0x0049C700, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1, 90, 0xFFFFFF, 1, 2, 1.0, 1.0) to render secondary text field 1 in white at y = 90. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49C770(v2, 64) to format secondary text field 2 into the buffer. [callee:0x0049C770, source:raw]
    // RETURN: Call UITextRenderWithScale(v2, a1, 90, 0xFFFFFF, 0, 1, 1.0, 1.0) to render the second white pass of secondary text field 2 and return its result. [callee:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   int UIDebugOverlayRender(int a1) {
    //     int buf[16];
    //     SeasonNameLookup(buf, 64);  UITextRenderWithScale(buf, a1, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49C670(buf, 64);        UITextRenderWithScale(buf, a1, 10, 0xFFFFFF, 0, 1, 1.0, 1.0);
    //     DoubleRenderPass(a1, 50);
    //     sub_49C700(buf, 64);        UITextRenderWithScale(buf, a1, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49C770(buf, 64);        return UITextRenderWithScale(buf, a1, 90, 0xFFFFFF, 0, 1, 1.0, 1.0);
    //   }
    // UNRESOLVED: Global unk_7CE234 is declared in the packet globals but never referenced in the raw source text; it may be read transitively by the format/render helpers.
    // UNRESOLVED: Structural twin of 004dbf90 (prelabel cluster_copy, DERIVED); unlike the twin this function renders only white 0xFFFFFF passes and delegates color pairing to DoubleRenderPass, whose internal semantics are not visible here.
    // UNRESOLVED: Exact meaning of the UITextRenderWithScale parameter tuples (alignment/style/alpha enums) is not derivable from this function alone.
}
