## BitmapDraw_81f0_004981f0 — UI Message Element Render (Text Only)

**Summary:** Renders a text or UI element at a specified vertical position with horizontal centering within bounding rectangle. Optionally resolves input string through a message display buffer. Similar to BitmapDraw_004980d0 but without the background surface fill step.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIFieldRenderer (00487f70), UITextBoxRendererWithScrollbar (004883d0), UILargeRenderDispatcher (00488be0), TextInputRender (0048b9c0), UIFullRenderWithDimensions (0048fee0), FPSOverlayDraw (00495440)

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
| 00423a00 | BinarySearchInStringTable | Looks up string a2 in string table; returns non-zero if found |
| 00494f00 | ShortComputation_4f00 | Computes element dimensions (width) from string |
| 00494f10 | UIMessageDispatch | Dispatches UI element display at computed horizontal position |
| 00495150 | GlobalAccessor_5150 | Retrieves global context/state value for dispatch |

**Guard conditions:**
- `a2 == NULL` → return -1 (BLOCKED: no element string)
- `strlen(this + 5400) == 0` → skip body, return 0 (BLOCKED: no display text)
- `a7 != 0` → lookup a2 in string table, copy to message buffer if found (PASSES: use buffered message)
- `a7 == 0` → use a2 directly (PASSES: direct string)
- `a4 - a3 <= (int)a2` → left-align element (PASSES)
- `a4 - a3 > (int)a2` → center-align element horizontally (PASSES)
