## NetworkMessageQueueDequeue_0057ea30 — dequeue message from network queue

**Summary:** Searches a mutex-protected linked list (head at this+0xB00) for a node whose data's first DWORD matches INADDR_ANY. On match, reads second DWORD offset from node data into output. Returns 1 if found, 0 otherwise.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB04) | 0x0 | R | — | Tail node data pointer (first DWORD) |
| *(this+0xB04) | 0x4 | R | — | Tail node next pointer |
| this | 0xB00 | R | — | List head pointer (start of search) |
| this | 0xB04 | R | — | List tail pointer |
| this | 0xB08 | R | — | List cursor/iterator |
| this | 0xB10 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |
| this | 0xB14 | R | — | Mutex wait timeout in ms |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before list search |
| 0059e1a4 | ReleaseMutex | R | Release mutex after search |
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order for match |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to this+0xA84 |

**Guard conditions:**
- If mutex handle (this+0xB10) is 0 → skip entire operation, return 0
- If head pointer (this+0xB00) is 0 → skip search, release mutex, return 0
- Node iteration continues while node exists; if node's data pointer is null or data's first DWORD != INADDR_ANY, advance to next node
- If no match found after exhausting list → release mutex, return 0
