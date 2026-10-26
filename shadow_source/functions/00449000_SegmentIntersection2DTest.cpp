// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00449000
// Canonical corpus name: F_2DLineSegmentIntersection
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/F_2DLineSegmentIntersection_00449000.c

void UnknownObject::SegmentIntersection2DTest()
{
    // 2D line-segment intersection test over four point triples (a1, a2, a3, a4). Rejects segments that share both endpoints or form a vertical pair, then solves both intersection parameters and requires each to lie strictly inside the open unit interval. Rejects contact at segment endpoints within the 0.001 skin tolerance by comparing each parametric distance against the corresponding segment length. Returns true only for a valid interior crossing. Invoked by SATEdgeSeparationTest (004491C0).
    // GUARD: Reject when the segments share both endpoints: a1 == a3 and a2 == a4, or a1 == a4 and a2 == a3, returning 0 [source:raw]
    // GUARD: Reject when the first segment is vertical (a1.x == a2.x via field 0x0) and the second segment is also vertical (a3.x == a4.x), returning 0 [source:raw, field:this:0x00000000]
    // ASSIGNMENT: When only the first segment is vertical (a1.x == a2.x but a3.x != a4.x), swap the two segments so the solver always proceeds with a non-vertical first segment [source:raw]
    // CALCULATION: Reads vertex coordinates through this+0x0 (X) and this+0xC (Y) and computes the direction deltas v21, v20, v17, v22 between the two endpoint pairs [field:this:0x00000000, field:this:0x0000000C, source:raw]
    // CALCULATION: Computes the slope scale v23 = 1.0 / v21 using the constant 1.0 (dbl_59E420) [global:0x0059E420, source:raw]
    // GUARD: Reject the parallel / degenerate case: v12 = v17 * v11 + v22 equals 0.0 (zero constant dbl_59E430), returning 0 [global:0x0059E430, source:raw]
    // CALCULATION: Solves v18 = (v11 * v8 + v9 - (v11 * v19 + v10)) / v12, the intersection parameter measured along segment two [source:raw]
    // GUARD: Reject v18 outside the open unit interval: v18 <= 0.0 or v18 >= 1.0, returning 0 [source:raw]
    // CALCULATION: Solves v14 = (v18 * v17 + v19 - v8) * v23, the intersection parameter measured along segment one [source:raw]
    // GUARD: Reject v14 outside the open unit interval: v14 <= 0.0 or v14 >= 1.0, returning 0 [source:raw]
    // CALCULATION: Computes segment-one length v24 = sqrt(v20 * v20 + v21 * v21) and the contact distance v15 = v14 * v24 [source:raw]
    // GUARD: Reject contact at a segment-one endpoint within the skin tolerance: v15 <= 0.001 or v15 >= v24 - 0.001, using the 0.001 threshold (dbl_59EA08), returning 0 [global:0x0059EA08, source:raw]
    // CALCULATION: Computes segment-two length v16 = sqrt(v22 * v22 + v17 * v17) [source:raw]
    // RETURN: Returns true only when v18 * v16 is strictly inside (0.001, v16 - 0.001), again applying the 0.001 endpoint skin [global:0x0059EA08, source:raw]
    // CALL: Invoked by SATEdgeSeparationTest (004491C0) for edge-to-edge crossing tests [caller:0x004491C0, source:raw]

    // Conservative worker pseudocode:
    //   if (a1 == a3 && a2 == a4) return 0;
    //   if (a1 == a4 && a2 == a3) return 0;
    //   if (a2.x == a1.x) {
    //     if (a4.x == a3.x) return 0;
    //     swap the two segments;
    //   }
    //   v21 = seg1.x2 - seg1.x1; v20 = seg1.y2 - seg1.y1;
    //   v17 = seg2.x2 - seg2.x1; v22 = seg2.y2 - seg2.y1;
    //   v23 = 1.0 / v21;
    //   v12 = v17 * -(v23 * v20) + v22;
    //   if (v12 == 0.0) return 0;
    //   v18 = (intersection parameter along segment two);
    //   if (v18 <= 0.0 || v18 >= 1.0) return 0;
    //   v14 = (intersection parameter along segment one);
    //   if (v14 <= 0.0 || v14 >= 1.0) return 0;
    //   len1 = sqrt(v20 * v20 + v21 * v21);
    //   if (v14 * len1 <= 0.001 || v14 * len1 >= len1 - 0.001) return 0;
    //   len2 = sqrt(v22 * v22 + v17 * v17);
    //   return v18 * len2 > 0.001 && v18 * len2 < len2 - 0.001;
    // UNRESOLVED: Each point is a float triple (12-byte stride), but only the X component (this+0x0) and the Y component (this+0xC) are read; the third component is never used here
    // UNRESOLVED: The three read-only constants dbl_59E420, dbl_59E430 and dbl_59EA08 are folded into the arithmetic by the compiler; their runtime identities are packet facts, not proven from this function alone
    // UNRESOLVED: The exact geometric interpretation of the v11 intermediate sign term could not be fully reconstructed
}
