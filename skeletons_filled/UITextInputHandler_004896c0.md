## UITextInputHandler_004896c0 — word-wrapping text input handler for UI text items

**Summary:** Takes input text string and word-wraps it to fit available width in a UI text element. Breaks text at word boundaries, creates menu items for each line via UIMenuItemCreator, and optionally sets item names via UIItemNameSetter.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionStateDispatch (004a0df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | related UI object's width or dimension for text area calculation |
| obj | 0x2C | R | — | related UI object's offset/margin for text area calculation |
| this | 0x0 | R | — | vtable pointer |
| this | 0xC | R | — | horizontal margin/padding for text layout |
| this | 0x94 | R | — | item count/offset used by UIItemNameSetter to index created items |
| this | 0xC8 | R | — | pointer to a structure containing file/resource path at +0x40 (or default path byte_5EA438) |
| this | 0x108 | R | — | unknown |
| this | 0x140 | R | — | right-side margin/padding dimension for text width calculation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | fallback default directory path when resource path field at this[0xC8]+0x40 is null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489600 | UIMenuItemCreator | creates a UI menu item for each word-wrapped text line |
| 00489c10 | UIItemNameSetter | sets name on the last created menu item (indexed via this[0x94]-1) |
| 00489d00 | sub_489D00 | finalizes/resets text input state |
| 004983b0 | TextRenderToSurface | measures rendered text width for word-wrap boundary detection |
| 00498560 | sub_498560 | loads or initializes text resource from path |
| 00587dd0 | sub_587DD0 | safe string copy with size limit (snprintf-style) |

**Guard conditions:** Returns -1 if a2 (input string) is null. If this[0xC8] is non-null, loads text resource from path at (this[0xC8]+0x40) or default path byte_5EA438. Word-wrap loop: breaks at word boundary when rendered width exceeds available space (v10). Trailing spaces are skipped before next iteration. Remaining unprocessed text after loop creates one final menu item.
