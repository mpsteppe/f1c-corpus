## HuffmanCtxAlloc_0051aec2 — HuffmanCtxAlloc

**Summary:** Allocates a Huffman decode context (88 bytes), sets vtable methods to ArrayProcessingWithValidation and TextureDecompression, and zeros internal state slots.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_516C7B (00516c7b)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x4) | 0x0 | R | — | sub-allocator vtable entry 0 (allocation function) |
| this | 0x4 | R | — | sub-allocator vtable pointer |
| this | 0x194 | RW | — | written with pointer to allocated 88-byte context |

**Written-by note (persistence):**
- this 0x194: once, unconditional; survives external poke

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0051a9c6 | TextureDecompression | R | vtable entry 1 (texture decode method) |
| 0051ad93 | ArrayProcessingWithValidation | R | vtable entry 0 (array validation + processing method) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** unconditional allocation and initialization.
