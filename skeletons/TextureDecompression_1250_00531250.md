## TextureDecompression_1250_00531250 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_52DF10 (0052df10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | [LLM] |
| this | 0x24A8 | RW | — | [LLM] |
| this | 0x24B8 | RW | — | [LLM] |
| this | 0x24BE | R | — | [LLM] |
| this | 0x24C3 | R | — | [LLM] |
| this | 0x24C4 | R | — | [LLM] |
| this | 0x24CC | R | — | [LLM] |
| this | 0x24D0 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x24A8: [LLM: once/conditional? does external poke survive?]
- this 0x24B8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b2ba4 | unk_5B2BA4 | R | VideoCodec_DataTable [DERIVED] |
| 005b4788 | dword_5B4788 | R | HuffmanDecodeTable [DERIVED] |
| 005b4790 | dword_5B4790 | R | Unknown_DWord_5B4790 [DERIVED] |
| 005b47a0 | dword_5B47A0 | R | ZLibBitCountTable [DERIVED] |
| 005b47b8 | dword_5B47B8 | R | AudioDecodeBitTable [DERIVED] |
| 005b47d0 | dword_5B47D0 | R | VLCBitstreamTable [DERIVED] |
| 005b65e0 | byte_5B65E0 | R | DXT_DecompressTable [DERIVED] |
| 005b6620 | word_5B6620 | R | Word_HuffmanTable [DERIVED] |
| 005da760 | off_5DA760 | R | AudioDecodeJumpTable [DERIVED] |
| 008b0108 | dword_8B0108 | R | AudioCodecInitFlag [DERIVED] (also: ` — codec initialized flag) |
| 008b0424 | unk_8B0424 | R | GIF_DecompTable [DERIVED] |
| 008b04a4 | unk_8B04A4 | R | AudioCodecTable [DERIVED] |
| 008b1624 | dword_8B1624 | R | CodecDecodeWorkspace [DERIVED] |
| 008b16a4 | byte_8B16A4 | R | AudioDecodeTable [DERIVED] |
| 008b1724 | unk_8B1724 | R | AudioDecoderWorkspace [DERIVED] |
| 008b1824 | unk_8B1824 | R | Unk_BitReader [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00530050 | MP3AudioDecoderHuffmanSampleRendering | [LLM] |
| 00530840 | sub_530840 | [LLM] |
| 00531830 | AudioMixerFloatingPointTo16BitPCMConversion | [LLM] |
| 00532aa0 | AudioResampler | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
