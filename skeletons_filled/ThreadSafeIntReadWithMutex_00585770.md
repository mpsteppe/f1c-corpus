## ThreadSafeIntReadWithMutex_00585770 — MutexProtectedIntRead

**Summary:** Acquires mutex at offset 0xF0, reads integer value from offset 0xEC under protection, releases mutex, and returns the read value. Thread-safe read accessor for a shared integer field.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SoundPlayDispatchWithStateChangeCheck (0057d890), sub_585870 (00585870)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xEC | R | — | Integer value read under mutex protection |
| this | 0xF0 | R | — | Mutex handle acquired before read |
| this | 0xF4 | R | — | Timeout (ms) for WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | Acquire mutex at offset 0xF0 with timeout at 0xF4 |
| 0059e1a4 | ReleaseMutex | R | Release mutex after read completes |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** Handle at offset 0xF0 must be non-NULL AND WaitForSingleObject must return 0 (WAIT_OBJECT_0) or 128 (WAIT_ABANDONED) for read to proceed on valid pointer; otherwise v4 = 0 leading to null-pointer dereference on *v4 (crash path, indicating handle should always exist when called correctly).
