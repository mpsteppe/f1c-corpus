## UIScrollViewRender_00486ac0 — UIScrollViewRender

**Summary:** Renders a scrollable UI view with optional screen-scale correction, clipping to parent bounds. Handles dirty-flag invalidation, iterates child scroll items to compute visible region, and dispatches either a direct 2D quad render or a scaled corrected render path.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | vtable function pointer slot (offset 8/20: dirty-check callback) |
| obj | 0xC | R | — | vtable function pointer slot (offset 12/16: clip-region setter) |
| obj | 0x10 | R | — | vtable function pointer at offset 16 |
| obj | 0x14 | R | — | vtable function pointer slot (offset 20: dirtiness query) |
| obj | 0x2C | R | — | child-object pointer at offset 0x2C from the child list head |
| obj | 0x34 | R | — | child count or list-position index |
| obj | 0x88 | R | — | scroll content object pointer: x/y/width/height of scrollable content |
| obj | 0xA0 | R | — | vtable dispatch at offset 0xA0 (136): clip-transform setup |
| this | 0x0 | R | — | vtable pointer (used for virtual dispatch: dtor, draw, clip, etc.) |
| this | 0x4 | R | — | parent x-coordinate (bounds left) |
| this | 0xC | R | — | parent width (from bounds struct) |
| this | 0x40 | R | — | cached width after screen-scale transform |
| this | 0x65 | R | — | dirty/invalidation flag (byte): triggers re-render when non-zero |
| this | 0x6C | RW | 0 | dirty-flag clear byte: set to 0 after invalidation handled (line 58) |
| this | 0x78 | R | — | scroll mode flag: 2 = use GlobalGetter for texture source, else GlobalAccessor_5150 |
| this | 0x84 | R | — | scroll offset X (used to index into child list) |
| this | 0x88 | R | — | scroll offset Y (used to index into child list) |

**Written-by note (persistence):**
- this 0x6C: cleared to 0 once per render pass (after dirty-flag check); external poke overwritten each time dirty flag is set

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a68e8 | flt_5A68E8 | R | ScreenScaleFactors [DERIVED] (also: ` � screen scaling factors) |
| 005a68ec | flt_5A68EC | R | AudioMixConstant_5A68EC [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | navigate child-list by index to find scroll-item at position |
| 00486830 | sub_486830 | query scroll view state (returns 0–3; 1=fill-copy path, 2–3=dual-dispatch path) |
| 00490920 | Accessor | retrieve render target / surface handle |
| 004918d0 | RenderSurfaceFillCopy | fill-copy render: blit region on surface (used for scroll mode 0–1) |
| 00491960 | DualDispatchWithGuard | dual-dispatch render: scissor+blit with guard check (used for scroll mode 2–3) |
| 00494a30 | F_10ParamForwarder | forward 10 parameters to a 2D render call (non-scaled path) |
| 00494a70 | F_2DScreenQuadRender | render a 2D textured quad with screen-scale correction applied |
| 00495110 | GlobalGetter | get global texture/surface by index (used in scroll mode 2) |
| 00495120 | GlobalFieldReader | read two global fields for screen-scale factors |
| 00495150 | GlobalAccessor_5150 | access global render data structure (default texture source) |
| 00587bdc | CRTFtol | CRT float-to-long truncation (used for pixel coordinate conversion) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x78 | == | 2 | scroll texture source: 2 = use GlobalGetter (alternate texture), else GlobalAccessor_5150 (default) |

**Guard interpretation:** When scroll mode (0x78) equals 2, the renderer switches to an alternate global texture source via GlobalGetter and sets v34=1 to skip RenderSurfaceFillCopy/DualDispatchWithGuard (those paths are only taken when v34==0, i.e., the default texture source). When mode != 2, the default GlobalAccessor_5150 path is used and surface rendering proceeds normally.
