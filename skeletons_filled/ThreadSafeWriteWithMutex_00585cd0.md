## ThreadSafeWriteWithMutex_00585cd0 — MutexProtectedFieldWriteAt5B4

**Summary:** Acquires mutex at offset 0x5B8, writes parameter `a2` to integer field at offset 0x5B4 under protection, releases mutex, and returns pointer to written field. Thread-safe write accessor for shared field at offset 0x5B4.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_57BF00 (0057bf00), NetworkSocketInitializationAndListen (005804a0), sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x5B4 | RW | — | Integer field written under mutex protection |
| this | 0x5B8 | R | — | Mutex handle acquired before write |
| this | 0x5BC | R | — | Timeout (ms) for WaitForSingleObject |

**Written-by note (persistence):**
- this 0x5B4: written unconditionally with a2; persists as external caller supplies value

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Acquire mutex at offset 0x5B8 with timeout at 0x5BC |
| 0059e1a4 | ReleaseMutex | R | Release mutex after write completes |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Handle at offset 0x5B8 must be non-NULL AND WaitForSingleObject must return 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) for write to proceed on valid pointer; otherwise result = 0 leads to null-pointer write (crash path).
