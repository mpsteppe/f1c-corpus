## MutexProtectedLinkedListLookupByID_0057dff0 — ListFindAndDisconnectByAddrPort

**Summary:** Acquires mutex, searches active connection linked list for node matching address (HIWORD(a2)) and port (a3). On match, calls ConnectionCleanupDisconnect (sub_57DE30) on found node with a6 parameter. Returns 1 if disconnected, 0 if no match. Network connection management.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57CB50 (0057cb50), sub_57D6C0 (0057d6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x2 | R | — | address family from matched node's sockaddr |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x4 | R | — | port from matched node's sockaddr |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x12 | R | — | second address family from node's sockaddr |
| *(*(*(this+0xAB4)+0x4)+0x0) | 0x14 | R | — | second port from node's sockaddr |
| *(*(this+0xAB4)+0x4) | 0x0 | R | — | pointer to socket address structure in matched node |
| *(this+0xAAC) | 0x0 | R | — | linked list node data (first entry) |
| *(this+0xAB4) | 0x4 | R | — | linked list node next pointer via cursor |
| this | 0xAAC | R | — | mutex-protected connection linked list head |
| this | 0xAB4 | RW | — | traversal cursor (set to list head at start) |
| this | 0xABC | R | — | mutex handle (WaitForSingleObject/ReleaseMutex) |
| this | 0xAC0 | R | — | mutex wait timeout in milliseconds |

**Written-by note (persistence):**
- this 0xAB4: conditional — written when mutex acquired; set to list head at start, then advanced during traversal

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 import — wait on mutex handle |
| 0059e1a4 | ReleaseMutex | R | kernel32 import — release mutex after lookup |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057de30 | sub_57DE30 | ConnectionCleanupDisconnect — remove and clean up matched node |

**Guard conditions:** List head at this+0xAAC must be non-NULL. Inner check on *v12 (first node data) must be non-NULL. If list empty or no node matches address/port pair, the function returns 0 without calling sub_57DE30.
