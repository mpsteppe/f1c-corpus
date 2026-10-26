## HuffmanTreeAlloc_0051ba70 — HuffmanTreeAlloc

**Summary:** Allocates Huffman tree context (80 bytes) with vtable method sub_51B7CD, plus a flat table buffer (count * 256 bytes) initialized to -1/0xFF.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (allocation function) |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x20 | R | — | number of Huffman tree slots (each 256 bytes) |
| this | 0x8C | RW | — | written with pointer to flat 256-byte-per-slot Huffman table |
| this | 0x194 | RW | — | written with pointer to allocated 80-byte context |

**Written-by note (persistence):**
- this 0x8C: once, unconditional; survives external poke
- this 0x194: once, unconditional; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051b7cd | sub_51B7CD | R | vtable entry 0 (Huffman tree method) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | <= | 0 | Huffman tree slot count |

**Guard interpretation:** this->0x20 <= 0 BLOCKS the memset initialization loop (skip filling tree blocks with 0xFF).
