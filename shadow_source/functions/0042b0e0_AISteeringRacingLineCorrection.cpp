// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0042B0E0
// Canonical corpus name: AISteeringRacingLineCorrection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AISteeringRacingLineCorrection_0042b0e0.c

void UnknownObject::AISteeringRacingLineCorrection()
{
    // Per-frame AI steering correction: in race phase (dword_7C56A8 == 3) locates the reference opponent ahead on track and adjusts a track parameter based on wrapped distance; then, when an opponent pointer exists, handles overtaking/timing decisions, and otherwise computes steering angle relative to the racing line via nearest-waypoint search and rotation-matrix math, resetting dynamics when the vehicle is off-line.
    // GUARD: Race-phase branch: only when dword_7C56A8 == 3, scan the active grid (dword_7C54F0 array, count dword_5C329C) for the vehicle whose waypoint index at offset +16480 equals this vehicle's target index (field +0x4060 minus 1). [global:0x007C56A8, global:0x005C329C, global:0x007C54F0, field:this:0x00004060, source:raw]
    // CALCULATION: Wrap the along-track distance difference between the reference vehicle (DistanceProjectionCalc on its base) and this vehicle (DistanceProjectionCalc on this+3) into the interval [-0.5 * flt_5EA3FC, 0.5 * flt_5EA3FC]. [callee:0x004F0050, global:0x005EA3FC, source:raw]
    // CALCULATION: When the wrapped distance exceeds -200.0: clamp twice the distance to a 15.0 minimum via TrackParameterMinimumClamp; then, if gate field +0x4440 is below 1.0 and the reference vehicle's speed magnitude (sqrt of its +3390..+3392 components) is under 0.2 and the lap-scaled condition (v26+5)*0.4 + flt_8ACF94 exceeds dbl_8AFEA0, zero field +0x4434. [callee:0x0042A740, field:this:0x00004440, field:this:0x00004434, global:0x008ACF94, global:0x008AFEA0, source:raw]
    // GUARD: If no matching reference vehicle was found (v3 reached dword_5C329C), call TrackParameterMinimumClamp(this, 49.0); then cap field +0x4434 at 0.9. [global:0x005C329C, callee:0x0042A740, field:this:0x00004434, source:raw]
    // GUARD: Enter opponent-handling section when dword_7C56A8 == 1, or when dword_7C56A8 == 3 and flt_8ACF94 + 30.0 <= dbl_8AFEA0. Reads the opponent pointer field +0x3AA8 and its validity flag at obj+0x12C to split between the opponent-present and opponent-absent paths. [global:0x007C56A8, global:0x008ACF94, global:0x008AFEA0, field:this:0x00003AA8, field:*(this+0x3AA8):0x0000012C, source:raw]
    // CALCULATION: Opponent-present, dword_7C56A8 == 1 path: if DistanceComparison(this+3) and target RPM at +0x39A8 exceeds EngineRPM at +0x39A0 and |dbl_8AFEA0 - field +0x4460| > 10.0, compute interrupt time v9 = speed(+0x4) * 8.5 via InterruptDispatch; if dbl_8AFEA0 <= v9 + 1.0 + field +0x4448*20.0 + flt_8ACF90, zero steering accumulator +0x442C; otherwise pick a random maneuver via RandomWeightedTierSelection + LoopWithConditionalSubCall, compute capped speed target v11 = min(scale(0x45E8)*1.5 + threshold(0x3984), cap(0x3988)) applied via SpeedValueSetterWithGlobalMirror and VehicleClimbAdjust(0), clear +0x4354/+0x4358, record dbl_8AFEA0 into +0x4460, and set maneuver state fields +0x4510 = 5, +0x4550 = 1, +0x4538 = flt_8ACFB4. [callee:0x004EFFD0, field:this:0x000039A8, field:this:0x000039A0, field:this:0x00004460, field:this:0x00000004, callee:0x0058957A, field:this:0x00004448, global:0x008ACF90, field:this:0x0000442C, callee:0x00429FD0, callee:0x004F1A60, field:this:0x000045E8, field:this:0x00003984, field:this:0x00003988, callee:0x004F1890, callee:0x004EFA40, field:this:0x00004354, field:this:0x00004358, field:this:0x00004510, field:this:0x00004550, field:this:0x00004538, global:0x008ACFB4, source:raw]
    // CALCULATION: Opponent-absent path: dispatch via SingleFunctionDispatch_10e0 on vtable field +0x0, transform with F_3DTransformWithMatrixMultiplication, compute the relative offset to the racing line, its magnitude v36 (via sqrt) and a track parameter v23 = dist*0.4 + 3.0 clamped through TrackParameterMinimumClamp. [callee:0x004D10E0, field:this:0x00000000, callee:0x004EFB20, callee:0x0042A740, source:raw]
    // LOOP: When byte_7CEC18 is set, iterate over up to min(dword_5C329C + 2, 104) waypoints via sub_403CD0, tracking the nearest by distance; if nearest < 80.0, clamp (nearest - 20.0) to a 35.0 minimum via TrackParameterMinimumClamp; if nearest < 35.0, compute steering field +0x442C as atan2 against the vehicle rotation axes (+0x34BC..+0x34DC) divided by +0x44B4 and clamp it to [-1.0, 1.0]. [global:0x007CEC18, global:0x005C329C, callee:0x00403CD0, global:0x005EA2C0, callee:0x0042A740, field:this:0x0000442C, field:this:0x000034BC, field:this:0x000034C4, field:this:0x000034C8, field:this:0x000034D0, field:this:0x000034D4, field:this:0x000034DC, field:this:0x000044B4, source:raw]
    // CALCULATION: If distance v36 < 40.0: build the rotation matrix via EulerToRotationMatrix and evaluate cross product v22; when v22 is in [0.0, 15.0) recompute steering +0x442C via atan2 against the rotation axes divided by +0x44B4 and clamp to [-1.0, 1.0]; when v22 < 0.0 call VehicleDynamicsStateReset(this+3) and AIVehiclePathPositionTracking, clear byte +0x45F4, and if dword_7C56A8 == 1 call ConditionalGate(this+3). [callee:0x00566E40, callee:0x004F2320, callee:0x004EF7C0, field:this:0x000045F4, global:0x007C56A8, callee:0x004EFAC0, field:this:0x0000442C, field:this:0x000044B4, source:raw]

    // Conservative worker pseudocode:
    //   if (dword_7C56A8 == 3) {
    //     ref = findVehicleWithWaypoint(activeGrid(dword_7C54F0, dword_5C329C), this->waypoint(0x4060) - 1);
    //     if (ref) { dist = wrapAlongTrack(DistanceProjectionCalc(ref) - DistanceProjectionCalc(this+3), flt_5EA3FC);
    //       if (dist > -200.0) { TrackParameterMinimumClamp(this, max(2*dist, 15.0)); if (gate(0x4440)<1.0 && refSlow(ref) && lateRace()) this->field(0x4434)=0.0; } }
    //     else TrackParameterMinimumClamp(this, 49.0);
    //     if (this->field(0x4434) > 0.9) this->field(0x4434) = 0.9;
    //   }
    //   if (dword_7C56A8 == 1 || (dword_7C56A8 == 3 && flt_8ACF94 + 30.0 <= dbl_8AFEA0)) {
    //     if (opponent(0x3AA8) && opponent->valid(0x12C)) { overtakingTimingLogic(this); }
    //     else { racingLineSteeringLogic(this); }
    //   }
    // UNRESOLVED: Twenty float globals in the 0x59E43C..0x59E99C range and dword_7CEC30 / dword_8ACEE0 are declared as read globals but do not appear in the raw decompiled body; they are likely consumed inside callees such as TrackParameterMinimumClamp, sub_403CD0 and SpeedValueSetterWithGlobalMirror.
}
