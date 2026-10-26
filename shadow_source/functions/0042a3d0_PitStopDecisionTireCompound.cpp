// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042A3D0
// Canonical corpus name: PitStopDecisionTireCompound
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/PitStopDecisionTireCompound_0042a3d0.c

void F1CVehicle::PitStopDecisionTireCompound()
{
    // Per-frame AI pit-stop logic on the F1CVehicle: schedules tire-compound selection relative to lap count and session state, re-arms wing-repair lap records, and on a blocking condition retires the vehicle (sets RetiredFlag, clears AIControlFlag, logs via sub_4BC060) and cleans up the pit-stop state.
    // ASSIGNMENT: Set pit-lane flag at +0x4548 to 1 and clear byte at +0x4584 to 0 on entry. [field:this:0x00004548, field:this:0x00004584, source:raw]
    // CALCULATION: Compute tire-change timing value v4: if lap counter at +0x45E0 plus 1 exceeds lap count at +0x4588, branch on session dword_7C56A4 == 7 (use dword_8ACF8C - lapNumber + 1.5, and set +0x4584 to 1 when dword_7C56A8 != 8; otherwise use per-lap record) or use per-lap record; else add 1.5 to record difference against lapNumber at +0x403C. Store to local v17. [field:this:0x000045E0, field:this:0x00004588, field:this:0x0000403C, global:0x007C56A4, global:0x007C56A8, global:0x008ACF8C, source:raw]
    // GUARD: If rear-wing pit data flag at obj+0xD18 is set, obj+0xD58 is clear and dword_7C56A4 == 7: call ConditionalGate, clear +0x4584, write lapNumber to the current-lap tire record slot and set the tire-choice index to 8. [field:obj:0x00000D18, field:obj:0x00000D58, field:this:0x0000403C, field:this:0x00004584, global:0x007C56A4, callee:0x004EFAC0, source:raw]
    // GUARD: If byte at +0x39FA is set and dword_7C56A4 == 7: call ConditionalGate, clear +0x4584, write lapNumber to the current-lap tire record slot and set the tire-choice index to 8 (same re-arm path as the rear-wing condition). [field:this:0x000039FA, field:this:0x0000403C, field:this:0x00004584, global:0x007C56A4, callee:0x004EFAC0, source:raw]
    // STATE_TRANSITION: If PitStopBlockingCondition(this) or dword_7C56A4 != 7: set local result v16 to 0, call SceneRenderUpdate(0), set time-of-next-exit at +0x4534 to dbl_8AFEA0 + 180.0, and when dword_7C56A4 == 7 additionally set RetiredFlag at +0x4410 to 1, clear AIControlFlag at +0x45F4 to 0 and call sub_4BC060(1) to log the retirement. [callee:0x0042AEE0, callee:0x004C6D90, callee:0x004BC060, field:this:0x00004534, field:this:0x00004410, field:this:0x000045F4, global:0x007C56A4, global:0x008AFEA0, source:raw]
    // CALCULATION: Clamp v17 to a 3.0 minimum, multiply by compound scale at +0x45E8, cap at the field +0x3988, store into the current-lap tire-compound slot and call ClampedIndexAssignment with the result. [field:this:0x000045E8, field:this:0x00003988, callee:0x004A5BD0, source:raw]
    // CALL: When v16 is clear (blocking path taken): call SpeedValueSetterWithGlobalMirror with the compound value and PostPitCleanup(this). [callee:0x004F1890, callee:0x0042A6F0, source:raw]
    // GUARD: If front-wing record (obj+0xCD4 set while obj+0xD14 clear) or rear-wing record (obj+0xD18 set while obj+0xD58 clear) indicates a damaged wing: call StateTransition(1). [field:obj:0x00000CD4, field:obj:0x00000D14, field:obj:0x00000D18, field:obj:0x00000D58, field:this:0x00000000, callee:0x004A56B0, source:raw]
    // CALCULATION: Select compound tier index v18 from flt_8AFEE8 thresholds (>=0.66 -> 6, >=0.33 -> 5, >=0.01 -> 4), falling back to the stored next-chosen-tires value at +0x458C below 0.01. [global:0x008AFEE8, field:this:0x0000458C, source:raw]
    // LOOP: Scan up to 7 entries starting at this+0x4600; when an entry matches the selected tier index, decrement the index at +0x3378 (via IndexDecrementWithBoundsWrap or UtilityFunction_5750) at most 8 times. [field:this:0x00004600, field:this:0x00003378, callee:0x004A57A0, callee:0x004A5750, source:raw]
    // RETURN: Return v16 as the byte service-ready result. [function:0x0042A3D0, source:raw]

    // Conservative worker pseudocode:
    //   vehicle->pitLaneFlag(0x4548) = 1; vehicle->stateByte(0x4584) = 0;
    //   timing = tireChangeTiming(vehicle->lapCounter(0x45E0), vehicle->lapCount(0x4588), vehicle->lapNumber(0x403C), sessionTier, dword_8ACF8C);
    //   if (rearWingRepairRequested(obj 0xD18/0xD58, sessionTier==7)) { ConditionalGate(this+3); rearmLapRecord(lapNumber, tireIndex=8); }
    //   if (secondaryGate(0x39FA) && sessionTier==7) { ConditionalGate(this+3); rearmLapRecord(lapNumber, tireIndex=8); }
    //   if (PitStopBlockingCondition(this) || sessionTier!=7) { sceneUpdate(); vehicle->timeOfNextExit(0x4534) = dbl_8AFEA0 + 180.0; if (sessionTier==7) { vehicle->RetiredFlag(0x4410)=1; vehicle->AIControlFlag(0x45F4)=0; sub_4BC060(1); } }
    //   clamped = ClampedIndexAssignment(max(timing,3.0) * scale(0x45E8), cap 0x3988); store to current-lap compound slot;
    //   if (!result) { SpeedValueSetterWithGlobalMirror(clamped); PostPitCleanup(this); }
    //   if (wingRecordDamaged(obj 0xCD4/0xD14 or 0xD18/0xD58)) StateTransition(1);
    //   tier = tierFromThreshold(flt_8AFEE8, fallback vehicle->nextChosenTires(0x458C));
    //   for each of 7 entries at 0x4600: if (entry == tier) adjustIndex(0x3378) up to 8 times;
    //   return result;
    // UNRESOLVED: Float literals flt_59E444, flt_59E478, flt_59E808, flt_59E8A4, flt_59E974, flt_59E978 are listed as accessed globals but do not appear in the raw decompiled body; they are likely consumed inside callees (ClampedIndexAssignment, SpeedValueSetterWithGlobalMirror).
}
