// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00405F80
// Canonical corpus name: ScaledDotProductWithClamp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/ScaledDotProductWithClamp_00405f80.c

void UnknownObject::ScaledDotProductWithClamp()
{
    // Computes an orientation-scaled attenuation factor as a dot-product ratio: the dot of a caller-supplied direction vector a2 with the orientation sub-struct reached through this+0x54 (offsets 0x7C, 0x80, 0x84), plus 330.0, divided by the dot of a2 with the listener-direction components at this+0x34, this+0x38, this+0x3C, plus 330.0, then multiplied by the current gain at this+0x48. The result is clamped to [0.125, 8.0] and written back to this+0x48. Called from F_3DSoundPositioningUpdate (0x00405B90) in the 3D audio positioning path.
    // CALCULATION: Read the orientation sub-struct pointer at this+0x54 and compute the numerator: (orientation[0x7C] * a2[0] + orientation[0x80] * a2[1] + orientation[0x84] * a2[2]) + 330.0. [field:*(this+0x54):0x0000007C, field:*(this+0x54):0x00000080, field:*(this+0x54):0x00000084, field:this:0x00000054, source:raw]
    // CALCULATION: Compute the denominator as the dot of a2 with the listener-direction components at this+0x34, this+0x38, this+0x3C plus 330.0. [field:this:0x00000034, field:this:0x00000038, field:this:0x0000003C, source:raw]
    // CALCULATION: Form the scaled factor v2 = (numerator / denominator) * current gain at this+0x48. [field:this:0x00000048, source:raw]
    // GUARD: Clamp v2 to [0.125, 8.0]: if v2 is below 0.125f write 1040187392 (0.125f) to this+0x48; else if v2 is above 8.0f write 1090519040 (8.0f) to this+0x48; otherwise store v2 unchanged. [field:this:0x00000048, source:raw]
    // ASSIGNMENT: Read the three module-scope float constants 0x0059E4DC, 0x0059E4E0, 0x0059E4E4 that back the 330.0 scale-offset and the 0.125 / 8.0 clamp literals; the exact per-literal mapping is unconfirmed. [global:0x0059E4DC, global:0x0059E4E0, global:0x0059E4E4, source:raw]

    // Conservative worker pseudocode:
    //   void ScaledDotProductWithClamp(void* this, const float* a2) {
    //     const float* ori = *(const float**)((char*)this + 0x54);
    //     float numerator = ori[0x7C / 4] * a2[0] + ori[0x80 / 4] * a2[1] + ori[0x84 / 4] * a2[2] + 330.0f;
    //     float denominator = *(float*)((char*)this + 0x34) * a2[0] + *(float*)((char*)this + 0x38) * a2[1] + *(float*)((char*)this + 0x3C) * a2[2] + 330.0f;
    //     float v2 = (numerator / denominator) * *(float*)((char*)this + 0x48);
    //     if (v2 >= 0.125f) {
    //       if (v2 <= 8.0f) *(float*)((char*)this + 0x48) = v2;
    //       else *(float*)((char*)this + 0x48) = 8.0f;
    //     } else {
    //       *(float*)((char*)this + 0x48) = 0.125f;
    //     }
    //   }
    // UNRESOLVED: The exact mapping of globals 0x0059E4DC, 0x0059E4E0, 0x0059E4E4 to the 330.0 / 0.125 / 8.0 literals is not confirmed by packet evidence.
    // UNRESOLVED: The caller-supplied a2 vector is treated as a direction vector because the sole caller F_3DSoundPositioningUpdate feeds it a normalized direction; this is DERIVED, not CONFIRMED.
    // UNRESOLVED: The orientation sub-struct semantics of offsets 0x7C, 0x80, 0x84 relative to the listener object type are not expressed in the raw text.
}
