// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9D00
// Canonical corpus name: FloatAccumulator
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/FloatAccumulator_004b9d00.c

void UnknownObject::FloatAccumulator()
{
    // Reads a float value through the pointer stored at this+0x0 via FloatGetter (004B8790), adds the incoming float parameter a2, and forwards the sum to SingleCallWrapper_9cd0 (004B9CD0). Invoked by PitServiceSteeringAnimationStep (004B9E40), so the pattern is a per-step float accumulation feeding an animation update.
    // CALL: FloatGetter(*this) dereferences the pointer stored at this+0x0 and returns the float value it points to [field:this:0x00000000, callee:0x004B8790]
    // CALCULATION: v3 = FloatGetter(*this) + a2 accumulates the incoming float parameter onto the stored value [source:raw]
    // CALL: SingleCallWrapper_9cd0(v2, v3) forwards the accumulated sum; argument v2 is an uninitialized local in the decompiled output, so the full signature is unknown [callee:0x004B9CD0, source:raw]
    // CALL: Invoked by PitServiceSteeringAnimationStep (004B9E40), consistent with a per-step steering animation accumulator [caller:0x004B9E40]

    // Conservative worker pseudocode:
    //   float current = FloatGetter(*this);
    //   float sum = current + a2;
    //   SingleCallWrapper_9cd0(v2, sum);
    // UNRESOLVED: Argument v2 to SingleCallWrapper_9cd0 is never assigned in the decompiled source; it is a Hex-Rays artifact and the callee's real parameter layout is unknown
    // UNRESOLVED: The object type owning the this+0x0 float pointer is unknown; prelabel only claims a structural twin of MultiFieldPointerFree (00414380) at DERIVED trust
    // UNRESOLVED: FloatGetter (004B8790) semantics beyond 'return float at *ptr' are not documented here
}
