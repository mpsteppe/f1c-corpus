## sub_4BAF20_004baf20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4BB3F0 (004bb3f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x22C | RW | 0 | [LLM] |
| this | 0x2EC | RW | 0 | [LLM] |
| this | 0x2F0 | RW | 9 | [LLM] |
| this | 0x2F4 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x22C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2EC: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2F0: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x2F4: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004bafcc | jpt_4BAF33 | R | [LLM] |
| 00b73aa4 | dword_B73AA4 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004bad70 | sub_4BAD70 | [LLM] |
| 004ce500 | sub_4CE500 | [LLM] |
| 004d0b20 | sub_4D0B20 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
