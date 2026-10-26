// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0052098E
// Canonical corpus name: PlaneFromEdgesNormalizeSSE
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaneFromEdgesNormalizeSSE_0052098e.c

void UnknownObject::PlaneFromEdgesNormalizeSSE()
{
    // Constructs a plane equation from three 3D points (a2, a3, a4) using SSE intrinsics. Computes two edge vectors, their cross product as the plane normal N, normalizes N via a Newton-Raphson reciprocal-square-root refinement using global constants xmmword_5D8C40/50, then computes the plane distance D as a dot product whose sign is flipped with xmmword_5D8C30. Writes the quad (Nx, Ny, Nz, D) to output a1 and returns a1.
    // CALCULATION: Load first input point from a2 into v5; form edge vectors v6 = point_a2 - point_a4 and v9 = point_a2 - point_a3 via SSE subtract. [source:raw, function:0x0052098E]
    // CALCULATION: v13 = cross product of the two edge vectors using SSE shuffle/multiply/subtract sequence, producing the plane normal N. [source:raw]
    // CALCULATION: v15 = sum of squared components of N (component-wise square plus horizontal add); v15.x = fsqrt of that sum, giving the normal length. [source:raw]
    // CALCULATION: Newton-Raphson refinement of the reciprocal length: v12.x = xmmword_5D8C50 (normalization scale) * (xmmword_5D8C40 (0.5) - squared_length * (1/length) * (1/length)); then v12 is broadcast across lanes. [global:0x005D8C50, global:0x005D8C40, source:raw]
    // ASSIGNMENT: v17 = normal N * broadcast refinement scale (normalized normal); *a1 = v17 writes plane normal (Nx, Ny, Nz) to output field this+0x0. [field:this:0x00000000, global:0x005D8C50, source:raw]
    // CALCULATION: v18 = point_a2 (v8) * normalized normal v17, then horizontal reduce (movehl + shuffle) yielding the plane distance D = dot(point, normal). [source:raw]
    // ASSIGNMENT: Write plane distance: a1->m128_i32[3] = D XOR xmmword_5D8C30 (sign-flip mask), storing the distance component with flipped sign. [global:0x005D8C30, source:raw]
    // RETURN: Return a1 (the output plane pointer). [function:0x0052098E, source:raw]

    // Conservative worker pseudocode:
    //   // Inputs a2, a3, a4 are three points; output quad is (Nx, Ny, Nz, D).
    //   edge1 = point(a2) - point(a4);
    //   edge2 = point(a2) - point(a3);
    //   N = cross(edge1, edge2);
    //   len2 = dot(N, N);
    //   len = sqrt(len2);
    //   scale = G_SCALE * (G_HALF - len2 / (len * len)); // Newton-Raphson refinement (1/len approx)
    //   Nn = N * broadcast(scale);
    //   D = dot(point(a2), Nn);
    //   a1 = (Nn.x, Nn.y, Nn.z, D ^ G_SIGNFLIP);
    //   return a1;
    // UNRESOLVED: Read of this+0x4 (field:this:0x00000004) has no explicit explanation in the raw SSE text; likely a decompiler artifact of the vector loads or an unrelated read.
    // UNRESOLVED: Semantic roles of globals xmmword_5D8C40 (0.5 refinement) and xmmword_5D8C50 (scale) are DERIVED from the Newton-Raphson SSE idiom, not proven by data.
    // UNRESOLVED: Input points are doubles (const double*), output quad is float (__m128); mixed-precision pipeline is per prototype but unverified against callers.
}
