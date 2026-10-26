## ShortComputation_7dd0_00407dd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SettingsSaveWrapper (00405030)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x18)+0x0) | 0x0 | R | — | [LLM] |
| *(this+0x18) | 0x0 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x20 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x20: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00406640 | ConditionalMatchTrigger | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
