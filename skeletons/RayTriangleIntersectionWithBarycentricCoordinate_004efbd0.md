## RayTriangleIntersectionWithBarycentricCoordinate_004efbd0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapSplitTimeEvent (004bc390)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x34AC | R | — | [LLM] |
| this | 0x34B0 | R | — | [LLM] |
| this | 0x34B4 | R | — | [LLM] |
| this | 0x34B8 | R | — | elapsedTime (alt) [CONFIRMED] |
| this | 0x34BC | R | — | [LLM] |
| this | 0x34C0 | R | — | [LLM] |
| this | 0x34C4 | R | — | [LLM] |
| this | 0x34C8 | R | — | [LLM] |
| this | 0x34CC | R | — | [LLM] |
| this | 0x34D0 | R | — | [LLM] |
| this | 0x34D4 | R | — | [LLM] |
| this | 0x34D8 | R | — | [LLM] |
| this | 0x34DC | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004ec020 | F_3DVectorAddition | [LLM] |
| 004ed710 | Vec3Add | [LLM] |
| 004ed750 | F_3DCrossProduct | [LLM] |
| 004ed7b0 | F_33MatrixVectorMultiply | [LLM] |
| 004ef680 | RideHeightDelta | [LLM] |
| 004efee0 | sub_4EFEE0 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
