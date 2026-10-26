## PlayerStatsDisplayCleanup_00469d30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x48) | 0x4 | R | — | [LLM] |
| this | 0x44 | RW | 0 | [LLM] |
| this | 0x48 | RW | 0 | [LLM] |
| this | 0x4C | RW | 0 | [LLM] |
| this | 0x50 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x44: [LLM: once/conditional? does external poke survive?]
- this 0x48: [LLM: once/conditional? does external poke survive?]
- this 0x4C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c6900 | aExperienceLaps | R | String_ExperienceLaps [DERIVED] |
| 005c6914 | aBestLap | R | sBestLap [DERIVED] |
| 005c6920 | aCircuit | R | StatKey_Circuit [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00469900 | sub_469900 | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 00489cb0 | StateCleanupNotification | [LLM] |
| 0048a3b0 | ByteSetterAt0xe0 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
