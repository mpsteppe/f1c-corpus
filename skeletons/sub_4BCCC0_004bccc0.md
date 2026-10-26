## sub_4BCCC0_004bccc0 — [LLM: short descriptive name]

**Summary:** [LLM: 1-2 sentences — what it does, what system]

**Frame-path:** ON_FRAME_PATH  
**Call frequency:** per-frame tick

**Called by:** MainGameTickUpdate (0042c690)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|
| *(*(obj+0x3AA8)+0x110) | 0x0 | R | — | [LLM] |
| *(*(obj+0x3AA8)+0x110) | 0x4 | R | — | [LLM] |
| *(*(obj+0x3AA8)+0x110) | 0x8 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x0 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x4 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x8 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x20 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x24 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x28 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x68 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x6C | R | — | [LLM] |
| *(obj+0x3AA8) | 0xA4 | R | — | [LLM] |
| *(obj+0x3AA8) | 0xA8 | R | — | [LLM] |
| *(obj+0x3AA8) | 0xAC | R | — | [LLM] |
| *(obj+0x3AA8) | 0x110 | R | — | [LLM] |
| *(obj+0x3AA8) | 0x12C | R | — | [LLM] |
| obj | 0x344C | R | — | [LLM] |
| obj | 0x34E0 | R | — | [LLM] |
| obj | 0x34E4 | R | — | [LLM] |
| obj | 0x34E8 | R | — | [LLM] |
| obj | 0x34F8 | R | — | [LLM] |
| obj | 0x34FC | R | — | [LLM] |
| obj | 0x3500 | R | — | [LLM] |
| obj | 0x3AA8 | R | — | [LLM] |
| this | 0x0 | R | — | [LLM] |
| this | 0x4 | R | — | [LLM] |
| this | 0x8 | R | — | [LLM] |
| this | 0xC | R | — | [LLM] |
| this | 0x14 | RW | — | [LLM] |
| this | 0x2C | R | — | [LLM] |
| this | 0x60 | RW | 1 | [LLM] |
| this | 0xA8 | RW | 0 | [LLM] |
| this | 0xAC | RW | — | [LLM] |
| this | 0xB0 | RW | — | [LLM] |
| this | 0xB4 | RW | 0 | [LLM] |
| this | 0xB8 | RW | — | [LLM] |
| this | 0xBC | RW | — | [LLM] |
| this | 0xC0 | RW | — | [LLM] |
| this | 0xC4 | RW | — | [LLM] |
| this | 0xC8 | RW | — | [LLM] |
| this | 0xCC | RW | — | [LLM] |
| this | 0xD0 | R | — | [LLM] |
| this | 0xD4 | RW | 1 | [LLM] |
| this | 0xD8 | RW | — | [LLM] |
| this | 0xDC | RW | — | [LLM] |

**Written-by note (persistence):**
- this 0x14: recalc every frame — external poke does NOT persist
- this 0x60: recalc every frame — external poke does NOT persist
- this 0xA8: recalc every frame — external poke does NOT persist
- this 0xAC: recalc every frame — external poke does NOT persist
- this 0xB0: recalc every frame — external poke does NOT persist
- this 0xB4: recalc every frame — external poke does NOT persist
- this 0xB8: recalc every frame — external poke does NOT persist
- this 0xBC: recalc every frame — external poke does NOT persist
- this 0xC0: recalc every frame — external poke does NOT persist
- this 0xC4: recalc every frame — external poke does NOT persist
- this 0xC8: recalc every frame — external poke does NOT persist
- this 0xCC: recalc every frame — external poke does NOT persist
- this 0xD4: recalc every frame — external poke does NOT persist
- this 0xD8: recalc every frame — external poke does NOT persist
- this 0xDC: recalc every frame — external poke does NOT persist

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 0059e43c | flt_59E43C | R | physics constant [DERIVED] (also: ` — float threshold for contact aging overflow) |
| 0059e440 | flt_59E440 | R | ZeroThreshold (~0.0f, physics clamp) [DERIVED] |
| 0059e450 | flt_59E450 | R | DegreesToRadians [DERIVED] |
| 0059e468 | flt_59E468 | R | BrakingZoneSpeedThreshold2 [DERIVED] |
| 0059e478 | flt_59E478 | R | SteeringCenterBoost [DERIVED] |
| 0059e4dc | flt_59E4DC | R | FullResponseThreshold [DERIVED] (also: ` — full response threshold (float) |
| 0059e5fc | flt_59E5FC | R | FrameRateCorrectionFactor [DERIVED] (also: ` â€” global frame-rate correction) |
| 0059e7e8 | flt_59E7E8 | R | TimeScalingConstant [DERIVED] |
| 0059e7ec | flt_59E7EC | R | ZeroConstant [DERIVED] (also: ` — compared constant (5.0f encoded indirectly) |
| 0059e824 | flt_59E824 | R | AIDynamicsThreshold [DERIVED] |
| 0059e87c | flt_59E87C | R | TimeStepMultiplier [DERIVED] |
| 0059e8cc | flt_59E8CC | R | WheelSpeedThreshold [DERIVED] (also: ` — wheel speed threshold (not in docs/12) |
| 0059e8e4 | flt_59E8E4 | R | WetGripThreshold [DERIVED] |
| 0059e8ec | flt_59E8EC | R | SpeedDeadzone [DERIVED] |
| 0059e8f4 | flt_59E8F4 | R | PhysicsThreshold_59E8F4 [DERIVED] |
| 0059e91c | flt_59E91C | R | ShortConversionMult [DERIVED] (also: conversion multipliers) |
| 0059e944 | flt_59E944 | R | Physics_Float_59E944 [DERIVED] |
| 0059eb48 | dbl_59EB48 | R | RideHeightThreshold [DERIVED] |
| 005acb30 | flt_5ACB30 | R | PhysicsForceThreshold [DERIVED] |
| 005acd7c | flt_5ACD7C | R | Flt_5ACD7C_Race [DERIVED] |
| 005acd80 | flt_5ACD80 | R | Unknown_Float_5ACD80 [DERIVED] |
| 005acd84 | flt_5ACD84 | R | DepthOfFieldScale [DERIVED] |
| 005acd88 | dbl_5ACD88 | R | UnknownDoubleConst3 [DERIVED] |
| 005acd90 | flt_5ACD90 | R | Flt_Unknown_Display [DERIVED] |
| 005acd94 | flt_5ACD94 | R | Flt_AiAudioFreqGain_CD94 [DERIVED] |
| 005acd98 | flt_5ACD98 | R | Unknown_Float_5ACD98 [DERIVED] |
| 005acd9c | flt_5ACD9C | R | UnknownFloat_5ACD9C [DERIVED] |
| 005acda0 | dbl_5ACDA0 | R | WheelContactForceThreshold [DERIVED] |
| 005c26ec | aIgnoredBlueFla | R | IgnoredBlueFlag [DERIVED] |
| 005c2710 | aCutTrack | R | StringCutTrack [DERIVED] |
| 005c271c | aSpeedingInPitl | R | Str_SpeedingInPitL [DERIVED] |
| 005c329c | dword_5C329C | R | VehicleCount [FACT] (also: ` — VehicleCount (set to 0 on join) |
| 005d25b0 | aWrongWay | R | WrongWayString [DERIVED] |
| 005d25bc | aLapWillNotCoun | R | Str_LapWillNotCount [DERIVED] |
| 005ea3fc | flt_5EA3FC | R | TrackRefSpeed [DERIVED] (also: ` â€” waypoint accumulation weight) |
| 005ea408 | flt_5EA408 | R | SessionMaxTime [DERIVED] (also: ` — threshold) |
| 005eb978 | dword_5EB978 | R | GameStatePtrArray3 [DERIVED] |
| 005ec4c0 | byte_5EC4C0 | R | EmptyStringBuffer [DERIVED] |
| 005ec4cc | byte_5EC4CC | RW | MessageDisplayBuffer [DERIVED] (also: ` (byte_5EC4CC) |
| 007c54dc | dword_7C54DC | R | CurrentPlayerIndex [CONFIRMED] |
| 007c54e4 | dword_7C54E4 | R | CurrentVehicleIndex [DERIVED] |
| 007c54f0 | dword_7C54F0 | R | VehiclePtrArray [FACT] |
| 007c56a4 | dword_7C56A4 | R | SessionType [FACT] |
| 007c56a8 | dword_7C56A8 | R | RacePhase [CONFIRMED] (also: ` — race phase (8 = ?) |
| 007cd204 | dword_7CD204 | R | ResourceDispatch_007CD204 [DERIVED] |
| 007cef84 | dword_7CEF84 | R | PenaltiesEnabled [DERIVED] |
| 008acfb4 | flt_8ACFB4 | R | IdleSpeedTarget [DERIVED] (also: ` â€” idle/reverse speed target) |
| 008ad264 | dword_8AD264 | R | PenaltyMessageQueue [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 004193a0 | AISessionModeTransition | [LLM] |
| 0041a4a0 | DisplayMessage0x11c | [LLM] |
| 0041a720 | sub_41A720 | [LLM] |
| 0041b3c0 | PitSelectionStateMachine | [LLM] |
| 0041b910 | ClearPitSelectionFlags | [LLM] |
| 00423a00 | BinarySearchInStringTable | [LLM] |
| 0045bd10 | TextLineWrappingAndRendering | [LLM] |
| 004bba90 | sub_4BBA90 | [LLM] |
| 004bbc60 | WarningHandler | [LLM] |
| 004bbd60 | StopGoPenaltyHandler | [LLM] |
| 004bc0e0 | DisqualificationHandler | [LLM] |
| 004bc340 | sub_4BC340 | [LLM] |
| 004d7c10 | FloatRangeIndexLookup | [LLM] |
| 004d7cf0 | FloatWrapTableInterpolation | [LLM] |
| 004eff00 | ForceDirectionProjection | [LLM] |
| 004f0050 | DistanceProjectionCalc | [LLM] |
| 004f01b0 | sub_4F01B0 | [LLM] |
| 00587bdc | CRTFtol | [LLM] |

**Guard conditions (deterministic — field vs literal):**

| Base | Offset | Test | Value | Field / meaning |
|------|--------|------|-------|-----------------|
| this | 0x14 | == | 18446744072627421184 → -1.0f | [LLM] |
| this | 0x60 | != | 2 | [LLM] |
| this | 0xD0 | > | 1 | [LLM] |

**Guard interpretation:** [LLM: from the table — what PASSES vs what is BLOCKED]
