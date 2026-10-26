## TimeBasedMessageChain_0041a500 — TimeBasedMessageDispatcher

**Summary:** Dispatches race commentary/event messages at fixed elapsed-time thresholds (2700s, 1800s, 900s, 600s, 300s, 180s) by inserting driver table entries with specific message IDs; resets audio buffer when elapsed time reaches zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitTimer (004d2e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e810 | flt_59E810 | R | LapTimeThreshold1 [DERIVED] |
| 0059e814 | flt_59E814 | R | OscillationMax [DERIVED] |
| 0059e818 | flt_59E818 | R | EngineRPMThreshold1 [DERIVED] |
| 0059e81c | flt_59E81C | R | LeadInPositionThreshold [DERIVED] |
| 005ea618 | flt_5EA618 | R | PointerTableEntry [DERIVED] |
| 005eb10c | dword_5EB10C | R | SoundSystemPtr [DERIVED] (also: ` — engine interface pointer) |
| 007cf3c8 | flt_7CF3C8 | R | TrackConditionState [CONFIRMED] |
| 007d0308 | dword_7D0308 | R | RaceActiveFlag [FACT] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004144d0 | StructInitWithSentinelValues | Initialize driver table entry struct with sentinel/default values |
| 004144f0 | DriverDataTableLookupAndTimeConversion | Populate driver data entry with message ID, timing info, and driver indices |
| 00418560 | InsertDriverTableEntry | Insert populated entry into shared driver data table |
| 004186a0 | BufferInitWith10fDefaults | Reset shared buffer to 10.0f default values |

**Guard conditions:** 
1. `dword_7D0308` (RaceActiveFlag) must be non-zero → PASSES: race active. BLOCKED: race inactive.
2. `flt_7CF3C8` (TrackConditionState) must not be 0.0 → PASSES: track condition initialized. BLOCKED: track condition zero.
3. `v1 = a1 - dbl_8AFEA0 < 2700.0` → PASSES: elapsed session time under 2700s. BLOCKED: elapsed >= 2700s (skip entire function body).
4. For each descending threshold T in {2700, 1800, 900, 600, 300, 180}: when `v4 = dbl_8AFE98 + v6 >= T` AND `v6 < T` → PASSES: fires message (IDs 35, 34, 277, 276, 279, 278 respectively). BLOCKED: v4 < T.
5. `v6 <= 0.0` → PASSES: elapsed time at/below zero → trigger audio callback and reset buffer.
