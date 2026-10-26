## MutexProtectedFieldWrite_005857c0 — MutexProtectedIntWrite

**Summary:** Acquires mutex at offset 0xF0, writes parameter `a2` to integer field at offset 0xEC under protection, releases mutex, and returns pointer to written field. Thread-safe write accessor for a shared integer field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkSocketInitializationAndListen (005804a0), sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | RW | — | Integer value written under mutex protection |
| this | 0xF0 | R | — | Mutex handle acquired before write |
| this | 0xF4 | R | — | Timeout (ms) for WaitForSingleObject |

**Written-by note (persistence):**
- this 0xEC: written unconditionally with a2; persists as external caller supplies value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Acquire mutex at offset 0xF0 with timeout at 0xF4 |
| 0059e1a4 | ReleaseMutex | R | Release mutex after write completes |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Handle at offset 0xF0 must be non-NULL AND WaitForSingleObject must return 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) for write to proceed on valid pointer; otherwise result = 0 leading to null-pointer write on *result (crash path).
