## HuffmanArithmeticBitstreamSymbolDecoder_0051a87e — HuffmanArithmeticBitstreamSymbolDecoder

**Summary:** Decodes a Huffman-coded symbol from a bitstream by extracting a code word, walking the Huffman tree if needed, and returning the decoded symbol from a lookup table.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextureDecompression (0051a9c6), BitstreamDecoder (0051af57), sub_51B154 (0051b154), sub_51B45F (0051b45f)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x1C)+0x0) | 0x4 | R | — | field 4 of parent context (used in error dispatch) |
| *(*(this+0x1C)+0x0) | 0x14 | RW | 114 | vtable entry 5 of parent context, written with 114 on decode error |
| *(this+0x1C) | 0x0 | R | — | pointer to parent context struct |
| this | 0xC | RW | — | bit accumulator value (written after decode) |
| this | 0x18 | RW | — | remaining bit count (written after decode) |
| this | 0x1C | R | — | pointer to parent context |

**Written-by note (persistence):**
- *(*(this+0x1C)+0x0) 0x14: once, conditional (decode error, v12 > 16); survives external poke
- this 0xC: on every successful exit, saved accumulator; survives external poke
- this 0x18: on every successful exit, saved bit count; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0051a794 | sub_51A794 | reads bytes into bit accumulator, handling escape sequences |

**Guard conditions:** a3 >= a5 PASSES (use existing accumulator). Else calls sub_51A794; if it returns 0, BLOCKED (returns -1). If decoded code word exceeds table threshold at *(a4 + 4*a5 + 68), enters tree-walk loop consuming additional bits until v9 <= table entry. If v12 > 16 after tree walk: BLOCKED by error (writes 114 to parent vtable, calls error handler, returns 0).
