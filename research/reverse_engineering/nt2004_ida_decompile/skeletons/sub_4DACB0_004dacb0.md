## sub_4DACB0_004dacb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4302B0 (004302b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x874 | RW | 5 | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- *(this+0x8) 0x874: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00768504 | dword_768504 | R | [LLM] |
| 007d4490 | byte_7D4490 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d2780 | sub_4D2780 | [LLM] |
| 004d97f0 | RenderToggleRefresh [exact] | [LLM] |
| 004d9890 | sub_4D9890 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
