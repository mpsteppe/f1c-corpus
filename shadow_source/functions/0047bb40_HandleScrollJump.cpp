// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BB40
// Canonical corpus name: sub_47BB40
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47BB40_0047bb40.c

void UnknownObject::HandleScrollJump()
{
    // Handles a scroll jump in a menu-style list. Compares the target position a2 against the current view center; when they differ, updates a bounded page counter (this+0xF0) by a full page, then either returns the half-item-height fine delta or applies a clamped fine scroll offset (this+0x110) and refreshes the display via sub_47BE00.
    // CALL: Invoke the virtual method at vtable offset 28 (index 7) on this to read the current scroll position. [field:this:0x00000000, field:obj:0x0000001C]
    // CALCULATION: Compute the view center as the scroll offset this+0x110 plus half the item height (this+0x118 / 2) plus the virtual scroll position. [field:this:0x00000110, field:this:0x00000118, field:obj:0x0000001C]
    // GUARD: When the target position a2 equals the computed center, return the half-item-height value without changing the scroll. [source:raw]
    // STATE_TRANSITION: When the target a2 is below the center, update the bounded page counter by subtracting this+0xF0 (one page). [callee:0x0047BAE0, field:this:0x000000F0]
    // STATE_TRANSITION: When the target a2 is above the center, update the bounded page counter by adding this+0xF0 (one page). [callee:0x0047BAE0, field:this:0x000000F0]
    // GUARD: Recompute the center after the page jump; when the target is still beyond it on the same side, return the half-item-height value without a fine adjustment. [field:this:0x00000110, field:this:0x00000118, field:obj:0x0000001C]
    // CALCULATION: Compute the fine scroll delta as the target a2 minus half the item height (this+0x118 / 2) minus the virtual scroll position. [field:this:0x00000118, field:obj:0x0000001C]
    // ASSIGNMENT: Write the fine delta into the scroll offset this+0x110. [field:this:0x00000110]
    // GUARD: Clamp the scroll offset to the maximum bound this+0x114 when the delta exceeds it, and to 0 when the delta is negative. [field:this:0x00000114, field:this:0x00000110]
    // CALL: Apply the final scroll position and refresh the display via sub_47BE00, returning its result. [callee:0x0047BE00]

    // Conservative worker pseudocode:
    //   cursor = virtual(this, offset 28)()
    //   half_step = this[70] / 2
    //   center = this[68] + half_step + cursor
    //   if a2 == center: return half_step
    //   if a2 < center:
    //       BoundedCounterUpdate(this, -this[60])
    //   else:
    //       BoundedCounterUpdate(this, this[60])
    //   cursor2 = virtual(this, offset 28)()
    //   if a2 < this[68] + half_step + cursor2: return half_step
    //   if a2 > this[68] + half_step + cursor2: return half_step
    //   delta = a2 - half_step - cursor2
    //   this[68] = delta
    //   if delta < 0: this[68] = 0
    //   elif delta > this[69]: this[68] = this[69]
    //   return sub_47BE00(this)
    // UNRESOLVED: Return value contract: the half-item-height value (this+0x118 / 2) is returned as the fine scroll delta on several paths, while the clamped path returns the result of sub_47BE00; the caller's (UIComponentScrollUpdate, 0x0047B1E0) use of the mixed return is unverified.
    // UNRESOLVED: The virtual slot at vtable offset 28 (index 7) returning the scroll position is unnamed; its concrete identity is unknown.
    // UNRESOLVED: Whether the fine-offset path runs only after a successful page jump or also for in-page moves is inferred from the raw control flow; the exact user-facing page-up/page-down semantics depend on caller context.
}
