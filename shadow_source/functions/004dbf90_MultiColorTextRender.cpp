// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DBF90
// Canonical corpus name: MultiColorTextRender
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MultiColorTextRender_004dbf90.c

void UnknownObject::MultiColorTextRender()
{
    // Renders a race-information overlay by repeatedly filling a 64-byte local buffer with a format helper and drawing it with UITextRenderWithScale. The lap-count line is drawn in yellow (16776960) at x = a1 + 215, y = 46 with scale 0.75. Two text rows on the left (x = a1 + 15, y = 10 and y = 90) are each rendered twice: a white pass (0xFFFFFF) followed by a yellow overlay pass (16776960). Returns the result of the final UITextRenderWithScale call.
    // CALL: Call sub_49C670(v2, 64) to format lap-count text into the 64-byte local buffer. [callee:0x0049C670, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1 + 215, 46, 16776960, 2, 0, 0.75, 1.0) to render the yellow lap-count line at the right offset with 0.75 scale. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49BDE0(v2, 64) to format overlay color text field 1 into the buffer. [callee:0x0049BDE0, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1 + 15, 10, 0xFFFFFF, 1, 2, 1.0, 1.0) to render the white foreground pass of the first left text row. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49BE50(v2, 64) to format overlay color text field 2 into the buffer. [callee:0x0049BE50, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1 + 15, 10, 16776960, 0, 1, 1.0, 1.0) to render the yellow overlay pass of the first left text row. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49C700(v2, 64) to format secondary text field 1 into the buffer. [callee:0x0049C700, source:raw]
    // CALL: Call UITextRenderWithScale(v2, a1 + 15, 90, 0xFFFFFF, 1, 2, 1.0, 1.0) to render the white foreground pass of the second left text row. [callee:0x004D7E40, source:raw]
    // CALL: Call sub_49C770(v2, 64) to format secondary text field 2 into the buffer. [callee:0x0049C770, source:raw]
    // RETURN: Call UITextRenderWithScale(v2, a1 + 15, 90, 16776960, 0, 1, 1.0, 1.0) to render the yellow overlay pass of the second row and return its result. [callee:0x004D7E40, source:raw]

    // Conservative worker pseudocode:
    //   int MultiColorTextRender(int a1) {
    //     char buf[64];
    //     sub_49C670(buf, 64);  UITextRenderWithScale(buf, a1 + 215, 46, 16776960, 2, 0, 0.75, 1.0);
    //     sub_49BDE0(buf, 64);  UITextRenderWithScale(buf, a1 + 15, 10, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49BE50(buf, 64);  UITextRenderWithScale(buf, a1 + 15, 10, 16776960, 0, 1, 1.0, 1.0);
    //     sub_49C700(buf, 64);  UITextRenderWithScale(buf, a1 + 15, 90, 0xFFFFFF, 1, 2, 1.0, 1.0);
    //     sub_49C770(buf, 64);  return UITextRenderWithScale(buf, a1 + 15, 90, 16776960, 0, 1, 1.0, 1.0);
    //   }
    // UNRESOLVED: Global unk_7CE234 is declared in the packet globals but never referenced in the raw source text; it may be read transitively by the format helpers (existing analysis labels it DriverAppearanceFlag, DERIVED tier).
    // UNRESOLVED: Exact meaning of the two render-pass parameter tuples (alignment/style/alpha enums) for UITextRenderWithScale is not derivable from this function alone.
    // UNRESOLVED: Purpose of a1 base offset shared by all left-row x coordinates is not evident from raw source.
}
