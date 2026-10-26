## COMInterfaceVectorProcessingMethod_00504b37 — Texture resize/compositing dispatch with format-specific handlers

**Summary:** Dispatches texture compositing/resizing based on pixel format ID (21–43): calls format-specific handlers (PhysicsStateDispatch, VehicleDataForwardingCall, sub_503920, sub_503A70, F_16BitTextureBlending, BitplaneBlendingCompositing, PixelBlenderCompositor, F_2xBoxDownscale, ImageBlendCombine, sub_50415C, sub_50427D, sub_5043C9). Falls through to generic float-vector 2x2 averaging path with staging buffers when format doesn't match or handler fails.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** D3DContextInit (005063a5)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | element constructor for vector init |
| 00504f3a | jpt_504C3F | R | jump table for format ID dispatch |
| 0059c496 | loc_59C496 | R | SEH jump target or exception handling label |
| 0059e7f8 | flt_59E7F8 | R | AntiRollMixingFactor [DERIVED] — float constant (0.25) for averaging |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | vector constructor for staging buffer elements |
| 00503659 | PhysicsStateDispatch | format handler for pixel type 21 |
| 005038ef | VehicleDataForwardingCall | format handler for pixel type 22 |
| 00503920 | sub_503920 | 16-bit 2x2 bilinear filter handler for format 23 |
| 00503a70 | sub_503A70 | format handler for pixel type 24 |
| 00503b94 | F_16BitTextureBlending | 16-bit texture blending handler for format 25 |
| 00503ce3 | BitplaneBlendingCompositing | bitplane compositing handler for format 26 |
| 00503e36 | PixelBlenderCompositor | 8-bit 2x2 pixel averaging handler for format 27 |
| 00503f75 | F_2xBoxDownscale | 2x box downscale handler for format 28 |
| 00504010 | ImageBlendCombine | image blend combine handler for format 29 |
| 0050415c | sub_50415C | format handler for pixel type 30 |
| 0050427d | sub_50427D | format handler for pixel type 42 |
| 005043c9 | sub_5043C9 | format handler for pixel type 43 |
| 00587bcf | FreeWrapper_7bcf | frees staging buffers |
| 00587c03 | OperatorNewNhMallocWrapper | allocates staging buffer memory |
| 0058a5d8 | SEHHandlerInit | initialises structured exception handler |

**Guard conditions:** If byte at offset 8 != 5 → returns -2147467259. If dest width != source_width>>1 (unless both 1) → returns -2147467259. If dest height != source_height>>1 (unless both 1) → returns -2147467259. If dest depth != 1 or source depth != 1 → returns -2147467259. If odd width > 1 → width adjusted down to even. If format matches a handler (21-43) and handler succeeds → returns 0. Fallback: allocates staging buffers, fails if allocation returns NULL (-2147024882).
