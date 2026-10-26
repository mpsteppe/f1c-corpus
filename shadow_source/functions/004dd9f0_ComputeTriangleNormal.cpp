// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD9F0
// Canonical corpus name: TriangleNormalComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TriangleNormalComputation_004dd9f0.c

void UnknownObject::ComputeTriangleNormal()
{
    // Computes the normalized face normal of a triangle from three float vertex pointers (a1, a2, a3) via cross product of the two edge vectors (a3-a2) and (a1-a2), writes the normalized result into the 3-float output pointer a4. Returns 0 on success and -1 on a degenerate (zero-area) triangle where the squared cross-product length is <= 0.0.
    // CALCULATION: Compute edge vectors U = a1 - a2 and V = a3 - a2 componentwise; each vertex is read as three floats (components accessed through vertex fields this+0x0, this+0x4, this+0x8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Compute cross product N = U x V (components v5, v16, v6). [source:raw]
    // CALCULATION: Compute squared length of the cross product: v6*v6 + v16*v16 + v5*v5. [source:raw]
    // GUARD: If squared cross-product length <= 0.0 (degenerate/zero-area triangle, threshold from global zero sentinel dbl_59E430), take the failure path. [global:0x0059E430, source:raw]
    // STATE_TRANSITION: On degenerate triangle: set return value to -1 and normalization scale to 1.0 (from global dbl_59E420). [global:0x0059E420, source:raw]
    // CALCULATION: On valid triangle: normalization scale = 1.0 / sqrt(squared length) (1.0 from global dbl_59E420). [global:0x0059E420, source:raw]
    // ASSIGNMENT: Write scaled normal components v8*v5, v16*v8, v8*v6 into output pointer a4 (a4[0], a4[1], a4[2]). [source:raw]
    // RETURN: Return 0 on success, -1 on degenerate triangle. [function:0x004DD9F0, source:raw]

    // Conservative worker pseudocode:
    //   edge1 = a1 - a2; edge2 = a3 - a2;
    //   cross = cross_product(edge2, edge1);
    //   lenSq = dot(cross, cross);
    //   if (lenSq <= 0.0) { scale = 1.0; status = -1; }
    //   else { scale = 1.0 / sqrt(lenSq); status = 0; }
    //   a4 = cross * scale;
    //   return status;
    // UNRESOLVED: The packet stores vertex components as this+0x0/0x4/0x8 fields while the raw source reads them through three separate float pointers a1/a2/a3; the exact object the fields belong to is unknown.
    // UNRESOLVED: Which callers (AnimationPlaybackSequence 0x0044ACB0, sub_4DE610, sub_4DF110) use the resulting normal and how is not established.
}
