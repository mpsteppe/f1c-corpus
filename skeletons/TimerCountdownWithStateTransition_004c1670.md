## TimerCountdownWithStateTransition_004c1670 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** PitStopPhaseAdvance (004c15a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xB144 | RW | 3 | [LLM] |
| this | 0xB148 | R | — | [LLM] |
| this | 0xB14C | RW | 1 | [LLM] |
| this | 0xB150 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0xB144: [LLM: once/conditional? does external poke survive?]
- this 0xB14C: [LLM: once/conditional? does external poke survive?]
- this 0xB150: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004c1190 | SceneOrderReader | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
