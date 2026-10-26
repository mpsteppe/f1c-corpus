// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004ED220
// Canonical corpus name: PhysicsTimeStep
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PhysicsTimeStep_004ed220.c

void UnknownObject::PhysicsTimeStep()
{
    // Per-frame physics timing step: first clamps the accumulated time delta via AccumulatorClamp, then, unless a disable flag at this+0x32BC is set, applies the global physics damping scale dbl_7C7428 for the same delta. The this+0x32BC flag gates the damping application without affecting the accumulator clamp.
    // CALL: Clamp the accumulated time delta: AccumulatorClamp(this, a2) with a2 as the frame time delta. [callee:0x004ED0F0, source:raw]
    // GUARD: Guard on this+0x32BC (this[3247]); when the flag is nonzero the damping application is skipped. [field:this:0x000032BC, source:raw]
    // CALL: Apply the global damping scale to the delta: PhysicsDampingScaleApplication(&dbl_7C7428, a2), passing the global as the scale source. [callee:0x0043EC50, global:0x007C7428, source:raw]
    // RETURN: Return void; the function has no value result. [source:raw]

    // Conservative worker pseudocode:
    //   void PhysicsTimeStep(_DWORD *this, float dt) {
    //     AccumulatorClamp(this, dt);
    //     if (!this[3247])
    //       PhysicsDampingScaleApplication(&dbl_7C7428, dt);
    //   }
    // UNRESOLVED: Meaning and writers of the disable flag at this+0x32BC are not established; it only gates the damping step here.
    // UNRESOLVED: Content and exact role of the global dbl_7C7428 (scale source passed to PhysicsDampingScaleApplication) are unknown.
    // UNRESOLVED: Caller CollisionSparkParticleEffects invokes this per-frame; the precise owning vehicle/object type is unresolved.
}
