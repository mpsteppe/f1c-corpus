## sub_4ADAD0_004adad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2D4 | R | — | [LLM] |
| this | 0x2E0 | R | — | [LLM] |
| this | 0x2E4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004ade7c | jpt_4ADB1F | R | [LLM] |
| 004adf00 | byte_4ADF00 | R | [LLM] |
| 00b73afc | unk_B73AFC | R | [LLM] |
| 00b74800 | dword_B74800 | W | [LLM] |
| 00b74804 | dword_B74804 | W | [LLM] |
| 00b74f74 | unk_B74F74 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00499d90 | sub_499D90 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2E0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
