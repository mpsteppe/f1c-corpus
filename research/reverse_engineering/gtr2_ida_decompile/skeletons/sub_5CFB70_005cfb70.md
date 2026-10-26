## sub_5CFB70_005cfb70 — [LLM: short descriptive name]

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
| 006ebbb1 | SEH_5CFB70 | R | [LLM] |
| 0072a3ac | aPassedActorSee | R | [LLM] |
| 0072a450 | aCanTFindShared | R | [LLM] |
| 0072b10c | aParentS | R | [LLM] |
| 0072b120 | aNodeNameS_0 | R | [LLM] |
| 0072b1a8 | aShearXyFXzFYzF | R | [LLM] |
| 0072b1cc | aScaleOrientXFY | R | [LLM] |
| 0072b1f8 | aScaleXFYFZF_0 | R | [LLM] |
| 0072b220 | aRotationXFYFZF | R | [LLM] |
| 0072b24c | aPositionXFYFZF_0 | R | [LLM] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 005a8840 | sub_5A8840 | [LLM] |
| 005bd430 | sub_5BD430 | [LLM] |
| 005be270 | sub_5BE270 | [LLM] |
| 005be610 | sub_5BE610 | [LLM] |
| 005c00f0 | sub_5C00F0 | [LLM] |
| 005c0780 | sub_5C0780 | [LLM] |
| 005c7280 | sub_5C7280 | [LLM] |
| 005cc900 | sub_5CC900 | [LLM] |
| 00630739 | ??2@YAPAXI@Z | [LLM] |
| 00643e40 | sub_643E40 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]

**String literals referenced (deterministic):**

- `Passed actor seems to be not valid!`
- `Can't find shared data.`
- `    + Parent = '%s'`
- `- Node name = '%s'`
- `    + Shear:			xy=%f, xz=%f, yz=%f`
- `    + Scale Orient:  x=%f, y=%f, z=%f, w=%f`
- `    + Scale:         x=%f, y=%f, z=%f`
- `    + Rotation:      x=%f, y=%f, z=%f, w=%f`
- `    + Position:      x=%f, y=%f, z=%f`
