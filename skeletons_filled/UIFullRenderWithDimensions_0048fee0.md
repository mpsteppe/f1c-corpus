## UIFullRenderWithDimensions_0048fee0 — UIFullRenderWithDimensions

**Summary:** Full UI render function that positions and draws text/bitmap content with clipping against viewport bounds. Reads rendering dimensions, string resource, and mode flag to select between different draw paths. Updates output position pointers.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB0 | R | — | String pointer (or default directory path) |
| this | 0xE4 | R | — | Render mode flag (0=full draw, 1=top draw, 2=bottom draw) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | Default directory/fallback path string |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004862c0 | UIStringAccessor_62c0 | Retrieves UI string resource |
| 00487060 | sub_487060 | Gets dimension/position value (mode parameter) |
| 004870e0 | sub_4870E0 | Gets another dimension/position value (mode parameter) |
| 004980d0 | BitmapDraw | Draws bitmap with specified source/dest rect |
| 004981f0 | BitmapDraw_81f0 | Draws bitmap with clipping (alternate variant) |
| 004983b0 | TextRenderToSurface | Renders text string to surface with alignment |
| 00498560 | sub_498560 | Unknown string/UI processing |

**Guard conditions:** Checks string at `this[44]` (offset 0xB0) — if null, uses default `byte_5EA438`. Checks `strlen(v6)` — BLOCKED (returns 0) if empty. Checks `this[57]` (offset 0xE4) value: 0 → draws full region via BitmapDraw_81f0, 1 → draws top region via BitmapDraw, 2 → draws bottom region via BitmapDraw_81f0, other values → BLOCKED (returns 0).
