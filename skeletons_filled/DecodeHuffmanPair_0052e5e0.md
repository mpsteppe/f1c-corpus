## DecodeHuffmanPair_0052e5e0 — HuffmanDecodeSymbolPair

**Summary:** Decodes two Huffman-coded symbols from bitstream using lookup tables (dword_5B4788, dword_5B4820). Reads code length and value from code table, advances bit position per symbol, writes decoded 16-bit results to output array.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CompressedAudioDecoder (0052e6f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x24A4 | R | — | bitstream buffer base pointer |
| this | 0x24A8 | RW | — | current bit position in bitstream (advanced per symbol) |

**Written-by note (persistence):**
- this 0x24A8: incremented by code length per decoded symbol; external poke overwritten by each decode

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b4788 | dword_5B4788 | R | Huffman VLC decode table (indexed by code length) |
| 005b4820 | dword_5B4820 | R | Huffman hash table base offsets (indexed by code length) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** per symbol: if code length byte (from code table) is zero, symbol decodes as 0 with no bitstream advance
