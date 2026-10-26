## ShortComputation_d3c0_0040d3c0 — ShortComputation_d3c0

**Summary:** Conditional session-phase-aware action dispatcher: stores decoded phase, triggers game action for IDs 7-10, sets activity flag, and computes reciprocal with sign check. Part of pit stop / session management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStopReadyCheck (004a6200)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | RW | — | Stores decoded session phase value (v3) when action ID is in range [7,10] |
| this | 0x24 | RW | 1 | Activity flag byte set to 1 when action dispatch occurs |

**Written-by note (persistence):**
- this 0x10: recalc every frame — external poke does NOT persist
- this 0x24: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] — input to reciprocal computation |
| 007d0350 | dword_7D0350 | R | SessionActiveFlag [DERIVED] (also: ` — session active flag (near GameState DAT_007d00ec) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cd60 | SessionPhaseDecode | Decodes current session phase identifier |
| 0040cde0 | GameActionStateMachine | Dispatches game action state machine with given action ID |

**Guard conditions:** dword_7D0350 (session active) must be non-zero → proceed. a2 must be in range [7,10] → store phase + dispatch action + set flag. Phase value (v3) must be <= 5 to store into this[4].
