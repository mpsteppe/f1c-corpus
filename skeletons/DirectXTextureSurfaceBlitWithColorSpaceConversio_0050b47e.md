## DirectXTextureSurfaceBlitWithColorSpaceConversio_0050b47e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x10) | 0x0 | RW | — | [LLM] |
| *(this+0x10) | 0x4 | RW | — | [LLM] |
| *(this+0x10) | 0x8 | R | — | [LLM] |
| *(this+0x10) | 0xC | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x10) 0x0: [LLM: once/conditional? does external poke survive?]
- *(this+0x10) 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005007ec | sub_5007EC | R | [LLM] |
| 0059c58c | loc_59C58C | R | [LLM] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005accd0 | flt_5ACCD0 | R | RGBChannelScaleR [DERIVED] (also: ` — R/B channel scale factor (fixed-point multiplier) |
| 005accd4 | flt_5ACCD4 | R | ChannelDecodeScale [DERIVED] (also: ` — Float scale factor for 5/6-bit channel decoding) |
| 005accd8 | flt_5ACCD8 | R | DXT_GreenChannelScale [DERIVED] (also: ` — G channel scale factor (different precision) |
| 005accdc | flt_5ACCDC | R | AlphaChannelScale [DERIVED] (also: ` — alpha channel scale factor) |
| 008b009c | dword_8B009C | R | ConversionState [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005008c2 | sub_5008C2 | [LLM] |
| 00507473 | UtilityFunction_7473 | [LLM] |
| 00587c03 | OperatorNewNhMallocWrapper | [LLM] |
| 0058a5d8 | SEHHandlerInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
