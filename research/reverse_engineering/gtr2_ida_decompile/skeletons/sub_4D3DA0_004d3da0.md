## sub_4D3DA0_004d3da0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D4540 (004d4540), sub_4D4750 (004d4750), sub_4D4860 (004d4860)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | R | — | [LLM] |
| this | 0x230 | RW | 0 | [LLM] |
| this | 0x234 | R | — | [LLM] |
| this | 0x240 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x230: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f16c8 | flt_6F16C8 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004d0b20 | sub_4D0B20 | [LLM] |
| 0063099c | __ftol2 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
