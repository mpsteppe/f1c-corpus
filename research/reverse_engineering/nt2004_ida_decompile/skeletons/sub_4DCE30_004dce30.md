## sub_4DCE30_004dce30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_4C19D0 (004c19d0), sub_4DD490 (004dd490)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x4404 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x74 | RW | 1 | [LLM] |

**Written-by note (persistence):**
- this 0x74: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00610154 | aLapTimeWillNot | R | [LLM] |
| 0062a170 | dword_62A170 | R | [LLM] |
| 0062a17c | Destination | R | [LLM] |
| 0062a37b | byte_62A37B | W | [LLM] |
| 0075cbb0 | dword_75CBB0 | R | [LLM] |
| 00764d68 | byte_764D68 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0041f230 | BinarySearchInStringTable [structural] | [LLM] |
| 0045d100 | sub_45D100 | [LLM] |
| 004eed40 | sub_4EED40 | [LLM] |
| 005beab0 | _strncpy | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x74 | == | 2 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Lap Time Will Not Count`
- `Lap Time Will Not Count`
