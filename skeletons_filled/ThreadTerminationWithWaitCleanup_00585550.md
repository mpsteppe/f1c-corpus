## ThreadTerminationWithWaitCleanup_00585550 — ThreadTerminateWithWaitAndClose

**Summary:** Retries ThreadResumeWithMutexWait (up to 10× with 250ms sleep), sets a termination flag under mutex, waits INFINITE on the thread handle, closes it, and clears handle/ID fields. Thread shutdown and cleanup.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AudioStreamingThreadShutdown (0057fde0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | RW | 0 | thread handle (cleared to 0 after close) |
| this | 0x8 | RW | 0 | thread ID (cleared to 0 after close) |
| this | 0xC | RW | 1 | termination flag (set to 1 under mutex before wait) |
| this | 0x10 | R | — | mutex handle for termination flag access |
| this | 0x14 | R | — | timeout for WaitForSingleObject on mutex |

**Written-by note (persistence):**
- this 0x4: set to 0 after CloseHandle (once)
- this 0x8: set to 0 after CloseHandle (once)
- this 0xC: set to 1 under mutex during termination sequence

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0dc | Sleep | R | kernel32 Sleep import (250ms between resume retries) |
| 0059e1a0 | WaitForSingleObject | R | kernel32 WaitForSingleObject import |
| 0059e1a4 | ReleaseMutex | R | kernel32 ReleaseMutex import |
| 0059e1a8 | CloseHandle | R | kernel32 CloseHandle import |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00585680 | ThreadResumeWithMutexWait | resume thread under mutex (retry up to 10×) |

**Guard conditions:** Thread handle (this+0x4) must be non-NULL to proceed with termination. BLOCKED: returns early if handle already NULL.
