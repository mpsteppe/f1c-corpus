## PitStopPhaseAdvance_004c15a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4A0590 (004a0590), sub_4A0760 (004a0760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB14C | RW | 7 | [LLM] |
| this | 0xB150 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xB14C: [LLM: once/conditional? does external poke survive?]
- this 0xB150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004c1644 | jpt_4C15B3 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c1660 | j_RaceStandingsRankingsComputation | [LLM] |
| 004c1670 | TimerCountdownWithStateTransition | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
