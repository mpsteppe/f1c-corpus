## AudioResampler_00532aa0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompressedAudioDecoder (0052e6f0), TextureDecompression_1250 (00531250)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24BC | RW | — | [LLM] |
| this | 0x24CC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24BC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b730c | unk_5B730C | R | AudioDSPTable [DERIVED] |
| 008b1924 | unk_8B1924 | R | AudioWavetableBuffer [DERIVED] |
| 008b3724 | unk_8B3724 | R | Unk_MMX_Const [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00534120 | F_3DTransformWithSIMD | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24CC | == | 2 | [LLM] |
| this | 0x24CC | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
