// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00542680
// Canonical corpus name: ConditionalFloatSetter
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ConditionalFloatSetter_00542680.c

void UnknownObject::ConditionalFloatSetter()
{
    // __thiscall setter that writes a float parameter a2 into the object's float field this+0x88 (this[34]) only when a2 is strictly positive. Non-positive values are rejected and the field retains its previous value. The comparison is against the zero sentinel at 0x0059E430.
    // GUARD: Guard the write on a2 > 0.0; the zero sentinel dbl_59E430 at 0x0059E430 supplies the comparison threshold. [global:0x0059E430, source:raw]
    // ASSIGNMENT: Store a2 into the float field at this+0x88 (this[34]) only when the guard passes. [field:this:0x00000088, source:raw]

    // Conservative worker pseudocode:
    //   void sub_542680(float *this, float a2) {
    //     if (a2 > 0.0)
    //       this[34] = a2;
    //   }
    // UNRESOLVED: Purpose of the guarded float field this+0x88 is unproven; callers span camera (ConditionalRenderPipelineDispatch 0x00409970, CameraModeViewportUpdate 0x00409A00, CameraShake 0x0040ADB0, CameraTransformComputation 0x0040B710) and car-selection (CarSelectionStateMachine 0x00434460) paths.
    // UNRESOLVED: Owner class is unknown; __thiscall shape implies a per-instance parameter that must stay non-negative.
}
