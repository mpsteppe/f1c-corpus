## sub_5BCC00_005bcc00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x74) | 0x0 | R | — | [LLM] |
| *(this+0x74) | 0x4 | R | — | [LLM] |
| this | 0x0 | RW | 2 | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0x78 | RW | — | [LLM] |
| this | 0x478 | RW | 0 | [LLM] |
| this | 0x47C | RW | 18446744073709551615 | [LLM] |
| this | 0x480 | R | — | [LLM] |
| this | 0x484 | R | — | [LLM] |
| this | 0x490 | RW | — | [LLM] |
| this | 0x498 | RW | — | [LLM] |
| this | 0x49C | RW | — | [LLM] |
| this | 0x5B4 | R | — | [LLM] |
| this | 0x5B8 | RW | 5 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x78: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x478: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x47C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x490: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x498: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x49C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x5B8: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005bcf1c | jpt_5BCC1E | R | [LLM] |
| 007feec0 | dword_7FEEC0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00577650 | sub_577650 | [LLM] |
| 005bc130 | sub_5BC130 | [LLM] |
| 005bcf30 | sub_5BCF30 | [LLM] |
| 005bcfc0 | sub_5BCFC0 | [LLM] |
| 005bdad0 | sub_5BDAD0 | [LLM] |
| 005be100 | sub_5BE100 | [LLM] |
| 005be1c0 | sub_5BE1C0 | [LLM] |
| 005be770 | sub_5BE770 | [LLM] |
| 005c2590 | _memcpy | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x47C | != | 18446744073709551615 | [LLM] |
| this | 0x47C | == | 18446744073709551615 | [LLM] |
| this | 0x498 | == | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
