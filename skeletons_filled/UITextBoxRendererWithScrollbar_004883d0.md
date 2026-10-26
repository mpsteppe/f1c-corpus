## UITextBoxRendererWithScrollbar_004883d0 — UITextBoxRendererWithScrollbar

**Summary:** Renders a scrollable UI text box widget with optional scrollbar, drawing up to two text strings (header at this+0xB0, body at this+0xB8) and supporting bitmap overlays. Computes an output bounding rectangle (a2=left, a3=right, a4=top, a5=bottom) that encompasses all rendered content.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | sub-object surface/rendering context handle (from ConditionalDelegation_6460 result, used as rendering base) |
| obj | 0x1C | R | — | sub-object content X origin (horizontal offset for content area) |
| obj | 0x20 | R | — | sub-object texture/surface handle (dereferenced from v6[8]+12 for rendering) |
| obj | 0x24 | R | — | sub-object content height/width dimension (v6[3]-v6[2], vertical extent of content) |
| obj | 0xAC | R | — | vtable method at offset 0xAC, called unconditionally between content and scrollbar rendering (likely cleanup/state flush) |
| this | 0x0 | R | — | vtable pointer; used to call virtual methods at +24, +28, +32, +36, +172 |
| this | 0x4 | R | — | left/top Y coordinate (this[1]), used as content region boundary |
| this | 0xC | R | — | X coordinate (this[3]), start of content area |
| this | 0x10 | R | — | X coordinate (this[4]), end of content area |
| this | 0xB0 | R | — | pointer to first UI text string (header/title); falls back to byte_5EA438 if null |
| this | 0xB8 | R | — | pointer to second UI text string (body text); falls back to byte_5EA438 if null |
| this | 0xE0 | R | — | current scroll position (this[56]), used to compute scrollbar state |
| this | 0xE4 | RW | — | scrollbar thumb top position, computed from scroll position and content proportions |
| this | 0xE8 | RW | — | scrollbar thumb height/size, computed from visible-to-total ratio |
| this | 0xEC | R | — | byte flag at this+236: indicates whether scrollbar sub-widget is present (gates scrollbar rendering path) |

**Written-by note (persistence):**
- this 0xE4: written once per frame during scrollbar computation; external pokes persist until next frame render
- this 0xE8: written once per frame during scrollbar computation; external pokes persist until next frame render

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004862c0 | UIStringAccessor_62c0 | gets the first text content string from the widget (header/title string accessor) |
| 004862e0 | UIStringAccessor_62e0 | gets the second text content string from the widget (body text string accessor) |
| 00486460 | ConditionalDelegation_6460 | returns a delegated sub-object for rendering: param 1 = content area, param 2 = scrollbar |
| 00487060 | sub_487060 | returns a horizontal coordinate for bitmap overlay positioning (param 5 or 2 for different UI states) |
| 004870e0 | sub_4870E0 | returns a vertical coordinate for bitmap overlay positioning |
| 00487160 | UtilityFunction_7160 | checks UI state and retrieves rendering coordinates; param 3/4 selects output registers |
| 00494a30 | F_10ParamForwarder | forwards 10 parameters to delegated sub-object renderer |
| 00495150 | GlobalAccessor_5150 | retrieves a global rendering surface/handle from unk_7CDE00 |
| 004980d0 | BitmapDraw | draws a bitmap at specified coordinates (simple blit) |
| 004981f0 | BitmapDraw_81f0 | draws a bitmap with stretching/scaling variant |
| 004982c0 | BitmapDrawWithAlpha | draws a bitmap with alpha blending support |
| 004983b0 | TextRenderToSurface | renders text to a surface; returns text width/height via &v81, &v82 |
| 00498560 | sub_498560 | text preparation/initialization before rendering |
| 00587bdc | CRTFtol | converts floating-point to integer (CRT truncation) |

**Guard conditions:** Content rendering proceeds only if ConditionalDelegation_6460(this, 1) returns non-null. Scrollbar elements are drawn only when v7 > 0 (computed scroll position positive). The byte flag at this+0xEC (byte at this+236) determines whether a scrollbar sub-widget exists, gating both scrollbar rendering and text rendering path choice. First text block (this+0xB0) and second text block (this+0xB8) are gated by strlen > 0; null pointers fall back to byte_5EA438. The UtilityFunction_7160 return value at the second text block chooses between BitmapDraw (true) and BitmapDraw_81f0 (false) rendering paths. sub_487060 return >= 0 selects BitmapDrawWithAlpha, else BitmapDraw_81f0 for the first text block overlay.
