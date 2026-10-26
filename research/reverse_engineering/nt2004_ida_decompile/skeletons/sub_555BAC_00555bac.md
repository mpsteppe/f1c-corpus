## sub_555BAC_00555bac — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_54E97C (0054e97c)

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
| 005eab70 | flt_5EAB70 | R | [LLM] |
| 005f30a4 | flt_5F30A4 | R | [LLM] |
| 005f52d0 | aIgnoringIncorr | R | [LLM] |
| 005f5308 | dbl_5F5308 | R | [LLM] |
| 005f5310 | dbl_5F5310 | R | [LLM] |
| 005f5318 | aDuplicateGamaC | R | [LLM] |
| 005f5330 | aOutOfPlaceGama | R | [LLM] |
| 005f5348 | aInvalidGamaAft | R | [LLM] |
| 005f5360 | aIncorrectGamaC | R | [LLM] |
| 005f537c | aMissingIhdrBef_1 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0054e7fc | sub_54E7FC | [LLM] |
| 0054e81a | CallbackDispatch [exact] | [LLM] |
| 005509e9 | FlagSetterFloatStore [exact] | [LLM] |
| 00554ec3 | ByteArrayToInt [exact] | [LLM] |
| 00554ee6 | sub_554EE6 | [LLM] |
| 005557b6 | sub_5557B6 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Ignoring incorrect gAMA value when sRGB is also present`
- `Out of place gAMA chunk`
- `Invalid gAMA after IDAT`
- `Incorrect gAMA chunk length`
- `Missing IHDR before gAMA`
