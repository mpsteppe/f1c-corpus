## sub_4BEB60_004beb60 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C0A80 (004c0a80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x48 | R | — | [LLM] |
| *(this+0xB8) | 0x64 | R | — | [LLM] |
| *(this+0xC4) | 0x0 | R | — | [LLM] |
| this | 0x0 | RW | — | [LLM] |
| this | 0x40 | RW | 0 | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x40: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xC8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbb0 | dword_75CBB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd140 | sub_4BD140 | [LLM] |
| 004bd160 | sub_4BD160 | [LLM] |
| 004bec30 | sub_4BEC30 | [LLM] |
| 0059ef50 | BitClear [exact] | [LLM] |
| 0059ef60 | Bit12FlagSet [exact] | [LLM] |
| 005a2930 | sub_5A2930 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xB8) | 0x48 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
