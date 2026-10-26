## FPSOverlayDraw_00495440 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE0 | RW | — | [LLM] |
| this | 0xE4 | RW | 0 | [LLM] |
| this | 0xE8 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0x1598 | R | — | [LLM] |
| this | 0x159C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xE0: [LLM: once/conditional? does external poke survive?]
- this 0xE4: [LLM: once/conditional? does external poke survive?]
- this 0xE8: [LLM: once/conditional? does external poke survive?]
- this 0xEC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005c3280 | aD_1 | R | ConfigParseTokenList [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00490920 | Accessor | [LLM] |
| 004918d0 | RenderSurfaceFillCopy | [LLM] |
| 004981f0 | BitmapDraw_81f0 | [LLM] |
| 004983b0 | TextRenderToSurface | [LLM] |
| 00498560 | sub_498560 | [LLM] |
| 00498730 | FloatFieldAccessor | [LLM] |
| 00587bdc | CRTFtol | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xE0 | == | 0 | [LLM] |
| this | 0x159C | != | 4129 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
