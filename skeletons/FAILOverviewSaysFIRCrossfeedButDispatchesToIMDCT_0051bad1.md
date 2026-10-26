## FAILOverviewSaysFIRCrossfeedButDispatchesToIMDCT_0051bad1 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x114) | 0x0 | RW | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 47 | [LLM] |
| obj | 0x18 | RW | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |
| this | 0x110 | R | — | [LLM] |
| this | 0x114 | R | — | [LLM] |
| this | 0x198 | R | — | [LLM] |
| this | 0x1C4 | RW | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x114) 0x0: [LLM: once/conditional? does external poke survive?]
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- obj 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C4: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0052804a | FixedPointIDCT | R | [LLM] |
| 0052835f | AudioFIRConvolutionFilter | R | [LLM] |
| 0052851d | AudioSampleLookup | R | [LLM] |
| 0052855a | RenderingBranchOnDAT005d79dc | R | [LLM] |
| 005285a6 | RenderModeBranch | R | [LLM] |
| 005285f2 | AudioMixing | R | [LLM] |
| 005b0508 | unk_5B0508 | R | Unk_ImageCodec [DERIVED] |
| 005b0588 | word_5B0588 | R | ImageDataBlock [DERIVED] |
| 005b05c8 | dbl_5B05C8 | R | DriverTableSource [DERIVED] (also: Source data table) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | [LLM] |
| this | 0xE8 | != | 8 | [LLM] |
| this | 0xE8 | == | 1 | [LLM] |
| this | 0xE8 | == | 2 | [LLM] |
| this | 0xE8 | == | 4 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
