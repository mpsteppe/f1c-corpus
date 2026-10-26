## sub_4DEA70_004dea70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DD490 (004dd490), sub_4EE5C0 (004ee5c0), sub_4F99C0 (004f99c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x8 | RW | 5 | [LLM] |
| this | 0x11C | RW | 0 | [LLM] |
| this | 0x11D | RW | 1 | [LLM] |
| this | 0x120 | RW | 0 | [LLM] |
| this | 0x124 | RW | 0 | [LLM] |
| this | 0x128 | RW | 0 | [LLM] |
| this | 0x12C | RW | 0 | [LLM] |
| this | 0x130 | RW | 18446744073701163007 | [LLM] |
| this | 0x134 | RW | 2147483647 | [LLM] |
| this | 0x138 | RW | 18446744073701163007 | [LLM] |
| this | 0x148 | RW | 18446744073709551517 | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x11D: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x120: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x124: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x128: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x12C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x130: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x134: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x138: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x148: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbb4 | dword_75CBB4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00421590 | sub_421590 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | != | 10 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
