## HUDFlagRendererMain_004d82d0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D8450 (004d8450)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x8 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007ce234 | unk_7CE234 | R | DriverAppearanceFlag [DERIVED] |
| 007cfea0 | dword_7CFEA0 | R | InputDisplayMode [DERIVED] |
| 008ab6e4 | dword_8AB6E4 | R | ScoringGate [CONFIRMED] |
| 008ad394 | dword_8AD394 | R | AudioEmitter3 [DERIVED] |
| 008b8dc8 | dword_8B8DC8 | R | RenderDevicePtr [DERIVED] (also: RenderDevicePtr (D3D device/renderer interface, docs/12, docs/19) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f10 | ConditionalFlagReturn | [LLM] |
| 0049b9a0 | sub_49B9A0 | [LLM] |
| 0049ba30 | sub_49BA30 | [LLM] |
| 0049ba50 | FuelWeightComputation | [LLM] |
| 0049ba90 | PitStateFlagCheck | [LLM] |
| 0049bab0 | DisqualificationCheck | [LLM] |
| 0049bad0 | ShortComputation_bad0 | [LLM] |
| 0049bb20 | VehicleFlagCheck | [LLM] |
| 00552fc0 | FieldSetterAt0x48 | [LLM] |
| 00553070 | sub_553070 | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x8 | != | 18446744073709551615 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
