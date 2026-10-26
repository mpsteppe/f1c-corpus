## sub_6BAA21_006baa21 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AB08 (0067ab08)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x58: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007454dc | aIncorrectIendC | R | [LLM] |
| 007454f8 | aNoImageInFile | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | [LLM] |
| 00679f26 | CallbackDispatch [structural] | [LLM] |
| 006ba69b | sub_6BA69B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Incorrect IEND chunk length`
- `No image in file`
