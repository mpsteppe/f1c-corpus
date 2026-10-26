## MenuLayoutCalculator_00467dc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xEC | RW | — | [LLM] |
| this | 0x108 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xEC: [LLM: once/conditional? does external poke survive?]
- this 0x108: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea438 | byte_5EA438 | R | unknown directory/file path [DERIVED] (also: ` — default application directory) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00467e40 | CreditsTxtParser | [LLM] |
| 00467f90 | HTMLOutputSectionProcessor | [LLM] |
| 00497ad0 | sub_497AD0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
