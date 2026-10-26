## BufferTruncationShrink_00599348 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_598E9E (00598e9e), CharValidationAgainstEncodingTableWithLocaleFall (00598fd4), sub_5990AE (005990ae), sub_599ED6 (00599ed6), FileOffsetPositionValidation (0059a01e), sub_59A103 (0059a103), sub_59A221 (0059a221), sub_59A9CA (0059a9ca)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058b130 | sub_58B130 | [LLM] |
| 00599560 | sub_599560 | [LLM] |
| 005995e5 | ConditionalStringFreeWithLengthCheck | [LLM] |
| 0059af68 | sub_59AF68 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
