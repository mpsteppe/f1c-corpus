## ZlibInflateDecompressionCore_005365d0 — Deflate block compression core

**Summary:** Core deflate compression loop. Manages hash table for LZ77 matching, encodes literals and length/distance pairs, writes to output buffers, and flushes via HuffmanBitStreamEncoder when buffers are full. Uses Zlib lookup tables (byte_5B82F8, byte_5B83F8, byte_5B84F8) for length/distance encoding. Main compression state machine for deflate streams.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b82f8 | byte_5B82F8 | R | Zlib_DistanceBaseTable [DERIVED] — distance base value lookup for deflate encoding |
| 005b83f8 | byte_5B83F8 | R | zlib_LengthExtraBits [DERIVED] — extra bit count for length codes |
| 005b84f8 | byte_5B84F8 | R | ZLibLengthTable [DERIVED] — length code base value lookup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00536160 | BufferCopyWithSizeTracking | copy compressed output buffer to output stream, track bytes written |
| 00536440 | TextBufferDecompressor | refill input buffer when insufficient bytes available |
| 00536900 | ZlibDeflateLongestMatch | find longest LZ77 match in hash chain |
| 005381f0 | HuffmanBitStreamEncoder | flush buffered symbols as Huffman-coded bitstream |

**Guard conditions:** Checks available bytes at a1+106 (0x6A). If < 0x106 (262), calls TextBufferDecompressor to refill; if still < 262 and a2==0 (no flush), returns 0 (need more input). If available bytes == 0, breaks loop. When match length at a1+86 >= 3 and within window, encodes length/distance pair using lookup tables; otherwise encodes single literal byte. Buffer flush triggered when output index (a1+5779) reaches capacity (a1+5775 - 1). Loop ends when available bytes exhausted; final flush calls HuffmanBitStreamEncoder + BufferCopyWithSizeTracking.
