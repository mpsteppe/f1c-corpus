## AudioMixerFloatingPointTo16BitPCMConversion_00531830 — [LLM: short descriptive name]

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
| 005b666c | unk_5B666C | R | AudioMixCoeffTable [DERIVED] (also: ` — coefficient table base for audio mixing) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00531b50 | F_32PointMDCTAudioTransform | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
