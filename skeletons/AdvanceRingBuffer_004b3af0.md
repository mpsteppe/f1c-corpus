## AdvanceRingBuffer_004b3af0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** InputCommandDispatchToEntities (0045f4a0), TeamRadioNetworkMessageProcessing (0045f710), PitTimingUpdate (004b7a90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x6C004 | R | — | [LLM] |
| this | 0x6C008 | R | — | [LLM] |
| this | 0x6C00C | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x6C00C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
