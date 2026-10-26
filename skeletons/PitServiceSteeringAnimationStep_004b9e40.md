## PitServiceSteeringAnimationStep_004b9e40 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** ConditionalMultiPathDispatcher (004ba180)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xF8C | RW | 5 | [LLM] |
| this | 0x0 | R | — | [LLM] |

**Written-by note (persistence):**
- obj 0xF8C: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004b9f48 | jpt_4B9E58 | R | [LLM] |
| 0059e600 | flt_59E600 | R | SteeringForceThreshold [DERIVED] |
| 005acd14 | flt_5ACD14 | R | CameraMoveMultiplier [DERIVED] |
| 005acd18 | flt_5ACD18 | R | CameraZoomMult [DERIVED] |
| 008afe90 | dbl_8AFE90 | R | EngineCoolingRate [DERIVED] (also: ` — cooling rate per frame) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004b86e0 | AngleClampWrap | [LLM] |
| 004b87a0 | QueuePeek | [LLM] |
| 004b9d00 | FloatAccumulator | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
