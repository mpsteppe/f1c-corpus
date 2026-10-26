## sub_4EDAD0_004edad0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4EABE0 (004eabe0), sub_4EC870 (004ec870), sub_4ECA90 (004eca90)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(obj+0x0) | 0x0 | R | — | [LLM] |
| *(obj+0x0) | 0xC | R | — | [LLM] |
| *(obj+0x0) | 0x1C | R | — | [LLM] |
| *(obj+0x0) | 0x28 | RW | 0 | [LLM] |
| *(obj+0x4) | 0x4 | R | — | [LLM] |
| obj | 0x0 | R | — | [LLM] |
| obj | 0x8 | R | — | [LLM] |
| this | 0x0 | RW | 0 | [LLM] |
| this | 0x4 | RW | 0 | [LLM] |
| this | 0x8 | RW | 0 | [LLM] |
| this | 0xC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- *(obj+0x0) 0x28: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007da988 | dword_7DA988 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00592310 | DestroyFree [structural] | [LLM] |
| 005be8ae | sub_5BE8AE | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x8 | == | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
