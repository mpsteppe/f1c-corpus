## NetworkReceivePacket_0057e940 — receive network packet from queue

**Summary:** Sets up local sockaddr_in, copies to context, then searches a mutex-protected linked list (at this+0xAC8) for a matching node via NetworkMessageEventComparisonWithShortMasking. On match, reads field at offset 0x14 from node and stores to output.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xAC8) | 0x0 | R | — | Node data pointer (first DWORD of head node) |
| *(this+0xAD4) | 0x0 | R | — | unknown (not directly referenced in this function) |
| this | 0xAC8 | R | — | List head pointer for received packet queue |
| this | 0xAD0 | RW | — | List cursor/iterator (advanced during search) |
| this | 0xAD4 | R | — | List tail pointer field |
| this | 0xAD8 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |
| this | 0xADC | R | — | Mutex wait timeout in ms |

**Written-by note (persistence):**
- this 0xAD0: cursor updated during traversal; survives until next search

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex before list search |
| 0059e1a4 | ReleaseMutex | R | Release mutex after search completes |
| 0059e2d8 | __imp_htonl | R | Convert INADDR_ANY to network byte order |
| 0059e2f4 | __imp_htons | R | Convert port to network byte order |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b840 | NetworkMessageEventComparisonWithShortMasking | Compare node against sockaddr_in to find matching packet |
| 0057b9f0 | Copy4DwordsStructToStruct | Copy 16-byte sockaddr_in to this+0xA84 |
| 005871f0 | ReadFieldAtOffset0x14 | Read field at node+0x14 for matched packet |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0xAC8 | == | 0 | List head pointer — NULL means empty queue |

**Guard interpretation:** If this+0xAC8 (head pointer) is 0, skip entire search loop, return 0 (no packet). Mutex still released.
