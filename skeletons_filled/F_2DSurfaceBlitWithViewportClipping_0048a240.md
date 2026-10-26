## F_2DSurfaceBlitWithViewportClipping_0048a240 — Surface blit with viewport clipping

**Summary:** Renders scrollable list area with viewport clipping. Computes visible rectangle from scroll position, calls ScrollbarAreaRendering and RenderSurfaceFillCopy for background, then UICustomRenderDispatch for per-item rendering within clipped bounds.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PassthroughWrapperReturns0 (0048aa00)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | this[1] — vertical start clipping boundary |
| this | 0x8 | R | — | this[2] — vertical end clipping boundary |
| this | 0x150 | R | — | this[84] — pixel scroll position for viewport offset |
| this | 0x160 | R | — | this[88] — max scroll / content height (guard: must be > 0) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | gets child widget data (index 3) for scrollbar dimensions |
| 004868c0 | ScrollbarAreaRendering | renders scrollbar track and thumb within computed area |
| 00487060 | sub_487060 | computes horizontal position offset for rendering |
| 004870e0 | sub_4870E0 | computes vertical position offset for rendering |
| 00489fd0 | UICustomRenderDispatch | dispatches per-item custom rendering within clipped viewport |
| 00490920 | Accessor | gets surface handle for pixel copy |
| 004918d0 | RenderSurfaceFillCopy | copies surface pixels to screen within rect |

**Guard conditions:** this[0x160] (max scroll/content height) must be > 0 AND ConditionalDelegation_6460 must return non-null to compute scrollbar area and surface blit. If guard fails, UICustomRenderDispatch still runs with default 800x600 rectangle.
