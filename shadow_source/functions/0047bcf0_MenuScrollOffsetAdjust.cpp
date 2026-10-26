// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0047BCF0
// Canonical corpus name: sub_47BCF0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_47BCF0_0047bcf0.c

void UnknownObject::MenuScrollOffsetAdjust()
{
    // __thiscall menu-scroll offset adjustment. Reads the current scroll offset from this+0xEC and the maximum visible item count from this+0xF0, queries the total wrapped-line count via MenuCursorCount (0047BC30) and the total scrollable-item count via MenuCursorCount_bc90 (0047BC90), then shifts or clamps this+0xEC so the cursor stays inside the visible window as the item count changes. A final clamp keeps the offset within [0, item_count-1], then the function tail-calls UtilityFunction_bd90 and returns its result.
    // CALL: v2 = MenuCursorCount(this): query the total wrapped-line count for the cursor [callee:0x0047BC30, source:raw]
    // CALL: v3 = MenuCursorCount_bc90(this): query the total number of scrollable items [callee:0x0047BC90, source:raw]
    // ASSIGNMENT: v4 = *(this+0xEC): load the current scroll offset [field:this:0x000000EC, source:raw]
    // GUARD: Branch on v2 >= v4 (cursor at/past current offset) versus v2 < v4 (cursor above the offset) [field:this:0x000000EC, source:raw]
    // CALCULATION: v7 = *(this+0xF0): read maximum visible item count; if v2 < v7+v4 the offset is already in range and stays unchanged (goto LABEL_14) [field:this:0x000000F0, source:raw]
    // CALCULATION: If v2 == v7+v4 (cursor exactly at window bottom) new offset v6 = v4+1 [field:this:0x000000EC, field:this:0x000000F0, source:raw]
    // CALCULATION: If v2 > v7+v4 (cursor beyond window) compute shift v8 = v2-(v7+v4-1), raise v7 to v8 when needed, new offset v6 = v7+v4 [field:this:0x000000EC, field:this:0x000000F0, source:raw]
    // ASSIGNMENT: *(this+0xEC) = v6: store the adjusted scroll offset for the v2 >= v4 branch [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Else if v2 >= v4-1 (cursor just above window) store *(this+0xEC) = v4-1 and goto LABEL_14 [field:this:0x000000EC, source:raw]
    // CALCULATION: Otherwise v5 = v4-v2, raised to *(this+0xF0) when larger; v6 = v4-v5 so the window shifts up to the cursor [field:this:0x000000EC, field:this:0x000000F0, source:raw]
    // ASSIGNMENT: *(this+0xEC) = v6: store the shifted offset for the v2 < v4 branch [field:this:0x000000EC, source:raw]
    // GUARD: LABEL_14 final clamp: v10 = *(this+0xEC); if v10 >= 0 then clamp to v9 = v3-1 when above, else set *(this+0xEC) = 0 [field:this:0x000000EC, source:raw]
    // ASSIGNMENT: Store the clamped offset: *(this+0xEC) = min(v10, v3-1) when v10 >= 0, else *(this+0xEC) = 0 [field:this:0x000000EC, source:raw]
    // CALL: Tail call UtilityFunction_bd90(this); return its result. Target address is not in the packet's callee evidence [source:raw]
    // RETURN: Return the result of UtilityFunction_bd90(this) [function:0x0047BCF0, source:raw]

    // Conservative worker pseudocode:
    //   v2 = MenuCursorCount(this);
    //   v3 = MenuCursorCount_bc90(this);
    //   v4 = *(this + 0xEC);
    //   if (v2 >= v4) {
    //     v7 = *(this + 0xF0);
    //     if (v2 < v7 + v4) goto LABEL_14;
    //     if (v2 == v7 + v4) v6 = v4 + 1;
    //     else {
    //       v8 = v2 - (v7 + v4 - 1);
    //       if (v7 <= v8) v7 = v8;
    //       v6 = v7 + v4;
    //     }
    //   } else {
    //     if (v2 >= v4 - 1) { *(this + 0xEC) = v4 - 1; goto LABEL_14; }
    //     v5 = v4 - v2;
    //     if (*(this + 0xF0) > v4 - v2) v5 = *(this + 0xF0);
    //     v6 = v4 - v5;
    //   }
    //   *(this + 0xEC) = v6;
    //   LABEL_14:
    //   v9 = v3 - 1;
    //   if (*(this + 0xEC) >= 0) {
    //     if (*(this + 0xEC) > v9) *(this + 0xEC) = v9;
    //   } else {
    //     *(this + 0xEC) = 0;
    //   }
    //   return UtilityFunction_bd90(this);
    // UNRESOLVED: UtilityFunction_bd90 is called as a tail call but the packet provides no callee address for it, so no callee evidence ref could be recorded
    // UNRESOLVED: The exact semantic split between MenuCursorCount (0047BC30, wrapped-line count) and MenuCursorCount_bc90 (0047BC90, scrollable-item count) is inferred from the surrounding clamp logic, not from packet prose
    // UNRESOLVED: The owner object is unknown; this+0xEC and this+0xF0 are only assigned by this function's own semantics
    // UNRESOLVED: No static callers recorded, so where this offset adjustment is invoked from the menu subsystem is unresolved
}
