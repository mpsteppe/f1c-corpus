## UIScrollViewRender_00486ac0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x8 | R | — | [LLM] |
| obj | 0xC | R | — | [LLM] |
| obj | 0x10 | R | — | [LLM] |
| obj | 0x14 | R | — | [LLM] |
| obj | 0x2C | R | — | [LLM] |
| obj | 0x34 | R | — | [LLM] |
| obj | 0x88 | R | — | [LLM] |
| obj | 0xA0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x65 | R | — | [LLM] |
| this | 0x6C | RW | 0 | [LLM] |
| this | 0x78 | R | — | [LLM] |
| this | 0x84 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x6C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a68e8 | flt_5A68E8 | R | ScreenScaleFactors [DERIVED] (also: ` � screen scaling factors) |
| 005a68ec | flt_5A68EC | R | AudioMixConstant_5A68EC [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00486460 | ConditionalDelegation_6460 | [LLM] |
| 00486830 | sub_486830 | [LLM] |
| 00490920 | Accessor | [LLM] |
| 004918d0 | RenderSurfaceFillCopy | [LLM] |
| 00491960 | DualDispatchWithGuard | [LLM] |
| 00494a30 | F_10ParamForwarder | [LLM] |
| 00494a70 | F_2DScreenQuadRender | [LLM] |
| 00495110 | GlobalGetter | [LLM] |
| 00495120 | GlobalFieldReader | [LLM] |
| 00495150 | GlobalAccessor_5150 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x78 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
