// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004896C0
// Canonical corpus name: UITextInputHandler
// Owner: UITextInputHandler [DERIVED]
// Raw source: functions/UITextInputHandler_004896c0.c

void UITextInputHandler::UITextInputHandler()
{
    // Word-wraps an input text string to fit the available width of a UI text control, creating one UI menu item per wrapped line via UIMenuItemCreator and optionally naming each item via UIItemNameSetter. The caller (SessionStateDispatch at 0x004A0DF0) supplies the raw text and an optional item name. Returns -1 on null input, 0 on success.
    // GUARD: Reject null input: if input string a2 is NULL, return -1 immediately. [function:0x004896C0, source:raw]
    // CALL: If this[0xC8] (this+0xC8) is non-null, load the text-resource path from *(this+0xC8)+0x40, falling back to global byte_5EA438 when that path pointer is null, and call sub_498560(path). [field:this:0x000000C8, global:0x005EA438, callee:0x00498560, source:raw]
    // CALL: Copy the input string a2 into the 700-byte local buffer v24 via sub_587DD0 (bounded/safe copy with 700 limit); force null-termination at v24[699]. [callee:0x00587DD0, source:raw]
    // CALCULATION: Compute available text width v10 = (virtual method at this->vtable+24)(this) - this[0x140] - (this[0xC] + this[0x140]). Reads the vtable pointer (this+0x0) and the layout margins at this+0xC and this+0x140. [field:this:0x00000000, field:this:0x0000000C, field:this:0x00000140, source:raw]
    // CALL: TextRenderToSurface(v24, &v18, v20, 1): render/measure the full input copy; v18 receives the measured width, v20 receives per-character render info. [callee:0x004983B0, source:raw]
    // LOOP: While measured width v18 exceeds available width v10: take the next chunk (up to 79 chars) of remaining text v19 into the line buffer v21 via sub_587DD0 and measure it with TextRenderToSurface. [callee:0x00587DD0, callee:0x004983B0, source:raw]
    // CALCULATION: If the candidate line still overflows, trim it at a word boundary: inspect per-char bytes v20[v11+3], stop at a space (0x20) when word-break is enabled, null-terminate the break point, and recompute strlen until the line fits. [callee:0x004983B0, source:raw]
    // CALL: UIMenuItemCreator(this, v21, 0, 0, 0, 0): create one UI menu item per wrapped line. [callee:0x00489600, source:raw]
    // CALL: When a3 is non-null, UIItemNameSetter(this[0x94]-1, a3) sets the name of the item just created, indexing through this+0x94. [callee:0x00489C10, field:this:0x00000094, source:raw]
    // CALCULATION: Advance the remaining-text pointer v19 past the consumed line and skip any trailing space characters. [source:raw]
    // CALL: After the wrap loop, if v19 still points at non-empty text, create a final menu item for the remainder and set its name when a3 is non-null. [callee:0x00489600, callee:0x00489C10, field:this:0x00000094, source:raw]
    // CALL: sub_489D00(this): finalize/reset the text input handler state. [callee:0x00489D00, source:raw]
    // CALL: Dispatch the virtual method at this->vtable+44 with (this, 1) to signal completion to the owning control. [field:this:0x00000000, source:raw]
    // RETURN: Return 0 on success. [function:0x004896C0, source:raw]

    // Conservative worker pseudocode:
    //   if (input_text == null) return -1;
    //   if (this->m_resource != null) loadTextResource(*(this->m_resource + 0x40) or defaultPath);
    //   copy(input_text, input_copy, 700);
    //   avail = getWidth(this) - this->m_rightMargin - (this->m_leftMargin + this->m_rightMargin);
    //   while (measure(input_copy).width > avail) {
    //     copy next chunk into line_buffer(79);
    //     while (line overflows) trim at word boundary until it fits;
    //     createMenuItem(line_buffer);
    //     if (item_name != null) setName(this->m_itemCount - 1, item_name);
    //     advance past line and skip spaces;
    //   }
    //   if (remaining text non-empty) createMenuItem(remaining) and name it;
    //   finalizeTextState(this);
    //   signalComplete(this, 1);
    //   return 0;
    // UNRESOLVED: obj+0x18 and obj+0x2C are read fields, but no access through a distinct `obj` pointer appears in the readable decompilation; they may belong to the object queried by the virtual method at vtable+24.
    // UNRESOLVED: this+0x108 is read, but its use is not visible in the readable decompilation.
    // UNRESOLVED: Exact meaning of the integer argument (1) to the vtable+44 virtual call is unconfirmed.
    // UNRESOLVED: Whether sub_489D00 merely resets state or also releases resources is unconfirmed.
}
