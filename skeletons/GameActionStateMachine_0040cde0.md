## GameActionStateMachine_0040cde0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** KeyboardInputActionMapper (0040be70), RandomStateMachineWithTimerAndTrigger (0040c070), CameraModeChangeRequest (0040c5b0), ConditionalModeDispatchWithGlobalGate (0040c610), CameraViewAssignment (0040c650), GameStateBranchDispatch (0040d100), SessionPhaseDispatchWithCascadeChecks (0040d1b0), ShortComputation_d3c0 (0040d3c0), ShortComputation_d410 (0040d410), StateResetOnCondition (0040d450), ModuleInitializationWithFallback (00434820), RaceFinishHandler (004a0ba0), sub_4B9890 (004b9890), PitTimer (004d2e50), sub_4DA840 (004da840)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(this+0x8) | 0x10 | R | — | [LLM] |
| this | 0x8 | RW | — | [LLM] |
| this | 0xC | RW | 2 | [LLM] |
| this | 0x14 | RW | 3 | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x1C | R | — | [LLM] |
| this | 0x20 | R | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x30 | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x8: recalc every frame — external poke does NOT persist
- this 0xC: recalc every frame — external poke does NOT persist
- this 0x14: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0040d050 | jpt_40CDFC | R | [LLM] |
| 0040d080 | sub_40D080 | R | [LLM] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007cfe88 | byte_7CFE88 | R | unknown (found in 0x0040cde0) [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409440 | ViewCameraModeDispatch | [LLM] |
| 004e0ed0 | AudioSoundEffectController | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x2C | > | 0 | [LLM] |
| this | 0x30 | > | 0 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
