## sub_4DC2C0_004dc2c0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EDFE0 (004edfe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x40C8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x18 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x1C | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x20 | RW | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x24 | RW | 0 | [LLM] |
| this | 0x74 | RW | 1 | [LLM] |
| this | 0xBC | RW | 0 | [LLM] |
| this | 0xC0 | RW | 0 | [LLM] |
| this | 0xC8 | RW | 0 | [LLM] |
| this | 0xCC | RW | 0 | [LLM] |
| this | 0xD0 | RW | 0 | [LLM] |
| this | 0xD4 | RW | 0 | [LLM] |
| this | 0xD8 | RW | 0 | [LLM] |
| this | 0xDC | RW | 18446744073701163007 | [LLM] |
| this | 0xE0 | RW | 18446744073701163007 | [LLM] |
| this | 0xE4 | RW | 18446744073709551615 | [LLM] |
| this | 0xE8 | RW | 0 | [LLM] |
| this | 0xEC | RW | 0 | [LLM] |
| this | 0xF0 | RW | 0 | [LLM] |
| this | 0xF4 | RW | 0 | [LLM] |
| this | 0xF8 | RW | 0 | [LLM] |
| this | 0x114 | RW | 0 | [LLM] |
| this | 0x118 | RW | 0 | [LLM] |
| this | 0x148 | RW | 18446744073709551614 | [LLM] |

**Written-by note (persistence):**
- this 0x18: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x1C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x20: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x24: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xBC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xCC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xD0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xD4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xD8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xF8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x114: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x118: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x148: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbb0 | dword_75CBB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004deb50 | sub_4DEB50 | [LLM] |
| 00515870 | sub_515870 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x40C8 | <= | 1 | [LLM] |
| this | 0x74 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
