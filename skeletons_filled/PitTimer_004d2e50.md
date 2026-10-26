## PitTimer_004d2e50 — PitStopTimerStateMachine

**Summary:** Tick-driven pit stop timer state machine that handles countdown display, pit lane open/close transitions, time-remaining messages, and session phase advancement. Part of the race UI / session management system.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** sub_4D4580 (004d4580)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | state machine substate (checked for == 2 to dispatch ShortComputation_dd80) |
| this | 0xB0 | RW | 2139095039 | pit timer countdown float (seconds until pit close; infinity sentinel = inactive) |
| this | 0xB4 | RW | — | secondary timer float (session elapsed target; used for phase advancement checks) |
| this | 0xC2 | RW | 1 | action-completed flag byte (prevents re-execution of one-shot state actions) |
| this | 0xD8 | RW | 2139095039 | tertiary timer float (message display interval; infinity sentinel = inactive) |
| this | 0xF4 | R | — | result/completion state (checked for == 2 to short-circuit; returned to caller) |
| this | 0x104 | R | — | interrupt-requested flag byte (guards InterruptDispatch call) |

**Written-by note (persistence):**
- this 0xB0: conditional (write when entering certain phases; survives external reads)
- this 0xB4: conditional (write when entering certain phases; survives external reads)
- this 0xC2: conditional (set to 1 or 0 in certain phases; survives external reads)
- this 0xD8: conditional (write when entering certain phases; survives external reads)

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004d3490 | jpt_4D2E8B | R | jump table for switch dispatch on RacePhase |
| 0059e420 | dbl_59E420 | R | BaseDoubleConstant [DERIVED] (also: ` (BaseDoubleConstant = 1.0) |
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e46c | flt_59E46C | R | TireSlipOffset [DERIVED] (also: ` — offset value) |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e808 | flt_59E808 | R | EngineTempThreshold [DERIVED] |
| 0059e80c | flt_59E80C | R | PitlaneTimeThreshold [DERIVED] |
| 0059e8d8 | flt_59E8D8 | R | BrakingSpeedThreshold3 [DERIVED] |
| 0059e968 | flt_59E968 | R | AIQualifyPushFrequency [DERIVED] |
| 0059e99c | flt_59E99C | R | PhysicsConversionFactor [DERIVED] (also: ` — conversion factor) |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005acef8 | flt_5ACEF8 | R | Flt_5ACEF8_Render [DERIVED] |
| 005acefc | flt_5ACEFC | R | TrackSurfaceScale [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d4194 | aSD02d02d | R | TimeFormatString [DERIVED] |
| 005d41a4 | aTimeRemaining | R | String_TimeRemaining [DERIVED] |
| 005d41b4 | a0001 | R | StrTimerDisplay [DERIVED] |
| 005d41bc | aTimeUntilPitCl | R | TimeUntilPitClosedField [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54e8 | dword_7C54E8 | R | PlayerVehiclePtr [FACT] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cd25c | dword_7CD25C | R | GameModuleManager [DERIVED] |
| 007cebf4 | dword_7CEBF4 | R | SessionRaceState [DERIVED] |
| 007cec30 | dword_7CEC30 | R | ReconPitOpen [DERIVED] |
| 007cec78 | byte_7CEC78 | R | PitTimerVisible [DERIVED] |
| 007ced8c | dword_7CED8C | R | UIRacePhaseFlag [DERIVED] |
| 007cee88 | dword_7CEE88 | R | SessionInitFlags [DERIVED] |
| 008afe98 | dbl_8AFE98 | R | ScoringDefaultReturn [DERIVED] (also: ` — default return value (float) |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cde0 | GameActionStateMachine | triggers game action (session state change: action 5, param 1) |
| 0040d100 | GameStateBranchDispatch | dispatches to a game state branch handler on the session manager |
| 0040dd80 | ShortComputation_dd80 | short computation/transition when state == 2 |
| 0040de60 | sub_40DE60 | tick update / processing call for the timer object |
| 0040e170 | TickUpdateDispatch | dispatches tick update to the timer's update handler |
| 0041a500 | TimeBasedMessageChain | processes time-based message queue with float timer value |
| 0041a6b0 | DisplayMessage0x113 | displays message ID 0x113 (pit-related notification) |
| 00423a00 | BinarySearchInStringTable | looks up a format string in string table by key |
| 0042d140 | sub_42D140 | sets session sub-state to a new value |
| 0045bd10 | TextLineWrappingAndRendering | renders wrapped text at screen position |
| 0045bde0 | ShortComputation_bde0 | short computation on resource dispatch (display update) |
| 0045bdf0 | ShortComputation_bdf0 | short computation on resource dispatch (pit-related) |
| 00461db0 | SessionStateCheckWrapper | checks if a game module manager session state is active |
| 004bc9b0 | sub_4BC9B0 | operates on player vehicle data (offset +16436) with flags |
| 004d0ec0 | ArithmeticComparison_0ec0 | sets a state field to a new value (equivalent to state transition) |
| 004d11d0 | sub_4D11D0 | pit timer display update: formats and shows time string |
| 004d1cd0 | SingleCallWrapper_1cd0 | single dispatch call with a state parameter (0-5 tier) |
| 004d2210 | PitCloseTeamReadyCheck | checks if all teams are ready for pit close |
| 004d2e20 | ArithmeticComparison_2e20 | arithmetic comparison / state transition for pit close |
| 0058815f | StringFormatWithBufferOverflowCheck | formats a time-remaining string: "%s %d:%02d:%02d" |
| 0058957a | InterruptDispatch | checks if an interrupt occurred since given timestamp |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x0 | == | 2 | state machine substate: when 2, triggers ShortComputation_dd80 dispatch |
| this | 0xF4 | == | 2 | completion state: when 2, skips final result check and returns early |

**Guard interpretation:** 
- this+0x0 == 2 → PASSES: triggers special processing (ShortComputation_dd80) then continues; BLOCKED: skips that dispatch, normal flow continues
- this+0xF4 == 2 → PASSES: returns result 2 immediately (early exit); BLOCKED: runs interrupt/state check logic at function tail before returning
