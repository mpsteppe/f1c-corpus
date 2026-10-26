## sub_4FAF90_004faf90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4D0D50 (004d0d50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x94 | RW | — | [LLM] |
| this | 0x98 | RW | — | [LLM] |
| this | 0xA1 | RW | 0 | [LLM] |

**Written-by note (persistence):**
- this 0x94: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x98: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0xA1: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fd650 | aBeginningPaceL | R | [LLM] |
| 0075cba8 | dword_75CBA8 | R | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |
| 007da9d0 | dbl_7DA9D0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042f950 | sub_42F950 | [LLM] |
| 0045d100 | sub_45D100 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Beginning Pace Lap`
