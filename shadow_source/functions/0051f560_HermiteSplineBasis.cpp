// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F560
// Canonical corpus name: HermiteSplineBasis
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/HermiteSplineBasis_0051f560.c

void UnknownObject::HermiteSplineBasis()
{
    // Straight-line SSE evaluation of the four cubic Hermite basis functions at parameter t, then a weighted blend of two input values (a6, a8) against the tangent basis lanes H10 and H11, storing two floats through the output pointer a4 and returning a4. No guards, no callees. Structurally a twin of CubicSpline but only the H10/H11 combination is emitted.
    // ASSIGNMENT: Compute powers of the spline parameter t (a9): the scalar float t is loaded, a1[0] receives t*t (t^2) and a2[0] receives a9*t*t (t^3); both are later broadcast across SSE lanes for the per-lane polynomial. [source:raw, function:0x0051F560]
    // CALCULATION: Evaluate the four-lane cubic polynomial v11 = t^3 * xmmword_5D8A90 + t^2 * xmmword_5D8AB0 + t * xmmword_5D8AC0, with dword_5D8AA0 added as a constant term on lane 0 only. Lane-wise this is the Hermite cubic basis evaluated at t. [source:raw, global:0x005D8A90, global:0x005D8AB0, global:0x005D8AC0, global:0x005D8AA0]
    // CALCULATION: Blend the two input doubles a6 and a8 against selected basis lanes: v12 = _mm_loadh_ps(a6) * shuffle(v11, 80) + _mm_loadh_ps(a8) * shuffle(v11, 250). Shuffles select lanes (0,1) and (2,3); because loadh zeroes the low half, lanes 2 and 3 of v12 survive as a6[*]*H10(t) + a8[*]*H11(t). [source:raw]
    // ASSIGNMENT: Store the low two float lanes of v12 + movehl(a3, v12) through the output double pointer a4, writing the two weighted-combination results a6[i]*H10(t) + a8[i]*H11(t) (8 bytes = one double-width write). [source:raw, function:0x0051F560]
    // RETURN: Return the output pointer a4 unchanged. [source:raw, function:0x0051F560]

    // Conservative worker pseudocode:
    //   double *HermiteSplineBasis(double *out, const double *a6, const double *a8, float t) {
    //     float t2 = t * t;
    //     float t3 = t2 * t;
    //     // v11[0..3] = the four Hermite cubic basis functions evaluated at t (4-lane SSE)
    //     //   v11[i] = t3*xmmword_5D8A90[i] + t2*xmmword_5D8AB0[i] + t*xmmword_5D8AC0[i]
    //     //   with dword_5D8AA0 folded in as the lane-0 constant term
    //     // result: only the H10 and H11 lanes are combined with the two inputs
    //     out[0] = (float)a6[0] * v11[1] + (float)a8[0] * v11[3];
    //     out[1] = (float)a6[1] * v11[1] + (float)a8[1] * v11[3];
    //     return out;
    //   }
    // UNRESOLVED: The four SSE constant globals (xmmword_5D8A90, xmmword_5D8AB0, xmmword_5D8AC0, dword_5D8AA0) are read as data but their numeric values are not in the packet; the Hermite-basis identification is DERIVED from the cubic polynomial shape and the structural twin, not from the constants themselves.
    // UNRESOLVED: a6 and a8 are declared const double* in the raw source but consumed by _mm_loadh_ps as two float lanes; the true element type is ambiguous.
    // UNRESOLVED: Only the H10/H11 lanes are emitted; the H00/H01 contributions are cancelled by loadh low-half zeroing. Whether this is intentional tangent-only interpolation or a specialization for the caller is unknown.
    // UNRESOLVED: Scalar parameters a5 and a7 appear in the prototype but are unused in the shown body; their role is unknown.
    // UNRESOLVED: The a1, a2, a3 __m128 register parameters are __userpurge ABI artifacts of the decompiler output; their live-register meaning is not asserted.
    // UNRESOLVED: Owner object identity is not established by the packet; owner retained as UnknownObject.
}
