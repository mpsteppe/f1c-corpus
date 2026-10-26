## CollisionCoefficientApplication_00456f70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4085F0 (004085f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xAC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059ef9c | flt_59EF9C | R | ForceFeedbackGain [DERIVED] |
| 0059efa0 | flt_59EFA0 | R | AudioPanLFE [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456fb0 | ClampedFloatSetter | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
