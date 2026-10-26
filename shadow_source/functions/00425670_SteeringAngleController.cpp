// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00425670
// Canonical corpus name: SteeringAngleController
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SteeringAngleController_00425670.c

void UnknownObject::SteeringAngleController()
{
    // AI steering-angle and driver-status controller called per-frame from AIMainUpdate. When driverStatus (this+0x4510) == 6, computes the steering error as the wrapped angle from the vehicle heading (this+0x34F0) toward a target position read through this+0x4354 (+0x94/+0x9C) and exits to state 7 when the error is small or a timer this+0x447C has elapsed. Otherwise it computes the error from a direction vector (this+0x34F8/0x3500) against the heading, updates a steering-error accumulator this+0x446C (decrement toward 0 when on-aim or slow, +5 when off-aim), and when the accumulator exceeds this+0x4558 it resets AI state, calls RaceStartCountdownStateUpdate when gear (this+0x39FC) > 2, and sets driverStatus = 1. Finally, on the this+0x447C timer, it toggles driverStatus between 6 and 0 and snapshots the vehicle position into this+0x4470/0x4474/0x4478.
    // GUARD: Follow-target steering mode: when driverStatus (this+0x4510) == 6, take the target-relative path; otherwise the normal direction-vector path. [guard:1, field:this:0x00004510]
    // CALCULATION: Compute the heading error toward the target: atan2 of (target Z/X from this+0x4354 deref +0x94/+0x9C minus own position this+0x34E0/0x34E8), with pi/2 fallback when the delta is zero, then subtract own heading this+0x34F0 and wrap to [-pi, pi]. [field:*(this+0x4354):0x00000094, field:*(this+0x4354):0x0000009C, field:this:0x00004354, field:this:0x000034E0, field:this:0x000034E8, field:this:0x000034F0]
    // STATE_TRANSITION: In follow-target mode, when |heading error| < 0.5 rad or the snapshot timer this+0x447C has elapsed (dbl_8AFEA0 > this+0x447C), set driverStatus = 7. [field:this:0x00004510, field:this:0x0000447C, global:0x008AFEA0]
    // CALCULATION: Normal path: compute atan2 from the direction vector components this+0x34F8/0x3500 (pi/2 fallback when this+0x3500 == 0), subtract own heading this+0x34F0 and wrap the result to [-pi, pi]. [field:this:0x000034F8, field:this:0x00003500, field:this:0x000034F0]
    // CALCULATION: Steering-error accumulator: when |error| <= 0.5 or Speed (this+0x4440) <= 0.5, decrement this+0x446C toward 0 (clamped, no negative); otherwise increment this+0x446C by 5. [field:this:0x0000446C, field:this:0x00004440]
    // CALL: Accumulator overflow: when this+0x446C > this+0x4558 (threshold), if CurrentGear (this+0x39FC) > 2 call RaceStartCountdownStateUpdate(gear - 1), then reset this+0x446C = 0, call AIClearStateFlags(this), and set driverStatus (this+0x4510) = 1. [guard:0, field:this:0x000039FC, callee:0x004EF930, field:this:0x0000446C, callee:0x0042AE00, field:this:0x00004510, field:this:0x00004558]
    // STATE_TRANSITION: Position-snapshot timer: when dbl_8AFEA0 > this+0x447C, toggle driverStatus (this+0x4510) between 6 and 0 (the v12|v13 test is a decompiler artifact of the fabs guard), snapshot the vehicle position this+0x34E0/0x34E4/0x34E8 into this+0x4470/0x4474/0x4478, and rearm this+0x447C = now + 4.0. [global:0x008AFEA0, field:this:0x0000447C, field:this:0x00004510, field:this:0x000034E0, field:this:0x000034E4, field:this:0x000034E8, field:this:0x00004470, field:this:0x00004474, field:this:0x00004478]

    // Conservative worker pseudocode:
    //   if (vehicle->driverStatus == 6) {
    //     target = *(int*)(this + 0x4354);
    //     err = atan2(-(target->z - this->posZ), -(target->x - this->posX)) - this->yaw; // pi/2 fallback
    //     wrap err to [-pi, pi];
    //     if (fabs(err) < 0.5 || globalTime > this->snapshotTime_447C) vehicle->driverStatus = 7;
    //     goto snap;
    //   }
    //   err = atan2(-this->dirZ, -this->dirX) - this->yaw; // pi/2 fallback; wrap to [-pi, pi]
    //   if (fabs(err) <= 0.5 || this->Speed <= 0.5) acc = max(acc - 1, 0); else acc = acc + 5;
    //   if (acc > this->threshold_4558) {
    //     if (this->gear > 2) RaceStartCountdownStateUpdate(this->gear - 1);
    //     this->acc_446C = 0; AIClearStateFlags(this); vehicle->driverStatus = 1;
    //   }
    //   snap:
    //   if (globalTime > this->snapshotTime_447C) {
    //     vehicle->driverStatus = (vehicle->driverStatus == 6) ? 0 : 6;
    //     this->snapX_4470 = this->posX; this->snapY_4474 = this->posY; this->snapZ_4478 = this->posZ;
    //     this->snapshotTime_447C = globalTime + 4.0;
    //   }
    // UNRESOLVED: The v12|v13 test in the snapshot block is a decompiler c0/c2-flag artifact of the fabs(angle) comparison; the driverStatus toggle is treated as unconditional within the timer branch.
    // UNRESOLVED: The read-only float/double globals flt_59E43C, flt_59E440, flt_59E450, flt_59E46C, dbl_59E880, flt_59E888, dbl_59E890, dbl_59E898 have no visible use in the decompiled body; they may be consumed by called subroutines or belong to omitted table setup.
    // UNRESOLVED: Owner is UnknownObject per the packet (abi trust LEGACY, prototype null); no owner claim is made.
    // UNRESOLVED: The target struct behind this+0x4354 (+0x94/+0x9C) and the direction vector fields this+0x34F8/0x3500 have no packet names; the +0x34F0 heading/yaw role is CONFIRMED by both packet guard evidence and existing analysis.
}
