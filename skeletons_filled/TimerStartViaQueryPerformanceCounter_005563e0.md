## TimerStartViaQueryPerformanceCounter_005563e0 — TimerStartCapture

**Summary:** Records a fresh timestamp into the timer's previous-query fields (offset 0x30/0x34) for subsequent delta computation. Only writes if timer is initialized and both timestamp fields are currently zero (no pending measurement). Part of high-resolution timer system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityFlagSetSubInitChain (00551440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency; non-zero indicates initialized |
| this | 0x30 | RW | — | previous query timestamp low part (written with fresh QPC/RDTSC low) |
| this | 0x34 | RW | — | previous query timestamp high part (written with fresh QPC/RDTSC high) |
| this | 0x48 | R | — | timer mode flags; bit 0=1 means use QPC, else RDTSC |

**Written-by note (persistence):**
- this 0x30: written only when both 0x30 and 0x34 are currently zero (first start)
- this 0x34: same condition

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
1. `*this == 0` (offset 0x0, frequency zero / timer not initialized) → skip, return 0
2. `this[13] != 0` (offset 0x34, previous high part already set) → skip, return existing value
3. `this[12] != 0` (offset 0x30, previous low part already set) → skip
   PASSES: all guards pass → query current timestamp, store at offsets 0x30/0x34
   BLOCKED: timer not initialized OR a measurement is already pending (fields not zero)