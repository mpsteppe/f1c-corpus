## sub_6BAB6C_006bab6c — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AB08 (0067ab08)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | [LLM] |
| this | 0x130 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006f2378 | dbl_6F2378 | R | [LLM] |
| 007205d0 | dbl_7205D0 | R | [LLM] |
| 00724bec | flt_724BEC | R | [LLM] |
| 0074550c | aIgnoringIncorr | R | [LLM] |
| 00745548 | dbl_745548 | R | [LLM] |
| 007455d0 | aUnknownSrgbInt | R | [LLM] |
| 007455e4 | aDuplicateSrgbC | R | [LLM] |
| 007455fc | aOutOfPlaceSrgb | R | [LLM] |
| 00745614 | aInvalidSrgbAft | R | [LLM] |
| 0074562c | aIncorrectSrgbC | R | [LLM] |
| 00745648 | aMissingIhdrBef_2 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | [LLM] |
| 00679f26 | CallbackDispatch [structural] | [LLM] |
| 0067a98e | sub_67A98E | [LLM] |
| 006b9dc1 | sub_6B9DC1 | [LLM] |
| 006ba69b | sub_6BA69B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Ignoring incorrect gAMA value when sRGB is also present`
- `Unknown sRGB intent`
- `Duplicate sRGB chunk`
- `Out of place sRGB chunk`
- `Invalid sRGB after IDAT`
- `Incorrect sRGB chunk length`
- `Missing IHDR before sRGB`
