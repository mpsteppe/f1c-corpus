## TimerFrameRateThrottle_004d3740 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 005f070c | unk_5F070C | R | VEH[0].0x4034 [LLM: field purpose] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00424cd0 | AICommandMessageQueueDispatcher | [LLM] |
| 004bc390 | LapSplitTimeEvent | [LLM] |
| 0054c150 | FlagPropertyGetter | [LLM] |
| 0054fae0 | BufferEntryClear | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
