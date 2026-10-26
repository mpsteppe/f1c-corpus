## AudioStreamConstructWithVTableInit_00581e80 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x12C | RW | 0 | [LLM] |
| this | 0x130 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x12C: [LLM: once/conditional? does external poke survive?]
- this 0x130: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059cbc8 | SEH_581E80 | R | [LLM] |
| 005b8b3c | off_5B8B3C | R | VTable_5B8B3C [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0057a160 | ConstructorVTableSetInit | [LLM] |
| 0057a1e0 | SmallStructFieldInit | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
