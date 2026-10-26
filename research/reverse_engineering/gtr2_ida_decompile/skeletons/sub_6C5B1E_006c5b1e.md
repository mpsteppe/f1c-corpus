## sub_6C5B1E_006c5b1e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x100) | 0x3C | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x6E | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x124 | R | — | [LLM] |
| this | 0x128 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00742874 | aInternalErrorO_1 | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |
| 02000000 | dword_2000000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x6E | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `internal error: overlapping output writes`
