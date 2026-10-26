## SuspensionWheelForceCalculation_00459070 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_458DF0 (00458df0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |
| this | 0x14 | R | — | [LLM] |
| this | 0x74 | R | — | [LLM] |
| this | 0xA8 | R | — | [LLM] |
| this | 0xAC | RW | 1065353216 → 1.0f | [LLM] |
| this | 0xB8 | R | — | [LLM] |
| this | 0xBC | R | — | [LLM] |
| this | 0xCC | R | — | [LLM] |

**Written-by note (persistence):**
- this 0xAC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456110 | F_3VectorCopyToStruct | [LLM] |
| 00456150 | StructFieldCopy | [LLM] |
| 004582c0 | GuardedFunctionWithFlagSet | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
