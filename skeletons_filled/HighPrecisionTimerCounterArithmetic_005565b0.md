## HighPrecisionTimerCounterArithmetic_005565b0 — TimerQueryAdjustedElapsedTime

**Summary:** Computes elapsed time from a reference timestamp (offset 0x18/0x1C), subtracts an accumulated delta (offset 0x28/0x2C), and adds a base accumulated time (offset 0x10). Does not modify any stored fields. Part of high-resolution timer adjustment system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4F8F50 (004f8f50), TimerBasedStateUpdateWithCap (005514c0), sub_5613E0 (005613e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency for converting ticks to time |
| this | 0x8 | R | — | reciprocal scaling factor (2^32 / frequency) |
| this | 0x10 | R | — | accumulated time base added to final result |
| this | 0x18 | R | — | reference timestamp low part (reset point for delta) |
| this | 0x1C | R | — | reference timestamp high part |
| this | 0x28 | R | — | accumulated delta low part (subtracted from elapsed) |
| this | 0x2C | R | — | accumulated delta high part |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005564b0 | QueryPerformanceCounterWrapperWithModeDispatch | dispatch to QPC or RDTSC based on mode flags |

**Guard conditions:** none — unconditional read and compute