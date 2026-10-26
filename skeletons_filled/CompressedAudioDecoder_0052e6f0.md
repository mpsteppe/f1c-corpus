## CompressedAudioDecoder_0052e6f0 — Compressed audio frame decoder

**Summary:** Decodes one frame of compressed audio from bitstream buffer. Reads nibble-coded codebook selectors, decodes Huffman-coded VQ indices, dequantizes to float samples, resamples to output rate, and converts to 16-bit PCM. Core MP3/ADPCM-style audio decoding pipeline.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_52DF10 (0052df10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | input bitstream buffer pointer (this[2345]) |
| this | 0x24A8 | RW | — | bitstream bit-offset cursor (this[2346]), advances per read |
| this | 0x24CC | R | — | audio mode/channel config (this[2355]), compared to 2 |
| this | 0x24D0 | R | — | output sample stride / channel count (this[2356]), used as address multiplier |

**Written-by note (persistence):**
- this 0x24A8: updated each bit read; cursor advances through input bitstream

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
| 008b0108 | dword_8B0108 | R | AudioCodecInitFlag [DERIVED] — codec initialized flag |
| 008b0124 | dword_8B0124 | R | AudioDecodeWorkspace [DERIVED] — decoded sample workspace (32 floats) |
| 008b0224 | dword_8B0224 | R | VQDecodeWorkspace [DERIVED] — VLC decoded values workspace |
| 008b0324 | unk_8B0324 | R | CodebookSelectorArray [DERIVED] — codebook selector array (32 entries) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052e5e0 | DecodeHuffmanPair | decode one Huffman-coded symbol pair from bitstream |
| 00531830 | AudioMixerFloatingPointTo16BitPCMConversion | convert float sample buffer to 16-bit PCM output |
| 00532aa0 | AudioResampler | resample decoded audio to target output rate |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x24CC | == | 2 | audio mode selector (this[2355]) |

**Guard interpretation:** Early return -1 when this[2345] (input buffer pointer at +0x24A4) is NULL. When dword_8B0108 (codec init flag) is zero, takes software decode path using unk_8B0324 & dword_8B0124 globals directly. When nonzero, reads nibble selectors from bitstream then decodes. Within each path, this[2355] == 2 selects 256-byte frame with 32-codebook-entry decode (DecodeHuffmanPair loop + 12 resampler passes); this[2355] != 2 selects 128-byte frame with direct VQ decode + 12 resampler passes.
