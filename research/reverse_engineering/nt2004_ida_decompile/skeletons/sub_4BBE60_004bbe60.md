## sub_4BBE60_004bbe60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BBBD0 (004bbbd0), sub_4FB270 (004fb270)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 1 | [LLM] |
| this | 0x1 | RW | 0 | [LLM] |
| this | 0x4 | RW | 1 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | — | [LLM] |
| this | 0x10 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd348 | off_5FD348 | R | [LLM] |
| 007d74e0 | flt_7D74E0 | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042c000 | sub_42C000 | [LLM] |
| 004bbf40 | sub_4BBF40 | [LLM] |
| 004edfe0 | sub_4EDFE0 | [LLM] |
| 004eec20 | sub_4EEC20 | [LLM] |
| 004eec50 | sub_4EEC50 | [LLM] |
| 004eece0 | sub_4EECE0 | [LLM] |
| 0051c0e0 | sub_51C0E0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
