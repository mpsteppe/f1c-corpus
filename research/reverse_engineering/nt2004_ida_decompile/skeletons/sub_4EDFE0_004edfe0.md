## sub_4EDFE0_004edfe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_42F950 (0042f950), sub_4BBDC0 (004bbdc0), sub_4BBE60 (004bbe60), sub_4EE160 (004ee160)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4404 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x4404: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbb0 | dword_75CBB0 | R | [LLM] |
| 0075cbb4 | dword_75CBB4 | R | [LLM] |
| 007d7428 | byte_7D7428 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00421180 | sub_421180 | [LLM] |
| 004c1940 | sub_4C1940 | [LLM] |
| 004c1960 | sub_4C1960 | [LLM] |
| 004dc2c0 | sub_4DC2C0 | [LLM] |
| 004dd970 | sub_4DD970 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 004f8f90 | sub_4F8F90 | [LLM] |
| 00514eb0 | sub_514EB0 | [LLM] |
| 0051be20 | sub_51BE20 | [LLM] |
| 0051c0e0 | sub_51C0E0 | [LLM] |
| 0051e820 | sub_51E820 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
