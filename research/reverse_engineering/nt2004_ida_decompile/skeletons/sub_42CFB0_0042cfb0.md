## sub_42CFB0_0042cfb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x5308) | 0x62A0 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |
| this | 0x4620 | R | — | [LLM] |
| this | 0x4718 | R | — | [LLM] |
| this | 0x4810 | R | — | [LLM] |
| this | 0x4908 | R | — | [LLM] |
| this | 0x5194 | R | — | [LLM] |
| this | 0x5308 | R | — | [LLM] |
| this | 0x5D74 | R | — | [LLM] |
| this | 0x5D9C | R | — | [LLM] |
| this | 0x5DA8 | R | — | [LLM] |
| this | 0x5DAC | R | — | [LLM] |
| this | 0x5DB4 | R | — | [LLM] |
| this | 0x5DB8 | R | — | [LLM] |
| this | 0x5DBC | R | — | [LLM] |
| this | 0x5DD4 | R | — | [LLM] |
| this | 0x5E5C | RW | — | [LLM] |
| this | 0x5E60 | RW | — | [LLM] |
| this | 0x5E64 | RW | 0 | [LLM] |
| this | 0x5E68 | RW | — | [LLM] |
| this | 0x5E6C | RW | — | [LLM] |
| this | 0x5EDC | RW | — | [LLM] |
| this | 0x5EE4 | RW | 1 | [LLM] |
| this | 0x5EEC | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x5E5C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5E60: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5E64: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5E68: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5E6C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5EDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5EE4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5EEC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d54e4 | flt_5D54E4 | R | [LLM] |
| 005d54e8 | flt_5D54E8 | R | [LLM] |
| 005d54f0 | flt_5D54F0 | R | [LLM] |
| 005d54f8 | flt_5D54F8 | R | [LLM] |
| 005d5510 | flt_5D5510 | R | [LLM] |
| 005d5914 | flt_5D5914 | R | [LLM] |
| 005d5adc | flt_5D5ADC | R | [LLM] |
| 005d5ba0 | flt_5D5BA0 | R | [LLM] |
| 005d5be0 | flt_5D5BE0 | R | [LLM] |
| 005d5bfc | flt_5D5BFC | R | [LLM] |
| 005d5d04 | flt_5D5D04 | R | [LLM] |
| 005d5d84 | flt_5D5D84 | R | [LLM] |
| 005d5d88 | flt_5D5D88 | R | [LLM] |
| 005fd1f8 | flt_5FD1F8 | R | [LLM] |
| 005fd340 | NumOfElements | R | [LLM] |
| 0075aad0 | dword_75AAD0 | R | [LLM] |
| 007d7928 | dword_7D7928 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005be8bc | __ftol | [LLM] |
| 005bf36d | _rand | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x5DD4 | == | 11 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
