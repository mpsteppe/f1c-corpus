## TextureDecompression_0051a9c6 — TextureDecompression

**Summary:** Decompresses one block of texture data using Huffman-coded bitstream with run-length and distance encoding (DEFLATE-like), processing up to this->0x13C sub-blocks per call.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | saved bit accumulator (v2[5]) during state save |
| this | 0x18 | RW | — | saved read pointer during state save |
| this | 0xFC | R | — | block count passed to AudioBufferReset |
| this | 0x13C | R | — | number of sub-blocks to process this call |
| this | 0x140 | R | — | pointer to output sub-block descriptor array |
| this | 0x178 | RW | — | written during processing |
| this | 0x194 | R | — | pointer to internal decode state struct |
| this | 0x1A4 | RW | — | decode state v3[4] bit accumulator (saved/restored) |
| this | 0x1A8 | RW | — | decode state v3[5] bit count (saved/restored) |
| this | 0x1B4 | RW | — | decode state v3[8] saved intermediate value |
| this | 0x1B8 | RW | — | decode state v3[9] saved intermediate value |
| this | 0x1BC | RW | — | decode state v3[10] saved intermediate value |
| this | 0x1C0 | RW | — | decode state v3[11] saved intermediate value |
| this | 0x1C4 | R | — | decode state v3[12] remaining block count (decremented) |

**Written-by note (persistence):**
- this 0x14: on exit, saved bit accumulator; survives external poke
- this 0x18: on exit, saved write pointer; survives external poke
- this 0x178: conditional, written during sub-block processing; survives external poke
- this 0x1A4: on exit, saved bit accumulator; survives external poke
- this 0x1A8: on exit, saved bit count; survives external poke
- this 0x1B4: on exit, saved intermediate value; survives external poke
- this 0x1B8: on exit, saved intermediate value; survives external poke
- this 0x1BC: on exit, saved intermediate value; survives external poke
- this 0x1C0: on exit, saved intermediate value; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af778 | dword_5AF778 | R | ZLibDistanceTable [DERIVED] — distance/index table for LZ77-style copy |
| 005b03a0 | dword_5B03A0 | R | VQDecodeTableEntry [DERIVED] — threshold table for extra bits |
| 005b03e0 | dword_5B03E0 | R | FontGlyphTable [DERIVED] — base offset table for extra bits |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a794 | sub_51A794 | bitstream reader with escape sequence handling |
| 0051a87e | HuffmanArithmeticBitstreamSymbolDecoder | Huffman symbol decoder for code trees |
| 0051a968 | AudioBufferReset | resets audio/decode buffer state before processing |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x13C | <= | 0 | sub-block count to process |

**Guard interpretation:** this->0x13C <= 0 BLOCKS entire processing (jumps to state save/restore epilogue). Otherwise, processes each sub-block: for each, decodes Huffman-coded symbols via literal/LZ77-style run-length + distance pattern. Any sub_51A794 or HuffmanArithmeticBitstreamSymbolDecoder failure (return < 0) BLOCKS immediately with return 0.
