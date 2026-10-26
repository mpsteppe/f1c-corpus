## MultiStepInitSequence_00495020 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** FileLoadWithRetryLoop (004f9b70)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007cde24 | dword_7CDE24 | R | TexSurfaceRef3 [DERIVED] (also: � surface 3 refs) |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004f9b30 | StateFlagComputation | [LLM] |
| 004f9f00 | ConditionalInit | [LLM] |
| 00553700 | sub_553700 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
