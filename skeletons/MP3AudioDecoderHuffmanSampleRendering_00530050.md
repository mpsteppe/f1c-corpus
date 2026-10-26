## MP3AudioDecoderHuffmanSampleRendering_00530050 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureDecompression_1250 (00531250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |
| this | 0x24B8 | R | — | [LLM] |
| this | 0x24CC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0053073c | jpt_5302EF | R | [LLM] |
| 005307bc | jpt_5304EA | R | [LLM] |
| 005b10a4 | flt_5B10A4 | R | DCTDecodeTable [DERIVED] |
| 005b4788 | dword_5B4788 | R | HuffmanDecodeTable [DERIVED] |
| 005da738 | dword_5DA738 | R | AnimationWeightScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24B8 | > | 0 | [LLM] |
| this | 0x24CC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
