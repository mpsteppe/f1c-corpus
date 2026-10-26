## RaceFinishHandler_004a0ba0 — RaceFinishHandler

**Summary:** Handles race completion per driver. Triggers per-driver commentary, transitions game state machine to post-race mode, and conditionally switches to menu mode based on vehicle state and timing. Dispatches event 19 for race winner.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** LapCompletion (004bc4e0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec6d8 | unk_5EC6D8 | R | VEH[0].0x0 = postProcessInput [CONFIRMED] |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007ce814 | dword_7CE814 | R | QualifyingDSQEnabled [DERIVED] |
| 008acee0 | dword_8ACEE0 | R | ForceFeedbackBase [CONFIRMED] |
| 008acf90 | flt_8ACF90 | R | RaceTimeOffset [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | Transitions game action state machine to post-race state |
| 00419c50 | PerDriverRaceCommentary | Triggers race commentary specific to this driver |
| 004a0c60 | SessionMenuModeSwitch | Switches session to menu/mode select |
| 004d1b50 | sub_4D1B50 | Gets vehicle index for driver |
| 004d8760 | sub_4D8760 | Dispatches in-race event/commentary by ID |
| 004ef5a0 | SessionStateTransition | Transitions session to specified state |

**Guard conditions:** Driver field at offset 0x32C8 (a2[3250]) must be 0 AND QualifyingDSQEnabled (dword_7CE814) must be 0 for the state machine transition block. If either is non-zero, skips GameActionStateMachine, SessionStateTransition, and SessionMenuModeSwitch. SessionMenuModeSwitch additionally requires position != 1 (a2[4120]), vehicle at offset 0x4121 == 1, elapsed time > 60.0s, and session mode != 19.
