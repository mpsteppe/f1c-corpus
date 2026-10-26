// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047B9C0
// Canonical corpus name: MenuCursorPositioning
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuCursorPositioning_0047b9c0.c

void UnknownObject::MenuCursorPositioning()
{
    // Positions the menu cursor on wrapped text. Reads the source text pointer (double-indirect this+0xE0) with a default fallback string, measures the current substring length, walks wrapped items via MenuCursorNavigationHelper to find the line containing the cursor, temporarily NUL-terminates the text at the cursor index to measure the sub-run with TextRenderToSurface, restores the character, applies a signed cursor advance clamped at zero, then advances through further wrapped items and renders the active item with MenuItemRenderHelper, storing the final index back to this+0xE4.
    // ASSIGNMENT: Read source text pointer through this+0xE0 (double-indirect); load the string, substituting the global default byte_5EA438 when the pointer is null [field:this:0x000000E0, field:*(this+0xE0):0x00000000, global:0x005EA438, source:raw]
    // CALCULATION: Measure the source string length v5 = strlen(text) + 1 [source:raw]
    // LOOP: First navigation loop: call MenuCursorNavigationHelper(this, v6) to locate the next wrap boundary, updating v6 to the returned index on each iteration [callee:0x0047B730, source:raw]
    // GUARD: Break the navigation loop when no further wrapping (v6 == v8), when the cursor index (this+0xE4) is before the candidate, or at end-of-string where the last character is not the 0xFF delimiter [field:this:0x000000E4, source:raw]
    // CALL: Set up the resource path: read the associated object via this+0xC8, take its char* at +0x40 (fallback byte_5EA438 if null) and pass it to sub_498560 for directory-path processing [field:this:0x000000C8, field:*(this+0xC8):0x00000040, callee:0x00498560, global:0x005EA438, source:raw]
    // ASSIGNMENT: Temporarily overwrite the text byte at the cursor index this+0xE4 with a NUL, measure the sub-run v4[v6] via TextRenderToSurface, then restore the original character [field:this:0x000000E4, callee:0x004983B0, source:raw]
    // CALCULATION: Compute the target cursor advance v13 = a2 + i and clamp it to zero when negative [source:raw]
    // GUARD: If the clamped target v13 falls below the current index i, reset both i and v6 to zero and re-run MenuCursorNavigationHelper(this, 0) [callee:0x0047B730, source:raw]
    // LOOP: Second loop: continue advancing v6 via MenuCursorNavigationHelper while the text at the returned index is non-empty, until i reaches the clamped target v13 [callee:0x0047B730, source:raw]
    // CALL: Render the active menu item with MenuItemRenderHelper(this, measured_width, v6, result) [callee:0x0047B910, source:raw]
    // ASSIGNMENT: Store the final cursor position result to this+0xE4 [field:this:0x000000E4, source:raw]
    // RETURN: Return the final cursor position [function:0x0047B9C0, source:raw]
    // CALL: Identified as the Menu_Cursor_Positioning ABI entry; menu-cursor positioning entry point [abi:lead, function:0x0047B9C0]

    // Conservative worker pseudocode:
    //   const char* text = **(const char***)(this + 0xE0);
    //   if (!text) text = byte_5EA438;
    //   len = strlen(text) + 1;
    //   pos = 0;
    //   for (i = 0; ; i++) {
    //       next = MenuCursorNavigationHelper(this, pos);
    //       if (pos == next || cursor >= next || (len - 1 == next && text[next - 1] != 0xFF)) break;
    //       pos = next;
    //   }
    //   obj = *(this + 0xC8);
    //   if (obj) sub_498560(*(char**)(obj + 0x40) ? *(char**)(obj + 0x40) : byte_5EA438);
    //   char saved = text[cursor]; text[cursor] = 0;
    //   TextRenderToSurface(&text[pos], &w, &dims, 1);
    //   text[cursor] = saved;
    //   target = max(0, a2 + i);
    //   if (target < i) { i = 0; pos = 0; MenuCursorNavigationHelper(this, 0); }
    //   while (i < target) {
    //       r = MenuCursorNavigationHelper(this, pos);
    //       if (!text[r]) break;
    //       i++; pos = r;
    //   }
    //   cursor = MenuItemRenderHelper(this, w, pos, r);
    //   this->cursor = cursor;
    //   return cursor;
    // UNRESOLVED: The 0xFF byte used as a wrap delimiter is implied by the end-of-string guard; its exact encoding is not established.
    // UNRESOLVED: Semantics of a2 (relative cursor delta) and the meaning of the count returned by MenuCursorNavigationHelper are inferred from usage only.
    // UNRESOLVED: The associated object at this+0xC8 and its +0x40 resource-path string are not identified to a concrete class.
}
