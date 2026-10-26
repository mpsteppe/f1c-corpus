// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D700
// Canonical corpus name: sub_49D700
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_49D700_0049d700.c

void UnknownObject::SessionMultiLineHudRender()
{
    // Renders a four-row HUD display in dual columns. Initializes a dual-text element with DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8), then for each of four rows stacks the Y position by the dword_5CCBBC stride and renders a value line (format helper sub_49C310/sub_49C490/sub_49BCD0/sub_49C0B0, left column texture dword_5CCBC0, trailing flag 1) followed by a label line (format helper sub_49C370/sub_49C4E0/sub_49BD40, right column data dword_7CE238, trailing flag 0) through StringFormatAndRender, reading the surface pointer from this+0x8 and the display-context data value at (this+0x14)+84. The final row uses the literal 240 for the left-column argument and the function returns that call's result.
    // CALL: Initialize the dual-column HUD element with DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8). [callee:0x0049E410, global:0x005CCBC0, global:0x007CE238, global:0x005CCBB8]
    // CALCULATION: Compute the four row Y positions by stacking dword_5CCBBC (row stride) onto the base dword_5CCBB8: row1 = base + stride, row2 = row1 + stride, row3 = row2 + stride, row4 = row3 + stride. [global:0x005CCBBC, global:0x005CCBB8]
    // CALL: Row 1 value: format the text buffer with sub_49C310(buf, 64), then StringFormatAndRender(buf, dword_5CCBC0, row1Y, this+0x8, *(this+0x14 + 84), 1). [callee:0x0049C310, callee:0x0049F6A0, global:0x005CCBC0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 1 label: format the text buffer with sub_49C370(buf, 64), then StringFormatAndRender(buf, dword_7CE238, row1Y, this+0x8, *(this+0x14 + 84), 0). [callee:0x0049C370, callee:0x0049F6A0, global:0x007CE238, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 2 value: format the text buffer with sub_49C490(buf, 64), then StringFormatAndRender(buf, dword_5CCBC0, row2Y, this+0x8, *(this+0x14 + 84), 1). [callee:0x0049C490, callee:0x0049F6A0, global:0x005CCBC0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 2 label: format the text buffer with sub_49C4E0(buf, 64), then StringFormatAndRender(buf, dword_7CE238, row2Y, this+0x8, *(this+0x14 + 84), 0). [callee:0x0049C4E0, callee:0x0049F6A0, global:0x007CE238, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 3 value: format the text buffer with sub_49BCD0(buf, 64), then StringFormatAndRender(buf, dword_5CCBC0, row3Y, this+0x8, *(this+0x14 + 84), 1). [callee:0x0049BCD0, callee:0x0049F6A0, global:0x005CCBC0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 3 label: format the text buffer with sub_49BD40(buf, 64), then StringFormatAndRender(buf, dword_7CE238, row3Y, this+0x8, *(this+0x14 + 84), 0). [callee:0x0049BD40, callee:0x0049F6A0, global:0x007CE238, field:this:0x00000008, field:this:0x00000014]
    // CALL: Row 4 value: format the text buffer with sub_49C0B0(buf, 64), then StringFormatAndRender(buf, 240, row4Y, this+0x8, *(this+0x14 + 84), 1); the function's return value is that call's result. [callee:0x0049C0B0, callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // RETURN: Return the result of the final StringFormatAndRender call. [callee:0x0049F6A0]

    // Conservative worker pseudocode:
    //   DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
    //   y = dword_5CCBB8;
    //   y += dword_5CCBBC; sub_49C310(buf, 64); StringFormatAndRender(buf, dword_5CCBC0, y, this[2], *(this[5]+84), 1);
    //   sub_49C370(buf, 64); StringFormatAndRender(buf, dword_7CE238, y, this[2], *(this[5]+84), 0);
    //   y += dword_5CCBBC; sub_49C490(buf, 64); StringFormatAndRender(buf, dword_5CCBC0, y, this[2], *(this[5]+84), 1);
    //   sub_49C4E0(buf, 64); StringFormatAndRender(buf, dword_7CE238, y, this[2], *(this[5]+84), 0);
    //   y += dword_5CCBBC; sub_49BCD0(buf, 64); StringFormatAndRender(buf, dword_5CCBC0, y, this[2], *(this[5]+84), 1);
    //   sub_49BD40(buf, 64); StringFormatAndRender(buf, dword_7CE238, y, this[2], *(this[5]+84), 0);
    //   y += dword_5CCBBC; sub_49C0B0(buf, 64); return StringFormatAndRender(buf, 240, y, this[2], *(this[5]+84), 1);
    // UNRESOLVED: Field this+0x68 (read) does not appear in the raw decompiled body; possibly additional display-context data.
    // UNRESOLVED: Globals dword_7CE048 and unk_7CE234 are referenced in the IDB but do not appear in the raw decompiled body; their role here is unknown.
    // UNRESOLVED: The format-buffer helpers (sub_49C310 and siblings) and the exact meaning of the trailing format flag (0/1) and the literal 240 are not resolved from the packet.
    // UNRESOLVED: Single caller is sub_49D5D0 (0x0049D5D0); the caller-side invocation context is not analyzed here.
}
