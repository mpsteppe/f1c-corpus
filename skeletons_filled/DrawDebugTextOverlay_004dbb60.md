## DrawDebugTextOverlay_004dbb60 — Render multi-line debug text overlay

**Summary:** Renders debug information overlay by formatting multiple data fields into a 64-byte buffer via sub_49C* formatters and displaying them as colored text lines at screen-relative positions (a1 offset); also renders a secondary overlay element via DoubleRenderPass.

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
| 0049c310 | sub_49C310 | Format debug field 1 into text buffer |
| 0049c370 | sub_49C370 | Format debug field 2 into text buffer |
| 0049c490 | sub_49C490 | Format debug field 3 into text buffer |
| 0049c4e0 | sub_49C4E0 | Format debug field 4 into text buffer |
| 0049c6d0 | sub_49C6D0 | Clear/initialize 64-byte text buffer |
| 004d7e40 | UITextRenderWithScale | Render text with position, color, scale, and alignment parameters |
| 004dc1a0 | DoubleRenderPass | Render secondary overlay element (dual-pass render) |

**Guard conditions:** None — function executes unconditionally with no early-return branches.
