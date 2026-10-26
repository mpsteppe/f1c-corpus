## MenuCursorPositioning_0047b9c0 — MenuCursorPositioning

**Summary:** Positions menu cursor on wrapped text: navigates wrapped items to find the line containing the cursor, measures the substring width, advances through additional wrapped items, then renders via MenuItemRenderHelper and updates cursor position.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC8) | 0x40 | R | — | Object used for resource path (char* at +64) |
| *(this+0xE0) | 0x0 | R | — | Source text string pointer |
| this | 0xC8 | R | — | Pointer to associated object for resource path setup |
| this | 0xE0 | R | — | Double-indirect pointer to source text |
| this | 0xE4 | RW | — | Cursor position / visible item index (start of current visible range) |

**Written-by note (persistence):**
- this 0xE4: Written each call with new cursor position; persists until next positioning update

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default fallback text string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0047b730 | MenuCursorNavigationHelper | Navigates wrapped text to find next/previous item boundaries |
| 0047b910 | MenuItemRenderHelper | Renders menu item text at the calculated position |
| 004983b0 | TextRenderToSurface | Measures rendered text width |
| 00498560 | sub_498560 | Processes resource directory path before rendering |

**Guard conditions:** First loop breaks when: (1) no more wrapping (v6==v8), (2) cursor position (this+0xE4) is before current wrap position, (3) end of string with last char not 0xFF delimiter. Second loop: if cursor advance would be negative (v13 < i), resets to line 0. Loop ends when i >= v13.
