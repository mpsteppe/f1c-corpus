## sub_5F2CE0_005f2ce0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_46F990 (0046f990)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x44)+0x0) | 0x18 | R | — | [LLM] |
| *(this+0x44) | 0x0 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x48 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0072c65c | aNoPendingQuery | R | [LLM] |
| 0072c674 | aNoHwQueryObjec | R | [LLM] |
| 0072c6c8 | aErrorIssuingQu_0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005d8c80 | sub_5D8C80 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `No pending query for %s`
- `No hw query object for %s`
- `Error issuing query end.`
