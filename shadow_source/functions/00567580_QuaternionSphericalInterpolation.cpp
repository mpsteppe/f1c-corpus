// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00567580
// Canonical corpus name: sub_567580
// Owner: UnknownObject [DERIVED]
// Raw source: functions/sub_567580_00567580.c

void UnknownObject::QuaternionSphericalInterpolation()
{
    // Four-component (quaternion-like) spherical interpolation between a2 and a3 with factor a4, writing the blended result into this[0..3]. Computes the dot product of the two inputs, negates the stored dot and all four components of a3 when the dot is negative (shortest-arc path), then blends a2 against the possibly-negated a3 using sin-weighted factors sin(dot*(1.0-a4))/sin(dot) and sin(dot*a4)/sin(dot). A near-identity guard (1.0 - dot against the 0.02 tolerance) selects the direct-lerp fallback through the x87 control-word passthrough helper instead of the sin-weighted branch. Structural twin of the 0053b5b0 slerp cluster; reused by both the collision response filter and the audio sample crossfade interpolation paths.
    // CALCULATION: Compute the dot product of a2 and a3 as a3[3]*a2[3] + a3[2]*a2[2] + a2[0]*a3[0] + a3[1]*a2[1], held through the float view of v19. [source:raw]
    // GUARD: If the dot product is below zero (compared against a read-only float global constant), negate both the stored dot and all four a3 components so interpolation takes the shortest arc. [source:raw, global:0x0059E43C]
    // ASSIGNMENT: Copy the (possibly negated) a3 components into v14..v17 as the second input of the final blend. [source:raw]
    // CALCULATION: Compute the inverse weight 1.0 - a4 (from a read-only float global constant) into the float view of v18. [source:raw, global:0x0059E440]
    // GUARD: Near-identity guard: 1.0 - dot is compared against the 0.02 tolerance constant (read-only float global); inside tolerance the sin-weighted branch is skipped and the direct blend weights are used. [source:raw, global:0x0059E6EC]
    // CALL: Call FloatFunctionPassThrough (x87 control-word/status passthrough) before the sin-weighted calculation when outside the tolerance. [callee:0x005894A0, source:raw]
    // CALCULATION: Compute the sin-weighted blend factors: reciprocal 1.0/sin(dot), then sin(dot*(1.0-a4))*reciprocal for the first weight and sin(dot*a4)*reciprocal for the second. [source:raw]
    // ASSIGNMENT: Blend all four outputs: this[i] = firstWeight * a2[i] + v14plus * secondWeight for each component i in 0..3. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]

    // Conservative worker pseudocode:
    //   void QuaternionSphericalInterpolation(float *out, const float *a, const float *b, float t) {
    //     float dot = b[3] * a[3] + b[2] * a[2] + a[0] * b[0] + b[1] * a[1];
    //     float bx0 = b[0], bx1 = b[1], bx2 = b[2], bx3 = b[3];
    //     if (dot >= 0.0) {
    //       /* keep b as-is * /
    //     } else {
    //       dot = -dot;
    //       bx0 = -b[0]; bx1 = -b[1]; bx2 = -b[2]; bx3 = -b[3];
    //     }
    //     float omt = 1.0 - t;
    //     float omd = 1.0 - dot;
    //     /* FPU compare of omd against 0.02, condition-code mask check 0x4100 * /
    //     if (condition_passes) {
    //       FloatFunctionPassThrough();
    //       float inv = 1.0 / sin(dot);
    //       omt = sin(dot * omt) * inv;
    //       t = sin(dot * t) * inv;
    //     }
    //     out[0] = omt * a[0] + bx0 * t;
    //     out[1] = omt * a[1] + bx1 * t;
    //     out[2] = omt * a[2] + bx2 * t;
    //     out[3] = omt * a[3] + bx3 * t;
    //   }
    // UNRESOLVED: Exact pairing of the three read-only float globals (flt_59E43C / flt_59E440 / flt_59E6EC) to the 0.0 / 0.02 / 1.0 constants is not determinable from the packet alone.
    // UNRESOLVED: The angle argument passed to sin() is the dot value itself; no separate arc-cosine step is visible, so the exact spherical-angle semantics are inferred rather than certain.
    // UNRESOLVED: Two unrelated callers (collision response filter and audio sample crossfade interpolation) reuse the same math; the owning class identity remains unknown.
    // UNRESOLVED: The exact polarity of the FPU condition-code guard (0x4100) relative to the 0.02 tolerance is a decompiler artifact and is rendered as a conditional branch without claiming which side dominates.
}
