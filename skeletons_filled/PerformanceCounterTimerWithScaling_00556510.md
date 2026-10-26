## PerformanceCounterTimerWithScaling_00556510 — TimerGetElapsedTimeSeconds

**Summary:** Computes elapsed time in seconds since last call. Queries current timestamp via TimerQueryDispatcher, computes delta from previous timestamp (offset 0x20/0x24), stores new timestamp, and returns `delta / frequency` using the reciprocal conversion factor at offset 0x8. Part of high-resolution timer system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F8F50 (004f8f50), sub_556730 (00556730)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency for converting ticks to time |
| this | 0x8 | R | — | reciprocal scaling factor (2^32 / frequency) for high-part time conversion |
| this | 0x20 | RW | — | previous timestamp low part (updated each call with new low) |
| this | 0x24 | RW | — | previous timestamp high part (updated each call with new high) |

**Written-by note (persistence):**
- this 0x20: overwritten every call with new timestamp low part
- this 0x24: overwritten every call with new timestamp high part

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005564b0 | QueryPerformanceCounterWrapperWithModeDispatch | dispatch to QPC or RDTSC based on mode flags |

**Guard conditions:** none — unconditional call; always queries timestamp and computes delta