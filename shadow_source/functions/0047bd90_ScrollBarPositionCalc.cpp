// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BD90
// Canonical corpus name: UtilityFunction_bd90
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/UtilityFunction_bd90_0047bd90.c

void UnknownObject::ScrollBarPositionCalc()
{
    // Computes a scroll-bar thumb pixel position on `this`. Reads the item count from MenuCursorCount_bc90(this), subtracts 1, and if that count exceeds 0 writes `(this+0xEC * this+0x114 + count/2) / count` to this+0x110; otherwise writes 0. Then clamps this+0x110 into [0, this+0x114] and returns the (pre-clamp) value read back. Integer rounding via the +count/2 term. Caller BoundedCounterUpdate (0047BAE0) drives it for menu cursor scrolling.
    // CALL: v2 = MenuCursorCount_bc90(this) - 1; obtain total item count from the menu cursor counter. [callee:0x0047BC90, function:0x0047BD90, source:raw]
    // GUARD: If v2 > 0, compute proportional position; else write 0 to this+0x110. [field:this:0x00000110, function:0x0047BD90, source:raw]
    // CALCULATION: this+0x110 = (this+0xEC * this+0x114 + v2/2) / v2; map scroll offset to a pixel position with integer rounding. [field:this:0x000000EC, field:this:0x00000110, field:this:0x00000114, function:0x0047BD90, source:raw]
    // ASSIGNMENT: else branch: this+0x110 = 0 when the count is not positive. [field:this:0x00000110, function:0x0047BD90, source:raw]
    // ASSIGNMENT: result = this+0x110; v4 = this+0x114; reload the computed position and the track size. [field:this:0x00000110, field:this:0x00000114, function:0x0047BD90, source:raw]
    // GUARD: Clamp: if result < 0 write 0; else if result > v4 write v4 to this+0x110. [field:this:0x00000110, field:this:0x00000114, function:0x0047BD90, source:raw]
    // RETURN: Return the pre-clamp position value held in result. [function:0x0047BD90, source:raw]

    // Conservative worker pseudocode:
    //   count = MenuCursorCount_bc90(this) - 1;
    //   if (count > 0)
    //     this->pos = (this->scrollOffset * this->track + count / 2) / count;
    //   else
    //     this->pos = 0;
    //   result = this->pos;
    //   track = this->track;
    //   if (result < 0)
    //     this->pos = 0;
    //   else if (result > track)
    //     this->pos = track;
    //   return result;
    // UNRESOLVED: Semantics of this+0xEC (scroll offset) and this+0x114 (track) as menu UI metrics is DERIVED from the field reads and the MenuCursorCount_bc90 divisor; the owning menu widget type is unidentified.
    // UNRESOLVED: The pre-clamp value (not the clamped one) is returned; callers may consume a value that exceeds the clamp bounds.
}
