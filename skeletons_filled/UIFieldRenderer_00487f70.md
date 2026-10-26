## UIFieldRenderer_00487f70 — UI field renderer with bitmap and text

**Summary:** Renders UI field with text and optional bitmap: validates label string at this+0xB0 and visibility flag at this+0xC8, selects rendering context via ShortComputation_6720/ByteFieldGetterAt100, measures text, calculates centered position using bound fields (this+0x4..0x10) and optional sub-structures at this+0x98/0x9C, then renders via BitmapDraw_81f0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x98) | 0x4 | R | — | y-offset of sub-structure 1 for centering calculation |
| *(this+0x98) | 0xC | R | — | x-offset of sub-structure 1 for centering calculation |
| *(this+0x9C) | 0x4 | R | — | y-offset of sub-structure 2 for centering calculation |
| *(this+0x9C) | 0xC | R | — | x-offset of sub-structure 2 for centering calculation |
| obj | 0x18 | R | — | rendering context field accessed via ShortComputation_6720 path selection |
| obj | 0x1C | R | — | rendering context field accessed via ShortComputation_6720 path selection |
| this | 0x0 | R | — | vtable pointer for virtual bounds queries (offsets 24, 28) |
| this | 0x4 | R | — | top bound of render area for centering |
| this | 0x8 | R | — | bottom bound of render area for centering |
| this | 0xC | R | — | left bound of render area for centering |
| this | 0x10 | R | — | right bound of render area for centering |
| this | 0x40 | R | — | base pointer for rendering operations (passed to sub_498560, TextRenderToSurface, BitmapDraw_81f0) |
| this | 0x98 | R | — | pointer to sub-structure 1 (layout/position data) |
| this | 0x9C | R | — | pointer to sub-structure 2 (alternate layout/position data) |
| this | 0xB0 | R | — | label string pointer for text rendering |
| this | 0xC8 | R | — | visibility/valid flag; if 0, renders nothing |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | default application directory string used as fallback when string fields are null |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486710 | ByteFieldGetterAt100 | retrieves UI state byte for rendering path selection |
| 00486720 | ShortComputation_6720 | computes state for rendering context selection (path 0/2 vs other) |
| 004981f0 | BitmapDraw_81f0 | renders bitmap surface to display |
| 004983b0 | TextRenderToSurface | measures/renders text to determine output dimensions |
| 00498560 | sub_498560 | sets up rendering context/surface for the field |

**Guard conditions:** strlen(this+0xB0) == 0 — returns -1 (no label text). this+0xC8 == 0 — returns 0 (invisible/disabled). After path selection, if selected string is null — returns 0. TextRenderToSurface yields v32 <= 0 or v31 <= 0 — returns 0 (zero-size text).
