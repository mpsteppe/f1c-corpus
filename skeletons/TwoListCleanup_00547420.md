## TwoListCleanup_00547420 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_53CAF0 (0053caf0), sub_54AC70 (0054ac70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x40) | 0x10 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0xE4 | R | — | [LLM] |
| this | 0x1A0 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x1A0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0053ab70 | SingleFieldFree | [LLM] |
| 00546370 | ArrayCleanupWithDualFree | [LLM] |
| 00557470 | EmptyStub_7470 | [LLM] |
| 00587bcf | FreeWrapper_7bcf | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
