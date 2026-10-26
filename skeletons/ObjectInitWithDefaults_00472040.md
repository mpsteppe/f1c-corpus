## ObjectInitWithDefaults_00472040 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x31C | RW | 0 | [LLM] |
| this | 0x324 | RW | 32 | [LLM] |
| this | 0x328 | RW | 0 | [LLM] |
| this | 0x32C | RW | 1 | [LLM] |
| this | 0x330 | RW | 1 | [LLM] |
| this | 0x334 | RW | 252 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x31C: [LLM: once/conditional? does external poke survive?]
- this 0x324: [LLM: once/conditional? does external poke survive?]
- this 0x328: [LLM: once/conditional? does external poke survive?]
- this 0x32C: [LLM: once/conditional? does external poke survive?]
- this 0x330: [LLM: once/conditional? does external poke survive?]
- this 0x334: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a1a40 | off_5A1A40 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00466d60 | ShortComputation_6d60 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
