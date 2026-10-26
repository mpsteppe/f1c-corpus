// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00424E70
// Canonical corpus name: AIMainUpdate
// Owner: F1CVehicle [CONFIRMED]
// Raw source: functions/AIMainUpdate_00424e70.c

void F1CVehicle::AIMainUpdate()
{
    // Per-frame AI tick for a single vehicle. Entry guard on AIEnableFlag (this+0x32C8 > 1 rejects the whole tick). Two top-level paths: (a) pre-race/formation init when the base-object AI enable is 1 and this+0x45F4 byte is clear, which handles session-phase changes, ring-buffer reset, pit-schedule seeding, the countdown/launch light ramp, and commits throttle/brake outputs before returning; (b) the normal racing tick which computes heading sin/cos from yaw, runs a driveability gate, lap-push timed dispatch, AIAbility refresh, pit entry/exit state transitions, and a driverStatus state machine (0-7) that dispatches steering/racing-line/gearshift logic. Both paths end by writing control outputs into the input fields this+0x3580/0x3584/0x357C.
    // GUARD: Entry guard: if AIEnableFlag (this+0x32C8) > 1, return immediately, disabling the whole AI tick for this vehicle. [guard:2, field:this:0x000032C8, source:raw, function:0x00424E70]
    // ASSIGNMENT: Store the global simulation time dbl_8AFEA0 into this+0x4480 (last-AI-update timestamp). [field:this:0x00004480, global:0x008AFEA0]
    // GUARD: Pre-race init path gate: if the byte at this+0x45F4 is clear AND the base-object AI enable (obj+0x32C8) equals 1, take the formation/pre-race branch; otherwise fall through to the per-frame racing tick. The ==1 check on obj+0x32C8 is guard:1; the implicit negative (obj+0x32C8 != 1) is guard:0. [field:this:0x000045F4, field:this:0x00000000, field:obj:0x000032C8, guard:1, guard:0]
    // ASSIGNMENT: Zero this+0x4028 (AI internal counter) and this+0x4434 (throttle output) at session-phase entry. [field:this:0x00004028, field:this:0x00004434]
    // CALL: Session-phase change (dword_7C56A8 != this+0x444C): decrement countdown field this+0x4448 by 0.025 per frame; when it drops below 0, reset the AI ring buffers via AIRingBufferFieldInit. [field:this:0x0000444C, field:this:0x00004448, global:0x007C56A8, callee:0x00424C80]
    // CALL: When global session phase dword_7C56A8 is 5 or 1, clear session-cleanup flags via SessionCleanupFlagClear, then store the current phase into this+0x444C. [global:0x007C56A8, callee:0x0042ADB0, field:this:0x0000444C]
    // LOOP: Pit-schedule scan (when byte this+0x45F4 == 1 and global byte_5C3160 == 1): over the 5 ring entries at this+0x4144/0x4148, seed this+0x413C = now + 2.0, then per entry: state 4 with zeroed timer -> ConditionalGate(this+12) and schedule this+0x4170 = (RNG & 0x14) + now + 10.0; state 5 with zeroed timer -> ConditionalGate(this+12) and seed this+0x4068 (ReasonCode) with 7/3/8 selected by RNG%4. [guard:9, field:this:0x000045F4, global:0x005C3160, field:this:0x0000413C, field:this:0x00004144, field:this:0x00004148, callee:0x004EFAC0, field:this:0x00004170, callee:0x005884ED, field:this:0x00004068, global:0x008AFEA0]
    // CALL: Countdown start when this+0x444C == 4: set global byte_5C3160 = 1 and call RaceStartCountdownStateUpdate(0); elapsed time is measured against global flt_8ACFB8. [guard:7, field:this:0x0000444C, global:0x005C3160, callee:0x004EF930, global:0x008ACFB8]
    // CALCULATION: Countdown/launch light ramp: clamp (now - flt_8ACFB8) to [0,1], index the countdown animation table via CRTFtol into unk_5C30E0 or dword_5C3144 (toggle this+0x4568 selects which), write the resulting throttle into this+0x4434, and stagger the light timers this+0x4560/0x4564/0x4568 using RNG. [field:this:0x00004560, field:this:0x00004564, field:this:0x00004568, callee:0x00587BDC, global:0x005C30E0, global:0x005C3144, callee:0x005884ED, field:this:0x00004434, field:this:0x00004438, field:this:0x0000442C]
    // CALCULATION: Roll-off throttle mapping after the launch ramp: scale (this+0x399C - this+0x39A0) by an interpolation factor into this+0x4434 + 0.5, clamped to 0..1; clamp writes 1.0 into this+0x4438 and 0 into this+0x442C. [field:this:0x0000399C, field:this:0x000039A0, field:this:0x00004434, field:this:0x00004438, field:this:0x0000442C]
    // CALCULATION: LABEL_86 output commit: if carConditions (this+0x3D6C) == 2, zero throttle and ramp brake this+0x4438 from fabs(this+0x4428) (also 0.01 clamp), then write the committed control outputs into the input fields this+0x3580/this+0x3584/this+0x357C, clear this+0x45FC, and return. [guard:4, field:this:0x00003D6C, field:this:0x00004428, field:this:0x00004434, field:this:0x00004438, field:this:0x0000442C, field:this:0x00003580, field:this:0x00003584, field:this:0x0000357C, field:this:0x000045FC]
    // CALCULATION: Racing tick heading: compute -sin(yaw) and -cos(yaw) from this+0x34F0 (RenderX/yaw) into this+0x448C and this+0x4494 respectively (racing-line direction vectors). [field:this:0x000034F0, field:this:0x0000448C, field:this:0x00004494]
    // GUARD: Driveability gate: if sub_426430(this) returns false, or the base-object AI enable (obj+0x32C8) is not 1, return before any racing AI logic. [callee:0x00426430, field:this:0x00000000, guard:1]
    // CALL: Timed lap-push dispatch: when this+0x413C (timer) elapses, reset it to 2139095039; call AIStateFlagSetter(1) when global dword_7C56A8 == 8, otherwise call AIPushLap(this). [field:this:0x0000413C, global:0x007C56A8, callee:0x0042AC70, callee:0x0042A180]
    // LOOP: Lap pit-wait scan over the 5 entries at this+0x4144/0x4148: when the entry lap matches this+0x403C and this+0x4148 < 4, write this+0x416C = RNG % (int)this+0x416C (min 40.0 via this+0x409C) into the lap pit buffer slot 4*(this+0x4148) + this+0x3D70. [field:this:0x00004144, field:this:0x00004148, field:this:0x0000403C, field:this:0x0000409C, field:this:0x0000416C, guard:6, callee:0x005884ED, callee:0x00587BDC]
    // CALL: AIAbility refresh: if this+0x4480 (now) > this+0x4404 (next ability time), set this+0x4404 = this+0x4480 + 4.0 and call AIAbility(this). [field:this:0x00004480, field:this:0x00004404, callee:0x00429470]
    // STATE_TRANSITION: Pit entry: when the pit-wait timer this+0x4170 < this+0x4480 (now), clear AI state flags (AIClearStateFlags), set driverStatus this+0x4510 = 4 (when dword_7C56A4 == 7) or 5, reset the output/timer fields this+0x4524/0x4438/0x4434/0x454C/0x4550/0x4424 and counters this+0x43F8/0x443C, re-run the driveability gate sub_426430, arm the pit-exit timer this+0x447C = now + 4.0, and call VehicleClimbAdjust(0). [field:this:0x00004170, field:this:0x00004480, callee:0x0042AE00, global:0x007C56A4, field:this:0x00004510, field:this:0x00004524, field:this:0x00004438, field:this:0x00004434, field:this:0x0000454C, field:this:0x00004550, field:this:0x00004424, callee:0x00426430, field:this:0x0000447C, callee:0x004EFA40, field:this:0x000043F8, field:this:0x0000443C]
    // CALL: Racing-state dispatch when driverStatus (this+0x4510) is neither 4 nor 5: zero this+0x4420 when no state flag (this+0x45FC clear), carConditions (this+0x3D6C) != 2 and fuel/activity this+0x3984 > 0.001; then OpponentProximityScanTeamRecognition(this), write 1232348144 into this+0x4484, AIRacingLine(this), AISteering(this) when this+0x4550 < dword_5EA2CC, sub_426100(this), AISteeringCorrection(this), PhysicsGearShiftLogicWithThresholds(this). [field:this:0x000045FC, field:this:0x00003D6C, field:this:0x00003984, field:this:0x00004420, callee:0x0042A7D0, field:this:0x00004484, callee:0x00425920, field:this:0x00004550, global:0x005EA2CC, callee:0x004270A0, callee:0x00426100, callee:0x00426CF0, callee:0x00426330, guard:3]
    // STATE_TRANSITION: driverStatus (this+0x4510) state machine switch: case 0/6 -> SteeringAngleController(this); case 1 -> sub_4258C0(this); case 3 -> ArrayOfStructIndexedFieldCopy(dword_5EA2C0, obj+0x48A4, v39, v40) then squared-distance check between v39 and this+0x34E0/0x34E8 -> driverStatus = 0 when greater than this+0x461C, else this+0x461C = dist^2; case 2 -> FieldZeroSetter(this) and return; case 7 -> zero this+0x442C/0x4438/0x4434 and when Speed (this+0x4440) < 0.2 set driverStatus = 0. [field:this:0x00004510, callee:0x00425670, callee:0x004258C0, callee:0x00403F70, global:0x005EA2C0, field:obj:0x000048A4, field:this:0x000034E0, field:this:0x000034E8, field:this:0x0000461C, callee:0x00425660, field:this:0x00004440, field:this:0x0000442C, field:this:0x00004438, field:this:0x00004434]
    // STATE_TRANSITION: Pit-return / formation decision: when this+0x4534 (timeOfNextExit) has elapsed or driverStatus == 4, clear the this+0x45F4 byte when lap/finish conditions hold (this+0x4588 >= this+0x45E0 and dword_7C56A4 != 7, or FinishState this+0x4064 == 2); if sub_4A4110(this) passes and this+0x45F4 is set, driverStatus 5 -> RandomWeightedTierSelection(this), LoopWithConditionalSubCall(tier,1), VehicleClimbAdjust(0), driverStatus = 3, else driverStatus = 0; otherwise rearm this+0x4534 = now + 4.0. [field:this:0x00004534, guard:8, field:this:0x00004588, field:this:0x000045E0, field:this:0x000045F4, guard:5, field:this:0x00004064, callee:0x004A4110, callee:0x00429FD0, callee:0x004F1A60, callee:0x004EFA40, field:this:0x00004510]
    // ASSIGNMENT: Fallthrough neutral-output write when the racing path takes no early return: this+0x3580 = 0, this+0x3584 = 1.0, this+0x357C = 0. [field:this:0x00003580, field:this:0x00003584, field:this:0x0000357C]

    // Conservative worker pseudocode:
    //   if (vehicle->AIEnableFlag > 1) return;
    //   vehicle->lastAITime = globalTime;
    //   if (preRaceByte_45F4 == 0 && baseObject->AIEnable == 1) {
    //     // pre-race / formation init
    //     vehicle->counter_4028 = 0; vehicle->throttle = 0;
    //     if (sessionPhase != vehicle->phase_444C) {
    //       vehicle->countdown_4448 -= 0.025;
    //       if (vehicle->countdown_4448 < 0) {
    //         AIRingBufferFieldInit(vehicle);
    //         if (sessionPhase == 5 || sessionPhase == 1) SessionCleanupFlagClear(vehicle);
    //         vehicle->phase_444C = sessionPhase;
    //         if (preRaceByte_45F4 == 1 && byte_5C3160 == 1) {
    //           // scan 5 pit-schedule entries at 0x4144: state 4 -> schedule 0x4170, state 5 -> seed reason 0x4068
    //         }
    //       }
    //     }
    //     if (vehicle->phase_444C == 4) {
    //       byte_5C3160 = 1; RaceStartCountdownStateUpdate(0);
    //       // launch light ramp -> throttle, brake, timers
    //     }
    //     CommitOutputs(); return;
    //   }
    //   vehicle->headingSin = -sin(vehicle->yaw); vehicle->headingCos = -cos(vehicle->yaw);
    //   if (!sub_426430(vehicle) || baseObject->AIEnable != 1) return;
    //   // timed lap push, pit-wait scan, AIAbility, pit-entry transition, racing dispatch, driverStatus switch, pit-return decision
    //   CommitOutputs();
    // UNRESOLVED: The read-only float globals flt_59E43C..flt_59E87C and unk_7CE2F0 have no visible use in the decompiled body; they may be consumed indirectly by called subroutines or belong to decompiler-omitted table setup.
    // UNRESOLVED: The indexed array write at this + 4*(this+0x4148) + 0x3D70 lands inside the car-conditions buffer (carConditions starts at this+0x3D6C); exact element meaning is unresolved.
    // UNRESOLVED: The v39/v40 out-buffers passed to ArrayOfStructIndexedFieldCopy feed the driverStatus==3 waypoint-distance check; the exact indexed-array layout (base dword_5EA2C0, index obj+0x48A4) is DERIVED from the switch body.
    // UNRESOLVED: Semantic names for the many unnamed RW fields (0x4560/0x4564/0x4568 countdown light timers, 0x442C/0x4438 brake/engine-output pair, 0x4560/0x4564 timer pair) were not in the packet and are left as offsets.
}
