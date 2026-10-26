## sub_6BAC50_006bac50 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** sub_67AB08 (0067ab08)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x58 | R | — | [LLM] |
| this | 0x5D | RW | — | [LLM] |
| this | 0x108 | R | — | [LLM] |
| this | 0x10A | RW | 1 | [LLM] |
| this | 0x116 | R | — | [LLM] |
| this | 0x15C | RW | — | [LLM] |
| this | 0x162 | RW | — | [LLM] |
| this | 0x164 | RW | — | [LLM] |
| this | 0x166 | RW | — | [LLM] |
| this | 0x168 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x5D: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x10A: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x15C: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x162: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x164: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x166: [LLM: written once/conditional/recalc every frame? would an external poke survive?]
- this 0x168: [LLM: written once/conditional/recalc every frame? would an external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00745664 | aTrnsChunkNotAl | R | [LLM] |
| 00745690 | aIncorrectTrnsC | R | [LLM] |
| 007456ac | aDuplicateTrnsC | R | [LLM] |
| 007456c4 | aInvalidTrnsAft | R | [LLM] |
| 007456dc | aZeroLengthTrns | R | [LLM] |
| 007456f4 | aMissingPlteBef_0 | R | [LLM] |
| 00745710 | aMissingIhdrBef_3 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00679f05 | GuardedCallWithLongjmp [structural] | [LLM] |
| 00679f26 | CallbackDispatch [structural] | [LLM] |
| 0067a9c7 | sub_67A9C7 | [LLM] |
| 006b7269 | sub_6B7269 | [LLM] |
| 006b9da7 | sub_6B9DA7 | [LLM] |
| 006b9dc1 | sub_6B9DC1 | [LLM] |
| 006ba69b | sub_6BA69B | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `tRNS chunk not allowed with alpha channel`
- `Incorrect tRNS chunk length`
- `Incorrect tRNS chunk length`
- `Duplicate tRNS chunk`
- `Invalid tRNS after IDAT`
- `Zero length tRNS chunk`
- `Missing PLTE before tRNS`
- `Missing IHDR before tRNS`
