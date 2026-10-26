## NetworkPacketConstructor_0057afa0 — NetworkAddressListAppend

**Summary:** Allocates 16-byte network address struct (AF_INET, zero IP/port), overwrites with 4 DWORDs from a2. Creates 12-byte list node with flag at +8 set to 1, appends to embedded linked list in `this`. Increments counter at offset 0x14.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), VtableCallFormatDispatchTimerDispatchChain (0057dbb0), NetworkSocketAddressInit (0057f0c8)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xC) | 0x4 | RW | — | tail node's next pointer (node+4), set to new node |
| this | 0x4 | RW | 0 | byte flag, cleared to 0 |
| this | 0x8 | RW | — | linked list head pointer, set on first insert |
| this | 0xC | RW | — | linked list tail pointer, updated each insert |
| this | 0x10 | RW | — | secondary tail pointer, set on first insert |
| this | 0x14 | R | — | counter, incremented each insert |

**Written-by note (persistence):**
- *(this+0xC) 0x4: written once per insert; survives
- this 0x4: written once per call (0); survives
- this 0x8: written once on first insert; survives
- this 0xC: written once per insert; survives
- this 0x10: written once on first insert; survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e2d8 | __imp_htonl | R | import — convert IP address to network byte order (htonl) |
| 0059e2f4 | __imp_htons | R | import — convert port to network byte order (htons) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c03 | OperatorNewNhMallocWrapper | heap allocates 16 bytes (address struct) and 12 bytes (list node) |

**Guard conditions:** none — unconditional allocation and list insert

