## BoundedCounterUpdate_0047bae0 — ScrollOffsetBoundedUpdate

**Summary:** Updates scroll offset (this+0xEC) by delta a2, clamping within [0, total_items-1]. Returns result of UtilityFunction_bd90.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIComponentScrollUpdate (0047b1e0), sub_47BB40 (0047bb40)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | 0 | Scroll offset (item index at top of visible range) |

**Written-by note (persistence):**
- this 0xEC: Updated each call with clamped scroll offset; persists between scroll operations

**Globals referenced:** None

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047bc90 | MenuCursorCount_bc90 | Returns total number of scrollable items |
| 0047bd90 | UtilityFunction_bd90 | Recalculates scroll bar position after offset change |

**Guard conditions:** If a2 > 0, clamps to [0, total-1]; if a2 <= 0, clamps to >= 0 (no negative scroll). Always calls UtilityFunction_bd90.
