## InputActionRegistration_00455290 — RegisterInputActionStrings

**Summary:** Registers all input action display-name strings by copying them through StringCopyWithBufferRealloc. Called during input system initialization to populate the internal string table for keybinding/control names. Part of the hardware input subsystem.

**Frame-path:** NOT_FOUND  
**Call frequency:** UNKNOWN (no static path from tick root)

**Called by:** HWInput_Enter (00455bf0)

**Struct fields accessed:**

| Base | Offset | R/W | Init (literal → value) | Purpose |
|------|--------|-----|------------------------|---------|

**Globals referenced:**

| Address | Name | R/W | Role |
|---------|------|-----|------|
| 005c5460 | aLookRollRight | R | InputBinding_LookRollRight [DERIVED] |
| 005c5470 | aLookRollLeft | R | String_LookRollLeft [DERIVED] |
| 005c5480 | aLookDown | R | LookDownString [DERIVED] |
| 005c548c | aLookUp | R | LookUpString [DERIVED] |
| 005c5494 | aHandbrake | R | HandbrakeString [DERIVED] |
| 005c54a0 | aHeadlights | R | String_Headlights [DERIVED] |
| 005c54ac | aHorn | R | s_Horn [DERIVED] |
| 005c54b4 | aStarter | R | Starter [DERIVED] |
| 005c54bc | aIgnition | R | IgnitionField [DERIVED] |
| 005c54c8 | aVehicleLabels | R | VehicleLabelString [DERIVED] |
| 005c54d8 | aZeroHeadTracke | R | ZeroHeadTrackedString [DERIVED] |
| 005c54ec | aRestartRace | R | RestartRaceString [DERIVED] |
| 005c54fc | aPause | R | Str_Pause [DERIVED] |
| 005c5504 | aInstantReplay | R | StringInstantReplay [DERIVED] |
| 005c5514 | aLookBehind | R | LookBehindString [DERIVED] |
| 005c5520 | aLookRight | R | LookRightString [DERIVED] |
| 005c552c | aLookLeft | R | LookLeftString [DERIVED] |
| 005c5538 | aBrakeBiasR | R | BrakeBiasRConfigStr [DERIVED] |
| 005c5548 | aBrakeBiasF | R | BrakeBiasFString [DERIVED] |
| 005c5558 | aRpmLimiter | R | RpmLimiterField [DERIVED] |
| 005c5564 | aRequestPit | R | InputBinding_RequestPit [DERIVED] |
| 005c5570 | aLcdDecrease | R | String_LcdDecrease [DERIVED] |
| 005c5580 | aLcdIncrease | R | LcdIncreaseString [DERIVED] |
| 005c5590 | aLcdDown | R | LcdDownString [DERIVED] |
| 005c559c | aLcdUp | R | LcdUpString [DERIVED] |
| 005c55a4 | aLcdMode | R | String_LcdMode [DERIVED] |
| 005c55b0 | aLaunchControl | R | aLaunchControl [DERIVED] |
| 005c55c0 | aTcOverride | R | s_TCOverride [DERIVED] |
| 005c55cc | aClutch | R | sClutch [DERIVED] |
| 005c55d4 | aSeventhGear | R | SeventhGear [DERIVED] |
| 005c55e4 | aSixthGear | R | SixthGearField [DERIVED] |
| 005c55f0 | aFifthGear | R | FifthGearString [DERIVED] |
| 005c55fc | aFourthGear | R | FourthGearString [DERIVED] |
| 005c5608 | aThirdGear | R | ThirdGearString [DERIVED] |
| 005c5614 | aSecondGear | R | Str_SecondGear [DERIVED] |
| 005c5620 | aFirstGear | R | StringFirstGear [DERIVED] |
| 005c562c | aReverseGear | R | ReverseGearString [DERIVED] |
| 005c563c | aNeutral | R | NeutralString [DERIVED] |
| 005c5644 | aShiftDown | R | ShiftDownString [DERIVED] |
| 005c5650 | aShiftUp | R | ShiftUpConfigStr [DERIVED] |
| 005c565c | aBrake | R | ComponentNameBrake [DERIVED] |
| 005c5664 | aAccelerate | R | AccelerateString [DERIVED] |
| 005c5670 | aSteerLeft | R | SteerLeftField [DERIVED] |
| 005c567c | aSteerRight | R | InputBinding_SteerRight [DERIVED] |

**Functions called:**

| Address | Name | Purpose |
|---------|------|---------|
| 00566650 | StringCopyWithBufferRealloc | Copies a string into a managed buffer, reallocating if needed — registers the input action's display name |

**Guard conditions:** None — unconditional; all 46 strings are registered every call.
