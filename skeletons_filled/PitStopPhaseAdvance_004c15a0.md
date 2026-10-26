## PitStopPhaseAdvance_004c15a0 — SessionPhaseAdvance

**Summary:** Advances a session phase counter (0xB14C) from 1 through 7. At phase 7, triggers race standings/rankings computation and timer countdown with state transition. Each step zeros a flag byte at 0xB150.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0590 (004a0590), sub_4A0760 (004a0760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB14C | RW | 7 | session phase counter (1-7), incremented each call |
| this | 0xB150 | RW | 0 | phase flag byte, zeroed on every transition |

**Written-by note (persistence):**
- this 0xB14C: set to next phase value unconditionally per call — external poke survives
- this 0xB150: set to 0 unconditionally — external poke survives

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c1644 | jpt_4C15B3 | R | jump table for switch cases 1-7 |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c1660 | j_RaceStandingsRankingsComputation | compute race standings and rankings (called at phase 7) |
| 004c1670 | TimerCountdownWithStateTransition | start timer countdown and transition session state (called at phase 7) |

**Guard conditions:** No explicit guard. Switch on value at this+0xB14C matches cases 1-7. Any unhandled value falls through to default which zeros byte at 0xB150.
