## UIListSelectionHandler_00489ab0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** DualCallWrapper_af00 (0046af00), UIListSearchAndSelect (00489ba0), UIListManagementHandler (0048a3c0), SessionStateDispatch (004a0df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x14C | RW | — | [LLM] |
| this | 0x164 | R | — | [LLM] |
| this | 0x168 | RW | 18446744073709551615 | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x1CC | R | — | [LLM] |
| this | 0x1D4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x14C: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00489d00 | sub_489D00 | [LLM] |
| 00489e90 | FloatToIntConversion | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
