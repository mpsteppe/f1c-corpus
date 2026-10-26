## sub_6AE33E_006ae33e — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |
| this | 0xFC | RW | — | [LLM] |
| this | 0x100 | RW | — | [LLM] |
| this | 0x220 | RW | 18446744073709551615 | [LLM] |
| this | 0x224 | RW | 18446744073709551615 | [LLM] |

**Written-by note (persistence):**
- this 0xFC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x100: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x220: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x224: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006fd194 | aC_8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00681a51 | sub_681A51 | [LLM] |
| 00681aaa | sub_681AAA | [LLM] |
| 006bc1a9 | sub_6BC1A9 | [LLM] |
| 006bfab9 | sub_6BFAB9 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x220 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
