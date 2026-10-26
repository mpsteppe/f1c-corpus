## HighResolutionTimerDeltaCalculation_00556650 — TimerQueryDeltaSinceReset

**Summary:** Computes elapsed time in seconds from the reference timestamp at offset 0x18/0x1C to the current time. Calls TimerQueryDispatcher for current timestamp, subtracts stored reference, and converts ticks to time using frequency and reciprocal. Does not update any stored fields. Part of high-resolution timer system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_556760 (00556760), sub_55F0D0 (0055f0d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency for converting ticks to time |
| this | 0x8 | R | — | reciprocal scaling factor (2^32 / frequency) |
| this | 0x18 | R | — | reference timestamp low part (delta computed from here) |
| this | 0x1C | R | — | reference timestamp high part |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005564b0 | QueryPerformanceCounterWrapperWithModeDispatch | dispatch to QPC or RDTSC based on mode flags |

**Guard conditions:** none — unconditional compute