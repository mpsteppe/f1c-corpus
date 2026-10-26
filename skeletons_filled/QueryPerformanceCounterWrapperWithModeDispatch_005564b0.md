## QueryPerformanceCounterWrapperWithModeDispatch_005564b0 — TimerQueryDispatcher

**Summary:** Dispatches timestamp query to either QueryPerformanceCounter (mode bit 0) or RDTSC (mode bit 1) based on timer mode flags at offset 0x48. Stores HighPart/LowPart into caller-provided output pointers. Part of high-resolution timer abstraction layer.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PerformanceCounterTimerWithScaling (00556510), HighPrecisionTimerCounterArithmetic (005565b0), HighResolutionTimerDeltaCalculation (00556650)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency; non-zero indicates timer is initialized |
| this | 0x48 | R | — | timer mode flags: bit 0=use QPC, bit 1=use RDTSC |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | import address for QPC function |
| ff00000000005406 | byte_FF00000000005406 | R | unknown (possibly processor feature flags) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | read CPU timestamp counter (RDTSC) when mode bit 1 is set |

**Guard conditions:** 
1. `*this == 0` (offset 0x0, frequency zero / timer not initialized) → skip, return 0
   PASSES: mode bit 0 → QPC, store HighPart/*a2, LowPart/*a3
   PASSES: mode bit 1 → RDTSCTimestampRead(a2, a3)
   BLOCKED: timer not initialized → no query performed