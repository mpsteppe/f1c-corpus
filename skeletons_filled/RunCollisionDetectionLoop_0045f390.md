## RunCollisionDetectionLoop_0045f390 — CollisionDetectionTimedLoop

**Summary:** Runs timed collision detection loop with animation timing and physics processing. Guarded by session phase check; loops until animation completes or 60-second timeout, then processes collision results.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** SynchronizeWithServer (00464290)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| this | 0x3FB8 | R | — | Animation parameter set pointer passed to timing update |
| this | 0x3FC4 | R | — | Session phase/state: must equal 3 to proceed |

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059f118 | flt_59F118 | R | RaceTimeThreshold [DERIVED] — cell size constant (float) |
| 005ec6d0 | unk_5EC6D0 | R | unknown |
| 007c569c | dword_7C569C | R | SessionType5 (5=server) [DERIVED] — passed to MultiplayerVehiclePlacement |
| 008afe18 | unk_8AFE18 | R | GameRacePhaseTimer [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0042bda0 | TimerConversionWithSin | Convert timer value with sine function for physics timing |
| 0042cf10 | MultiplayerVehiclePlacement | Place/update multiplayer vehicle based on collision results |
| 0045c8b0 | ArrayInitializationLoop | Initialize collision array entries |
| 004b0170 | EmptyStub_0170 | Empty stub (timer cleanup) |
| 004f9fc0 | sub_4F9FC0 | Process fetched animation/collision value |
| 00568ba0 | StructZeroInit_8ba0 | Zero-initialize timer structure |
| 00568be0 | QPCTimerInitialization | Initialize QPC-based high-resolution timer |
| 00568c60 | TimerResetUsingQueryPerformanceCounter | Reset timer to current QPC value |
| 00568cf0 | HighResolutionTimerDelta | Compute elapsed time from last reset |
| 0057a5a0 | AnimationTimingUpdateWithParamSet | Update animation timing with parameter set |
| 0057a610 | AnimationValueFetchWithTiming | Fetch animation value with timing; returns nonzero when animation complete |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x3FC4 | != | 3 | Session phase/state field |

**Guard interpretation:**
- this[0x3FC4/4] != 3 → return 0 immediately (wrong session phase).
- this[0x3FC4/4] == 3 → proceed with loop.
- Loop: if timer <= 0.0, call AnimationTimingUpdateWithParamSet and reset step to 4.0.
- AnimationValueFetchWithTiming returns nonzero → break loop (animation complete).
- Elapsed (v6) >= 60.0 → timeout, cleanup timer, return 0.
- On success: process value, call TimerConversionWithSin, MultiplayerVehiclePlacement, ArrayInitializationLoop, cleanup timer, return 1.
