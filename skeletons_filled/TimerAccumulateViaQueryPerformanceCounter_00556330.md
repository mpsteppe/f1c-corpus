## TimerAccumulateViaQueryPerformanceCounter_00556330 — AccumulateElapsedTimerTick

**Summary:** Computes elapsed timer ticks since last query (QPC or RDTSC) and adds them to running accumulator at offsets 0x28/0x2C. Clears the previous-timestamp fields (0x30/0x34) after accumulation. Part of high-resolution timer system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | timer frequency; non-zero indicates timer is initialized |
| this | 0x28 | RW | — | accumulated elapsed ticks low part (running total) |
| this | 0x2C | RW | — | accumulated elapsed ticks high part |
| this | 0x30 | RW | 0 | previous query timestamp low part (cleared after use) |
| this | 0x34 | RW | 0 | previous query timestamp high part (cleared after use) |
| this | 0x48 | R | — | timer mode flags; bit 0=1 means use QPC, else RDTSC |

**Written-by note (persistence):**
- this 0x28: updated with delta low part each call (cumulative)
- this 0x2C: updated with delta high part each call (cumulative)
- this 0x30: cleared to 0 each call after accumulation
- this 0x34: cleared to 0 each call after accumulation

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | import address for QPC function |
| ff00000000005406 | byte_FF00000000005406 | RW | unknown (possibly processor feature flags) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | read CPU timestamp counter (RDTSC) when not using QPC |

**Guard conditions:** 
1. `*this == 0` (frequency field 0x0 is zero / timer not initialized) → skip accumulation, return 0
2. `this[13] == 0` (offset 0x34, previous high part is zero) → skip
3. `this[12] == 0` (offset 0x30, previous low part is zero) → skip
   PASSES: all three non-zero → query current timestamp, compute delta = current - previous, add to accumulators, clear previous fields.
   BLOCKED: any of the three is zero → return without accumulation.