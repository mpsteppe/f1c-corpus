## F_2DTextRenderingWithScissorRectangle_0049b370 — ScissoredTextRenderWithColorHighlight

**Summary:** Renders 2D text within a scissored rectangle region. Computes scaled text position from input dimensions, calls a chain of FloatToIntConversionChain calls, renders a background widget if UI flag is set, renders text via FieldSetter calls, and conditionally draws a time-based color highlight bar if feature flags are enabled.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | X center position for text layout |
| this | 0xC | R | — | Y offset for text position computation |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059ee8c | flt_59EE8C | R | QualityThresholdHigh [DERIVED] |
| 007ce23c | dword_7CE23C | R | UIRenderFlags [DERIVED] |
| 007ce240 | dword_7CE240 | R | UIDrawDetailFlag [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b200 | RandomColorGenerator | Generates highlight color from time-based oscillation |
| 004dcd60 | ConditionalCall | Widget render dispatch (background) |
| 004dcd80 | TwoFieldSetterUpdate | Updates render state fields |
| 004dcdd0 | PositionComputationWithAlignment | Computes widget alignment position |
| 004dcf20 | FieldSetterCall_cf20 | Sets text color field |
| 00552fc0 | FieldSetterAt0x48 | Sets render state field at offset 0x48 |
| 00553070 | sub_553070 | Text rendering call with position and device |
| 005531f0 | sub_5531F0 | Computes text dimensions from string |
| 00553a20 | FloatToIntConversionChain | Converts float positions to fixed-point |
| 00587bdc | CRTFtol | Float-to-int conversion for position scaling |

**Guard conditions:** If computed text width (v8) <= 0 or height (result) <= 0 → BLOCKED: early return. If dword_7CE23C[0] is nonzero → PASSES to background widget render. If a6 is nonzero AND dword_7CE240 is nonzero → PASSES to color highlight render via RandomColorGenerator.
