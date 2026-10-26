## FPSOverlayDraw_00495440 — DrawFPSOverlay

**Summary:** Calculates and renders FPS overlay text on screen. Checks config array for FPS-display toggle (value 0x1021), accumulates frame delta time, computes integer FPS, formats as string, and draws via surface/bitmap operations.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | BYTE flag: FPS overlay enabled (1) / disabled (0) |
| this | 0xE4 | RW | 0 | Integer FPS value (frames per second, converted from accumulator) |
| this | 0xE8 | RW | 0 | Frame count accumulator (incremented each draw) |
| this | 0xEC | RW | 0 | Float time accumulator (accumulated delta seconds) |
| this | 0x1598 | R | — | Length of configuration WORD array at +0x159C |
| this | 0x159C | R | — | Configuration WORD array; scanned for sentinel value 0x1021 (4129) to toggle FPS display |

**Written-by note (persistence):**
- this 0xE0: toggled conditionally when 0x1021 found in config array; persists across frames
- this 0xE4: reset to 0 on toggle-off and after FPS computation; driven by frame accumulator
- this 0xE8: reset to 0 on toggle-off and after FPS computation; updated every frame while enabled
- this 0xEC: reset to 0 on toggle-off and after FPS computation; accumulates FloatFieldAccessor delta

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians constant (used by callees) |
| 005c3280 | aD_1 | R | ConfigParseTokenList (used by callees) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | Retrieve render device or surface accessor for fill operation |
| 004918d0 | RenderSurfaceFillCopy | Fill/copy rendered surface region to backbuffer |
| 004981f0 | BitmapDraw_81f0 | Draw FPS text bitmap onto render surface |
| 004983b0 | TextRenderToSurface | Render formatted FPS string to an offscreen surface |
| 00498560 | sub_498560 | Prepare/clear render surface for text rendering |
| 00498730 | FloatFieldAccessor | Get frame delta time (seconds since last frame) |
| 00587bdc | CRTFtol | Convert float FPS value to integer (floor) |
| 0058815f | StringFormatWithBufferOverflowCheck | Format integer FPS as "%d" string with bounds check |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 0 | FPS enable flag — 0 = disabled |
| this | 0x159C | != | 4129 | Config array WORD value (0x1021) — FPS toggle sentinel |

**Guard interpretation:** When 0xE0 == 0, the entire FPS calculation and rendering block is SKIPPED (BLOCKED). When config array at 0x159C contains the sentinel 0x1021, the enable flag is toggled and accumulators may be reset; when the sentinel is absent (!= 4129), no toggle occurs and prior state persists.
