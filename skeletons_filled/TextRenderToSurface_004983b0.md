## TextRenderToSurface_004983b0 — Text Dimensions Computer

**Summary:** Computes rendered width and height of a text string. Optionally resolves the string through a message display buffer. Returns dimensions via output parameters a3 (width) and a4 (height). Called by many UI rendering functions to size text elements.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextWidgetInit (0047aab0), MenuCursorNavigationHelper (0047b730), MenuItemRenderHelper (0047b910), MenuCursorPositioning (0047b9c0), UIFieldRenderer (00487f70), UITextBoxRendererWithScrollbar (004883d0), UILargeRenderDispatcher (00488be0), UITextInputHandler (004896c0), sub_489D00 (00489d00), UIFullRenderPass (0048b030), UIEventShortcutHandler (0048b600), TextInputRender (0048b9c0), UIFullRenderWithDimensions (0048fee0), FPSOverlayDraw (00495440), UIComboListRender (00495580), UITextDialogRendering (00495bd0), StringTruncationWrapper (004985d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | R | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Looks up string a2 in string table; returns non-zero if found; used to decide whether to copy to message buffer |
| 00494f00 | ShortComputation_4f00 | Computes rendered text width and height from string, writing to *a3 and *a4 |

**Guard conditions:**
- `a2 == NULL` → set *a3=0, *a4=0, return -1 (BLOCKED: no input string)
- `strlen(this + 5400) == 0` → keep *a3=0, *a4=0, return 0 (BLOCKED: no display text to measure)
- `a5 != 0` → lookup a2 in string table, copy to message buffer if found, measure from buffer (PASSES: use buffered message)
- `a5 == 0` → measure a2 directly (PASSES)
