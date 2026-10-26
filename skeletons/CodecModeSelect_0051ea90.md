## CodecModeSelect_0051ea90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| obj | 0x14 | RW | 47 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x5C | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |
| this | 0x70 | RW | — | [LLM] |
| this | 0x74 | RW | — | [LLM] |
| this | 0x1A4 | R | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |
| this | 0x1B4 | R | — | [LLM] |
| this | 0x1B8 | R | — | [LLM] |
| this | 0x1C0 | R | — | [LLM] |
| this | 0x1D4 | RW | 0 | [LLM] |
| this | 0x1D8 | R | — | [LLM] |
| this | 0x1E8 | R | — | [LLM] |
| this | 0x1F8 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- obj 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x70: [LLM: once/conditional? does external poke survive?]
- this 0x74: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1D4: [LLM: once/conditional? does external poke survive?]
- this 0x1F8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051e5d7 | TableWeightedMix | R | [LLM] |
| 0051e65f | ChecksumComputeType03Stream | R | [LLM] |
| 0051e6ec | ChecksumComputeType1 | R | [LLM] |
| 0051e7d7 | AudioSynthesis3ChannelSampleGenerator | R | [LLM] |
| 0051e8d6 | PixelDataConvolutionViaLookupTable | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005159a8 | MemoryZeroFill | [LLM] |
| 0051e3e7 | sub_51E3E7 | [LLM] |
| 0051e512 | PerIndexTableGenerationWithDivision | [LLM] |
| 0051ea5a | VirtualArrayFill | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x64 | == | 3 | [LLM] |
| this | 0x1C0 | == | 0 | [LLM] |
| this | 0x1E8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
