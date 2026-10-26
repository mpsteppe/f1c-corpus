// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044AAE0
// Canonical corpus name: RecursiveTriangleEdgeSubdivisionForCollision
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveTriangleEdgeSubdivisionForCollision_0044aae0.c

void UnknownObject::RecursiveTriangleEdgeSubdivisionForCollision()
{
    // Recursively subdivides triangle (a1, a2, a3) for collision-mesh generation. Each edge vector is computed with Vec3Subtract and its squared length with EmptyFunction. Nested guards select the longest edge that still exceeds the squared-length threshold 22500.0 (stored at dbl_59EF38 per existing analysis): when such an edge is found it is split at its midpoint via WeightedAverageInterpolation, and the function recurses on the two resulting triangles. When all three edges are below the threshold, the triangle is emitted via TriangleMeshAdjacencyBuilder(a5, a1, a2, a3, a4, 0).
    // CALL: Vec3Subtract(v7, a1, a2): compute edge vector a1->a2 into scratch buffer v7. [source:raw, callee:0x004484C0]
    // CALL: EmptyFunction(v7): squared magnitude of edge a1->a2, stored in v8. [source:raw, callee:0x004484F0]
    // CALL: Vec3Subtract(v7, a2, a3): compute edge vector a2->a3. [source:raw, callee:0x004484C0]
    // CALL: EmptyFunction(v7): squared magnitude of edge a2->a3, stored in v9. [source:raw, callee:0x004484F0]
    // CALL: Vec3Subtract(v7, a3, a1): compute edge vector a3->a1. [source:raw, callee:0x004484C0]
    // CALL: EmptyFunction(v7): squared magnitude of edge a3->a1, stored in v5. [source:raw, callee:0x004484F0]
    // GUARD: Outer guard: if edge a1->a2 qualifies (v8 is the smallest squared length, or v8 <= 22500.0 threshold), the longest exceeding edge must lie elsewhere. [source:raw, global:0x0059EF38]
    // GUARD: Middle guard: if edge a2->a3 qualifies (v9 smallest or v9 <= 22500.0), check the last edge a3->a1. [source:raw, global:0x0059EF38]
    // GUARD: Inner guard: if edge a3->a1 also qualifies (v5 smallest or v5 <= 22500.0), all edges are below the squared-length threshold 22500.0. [source:raw, global:0x0059EF38]
    // RETURN: All edges below threshold: emit the triangle via TriangleMeshAdjacencyBuilder(a5, a1, a2, a3, a4, 0). [source:raw, callee:0x004493A0]
    // CALL: Edge a3->a1 exceeds threshold: WeightedAverageInterpolation(v7, a3, a1) computes its midpoint. [source:raw, callee:0x00448480]
    // CALL: Recurse on the two halves sharing the midpoint: (a1, a2, v7, a4, a5) and (v7, a2, a3, a4, a5). [source:raw, callee:0x0044AAE0]
    // CALL: Edge a2->a3 exceeds threshold: WeightedAverageInterpolation(v7, a2, a3) computes its midpoint. [source:raw, callee:0x00448480]
    // CALL: Recurse on the two halves sharing the midpoint: (a1, a2, v7, a4, a5) and (a1, v7, a3, a4, a5). [source:raw, callee:0x0044AAE0]
    // CALL: Edge a1->a2 exceeds threshold: WeightedAverageInterpolation(v7, a1, a2) computes its midpoint. [source:raw, callee:0x00448480]
    // CALL: Recurse on the two halves sharing the midpoint: (a1, v7, a3, a4, a5) and (v7, a2, a3, a4, a5). [source:raw, callee:0x0044AAE0]

    // Conservative worker pseudocode:
    //   int RecursiveTriangleEdgeSubdivisionForCollision(int *a1, int a2, int a3, int a4, char **a5) {
    //     char v7[16];
    //     Vec3Subtract(v7, (int)a1, a2);
    //     double v8 = EmptyFunction(v7);
    //     Vec3Subtract(v7, a2, a3);
    //     double v9 = EmptyFunction(v7);
    //     Vec3Subtract(v7, a3, (int)a1);
    //     double v5 = EmptyFunction(v7);
    //     if (v8 < v9 || v8 < v5 || v8 <= 22500.0) {
    //       if (v9 < v8 || v9 < v5 || v9 <= 22500.0) {
    //         if (v5 < v8 || v5 < v9 || v5 <= 22500.0)
    //           return TriangleMeshAdjacencyBuilder(a5, a1, a2, a3, a4, 0);
    //         WeightedAverageInterpolation(v7, a3, (int)a1);
    //         RecursiveTriangleEdgeSubdivisionForCollision(a1, a2, v7, a4, a5);
    //         return RecursiveTriangleEdgeSubdivisionForCollision(v7, a2, a3, a4, a5);
    //       }
    //       WeightedAverageInterpolation(v7, a2, a3);
    //       RecursiveTriangleEdgeSubdivisionForCollision(a1, a2, v7, a4, a5);
    //       return RecursiveTriangleEdgeSubdivisionForCollision(a1, v7, a3, a4, a5);
    //     }
    //     WeightedAverageInterpolation(v7, (int)a1, a2);
    //     RecursiveTriangleEdgeSubdivisionForCollision(a1, v7, a3, a4, a5);
    //     return RecursiveTriangleEdgeSubdivisionForCollision(v7, a2, a3, a4, a5);
    //   }
    // UNRESOLVED: The scratch buffer v7 is reused for every Vec3Subtract and WeightedAverageInterpolation result; it is only live across the immediate call, which the pseudocode preserves.
    // UNRESOLVED: The nesting of the guards makes edge v8 the preferred split unless v8 is already below threshold; exact selection priority is preserved from source but the intent (longest-edge-first) is DERIVED from the existing analysis.
    // UNRESOLVED: The link between the literal 22500.0 and the global dbl_59EF38 comes from existing_analysis (DERIVED), not from the raw source text.
    // UNRESOLVED: The context for a4 and a5 (adjacency/accumulator state) and the caller AnimationPlaybackSequence (0x0044ACB0) is not established here.
}
