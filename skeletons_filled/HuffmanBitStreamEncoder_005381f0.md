## HuffmanBitStreamEncoder_005381f0 — Deflate Huffman bitstream encoder

**Summary:** Encodes deflate symbols into Huffman-coded bitstream. Manages dynamic Huffman tree construction via sub_5383D0, writes symbols using bit-packing buffer (a1+5803/5805), calls BitstreamWriteBits and BitBufferWriter for output, and flushes via ScorecardZero. Core entropy coding stage for deflate compression.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DecompressionBufferFlush (00536300), ZlibInflateDecompressionCore (005365d0), InflateDecompressionLoop (00536a70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b7e00 | unk_5B7E00 | R | ZlibTreeTable [DERIVED] |
| 005b8280 | unk_5B8280 | R | InflateState_5B8280 [DERIVED] — static inflate state for fixed Huffman tree |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00537ec0 | ScorecardZero | zero out frequency/cost accumulators for next block |
| 00537f30 | BitstreamWriteBits | write raw bits to output bitstream |
| 005383d0 | sub_5383D0 | build dynamic Huffman tree from frequency table |
| 00538940 | PerformanceSectorTimeAccumulator | accumulate bit cost for length/distance tree optimization |
| 00538a90 | BitBufferWriter | flush buffered bits to output byte stream |
| 00539200 | HuffmanBitStreamDecoder | generate Huffman code table from tree (reverse code assignment) |
| 00539600 | BufferChecksumValidator | validate/update buffer checksum |
| 00539720 | UnicodeBufferFlusher | final flush of output buffer |

**Guard conditions:** When a1+122 (block counter) <= 0, skips Huffman tree rebuild entirely. When a1+28 (block type) == 2 (compressed), validates checksum via BufferChecksumValidator before tree build. Condition at line 43: when a3+4 <= v7 and a2 is set, writes symbol directly via BitstreamWriteBits; otherwise, encodes via Huffman (packed bit buffer) with separate code paths for last block (v8==v7, uses HuffmanBitStreamDecoder with unk_5B8280) vs middle blocks (uses HuffmanBitStreamDecoder with a1+2430 dynamic tree).
