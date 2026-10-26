// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0051F89E
// Canonical corpus name: PlaneFromThreePoints
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/PlaneFromThreePoints_0051f89e.c

void UnknownObject::PlaneFromThreePoints()
{
    // Reconstructs a plane equation from three input points (a2, a3, a4) using SSE intrinsics: forms two edge vectors from the shared point, computes their cross product as the plane normal, normalizes it via fsqrt plus a Newton-Raphson reciprocal-sqrt refinement driven by globals 0x005D8AE0 and 0x005D8AF0, and derives the plane distance D from the dot product of the first point with the normal, sign-flipped via global 0x005D8AD0. Stores the 4-lane plane (Nx, Ny, Nz, D) at output a1 and returns a1. Plane-from-three-points identity rests on the legacy ABI name; no caller is evidenced.
    // CALCULATION: Load input point a2 into a vector register via _mm_loadh_ps (high 64 bits); only its two (x, y) lanes take part in the computation. [function:0x0051F89E, source:raw]
    // CALCULATION: Form edge vector C - A = loadh(a2) - loadh(a4) (v6). [function:0x0051F89E, source:raw]
    // CALCULATION: Form edge vector B - A = loadh(a2) - loadh(a3) (v9). [function:0x0051F89E, source:raw]
    // CALCULATION: Cross product of the two edge vectors via shuffle/multiply/subtract (v7, v10, v11, v13) producing the unnormalized plane normal. [function:0x0051F89E, source:raw]
    // CALCULATION: Compute squared normal length (lane sums v14, v15), take fsqrt, then Newton-Raphson reciprocal-sqrt refinement using global 0x005D8AE0 (refinement coefficient, described as 0.5 in prior analysis) and global 0x005D8AF0 (normalization scale constant). [function:0x0051F89E, global:0x005D8AE0, global:0x005D8AF0, source:raw]
    // CALCULATION: Normalize the normal vector: multiply the cross product by the refined reciprocal length (v17). [function:0x0051F89E, source:raw]
    // ASSIGNMENT: Store the normalized normal (full 16-byte m128 quad) to the output plane at this+0x0 (RW). [function:0x0051F89E, field:this:0x00000000, source:raw]
    // CALCULATION: Dot the saved first point (v8 = loadh(a2)) with the normalized normal (v18) and sum the components to obtain the plane distance term. [function:0x0051F89E, source:raw]
    // ASSIGNMENT: Negate the distance (sign-flip XOR with global 0x005D8AD0) and store the plane D component into the output plane (lane 3 of the quad, byte offset 0xC). [function:0x0051F89E, global:0x005D8AD0, source:raw]
    // RETURN: Return the output pointer a1. [function:0x0051F89E, source:raw]

    // Conservative worker pseudocode:
    //   // a1: output plane (Nx, Ny, Nz, D); a2, a3, a4: three input points
    //   e1 = loadh(a2) - loadh(a4);  // edge from shared point A to point C
    //   e2 = loadh(a2) - loadh(a3);  // edge from shared point A to point B
    //   n = cross(e2, e1);           // unnormalized normal (shuffle/mul/sub)
    //   rlen = refine_rsqrt(dot(n, n)); // fsqrt + Newton step (coeff 0x005D8AE0, scale 0x005D8AF0)
    //   a1 = n * rlen;               // normalized normal; lane 3 overwritten by D
    //   d = -(a2 . a1);               // distance term, sign-flip XOR via 0x005D8AD0
    //   a1[3] = d;
    //   return a1;
    // UNRESOLVED: Low 64-bit lanes of the loaded points are left uninitialized by _mm_loadh_ps; only the two high (x, y) lanes of each point participate in the computation.
    // UNRESOLVED: Packet field this+0x4 is marked read (R), but no explicit read of that lane appears in the raw source; the whole output quad is written by *a1 = v17 and lane 3 (byte offset 0xC) is overwritten with D. The +0x4 read may be a decompiler artifact of the returned pointer.
    // UNRESOLVED: Exact constant values of globals 0x005D8AF0 (scale) and 0x005D8AE0 (refinement coefficient, described as 0.5 in prior analysis) are not evidenced in this packet; their roles as normalization constants are DERIVED.
    // UNRESOLVED: The shuffle masks and lane layout of the cross product are reconstructed from source:raw but not runtime-verified; uninitialized low lanes do not contribute to the stored plane.
    // UNRESOLVED: No caller is evidenced, so the plane-from-three-points semantics rest on the legacy ABI name PlaneFromThreePoints and the SSE shape of the code (DERIVED, not CONFIRMED).
}
