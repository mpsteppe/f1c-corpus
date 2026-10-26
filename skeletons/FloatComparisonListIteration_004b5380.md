## FloatComparisonListIteration_004b5380 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4B9000 (004b9000)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x20)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x20)+0x0) | 0x1BC | R | — | [LLM] |
| *(this+0x20) | 0x0 | R | — | [LLM] |
| *(this+0x28) | 0x4 | R | — | [LLM] |
| *(this+0x28) | 0x8 | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x28 | RW | — | [LLM] |
| this | 0x30 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x30: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b3a90 | ArithmeticComparison_3a90 | [LLM] |
| 00500190 | VehicleDataBufferClear | [LLM] |
| 005001b0 | sub_5001B0 | [LLM] |
| 005001d0 | FieldCompareConstant | [LLM] |
| 005001f0 | FloatComparisonCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
