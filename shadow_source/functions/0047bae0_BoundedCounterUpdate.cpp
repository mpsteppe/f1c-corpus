// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BAE0
// Canonical corpus name: BoundedCounterUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundedCounterUpdate_0047bae0.c

void UnknownObject::BoundedCounterUpdate()
{
    // Updates a bounded counter stored at this+0xEC by delta a2. On a positive delta, clamps to the last valid index (MenuCursorCount_bc90 result minus one). On a non-positive delta, clamps to zero when the result would go negative. Both paths finish by calling UtilityFunction_bd90 and returning its result.
    // ASSIGNMENT: Read the current counter value at this+0xEC into a scratch value before applying the delta. [source:raw, field:this:0x000000EC]
    // GUARD: Branch on whether the delta a2 is greater than zero (increment path). [source:raw]
    // ASSIGNMENT: Increment path: store the new counter value (delta a2 added to the current value) back to this+0xEC. [source:raw, field:this:0x000000EC]
    // CALL: Query the total scrollable item count via MenuCursorCount_bc90(this) and compute the last valid index as count minus one. [source:raw, callee:0x0047BC90]
    // GUARD: Check whether the incremented counter now exceeds the last valid index. [source:raw]
    // ASSIGNMENT: Clamp the counter at this+0xEC down to the last valid index when it overflows. [source:raw, field:this:0x000000EC]
    // ASSIGNMENT: Non-positive path: store the new counter value (delta a2 added to the current value) back to this+0xEC. [source:raw, field:this:0x000000EC]
    // GUARD: Check whether the decremented counter went below zero. [source:raw]
    // ASSIGNMENT: Clamp the counter at this+0xEC up to zero when the delta would drive it negative. [source:raw, field:this:0x000000EC]
    // CALL: Invoke UtilityFunction_bd90(this) after the counter update. [source:raw, callee:0x0047BD90]
    // RETURN: Return the result of UtilityFunction_bd90 on both paths. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_47BAE0(_DWORD *this, int delta) {
    //     int current = this[59];            // this+0xEC
    //     if (delta > 0) {
    //       this[59] = delta + current;
    //       int last = MenuCursorCount_bc90(this) - 1;
    //       if (this[59] > last) this[59] = last;
    //     } else {
    //       this[59] = delta + current;
    //       if (delta + current < 0) this[59] = 0;
    //     }
    //     return UtilityFunction_bd90(this);
    //   }
    // UNRESOLVED: What the counter at this+0xEC drives (scroll position per existing analysis) is not proven by this function alone; MenuCursorCount_bc90 defines the upper bound semantics.
    // UNRESOLVED: UtilityFunction_bd90 return value semantics are opaque here.
}
