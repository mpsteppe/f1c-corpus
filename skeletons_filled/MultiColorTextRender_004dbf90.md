## MultiColorTextRender_004dbf90 — Render multi-color lap/time overlay

**Summary:** Renders race information overlay using two color passes per text line: lap info in yellow at right offset, then position/status text pairs (white foreground + yellow overlay) at two rows on the left side of the screen.

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

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049bde0 | sub_49BDE0 | Format overlay color text field 1 into buffer |
| 0049be50 | sub_49BE50 | Format overlay color text field 2 into buffer |
| 0049c670 | sub_49C670 | Format lap count text into buffer |
| 0049c700 | sub_49C700 | Format secondary text field 1 into buffer |
| 0049c770 | sub_49C770 | Format secondary text field 2 into buffer |
| 004d7e40 | UITextRenderWithScale | Render text with position, color, scale, and alignment parameters |

**Guard conditions:** None — function executes unconditionally.
