## TrackOpeningProgressTimer_004612e0 — TrackOpenProgressDecay

**Summary:** Decrements track opening progress timer each frame by a clamped delta; marks track as fully open when timer reaches zero.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x29 | RW | 1 | Track open flag (set to 1 when timer expires) |
| this | 0x2C | RW | 18446744072627421184 → -1.0f | Track opening progress timer (decayed toward 0) |
| this | 0x3FC4 | R | — | Session phase/state value (checked for 1 or 2 to skip) |

**Written-by note (persistence):**
- this 0x29: set to 1 when timer expires; persists until cleared externally
- this 0x2C: decremented each frame; set to -1.0f on expiry; persists

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | Zero threshold (~0.0f, physics clamp) [DERIVED] |
| 0059e444 | flt_59E444 | R | Frame delta (1/60) [DERIVED] |
| 0059e450 | flt_59E450 | R | Degrees-to-radians conversion [DERIVED] |
| 0059f0b4 | flt_59F0B4 | R | Initial track open speed value [DERIVED] |
| 005c5ce4 | aDDevF119992002_1 | R | SourceDevPathStr [DERIVED] |
| 005c6134 | aApplyingFrameT | R | "Applying frame time" debug string |
| 007c569c | dword_7C569C | R | Session type (5=server) — guards dev logging |
| 008ad25c | dword_8AD25C | R | Debug message buffer pointer |
| 008afe90 | dbl_8AFE90 | R | Engine cooling rate / frame delta (used as decrement step) |
| 008afea0 | dbl_8AFEA0 | R | Session time (passed to utility function) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0045e570 | UtilityFunction_e570 | Session-scoped utility call when timer reaches 5.0 |
| 004d7a50 | StringSplitLoop | Guard check for dev logging verbosity |
| 004d7aa0 | DebugLogWrite | Write "Applying frame time" debug message |

**Guard conditions:** Early return when session state (this+0x3FC4) is 1 or 2, or when progress timer (this+0x2C) is negative. DebugLogWrite blocked when dword_7C569C==5 (server session) or StringSplitLoop returns 0.
