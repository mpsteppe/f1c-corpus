## sub_47BCF0_0047bcf0 — MenuScrollOffsetAdjust

**Summary:** Adjusts scroll offset (this+0xEC) to keep cursor visible after item count changes. Reads total lines and visible item count, then clamps or shifts scroll offset.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | 0 | Scroll offset (adjusted to keep cursor in view) |
| this | 0xF0 | R | — | Max visible item count (used for scroll range calculations) |

**Written-by note (persistence):**
- this 0xEC: Written with adjusted scroll offset; persists until next adjustment

**Globals referenced:** None

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047bc30 | MenuCursorCount | Counts total wrapped text lines |
| 0047bc90 | MenuCursorCount_bc90 | Returns total number of scrollable items |

**Guard conditions:** Two branches based on whether total lines >= visible threshold. If scroll offset exceeds max, clamps to max. Final clamp to [0, total_items-1] and calls UtilityFunction_bd90.
