## ShortComputation_d410_0040d410 — ShortComputation_d410

**Summary:** Complementary action to d3c0: decodes session phase, dispatches game action for phase range [7,10], computes safe reciprocal, and clears activity flag. Part of pit stop / session management system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** sub_4A00A0 (004a00a0), sub_4A0250 (004a0250), PitStopProgress (004a68b0), PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | Action ID read for GameActionStateMachine dispatch |
| this | 0x24 | RW | 0 | Activity flag byte cleared to 0 (complement of d3c0's set to 1) |

**Written-by note (persistence):**
- this 0x24: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] — input to SafeDivisionWithZeroGuard |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00408450 | SafeDivisionWithZeroGuard | Computes safe reciprocal (1.0/0.5) guarded against zero input |
| 0040cd60 | SessionPhaseDecode | Decodes current session phase identifier |
| 0040cde0 | GameActionStateMachine | Dispatches game action state machine with action ID from this[4] |

**Guard conditions:** Decoded phase must be in range [7,10] → dispatch GameActionStateMachine. Otherwise → skip action dispatch.
