## ThreadSuspendWithMutexWaitLock_005855e0 — ThreadSuspendWithRetryAndMutex

**Summary:** Suspends a thread under mutex protection, retrying SuspendThread up to 50 times with increasing sleep delays if the thread has prior suspend count. Sets a suspend flag once suspended. Returns 1 on success, 0 on failure.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | thread handle to suspend |
| this | 0x1C | RW | 1 | suspend flag (set to 1 after successful suspend) |
| this | 0x20 | R | — | mutex handle for suspend flag access |
| this | 0x24 | R | — | timeout for WaitForSingleObject on mutex |

**Written-by note (persistence):**
- this 0x1C: set to 1 when thread successfully suspended; persists until cleared externally

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | kernel32 Sleep import (increasing delay between retries) |
| 0059e1a0 | WaitForSingleObject | R | kernel32 WaitForSingleObject import |
| 0059e1a4 | ReleaseMutex | R | kernel32 ReleaseMutex import |
| 0059e1fc | SuspendThread | R | kernel32 SuspendThread import |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Thread handle (this+0x4) must be non-NULL. Suspend flag (this+0x1C) must be 0 (not already suspended) — BLOCKED (skips suspend). Mutex must be acquired. Retry loop: exits after 50 attempts if SuspendThread continues returning 0 (previous suspend count > 0).
