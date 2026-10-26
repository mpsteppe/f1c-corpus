// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0049D8B0
// Canonical corpus name: UtilityFunction_d8b0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_d8b0_0049d8b0.c

void UnknownObject::DualDisplayFormattedLineRenderer()
{
    // Text-display helper: renders the base dual text via DualTextDisplay, then, when field this+0x8 is nonzero, emits a sequence of formatted lines at stepped offsets. Each line is prepared by a per-line buffer helper and rendered with StringFormatAndRender into the first-region display state v1 (flag 1) and second-region display state v2 (flag 0), using this[2] and the string data at this[5]+84 as content. The final line renders with literal 240 instead of a display-state value.
    // ASSIGNMENT: Capture display parameters: v1 = dword_5CCBC0, v2 = dword_7CE238, v3 = dword_5CCBB8. [global:0x005CCBC0, global:0x007CE238, global:0x005CCBB8]
    // CALL: Render the base dual-text display with DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8). [callee:0x0049E410, global:0x005CCBC0, global:0x007CE238, global:0x005CCBB8]
    // GUARD: Read this[2] (field this+0x8); when zero the formatted-line block is skipped and that value is returned. [field:this:0x00000008]
    // CALCULATION: Compute line offset v6 = dword_5CCBBC + v3. [global:0x005CCBBC, global:0x005CCBB8]
    // CALL: Prepare the text buffer with sub_49C140(v10, 64). [callee:0x0049C140]
    // CALL: Render StringFormatAndRender(v10, v1, v6, this[2], *(this[5]+84), 1) with first-region display state v1. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Prepare the text buffer with sub_49C280(v10, 64). [callee:0x0049C280]
    // CALL: Render StringFormatAndRender(v10, v2, v6, this[2], *(this[5]+84), 0) with second-region display state v2. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Advance line offset v7 = dword_5CCBBC + v6. [global:0x005CCBBC]
    // CALL: Prepare the text buffer with sub_49BDE0(v10, 64). [callee:0x0049BDE0]
    // CALL: Render first-region line StringFormatAndRender(v10, v1, v7, this[2], *(this[5]+84), 1). [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Prepare the text buffer with sub_49BE50(v10, 64). [callee:0x0049BE50]
    // CALL: Render second-region line StringFormatAndRender(v10, v2, v7, this[2], *(this[5]+84), 0). [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Advance line offset v8 = dword_5CCBBC + v7. [global:0x005CCBBC]
    // CALL: Prepare the text buffer with sub_49BF80(v10, 64). [callee:0x0049BF80]
    // CALL: Render first-region line StringFormatAndRender(v10, v1, v8, this[2], *(this[5]+84), 1). [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALL: Prepare the text buffer with sub_49BFF0(v10, 64). [callee:0x0049BFF0]
    // CALL: Render second-region line StringFormatAndRender(v10, v2, v8, this[2], *(this[5]+84), 0). [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // CALCULATION: Advance line offset v9 = dword_5CCBBC + v8. [global:0x005CCBBC]
    // CALL: Prepare the text buffer with sub_49C0B0(v10, 64). [callee:0x0049C0B0]
    // CALL: Final render StringFormatAndRender(v10, 240, v9, this[2], *(this[5]+84), 1); the literal 240 replaces the display-state value. [callee:0x0049F6A0, field:this:0x00000008, field:this:0x00000014]
    // RETURN: Return the final render result, or this[2] when the formatted-line block was skipped. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_49D8B0(void *this) {
    //     int v1 = dword_5CCBC0, v2 = dword_7CE238, v3 = dword_5CCBB8;
    //     DualTextDisplay(dword_5CCBC0, dword_7CE238, dword_5CCBB8);
    //     int result = this[2];
    //     if (result) {
    //       int y = dword_5CCBBC + v3;
    //       sub_49C140(buf,64); StringFormatAndRender(buf, v1, y, this[2], *(this[5]+84), 1);
    //       sub_49C280(buf,64); StringFormatAndRender(buf, v2, y, this[2], *(this[5]+84), 0);
    //       y += dword_5CCBBC;
    //       sub_49BDE0(buf,64); StringFormatAndRender(buf, v1, y, this[2], *(this[5]+84), 1);
    //       sub_49BE50(buf,64); StringFormatAndRender(buf, v2, y, this[2], *(this[5]+84), 0);
    //       y += dword_5CCBBC;
    //       sub_49BF80(buf,64); StringFormatAndRender(buf, v1, y, this[2], *(this[5]+84), 1);
    //       sub_49BFF0(buf,64); StringFormatAndRender(buf, v2, y, this[2], *(this[5]+84), 0);
    //       y += dword_5CCBBC;
    //       sub_49C0B0(buf,64);
    //       return StringFormatAndRender(buf, 240, y, this[2], *(this[5]+84), 1);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the per-line buffer helpers sub_49C140, sub_49C280, sub_49BDE0, sub_49BE50, sub_49BF80, sub_49BFF0, sub_49C0B0 (attribute/format setup) is not confirmed.
    // UNRESOLVED: The final render call uses literal 240 in place of a display-state value; purpose unknown.
    // UNRESOLVED: Fields and globals present in the deterministic facts but absent from the Hex-Rays text (this+0x68, dword_7CE048, unk_7CE234) have an unknown role.
    // UNRESOLVED: Called from sub_49D5D0; the driving UI context is unknown.
}
