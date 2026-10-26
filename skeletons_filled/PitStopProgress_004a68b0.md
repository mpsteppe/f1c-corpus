## PitStopProgress_004a68b0 — Pit Stop Progress Timer and State Machine

**Summary:** Manages pit stop progress each tick: applies wheel damage repair forces on a timed schedule, controls pit speed limiter, triggers pit exit state transitions, handles post-pit cleanup and camera mode changes.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** PitStateUpdateMachine (004a6e50)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0x1054 | R | — | VehicleDetailLevel (read to check if pit crew meshes should load) |
| obj | 0x105C | RW | 1 | PitCrewMeshFlag (set to 1 to trigger pit crew mesh loading) |
| obj | 0x32C8 | R | — | AIEnableFlag (checked == 1 for AI pit cleanup dispatch) |
| obj | 0x4064 | R | — | FinishState (checked != 1 before pit exit audio) |
| obj | 0x4068 | RW | 0 | ReasonCode (zeroed when pit speed limiter deactivated with non-zero speed) |
| this | 0x0 | R | — | BaseVehiclePtr (deref for obj fields like AIEnableFlag, FinishState, ReasonCode) |
| this | 0x4 | R | — | VehicleIndex (compared with current player vehicle index) |
| this | 0x8 | R | — | PitCrewObjectPtr (pointer to pit crew entity for dispatch) |
| this | 0x1A0 | R | — | PitEntryTime (session time when pit stop started) |
| this | 0x1A4 | R | — | PitCompletionTime (session time threshold — when elapsed time exceeds this, pit ends) |
| this | 0x1A8 | RW | — | PitStopElapsed (pit completion time minus entry time, written at pit exit) |
| this | 0x1AC | RW | 0 | PitMidFlag (byte: set to 0 when mid-pit event fires) |
| this | 0x1B0 | R | — | PitPhaseTime0 (first repair phase time) |
| this | 0x1B4 | R | — | PitPhaseTime1 (second repair phase time) |
| this | 0x1B8 | R | — | PitPhaseTime2 (third repair phase time) |
| this | 0x1C0 | R | — | SpeedLimiterActive (bool: if non-zero, speed limiter is engaged) |
| this | 0x1C4 | R | — | SpeedLimiterTarget (target speed value for limiter) |
| this | 0x1D0 | R | — | RepairRate0 (wheel damage repair rate for front wheels) |
| this | 0x1D4 | R | — | RepairRate1 (wheel damage repair rate for rear wheels) |

**Written-by note (persistence):**
- obj 0x105C: recalc every frame — external poke does NOT persist
- obj 0x4068: recalc every frame — external poke does NOT persist
- this 0x1A8: recalc every frame — external poke does NOT persist
- this 0x1AC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e800 | flt_59E800 | R | AmplitudeLimit [DERIVED] (also: ` — under-relaxation upper bound) |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e96c | flt_59E96C | R | DamageInterpFactor [DERIVED] |
| 005acb60 | flt_5ACB60 | R | PitRepairThreshold [DERIVED] |
| 005acb64 | flt_5ACB64 | R | BrakeBias_Rate [DERIVED] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007cf884 | dword_7CF884 | R | DetailLevel [DERIVED] (also: ` â€” detail level (â‰¤1 = load pitcrew meshes) |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afea0 | dbl_8AFEA0 | R | SessionTime [DERIVED] (also: ` — current session time (passed to FUN_0040f300) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040d410 | ShortComputation_d410 | Dispatch pit exit session manager update |
| 00424cd0 | AICommandMessageQueueDispatcher | Send AI command message (15 = pit exit complete) on pit exit |
| 0042a6f0 | PostPitCleanup | Clean up AI state after pit stop |
| 004a34a0 | PerElementConditionalActionDispatcher | Dispatch per-element action on pit crew object |
| 004a5c80 | StateChangeNotify | Notify state machine of pit stop completion (state 4) |
| 004d8760 | sub_4D8760 | Dispatch some event with params (6, 0) for current player vehicle |
| 004f1890 | SpeedValueSetterWithGlobalMirror | Set pit speed limiter value globally |
| 004f1b50 | CameraModeSetter | Set camera mode (0 = normal, called on pit exit) |
| 004f1ba0 | WheelForceParameterSet | Apply wheel damage repair forces (front/rear) with timed interpolation |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0x32C8 | == | 1 | AIEnableFlag — PASSES: triggers AI post-pit cleanup and command dispatch |
| obj | 0x4064 | != | 1 | FinishState — PASSES: audio controller dispatch only if not finished |
| obj | 0x4068 | == | 9 | ReasonCode — BLOCKED: if ReasonCode=9, clear it when speed limiter engaged and target > 0 |

**Guard interpretation:** Main time-based gate: `a2 < pitCompletionTime` → still in pit stop (repair forces active). If `a2 >= pitCompletionTime` → pit exit: deactivate speed limiter, notify state change to 4, trigger AI cleanup (if AI enabled), dispatch pit exit command (15), reset wheel forces to zero, switch camera mode to 0, and dispatch pit crew cleanup. Within the pit window, wheel damage repair forces ramp up in two timed phases (0.2s and 1.4s after pit start) to peak 0.096.
