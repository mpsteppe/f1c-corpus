## RenderCallWithGuard_004d1140 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** VehicleMainPhysicsUpdate (004441f0), Camera (004a3b50), SceneRenderUpdate (004c6d90), RenderTickUpdate (004c8b70), LoopOverTwoParallelArrays (004d1030), sub_4D1180 (004d1180), AIRacingLinePathFollowing (004e9ca0), DistanceComparison (004effd0), sub_4F0D20 (004f0d20), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x48A4 | R | — | [LLM] |
| this | 0x48A8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea2c0 | dword_5EA2C0 | R | SetupScenePtr [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00403fc0 | IndexedStructDataRead | [LLM] |
| 004c6f10 | sub_4C6F10 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x48A4 | < | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
