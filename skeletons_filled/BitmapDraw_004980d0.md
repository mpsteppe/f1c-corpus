## BitmapDraw_004980d0 — Centered Bitmap/UI Element Render

**Summary:** Renders a bitmap or UI element centered within a bounding rectangle if a text string is present. Optionally resolves the input string through a message display buffer. Computes centered horizontal/vertical position, dispatches UI display, then fills a background surface behind the rendered element.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UITextBoxRendererWithScrollbar (004883d0), UILargeRenderDispatcher (00488be0), UIFullRenderWithDimensions (0048fee0)

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
| 00423a00 | BinarySearchInStringTable | Looks up string a2 in a string table; returns non-zero if found |
| 00490920 | Accessor | Gets render surface/context pointer for fill operation |
| 004918d0 | RenderSurfaceFillCopy | Fills a rectangular surface area at computed position |
| 00494f00 | ShortComputation_4f00 | Computes element/text dimensions (width, height) |
| 00494f10 | UIMessageDispatch | Dispatches UI element display at centered position with computed dimensions |
| 00495150 | GlobalAccessor_5150 | Retrieves global context or state value used for the dispatch |

**Guard conditions:**
- `a2 == NULL` → return -1 (BLOCKED: no element string)
- `strlen(this + 5400) == 0` → skip entire rendering body, return 0 (BLOCKED: no display text present)
- `a7 != 0` → lookup a2 in string table, copy to message buffer if found (PASSES: use buffered message)
- `a7 == 0` → use a2 directly (PASSES: direct string)
- `a4 - a3 <= (int)a2` → left-align if element wider than box (PASSES)
- `a4 - a3 > (int)a2` → center-align element within box (PASSES)
