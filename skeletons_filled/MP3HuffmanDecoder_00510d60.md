## MP3HuffmanDecoder_00510d60 — Decompression table builder

**Summary:** Parses Huffman/decompression table entries from a byte stream. Each entry specifies a table index (0-3) and value format; reads values from stream according to global position table dword_5AF778, stores them as WORD arrays in allocated buffers, and optionally outputs 64-WORD batches to the state dispatcher.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x0 | R | — | vtable base for state dispatcher (vfunc 0 for error state 30) |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (states 80, 92) |
| obj | 0x14 | RW | 92 | state code — 80(entry), 30(index err), 92(value batch) |
| obj | 0x18 | RW | — | table index (low nibble of entry byte) |
| obj | 0x1C | RW | — | value flag (high nibble of entry byte) |
| obj | 0x20 | RW | — | WORD batch values from buffer (per 8-WORD output) |
| obj | 0x24 | RW | — | WORD batch values from buffer |
| obj | 0x28 | RW | — | WORD batch values from buffer |
| obj | 0x2C | RW | — | WORD batch values from buffer |
| obj | 0x30 | RW | — | WORD batch values from buffer |
| obj | 0x34 | RW | — | WORD batch values from buffer |
| obj | 0x68 | R | — | count/limit checked against 2 — determines if 64-WORD batch output runs |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |

**Written-by note (persistence):**
- obj 0x14: written each entry and batch
- obj 0x18-0x34: overwritten per 8-WORD batch output (up to 8 batches)
- this 0x14: stream state pointer — external setup
- this 0x18: may be updated as buffer position cache
- allocated WORD tables: allocated via VTableAllocNullTerminate if nil, then filled with values per dword_5AF778 positioning

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005af778 | dword_5AF778 | R | position/index table — array of indices into the WORD table being built |
| 005af878 | dword_5AF878 | R | end address of the position table — loop runs from dword_5AF778 to this address |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00516974 | VTableAllocNullTerminate | allocates a new WORD table buffer if the table slot pointer is null |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x68 | >= | 2 | batch output count threshold |

**Guard interpretation:** If obj+0x68 >= 2 (PASS): after building each table entry, iterate through the buffer in 8-WORD groups and output each group via state 92 dispatch (up to 64 WORDs total). If obj+0x68 < 2 (BLOCKED): skip the batch output entirely.
