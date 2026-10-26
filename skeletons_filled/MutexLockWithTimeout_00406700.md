## MutexLockWithTimeout_00406700 — MutexProtectedValueWriteWithTimeout

**Summary:** Writes a value under mutex protection. Waits on mutex with configured timeout, writes input parameter to offset 0x4C, then releases mutex. Returns 1 on success, 0 on failure (no mutex or wait failure).

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MutexSynchronizationObjectInit (00406130), ViewCameraReset (004064c0), sub_406790 (00406790)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4C | RW | — | protected integer value (written under mutex) |
| this | 0x50 | R | — | Windows mutex handle |
| this | 0x54 | R | — | mutex wait timeout (passed to WaitForSingleObject) |

**Written-by note (persistence):**
- this 0x4C: written under mutex — external poke survives but may be overwritten on next mutex-protected write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Windows API to wait on mutex handle |
| 0059e1a4 | ReleaseMutex | R | Windows API to release mutex after write |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** checks this[20] (offset 0x50) != NULL for valid mutex handle — if NULL, returns 0. Then checks WaitForSingleObject result: if non-zero AND not 128 (WAIT_ABANDONED), returns 0.
