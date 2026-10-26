## sub_4ADAF0_004adaf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4B03F0 (004b03f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x174)+0x28) | 0x28 | RW | — | [LLM] |
| this | 0x14C | RW | — | [LLM] |
| this | 0x150 | R | — | [LLM] |
| this | 0x174 | R | — | [LLM] |

**Written-by note (persistence):**
- *(*(this+0x174)+0x28) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x14C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004adbb0 | sub_4ADBB0 | [LLM] |
| 004b0680 | sub_4B0680 | [LLM] |
| 004b0930 | sub_4B0930 | [LLM] |
| 004b0960 | sub_4B0960 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005be8e3 | ??2@YAPAXI@Z | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
