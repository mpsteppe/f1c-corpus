## GameActionStateMachine_0040cde0 — GameActionStateMachine

**Summary:** 10-case state machine dispatching camera mode changes and audio effects based on action IDs (0-10). Manages state pointers, transitions, and conditional virtual dispatch. Part of camera/view/input system.

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** KeyboardInputActionMapper (0040be70), RandomStateMachineWithTimerAndTrigger (0040c070), CameraModeChangeRequest (0040c5b0), ConditionalModeDispatchWithGlobalGate (0040c610), CameraViewAssignment (0040c650), GameStateBranchDispatch (0040d100), SessionPhaseDispatchWithCascadeChecks (0040d1b0), ShortComputation_d3c0 (0040d3c0), ShortComputation_d410 (0040d410), StateResetOnCondition (0040d450), ModuleInitializationWithFallback (00434820), RaceFinishHandler (004a0ba0), sub_4B9890 (004b9890), PitTimer (004d2e50), sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x10 | R | — | Virtual method at vtable+0x10 (5th method) on current state object |
| this | 0x8 | RW | — | Current/active state pointer (this[2]), set from this[6] on each transition |
| this | 0xC | RW | 2 | State result/action code (this[3]), stores dispatched action ID |
| this | 0x14 | RW | 3 | Secondary state value (this[5]), set during case 3 transitions |
| this | 0x18 | R | — | Current camera/session pointer (this[6]) |
| this | 0x1C | R | — | Secondary object pointer (this[7]) used in case 5 guard |
| this | 0x20 | R | — | Third object pointer (this[8]) used in case 5 guard |
| this | 0x2C | R | — | Guard field (> 0 check) for case 5 progression |
| this | 0x30 | R | — | Guard field (> 0 check) for case 5 progression |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d050 | jpt_40CDFC | R | Jump table for 10-case switch dispatch |
| 0040d080 | sub_40D080 | R | Function pointer used in case 5 fallback decision |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cfe88 | byte_7CFE88 | R | Flag byte checked in case 3 for additional camera mode transition |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409440 | ViewCameraModeDispatch | Dispatches camera mode change with action ID, transition flags, and instant/lerp parameter |
| 004e0ed0 | AudioSoundEffectController | Triggers audio sound effect (parameter 0 = default/stop) |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2C | > | 0 | Counter/timer field from object at this[8] |
| this | 0x30 | > | 0 | Counter/timer field from object at this[7] |

**Guard interpretation:** Case 5 only proceeds to virtual dispatch + state update if *(this[8] + 0x10) > 0 OR *(this[7] + 0x10) > 0. If both are <= 0, execution falls through without the virtual call but still plays audio and stores action ID.
