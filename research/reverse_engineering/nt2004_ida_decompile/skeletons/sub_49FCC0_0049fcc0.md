## sub_49FCC0_0049fcc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_476570 (00476570), sub_49FDB0 (0049fdb0), sub_4A0650 (004a0650), sub_4BA6B0 (004ba6b0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xA8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x90 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x178 | RW | — | [LLM] |
| this | 0x190 | R | — | [LLM] |
| this | 0x194 | RW | 18446744073709551615 | [LLM] |
| this | 0x1A8 | R | — | [LLM] |
| this | 0x1BC | R | — | [LLM] |
| this | 0x1C4 | R | — | [LLM] |
| this | 0x22C | R | — | [LLM] |
| this | 0x234 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x178: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x194: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00629120 | byte_629120 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049ff10 | sub_49FF10 | [LLM] |
| 004a0090 | sub_4A0090 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
