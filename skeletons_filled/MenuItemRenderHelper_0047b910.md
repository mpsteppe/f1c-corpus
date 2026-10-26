## MenuItemRenderHelper_0047b910 — MenuItemFitMeasurer

**Summary:** Measures text character-by-character to find how many characters fit within a width constraint. Used to trim menu item text for display within available space.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuItemLayoutCalculator (0047b850), MenuCursorPositioning (0047b9c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | R | — | Pointer to string pointer (double indirection — source text) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback directory path / string source |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004983b0 | TextRenderToSurface | Measures rendered text width for a given substring |

**Guard conditions:** If `a3 + 1 >= a4` (no characters to measure), skips loop entirely. Loop breaks when rendered width exceeds available width `a2`. Final check: if `v5 == a4` and `v5 > a3` and character at `v4[v5]` is non-null, decrement v5.
