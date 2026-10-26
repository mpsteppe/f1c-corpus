// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004A6340
// Canonical corpus name: PitStopOperationTimer
// Owner: F1CPitMachine [CONFIRMED]
// Raw source: functions/PitStopOperationTimer_004a6340.c

void F1CPitMachine::PitStopOperationTimer()
{
    // Per-frame pit stop operation timing and sequence coordinator on the pit machine. Clears the operation-progress block, then either (active branch) advances the vehicle progress bar via ProgressBarIncrement and pushes the result through the physics channel, or (idle branch) computes the max duration of all pending operations — base time, tire/wheel part changes, crew part-group loop, tire-change state transitions, wheel-gun operations and audio/visual effect gates — from sampled flt_8AAE74 values, frame time bases, and vehicle gate flags. On pit-state transitions it dispatches ConditionalMathDispatch, NthValidPartLookup/CompoundIndexLookup part resolution, LoopWithConditionalSubCall, ProgressBarEventEncode, sub_4A35F0 channel processing and AudioSoundEffectController. Returns 0.0 while the vehicle pit state obj+0x32C8 equals 1 and PitStopBlockingCondition holds, otherwise the accumulated duration.
    // ASSIGNMENT: Clear the operation-progress block this[111..115] (this+0x1BC through this+0x1CC) to 0 and initialize the duration accumulator v42 to 0.0. [field:this:0x000001BC, field:this:0x000001C0, field:this:0x000001C4, field:this:0x000001C8, field:this:0x000001CC]
    // GUARD: Pit stop active branch: pit stop active flag this+0x2C (this[11]) non-zero selects the in-progress progress-bar path; otherwise the idle timing computation runs. [field:this:0x0000002C]
    // CALL: Advance the vehicle progress field (v4 + 4109) via ProgressBarIncrement; store the result into the progress slot this+0x1BC and the local duration v42. [callee:0x004BBF20, field:this:0x000001BC]
    // CALL: When the physics channel this+0x8 (this[2]) is present, run PhysicsChannelProcessingWithLocals(channel, v45) and then FlagSetterWithOR(channel, this+0x1A0). [callee:0x004A3820, callee:0x004A3560, field:this:0x00000008, field:this:0x000001A0]
    // GUARD: Idle timing branch only runs while the vehicle pit state obj+0x32C8 (v4[3250]) is zero. [field:obj:0x000032C8]
    // CALCULATION: Base time offset v7 = (float(this+0x18C) + 25.0 - dbl_8AFEA0) * 0.5, clamped to the range [0, 4.5]. [field:this:0x0000018C, global:0x008AFEA0]
    // GUARD: Pit stop type: when the vehicle pit type obj+0x4040 (v4[4112]) equals 2 (regular stop) the lap part index taken from obj+0x403C (v4[4111]) is incremented. [field:obj:0x00004040, field:obj:0x0000403C, guard:1]
    // LOOP: Scan the part-selection list starting at this+0x164 (this[89], stepping by 2 dwords, reading this+0x168 as the second element of each pair) for the first entry that is non-negative, bounded by the part count this+0x160 (this[88]); when the target index falls inside the list, clear the trailing entries to the signed-min sentinel 0x80000000 and store the sentinel at the found slot. [field:this:0x00000164, field:this:0x00000168, field:this:0x00000160, guard:2, guard:3]
    // ASSIGNMENT: Read the vehicle object pointer from float this+0x0 and populate this+0x1B0 (this[108]) from the vehicle field at byte 14724. [field:this:0x00000000, field:this:0x000001B0]
    // CALCULATION: Accumulate total time v16 = this[27] (this+0x6C) * double(this+0x60) + double(this+0x58); store the result into float this+0x1B8 and v45[0]. [field:this:0x0000006C, field:this:0x00000060, field:this:0x00000058, field:this:0x000001B8]
    // GUARD: Operation completion check: if v16 <= float(this+0x1B0) the operation is complete and, when global dword_7C56A4 differs from 7, SpeedValueSetterWithGlobalMirror is dispatched with the time value. [field:this:0x000001B0, global:0x007C56A4, callee:0x004F1890]
    // CALCULATION: Running path: set this+0x1C0 (this[112]) to 1, compute the incremental step (v16 - float this+0x1B0) * 0.083333336, add a sampled flt_8AAE74 entry via the rotating index dword_8AAE70 plus v7 and 1.5, accumulate the max into v42, and store this+0x1B4 = channel time + v7 + 1.0. [field:this:0x000001C0, field:this:0x000001B0, field:this:0x000001B4, global:0x008AAE74, global:0x008AAE70]
    // GUARD: Crew/part-change group: this+0xAC (this[43]) non-zero enables the four-part crew loop. [field:this:0x000000AC]
    // LOOP: Four-entry loop sampling flt_8AAE74 entries through the rotating index dword_8AAE70, squaring each sample into v45[i+1]/v48[i], tracking the running max v44; then extend the duration to v44 + v46 + 6.5. [global:0x008AAE74, global:0x008AAE70]
    // CALL: Resolve the current valid part via NthValidPartLookup(this, this[43]); set this+0x1C4 (this[113]) to 1. [callee:0x004A5820, field:this:0x000000AC, field:this:0x000001C4]
    // LOOP: Match the resolved part against CompoundIndexLookup(v28) within the part count held through this+0x158 (this[86][4]); on match run LoopWithConditionalSubCall(v28, 1). [callee:0x004D7570, callee:0x004F1A60, field:this:0x00000158]
    // ASSIGNMENT: Store this+0x1D0 (this[116]) = this+0x1A0 and float this+0x1D4 = part max time + v46 + 5.5. [field:this:0x000001D0, field:this:0x000001D4, field:this:0x000001A0]
    // GUARD: Tire-change state transition: previous tire state this+0xEC (this[59]) differs from current tire state this+0xF0 (this[60]). [field:this:0x000000EC, field:this:0x000000F0]
    // CALL: On tire change: set this+0x1C8 (this[114]) to 1, extend the duration to v46 + 8.0 and v54 to 8.0, then dispatch ConditionalMathDispatch(27, this[59] * double(this+0xE0) + double(this+0xD8)). [callee:0x004F1860, field:this:0x000001C8, field:this:0x000000EC, field:this:0x000000E0, field:this:0x000000D8]
    // GUARD: Wheel-gun/pit operation group: this+0x12C (this[75]) non-zero enables effect dispatch and the vehicle gate flag checks. [field:this:0x0000012C]
    // CALL: Set this+0x1CC (this[115]) to 1; when dword_83EE60 is below 1023 increment it and add 432 to dword_8AAE64; dispatch ProgressBarEventEncode(6, 0, 0, this[1] (this+0x4), dbl_8AFEA0, 0). [field:this:0x000001CC, global:0x0083EE60, global:0x008AAE64, callee:0x004B33B0, field:this:0x00000004, global:0x008AFEA0]
    // CALCULATION: Extend the operation duration with vehicle gate flags: vehicle pit-block flag obj+0xCD4 and the vehicle audio flags at obj+0x1054/obj+0x105C gate extra margins of v46 + 8.0 and v46 + 39.0; add a sampled flt_8AAE74 entry via dword_8AAE70, updating the maxima v42 and v54. [field:obj:0x00000CD4, field:obj:0x00001054, field:obj:0x0000105C, global:0x008AAE74, global:0x008AAE70]
    // CALL: Channel dispatch: when the physics channel this+0x8 is present run sub_4A35F0(channel, &v46), FlagSetterWithOR(channel, this+0x1A0), and PerElementConditionalActionDispatcher(channel, 1). [callee:0x004A35F0, callee:0x004A3560, callee:0x004A34A0, field:this:0x00000008, field:this:0x000001A0]
    // CALL: Audio effect: when dword_7CF884 is positive and the vehicle audio byte obj+0x105C is set, clear it and play AudioSoundEffectController(obj+0x1054). [global:0x007CF884, field:obj:0x0000105C, field:obj:0x00001054, callee:0x004E0ED0]
    // RETURN: Final guard: if the vehicle pit state obj+0x32C8 equals 1 and PitStopBlockingCondition(vehicle) holds, return 0.0; otherwise return the accumulated duration v42. [field:obj:0x000032C8, callee:0x0042AEE0, guard:0, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   clear this[111..115]; v42 = 0;
    //   if (this[11]) { advance progress bar; push through physics channel; }
    //   else {
    //     v7 = clamp((this[99] + 25 - dbl_8AFEA0) * 0.5, 0, 4.5);
    //     if (vehicle pit type == 2) lapIndex++;
    //     scan part list for first non-negative entry; clear trailing slots;
    //     accumulate time from frame bases; complete or step toward completion;
    //     if (crew group) { sample 4 times; resolve part; dispatch loop; }
    //     if (tire state changed) dispatch ConditionalMathDispatch;
    //     if (wheel-gun group) encode progress event;
    //     push through channel; maybe play audio effect;
    //   }
    //   return (pit state == 1 && blocking) ? 0.0 : v42;
    // UNRESOLVED: Twelve globals (flt_59E43C, flt_59E440, flt_59E450, flt_59E4DC, flt_59E8A0, flt_59E8A4, flt_59E918, flt_59E960, flt_59E994, flt_5ACB54, flt_5ACB58, flt_5ACB5C) are listed as read globals in the packet but do not appear in the rendered decompiled source; their role is unknown.
    // UNRESOLVED: Guard 3 (this+0x168 > 0) is attributed to the part-list scan region but its exact source expression is ambiguous in the rendered code.
    // UNRESOLVED: Vehicle byte gates at obj+3348/3352/3416 gate the 8.0/39.0 time margins but are not in the packet field list; treated as part of the obj+0xCD4/0x1054 checks.
}
