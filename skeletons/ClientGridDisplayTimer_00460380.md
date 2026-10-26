## ClientGridDisplayTimer_00460380 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SessionScoringUpdate (004643c0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x1C | RW | 1089470464 → 7.5f | PhysX [FACT] |
| this | 0x20 | RW | 1 | PhysY [FACT] |
| this | 0x3FC4 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x1C: [LLM: once/conditional? does external poke survive?]
- this 0x20: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f0ac | dword_59F0AC | R | NetTimeoutInterval [DERIVED] (also: ` — float constants) |
| 005c5f5c | aMpclientgrid | R | MpClientGrid [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cd8c0 | dword_7CD8C0 | R | GameCommandDispatchInterface [DERIVED] (also: ` — game command dispatch interface pointer) |
| 007ce24c | unk_7CE24C | R | CriticalSection [DERIVED] (also: ` — Session data object) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 008ac368 | unk_8AC368 | R | VehicleSetupBase [DERIVED] |
| 008ac48c | dword_8AC48C | R | CurrentSceneIndex [DERIVED] (also: ` — module list index) |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00461550 | FAILWRONGDESCRIPTION | [LLM] |
| 00461900 | SessionConfigWriteback | [LLM] |
| 004630d0 | UniqueID | [LLM] |
| 00497940 | LookupDispatch | [LLM] |
| 004a0030 | sub_4A0030 | [LLM] |
| 004a0dc0 | SystemOSAPICall_0dc0 | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004c54f0 | AIW | [LLM] |
| 004c5690 | SceneDataParser | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3FC4 | == | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
