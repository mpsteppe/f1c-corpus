## ThreadSafeCallWithMutex_00584c70 — MutexGuardedListAppend

**Summary:** Acquires a mutex, appends a node to a linked list (via LinkedListNodeAppend_6000), then releases the mutex. Thread-safe list insertion wrapper.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), VtableCallFormatDispatchTimerDispatchChain (0057dbb0), NetworkSocketAddressInit (0057f0c8), VTableDispatchWithConditionalCall (00585380)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x554 | R | — | mutex handle for linked list access |
| this | 0x558 | R | — | timeout duration for WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 WaitForSingleObject import |
| 0059e1a4 | ReleaseMutex | R | kernel32 ReleaseMutex import |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00586000 | LinkedListNodeAppend_6000 | append node to list |

**Guard conditions:** Mutex handle (this+0x554) must be non-NULL. WaitForSingleObject must return 0 (signaled) or 128 (WAIT_ABANDONED) — BLOCKED on timeout/error. PASSES: mutex acquired then released after append.
