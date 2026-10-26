## sub_517ADC_00517adc — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_511B7C (00511b7c), sub_519019 (00519019)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x0 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | RW | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | RW | — | [LLM] |
| this | 0x1C | RW | 12 | [LLM] |
| this | 0x20 | RW | 0 | [LLM] |
| this | 0x24 | RW | — | [LLM] |
| this | 0x28 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x4: [LLM: once/conditional? does external poke survive?]
- this 0x18: [LLM: once/conditional? does external poke survive?]
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]
- this 0x24: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 00517e0b | jpt_517B19 | R | [LLM] |
| 005afa20 | aNeedDictionary | R | NeedDictionaryString [DERIVED] |
| 005afa30 | aIncorrectDataC | R | IncorrectDataChecksumString [DERIVED] |
| 005afa48 | aIncorrectHeade | R | String_IncorrectHeader [DERIVED] |
| 005afa60 | aInvalidWindowS | R | aInvalidWindowS [DERIVED] |
| 005afa74 | aUnknownCompres | R | UnknownCompres [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0052765a | sub_52765A | [LLM] |
| 00527752 | sub_527752 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
