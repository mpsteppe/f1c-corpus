## UILargeRenderDispatcher_00488be0 — UILargeRenderDispatcher

**Summary:** Main UI render dispatch: reads text from stored string (or defaults), determines alignment (L/C/R from first char), measures text bounds via TextRenderToSurface, auto-wraps if exceeds max width (0xE4), and renders via BitmapDraw/BitmapDrawWithAlpha/BitmapDraw_81f0 based on alignment mode at 0xE0. Returns output position rect via out-parameters.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UIRenderDispatchWrapper (00488f40), ConditionalRenderingCall (0048d6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x0 | R | — | Linked child list head (traversed for string table) |
| this | 0x4 | R | — | Render Y position top |
| this | 0x8 | R | — | Render X position left |
| this | 0xC | R | — | Render X position right |
| this | 0x10 | R | — | Render Y position bottom |
| this | 0xB0 | R | — | Stored string pointer (text to render) |
| this | 0xB8 | R | — | Linked child list pointer (for string table lookup) |
| this | 0xE0 | RW | 3 | Alignment mode: 1=Left, 2=Center, 3=Right |
| this | 0xE4 | R | — | Max width limit for text wrapping |
| this | 0xE8 | R | — | Flag: use string table lookup (binary search) |

**Written-by note (persistence):**
- this 0xE0: Written conditionally based on alignment character (C/L/R). Overwritten each render.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00423a00 | BinarySearchInStringTable | Look up text in string table for localization |
| 004980d0 | BitmapDraw | Render bitmap (default alignment) |
| 004981f0 | BitmapDraw_81f0 | Render bitmap (left alignment) |
| 004982c0 | BitmapDrawWithAlpha | Render bitmap with alpha (right alignment) |
| 004983b0 | TextRenderToSurface | Measure/render text to calculate bounding box |
| 0049a9c0 | ShortComputation_a9c0 | UI position calculation helper |
| 00587bdc | CRTFtol | Convert double to int (used for centering math) |
| 00589a35 | sub_589A35 | Get first character (alignment char extraction) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 3 | Alignment mode Right |
| this | 0xE0 | == | 2 | Alignment mode Center |
| this | 0xE4 | <= | 0 | Max width limit — zero or negative disables wrapping |

**Guard interpretation:** When 0xE4 <= 0, text is not auto-wrapped and rendered as single line. When 0xE0 is checked for 3 (Right) or 2 (Center) to select rendering path; default (1/Left) falls through to BitmapDraw_81f0.
