## TrackEnvironmentSelect_004ade20 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** TextFileReader (004b09a0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1AEC | RW | 1 | [LLM] |
| this | 0x1B10 | RW | — | [LLM] |
| this | 0x1B18 | R | — | [LLM] |
| this | 0x1B1C | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1AEC: [LLM: once/conditional? does external poke survive?]
- this 0x1B10: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ec4a8 | dword_5EC4A8 | R | CameraIndexStep [DERIVED] (also: ` — Camera index increment) |
| 007cb710 | byte_7CB710 | R | EnvironmentFlags [DERIVED] (also: ` — Env flag (bit 0 = wet) |
| 007cbb0c | byte_7CBB0C | R | EnvFlagMixed (bit0) [DERIVED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008ac490 | dword_8AC490 | R | SceneArray (stride 0x18c) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004adf10 | DrivingModeParameterSetup | [LLM] |
| 004ae490 | CarPartVisibilityController | [LLM] |
| 004ae750 | sub_4AE750 | [LLM] |
| 004ae9f0 | sub_4AE9F0 | [LLM] |
| 004af220 | TireCompoundClamp | [LLM] |
| 004af3a0 | PhysicsParameterInitialization | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004c55b0 | TrackSceneLoader | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x1B10 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
