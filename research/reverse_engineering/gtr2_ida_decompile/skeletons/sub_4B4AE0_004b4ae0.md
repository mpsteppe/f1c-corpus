## sub_4B4AE0_004b4ae0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x114 | R | — | [LLM] |
| this | 0x118 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x118: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00b70774 | byte_B70774 | W | [LLM] |
| 00b70776 | byte_B70776 | R | [LLM] |
| 00b70777 | byte_B70777 | R | [LLM] |
| 00b707a4 | byte_B707A4 | W | [LLM] |
| 00b707a6 | byte_B707A6 | R | [LLM] |
| 00b707a7 | byte_B707A7 | R | [LLM] |
| 00b70804 | byte_B70804 | W | [LLM] |
| 00b70806 | byte_B70806 | R | [LLM] |
| 00b70807 | byte_B70807 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004a7340 | sub_4A7340 | [LLM] |
| 004cd650 | ByteFieldGetterAt100 [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x114 | == | 766 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
