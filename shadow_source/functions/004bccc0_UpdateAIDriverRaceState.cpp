// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BCCC0
// Canonical corpus name: sub_4BCCC0
// Owner: AIDriverController [DERIVED]
// Raw source: functions/sub_4BCCC0_004bccc0.c

void AIDriverController::UpdateAIDriverRaceState()
{
    // Per-frame AI driver race-state update (called from MainGameTickUpdate): recomputes and wraps the driver's track distance projection, enforces pit-lane speed limits with stop-go penalties and monetary fines, detects corner cutting and wrong-way driving, manages cut-track/blue-flag penalty timers, and drives pit-entry selection based on nearby vehicle proximity.
    // CALL: Derive vehicle context base v3 from this[0]+12 and load vehicle block v5; compute per-vehicle track distance via DistanceProjectionCalc(v3). [callee:0x004F0050, field:this:0x00000000, field:obj:0x00003AA8, source:raw]
    // ASSIGNMENT: Store computed track distance into this[5] (race track position/progress field). [callee:0x004F0050, field:this:0x00000014]
    // GUARD: Skip distance wrap while this[5] holds the -1.0 sentinel (guard:0). [guard:0, field:this:0x00000014]
    // CALL: Wrap track distance with FloatWrapTableInterpolation; re-wrap this[5] when distance >= 0.666. [callee:0x004D7CF0, guard:0, field:this:0x00000014]
    // GUARD: Entering pit lane: session pit-lane flag at obj+0x344C is set. [field:obj:0x0000344C, field:this:0x000000A8]
    // STATE_TRANSITION: Pit-lane entry transition: set byte flag this[42] and clear speed-penalty accumulator this[43] when previously not in pit lane. [field:obj:0x0000344C, field:this:0x000000A8, field:this:0x000000AC]
    // CALCULATION: Accumulate pit-lane speed excess into this[43] as (speed magnitude - flt_8ACFB4) * delta_time while the excess is positive. [field:this:0x000000AC, global:0x008ACFB4]
    // GUARD: Pit-lane exit: if accumulated speed penalty this[43] > 7.5 and penalties are enabled (dword_7CEF84). [field:this:0x000000A8, field:this:0x000000AC, global:0x007CEF84, global:0x007C56A4]
    // CALL: Racing mode (dword_7C56A4 == 7): apply fixed stop-go penalty of 10s for aSpeedingInPitl. [callee:0x004BBD60, global:0x005C271C, global:0x007C56A4, field:this:0x00000000]
    // CALL: Other modes: compute monetary fine via CRTFtol((this[43]-7.5)*0.025)*500 + 1500 and apply it through sub_4BBA90(this, aSpeedingInPitl, fine). [callee:0x00587BDC, callee:0x004BBA90, global:0x005C271C, global:0x007CEF84, field:this:0x000000AC]
    // CALCULATION: Project vehicle position onto the track segment direction to compute lateral offset v68, clamped by track half-widths (v5+104/108). [field:*(obj+0x3AA8):0x00000000, field:*(obj+0x3AA8):0x00000004, field:*(obj+0x3AA8):0x00000008, field:*(obj+0x3AA8):0x00000020, field:*(obj+0x3AA8):0x00000024, field:*(obj+0x3AA8):0x00000028, field:*(obj+0x3AA8):0x00000068, field:*(obj+0x3AA8):0x0000006C, field:obj:0x000034E0, field:obj:0x000034E4, field:obj:0x000034E8]
    // CALL: Query corner-cut tracking enablement via sub_4BC340(this). [callee:0x004BC340, field:this:0x000000B4]
    // GUARD: Corner-cut resolution active: byte flag this[45] (offset 180) is set and lateral offset < 1.0. [field:this:0x000000B4]
    // CALCULATION: Track corner-cut severity: keep minimum ForceDirectionProjection in this[51], accumulate this[50] += delta_time. [callee:0x004EFF00, field:this:0x000000CC, field:this:0x000000C8]
    // CALCULATION: Estimate gained distance from the corner cut via sub_4F01B0, lap/segment deltas and flt_5EA408; build the speed compensation into the corner-cut timing value. [callee:0x004F01B0, global:0x005EA408, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000B8, field:this:0x000000BC, field:this:0x00000008, field:this:0x0000002C]
    // CALCULATION: Normalize the direction vector and compute corner-cut depth v66 against track boundary vectors (v5+164/168/172). [field:*(obj+0x3AA8):0x000000A4, field:*(obj+0x3AA8):0x000000A8, field:*(obj+0x3AA8):0x000000AC, field:this:0x000000CC]
    // GUARD: Corner-cut violation: depth v66 > 1.75 and penalties enabled; repeat count this[52] > 1 or depth > 2.75 (guard:2). [guard:2, global:0x007CEF84, field:this:0x000000D0]
    // CALL: Apply aCutTrack penalty: stop-go of 10s in racing mode, otherwise a warning via WarningHandler(this, aCutTrack). [callee:0x004BBD60, callee:0x004BBC60, global:0x005C2710, global:0x007C56A4, guard:2, field:this:0x000000D0]
    // CALL: Increment cut-track counter this[52] and set flag this[24]=1; when the lap will not count, look up aLapWillNotCoun in the string table and render it as a message. [field:this:0x000000D0, field:this:0x00000060, global:0x005D25BC, global:0x005EC4C0, global:0x005EC4CC, global:0x007CD204, callee:0x00423A00, callee:0x0045BD10]
    // STATE_TRANSITION: Begin corner-cut tracking when lateral offset > 2.5: snapshot lap this[47], segment value this[48], projection this[49], reset accumulators, set the in-progress flag. [callee:0x004EFF00, callee:0x004F01B0, field:this:0x000000B4, field:this:0x000000BC, field:this:0x000000B8, field:this:0x000000C0, field:this:0x000000C4, field:this:0x000000C8, field:this:0x000000CC, field:*(obj+0x3AA8):0x0000012C, field:this:0x00000008]
    // ASSIGNMENT: When corner-cut tracking is not enabled, clear the in-progress flag this[45]. [callee:0x004BC340, field:this:0x000000B4]
    // CALCULATION: Wrong-way check: read the direction block pointer at v5+272, project the block offset onto the segment direction; if negative accumulate this[44] += -offset * delta_time / |dir|. [field:*(obj+0x3AA8):0x00000110, field:*(*(obj+0x3AA8)+0x110):0x00000000, field:*(*(obj+0x3AA8)+0x110):0x00000004, field:*(*(obj+0x3AA8)+0x110):0x00000008, field:*(obj+0x3AA8):0x00000000, field:*(obj+0x3AA8):0x00000004, field:*(obj+0x3AA8):0x00000008, field:this:0x000000B0]
    // CALL: Wrong-way warning: when the accumulator crosses 10, look up aWrongWay and render it; when a rival is on the same lap and the driver is moving forward, raise DisplayMessage0x11c. [callee:0x00423A00, callee:0x0045BD10, callee:0x0041A4A0, global:0x005D25B0, global:0x005EC4C0, global:0x005EC4CC, global:0x007CD204, global:0x007C54DC, global:0x007C54E4, global:0x007C54F0, field:this:0x000000B0]
    // CALL: Wrong-way disqualification when the accumulator crosses 125 and penalties are enabled. [callee:0x004BC0E0, global:0x005D25B0, global:0x007CEF84, field:this:0x000000B0]
    // GUARD: Early-return guard: skip pit-selection logic when the session pit-lane flag is set, mode dword_7C56A8 != 5, or lateral offset >= 8.0. [field:obj:0x0000344C, global:0x007C56A8]
    // RETURN: Exit path (LABEL_120) resets blue-flag timer this[55] to 0.0 before returning. [field:this:0x000000DC, global:0x007C56A8, field:obj:0x0000344C]
    // CALCULATION: Compute pit-proximity thresholds: distance base 37.0/87.0 by mode plus 3.0 blue-flag bonus; time-window base 0.8/1.9 plus 0.2 bonus. [global:0x007C56A4, field:this:0x000000D4, field:this:0x000000D8]
    // LOOP: Iterate all dword_5C329C vehicles, skipping self (this[1]); compute wrapped track-distance delta and test each candidate's proximity. [global:0x005C329C, global:0x007C54F0, global:0x005EA3FC, field:this:0x00000004, callee:0x004F0050]
    // GUARD: Candidate qualifies in a mode-specific way (racing: rival behind and off the driver's lap; non-racing: rival flagged) and the lateral gap is within the time window. [global:0x007C56A4, field:this:0x0000002C, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000060, guard:1]
    // ASSIGNMENT: Record the pit candidate: set blue-flag flag this[53] and the nearest candidate index this[54]. [field:this:0x000000D4, field:this:0x000000D8]
    // CALL: When no candidate, the recorded index changed, or mode != 7: clear pit-selection flags via ClearPitSelectionFlags(5, context) whenever the timer is nonzero. [callee:0x0041B910, field:this:0x000000D4, field:this:0x000000D8, field:this:0x000000DC, field:this:0x00000000, global:0x007C56A4]
    // CALL: Advance the pit-selection state machine (dword_5EB978) with events 1/2/3 on timer transitions at 0/10/20 seconds. [callee:0x0041B3C0, global:0x005EB978, field:this:0x000000DC, field:this:0x00000014, field:this:0x00000000]
    // CALL: Accumulate blue-flag timer this[55]; when it exceeds 30 and penalties are enabled, apply the ignored-blue-flag stop-go penalty, show the message via sub_41A720, and reset the timer. [field:this:0x000000DC, callee:0x004BBD60, callee:0x0041A720, global:0x005C26EC, global:0x007CEF84, field:this:0x00000000]

    // Conservative worker pseudocode:
    //   track_dist = DistanceProjectionCalc(context);
    //   if (this[5] != -1.0) { FloatWrapTableInterpolation(track_dist); if (track_dist >= 0.666) FloatWrapTableInterpolation(this[5]); }
    //   this[5] = track_dist;
    //   if (in_pit_lane) { this[42]=1; if (speed - flt_8ACFB4 > 0) this[43] += excess * dt; }
    //   else if (this[42]) { this[42]=0; if (this[43] > 7.5 && penalties_enabled) { if (mode==7) StopGoPenalty(aSpeedingInPitl, 10); else sub_4BBA90(this, aSpeedingInPitl, CRTFtol((this[43]-7.5)*0.025)*500+1500); } }
    //   if (corner_cut_enabled(this)) { if (in_progress && lateral < 1.0) { penalize/warn aCutTrack; maybe show lap-will-not-count; } else if (lateral > 2.5) begin_corner_cut_snapshot(); }
    //   else { clear_in_progress(); }
    //   wrong_way: accumulate this[44]; warn at 10; disqualify at 125;
    //   if (pit_lane_flag || mode!=5 || lateral >= 8.0) { this[55]=0; return; }
    //   pit selection: scan dword_5C329C vehicles, find candidate, drive PitSelectionStateMachine timer events, blue-flag penalty at 30s.
    // UNRESOLVED: Packet-listed callees FloatRangeIndexLookup (0x004D7C10) and AISessionModeTransition (0x004193A0) are not visible as calls in the raw decompiled body and cannot be placed.
    // UNRESOLVED: The many unplaced flt_/dbl_ float constants and dword_8AD264 are not visible as named reads in the decompiled source; Hex-Rays likely folded them into FPU immediates, so no grounded mapping exists.
    // UNRESOLVED: Packet field base expressions (obj / *(obj+0x3AA8) / *(*(obj+0x3AA8)+0x110)) are IDB-normalized; their exact correspondence to the raw pointer arithmetic (v3/v5/v34) is approximate. The obj+0x344C read is treated as the pit-lane/session flag read at context+13388.
    // UNRESOLVED: obj+0x34F8 / 0x34FC / 0x3500 field refs have no clear anchor in the decompiled source and are left unresolved.
    // UNRESOLVED: The existing-analysis label for obj+0x344C (segment normal) conflicts with the raw source reading a byte flag at context+13388; raw source reading was favored.
    // UNRESOLVED: The this+0x60 guard (guard:1, != 2) is tied to the cut-track / pit-proximity flag semantics only approximately.
}
