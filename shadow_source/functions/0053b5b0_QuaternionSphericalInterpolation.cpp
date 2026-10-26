// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0053B5B0
// Canonical corpus name: QuaternionSphericalInterpolation
// Owner: QuaternionMathLibrary [DERIVED]
// Raw source: functions/QuaternionSphericalInterpolation_0053b5b0.c

void QuaternionMathLibrary::QuaternionSphericalInterpolation()
{
    // Spherical linear interpolation (SLERP) of two quaternions. Computes the 4-component dot product of a2 and a3; when negative, negates a3 to take the shortest path on the hypersphere. When 1.0 - dot exceeds the 0.02 epsilon, calls FloatFunctionPassThrough (0x005894A0) and blends with sin-based weights (1.0/sin(dot) applied to sin(dot*weight)); otherwise falls through to the linear blend. Writes the interpolated quaternion to this[0..3] (this+0x0/+0x4/+0x8/+0xC).
    // CALCULATION: Compute the 4-component dot product of quaternions a2 and a3: a3[3]*a2[3] + a3[2]*a2[2] + *a2 * *a3 + a3[1]*a2[1] [source:raw]
    // GUARD: When the dot product is negative, negate the source quaternion a3 (components v9..v12) and the stored dot value (shortest-path on the hypersphere); otherwise copy a3 unmodified [source:raw]
    // CALCULATION: Compute the weight complement v13 = 1.0 - a4 [source:raw]
    // GUARD: When 1.0 - dot > 0.02 use full trigonometric SLERP (sin-based weights); otherwise fall through to the linear blend path [source:raw]
    // CALL: Call FloatFunctionPassThrough (0x005894A0) before the sin-based interpolation weights are computed [callee:0x005894A0, source:raw]
    // CALCULATION: SLERP weights: v8 = 1.0/sin(dot); v13 = sin(dot*v13)*v8; a4 = sin(dot*a4)*v8 [source:raw]
    // ASSIGNMENT: Blend the result quaternion: this[i] = v13 * a2[i] + v_n * a4 for components 0-3, writing this+0x0, this+0x4, this+0x8, and this+0xC [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // RETURN: Void return; called by sub_551210 (0x00551210); the ABI lead name is Quaternion_Spherical_Interpolation [caller:0x00551210, abi:lead, function:0x0053B5B0, source:raw]

    // Conservative worker pseudocode:
    //   dot = a3[3]*a2[3] + a3[2]*a2[2] + a2[0]*a3[0] + a3[1]*a2[1];
    //   if (dot < 0.0) { dot = -dot; a3 = -a3; }
    //   w = 1.0 - t;
    //   if (1.0 - dot > 0.02) {
    //     FloatFunctionPassThrough();
    //     inv = 1.0/sin(dot);
    //     w = sin(dot*w)*inv;
    //     t = sin(dot*t)*inv;
    //   }
    //   this[0] = w*a2[0] + a3[0]*t;
    //   this[1] = w*a2[1] + a3[1]*t;
    //   this[2] = w*a2[2] + a3[2]*t;
    //   this[3] = w*a2[3] + a3[3]*t;
    // UNRESOLVED: Three read-only globals (flt_59E43C, flt_59E440, flt_59E6EC) are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill labels them physics constants, all unverifiable from this packet
    // UNRESOLVED: The 0.02 epsilon threshold and the 1.0 constants match the small-angle linearization cut-off in the skeleton fill, but the derivation of those constants is not evidenced in the packet
}
