## NetworkPacketSend_ead0_0057ead0 — send/queue network packet with aggregation

**Summary:** Mutex-protected network send: searches linked list for existing entry matching INADDR_ANY. If found, updates entry with new value `a2`; if not found, allocates new data node and list node. Accumulates `a2` into sum and increments counter on every send.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB04) | 0x0 | R | — | Tail node data pointer (first DWORD) |
| *(this+0xB04) | 0x4 | RW | — | Tail node data[1] — latest send value a2 |
| *(this+0xB04) | 0x8 | RW | — | Tail node data[2] — accumulated sum of all a2 values |
| *(this+0xB04) | 0xC | RW | — | Tail node data[3] — send counter (incremented each call) |
| this | 0xB00 | RW | — | List head pointer (set on first insert) |
| this | 0xB04 | RW | — | List tail pointer (updated on each insert) |
| this | 0xB08 | RW | — | List cursor (set = head on first insert) |
| this | 0xB0C | R | — | Node count (incremented on each insert) |
| this | 0xB10 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |
| this | 0xB14 | R | — | Mutex wait timeout in ms |

**Written-by note (persistence):**
- *(this+0xB04) 0x4: updated every call with latest a2 value; persists until next send
- *(this+0xB04) 0x8: accumulated sum, grows with each call; survives across calls
- *(this+0xB04) 0xC: counter, increments each call; survives across calls
- this 0xB00: written once on first list insert (set to new node); persists until list destroyed
- this 0xB04: updated on every insert; reflects tail of list
- this 0xB08: written on first insert (cursor = head); persists until list destroyed

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before list operation |
| 0059e1a4 | ReleaseMutex | R | Release mutex after operation |
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order for match |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to this+0xA84 |
| 00587c03 | OperatorNewNhMallocWrapper | Allocate 16-byte data block and 12-byte list node |

**Guard conditions:**
- If mutex handle (this+0xB10) is 0 → return 0 immediately
- If WaitForSingleObject fails with non-zero and non-128 → return 0
- If existing node not found and data allocation fails → return 1 (via goto, no list update)
- If node allocation fails after data allocation → return 1 (data orphaned, no list update)
