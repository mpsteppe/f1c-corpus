## TextRenderWithShadow_004dbde0 — Render text with shadow outline

**Summary:** Renders text with a drop-shadow effect by performing two render passes at the same position: first a shadow pass (mode 1/alignment 2) and then a foreground pass (mode 0/alignment 1), using sub_49C8F0 and sub_49C960 to format the text buffer.

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
| 0049c8f0 | sub_49C8F0 | Format text into 64-byte buffer for shadow pass |
| 0049c960 | sub_49C960 | Format text into 64-byte buffer for foreground pass |
| 004d7e40 | UITextRenderWithScale | Render text string with position, color, scale, and alignment parameters |

**Guard conditions:** None — function executes unconditionally.
