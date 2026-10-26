## StateFlagComputation_004f9b30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** MultiStepInitSequence (00495020), sub_495080 (00495080), SceneEntityCleanup (00497100), sub_4FA7E0 (004fa7e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |
| 008afe72 | byte_8AFE72 | W | AudioInitSuccessFlag [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9b20 | sub_4F9B20 | [LLM] |
| 0055c060 | CallWrapper_c060 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
