## F_2DTextRenderingWithScissorRectangle_0049b370 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_49F870 (0049f870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |

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
| 0049b200 | RandomColorGenerator | [LLM] |
| 004dcd60 | ConditionalCall | [LLM] |
| 004dcd80 | TwoFieldSetterUpdate | [LLM] |
| 004dcdd0 | PositionComputationWithAlignment | [LLM] |
| 004dcf20 | FieldSetterCall_cf20 | [LLM] |
| 00552fc0 | FieldSetterAt0x48 | [LLM] |
| 00553070 | sub_553070 | [LLM] |
| 005531f0 | sub_5531F0 | [LLM] |
| 00553a20 | FloatToIntConversionChain | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
