## MainCameraDirectorUpdate_0040ca30 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** GamePostMainLoop (0042d8a0), StateTriggerCheck (004b8ae0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(this+0x8)+0x0) | 0xC | R | — | [LLM] |
| *(*(this+0x8)+0x0) | 0x10 | R | — | [LLM] |
| *(*(this+0x8)+0x0) | 0x18 | R | — | [LLM] |
| *(this+0x8) | 0x0 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0x18 | R | — | [LLM] |
| this | 0x25 | RW | 0 | [LLM] |
| this | 0x28 | RW | 0 | [LLM] |
| this | 0x2D | RW | 1 | [LLM] |
| this | 0x2E | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x25: [LLM: once/conditional? does external poke survive?]
- this 0x28: [LLM: once/conditional? does external poke survive?]
- this 0x2D: [LLM: once/conditional? does external poke survive?]

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e6d8 | dbl_59E6D8 | R | dbl_59E6D8 [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56ac | byte_7C56AC | R | EnableFlag [DERIVED] (also: ` — enable flag (byte) |
| 007cfe28 | flt_7CFE28 | R | Unknown_Float_7CFE28 [DERIVED] |
| 007cfe4c | dword_7CFE4C | R | UnknownSteerState [DERIVED] |
| 007cfe54 | dword_7CFE54 | R | Unknown_VehicleState [DERIVED] |
| 008ac4c4 | dword_8AC4C4 | R | InitStatus [DERIVED] |
| 008acebc | dword_8ACEBC | R | PhysicsEventCounter [DERIVED] |
| 008ad298 | dword_8AD298 | R | SessionModeIdentifier [DERIVED] |
| 008afe64 | dword_8AFE64 | R | RaceTimeDelta [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00409890 | sub_409890 | [LLM] |
| 0040be70 | KeyboardInputActionMapper | [LLM] |
| 0040c070 | RandomStateMachineWithTimerAndTrigger | [LLM] |
| 0040c5b0 | CameraModeChangeRequest | [LLM] |
| 0040c7a0 | CameraTargetUpdateOnPlayerChange | [LLM] |
| 0040c870 | VirtualDispatchHelper | [LLM] |
| 0040c910 | ShortComputation_c910 | [LLM] |
| 004ccdc0 | ParticlePositionAdd | [LLM] |
| 004d8860 | ConditionalBranchByFlag | [LLM] |
| 004f0d20 | sub_4F0D20 | [LLM] |
| 0053d450 | ShortComputation_d450 | [LLM] |
| 00542420 | TwoCallDelegation_2420 | [LLM] |
| 00542460 | TripleFieldGetter_2460 | [LLM] |

**Guard conditions:** [LLM: from code — field, checked values, what PASSES vs what is BLOCKED]
