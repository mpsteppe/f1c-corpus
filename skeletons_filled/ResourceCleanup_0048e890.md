## ResourceCleanup_0048e890 — SemaphoreHandleCleanup

**Summary:** Cleans up a mutex/semaphore resource: if handle at offset 0xE8 is non-zero, calls MutexSemaphoreCleanup and zeroes the handle; also zeroes field at offset 0xEC. Returns 1.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** StateResetWithZero (004662e0), Destructor_e670 (0048e670)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xE8 | RW | 0 | mutex/semaphore handle to clean up |
| this | 0xEC | RW | 0 | secondary counter/state to reset to zero |

**Written-by note (persistence):**
- this 0xE8: cleared after cleanup; external allocation would set it again
- this 0xEC: unconditionally zeroed; survives until next write

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005461b0 | MutexSemaphoreCleanup | release a mutex/semaphore object |

**Guard conditions:** if (this[58] != 0) → PASS (call MutexSemaphoreCleanup and zero handle); if zero → BLOCKED (skip cleanup). Offset 0xEC is always zeroed regardless.
