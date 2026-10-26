## NetworkThreadConnectionCleanup_0057edd0 — zero out connection send data for cleanup

**Summary:** Mutex-protected cleanup: searches linked list (head at this+0xB00) for node matching INADDR_ANY, zeros its data fields at offsets 4, 8, 12 (counter, accumulated sum, latest value). Releases mutex.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB04) | 0x0 | R | — | Tail node data pointer (read before zeroing) |
| *(this+0xB04) | 0x4 | RW | 0 | Tail node data[1] — zeroed (latest value) |
| *(this+0xB04) | 0x8 | RW | 0 | Tail node data[2] — zeroed (accumulated sum) |
| *(this+0xB04) | 0xC | RW | 0 | Tail node data[3] — zeroed (send counter) |
| this | 0xB00 | R | — | List head pointer (start of search) |
| this | 0xB04 | R | — | List tail pointer |
| this | 0xB08 | R | — | List cursor/iterator |
| this | 0xB10 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |
| this | 0xB14 | R | — | Mutex wait timeout in ms |

**Written-by note (persistence):**
- *(this+0xB04) 0x4: zeroed on cleanup; reset to 0 until next send
- *(this+0xB04) 0x8: zeroed on cleanup; reset to 0 until next send
- *(this+0xB04) 0xC: zeroed on cleanup; reset to 0 until next send

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before cleanup |
| 0059e1a4 | ReleaseMutex | R | Release mutex after cleanup |
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order for match |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to this+0xA84 |

**Guard conditions:**
- If mutex handle (this+0xB10) is 0 → return immediately
- If WaitForSingleObject fails (non-zero, non-128) → return immediately
- If head pointer (this+0xB00) is 0 → skip search, release mutex
- If no matching node found → release mutex, do nothing
