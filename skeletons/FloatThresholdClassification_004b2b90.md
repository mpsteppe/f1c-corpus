## FloatThresholdClassification_004b2b90 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** VectorToShort3Conversion (004b2c80)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xF | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0xF: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e7fc | flt_59E7FC | R | BumpDampingConstant [DERIVED] (also: ` — bump damping constants) |
| 0059e908 | flt_59E908 | R | CollisionEventThreshold [DERIVED] (also: ` — collision time threshold) |
| 0059ee8c | flt_59EE8C | R | QualityThresholdHigh [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
