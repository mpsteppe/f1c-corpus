## InitViewportDimensions_00498740 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CarCrashDamageProcessing (00496030), UILargeRender (00496930)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5C | RW | — | [LLM] |
| this | 0x60 | RW | — | [LLM] |
| this | 0x64 | RW | — | [LLM] |
| this | 0x68 | RW | — | [LLM] |
| this | 0x6C | RW | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x5C: [LLM: once/conditional? does external poke survive?]
- this 0x60: [LLM: once/conditional? does external poke survive?]
- this 0x64: [LLM: once/conditional? does external poke survive?]
- this 0x68: [LLM: once/conditional? does external poke survive?]
- this 0x6C: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e9b0 | dbl_59E9B0 | R | Rad2DegOrTimerMult [DERIVED] (also: ` — conversion multiplier) |
| 005ac9d8 | dbl_5AC9D8 | R | InitFloatValue [DERIVED] |
| 007cb24c | dword_7CB24C | R | Unknown_RenderState_B24C [DERIVED] |
| 007cb274 | flt_7CB274 | R | UITextColor [DERIVED] |
| 007cb278 | flt_7CB278 | R | FontRendererConfig [DERIVED] |
| 007cb2fc | dword_7CB2FC | R | SCREEN_WIDTH [DERIVED] |
| 007cb300 | dword_7CB300 | R | UIScrollAccel [DERIVED] |
| 007cb304 | dword_7CB304 | R | InitConst_7CB304 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0044f7d0 | ContactFlagReadClear | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
