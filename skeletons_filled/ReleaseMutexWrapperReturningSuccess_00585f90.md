## ReleaseMutexWrapperReturningSuccess_00585f90 — ReleaseMutexWithNullCheck

**Summary:** Checks if mutex handle at offset 0x50 is non-NULL, then calls ReleaseMutex and returns the result. Returns FALSE if handle is NULL.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_5837F0 (005837f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x50 | R | — | Mutex handle to release |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a4 | ReleaseMutex | R | Release the mutex handle |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Handle at offset 0x50 must be non-NULL to call ReleaseMutex; if NULL, returns FALSE.
