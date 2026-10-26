## CommandQueueResponseHandler_00429ee0 — CommandQueueResponseHandler

**Summary:** Processes dequeued AI commands by checking for each command type via PairArrayLinearSearch. Handles phase-3 cleanup, session-type-dependent parameter setting (cmd 0), parameter reset (cmd 5, 99999), state flag set (cmd 4, 14), and phase-4 speed delta reset. Updates driverStatus, reset flags, and calls parameter/wrapper functions.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** AICommandMessageQueueDispatcher (00424cd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x443C | RW | 1 | AI state flag — set to 1 by commands 4 and 14 |
| this | 0x4510 | RW | 5 | driverStatus [CONFIRMED] — set to 5 when command 0 processed |
| this | 0x4544 | RW | 1 | reset flag — cleared by phase-3, cmd 0, cmd 14; set by cmd 5 and phase 4 |

**Written-by note (persistence):**
- this 0x443C: recalc every frame — external poke does NOT persist
- this 0x4510: recalc every frame — external poke does NOT persist
- this 0x4544: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] — checked for value != 7 (non-race session) for cmd 0 handling |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase 3 or 4 trigger special handling) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424e30 | PairArrayLinearSearch | searches command queue for specific command IDs (0, 4, 5, 14) |
| 0042ac90 | WrapPlayerCallback | wraps up player session callback (phase 3 cleanup) |
| 0042aca0 | AISpeedDeltaSetter | sets AI speed delta (1 for cmd 0, 0 for phase 4) |
| 0042acd0 | ParameterValueSetter | sets parameter value (18, 99999) |
| 0042adb0 | SessionCleanupFlagClear | clears session cleanup flags |

**Guard conditions:** No function-level guard — each command block conditional on PairArrayLinearSearch result and global state checks (race phase, session type). Race phase 3 triggers cleanup unconditionally at function start.
