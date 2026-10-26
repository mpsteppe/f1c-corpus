## MutexProtectedValueReadWithTimeout_004066c0 — MutexProtectedValueReadWithTimeout

**Summary:** Reads a mutex-protected integer value from the object. Waits on mutex with configured timeout, reads value from offset 0x4C, then releases mutex. Returns -1 on failure (null mutex or wait failure).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexWrapper (004064b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | R | — | protected integer value (read under mutex) |
| this | 0x50 | R | — | Windows mutex handle |
| this | 0x54 | R | — | mutex wait timeout (passed to WaitForSingleObject) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Windows API to wait on mutex handle |
| 0059e1a4 | ReleaseMutex | R | Windows API to release mutex after read |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[20] (offset 0x50) != NULL for valid mutex handle — if NULL, returns -1. Then checks WaitForSingleObject result: 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) allow the read; any other result returns -1.
