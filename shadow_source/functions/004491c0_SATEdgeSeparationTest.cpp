// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004491C0
// Canonical corpus name: SATEdgeSeparationTest
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SATEdgeSeparationTest_004491c0.c

void UnknownObject::SATEdgeSeparationTest()
{
    // Triangle-pair intersection test. Computes edge half-planes of the first triangle into a 72-byte stack buffer, then for each of the three vertex pairs tests a separating axis via SATSeparatingAxisTest; if none separates, repeats the process on the second triangle against the first's vertex pairs. When neither triangle pair is separated, tests 2D line-segment intersections between the edges of both triangles with F_2DLineSegmentIntersection; returns 1 (intersecting) on the first edge crossing, else 0.
    // CALL: Compute edge half-plane data of the first triangle this into the stack buffer v13 via TriangleEdgeHalfPlaneComputation(this, v13). [source:raw, callee:0x00448F00]
    // LOOP: Loop over the three vertex pairs of the second triangle a2: index v4 from 0, test SATSeparatingAxisTest(v13, a2[2*v4]). [source:raw, callee:0x00448FC0]
    // GUARD: Guard on each SATSeparatingAxisTest result: a true separating axis returns 1 immediately; exit the loop when all three tests pass without separation (v4 reaches 3). [source:raw, callee:0x00448FC0]
    // CALL: Recompute edge half-planes of the second triangle a2 into the same buffer via TriangleEdgeHalfPlaneComputation(a2, v13). [source:raw, callee:0x00448F00]
    // LOOP: Loop over the three vertex pairs of the first triangle this: index v5 from 0, test SATSeparatingAxisTest(v13, this[2*v5]); return 1 if any test reports a separating axis. [source:raw, callee:0x00448FC0]
    // LOOP: Nested edge-pair loop: for edge index v6 in 0..2, compute next vertex index v7 = (v6 + 1) % 3, then iterate over the second triangle's vertices v11 = 0..2 calling F_2DLineSegmentIntersection(this[2*v6], this[2*v7], a2[2*v6], a2[2*v9]). [source:raw, callee:0x00449000]
    // RETURN: Return 1 when any edge pair intersects; return 0 when all three edge-pair scans complete without an intersection. [source:raw, callee:0x00449000]

    // Conservative worker pseudocode:
    //   char SATEdgeSeparationTest(_DWORD *this, _DWORD *a2) {
    //     _BYTE v13[72];
    //     TriangleEdgeHalfPlaneComputation(this, v13);
    //     for (int i = 0; i < 3; ++i)
    //       if (SATSeparatingAxisTest(v13, (float*)a2[2*i])) return 1;
    //     TriangleEdgeHalfPlaneComputation(a2, v13);
    //     for (int j = 0; j < 3; ++j)
    //       if (SATSeparatingAxisTest(v13, (float*)this[2*j])) return 1;
    //     for (int e = 0; e < 3; ++e) {
    //       int e2 = (e == 2) ? 0 : e + 1;
    //       int v = (e == 2) ? 0 : e + 1;
    //       for (int k = 0; k < 3; ++k) {
    //         if (F_2DLineSegmentIntersection((float*)this[2*e], (float*)this[2*e2], (float*)a2[2*e], (float*)a2[2*v])) return 1;
    //       }
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: Triangle vertex layout and the 2*index stride imply vertex pointers are packed as pointer pairs; exact struct layout of the triangle object is unknown.
    // UNRESOLVED: Semantic meaning of the 72-byte half-plane buffer (internal format) is not determined.
    // UNRESOLVED: Caller SweepAndPruneAABBOverlapDetection (0x004497E0) suggests broad-phase use, but the owning collision object is unknown.
}
