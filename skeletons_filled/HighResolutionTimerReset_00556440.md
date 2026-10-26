## HighResolutionTimerReset_00556440 — TimerResetAndClearAccumulators

**Summary:** Queries a fresh timestamp (QPC or RDTSC), stores it at offsets 0x18/0x1C, and clears all accumulator fields (0x10/0x14, 0x28/0x2C, 0x30/0x34) to zero. Copies the new timestamp to offset 0x20/0x24 as snapshot. Called from multiple initialization and state-update paths to reset timer state.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalInitBranch (004f8f10), sub_4F8F50 (004f8f50), EntityFlagSetSubInitChain (00551440), TimerBasedStateUpdateWithCap (005514c0), BoundsCheckAgainstDAT008b8e48 (00556700), sub_55F0D0 (0055f0d0), sub_5613E0 (005613e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency; non-zero indicates initialized |
| this | 0x10 | RW | 0 | accumulated elapsed low part (cleared to 0) |
| this | 0x14 | RW | 0 | accumulated elapsed high part (cleared to 0) |
| this | 0x18 | RW | — | current query timestamp low part (fresh QPC/RDTSC) |
| this | 0x1C | RW | — | current query timestamp high part (fresh QPC/RDTSC) |
| this | 0x20 | RW | — | snapshot of timestamp low part (copy of 0x18) |
| this | 0x24 | RW | — | snapshot of timestamp high part (copy of 0x1C) |
| this | 0x28 | RW | 0 | delta accumulator low part (cleared to 0) |
| this | 0x2C | RW | 0 | delta accumulator high part (cleared to 0) |
| this | 0x30 | RW | 0 | previous timestamp low part (cleared to 0) |
| this | 0x34 | RW | 0 | previous timestamp high part (cleared to 0) |
| this | 0x48 | R | — | timer mode flags; bit 0=1 means use QPC, else RDTSC |

**Written-by note (persistence):**
- this 0x10/0x14: cleared to 0 every call
- this 0x18/0x1C: overwritten every call with fresh timestamp
- this 0x20/0x24: overwritten every call with copy of 0x18/0x1C
- this 0x28/0x2C: cleared to 0 every call
- this 0x30/0x34: cleared to 0 every call

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | import address for QPC function |
| ff00000000005406 | byte_FF00000000005406 | R | unknown (possibly processor feature flags) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | read CPU timestamp counter (RDTSC) when not using QPC |

**Guard conditions:** 
1. `*this == 0` (offset 0x0, frequency zero / timer not initialized) → skip all, return 0
   PASSES: frequency non-zero → query timestamp, clear all accumulators
   BLOCKED: timer not initialized → no state changes