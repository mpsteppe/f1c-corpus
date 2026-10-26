// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D1D80
// Canonical corpus name: sub_4D1D80
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4D1D80_004d1d80.c

void UnknownObject::ScoringPositionUpdate()
{
    // Periodic scoring/standing update gated by a countdown timer. Every expiry it iterates the active driver grid computing per-vehicle position-change gaps, runs a proximity/range check against the monitor, records enter/leave events into a progress-bar ring buffer, sorts drivers by standing, syncs the sorted order array, encodes order-change events, and calls pit-proximity detection sub_4D1730.
    // CALCULATION: Decrement the timer at offset 0x120 by dbl_8AFE98; when the result is at most 0.0, reset it to 1048576000 (0.25f) and run the update pass [field:this:0x00000120, global:0x008AFE98, source:raw]
    // LOOP: For each driver i in [0, dword_5C329C), fetch the vehicle from dword_7C54F0[i] and call PositionChangeMonitor(vehicle + 12) [global:0x005C329C, global:0x007C54F0, callee:0x004E9630, source:raw]
    // GUARD: Branch on the vehicle's activity state (dword at vehicle+16448) combined with the monitor state at monitor+68: either set the gap field to flt_5EA3FC, zero it, or compute a real delta [global:0x005EA3FC, source:raw]
    // CALCULATION: Compute the position delta between two track-position pointers (monitor+268 and monitor+272), normalize by 1/sqrt(distance-squared) when non-zero, and project the result into the vehicle gap field at +16452 [source:raw]
    // CALCULATION: Proximity gate: compare the gap against the threshold at offset 0x100 minus the vehicle track length (sqrt of three squared position terms times 5.0), setting v4 when any driver falls inside the window [field:this:0x00000100, source:raw]
    // STATE_TRANSITION: When the proximity hit flag differs from the byte at offset 0x104, advance the ring buffer at dword_8AAE64 (bounded by dword_83EE60 below 1023, stride 432) and encode a ProgressBarEventEncode event with the dbl_8AFEA0 timestamp: type 33 when entering proximity, type 34 when leaving [field:this:0x00000104, global:0x008AAE64, global:0x0083EE60, global:0x008AFEA0, callee:0x004B33B0, source:raw]
    // LOOP: Build the standing-order byte array v38 by reading byte vehicle+18580 for each entry of dword_7C54F0 [global:0x007C54F0, source:raw]
    // GUARD: Sort the order array with sub_5890AA: use DriverSortComparator when dword_7C56A4 equals 7, otherwise DriverStandingComparator [global:0x007C56A4, global:0x004D0CF0, global:0x004D0C20, callee:0x005890AA, source:raw]
    // LOOP: Sync the sorted order bytes into the per-driver order array at offset 0x128 (byte per index) and flag any change [field:this:0x00000128, source:raw]
    // STATE_TRANSITION: If the order changed, reset the update counter at offset 0x124 to 0 and encode a type-7 order-change event (ring head at dword_8AAE64 with dbl_8AFEA0 timestamp and count dword_5C329C + 12); otherwise increment the counter byte [field:this:0x00000124, global:0x008AAE64, global:0x0083EE60, global:0x008AFEA0, global:0x005C329C, callee:0x004B33B0, source:raw]
    // CALCULATION: Fill the order-change event payload: when there are no drivers write the negative float bit pattern -1082130432 into three ring floats, otherwise write three values looked up from flt_5F0780 indexed by the order byte times 4656 [global:0x005C329C, global:0x005F0780, source:raw]
    // LOOP: Copy the per-driver order bytes from offset 0x128 into the ring event payload starting at byte offset 20 [field:this:0x00000128, global:0x005C329C, source:raw]
    // CALL: Call sub_4D1730(this) for pit-proximity detection at the end of the update pass [callee:0x004D1730, source:raw]

    // Conservative worker pseudocode:
    //   timer (this+0x120) -= dbl_8AFE98;
    //   if (timer > 0.0) return;
    //   timer (this+0x120) = 1048576000;  // 0.25f
    //   for (i = 0; i < dword_5C329C; ++i) {
    //     monitor = PositionChangeMonitor(dword_7C54F0[i] + 12);
    //     vehicle = dword_7C54F0[i];
    //     if (activity state selects) gap (vehicle+16452) = flt_5EA3FC;
    //     else if (state selects) gap = 0;
    //     else gap = normalize(position_now - position_prev) projected;
    //     if (!monitorFlag(monitor+300)) {
    //       v35 = threshold (this+0x100) - trackLength * 5.0;
    //       if (gap inside [v35, threshold]) proximity_hit = 1;
    //     }
    //   }
    //   if (proximity_hit != byte (this+0x104)) {
    //     ring = dword_8AAE64; if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //     ProgressBarEventEncode(ring, 4, proximity_hit ? 33 : 34, 0, 255, dbl_8AFEA0, 0);
    //   }
    //   for (j = 0; j < dword_5C329C; ++j) order[j] = byte (dword_7C54F0[j] + 18580);
    //   sub_5890AA(order, n, 1, dword_7C56A4 == 7 ? DriverSortComparator : DriverStandingComparator);
    //   changed = any(order[i] != byte (this + 0x128 + i)); copy order into this + 0x128;
    //   if (changed) { counter (this+0x124) = 0; encode order-change event; fill payload; }
    //   else ++counter (this+0x124);
    //   sub_4D1730(this);
    // UNRESOLVED: Three read-only float globals (flt_59E43C, flt_59E440, flt_59E7EC) are flagged by packet facts but do not appear in the raw decompiled source; their role is not verifiable here
    // UNRESOLVED: Class ownership is unknown; the this object holds a standing/proximity state (thresholds, timer, counter, order array)
    // UNRESOLVED: The monitor struct fields referenced through PositionChangeMonitor (offsets at monitor+4, +8, +68, +72, +268, +272, +300) are not part of this packet's field list and are described only via the raw source
}
