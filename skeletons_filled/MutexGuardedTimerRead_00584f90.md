## MutexGuardedTimerRead_00584f90 — MutexGuardedTimerRead

**Summary:** Acquires a mutex, reads a timer value (via FloatAdditionReturnsFUN00568d90Param1), releases the mutex, and returns the timer value. Thread-safe timer read.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** AnimationTimingUpdateWithParamSet (0057a5a0), AnimationValueFetchWithTiming (0057a610), sub_57CB50 (0057cb50), VtableCallFormatDispatchTimerDispatchChain (0057dbb0), sub_57DC10 (0057dc10), sub_57E0A0 (0057e0a0), sub_584230 (00584230)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD4 | R | — | mutex handle for timer access |
| this | 0xD8 | R | — | timeout duration for WaitForSingleObject |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e1a0 | WaitForSingleObject | R | kernel32 WaitForSingleObject import |
| 0059e1a4 | ReleaseMutex | R | kernel32 ReleaseMutex import |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00583680 | FloatAdditionReturnsFUN00568d90Param1 | read accumulated float from timer object |

**Guard conditions:** Mutex handle (this+0xD4) must be non-NULL. WaitForSingleObject must return 0 (signaled) or 128 (WAIT_ABANDONED) — BLOCKED on timeout/error. If blocked, timer object is passed NULL to read function (returns 0).
