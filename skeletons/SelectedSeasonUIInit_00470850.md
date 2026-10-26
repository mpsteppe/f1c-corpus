## SelectedSeasonUIInit_00470850 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x31C | RW | 401 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x31C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005a0540 | off_5A0540 | R | [LLM] |
| 005be704 | off_5BE704 | R | UITextHandle_5be704 [DERIVED] (also: ` — UI/text handle) |
| 005c6e58 | aSelectedSeason | R | [LLM] |
| 005c6e68 | aTimeScaled | R | [LLM] |
| 005c6e74 | aNormal_0 | R | Str_Normal [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00470960 | SessionSetupScreenSetup | [LLM] |
| 00486f30 | LinkedListInsertWithNodeAllocation | [LLM] |
| 0048c070 | sub_48C070 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
