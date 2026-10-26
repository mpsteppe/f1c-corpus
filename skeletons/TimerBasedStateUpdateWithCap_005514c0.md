## TimerBasedStateUpdateWithCap_005514c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LinkedListTraversalWithConditionalTimerUpdate (00551760)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1C) | 0x8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |
| this | 0x1C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x8: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00551210 | sub_551210 | [LLM] |
| 00551440 | EntityFlagSetSubInitChain | [LLM] |
| 00551480 | AudioFlagSet | [LLM] |
| 005514a0 | FlagUpdateWithCascade | [LLM] |
| 00556440 | HighResolutionTimerReset | [LLM] |
| 005565b0 | HighPrecisionTimerCounterArithmetic | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
