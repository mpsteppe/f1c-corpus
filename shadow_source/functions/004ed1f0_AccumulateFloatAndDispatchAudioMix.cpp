// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED1F0
// Canonical corpus name: ForceApplicationRouter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ForceApplicationRouter_004ed1f0.c

void UnknownObject::AccumulateFloatAndDispatchAudioMix()
{
    // Frame-path float parameter forwarder (__thiscall), structural twin of the FloatParameterForwarder cluster representative: feeds the incoming float a2 into AccumulatorClamp against this, then, when the mode flag at this+0x32BC is zero, dispatches into RandomWeightedAudioMix along with the shared race-time double global. Called from the collision spark particle effects path.
    // CALL: Accumulate and clamp the float input: AccumulatorClamp(this, a2). [callee:0x004ED0F0, source:raw]
    // GUARD: Guard: read the mode flag at this+0x32BC; dispatch to RandomWeightedAudioMix only when it is zero (non-zero blocks the audio dispatch). [field:this:0x000032BC, source:raw]
    // CALL: Dispatch the random-weighted audio mix with the accumulated float value and the race-time global: RandomWeightedAudioMix(&dbl_7C7428, a2). [callee:0x0043EC00, global:0x007C7428, source:raw]
    // CALL: Called from CollisionSparkParticleEffects (0x004EC1A0) on the per-frame path. [caller:0x004EC1A0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4ED1F0(CPhysAccum* this, float v) {
    //     AccumulatorClamp(this, v);
    //     if (!this->modeFlag /* +0x32BC * /)
    //       RandomWeightedAudioMix(&g_raceTime /* 0x007C7428 * /, v);
    //   }
    // UNRESOLVED: Owner class of this is unknown; the mode flag at +0x32BC suppresses the dispatch when non-zero but its setters are unknown.
    // UNRESOLVED: The meaning of the value passed through to RandomWeightedAudioMix depends on the accumulator semantics in AccumulatorClamp (0x004ED0F0); the twin dispatch pattern with the cluster representative is structural only and does not prove shared ownership.
}
