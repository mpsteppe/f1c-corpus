// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00519720
// Canonical corpus name: AudioStreamBufferFill
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AudioStreamBufferFill_00519720.c

void UnknownObject::AudioStreamBufferFill()
{
    // Streaming buffer filler driven by a three-state machine stored at *(this+0x180)+0x44 (flattened this+0x1C4): state 0 schedules a new write window, state 1 performs the write dispatch, state 2 flushes. On first use the descriptor init flag *(this+0x1B0) is clear, so an indirect setup call through this+0x184+12 primes the channel and increments the write-cycle counter *(this+0x1CC). Writes dispatch through an indirect call at this+0x188+4 into the current channel data pointer with the fill position and target sizes. When a write window completes, the channel buffer index *(this+0x1C0) is toggled with XOR 1, PerIndexBufferCopyWithInterleavedOffset runs when the cycle counter equals 1, and the state advances to flush. ArrayProcessingWithScaling runs when the cycle counter reaches the limit this+0x118.
    // GUARD: First-use guard: when the descriptor init flag *(this+0x180)+0x30 (flattened this+0x1B0) is zero, the one-time channel setup path runs [field:this:0x000001B0, field:this:0x00000180, source:raw]
    // CALL: One-time setup: indirect call through this+0x184+12 (a1[97]+12) passing the current channel data pointer *(*(this+0x180) + 4*index + 0x38); a zero return aborts the function immediately [field:this:0x00000184, field:this:0x00000180, source:raw]
    // ASSIGNMENT: On successful setup, increments the write-cycle counter *(this+0x180)+0x4C (flattened this+0x1CC) and sets the init flag *(this+0x1B0) to 1 [field:this:0x000001CC, field:this:0x000001B0, field:this:0x00000180, source:raw]
    // GUARD: State dispatch on the descriptor state word this+0x1C4: 0 = schedule/init, 1 = write, 2 = flush; a state above 2 returns the running state value unchanged [field:this:0x000001C4, source:raw]
    // ASSIGNMENT: State 0 (schedule) prepares the next write: fill position *(this+0x1B4) set to 0, write target *(this+0x1C8) set to this+0x114 minus 1, and state *(this+0x1C4) set to 1 [field:this:0x000001B4, field:this:0x000001C8, field:this:0x00000114, field:this:0x000001C4, source:raw]
    // CALL: When the write-cycle counter *(this+0x1CC) equals the cycle limit this+0x118, ArrayProcessingWithScaling is invoked on the stream object [callee:0x00519622, field:this:0x000001CC, field:this:0x00000118, source:raw]
    // CALL: Write/flush dispatch: indirect call through this+0x188+4 (a1[98]+4) with (a1, current channel data pointer, &fill position *(this+0x180)+0x34, write target *(this+0x1C8), a2, a3, a4) [field:this:0x00000188, field:this:0x00000180, field:this:0x000001B4, field:this:0x000001C8, source:raw]
    // CALCULATION: After dispatch, compares the updated fill position *(this+0x1B4) against the write target *(this+0x1C8); the write is still in progress while the fill position is below the target [field:this:0x000001B4, field:this:0x000001C8, source:raw]
    // STATE_TRANSITION: State 2 (flush): if the fill position *(this+0x1B4) reaches the write target *(this+0x1C8), the state *(this+0x1C4) returns to 0 and, when the output counter *a3 is still below a4, the schedule path runs again [field:this:0x000001B4, field:this:0x000001C8, field:this:0x000001C4, source:raw]
    // GUARD: On completed writes, when the write-cycle counter *(this+0x1CC) equals 1 PerIndexBufferCopyWithInterleavedOffset is invoked (packet guard) [guard:0, field:this:0x000001CC, source:raw]
    // CALL: PerIndexBufferCopyWithInterleavedOffset invoked on the stream object for the single-cycle case [callee:0x0051954E, source:raw]
    // ASSIGNMENT: Completes the write cycle: toggles the channel buffer index *(this+0x1C0) with XOR 1, clears the init flag *(this+0x1B0), sets fill position *(this+0x1B4) to this+0x114+1, write target *(this+0x1C8) to this+0x114+2, and advances the state *(this+0x1C4) to 2 [field:this:0x000001C0, field:this:0x000001B0, field:this:0x000001B4, field:this:0x000001C8, field:this:0x00000114, field:this:0x000001C4, source:raw]
    // RETURN: Returns the partial fill result while a write is incomplete, a4 when the flush saturates the output, or 2 after a completed cycle [source:raw]

    // Conservative worker pseudocode:
    //   desc = *(this + 0x180);
    //   if (!*(desc + 0x30)) {
    //     result = (*(*(this+0x184) + 12))(this, *(desc + 4*(*(desc+0x40)) + 0x38));
    //     if (!result) return result;
    //     ++*(desc + 0x4C); *(desc + 0x30) = 1;
    //   }
    //   state = *(desc + 0x44);
    //   if (state == 0) {
    //     *(desc+0x34) = 0; *(desc+0x48) = *(this+0x114) - 1;
    //     if (*(desc+0x4C) == *(this+0x118)) ArrayProcessingWithScaling(this);
    //     *(desc+0x44) = 1;
    //   } else if (state == 2) {
    //     write_dispatch();
    //     if (*(desc+0x34) < *(desc+0x48)) return *(desc+0x34);
    //     *(desc+0x44) = 0;
    //     if (*a3 >= a4) return a4;
    //     goto schedule;
    //   } else if (state > 2) {
    //     return state;
    //   }
    //   write_dispatch();
    //   if (*(desc+0x34) >= *(desc+0x48)) {
    //     if (*(desc+0x4C) == 1) PerIndexBufferCopyWithInterleavedOffset(this);
    //     *(desc+0x40) ^= 1; *(desc+0x30) = 0;
    //     *(desc+0x34) = *(this+0x114) + 1;
    //     *(desc+0x48) = *(this+0x114) + 2;
    //     *(desc+0x44) = 2;
    //     return 2;
    //   }
    //   return *(desc+0x34);
    // UNRESOLVED: Packet flags read-only fields this+0x18C and this+0x190 (a1[99], a1[100]) that never appear in the raw decompiled source
    // UNRESOLVED: The two indirect call targets (this+0x184+12 and this+0x188+4) are reached through fields but no resolved callee addresses are given in the packet
    // UNRESOLVED: The buffer-descriptor fields at *(this+0x180)+0x30/+0x34/+0x40/+0x44/+0x48/+0x4C are recorded as flattened this-relative offsets (this+0x1B0..+0x1CC); the flattening is a packet convention and no independent layout evidence exists
}
