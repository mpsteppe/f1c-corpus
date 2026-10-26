// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1730
// Canonical corpus name: sub_4D1730
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1730_004d1730.c

void UnknownObject::PitProximityDetectionAndNotification()
{
    // Per-frame pit proximity pass over the active vehicle grid. First resets each entry of the current pit-state array (this+0x110, 8 bytes per entry, count this+0x10C) to state 0 via ShortComputation_0f00. Then iterates dword_5C329C vehicles from the dword_7C54F0 active-array, skipping vehicles in state 2, and computes an approach threshold from the vehicle's pit/session data at +15016 and the fields this+0xD4 and this+0xB0, with a session-specific clamp when dword_7C56A4 == 7 and dword_7C56A8 == 5. When the vehicle's direction dot velocity (fields +164/+168/+172 by +13560/+13564/+13568) is below the threshold, the vehicle is mapped through DistanceProjectionCalc and CRTFtol into an array index this+0x10C range and its pit-state entry is written to state 2. Then a state-change pass compares this+0x110 against the previous-state array this+0x114 and raises PitSelectionStateMachine(dword_5EB978) on any transition. Finally, if anything changed or more than 5.0 elapsed since the last log, a ProgressBarEventEncode(...,4,10,...) heartbeat plus per-vehicle packed progress events are appended to the ring buffer anchored by dword_8AAE64/dword_83EE60 and the this+0x118 timestamp is refreshed. Called by sub_4D1D80 (004D1D80).
    // LOOP: Reset pass: for each of this+0x10C entries, ShortComputation_0f00(this+0x110 + 8*i, 0) clears the per-vehicle pit-state entry [field:this:0x0000010C, field:this:0x00000110, callee:0x004D0F00, source:raw]
    // LOOP: Vehicle pass: iterate j over dword_5C329C vehicles taken from the dword_7C54F0 active-vehicle array [global:0x005C329C, global:0x007C54F0, source:raw]
    // GUARD: Skip vehicles whose state at +16484 equals 2; keep the current vehicle otherwise [source:raw]
    // ASSIGNMENT: v6 = the vehicle's pit/session data pointer at vehicle+15016 [source:raw]
    // CALCULATION: Approach threshold v7: when *(v6+300) is set, v7 is -1.0 if vehicle+13388 is set, else this+0xD4 * 0.5; otherwise v7 is *(v6+140) - 60.0 floored at *(v6+140) * 0.22499999 [field:this:0x000000D4, source:raw]
    // GUARD: Session clamp: if dword_7C56A4 == 7 and dword_7C56A8 == 5 and dbl_8AFEA0 < this+0xB0 + 20.0, clamp v7 down to (dbl_8AFEA0 - this+0xB0) * 6.0 - 10.0 [global:0x007C56A4, global:0x007C56A8, global:0x008AFEA0, field:this:0x000000B0, source:raw]
    // CALCULATION: When the dot product of direction (+164/+168/+172) with vehicle velocity (+13560/+13564/+13568) is below v7, compute v8 = DistanceProjectionCalc(vehicle+12), then v9 = CRTFtol(v8 * this+0x108) - 1 clamped into 0..this+0x10C-1, and write pit-state 2 into this+0x110 + 8*v9 via ShortComputation_0f00 [callee:0x004F0050, callee:0x00587BDC, field:this:0x00000108, field:this:0x0000010C, field:this:0x00000110, callee:0x004D0F00, source:raw]
    // GUARD: The state-change pass only runs when the entry count this+0x10C is greater than 0 (packet guard) [guard:0, field:this:0x0000010C, source:raw]
    // LOOP: State-diff loop: for each index up to this+0x10C, compare the new id from this+0x110 + 8*k against the previous id in this+0x114 + 4*k; on a difference raise PitSelectionStateMachine(dword_5EB978, curId, prevId, entryTime, 0, 0), copy the new id back into this+0x114, and set the changed flag [field:this:0x00000110, field:this:0x00000114, field:this:0x0000010C, callee:0x0041B3C0, global:0x005EB978, source:raw]
    // GUARD: Ring-buffer flush gate: run the logging block when the changed flag is set or dbl_8AFEA0 - this+0x118 is greater than 5.0 [global:0x008AFEA0, field:this:0x00000118, source:raw]
    // ASSIGNMENT: Refresh the this+0x118 timestamp to dbl_8AFEA0 and advance the ring buffer: increment dword_83EE60 (capped at 1023) and advance the dword_8AAE64 cursor by 432 bytes [field:this:0x00000118, global:0x008AFEA0, global:0x0083EE60, global:0x008AAE64, source:raw]
    // CALL: ProgressBarEventEncode(v16, 4, 10, 0, 255, globalTime, 0) writes the heartbeat progress event for the pass [callee:0x004B33B0, global:0x008AFEA0, source:raw]
    // LOOP: Per-vehicle packing loop: for each of this+0x10C entries with a non-zero id, pack id + (k << 6) into the event word slot; every 16 packed entries advance the ring buffer and emit ProgressBarEventEncode(...,4,11,...), resetting the pack counter [field:this:0x0000010C, field:this:0x00000110, callee:0x004B33B0, global:0x008AAE64, global:0x0083EE60, source:raw]
    // CALL: Invoked by sub_4D1D80 (004D1D80) as the pit proximity detection stage [caller:0x004D1D80, source:raw]

    // Conservative worker pseudocode:
    //   count = this[0x10C];
    //   for (i = 0; i < count; ++i)
    //     ShortComputation_0f00(this[0x110] + 8*i, 0);
    //   for (j = 0; j < dword_5C329C; ++j) {
    //     veh = dword_7C54F0[j];
    //     if (veh[16484] == 2) continue;
    //     data = veh[15016];
    //     if (data[300])
    //       threshold = veh[13388] ? -1.0 : this[0xD4] * 0.5;
    //     else
    //       threshold = max(data[140] - 60.0, data[140] * 0.22499999);
    //     if (dword_7C56A4 == 7 && dword_7C56A8 == 5 && dbl_8AFEA0 < this[0xB0] + 20.0)
    //       threshold = min(threshold, (dbl_8AFEA0 - this[0xB0]) * 6.0 - 10.0);
    //     if (dot(data+164/168/172, veh+13560/13564/13568) < threshold) {
    //       proj = DistanceProjectionCalc(veh + 12);
    //       idx = CRTFtol(proj * this[0x108]) - 1;
    //       if (idx < 0) idx += count;
    //       idx = clamp(idx, 0, count - 1);
    //       ShortComputation_0f00(this[0x110] + 8*idx, 2);
    //     }
    //   }
    //   changed = false;
    //   if (count > 0) {
    //     for (k = 0; k < count; ++k) {
    //       cur = *(this[0x110] + 8*k); prev = *(this[0x114] + 4*k);
    //       if (prev != cur) {
    //         PitSelectionStateMachine(dword_5EB978, cur, prev, *(this[0x110]+8*k+4), 0, 0);
    //         *(this[0x114] + 4*k) = cur;
    //         changed = true;
    //       }
    //     }
    //   }
    //   if (changed || dbl_8AFEA0 - this[0x118] > 5.0) {
    //     this[0x118] = dbl_8AFEA0;
    //     bump ring buffer (dword_83EE60 < 1023);
    //     ProgressBarEventEncode(cursor, 4, 10, 0, 255, dbl_8AFEA0, 0);
    //     pack = 0;
    //     for (k = 0; k < count; ++k) {
    //       id = *(this[0x110] + 8*k);
    //       if (id) {
    //         if (pack >= 16) {
    //           bump ring buffer;
    //           ProgressBarEventEncode(cursor, 4, 11, 0, 255, dbl_8AFEA0, 0);
    //           pack = 0;
    //         }
    //         cursor_word[pack++ + 4] = id + (k << 6);
    //         pack cursor dword = (pack << 9) | header;
    //       }
    //     }
    //   }
    // UNRESOLVED: Eight read-only globals (flt_59E450, flt_59E5FC, flt_59E670, flt_59E7EC, flt_59E8EC, flt_59E940, flt_59F118, flt_5ACEE8) are flagged by the packet facts but appear nowhere in the raw decompiled source; the existing analysis assigns them speculative physics/format constants that are unverifiable from this packet
    // UNRESOLVED: The vehicle-relative offsets +16484, +15016, +13388, +13560/+13564/+13568 and +12 are outside this object's field table; their vehicle-struct meanings come only from the raw source text
    // UNRESOLVED: The ring-buffer entry layout (432-byte stride, the 1023 cap, and the word/dword packing in ProgressBarEventEncode) is not defined by this packet
}
