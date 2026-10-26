## sub_6C5CC7_006c5cc7 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x88 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x34 | R | — | [LLM] |
| this | 0x38 | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x4C | R | — | [LLM] |
| this | 0x50 | R | — | [LLM] |
| this | 0x60 | R | — | [LLM] |
| this | 0x88 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x100 | R | — | [LLM] |
| this | 0x13C | R | — | [LLM] |
| this | 0x154 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00747288 | aMaximumConstan | R | [LLM] |
| 00747350 | aMaximumSampler | R | [LLM] |
| 0074768c | aMaximumPredica | R | [LLM] |
| 007476e0 | aMaximumTempReg | R | [LLM] |
| 00747708 | aInternalErrorU_11 | R | [LLM] |
| 00747738 | aTargetDoesNotS | R | [LLM] |
| 00747764 | aMaximumLoopReg | R | [LLM] |
| 0074778c | aMaximumBoolReg | R | [LLM] |
| 01000000 | dword_1000000 | R | [LLM] |
| 02000000 | dword_2000000 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00686791 | sub_686791 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `maximum constant register index exceeded - Try reducing number of constants referenced`
- `maximum sampler register index exceeded`
- `maximum predicate register index exceeded`
- `maximum temp register index exceeded`
- `internal error: unexpected input register type`
- `target does not support relative addressing`
- `maximum loop register index exceeded`
- `maximum bool register index exceeded`
