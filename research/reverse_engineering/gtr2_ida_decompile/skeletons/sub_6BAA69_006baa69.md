## sub_6BAA69_006baa69 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AB08 (0067ab08)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | [LLM] |
| this | 0x130 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x130: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f1f44 | flt_6F1F44 | R | [LLM] |
| 007205d0 | dbl_7205D0 | R | [LLM] |
| 00736ccc | flt_736CCC | R | [LLM] |
| 0074550c | aIgnoringIncorr | R | [LLM] |
| 00745548 | dbl_745548 | R | [LLM] |
| 00745550 | aDuplicateGamaC | R | [LLM] |
| 00745568 | aOutOfPlaceGama | R | [LLM] |
| 00745580 | aInvalidGamaAft | R | [LLM] |
| 00745598 | aIncorrectGamaC | R | [LLM] |
| 007455b4 | aMissingIhdrBef_1 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | [LLM] |
| 00679f26 | CallbackDispatch [structural] | [LLM] |
| 0067a883 | sub_67A883 | [LLM] |
| 006b9d7d | ByteArrayToInt [structural] | [LLM] |
| 006b9dc1 | sub_6B9DC1 | [LLM] |
| 006ba69b | sub_6BA69B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Ignoring incorrect gAMA value when sRGB is also present`
- `Out of place gAMA chunk`
- `Invalid gAMA after IDAT`
- `Incorrect gAMA chunk length`
- `Missing IHDR before gAMA`
