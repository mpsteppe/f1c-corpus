// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F2C0
// Canonical corpus name: SSECubicSplineInterpolation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSECubicSplineInterpolation_0051f2c0.c

void UnknownObject::SSECubicSplineInterpolation()
{
    // Pure SSE cubic-spline (Hermite-basis) interpolation. Evaluates four cubic weight polynomials at the float parameter a8 by a vector polynomial t*P3 + P0 + t^2*P2 + t^3*P1 whose coefficient vectors are the XMM constants xmmword_5D8A80/60/70/50, broadcasts the resulting weights, blends the two control-pair inputs a5 (start) and a7 (end), and stores the two resulting single-precision values to a3, which is returned.
    // CALCULATION: Take the float parameter a8 as XMM v8 and square it into a1 lane 0 (t^2). [source:raw]
    // CALCULATION: Compute a8 * t^2 into a2 lane 0 (t^3). [source:raw]
    // CALCULATION: Broadcast t across all four lanes (shuffle 0), multiply by xmmword_5D8A80 (t coefficient vector) and add xmmword_5D8A60 (constant vector). [source:raw, global:0x005D8A80, global:0x005D8A60]
    // CALCULATION: Accumulate the t^2 term (shuffled a1 multiplied by xmmword_5D8A70) and the t^3 term (shuffled a2 multiplied by xmmword_5D8A50) into v9, producing four cubic weight polynomials evaluated at t. [source:raw, global:0x005D8A70, global:0x005D8A50]
    // CALCULATION: Load the end control pair from a7 (high half of an XMM register, two floats) and scale it by broadcast weights taken from v9 lanes 2,3 (shuffle 250) into v10. [source:raw]
    // CALCULATION: Load the start control pair from a5, scale it by broadcast weights taken from v9 lanes 0,1 (shuffle 80), and add v10 into v11. [source:raw]
    // ASSIGNMENT: Sum v11 with its high-half moved to low lanes (movehl) and store the low two floats to the output pointer a3: out[0] = a5[0]*w0 + a7[0]*w2, out[1] = a5[1]*w1 + a7[1]*w3. [source:raw]
    // RETURN: Return the output pointer a3. [function:0x0051F2C0, source:raw]

    // Conservative worker pseudocode:
    //   // a8 = parameter t; a5/a7 = start/end control pairs; result = a3 (2 floats)
    //   t2 = a8 * a8;
    //   t3 = a8 * t2;
    //   w = t * XMM[0x005D8A80] + XMM[0x005D8A60] + t2 * XMM[0x005D8A70] + t3 * XMM[0x005D8A50]; // 4 lanes
    //   out[0] = a5[0] * w[0] + a7[0] * w[2];
    //   out[1] = a5[1] * w[1] + a7[1] * w[3];
    //   return a3;
    // UNRESOLVED: Exact float values of the four coefficient vectors xmmword_5D8A50/60/70/80 are not present in the packet, so the specific Hermite/cubic basis (e.g. smoothstep h00/h01 vs tangent-carrying h10/h11) cannot be confirmed.
    // UNRESOLVED: Decompiler declares a3/a5/a7 as double* but all loads/stores are single-precision float pairs (loadh/storel); the true element type is ambiguous.
    // UNRESOLVED: The int parameters a4 and a6 are unused in the body; their purpose is unknown.
    // UNRESOLVED: Whether the two outputs interpolate two components of one vector or two independent scalars is not resolvable from this function alone.
}
