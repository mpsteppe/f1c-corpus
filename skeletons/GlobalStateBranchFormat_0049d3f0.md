## GlobalStateBranchFormat_0049d3f0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SteeringWheelAnimation (0049d070)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x10 | R | — | [LLM] |
| this | 0x64 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ccec8 | a3d | R | FormatStringToken [DERIVED] (also: format string) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007d0474 | byte_7D0474 | R | UITextEncodingFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0049b900 | SpeedMagnitude | [LLM] |
| 0049b950 | SpeedMagnitude_b950 | [LLM] |
| 00553070 | sub_553070 | [LLM] |
| 0058815f | StringFormatWithBufferOverflowCheck | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
