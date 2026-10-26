## sub_5BBC20_005bbc20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_5BBB80 (005bbb80), sub_5BC0A0 (005bc0a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x24 | R | — | [LLM] |
| this | 0x3C | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00624acc | dword_624ACC | R | [LLM] |
| 00624ad0 | dword_624AD0 | R | [LLM] |
| 00624ad8 | dword_624AD8 | R | [LLM] |
| 00624adc | dword_624ADC | R | [LLM] |
| 00624ae0 | dword_624AE0 | R | [LLM] |
| 00624ae4 | byte_624AE4 | R | [LLM] |
| ff00000000005e85 | byte_FF00000000005E85 | W | [LLM] |
| ff00000000005e86 | byte_FF00000000005E86 | W | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005bbbd0 | sub_5BBBD0 | [LLM] |
| 005bdb70 | GetTickCount [exact] | [LLM] |
| 005d26e6 | sendto [exact] | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `\status\`
- `\basic\\info\`
