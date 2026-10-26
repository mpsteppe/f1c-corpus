## CollisionResponseWithRandomPerturbation_00457a00 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** CameraShake (0040adb0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x90 | R | — | [LLM] |
| this | 0x94 | R | — | [LLM] |
| this | 0x98 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e670 | flt_59E670 | R | SentinelFlagConstant [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00456010 | UtilityFunction_6010 | [LLM] |
| 00456130 | VectorCopy | [LLM] |
| 00457b00 | StateActivatedPositionSaveRestore | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
