// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048B600
// Canonical corpus name: UIEventShortcutHandler
// Owner: UIEventShortcutHandler [DERIVED]
// Raw source: functions/UIEventShortcutHandler_0048b600.c

void UIEventShortcutHandler::UIEventShortcutHandler()
{
    // Keyboard/event handler for a text edit field: gated by a master enable flag, it walks an array of u16 event codes, translates and filters characters, inserts them at a cursor position with a width/overflow re-check, handles backspace, and on the enter/accept code activates the value via vtable dispatch after refreshing the rendered text.
    // GUARD: If the master enable byte at this+0x2EC is zero, return 0 (handler inactive). [field:this:0x000002EC, source:raw]
    // LOOP: Iterate a3 u16 event codes starting at a2 + 2*index; each code selects a branch (loop exits on codes 1 or 28, backspace on 14, otherwise character input). [source:raw]
    // STATE_TRANSITION: Backspace (code 14): if the cursor pointer at this+0x2F4 differs from the buffer start at this+0x2F0, step the cursor back one byte; write a null terminator at the cursor, touching the byte at *(this+0x2F4)+0 and the following terminator byte at *(this+0x2F4)+1. [field:this:0x000002F4, field:this:0x000002F0, field:*(this+0x2F4):0x00000000, field:*(this+0x2F4):0x00000001]
    // ASSIGNMENT: Character insertion: translate the raw code with TranslateVirtualKey and filter it with sub_48B560; if accepted and there is room (cursor at this+0x2F4 minus start at this+0x2F0 < limit at this+0x2F8 minus 1), write the translated byte at the cursor, advance the cursor, and null-terminate. [callee:0x00455B30, callee:0x0048B560, field:this:0x000002F0, field:this:0x000002F4, field:this:0x000002F8, field:*(this+0x2F4):0x00000000, field:*(this+0x2F4):0x00000001]
    // CALL: Width/overflow re-check: when the render surface (this+0x2FC), the font object (this+0xC8) and the string object (this+0x40) are all set, load the font string from *(this+0xC8)+0x40 (fallback byte_5EA438) via sub_498560, measure the text at the cursor (this+0x2FC) and at the buffer start (this+0x2F0) with TextRenderToSurface, and if the start measurement exceeds the cursor measurement, rewind the cursor and null-terminate. [field:this:0x000002FC, field:this:0x000000C8, field:*(this+0xC8):0x00000040, field:this:0x00000040, field:this:0x000002F0, callee:0x00498560, callee:0x004983B0, global:0x005EA438]
    // CALL: Refresh rendered text: StringReverseCopyLookup into *(this+0x40)+5772 using the lookup source string at this+0xA0 (fallback byte_5EA438) and the buffer start this+0x2F0, then dispatch the vtable slot 0x2C update method on this. [callee:0x0049A490, field:this:0x00000040, field:this:0x000000A0, field:this:0x000002F0, global:0x005EA438, field:obj:0x0000002C, field:this:0x00000000]
    // STATE_TRANSITION: Accept path (loop exited on codes 1 or 28): if the byte at this+0xE5 is zero, SetterVTableIDCheck(0); dispatch vtable slot 0xB0 (enter activation) on this and mark handled. [field:this:0x000000E5, field:this:0x00000000, field:obj:0x000000B0, callee:0x0048B910]
    // RETURN: Return the handled flag (nonzero if any key was processed). [source:raw, function:0x0048B600]

    // Conservative worker pseudocode:
    //   if (!this->enabled) return 0;
    //   for (i = 0; i < count; i++) {
    //       code = events[i];
    //       if (code == 1 || code == 28) break;
    //       if (code == 14) { backspace(); handled = 1; refresh(); continue; }
    //       if (is_allowed(translate(code))) {
    //           if (cursor - start < limit - 1) { *cursor++ = translated; *cursor = 0; }
    //           if (overflow_after_insert()) backspace();
    //           handled = 1;
    //       }
    //       refresh();
    //   }
    //   if (code == 1 || code == 28) { if (!this->accept_enabled) check_id(0); this->vtbl[176](this); handled = 1; refresh(); }
    //   return handled;
    // UNRESOLVED: role of global ppvOut (0x007CA590), read-only
    // UNRESOLVED: meaning of the hard-coded 5772-byte offset into *(this+0x40) used by StringReverseCopyLookup
    // UNRESOLVED: exact semantics of the two TextRenderToSurface width comparisons
}
