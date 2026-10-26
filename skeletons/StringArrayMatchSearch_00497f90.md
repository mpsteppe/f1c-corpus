## StringArrayMatchSearch_00497f90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** UICustomRenderDispatch (00489fd0), DriverNameStringHandler (00497ec0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1514 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005cc79c | dword_5CC79C | R | HashTableHead [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00587c20 | sub_587C20 | [LLM] |
| 00588410 | sub_588410 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1514 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
