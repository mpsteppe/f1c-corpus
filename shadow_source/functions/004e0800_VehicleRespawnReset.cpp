// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E0800
// Canonical corpus name: VehicleRespawnReset
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VehicleRespawnReset_004e0800.c

void UnknownObject::VehicleRespawnReset()
{
    // Vehicle respawn / race-restart state reset. Clears the respawn marker byte, invokes an auxiliary reset (sub_5506A0) when a prior-collision flag is set, computes a random respawn delay from a rotating noise table, reinitializes vehicle substructures (MultiSystemStructInitializer, optional StateArrayReset), writes a progress-bar event when the base object is not in an active race, resets audio/sound state and scale propagation, zeroes collision force and torque accumulators, writes sentinel ID values, computes a speed scale, and dispatches per-contact-zone resets via ConditionalDispatchByFlag.
    // ASSIGNMENT: Clear respawn marker byte this+0x974 = 0. [field:this:0x00000974, source:raw]
    // GUARD: If this+0x8A4 (prior-collision flag) is nonzero, call sub_5506A0(0, 0, 0). [field:this:0x000008A4, callee:0x005506A0]
    // CALCULATION: Random respawn delay: this+0x94C = flt_8AAE74[(byte)dword_8AAE70++] * 0.14 + 0.0099999998. [global:0x008AAE74, global:0x008AAE70, field:this:0x0000094C]
    // CALL: MultiSystemStructInitializer(this) reinitializes the vehicle's substructure system. [callee:0x004E0DB0]
    // GUARD: If flag a2 is set call StateArrayReset(this); otherwise, when the base object's counter (obj+0x32C8) <= 1, take the progress-bar event path. [callee:0x004E3890, field:this:0x00000000, field:obj:0x000032C8, guard:0]
    // CALL: Progress-bar event: if dword_83EE60 < 1023 then increment dword_83EE60 and dword_8AAE64 += 432; ProgressBarEventEncode(dword_8AAE64, 2, 8, 4, *(base+18580)=obj+0x4894, dbl_8AFEA0 as float, 0). [global:0x0083EE60, global:0x008AAE64, callee:0x004B33B0, global:0x008AFEA0, field:obj:0x00004894]
    // CALL: Capture audio handle v15 = this+0x964, set respawn flags this+0x96C = 1 and this+0x96D = 1, call AudioSoundEffectController(v15), then clear this+0x979 = 0. [field:this:0x00000964, field:this:0x0000096C, field:this:0x0000096D, field:this:0x00000979, callee:0x004E0ED0]
    // CALL: ScalePropagate(1.0) propagates a uniform 1.0 scale through the vehicle hierarchy. [callee:0x004E2CA0]
    // ASSIGNMENT: Zero collision force/torque accumulators: this+0x934, this+0x938, this+0x93C, this+0x940, this+0x944, this+0x948 = 0. [field:this:0x00000934, field:this:0x00000938, field:this:0x0000093C, field:this:0x00000940, field:this:0x00000944, field:this:0x00000948]
    // ASSIGNMENT: Write sentinel IDs: this+0x980 = -1 and this+0x984 = -8388609. [field:this:0x00000980, field:this:0x00000984]
    // CALCULATION: Compute scale factor: if flt_7CF740 >= 1.0 use flt_7CF740 else 1.0; store this+0x988 = 32.0 / scale. [global:0x007CF740, field:this:0x00000988]
    // LOOP: If this+0x898 is set and count this+0x8B4 > 0, loop over the contact zones: ConditionalDispatchByFlag(handle from this+0x8B8, params from this+0x8C4, 1.0). [field:this:0x00000898, field:this:0x000008B4, guard:1, field:this:0x000008B8, field:this:0x000008C4, callee:0x00551810]
    // GUARD: If pending-cleanup byte this+0x98C is set: clear it and zero 17 entries (stride 28 bytes) starting at this+0x990. [field:this:0x0000098C, field:this:0x00000990]

    // Conservative worker pseudocode:
    //   this[0x974] = 0;
    //   if (this[0x8A4]) sub_5506A0(0, 0, 0);
    //   this[0x94C] = flt_8AAE74[(byte)dword_8AAE70++] * 0.14 + 0.0099999998;
    //   MultiSystemStructInitializer(this);
    //   if (a2) StateArrayReset(this);
    //   else if (baseObj[0x32C8] <= 1) {
    //     if (dword_83EE60 < 1023) { ++dword_83EE60; dword_8AAE64 += 432; }
    //     ProgressBarEventEncode(dword_8AAE64, 2, 8, 4, baseObj[0x4894], (float)dbl_8AFEA0, 0);
    //   }
    //   AudioSoundEffectController(this[0x964]); this[0x96C] = 1; this[0x96D] = 1; this[0x979] = 0;
    //   ScalePropagate(1.0);
    //   this[0x934..0x948] = 0; this[0x980] = -1; this[0x984] = -8388609;
    //   this[0x988] = 32.0 / max(flt_7CF740, 1.0);
    //   if (this[0x898] && this[0x8B4] > 0) for each zone: ConditionalDispatchByFlag(zone, params, 1.0);
    //   if (this[0x98C]) { this[0x98C] = 0; for (i = 0; i < 17; i++) *(byte*)(this + 0x990 + 28*i) = 0; }
    // UNRESOLVED: The read-only float globals flt_59E43C, flt_59E444, flt_59EC20, flt_5AD150 have no visible use in the decompiled body; they may be consumed indirectly by called subroutines.
    // UNRESOLVED: The exact meaning of the sentinel writes this+0x980 = -1 and this+0x984 = -8388609 and of the strided 17-entry zeroing at this+0x990 is not given by the packet; left as offsets.
    // UNRESOLVED: The substructure pointer this+0x964 passed to AudioSoundEffectController is treated as an opaque handle.
}
