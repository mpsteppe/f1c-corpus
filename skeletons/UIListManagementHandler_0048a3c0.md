## UIListManagementHandler_0048a3c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_47C360 (0047c360)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | RW | — | [LLM] |
| this | 0x94 | RW | — | [LLM] |
| this | 0x168 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x90: [LLM: once/conditional? does external poke survive?]
- this 0x94: [LLM: once/conditional? does external poke survive?]
- this 0x168: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0048a634 | jpt_48A496 | R | [LLM] |
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004863c0 | ShortComputation_63c0 | [LLM] |
| 00486400 | UtilityFunction_6400 | [LLM] |
| 00489920 | UIScreenTextAccessor | [LLM] |
| 00489970 | UITextFormatHelper | [LLM] |
| 00489ab0 | UIListSelectionHandler | [LLM] |
| 00566650 | StringCopyWithBufferRealloc | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |
| 00587ece | sub_587ECE | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
