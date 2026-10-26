## TextureDecompression_0051a9c6 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0xFC | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |
| this | 0x140 | R | — | [LLM] |
| this | 0x178 | RW | — | [LLM] |
| this | 0x194 | R | — | [LLM] |
| this | 0x1A4 | RW | — | [LLM] |
| this | 0x1A8 | RW | — | [LLM] |
| this | 0x1B4 | RW | — | [LLM] |
| this | 0x1B8 | RW | — | [LLM] |
| this | 0x1BC | RW | — | [LLM] |
| this | 0x1C0 | RW | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x178: [LLM: once/conditional? does external poke survive?]
- this 0x1A4: [LLM: once/conditional? does external poke survive?]
- this 0x1A8: [LLM: once/conditional? does external poke survive?]
- this 0x1B4: [LLM: once/conditional? does external poke survive?]
- this 0x1B8: [LLM: once/conditional? does external poke survive?]
- this 0x1BC: [LLM: once/conditional? does external poke survive?]
- this 0x1C0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af778 | dword_5AF778 | R | ZLibDistanceTable [DERIVED] |
| 005b03a0 | dword_5B03A0 | R | VQDecodeTableEntry [DERIVED] |
| 005b03e0 | dword_5B03E0 | R | FontGlyphTable [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a794 | sub_51A794 | [LLM] |
| 0051a87e | HuffmanArithmeticBitstreamSymbolDecoder | [LLM] |
| 0051a968 | AudioBufferReset | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x13C | <= | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
