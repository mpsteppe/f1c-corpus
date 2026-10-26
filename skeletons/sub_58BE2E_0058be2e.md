## sub_58BE2E_0058be2e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FloatToStringWithSignWidth (0058bdcd), UtilityFunction_bfec (0058bfec)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 45 | [LLM] |
| this | 0x1 | RW | — | [LLM] |
| this | 0x2 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005b8d80 | aE000 | R | String_E000 [DERIVED] |
| 005e6bd8 | byte_5E6BD8 | R | DecimalSeparatorChar [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058c0d0 | StringShiftByOffset | [LLM] |
| 0058fca0 | sub_58FCA0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
