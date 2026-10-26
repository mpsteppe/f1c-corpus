## sub_4BECA0_004beca0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BEE40 (004bee40), sub_4BEF30 (004bef30), sub_4C0A80 (004c0a80), sub_4C21B0 (004c21b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0xB8) | 0x2 | R | — | [LLM] |
| *(this+0xB8) | 0x48 | R | — | [LLM] |
| *(this+0xB8) | 0x64 | R | — | [LLM] |
| *(this+0xC4) | 0x0 | R | — | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | R | — | [LLM] |
| this | 0xC8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xC0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0075cbb0 | dword_75CBB0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bd140 | sub_4BD140 | [LLM] |
| 0059ef50 | BitClear [exact] | [LLM] |
| 0059ef60 | Bit12FlagSet [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| *(this+0xB8) | 0x48 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
