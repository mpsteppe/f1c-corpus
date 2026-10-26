// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F200
// Canonical corpus name: SSEHermiteCubicInterp
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SSEHermiteCubicInterp_0051f200.c

void UnknownObject::SSEHermiteCubicInterp()
{
    // Hermite cubic interpolation between four input float pairs (a4-a7) using SSE intrinsics. Computes t^2 and t^3 from parameter t (a8), evaluates a cubic basis polynomial via precomputed spline coefficient constants (xmmword_5D8A50/60/70/80), blends the four inputs with the resulting basis values, and stores the interleaved result at output pointer a3. Straight-line, unconditional, no callees.
    // CALCULATION: Square interpolation parameter t=a8 into a1, yielding t^2. [source:raw, function:0x0051F200]
    // CALCULATION: Compute t^3 = t * t^2 into a2. [source:raw, function:0x0051F200]
    // CALCULATION: Evaluate the cubic basis polynomial at t via SSE multiply-accumulate: constant term xmmword_5D8A60, t term xmmword_5D8A80, t^2 term xmmword_5D8A70, t^3 term xmmword_5D8A50; result held in v9. [source:raw, global:0x005D8A50, global:0x005D8A60, global:0x005D8A70, global:0x005D8A80]
    // CALCULATION: Blend the four input float pairs a4, a5, a6, a7 using the four scalar basis values broadcast from v9 via shuffles; result held in v10. [source:raw, function:0x0051F200]
    // ASSIGNMENT: Store high 64 bits of v10 to output pointer a3 as a double, and store the low 32 bits of v10 at a3+8, producing the interleaved float-pair output. [source:raw, function:0x0051F200]
    // RETURN: Return output pointer a3. [source:raw, function:0x0051F200]

    // Conservative worker pseudocode:
    //   // t = a8; basis coefficients from global SSE constants
    //   t2 = t * t;
    //   t3 = t * t2;
    //   basis = c0(xmmword_5D8A60) + c1(xmmword_5D8A80)*t + c2(xmmword_5D8A70)*t2 + c3(xmmword_5D8A50)*t3;
    //   v10 = basis_0*a4 + basis_1*a5 + basis_2*a6 + basis_3*a7;
    //   *(double*)a3 = high64(v10);
    //   *(int*)(a3 + 8) = low32(v10);
    //   return a3;
    // UNRESOLVED: Exact coefficient values stored at xmmword_5D8A50/60/70/80 are not present in the packet; the t/t^2/t^3/constant term mapping is inferred from the decompiler expression only.
    // UNRESOLVED: Storing low 32 bits of v10 at a3+8 via an integer store implies interleaved float-pair output, but the exact output layout is unconfirmed.
    // UNRESOLVED: No callers or frame path found; the function may be reached indirectly or be a top-level math utility.
}
