## AudioSoundEffectController_004e0ed0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** ViewCameraModeDispatch (00409440), CameraTargetUpdateOnPlayerChange (0040c7a0), GameActionStateMachine (0040cde0), NetCommPlayerSlotSync (0045fc50), PitStopOperationTimer (004a6340), VehicleVisibilityCulling (004b3dc0), LoadingPhase2 (004b8940), PitCrewStateMachine (004bbfc0), VehiclePhysicsTimeStep (004c73f0), SetDriverVisibility (004c7aa0), VehicleRespawnReset (004e0800), LazyInitCallback (004e0d00), sub_4F1FE0 (004f1fe0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| obj | 0xC4 | R | — | [LLM] |
| obj | 0x4894 | R | — | [LLM] |
| obj | 0x48BC | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x144 | R | — | [LLM] |
| this | 0x184 | R | — | [LLM] |
| this | 0x188 | R | — | [LLM] |
| this | 0x1C8 | R | — | [LLM] |
| this | 0x26C | R | — | [LLM] |
| this | 0x2AC | R | — | [LLM] |
| this | 0x2B0 | R | — | [LLM] |
| this | 0x2F0 | R | — | [LLM] |
| this | 0x394 | R | — | [LLM] |
| this | 0x3D4 | R | — | [LLM] |
| this | 0x4BC | R | — | [LLM] |
| this | 0x4FC | R | — | [LLM] |
| this | 0x5E4 | R | — | [LLM] |
| this | 0x624 | R | — | [LLM] |
| this | 0x628 | R | — | [LLM] |
| this | 0x668 | R | — | [LLM] |
| this | 0x66C | R | — | [LLM] |
| this | 0x6AC | R | — | [LLM] |
| this | 0x6AD | R | — | [LLM] |
| this | 0x88C | R | — | [LLM] |
| this | 0x890 | R | — | [LLM] |
| this | 0x894 | R | — | [LLM] |
| this | 0x898 | R | — | [LLM] |
| this | 0x89C | R | — | [LLM] |
| this | 0x8A0 | R | — | [LLM] |
| this | 0x964 | RW | — | [LLM] |
| this | 0x96C | R | — | [LLM] |
| this | 0x96D | R | — | [LLM] |

**Written-by note (persistence):**
- this 0x964: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 004e169c | jpt_4E0F1D | R | [LLM] |
| 004e16ac | jpt_4E1029 | R | [LLM] |
| 004e16b4 | byte_4E16B4 | R | [LLM] |
| 005ea510 | dword_5EA510 | R | SessionManager [DERIVED] |
| 005ea518 | dword_5EA518 | R | ActiveControlProfilePtr [DERIVED] |
| 005ea528 | dword_5EA528 | R | AudioDeviceState [DERIVED] |
| 007c54e0 | dword_7C54E0 | R | postProcessInput [CONFIRMED] (also: unknown (near PlayerVehiclePtr +0x8)) |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007ce254 | byte_7CE254 | R | DisableHUDFlag [CONFIRMED] |
| 007cf710 | byte_7CF710 | R | SkipIntroFlag [DERIVED] |
| 007cf860 | dword_7CF860 | R | Unknown_AiTeamCount_F860 [DERIVED] |
| 007cfcec | dword_7CFCEC | R | PitControlFlag [DERIVED] |
| 007d0410 | dword_7D0410 | R | ChampionshipMode [FACT] (also: RaceMode) |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 0040cd60 | SessionPhaseDecode | [LLM] |
| 004f7010 | StateHandlerDispatch | [LLM] |
| 0054c030 | FlagFieldBitManipulation | [LLM] |
| 0054c1b0 | UIWidgetRecursiveStateUpdate | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| obj | 0xC4 | != | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
