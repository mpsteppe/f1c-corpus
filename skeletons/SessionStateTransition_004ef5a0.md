## SessionStateTransition_004ef5a0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SeasonScoringReset (0042bd60), NetCommPlayerSlotSync (0045fc50), AutoJoinRetryLoop (004637a0), MultiplayerSessionJoinHandler (0046de10), RaceFinishHandler (004a0ba0), RestartGate (004a0fd0), LoadVehicleEntries (004b70b0), LoadingPhase1 (004b87c0), LoadingPhase2 (004b8940), ProcessDriverEntries (004b8da0), AIDriverCountSetup (004bfd90), sub_4C0850 (004c0850), sub_4C1050 (004c1050), sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x0 | R | — | postProcessInput [CONFIRMED] |
| this | 0x32BC | RW | — | [LLM] |
| this | 0x34EC | R | — | [LLM] |
| this | 0x34F0 | R | — | RenderX [FACT] |
| this | 0x34F4 | R | — | RenderY [FACT] |

**Written-by note (persistence):**
- this 0x32BC: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 007c7428 | dbl_7C7428 | R | RaceTimeElapsed [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042aca0 | AISpeedDeltaSetter | [LLM] |
| 0042adb0 | SessionCleanupFlagClear | [LLM] |
| 00447780 | sub_447780 | [LLM] |
| 004e9630 | PositionChangeMonitor | [LLM] |
| 004ef7c0 | AIVehiclePathPositionTracking | [LLM] |
| 004efb20 | F_3DTransformWithMatrixMultiplication | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x32BC | == | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
