// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00455290
// Canonical corpus name: InputActionRegistration
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/InputActionRegistration_00455290.c

void UnknownObject::registerInputActionStrings()
{
    // Straight-line free function that registers 44 input-action display strings by passing each string constant through StringCopyWithBufferRealloc. Every call pushes one global ASCII string (input action name) into the copy-with-realloc helper; the final call's result is returned. Called from HWInput_Enter during hardware-input initialization to populate the input action string table.
    // CALL: Register the steering/throttle/brake control strings: StringCopyWithBufferRealloc(aSteerRight), (aSteerLeft), (aAccelerate), (aBrake). [callee:0x00566650, global:0x005C567C, global:0x005C5670, global:0x005C5664, global:0x005C565C, source:raw]
    // CALL: Register the gear and clutch strings: (aShiftUp), (aShiftDown), (aNeutral), (aReverseGear), (aFirstGear), (aSecondGear), (aThirdGear), (aFourthGear), (aFifthGear), (aSixthGear), (aSeventhGear), (aClutch). [callee:0x00566650, global:0x005C5650, global:0x005C5644, global:0x005C563C, global:0x005C562C, global:0x005C5620, global:0x005C5614, global:0x005C5608, global:0x005C55FC, global:0x005C55F0, global:0x005C55E4, global:0x005C55D4, global:0x005C55CC, source:raw]
    // CALL: Register the electronic-aid and pit/limiter strings: (aTcOverride), (aLaunchControl), (aLcdMode), (aLcdUp), (aLcdDown), (aLcdIncrease), (aLcdDecrease), (aRequestPit), (aRpmLimiter), (aBrakeBiasF), (aBrakeBiasR). [callee:0x00566650, global:0x005C55C0, global:0x005C55B0, global:0x005C55A4, global:0x005C559C, global:0x005C5590, global:0x005C5580, global:0x005C5570, global:0x005C5564, global:0x005C5558, global:0x005C5548, global:0x005C5538, source:raw]
    // CALL: Register the camera/view, session and cockpit strings: (aLookLeft), (aLookRight), (aLookBehind), (aInstantReplay), (aPause), (aRestartRace), (aZeroHeadTracke), (aVehicleLabels), (aIgnition), (aStarter), (aHorn), (aHeadlights), (aHandbrake), (aLookUp), (aLookDown), (aLookRollLeft). [callee:0x00566650, global:0x005C552C, global:0x005C5520, global:0x005C5514, global:0x005C5504, global:0x005C54FC, global:0x005C54EC, global:0x005C54D8, global:0x005C54C8, global:0x005C54BC, global:0x005C54B4, global:0x005C54AC, global:0x005C54A0, global:0x005C5494, global:0x005C548C, global:0x005C5480, global:0x005C5470, source:raw]
    // RETURN: Register the final string aLookRollRight and return the result of its StringCopyWithBufferRealloc call as the function result. [callee:0x00566650, global:0x005C5460, source:raw]

    // Conservative worker pseudocode:
    //   int registerInputActionStrings() {
    //     StringCopyWithBufferRealloc(aSteerRight);
    //     StringCopyWithBufferRealloc(aSteerLeft);
    //     StringCopyWithBufferRealloc(aAccelerate);
    //     StringCopyWithBufferRealloc(aBrake);
    //     StringCopyWithBufferRealloc(aShiftUp);
    //     StringCopyWithBufferRealloc(aShiftDown);
    //     StringCopyWithBufferRealloc(aNeutral);
    //     StringCopyWithBufferRealloc(aReverseGear);
    //     StringCopyWithBufferRealloc(aFirstGear);
    //     StringCopyWithBufferRealloc(aSecondGear);
    //     StringCopyWithBufferRealloc(aThirdGear);
    //     StringCopyWithBufferRealloc(aFourthGear);
    //     StringCopyWithBufferRealloc(aFifthGear);
    //     StringCopyWithBufferRealloc(aSixthGear);
    //     StringCopyWithBufferRealloc(aSeventhGear);
    //     StringCopyWithBufferRealloc(aClutch);
    //     StringCopyWithBufferRealloc(aTcOverride);
    //     StringCopyWithBufferRealloc(aLaunchControl);
    //     StringCopyWithBufferRealloc(aLcdMode);
    //     StringCopyWithBufferRealloc(aLcdUp);
    //     StringCopyWithBufferRealloc(aLcdDown);
    //     StringCopyWithBufferRealloc(aLcdIncrease);
    //     StringCopyWithBufferRealloc(aLcdDecrease);
    //     StringCopyWithBufferRealloc(aRequestPit);
    //     StringCopyWithBufferRealloc(aRpmLimiter);
    //     StringCopyWithBufferRealloc(aBrakeBiasF);
    //     StringCopyWithBufferRealloc(aBrakeBiasR);
    //     StringCopyWithBufferRealloc(aLookLeft);
    //     StringCopyWithBufferRealloc(aLookRight);
    //     StringCopyWithBufferRealloc(aLookBehind);
    //     StringCopyWithBufferRealloc(aInstantReplay);
    //     StringCopyWithBufferRealloc(aPause);
    //     StringCopyWithBufferRealloc(aRestartRace);
    //     StringCopyWithBufferRealloc(aZeroHeadTracke);
    //     StringCopyWithBufferRealloc(aVehicleLabels);
    //     StringCopyWithBufferRealloc(aIgnition);
    //     StringCopyWithBufferRealloc(aStarter);
    //     StringCopyWithBufferRealloc(aHorn);
    //     StringCopyWithBufferRealloc(aHeadlights);
    //     StringCopyWithBufferRealloc(aHandbrake);
    //     StringCopyWithBufferRealloc(aLookUp);
    //     StringCopyWithBufferRealloc(aLookDown);
    //     StringCopyWithBufferRealloc(aLookRollLeft);
    //     return StringCopyWithBufferRealloc(aLookRollRight);
    //   }
    // UNRESOLVED: The exact destination buffer/table that StringCopyWithBufferRealloc writes into is not visible in this packet; the caller HWInput_Enter (00455BF0) suggests this fills the input-system action-name table used for keybinding display.
    // UNRESOLVED: Owner is unknown: the function takes no this pointer and the packet records no class evidence.
}
