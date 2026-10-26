## LinkedBufferCleanup_00582dc0 — BufferListTeardownWithTimerCleanup

**Summary:** Tears down a two-list buffer structure. For second-list nodes, frees data directly. For first-list flagged nodes, calls NTimeCallbackLoopWithSEH with 4156-byte entries and EmptyStub_aa60 callback, then frees callback block. Zeros all list fields after teardown.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BCE0 (0057bce0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | First DWORD of node's data block (entry count for NTimeCallbackLoopWithSEH) |
| *(this+0x14) | 0x4 | R | — | First-list data block's second DWORD (not directly used in cleanup) |
| obj | 0x0 | R | — | Node's data pointer (first field of 12-byte node) |
| obj | 0x8 | R | — | Flag byte — non-zero means call cleanup on data before freeing |
| this | 0x0 | RW | 0 | Head pointer of first linked list |
| this | 0x4 | RW | 0 | Tail pointer of first linked list |
| this | 0x8 | RW | 0 | Current/iterator pointer for first linked list |
| this | 0xC | RW | 0 | Count of nodes in first linked list |
| this | 0x10 | RW | 0 | Head pointer of second linked list |
| this | 0x14 | RW | 0 | Tail pointer of second linked list |
| this | 0x18 | RW | 0 | Current/iterator pointer for second linked list |
| this | 0x1C | RW | 0 | Count of nodes in second linked list |

**Written-by note (persistence):**
- this 0x0: cleared to 0 at end.
- this 0x4: cleared to 0 at end.
- this 0x8: cleared to 0 at end.
- this 0xC: cleared to 0 at end.
- this 0x10: cleared to 0 at end.
- this 0x14: cleared to 0 at end.
- this 0x18: cleared to 0 at end.
- this 0x1C: cleared to 0 at end.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0047aa60 | EmptyStub_aa60 | R | No-op callback passed to NTimeCallbackLoopWithSEH for timer cleanup |
| 0059cda8 | SEH_582DC0 | R | SEH handler registration for exception protection during teardown |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | Free allocated memory (nodes, data blocks, callback blocks) |
| 0058a5f7 | NTimeCallbackLoopWithSEH | Process callback entries in block with SEH — uses 4156-byte entries and empty stub |

**Guard conditions:** Checks this[4] (second list head, offset 0x10) before iterating second list. Checks *this (first list head, offset 0x0) before iterating first list.
