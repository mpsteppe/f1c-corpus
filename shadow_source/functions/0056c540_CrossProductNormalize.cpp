// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0056C540
// Canonical corpus name: CrossProductNormalize
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/CrossProductNormalize_0056c540.c

void UnknownObject::CrossProductNormalize()
{
    // Computes the cross product of two 3-component double vectors (a1 x a2) into a3, then rescales a3 by the factor dot(a1,a2)/|a3| with the dot product clamped to 1.0. The rescaling is skipped entirely when the cross product is zero.
    // CALCULATION: Compute the x component of the cross product a3[0] = a2[2]*a1[1] - a2[1]*a1[2], reading the input vector components at this+0x0, +0x8 and +0x10. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Compute the y component of the cross product a3[1] = a2[0]*a1[2] - a1[0]*a2[2]. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Compute the z component of the cross product a3[2] = a1[0]*a2[1] - a2[0]*a1[1] into local v3. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // ASSIGNMENT: Store the z component v3 into a3[2]. [source:raw]
    // GUARD: Guard on the cross product being non-zero: if all three components of a3 compare unequal to the zero sentinel, proceed to rescale. [global:0x0059E430, source:raw]
    // CALCULATION: Compute the dot product of the two input vectors v5 = a1[0]*a2[0] + a1[2]*a2[2] + a1[1]*a2[1]. [field:this:0x00000000, field:this:0x00000008, field:this:0x00000010, source:raw]
    // CALCULATION: Compute the squared magnitude of the cross product v6 = a3[1]^2 + a3[0]^2 + v3^2. [source:raw]
    // GUARD: Clamp the dot product to 1.0 when it exceeds the boundary constant at 0x0059E420. [global:0x0059E420, source:raw]
    // CALL: Call FloatFunctionPassThrough as part of the float result pipeline. [callee:0x005894A0, source:raw]
    // CALCULATION: Compute the rescale factor v4 = clamped_dot / sqrt(v6). [source:raw]
    // ASSIGNMENT: Scale the three output components a3[0], a3[1], a3[2] by the factor v4. [source:raw]
    // RETURN: Return void. [source:raw]

    // Conservative worker pseudocode:
    //   void sub_56C540(const double* a1, const double* a2, double* a3) {
    //     a3[0] = a2[2]*a1[1] - a2[1]*a1[2];
    //     a3[1] = a2[0]*a1[2] - a1[0]*a2[2];
    //     a3[2] = a1[0]*a2[1] - a2[0]*a1[1];
    //     if (a3[0] != 0.0 || a3[1] != 0.0 || a3[2] != 0.0) {
    //       double dot = a1[0]*a2[0] + a1[1]*a2[1] + a1[2]*a2[2];
    //       if (dot > 1.0) dot = 1.0;
    //       FloatFunctionPassThrough();
    //       double f = dot / sqrt(a3[0]*a3[0] + a3[1]*a3[1] + a3[2]*a3[2]);
    //       a3[0] *= f; a3[1] *= f; a3[2] *= f;
    //     }
    //   }
    // UNRESOLVED: The rescale factor dot/|cross| (dot clamped to 1.0) is not unit normalization; the exact intended geometric meaning is DERIVED from the literals, not confirmed.
    // UNRESOLVED: The boundary constants at 0x0059E420 and 0x0059E430 are read as a 1.0 clamp constant and a zero sentinel respectively; these identities are DERIVED from the skeleton analysis, not confirmed.
    // UNRESOLVED: The FloatFunctionPassThrough call has no visible effect on the computed result in the raw source.
}
