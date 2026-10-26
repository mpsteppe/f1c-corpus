## sub_6C1CA3_006c1ca3 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_6A14B5 (006a14b5), sub_6B1163 (006b1163)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x78 | R | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x108 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00746630 | dword_746630 | R | [LLM] |
| 007466b0 | dword_7466B0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681aaa | sub_681AAA | [LLM] |
| 006bb35b | sub_6BB35B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
