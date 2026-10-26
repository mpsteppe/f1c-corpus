## MenuCursorNavigationHelper_0047b730 — MenuTextWrapMeasurer

**Summary:** Text word-wrapping helper: binary-searches a string to find the split position that fits within a width constraint (this+0x100), then backtracks to the nearest word boundary (space or 0xFF). Used for menu text layout/wrapping.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MenuItemLayoutCalculator (0047b850), MenuCursorPositioning (0047b9c0), MenuCursorCount (0047bc30), MenuCursorCount_bc90 (0047bc90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC8) | 0x40 | R | — | Object pointer used for resource path lookup (char* at +64 fed to sub_498560) |
| *(this+0xE0) | 0x0 | R | — | String pointer for text to measure/wrap |
| this | 0xC8 | R | — | Pointer to an associated object (for resource path) |
| this | 0xE0 | R | — | Pointer to text string pointer (double indirection) |
| this | 0x100 | R | — | Max width constraint (compared against measured text width) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback directory path |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004983b0 | TextRenderToSurface | Measures rendered text width by temporarily rendering to a surface |
| 00498560 | sub_498560 | Processes resource path (called per-iteration for context setup) |

**Guard conditions:** External binary search loop (v6 > 0) — always enters with v6=32. Inner loop checks `step + a2 <= string_len - 1`. After positioning, if character at found position is non-null, backtracks looking for space (0x20) or 0xFF word boundary, with bounds check `v11 >= a2`.
