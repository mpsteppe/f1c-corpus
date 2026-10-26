## sub_4D1CF0_004d1cf0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D20A0 (004d20a0), sub_4D20D0 (004d20d0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | 18446744073709546080 | [LLM] |
| this | 0x200 | RW | 18446744073709546080 | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x200: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d206c | jpt_4D1CFF | R | [LLM] |
| 005ea604 | flt_5EA604 | R | [LLM] |
| 005ea658 | dbl_5EA658 | R | [LLM] |
| 005ea660 | dbl_5EA660 | R | [LLM] |
| 005ea668 | dbl_5EA668 | R | [LLM] |
| 005ea670 | dbl_5EA670 | R | [LLM] |
| 005ea678 | dbl_5EA678 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005be8bc | __ftol | [LLM] |
| 005bef20 | __CIpow | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
