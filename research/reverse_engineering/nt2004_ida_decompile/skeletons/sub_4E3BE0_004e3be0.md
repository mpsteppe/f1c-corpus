## sub_4E3BE0_004e3be0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4E44C0 (004e44c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x260 | RW | — | [LLM] |
| this | 0x268 | R | — | [LLM] |
| this | 0x26C | RW | — | [LLM] |
| this | 0x270 | RW | — | [LLM] |
| this | 0x274 | R | — | [LLM] |
| this | 0x278 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x260: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x26C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x270: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x278: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005fc158 | aSeasonscoringi | R | [LLM] |
| 007685d0 | dword_7685D0 | R | [LLM] |
| 0076bb88 | dword_76BB88 | R | [LLM] |
| 007d7a10 | byte_7D7A10 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004deb90 | sub_4DEB90 | [LLM] |
| 004debd0 | sub_4DEBD0 | [LLM] |
| 0057a6d0 | sub_57A6D0 | [LLM] |
| 0057a700 | sub_57A700 | [LLM] |
| 0057ae50 | sub_57AE50 | [LLM] |
| 005bebfe | _atol | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `SeasonScoringInfo`
