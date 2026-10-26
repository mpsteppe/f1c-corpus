## UITextBoxRendererWithScrollbar_004883d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x18 | R | — | [LLM] |
| obj | 0x1C | R | — | [LLM] |
| obj | 0x20 | R | — | [LLM] |
| obj | 0x24 | R | — | [LLM] |
| obj | 0xAC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0xB0 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xE0 | R | — | [LLM] |
| this | 0xE4 | RW | — | [LLM] |
| this | 0xE8 | RW | — | [LLM] |
| this | 0xEC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]

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
| 004862c0 | UIStringAccessor_62c0 | [LLM] |
| 004862e0 | UIStringAccessor_62e0 | [LLM] |
| 00486460 | ConditionalDelegation_6460 | [LLM] |
| 00487060 | sub_487060 | [LLM] |
| 004870e0 | sub_4870E0 | [LLM] |
| 00487160 | UtilityFunction_7160 | [LLM] |
| 00494a30 | F_10ParamForwarder | [LLM] |
| 00495150 | GlobalAccessor_5150 | [LLM] |
| 004980d0 | BitmapDraw | [LLM] |
| 004981f0 | BitmapDraw_81f0 | [LLM] |
| 004982c0 | BitmapDrawWithAlpha | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
