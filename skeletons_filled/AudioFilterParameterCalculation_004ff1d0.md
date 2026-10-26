## AudioFilterParameterCalculation_004ff1d0 — FilterParameterAverageCalculate

**Summary:** Averages min/max values across a linked list of keyframes up to a future time (session time + 3000 or +5400 for session type 7), applies offset from this+0x104, clamps to [0,1], and returns via ThresholdBasedReturn. Falls back to status codes 2-5 if no curve is set.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitRaceStatusMessageDispatcher (0041be60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x38)+0xC) | 0xC | R | — | Next-next node chain pointer (loop traversal) |
| *(this+0x38) | 0x0 | R | — | Keyframe time bound (loop break condition) |
| *(this+0x38) | 0x8 | R | — | Keyframe value (tracked for min/max) |
| this | 0x20 | R | — | Fallback value (0.0 → return 2) |
| this | 0x24 | R | — | Fallback threshold (0.0 → return 3, >= 0.6 → return 5) |
| this | 0x38 | R | — | Linked list head pointer to keyframe chain |
| this | 0x104 | R | — | Offset added to averaged min/max value |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 005ad338 | flt_5AD338 | R | UI_ScrollRange [DERIVED] |
| 005ad33c | flt_5AD33C | R | SessionTypeFloatSelect [DERIVED] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004feaa0 | ThresholdBasedReturn | Convert evaluated float to integer return code via threshold |

**Guard conditions:** If this+0x38 (head pointer) is NULL → returns status 2-5 based on this+0x20/0x24. If session type (dword_7C56A4) == 7 → future time = session time + 5400, else + 3000. Loop breaks when keyframe time > future target time. Result clamped: if < 0.0 → 0.0; if > 1.0 → 1.0; else pass-through.
