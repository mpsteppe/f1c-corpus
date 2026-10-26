## SteeringInputSmoothingWithSaturation_004569b0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xA0 | RW | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xA0: [LLM: once/conditional? does external poke survive?]
- this 0xBC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |
| 0059ef84 | flt_59EF84 | R | Flt_CameraOffset [DERIVED] |
| 0059ef88 | flt_59EF88 | R | Unknown_Float_59EF88 [DERIVED] |
| 0059efa8 | flt_59EFA8 | R | TwoPI [DERIVED] (also: ` -- 2*PI (full-range) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0058957a | InterruptDispatch | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
