## MutexProtectedFunctionCallWithWait_00584f30 — MutexGuardedListAppend_C

**Summary:** Acquires a mutex, appends a node to a linked list (via LinkedListNodeAppend_6000), then releases the mutex. Thread-safe list insertion, variant C with different field offsets.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5A8 | R | — | mutex handle for linked list access |
| this | 0x5AC | R | — | timeout duration for WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 WaitForSingleObject import |
| 0059e1a4 | ReleaseMutex | R | kernel32 ReleaseMutex import |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00586000 | LinkedListNodeAppend_6000 | append node to list |

**Guard conditions:** Mutex handle (this+0x5A8) must be non-NULL. WaitForSingleObject must return 0 (signaled) or 128 (WAIT_ABANDONED) — BLOCKED on timeout/error. PASSES: mutex acquired then released after append.
