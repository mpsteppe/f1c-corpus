## AngleClampWrap_004b86e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameDataFileIO (004b7300), LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), sub_4B8C40 (004b8c40), PitServiceSteeringAnimationStep (004b9e40), sub_4BA1F0 (004ba1f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF30 | R | — | [LLM] |
| this | 0xF34 | R | — | [LLM] |
| this | 0xF38 | RW | — | [LLM] |
| this | 0xF3C | RW | — | [LLM] |
| this | 0xF81 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xF38: [LLM: once/conditional? does external poke survive?]
- this 0xF3C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
