## BitstreamDecoder_0051af57 — BitstreamDecoder

**Summary:** Decodes one block of bitstream data by reading Huffman-coded symbols from sub-blocks, applying extra bits from tables, and writing shifted results to output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | — | saved read pointer state |
| this | 0x18 | RW | — | saved write/output pointer state |
| this | 0xFC | R | — | block count flag (checked for zero to conditionally reset) |
| this | 0x13C | R | — | number of sub-blocks to process this call |
| this | 0x140 | R | — | pointer to output sub-block descriptor array |
| this | 0x174 | R | — | shift value applied to decoded output |
| this | 0x178 | RW | — | written during sub-block processing |
| this | 0x194 | R | — | pointer to internal decode state struct |
| this | 0x1A4 | RW | — | decode state v4[4] bit accumulator (saved/restored) |
| this | 0x1A8 | RW | — | decode state v4[5] bit count (saved/restored) |
| this | 0x1C8 | R | — | decode state v4[13] remaining block count (decremented) |

**Written-by note (persistence):**
- this 0x14: on exit, saved read pointer; survives external poke
- this 0x18: on exit, saved write pointer; survives external poke
- this 0x178: conditional, written per sub-block; survives external poke
- this 0x1A4: on exit, saved bit accumulator; survives external poke
- this 0x1A8: on exit, saved bit count; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b0488 | dword_5B0488 | R | JpegHuffmanTable_5B0488 [DERIVED] — extra bits threshold table |
| 005b04c8 | dword_5B04C8 | R | HuffmanTree_5B04C8 [DERIVED] — extra bits base offset table |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a794 | sub_51A794 | bitstream reader with escape sequence handling |
| 0051a87e | HuffmanArithmeticBitstreamSymbolDecoder | Huffman symbol decoder for code trees |
| 0051aefc | CounterUpdateWithZero | resets counter state before processing if needed |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xFC | == | 0 | block count flag |
| this | 0x13C | <= | 0 | sub-block count |

**Guard interpretation:** this->0xFC == 0 BLOCKS CounterUpdateWithZero call (skip reset). this->0x13C <= 0 BLOCKS entire processing loop (jump to epilogue). Each sub-block: if bit count < 8, calls sub_51A794; if that returns 0, BLOCKED (return 0). HuffmanArithmeticBitstreamSymbolDecoder returning < 0 also BLOCKED immediately.
