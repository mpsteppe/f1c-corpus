## SessionMenuModeSwitch_004a0c60 — PostRaceMenuModeSwitch

**Summary:** Switches session to menu mode after race completion. Two paths: if setup directory suffix flag is set, transitions directly to main menu with SessionType5=6; otherwise initializes post-race state (reciprocal computation and one-time init) if qualifying DSQ is not enabled.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** RaceFinishHandler (004a0ba0), sub_4A0CB0 (004a0cb0), LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005ea43c | dword_5EA43C | R | SetupDirSuffix [DERIVED] |
| 005ea4e8 | flt_5EA4E8 | R | RandomOffsetFlag [DERIVED] |
| 007c569c | dword_7C569C | W | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007ce24d | unk_7CE24D | R | SessionTransitionFlag [DERIVED] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00404f00 | ByteFieldExtractorWithShift | Extracts byte field from SetupDirSuffix to determine menu mode path |
| 00404f30 | MainMenuTransition | Transitions game to main menu screen |
| 00408420 | ReciprocalWithSignCheck | Computes reciprocal with sign check on post-race offset flag |
| 004a0d10 | GlobalStateOneTimeInitializer | Performs one-time initialization of session transition state |

**Guard conditions:** If ByteFieldExtractorWithShift(&dword_5EA43C) returns non-zero → takes main-menu transition path (dword_7C569C=6, MainMenuTransition). Otherwise → takes post-race init path; the ReciprocalWithSignCheck and GlobalStateOneTimeInitializer calls are guarded by dword_7CE814 (QualifyingDSQEnabled) needing to be 0.
