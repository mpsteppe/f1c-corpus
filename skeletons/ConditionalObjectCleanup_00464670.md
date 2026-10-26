## ConditionalObjectCleanup_00464670 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameExit (0042db20)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x3FB8 | RW | 0 | [LLM] |
| obj | 0x417C | R | — | [LLM] |
| obj | 0x1B79C | RW | 0 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0x3FB8: [LLM: once/conditional? does external poke survive?]
- obj 0x1B79C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a8b0 | VTableCallViaOffset0x7c | [LLM] |
| 0057ab20 | PointerCheckWithFallback | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
