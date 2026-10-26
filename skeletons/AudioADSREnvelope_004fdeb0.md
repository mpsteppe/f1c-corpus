## AudioADSREnvelope_004fdeb0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4FCEE0 (004fcee0), WeatherConditionsFileWriter (004fe820), AudioEventRingBufferProcessing (004feaf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x44) | 0x0 | R | — | [LLM] |
| *(this+0x44) | 0x4 | R | — | [LLM] |
| *(this+0x44) | 0x8 | R | — | [LLM] |
| this | 0x38 | RW | — | [LLM] |
| this | 0x3C | R | — | [LLM] |
| this | 0x40 | R | — | [LLM] |
| this | 0x44 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x38: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e84c | flt_59E84C | R | VelocityRateLimit [DERIVED] (also: ` — display message threshold) |
| 0059e864 | flt_59E864 | R | ColorQuantScale [DERIVED] (also: ` — Quantization scale for color channels) |
| 005accb0 | flt_5ACCB0 | R | ClutchCatchSpeedScale [DERIVED] |
| 005ad30c | flt_5AD30C | R | Unknown_Float_DamperDecay [DERIVED] |
| 005ad310 | flt_5AD310 | R | BrakeForceAccumCoeff [DERIVED] |
| 005ad314 | flt_5AD314 | R | TractionControlMultiplier [DERIVED] |
| 005ad318 | flt_5AD318 | R | PhysicsDecay_LinearConst [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004fd6f0 | RangeInterpolationTable | [LLM] |
| 004fde00 | sub_4FDE00 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
