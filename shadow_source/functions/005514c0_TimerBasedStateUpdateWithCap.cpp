// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005514C0
// Canonical corpus name: TimerBasedStateUpdateWithCap
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TimerBasedStateUpdateWithCap_005514c0.c

void UnknownObject::TimerBasedStateUpdateWithCap()
{
    // Advances a timed entity state guarded by a state pointer at this+0x1C. When the flags word at this+0x4 has the 0x1000 audio-reset bit set, clears that bit, sets the 0x8000 timer-active bit, zeroes the accumulator at this+0x8 and resets the high-resolution timer. When the flags byte1 0x80 timer-query bit is set, queries the elapsed time from the QPC handle at this+0x0, stores it at this+0x10, and caps it at the maximum duration read from the cap structure (*(this+0x1C)+8). On reaching the cap, dispatches through FlagUpdateWithCascade (flags bit 0x20000) or EntityFlagSetSubInitChain plus AudioFlagSet, then applies the elapsed time to entity state via sub_551210.
    // GUARD: Outer guard: the state is only advanced when this[7] (offset 0x1C) is non-zero (the cap structure pointer must be present); otherwise the function does nothing. [field:this:0x0000001C, source:raw]
    // GUARD: Audio-reset path: when the flags word this[1] (offset 0x4) has the 0x1000 bit set, rebuild the flags as (v3 & 0xFFFF6FFF) | 0x8000 — clearing 0x1000 and setting the 0x8000 timer-active bit — write the result back to this+0x4, zero the accumulator this[2] (offset 0x8), and reset the high-resolution timer with the QPC handle *this. [callee:0x00556440, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Flags update: new flags value (v3 & 0xFFFF6FFF) | 0x8000 is stored to this[1] (offset 0x4), preserving all bits except 0x1000 while asserting 0x8000. [field:this:0x00000004, source:raw]
    // GUARD: Timer-query path: when the byte1 0x80 bit of the flags word is set, query elapsed time v5 = HighPrecisionTimerCounterArithmetic(*(_DWORD *)this) using the QPC handle and store it into this[4] (offset 0x10). [callee:0x005565B0, field:this:0x00000000, field:this:0x00000010, source:raw]
    // CALCULATION: Cap enforcement: read the maximum duration at *(float *)(v6 + 8) where v6 = this[7] (offset 0x1C) — the cap field *(this+0x1C)+8; when v5 reaches it, clamp this[4] (offset 0x10) to that maximum. [field:*(this+0x1C):0x00000008, field:this:0x00000010, field:this:0x0000001C, source:raw]
    // GUARD: Cap dispatch: when the cap is reached and the flags word (this+0x4) has the 0x20000 bit set, take the cascade path — FlagUpdateWithCascade(this), then sub_551210(this, a2, elapsed) and return. [callee:0x005514A0, callee:0x00551210, field:this:0x00000004, source:raw]
    // STATE_TRANSITION: Cap dispatch, non-cascade path: when the cap is reached without the 0x20000 bit, call EntityFlagSetSubInitChain(this) to start the sub-init chain and AudioFlagSet(this) to set the audio timer flag, then apply sub_551210(this, a2, elapsed). [callee:0x00551440, callee:0x00551480, callee:0x00551210, source:raw]
    // CALL: Common application: sub_551210(this, a2, this[4]) applies the current (possibly capped) elapsed time from this+0x10 to the entity state; it runs on the running path as well as both cap-reached branches. [callee:0x00551210, field:this:0x00000010, source:raw]

    // Conservative worker pseudocode:
    //   if (!this[7]) return;
    //   flags = this[1];
    //   if (flags & 0x1000) { this[1] = (flags & 0xFFFF6FFF) | 0x8000; this[2] = 0.0; HighResolutionTimerReset(*this); }
    //   if ((BYTE1(this[1]) & 0x80) != 0) {
    //     this[4] = HighPrecisionTimerCounterArithmetic(*this);
    //     cap = *(float *)(this[7] + 8);
    //     if (this[4] >= cap) {
    //       this[4] = cap;
    //       if (this[1] & 0x20000) { FlagUpdateWithCascade(this); sub_551210(this, a2, this[4]); return; }
    //       EntityFlagSetSubInitChain(this);
    //       AudioFlagSet(this);
    //     }
    //     sub_551210(this, a2, this[4]);
    //   }
    // UNRESOLVED: The exact meaning of each flags bit (0x1000 audio reset, 0x8000 timer active, 0x20000 cascade mode) is DERIVED from the fill's field annotations, not independently evidenced.
    // UNRESOLVED: The elapsed value this+0x10 is recomputed from the QPC every call and capped, so an external poke is overwritten; the fill records this as non-persistent.
    // UNRESOLVED: The cap structure behind this+0x1C is only evidenced through its +8 field; its full layout is unknown.
}
