## MultiLayerTextRendering_004dbe60 — Render lap/time info with conditional layout

**Summary:** Renders multi-layer race information overlay; branches on TotalRaceLaps (dword_8ACF8C): if 0x7FFFFFFF (infinite), renders text with shadow at top position; otherwise renders lap counter in yellow at a larger offset. Always renders secondary text fields with shadow below.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 008acf8c | dword_8ACF8C | R | TotalRaceLaps [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049c670 | sub_49C670 | Format lap count text into buffer (finite laps branch) |
| 0049c700 | sub_49C700 | Format secondary text field 1 into buffer |
| 0049c770 | sub_49C770 | Format secondary text field 2 into buffer |
| 0049c8f0 | sub_49C8F0 | Format primary text into buffer for shadow pass |
| 0049c960 | sub_49C960 | Format primary text into buffer for foreground pass |
| 004d7e40 | UITextRenderWithScale | Render text with position, color, scale, and alignment parameters |

**Guard conditions:** Checks `dword_8ACF8C` (TotalRaceLaps) against `0x7FFFFFFF` (infinite/unset). PASSES when equal: renders text with shadow at (a1+50, 10) in white. BLOCKED/alternative when not equal: renders lap info in yellow at (a1+215, 46) instead.
