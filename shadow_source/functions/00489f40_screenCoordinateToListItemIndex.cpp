// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00489F40
// Canonical corpus name: sub_489F40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_489F40_00489f40.c

void UnknownObject::screenCoordinateToListItemIndex()
{
    // Converts a screen y-coordinate a2 into a list item index using layout parameters from the object at this: (a2 - horizontal_offset(0x13C) - column_offset(0x134) - start(0x4)) / item_height(0x158) + scroll_offset(0x14C), truncating with CRTFtol, then clamps the result within scroll bounds and, when a3 is set, within visible-page and total-item-count bounds.
    // GUARD: Load item height this[86] (offset 0x158); if it is not greater than 0, return -1 without computing an index. [field:this:0x00000158, source:raw]
    // GUARD: Check the vertical range: a2 must be greater than this[1] (offset 0x4) and less than this[2] (offset 0x8); otherwise return -1. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute the raw index as CRTFtol((a2 - this[79] - this[77] - this[1]) / item_height + this[83]), i.e. truncate the distance from the layout start divided by item height, offset by the scroll offset. [callee:0x00587BDC, field:this:0x0000013C, field:this:0x00000134, field:this:0x00000004, field:this:0x00000158, field:this:0x0000014C, source:raw]
    // ASSIGNMENT: Clamp the result up to the scroll offset this[83] (0x14C): if result < scroll offset, set result = scroll offset. [field:this:0x0000014C, source:raw]
    // GUARD: When a3 is set, clamp the result to at most this[89] (0x164) + scroll offset - 1, and if result >= this[37] (0x94, total item count) return this[37] - 1. [field:this:0x00000164, field:this:0x00000094, source:raw]
    // RETURN: Return the computed and clamped index, or -1 when the range or item-height guards fail. [source:raw]

    // Conservative worker pseudocode:
    //   int screenCoordinateToListItemIndex(int *this, int a2, char a3) {
    //     int itemHeight = this[86];
    //     if (itemHeight <= 0) return -1;
    //     int start = this[1];
    //     if (a2 <= start || a2 >= this[2]) return -1;
    //     int scroll = this[83];
    //     int idx = CRTFtol((double)(a2 - this[79] - this[77] - start) / (double)itemHeight + (double)scroll);
    //     if (idx < scroll) idx = scroll;
    //     if (a3) {
    //       if (idx > this[89] + scroll - 1) idx = this[89] + scroll - 1;
    //       if (idx >= this[37]) return this[37] - 1;
    //     }
    //     return idx;
    //   }
    // UNRESOLVED: The exact roles of the layout fields (horizontal offset 0x13C, column offset 0x134, vertical boundaries 0x4/0x8) are DERIVED from the existing fill; the formula itself is directly evidenced.
    // UNRESOLVED: The meaning of the a3 flag and the conditions under which callers set it are not established by this packet.
}
