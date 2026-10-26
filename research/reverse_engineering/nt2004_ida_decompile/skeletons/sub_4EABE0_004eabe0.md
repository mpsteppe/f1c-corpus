## sub_4EABE0_004eabe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EA010 (004ea010), sub_4ED590 (004ed590)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x60 | RW | — | [LLM] |
| this | 0x6C | R | — | [LLM] |
| this | 0x7C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d5b0 | sub_40D5B0 | [LLM] |
| 004667a0 | LinkedListDestructorWithData [structural] | [LLM] |
| 0046df90 | sub_46DF90 | [LLM] |
| 004eace0 | sub_4EACE0 | [LLM] |
| 004eb6c0 | sub_4EB6C0 | [LLM] |
| 004edad0 | sub_4EDAD0 | [LLM] |
| 004edbe0 | sub_4EDBE0 | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |
| 005bf290 | __strcmpi | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
