## TextureDecompression_1250_00531250 — Audio frame decompression dispatcher

**Summary:** Decodes one frame of compressed audio: reads Huffman codebook header, decodes codebook selectors and delta-coded side information from bitstream, then dispatches to either hardware-accelerated (sub_530840 + AudioResampler) or software (MP3AudioDecoderHuffmanSampleRendering + AudioMixerFloatingPointTo16BitPCMConversion) decode path based on dword_8B0108 flag. Audio codec entry point for frame decompression.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_52DF10 (0052df10)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | input bitstream buffer pointer (this+9380) |
| this | 0x24A8 | RW | — | bitstream bit-offset cursor (this+9384), advances per read |
| this | 0x24B8 | RW | — | codebook entry count (this+9400), initialized from word_5B6620 lookup |
| this | 0x24BE | R | — | channel mode flag (this+9406), selects 4 or table-based entry count |
| this | 0x24C3 | R | — | codec config byte 0 (this+9411) |
| this | 0x24C4 | R | — | codec config byte 1 (this+9412) |
| this | 0x24CC | R | — | stereo flag / channel mode (this+9420), ==2 for stereo (indexing *2) |
| this | 0x24D0 | R | — | output stride / sample count (this+9424) |

**Written-by note (persistence):**
- this 0x24A8: updated per bit read; cursor advances through input bitstream
- this 0x24B8: written once per frame from word_5B6620 table lookup (codebook entry count)

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
| 008b0108 | dword_8B0108 | R | AudioCodecInitFlag [DERIVED] — codec initialized flag |
| 008b0424 | unk_8B0424 | R | GIF_DecompTable [DERIVED] |
| 008b04a4 | unk_8B04A4 | R | AudioCodecTable [DERIVED] |
| 008b1624 | dword_8B1624 | R | CodecDecodeWorkspace [DERIVED] |
| 008b16a4 | byte_8B16A4 | R | AudioDecodeTable [DERIVED] |
| 008b1724 | unk_8B1724 | R | AudioDecoderWorkspace [DERIVED] |
| 008b1824 | unk_8B1824 | R | Unk_BitReader [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00530050 | MP3AudioDecoderHuffmanSampleRendering | software path: render Huffman-decoded samples to float buffer |
| 00530840 | sub_530840 | accel path: render Huffman-decoded samples to word buffer with scale table |
| 00531830 | AudioMixerFloatingPointTo16BitPCMConversion | convert float sample buffer to 16-bit PCM output |
| 00532aa0 | AudioResampler | resample decoded audio to target output rate |

**Guard conditions:** Early return 0 when this[0x24A4] (input buffer pointer at this+9380) is NULL. When dword_8B0108 (codec init flag) is nonzero, takes HW-accelerated path: calls sub_530840 to render samples then AudioResampler (3 channels × 12 blocks). When zero, takes software path: calls MP3AudioDecoderHuffmanSampleRendering then AudioMixerFloatingPointTo16BitPCMConversion (3 output buffers × 12 iterations).
