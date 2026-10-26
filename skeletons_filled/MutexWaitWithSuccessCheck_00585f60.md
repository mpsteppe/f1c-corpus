## MutexWaitWithSuccessCheck_00585f60 — MutexWaitWithSuccessCheck

**Summary:** Waits on mutex handle at offset 0x50 with timeout at offset 0x54. Returns `this` if wait succeeds (WAIT_OBJECT_0 or WAIT_ABANDONED), or 0 if handle is NULL or wait fails/times out.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | Mutex handle to wait on |
| this | 0x54 | R | — | Timeout (ms) for WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Wait on mutex with timeout |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Handle at offset 0x50 must be non-NULL AND WaitForSingleObject must return 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) to pass (return `this`). NULL handle or non-zero/non-128 return blocks (return 0).
