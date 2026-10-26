## sub_4DEBE0_004debe0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4DDB70 (004ddb70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xD8 | R | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |
| this | 0xE4 | RW | 18446744073709551615 | [LLM] |
| this | 0xE8 | R | — | [LLM] |
| this | 0xEC | R | — | [LLM] |
| this | 0xF0 | R | — | [LLM] |
| this | 0xF4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xDC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xE4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005d54dc | flt_5D54DC | R | [LLM] |
| 005d54e0 | flt_5D54E0 | R | [LLM] |
| 005d5708 | flt_5D5708 | R | [LLM] |
| 005d5adc | flt_5D5ADC | R | [LLM] |
| 005fc8d8 | aDangerousDrivi | R | [LLM] |
| 00629328 | flt_629328 | R | [LLM] |
| 0062bf68 | unk_62BF68 | R | [LLM] |
| 0075cbb0 | dword_75CBB0 | R | [LLM] |
| 007671cc | dword_7671CC | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041b4e0 | sub_41B4E0 | [LLM] |
| 004dc580 | sub_4DC580 | [LLM] |
| 004dc690 | sub_4DC690 | [LLM] |
| 004dccc0 | sub_4DCCC0 | [LLM] |
| 0051c630 | sub_51C630 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Dangerous Driving`
- `Dangerous Driving`
- `Dangerous Driving`
- `Dangerous Driving`
