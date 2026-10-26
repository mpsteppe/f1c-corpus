## HuffmanBitStreamDecoder_00539200 — Deflate symbol-to-bitstream encoder

**Summary:** Encodes buffered literal/length/distance symbols into Huffman-coded bitstream. Iterates through pending symbols from output buffer (a1+5771, a1+5783), writes Huffman codes for literals, lengths, and distances using bit-packing with overflow-to-byte flushing. Applies Zlib lookup tables (byte_5B82F8, byte_5B83F8, byte_5B84F8) for length/distance base values and extra bits. Finalizes with end-of-block code.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HuffmanBitStreamEncoder (005381f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x400 | R | — | length code base value at a2+1024 (end-of-block code word) |
| this | 0x402 | R | — | length code bit count at a2+1026 (end-of-block code length) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b7cb0 | dword_5B7CB0 | R | AILookupTableInt [DERIVED] — extra length bits count lookup |
| 005b7d28 | dword_5B7D28 | R | FontGlyphData [DERIVED] — extra distance bits count lookup |
| 005b82f8 | byte_5B82F8 | R | Zlib_DistanceBaseTable [DERIVED] — distance base value for short matches |
| 005b83f8 | byte_5B83F8 | R | zlib_LengthExtraBits [DERIVED] — distance base value for long matches |
| 005b84f8 | byte_5B84F8 | R | ZLibLengthTable [DERIVED] — length code base value lookup |
| 005b85f8 | dword_5B85F8 | R | ImageDecompressConst [DERIVED] — extra length bits offset |
| 005b8670 | dword_5B8670 | R | AudioCodec_5B8670 [DERIVED] — extra distance bits offset |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Loop only runs when a1+5779 (pending symbol count) > 0. For each symbol: if word at a1+5783[v4] is non-zero, encodes length+match (length Huffman code, extra length bits if any, distance Huffman code, extra distance bits if any). If zero, encodes literal Huffman code. Bit buffer overflow (bits > 16) triggers byte-by-byte flush to output buffer at a1+8, a1+20. After symbol loop, always writes end-of-block code from a2+1024/1026.
