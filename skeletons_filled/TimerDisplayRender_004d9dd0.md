## TimerDisplayRender_004d9dd0 — Timer HUD display with separators

**Summary:** Renders the timer HUD area: delegates countdown logic to TimerCountdown, then renders two colored separator characters (red left, green right) and a centered track/venue path label in yellow. Only draws when countdown timer is active.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccef0 | aC | R | FormatString [DERIVED] |
| 005d4ae9 | byte_5D4AE9 | R | Separator character rendered as left (red) and right (green) decorative elements |
| 005ea438 | byte_5EA438 | R | Default application directory path used as track label text |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] — base buffer for string search |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] — working buffer for rendered text |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Checks if directory path is in display buffer; if found, triggers copy for render |
| 004d7e40 | UITextRenderWithScale | Renders separator chars (red/green) and center label (yellow) |
| 004d98a0 | TimerCountdown | Processes countdown timer: decrements and renders driver info; returns 0 while active |
| 00587dd0 | sub_587DD0 | Copies string into local buffer with max length 127 |
| 0058815f | StringFormatWithBufferOverflowCheck | Formats separator character into buffer |

**Guard conditions:** `TimerCountdown(this)` returning non-zero → BLOCKED (timer expired, skip all rendering). `BinarySearchInStringTable` true → triggers path string copy into display buffer before render.
