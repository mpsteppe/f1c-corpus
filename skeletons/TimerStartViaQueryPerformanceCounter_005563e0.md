## TimerStartViaQueryPerformanceCounter_005563e0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** EntityFlagSetSubInitChain (00551440)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |
| this | 0x34 | RW | — | [LLM] |
| this | 0x48 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x30: [LLM: once/conditional? does external poke survive?]
- this 0x34: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e23c | QueryPerformanceCounter | R | [LLM] |
| ff00000000005406 | byte_FF00000000005406 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
