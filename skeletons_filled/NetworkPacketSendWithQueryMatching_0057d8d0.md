## NetworkPacketSendWithQueryMatching_0057d8d0 — SendPacketToMatchingConnections

**Summary:** Builds structured packet from a2 via StructuredMemoryCopyWithHeaderPrepend. If a3 is non-null, sends to specific connection matched by ID in mutex-protected list. If null, broadcasts to all connections whose query criteria (from a2+0x48 list) match the connection's event fields.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UDPSocketBind (0057e860), sub_580DE0 (00580de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAAC)+0x0) | 0x2 | R | — | connection node WORD field (compared with HIWORD of query key) |
| *(*(this+0xAAC)+0x0) | 0x4 | R | — | connection node DWORD field (compared with a3[1]) |
| *(*(this+0xAAC)+0x0) | 0x12 | R | — | connection node second WORD field (alternative match) |
| *(*(this+0xAAC)+0x0) | 0x14 | R | — | connection node second DWORD field (alternative match) |
| *(this+0xAAC) | 0x0 | R | — | linked list head pointer (points to first connection node) |
| *(this+0xAB8) | 0x2 | R | — | field at list struct+3 offset 2 (node field for broadcast match) |
| *(this+0xAB8) | 0x4 | R | — | field at list struct+3 offset 4 (node field for broadcast match) |
| this | 0xAAC | R | — | linked list structure pointer (head/tail/count at offsets 0/4/8, mutex+timeout at 16/20) |
| this | 0xAB4 | RW | — | iterator/current pointer for list walk |
| this | 0xAB8 | R | — | some list field (3rd DWORD of list struct) |
| this | 0xABC | R | — | mutex handle for thread-safe list access |
| this | 0xAC0 | R | — | mutex wait timeout (milliseconds) |

**Written-by note (persistence):**
- this 0xAB4: updated during each list walk; external poke does not survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | acquire list mutex before walking |
| 0059e1a4 | ReleaseMutex | R | release list mutex after walk |
| 0059e300 | __imp_send | R | Winsock send — transmit packet on matched socket |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b0d0 | IndexedLinkedListNodeGetter | get node by index from query list at a2+0x48 |
| 0057b2e0 | StructFieldGetter_b2e0 | retrieve additional struct field for match validation |
| 0057b6b0 | OffsetGetter | get socket handle offset from connection node for send() |
| 0057d5d0 | StructuredMemoryCopyWithHeaderPrepend | build structured packet header + payload in buf |
| 0057db80 | sub_57DB80 | secondary match function for connection ID query |
| 005871f0 | ReadFieldAtOffset0x14 | read field at offset 0x14 for broadcast match filter |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAAC | == | 0 | linked list head pointer |

**Guard interpretation:** if list head (*(this+0xAAC)) is NULL → skip entire send loop, return 1. If non-null → walk list and send to matching connections.
