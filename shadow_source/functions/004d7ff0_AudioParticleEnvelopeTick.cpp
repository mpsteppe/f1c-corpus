// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004D7FF0
// Canonical corpus name: PhaseBasedAudioParticleEnvelope
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhaseBasedAudioParticleEnvelope_004d7ff0.c

void UnknownObject::AudioParticleEnvelopeTick()
{
    // Advances a phase accumulator stored in this[3] by the fixed delta dbl_8AFE98, normalizes it by subtracting the floor (via CRTFtol) scaled by 60.0, and only when the result is >= 0.2 evaluates a six-segment amplitude envelope over a 4.0-unit cycle. Each active segment calls TimerClockFormat(amplitude, segment) with an amplitude of 1.0 or a linear ramp, and a per-segment flag (1 or 0). Returns void after the first matching segment.
    // CALCULATION: Advance the phase accumulator: this[3] = dbl_8AFE98 + this[3]. [field:this:0x0000000C, global:0x008AFE98]
    // CALCULATION: Normalize the phase: v2 = this[3] - (double)CRTFtol(this[3]) * 60.0, i.e. subtract the floor of the accumulator scaled by 60.0. [callee:0x00587BDC, field:this:0x0000000C]
    // GUARD: Gate on v2 >= 0.2: below 0.2 the function produces no output and returns. [source:raw]
    // CALCULATION: Normalize the cycle phase v9 = v2 - 0.2 once the 0.2 gate is passed. [source:raw]
    // CALCULATION: Attack segment (v9 < 0.5): amplitude v5 = 1.0 - (0.5 - v9 + 0.5 - v9), i.e. 1.0 - 2*(0.5 - v9); then TimerClockFormat(v5, 1) and return. [callee:0x004D8130, source:raw]
    // CALL: Sustain segment (v9 < 1.5): TimerClockFormat(1.0, 1) and return. [callee:0x004D8130]
    // CALCULATION: Decay segment (v9 < 2.0): amplitude v7 = 2.0 - v9 + 2.0 - v9, i.e. 2*(2.0 - v9); then TimerClockFormat(v7, 1) and return. [callee:0x004D8130, source:raw]
    // CALCULATION: Release-fall segment (v9 < 2.5): amplitude v6 = 1.0 - (2.5 - v9 + 2.5 - v9), i.e. 1.0 - 2*(2.5 - v9); then TimerClockFormat(v6, 0) and return. [callee:0x004D8130, source:raw]
    // CALL: Sustain-low segment (v9 < 3.5): TimerClockFormat(1.0, 0) and return. [callee:0x004D8130]
    // CALCULATION: Final decay segment (v9 < 4.0): amplitude v7 = 4.0 - v9 + 4.0 - v9, i.e. 2*(4.0 - v9); then TimerClockFormat(v7, 0) and return. [callee:0x004D8130, source:raw]
    // CALL: This envelope tick is dispatched by VTableDispatchChain_7e00 (0x004D7E00). [caller:0x004D7E00]

    // Conservative worker pseudocode:
    //   void sub_4D7FF0(float *this) {
    //     this[3] += dbl_8AFE98;
    //     double phase = this[3] - (double)CRTFtol(this[3]) * 60.0;
    //     if (phase < 0.2) return;
    //     phase -= 0.2;
    //     if (phase < 0.5) { TimerClockFormat(1.0f - 2.0f * (0.5f - phase), 1); return; }
    //     if (phase < 1.5) { TimerClockFormat(1.0f, 1); return; }
    //     if (phase < 2.0) { TimerClockFormat(2.0f * (2.0f - phase), 1); return; }
    //     if (phase < 2.5) { TimerClockFormat(1.0f - 2.0f * (2.5f - phase), 0); return; }
    //     if (phase < 3.5) { TimerClockFormat(1.0f, 0); return; }
    //     if (phase < 4.0) { TimerClockFormat(2.0f * (4.0f - phase), 0); return; }
    //   }
    // UNRESOLVED: Object identity/class is unknown; the 'envelope' interpretation of this[3] and TimerClockFormat derives from the legacy name, not from packet evidence.
    // UNRESOLVED: Ten packet globals (flt_59E43C, flt_59E450, flt_59E46C, flt_59E7E8, flt_59E800, flt_59E8A4, flt_59E8E4, flt_59E9C0, flt_59F118, flt_5ACCE8) are absent from the raw source text; their association with this function is suspect.
    // UNRESOLVED: Meaning of the second TimerClockFormat argument (1/0) and the 60.0 wrap divisor are unknown.
}
