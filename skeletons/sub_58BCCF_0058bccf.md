## sub_58BCCF_0058bccf — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x1 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]
- this 0x1: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005e69c8 | off_5E69C8 | R | CharTypeTable [DERIVED] |
| 005e6bd4 | cbMultiByte | R | CharTypeTableVersion [DERIVED] (also: CharTypeTableVersion (docs/08, 12, 20) |
| 005e6bd8 | byte_5E6BD8 | R | DecimalSeparatorChar [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058b465 | sub_58B465 | [LLM] |
| 0058c674 | CharacterEncodingConvertViaLookupTableFallback | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
