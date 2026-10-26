## RaceModeSetup_00404890 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_404B60 (00404b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 1 | [LLM] |
| this | 0x15 | RW | 0 | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x50 | RW | — | [LLM] |
| this | 0x54 | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: [LLM: once/conditional? does external poke survive?]
- this 0x15: [LLM: once/conditional? does external poke survive?]
- this 0x50: [LLM: once/conditional? does external poke survive?]
- this 0x54: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e448 | flt_59E448 | R | TileSteppingMultiplier [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007d0410 | dword_7D0410 | RW | ChampionshipMode [FACT] (also: RaceMode) |
| 007d0418 | dword_7D0418 | R | SessionTimeoutOverride [DERIVED] |
| 007d041c | dword_7D041C | R | RaceModeTimeoutAlt [DERIVED] (also: ` — alternate timeout sources) |
| 007d0798 | flt_7D0798 | W | RaceSetupScaling [CONFIRMED] |
| 007d07a0 | flt_7D07A0 | R | UISliderMax [DERIVED] |
| 007d07a4 | dword_7D07A4 | R | DifficultyFloatThreshold [DERIVED] |
| 007d2e44 | dword_7D2E44 | RW | ScoringGateEnableFlag [CONFIRMED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404850 | PathStringUtility | [LLM] |
| 0040d360 | ShortComputation_d360 | [LLM] |
| 004a0d90 | SetGlobalFlag | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
