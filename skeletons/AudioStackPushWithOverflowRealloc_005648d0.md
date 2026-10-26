## AudioStackPushWithOverflowRealloc_005648d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** NetworkConnection (00563260), DisplayModeQueryWrapper (005633d0), SingleFunctionCallWrapper_48c0 (005648c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005648b0 | LinearInterpolation | [LLM] |
| 00564930 | AccumulatorWithReallocOnGrowth | [LLM] |
| 00564960 | AlignedMemoryCopyFromStructBuffer | [LLM] |
| 0058b130 | sub_58B130 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
