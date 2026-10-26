// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047B850
// Canonical corpus name: MenuItemLayoutCalculator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MenuItemLayoutCalculator_0047b850.c

void UnknownObject::MenuItemLayoutCalculator()
{
    // Computes which menu item to activate and render given a cursor/scroll position. Reads the item height from this+0xF4 and returns 0 if it is not positive; otherwise derives a horizontal position v6 from the width argument minus the right/left margins (this+0xF8, this+0xC), derives a clamped line index v7 from the height argument minus the bottom/top margins (this+0xFC, this+0x4) divided by the item height, clamped to [0, this+0xF0-1]. It then walks wrapped items from the scroll offset this+0xEC via MenuCursorNavigationHelper until the helper returns the queried index (success) or the remaining count is exhausted, resolves a resource-path string through this+0xC8 (falling back to byte_5EA438), and finally renders via MenuItemRenderHelper.
    // GUARD: Item-height guard: v4 = this[61] (offset 0xF4); when v4 is not positive the layout is degenerate and the function returns 0 immediately. [field:this:0x000000F4, source:raw]
    // CALCULATION: Horizontal position: v6 = a2 - this[62] (offset 0xF8 right margin) - this[3] (offset 0xC left margin), the usable width for the item. [field:this:0x0000000C, field:this:0x000000F8, source:raw]
    // CALCULATION: Vertical line index: v7 = (a3 - this[63] (offset 0xFC bottom margin) - this[1] (offset 0x4 top margin)) / v4, mapping the height argument into an item line number. [field:this:0x00000004, field:this:0x000000F4, field:this:0x000000FC, source:raw]
    // GUARD: Clamp the line index to the visible window: when v7 is negative force it to 0; when v7 exceeds this[60] - 1 (offset 0xF0 max visible item count) clamp to this[60] - 1. [field:this:0x000000F0, source:raw]
    // CALCULATION: Scroll base: v8 = this[59] (offset 0xEC scroll offset) + clamped v7, the starting point for the wrap navigation count. [field:this:0x000000EC, source:raw]
    // LOOP: Wrap navigation: repeatedly call MenuCursorNavigationHelper((int)this, i); when the helper returns the same index as the current i the target item is found and i is returned; otherwise decrement v8 and continue; break once v8 reaches 0. [callee:0x0047B730, field:this:0x000000EC, source:raw]
    // CALCULATION: Resource path resolution: when v11 = this[50] (offset 0xC8) is non-null, load the string pointer v12 = *(char **)(v11 + 64) (byte offset 0x108 from this) and fall back to the global byte_5EA438 when it is null. [field:this:0x000000C8, field:this:0x00000108, global:0x005EA438, source:raw]
    // CALL: sub_498560(v12) processes the resolved resource-path string before rendering. [callee:0x00498560, source:raw]
    // CALL: MenuItemRenderHelper(v6, i, v10) renders the computed menu item at the derived position using the saved navigation result, and its result is returned. [callee:0x0047B910, source:raw]
    // RETURN: Return 0 on the degenerate item-height path and on the success path where MenuCursorNavigationHelper returns the queried index; otherwise return the MenuItemRenderHelper result. [source:raw]

    // Conservative worker pseudocode:
    //   v4 = this[61];
    //   if (v4 <= 0) return 0;
    //   v6 = a2 - this[62] - this[3];
    //   v7 = clamp((a3 - this[63] - this[1]) / v4, 0, this[60] - 1);
    //   v8 = this[59] + v7;
    //   for (i = 0; ; ) {
    //     v10 = MenuCursorNavigationHelper(this, i);
    //     if (i == v10) return i;
    //     if (!v8) break;
    //     --v8;
    //     i = v10;
    //   }
    //   if (this[50]) { v12 = *(this[50] + 64); if (!v12) v12 = byte_5EA438; sub_498560(v12); }
    //   return MenuItemRenderHelper(v6, i, v10);
    // UNRESOLVED: The exact meaning of the wrap navigation count in this[59] (scroll offset) and the semantics of the this+0xF0 ceiling as a visible-item count are DERIVED from the fill, not runtime-confirmed.
    // UNRESOLVED: The field entry field:this:0x00000108 represents the string pointer reached through this[50] + 64; the decompiler renders it as *(char **)(v11 + 64), so the 0x108 offset is an interpretation of the packet field list.
    // UNRESOLVED: byte_5EA438 is used as the fallback path string when this+0xC8 does not yield a valid pointer; its exact content is unknown.
}
