## RunCollisionDetectionLoop_0045f390 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SynchronizeWithServer (00464290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FB8 | R | — | [LLM] |
| this | 0x3FC4 | R | — | [LLM] |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] (also: ` — cell size constant (float) |
| 005ec6d0 | unk_5EC6D0 | R | [LLM] |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] (also: ` — SessionType5 (guards dev logging) |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bda0 | TimerConversionWithSin | [LLM] |
| 0042cf10 | MultiplayerVehiclePlacement | [LLM] |
| 0045c8b0 | ArrayInitializationLoop | [LLM] |
| 004b0170 | EmptyStub_0170 | [LLM] |
| 004f9fc0 | sub_4F9FC0 | [LLM] |
| 00568ba0 | StructZeroInit_8ba0 | [LLM] |
| 00568be0 | QPCTimerInitialization | [LLM] |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | [LLM] |
| 00568cf0 | HighResolutionTimerDelta | [LLM] |
| 0057a5a0 | AnimationTimingUpdateWithParamSet | [LLM] |
| 0057a610 | AnimationValueFetchWithTiming | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3FC4 | != | 3 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
