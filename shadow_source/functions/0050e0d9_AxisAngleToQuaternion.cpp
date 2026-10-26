// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0050E0D9
// Canonical corpus name: AxisAngleToQuaternion
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/AxisAngleToQuaternion_0050e0d9.c

void UnknownObject::AxisAngleToQuaternion()
{
    // Converts an axis-angle vector (a2, with the rotation angle encoded as the vector magnitude) into a quaternion written to a1. Writes a1[3] = cos(angle); when sin(angle) is not near zero (FloatRangeCheck), writes a1[0..2] = axis * (sin(angle)/angle); otherwise takes a degenerate near-zero-angle branch. Returns a1.
    // CALCULATION: Compute rotation angle v5 as the magnitude of the axis vector a2: v5 = sqrt(a2[0]^2 + a2[1]^2 + a2[2]^2). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw, function:0x0050E0D9]
    // ASSIGNMENT: Write the quaternion scalar component: a1[3] = cos(v5). [field:this:0x0000000C, source:raw, function:0x0050E0D9]
    // CALCULATION: Compute v6 = sin(v5) and hold it for the degenerate check and the scaling factor. [source:raw, function:0x0050E0D9]
    // CALL: Call FloatRangeCheck(v6, 0.0) to test whether sin(angle) is within range of zero. [callee:0x0050C042, source:raw, function:0x0050E0D9]
    // GUARD: Branch on the FloatRangeCheck result: true selects the degenerate near-zero-angle path, false selects the general scaling path. [callee:0x0050C042, source:raw, function:0x0050E0D9]
    // ASSIGNMENT: Degenerate path: copy a1[0..2] from a second pointer (v2). The raw source shows v2 as an uninitialized register-derived value, so the intended copy source is unresolved. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw, function:0x0050E0D9]
    // CALCULATION: General path: compute the normalization factor v3 = v6 / v5 = sin(angle)/angle. [source:raw, function:0x0050E0D9]
    // ASSIGNMENT: General path: write a1[0] = v3 * a2[0]. [field:this:0x00000000, source:raw, function:0x0050E0D9]
    // ASSIGNMENT: General path: write a1[1] = v3 * a2[1]. [field:this:0x00000004, source:raw, function:0x0050E0D9]
    // ASSIGNMENT: General path: write a1[2] = v3 * a2[2]. [field:this:0x00000008, source:raw, function:0x0050E0D9]
    // RETURN: Return the output quaternion pointer a1. [source:raw, function:0x0050E0D9]

    // Conservative worker pseudocode:
    //   float *AxisAngleToQuaternion(float *outQuat, const float *axisAngle) {
    //     float angle = sqrtf(axisAngle[0]*axisAngle[0] + axisAngle[1]*axisAngle[1] + axisAngle[2]*axisAngle[2]);
    //     outQuat[3] = cosf(angle);
    //     float s = sinf(angle);
    //     if (FloatRangeCheck(s, 0.0f)) {
    //       /* degenerate near-zero-angle path; copy source unresolved * /
    //     } else {
    //       float k = s / angle;
    //       outQuat[0] = k * axisAngle[0];
    //       outQuat[1] = k * axisAngle[1];
    //       outQuat[2] = k * axisAngle[2];
    //     }
    //     return outQuat;
    //   }
    // UNRESOLVED: Degenerate branch copies a1[0..2] from v2, which the decompiler shows as an uninitialized register-derived pointer; the intended copy source is unknown.
    // UNRESOLVED: FloatRangeCheck's exact epsilon/range semantics are not present in the packet; only its use as a near-zero guard for sin(angle) is evident.
    // UNRESOLVED: Whether the input axis vector a2 is expected to be pre-normalized before the caller, or normalization happens upstream, is not evident from this function alone.
}
