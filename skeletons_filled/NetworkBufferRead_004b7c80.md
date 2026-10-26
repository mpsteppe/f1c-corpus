## NetworkBufferRead_004b7c80 — Network Buffer Range Read

**Summary:** Walks a linked list of data entries, selects those with float key in [a4, a5] range, and dispatches their payload data (deltas) via FileWriteWithBackendDispatch and ConditionalDispatch_6bd0. Returns total bytes dispatched.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B7DE0 (004b7de0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x714) | 0x0 | R | — | List node data pointer (float key for range check) |
| *(this+0x714) | 0x4 | R | — | Node payload size/offset field |
| this | 0x714 | R | — | List head pointer (start of walk) |
| this | 0x71C | RW | — | List current/temp walk pointer |
| this | 0x720 | R | — | List count (unused in logic) |

**Written-by note (persistence):**
- this 0x71C: Updated as list is walked; per-call.

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566bd0 | ConditionalDispatch_6bd0 | Read/dispatch data buffer of given size |
| 00566c00 | FileWriteWithBackendDispatch | Write buffer data to file or network backend |
| 00566d70 | FileSizeQueryWithFallback | Query resource size for delta calculation |
| 00566db0 | sub_566DB0 | Seek/set position in resource |
| 00566e20 | ResourceLookupDispatcher | Look up resource total size |

**Guard conditions:** If this+0x714 (list head) is NULL, return 0 — empty list. If head node's first DWORD (float key) is NULL/0, return 0. Walk entries: if float key > a5 (upper bound), stop and return immediately. If float key >= a4 (lower bound), process the entry's payload; otherwise skip. If next pointer is NULL, return.
