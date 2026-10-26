## QPCTimestampReadWrapper_00568cb0 — ConditionalQPCCounterRead

**Summary:** Conditionally reads the QueryPerformanceCounter value if the timer is initialized (frequency non-zero) and mode bit 0 is set. Outputs HighPart and LowPart via pointer parameters. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HighResolutionTimerDelta (00568cf0), PerformanceCounterDiffWithScaling (00568d90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency LowPart (non-zero = timer initialized) |
| this | 0x48 | R | — | timer mode/flags (bit 0 enables QPC counter read) |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | Win32 QPC API pointer to get current performance counter |
| ff00000000005406 | byte_FF00000000005406 | R | unknown timer-related byte |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if *this (frequency field at offset 0) is zero (timer not initialized) OR bit 0 of this[18] (offset 0x48) is not set, QPC is NOT called and output parameters are NOT written.
