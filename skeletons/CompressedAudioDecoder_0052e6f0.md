## CompressedAudioDecoder_0052e6f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_52DF10 (0052df10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |
| this | 0x24CC | R | — | [LLM] |
| this | 0x24D0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b11a4 | flt_5B11A4 | R | TextureColorFloat [DERIVED] |
| 005b2ba4 | unk_5B2BA4 | R | VideoCodec_DataTable [DERIVED] |
| 005b2ca4 | dword_5B2CA4 | R | AudioCodecState [DERIVED] |
| 005b4788 | dword_5B4788 | R | HuffmanDecodeTable [DERIVED] |
| 005b4798 | dword_5B4798 | R | ZBufferState [DERIVED] |
| 005b47a0 | dword_5B47A0 | R | ZLibBitCountTable [DERIVED] |
| 005b47a8 | dword_5B47A8 | R | TexDecodeConstant [DERIVED] |
| 005b4820 | dword_5B4820 | R | HashTableMask [DERIVED] |
| 008b0108 | dword_8B0108 | R | AudioCodecInitFlag [DERIVED] (also: ` — codec initialized flag) |
| 008b0124 | dword_8B0124 | R | AudioDecodeWorkspace [DERIVED] (also: ` — decoded sample workspace (32 floats) |
| 008b0224 | dword_8B0224 | R | VQDecodeWorkspace [DERIVED] (also: ` — VLC decoded values workspace) |
| 008b0324 | unk_8B0324 | R | CodebookSelectorArray [DERIVED] (also: ` — codebook selector array (32 entries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052e5e0 | DecodeHuffmanPair | [LLM] |
| 00531830 | AudioMixerFloatingPointTo16BitPCMConversion | [LLM] |
| 00532aa0 | AudioResampler | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24CC | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
