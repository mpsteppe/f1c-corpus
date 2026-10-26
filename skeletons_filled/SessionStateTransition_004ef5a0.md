## SessionStateTransition_004ef5a0 — SessionStateTransitionHandler

**Summary:** Updates session state pointer and handles entry/exit side-effects. On state exit (non-NULL → NULL), records vehicle position and race time. On entry to state 1, triggers position change monitor, cleanup flags, and AI speed adjustment.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringReset (0042bd60), NetCommPlayerSlotSync (0045fc50), AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10), RaceFinishHandler (004a0ba0), RestartGate (004a0fd0), LoadVehicleEntries (004b70b0), LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), ProcessDriverEntries (004b8da0), AIDriverCountSetup (004bfd90), sub_4C0850 (004c0850), sub_4C1050 (004c1050), sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | RW | — | Session state pointer/identifier; written each call |
| this | 0x34EC | R | — | Vehicle position Z component (used with RenderX/RenderY) |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |

**Written-by note (persistence):**
- this 0x32BC: Overwritten each call with new state pointer; last writer wins

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aca0 | AISpeedDeltaSetter | Adjusts AI speed delta after state transition to state 1 |
| 0042adb0 | SessionCleanupFlagClear | Clears session cleanup flags for current session |
| 00447780 | sub_447780 | Computes something with race time elapsed and vehicle position vector |
| 004e9630 | PositionChangeMonitor | Returns structure with position change data for session |
| 004ef7c0 | AIVehiclePathPositionTracking | Tracks vehicle position along predefined path segments |
| 004efb20 | F_3DTransformWithMatrixMultiplication | Transforms vector by matrix multiplication |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32BC | == | 1 | Previous state != 1 AND new state == 1 |

**Guard interpretation:** PASSES if prior state was not pointer-value 1 and newly written state equals 1 (entry into state 1); then runs cleanup + AI speed adjustment + position tracking reset. BLOCKED otherwise.
