## sub_5CCE20_005cce20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Called by:** (none static — top-level or indirect-only)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0xC | R | — | [LLM] |
| this | 0x10 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 006eb956 | SEH_5CCE20 | R | [LLM] |
| 007299bc | asc_7299BC | R | [LLM] |
| 00729e88 | aMotionpartchun_1 | R | [LLM] |
| 00729ff0 | aPassedMotionSe | R | [LLM] |
| 0072a450 | aCanTFindShared | R | [LLM] |
| 0072a8c8 | aPoseScaleXFYFZ | R | [LLM] |
| 0072a8f0 | aPoseRotationXF | R | [LLM] |
| 0072a91c | aPosePositionXF | R | [LLM] |
| 0072af54 | aBindPoseScaleX | R | [LLM] |
| 0072af80 | aBindPoseRotati | R | [LLM] |
| 0072afb4 | aBindPosePositi | R | [LLM] |
| 0072afe0 | aMotionPartS | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004050c0 | sub_4050C0 | [LLM] |
| 005a8840 | sub_5A8840 | [LLM] |
| 005be180 | sub_5BE180 | [LLM] |
| 005be270 | sub_5BE270 | [LLM] |
| 005be610 | sub_5BE610 | [LLM] |
| 005c6150 | sub_5C6150 | [LLM] |
| 005c7220 | sub_5C7220 | [LLM] |
| 005d3270 | sub_5D3270 | [LLM] |
| 005d3300 | sub_5D3300 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 006308d3 | j__free | [LLM] |
| 00643d50 | sub_643D50 | [LLM] |
| 00643e40 | sub_643E40 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `MotionPartChunkProcessor3`
- `Passed motion seems to be not valid!`
- `Can't find shared data.`
- `    + Pose Scale:    x=%f, y=%f, z=%f`
- `    + Pose Rotation: x=%f, y=%f, z=%f, w=%f`
- `    + Pose Position: x=%f, y=%f, z=%f`
- `    + Bind Pose Scale:    x=%f, y=%f, z=%f`
- `    + Bind Pose Rotation: x=%f, y=%f, z=%f, w=%f`
- `    + Bind Pose Position: x=%f, y=%f, z=%f`
- `- Motion Part='%s'`
