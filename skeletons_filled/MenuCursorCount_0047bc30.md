## MenuCursorCount_0047bc30 — MenuCursorCount

**Summary:** Counts the number of wrapped text items/lines up to the cursor position. Iterates via MenuCursorNavigationHelper, incrementing counter until end of string or cursor position is reached.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47BCF0 (0047bcf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xE0) | 0x0 | R | — | Source text string pointer |
| this | 0xE0 | R | — | Double-indirect pointer to source text string |
| this | 0xE4 | R | — | Cursor position (limit for line counting) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback text string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b730 | MenuCursorNavigationHelper | Navigates to next wrapped line boundary |

**Guard conditions:** Loop breaks when: (1) no more wrapping (i==v6), (2) cursor position (this+0xE4) < current wrap position, (3) end of string with last char not 0xFF delimiter.
