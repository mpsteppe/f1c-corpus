// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B7A90
// Canonical corpus name: PitTimingUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PitTimingUpdate_004b7a90.c

void UnknownObject::PitTimingUpdate()
{
    // Main pit-timing tick: accumulates the elapsed frame time into per-vehicle pit timers, triggers pit-stall proximity checks (and car-lighting refresh) when a timer passes its threshold, dispatches a round-robin slice of 12 vehicle slots per frame to sub_4B6190, processes queued session-data messages through a ring buffer with a type-switch, and fires a pit-stop action when the recorded pit time has elapsed. The whole update is gated by a disable byte at this+0xF78.
    // GUARD: If the byte at this+0xF78 (offset 3960) is non-zero the entire pit-timing update is skipped. [field:this:0x00000F78, source:raw]
    // CALL: When the count argument a3 is non-zero, VehicleInstanceListBuilder rebuilds the vehicle instance list from this. [callee:0x004B5C50, source:raw]
    // CALL: PerformanceCounterDiffWithScaling reads the elapsed time from the timer embedded in this at offset 3372 into v14. [callee:0x00568D90, source:raw]
    // GUARD: Time gate: the update proceeds only when the elapsed time exceeds 0.025 seconds and the input a4 differs from the previous value stored at this+0xD78 (offset 3448) by more than 0.001. [field:this:0x00000D78, source:raw]
    // CALL: TimerResetUsingQueryPerformanceCounter resets the embedded timer in this at offset 3372 once the time gate passes. [callee:0x00568C60, source:raw]
    // LOOP: Over the first dword_5C329C (0x005C329C) vehicles, accumulate the elapsed time v14 into each per-vehicle timer at this+0xD7C (offset 3452); a timer is reset to 0.0 and the proximity path runs when it exceeds the threshold at this+0xF7C (offset 3964). [field:this:0x00000D7C, field:this:0x00000F7C, global:0x005C329C, source:raw]
    // CALL: On a timer threshold exceed, SetupCarLightingAndRender and PitStallProximityCheck are invoked for the affected vehicle. [callee:0x004C71C0, callee:0x004B5DA0, source:raw]
    // LOOP: Round-robin vehicle maintenance: from the step counter at this+0xD28 (offset 3368), call sub_4B6190 for every 12th slot below 104, then advance the counter (this+0xD28) by 1 modulo 12. [field:this:0x00000D28, callee:0x004B6190, source:raw]
    // ASSIGNMENT: Store the current input a4 into this+0xD78 (offset 3448) as the previous value for the next frame's delta check. [field:this:0x00000D78, source:raw]
    // CALL: Session-message processing: when the count in a2 is positive, SessionDataCopy snapshots the session data, then AdvanceRingBuffer is called repeatedly to pull messages into the local v15 buffer. [callee:0x004B3B30, callee:0x004B3AF0, source:raw]
    // GUARD: Message type dispatch: switch on (v15[0] >> 29) via the jump table at 0x004B7C60 (jpt_4B7BDF); types 2, 3, 4 and 6 always run PitStallProximityCheck, type 1 only when the sub-field ((v15[0] >> 18) & 0x3F) is non-zero and not 7. [global:0x004B7C60, callee:0x004B5DA0, source:raw]
    // CALL: Pit-stop action trigger: compute v12 from the pit-stall fields at this+0x9B0 (offset 2480) and this+0x9B8 (offset 2488) as base + 176 * index; when v12 is non-null and the pit time (threshold at this+0xF7C plus the +108 pit-target time) is not beyond a4, PitstopActionSet fires. [field:this:0x000009B0, field:this:0x000009B8, field:this:0x00000F7C, callee:0x004B6940, source:raw]
    // RETURN: The function always returns 0. [source:raw]

    // Conservative worker pseudocode:
    //   if (this[0xF78] != 0) return 0;
    //   if (a3) VehicleInstanceListBuilder(this, a3);
    //   v14 = PerformanceCounterDiffWithScaling(this + 3372);
    //   if (v14 > 0.025 && fabs(a4 - this[0xD78]) > 0.001) {
    //     TimerResetUsingQueryPerformanceCounter(this + 3372);
    //     for (v7 = 0; v7 < VehicleCount; v7++) {
    //       this[0xD7C][v7] += v14;
    //       if (this[0xD7C][v7] > this[0xF7C]) {
    //         this[0xD7C][v7] = 0.0;
    //         SetupCarLightingAndRender(v15);
    //         PitStallProximityCheck(this, v15, a4);
    //       }
    //     }
    //     for (i = this[0xD28]; i < 104; i += 12) sub_4B6190(this, i);
    //     this[0xD28] = (this[0xD28] + 1) % 12;
    //   }
    //   this[0xD78] = a4;
    //   if (a2[0] > 0) {
    //     SessionDataCopy(a2);
    //     while (AdvanceRingBuffer(a2, v15)) {
    //       switch (v15[0] >> 29) {
    //         case 1: if (!((v15[0] >> 18) & 0x3F) || ((v15[0] >> 18) & 0x3F) == 7) break;
    //         case 2: case 3: case 4: case 6: PitStallProximityCheck(this, v15, a4); break;
    //       }
    //     }
    //     v12 = this[0x9B0] + 176 * this[0x9B8];
    //     if (v12 && this[0xF7C] + v12[27] <= a4) PitstopActionSet(this, a4);
    //   }
    //   return 0;
    // UNRESOLVED: The globals flt_59E87C (0x0059E87C) and dbl_59EA08 (0x0059EA08) are not directly referenced in the raw function body (the time gate renders the literals 0.025 and 0.001); the existing analysis labels them TimeStepMultiplier and CollisionSkinThickness / clock-sync tolerance at DERIVED trust, which is not adopted here.
    // UNRESOLVED: dword_7C54F0 (0x007C54F0, VehiclePtrArray) is not read directly in the raw body; it is presumably consumed inside VehicleInstanceListBuilder or sub_4B6190, so no direct operation is assigned.
    // UNRESOLVED: The per-vehicle timer accumulator array at this+0xD7C is bounded by dword_5C329C (VehicleCount); the exact layout and stride semantics of the pit-stall scratch buffer v15 are only partially visible in the raw source.
}
