## AudioCodecBufferAllocation_0058f4f2 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005beb48 | word_5BEB48 | R | PathSepWord [DERIVED] |
| 005e6bd8 | byte_5E6BD8 | W | DecimalSeparatorChar [DERIVED] |
| 005e6bdc | dword_5E6BDC | W | LocaleInitFlag [DERIVED] |
| 005e9a88 | unk_5E9A88 | R | LocaleDataPtr [DERIVED] |
| 005e9ac0 | off_5E9AC0 | R | PTR_AudioStreamBuffer [DERIVED] |
| 008d3f40 | dword_8D3F40 | R | LocaleInitFlag [DERIVED] |
| 008d3f5c | dword_8D3F5C | RW | CRTLocaleAllocBlock [DERIVED] |
| 008d3f60 | dword_8D3F60 | RW | Dword_LocaleBuffer [DERIVED] |
| 008d3f64 | dword_8D3F64 | RW | LocaleBufferHandle [DERIVED] |
| 008d3f8e | word_8D3F8E | R | LocaleLanguageID [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058a935 | MallocWrapperForNhMalloc | [LLM] |
| 0058aa6f | sub_58AA6F | [LLM] |
| 0058f6c7 | InPlaceDigitCharConversionStripSemicolons | [LLM] |
| 0058fca0 | sub_58FCA0 | [LLM] |
| 005968f6 | sub_5968F6 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
