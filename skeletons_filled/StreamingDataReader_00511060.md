## StreamingDataReader_00511060 — Segment size reader with skip

**Summary:** Reads a 2-byte big-endian segment size from a byte stream. Dispatches state 90 with a stored field value (this+0x178) and the size, then skips the remaining segment bytes.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CommandDispatchStateMachine (0051126a)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x14) | 0x0 | R | — | byte stream buffer current read pointer |
| obj | 0x4 | R | — | second vtable entry for parameterized dispatch (state 90) |
| obj | 0x14 | RW | 90 | state code — always 90 |
| obj | 0x18 | RW | — | stored field value (copy of this+0x178) |
| obj | 0x1C | RW | — | big-endian size read from stream |
| this | 0x0 | R | — | pointer to state dispatcher object |
| this | 0x14 | RW | — | pointer to byte stream read state struct |
| this | 0x18 | RW | — | cached/alias of stream buffer read pointer |
| this | 0x20 | R | — | table entry count (unused in this function) |
| this | 0x24 | R | — | some constant/limit (unused in this function) |
| this | 0x178 | R | — | stored value reported in state 90 dispatch |

**Written-by note (persistence):**
- obj 0x14: written to 90 each call
- obj 0x18: written from this+0x178
- obj 0x1C: written with stream size
- this 0x14: stream pointer — external setup
- this 0x18: may be updated as buffer position cache

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** No explicit field-vs-literal guard. The function always reads 2 bytes and dispatches state 90. The implicit guard is that the stream must have at least 2 bytes available (refill called if not).
