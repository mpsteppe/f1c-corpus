// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004F8850
// Canonical corpus name: PerIndexStructFieldSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PerIndexStructFieldSetter_004f8850.c

void UnknownObject::PerIndexStructFieldSetter()
{
    // Per-index field setter on a float-array object. First delegates to HUDElementConfig(this, a2, a3, a4, a5), then flags the element indexed by a2 as configured by writing 1 to byte this[8*a2+49], and finally copies a 3-float block from a6 into this[8*a2+50..52]. Returns a pointer to that copied 3-float slot.
    // CALL: Delegate to HUDElementConfig(this, a2, a3, a4, a5) to configure the element. [callee:0x004F87C0, source:raw]
    // ASSIGNMENT: Set the element's configuration flag byte this[8*a2+49] to 1. [source:raw]
    // CALCULATION: Compute the slot pointer as &this[8*a2+50], the element's 3-float payload start. [source:raw]
    // ASSIGNMENT: Copy the 3 floats a6[0], a6[1], a6[2] into result[0], result[1], result[2]. [source:raw]
    // RETURN: Return the pointer to the copied 3-float slot. [source:raw]

    // Conservative worker pseudocode:
    //   float *PerIndexStructFieldSetter(float *this, int a2, int a3, float a4, float a5, float *a6) {
    //     HUDElementConfig(this, a2, a3, a4, a5);
    //     *(char *)&this[8*a2+49] = 1;
    //     float *result = &this[8*a2+50];
    //     result[0] = a6[0];
    //     result[1] = a6[1];
    //     result[2] = a6[2];
    //     return result;
    //   }
    // UNRESOLVED: Meaning of HUDElementConfig arguments a3, a4, a5 and the element index a2 depend on the caller's object layout (callers: ParticleEffectUpdateDispatch, WheelContactForceAggregation, WheelForceAggregation, SuspensionForceComputationWithPerCornerVirtualDi).
    // UNRESOLVED: Layout of the indexed element (fixed stride of 32 floats per element) is implied by the expressions but not confirmed by packet fields.
}
