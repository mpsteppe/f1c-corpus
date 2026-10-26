## FloatToInt16SaturationPack_004b31a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VehicleOrientationFromEulerAngles (004b2dd0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | RW | — | [LLM] |
| this | 0xE | RW | — | [LLM] |
| this | 0x10 | RW | 32767 | [LLM] |

**Written-by note (persistence):**
- this 0xC: [LLM: once/conditional? does external poke survive?]
- this 0xE: [LLM: once/conditional? does external poke survive?]
- this 0x10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e714 | flt_59E714 | R | FloatToInt16QuantScale [DERIVED] |
| 005acc90 | flt_5ACC90 | R | ShortNormMin [DERIVED] |
| 005acc94 | flt_5ACC94 | R | VertexShortClampMax [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
