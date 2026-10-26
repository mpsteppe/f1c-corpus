## ArithmeticComparison_2dc0_004c2dc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4C29F0 (004c29f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x2C | RW | 1 | [LLM] |
| this | 0x50 | RW | 1123024896 → 120.0f | [LLM] |

**Written-by note (persistence):**
- this 0x2C: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e968 | flt_59E968 | R | AIQualifyPushFrequency [DERIVED] |
| 005acb00 | flt_5ACB00 | R | Threshold_LowerBound_5ACB00 [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
