## sub_510ACC_00510acc — JPEG Huffman table parser

**Summary:** Parses JPEG Huffman table definitions (DHT marker) from a byte stream. Reads a 16-byte symbol-count header, validates sizes, reads symbol values, and stores the complete table (17-byte header + up to 256 symbol bytes) in dynamically allocated slots indexed by table ID (0-3 or 16-19).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x0 | R | — | vtable base for state dispatcher (vfunc 0 for error states 28, 29) |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (states 79, 85) |
| obj | 0x14 | RW | 29 | state code — 79(entry), 85(header batch), 28(size error), 29(index error) |
| obj | 0x18 | RW | — | first value: table ID byte (v23) or header byte |
| obj | 0x1C | RW | — | second value from header batch |
| obj | 0x20 | RW | — | third value from header batch |
| obj | 0x24 | RW | — | fourth value from header batch |
| obj | 0x28 | RW | — | fifth value from header batch |
| obj | 0x2C | RW | — | sixth value from header batch |
| obj | 0x30 | RW | — | seventh value from header batch |
| obj | 0x34 | RW | — | eighth value from header batch |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |

**Written-by note (persistence):**
- obj 0x14: written each entry and batch
- obj 0x18-0x34: overwritten each batch
- this 0x14: stream state pointer — external setup
- this 0x18: may be updated as buffer position cache
- allocated huffman table buffers: allocated via BufferAccessNullTerminate if nil, then filled with 17 header bytes + up to 256 symbol bytes

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516990 | BufferAccessNullTerminate | allocates a new buffer for a Huffman table slot when the slot pointer is null |

**Guard conditions:** Length field (v32) must be > 0 to enter the table loop. Within each entry: v30 (sum of 16 header bytes) must be ≤ 256 AND ≤ remaining v32, otherwise state 28 (size overflow). Slot index v17 must be < 4, otherwise state 29 (index out of range). v23 bit 4 selects slot array: bit set → this+0xB0+v23-16, bit clear → this+0xA0+v23.
