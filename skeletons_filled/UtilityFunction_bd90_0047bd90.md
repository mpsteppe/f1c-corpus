## UtilityFunction_bd90_0047bd90 — ScrollBarPositionCalc

**Summary:** Calculates scroll bar position/thumbsize: maps scroll offset (this+0xEC) to a proportional pixel position within track (this+0x114), using integer rounding. Clamps result to [0, track_size].

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** BoundedCounterUpdate (0047bae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | Scroll offset (item index) used as numerator |
| this | 0x110 | RW | 0 | Scroll bar pixel position (computed result) |
| this | 0x114 | R | — | Scroll track size (max pixel position, clamp ceiling) |

**Written-by note (persistence):**
- this 0x110: Written each call with proportional scroll bar position; persists until next calculation

**Globals referenced:** None

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047bc90 | MenuCursorCount_bc90 | Returns total item count (used as divisor in proportion) |

**Guard conditions:** If total items > 0, computes `(scroll_offset * track_size + count/2) / count`. If count <= 0 or result < 0, position = 0. Clamps result to [0, track_size].
