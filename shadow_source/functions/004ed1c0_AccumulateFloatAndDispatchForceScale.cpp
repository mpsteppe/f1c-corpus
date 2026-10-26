// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED1C0
// Canonical corpus name: FloatParameterForwarder
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatParameterForwarder_004ed1c0.c

void UnknownObject::AccumulateFloatAndDispatchForceScale()
{
    // Frame-path float parameter forwarder (__thiscall): feeds the incoming float a2 into AccumulatorClamp against this, then, when the mode flag at this+0x32BC is zero, dispatches the accumulated value into PhysicsForceScaleDispatch along with the shared race-time double global. Called from the collision spark particle effects path.
    // CALL: Accumulate and clamp the float input: AccumulatorClamp(this, a2). [callee:0x004ED0F0, source:raw]
    // GUARD: Guard: read the mode flag at this+0x32BC; dispatch to PhysicsForceScaleDispatch only when it is zero (non-zero blocks the force-scale dispatch). [field:this:0x000032BC, source:raw]
    // CALL: Dispatch the physics force-scale with the accumulated float value and the race-time global: PhysicsForceScaleDispatch(&dbl_7C7428, a2). [callee:0x0043EBD0, global:0x007C7428, source:raw]
    // CALL: Called from CollisionSparkParticleEffects (0x004EC1A0) on the per-frame path. [caller:0x004EC1A0, source:raw]

    // Conservative worker pseudocode:
    //   void sub_4ED1C0(CPhysAccum* this, float v) {
    //     AccumulatorClamp(this, v);
    //     if (!this->modeFlag /* +0x32BC * /)
    //       PhysicsForceScaleDispatch(&g_raceTime /* 0x007C7428 * /, v);
    //   }
    // UNRESOLVED: Owner class of this is unknown; the mode flag at +0x32BC suppresses the dispatch when non-zero but its setters are unknown.
    // UNRESOLVED: The meaning of the value passed through to PhysicsForceScaleDispatch depends on the accumulator semantics in AccumulatorClamp (0x004ED0F0).
}
