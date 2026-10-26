## RaceModeSetup_00404890 — RaceModeTransitionSetup

**Summary:** Configures race mode session transition: saves previous scoring/race-mode global state, sets new race mode value (2), applies timeout overrides, sets session transition flag, and computes scaling factor based on UI slider or difficulty threshold. Non-race mode path simply sets two byte flags.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_404B60 (00404b60)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x14 | RW | 1 | byte activation flag; always set to 1 in both paths (WORD or BYTE write) |
| this | 0x15 | RW | 0 | byte flag set to 0 only in non-race-mode path (when field 0x20 != 1) |
| this | 0x20 | R | — | dword check for race mode (value == 1 triggers full setup path) |
| this | 0x50 | RW | — | saved previous value of dword_7D2E44 (ScoringGateEnableFlag) before overwrite |
| this | 0x54 | RW | — | saved previous value of dword_7D0410 (RaceMode) before overwrite |

**Written-by note (persistence):**
- this 0x14: written once per call in all branches; external poke survives until next call
- this 0x15: written once per call only in non-race-mode branch; otherwise retains value
- this 0x50: written once per call only when race mode active; retains value between calls
- this 0x54: written once per call only when race mode active; retains value between calls

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
| 00404850 | PathStringUtility | copies/validates path string for resource loading during setup |
| 0040d360 | ShortComputation_d360 | performs short arithmetic computation with given parameters (1, 15) |
| 004a0d90 | SetGlobalFlag | sets a global session-transition flag to trigger state change |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x20 | == | 1 | dword indicating race mode is active |

**Guard interpretation:** Field at this+0x20 == 1 PASSES (enters full race-mode setup: saves/overwrites globals, computes scaling, sets session flag). Field != 1 BLOCKED (takes else branch: only sets byte flags 0x14=1, 0x15=0, skips all global modification).
