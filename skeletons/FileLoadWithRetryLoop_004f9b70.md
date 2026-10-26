## FileLoadWithRetryLoop_004f9b70 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4944A0 (004944a0), sub_4A00A0 (004a00a0), sub_4A0760 (004a0760), sub_4A08E0 (004a08e0), sub_4A09F0 (004a09f0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec3d0 | dword_5EC3D0 | R | SeasonParentPath [DERIVED] |
| 007ca590 | ppvOut | R | ModulePtrArray [DERIVED] |
| 007cb218 | dword_7CB218 | R | InputDeviceCount [DERIVED] |
| 007cde00 | unk_7CDE00 | R | Unknown_Render_CDE00 [DERIVED] |
| 007ce2a4 | unk_7CE2A4 | R | Unknown_Session_7CE2A4 [DERIVED] |
| 007cf2cc | flt_7CF2CC | R | DSPTransformParam [DERIVED] (also: ` — DSP transform parameter) |
| 008ac494 | byte_8AC494 | R | SceneArrayFirstSceneName [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404fe0 | OneTimeInitializationWithAtexitStyleRegistration | [LLM] |
| 00422fd0 | StringFormatReplaceOperation | [LLM] |
| 004537b0 | sub_4537B0 | [LLM] |
| 00495020 | MultiStepInitSequence | [LLM] |
| 00495060 | GuardedSubsystemRelease | [LLM] |
| 00495140 | GlobalAccessor | [LLM] |
| 004a1830 | sub_4A1830 | [LLM] |
| 004c8580 | VTableMethodGuard | [LLM] |
| 004c85a0 | VTableDispatchViaGlobal | [LLM] |
| 004c85c0 | NullCheckedVTableCall | [LLM] |
| 005434a0 | sub_5434A0 | [LLM] |
| 00551cf0 | BinkVideoFrameRender | [LLM] |
| 00551eb0 | sub_551EB0 | [LLM] |
| 00551f10 | ObjectCreationWithRollbackOnFailure | [LLM] |
| 00551f80 | ConditionalFreeWithBinkClose | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
