## QPCTimerInitialization_00568be0 — HighResTimerInitWithQPC

**Summary:** Initializes a high-resolution timer structure using QueryPerformanceCounter/QueryPerformanceFrequency. Stores frequency and computes a scale factor (2^32 / frequency) for converting QPC ticks to time units. Zeroes all timing accumulators. Returns 0.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RunCollisionDetectionLoop (0045f390), AutoJoinRetryLoop (004637a0), LargeStructInitialization (00464c10), sub_4989E0 (004989e0), CarPhysicsStateInitializer (004b57f0), ResourceFileLoader (004f9d60), VidMan_Enter (004fa000), TimerInitWithSEH (005835f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | timer frequency LowPart (from QueryPerformanceFrequency) |
| this | 0x8 | RW | — | scale factor = 2^32 / frequency for tick-to-time conversion |
| this | 0x10 | RW | 0 | accumulated time low part (zeroed) |
| this | 0x14 | RW | 0 | accumulated time high part (zeroed) |
| this | 0x18 | RW | — | last QPC counter LowPart snapshot |
| this | 0x1C | RW | — | last QPC counter HighPart snapshot |
| this | 0x20 | RW | — | working QPC counter LowPart copy |
| this | 0x24 | RW | — | working QPC counter HighPart copy |
| this | 0x28 | RW | 0 | tick accumulator low part (zeroed) |
| this | 0x2C | RW | 0 | tick accumulator high part (zeroed) |
| this | 0x48 | RW | — | timer mode/flags (copied from a2 parameter) |

**Written-by note (persistence):**
- this 0x0: written once when a2==1 and QPF succeeds; survives as persistent frequency base
- this 0x8: written unconditionally as scale factor; survives as persistent conversion factor
- this 0x10: zeroed unconditionally; reset on each init call
- this 0x14: zeroed unconditionally; reset on each init call
- this 0x18: written when a2==1 and QPF succeeds; snapshot survives
- this 0x1C: written when a2==1 and QPF succeeds; snapshot survives
- this 0x20: written unconditionally; working copy survives
- this 0x24: written unconditionally; working copy survives
- this 0x28: zeroed unconditionally; reset on each init call
- this 0x2C: zeroed unconditionally; reset on each init call
- this 0x48: written unconditionally with a2; mode/flags survive

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | Win32 QPC API pointer to get current performance counter |
| 0059e240 | QueryPerformanceFrequency | R | Win32 QPF API pointer to get timer frequency |
| 005af448 | dbl_5AF448 | R | TimerFreqScale [DERIVED] (also: ` — timer frequency scaling constant) |
| ff00000000005406 | byte_FF00000000005406 | RW | unknown timer-related byte |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** if a2 != 1 OR QueryPerformanceFrequency returns FALSE, timer frequency and initial counter are NOT captured (stale values preserved). Accumulators are still zeroed.
