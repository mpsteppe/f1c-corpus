## ThreadSafeMutexQueueWithTimedWait_0057ee80 — timed-wait mutex queue dequeue with event matching

**Summary:** Waits on mutex with caller-specified timeout. Searches linked list (head at this+0xAC8) comparing nodes against a2 via NetworkMessageEventComparisonWithShortMasking. On match, reads field at node data+0x14 into output. Returns 1 if found, 0 on timeout/no match.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57D6C0 (0057d6c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0xAD0)+0x4) | 0x0 | R | — | Cursor node's next pointer → first DWORD (data ptr of next) |
| *(this+0xAC8) | 0x0 | R | — | Head node data pointer |
| *(this+0xAD0) | 0x4 | R | — | Cursor node's next pointer |
| this | 0xAC8 | R | — | List head pointer (start of search) |
| this | 0xAD0 | RW | — | List cursor/iterator (initialized to head, advanced per node) |
| this | 0xAD8 | R | — | Mutex handle (WaitForSingleObject / ReleaseMutex) |

**Written-by note (persistence):**
- this 0xAD0: set to head at start; advanced during traversal; survives until next search

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex with caller-specified timeout |
| 0059e1a4 | ReleaseMutex | R | Release mutex after search |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057b840 | NetworkMessageEventComparisonWithShortMasking | Compare node against event/match parameter a2 |
| 005871f0 | ReadFieldAtOffset0x14 | Read field at node data + 0x14 for matched entry |

**Guard conditions:**
- If WaitForSingleObject returns WAIT_TIMEOUT (258) or WAIT_FAILED (-1) → return 0 immediately (no mutex acquired)
- If head pointer (this+0xAC8) is 0 → skip search, release mutex, return 0
- If no node matches a2 → release mutex, return 0
