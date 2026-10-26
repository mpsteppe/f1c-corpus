## RandomNoiseTableInitialization_004b3bd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GameFileLoader (0042d260)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x0: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e0d4 | __imp_GetTickCount | R | [LLM] |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e6e0 | flt_59E6E0 | R | RandomScalingFactor [DERIVED] |
| 005accf0 | flt_5ACCF0 | R | RandomRangeScale [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0055687b | RDTSCTimestampRead | [LLM] |
| 005884e0 | TLSFieldSetter | [LLM] |
| 005884ed | RandLCGRandomNumberGenerator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
