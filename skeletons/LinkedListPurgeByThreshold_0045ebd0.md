## LinkedListPurgeByThreshold_0045ebd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetCommSessionMessageDispatcher (0045d890)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x1B770) | 0x0 | R | — | [LLM] |
| *(this+0x1B774) | 0x0 | R | — | [LLM] |
| this | 0x1B770 | RW | — | [LLM] |
| this | 0x1B774 | RW | — | [LLM] |
| this | 0x1B778 | RW | 0 | [LLM] |
| this | 0x1B77C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1B770: [LLM: once/conditional? does external poke survive?]
- this 0x1B774: [LLM: once/conditional? does external poke survive?]
- this 0x1B778: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B770 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
