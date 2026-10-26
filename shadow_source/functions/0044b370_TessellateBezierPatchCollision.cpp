// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044B370
// Canonical corpus name: BezierPatchTessellation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BezierPatchTessellation_0044b370.c

void UnknownObject::TessellateBezierPatchCollision()
{
    // Tessellates Bezier patch control-point data into a collision triangle mesh. Initializes a collision shape buffer, packs input triangle vertices (32-byte stride from a2[2]) into cyclic adjacency via repeated TriangleMeshAdjacencyBuilder calls, computes collision contact responses, frees the input buffer, allocates a per-patch result index buffer, fits height-above-terrain surface coefficients per patch (HATPolygonSurfaceFit, then sub_44B110 derives a permutation index), writes fitted surface-height doubles into neighbour vertices, and finally builds the output adjacency buffer under a permutation-index switch dispatched through the jpt_44B6EC jump table (cases 0, 1-3 via AxisPermutationMatrixRead, 4 via CollisionFaceVerticesGather), freeing temporaries at the end. Called from CollisionGeometryOperationSelector (0x0044BB60).
    // CALL: Initialize the local collision shape buffer v69 via CollisionShapeInit. [callee:0x004492B0, source:raw]
    // CALL: Allocate the contact buffer for the input patch count: CollisionContactBufferAllocator(v69, 4 * a2[0]). [callee:0x004492D0, source:raw]
    // LOOP: Per-triangle loop over a2[0] entries: pack the vertex float/double components read at 32-byte stride from the a2[2] control-point stream into the local arrays v70/v73, tag each vertex set with RGBColorPacking(v5, v65), then call TriangleMeshAdjacencyBuilder four times over the four cyclic permutations of the packed arrays. [callee:0x00448EE0, callee:0x004493A0, source:raw]
    // CALL: Compute collision contact responses from the built adjacency: CollisionContactResponse(v69). [callee:0x00449700, source:raw]
    // CALL: Release the input triangle buffer: PhysicsBufferFree(a2). [callee:0x00449340, source:raw]
    // CALL: Allocate the per-patch result index buffer v65[0] with OperatorNewNhMallocWrapper(4 * count). [callee:0x00587C03, source:raw]
    // LOOP: Per-patch loop over the count: run HATPolygonSurfaceFit on each of the four vertices (92-byte output stride, 32-byte input stride), then sub_44B110(v82) derives a permutation index stored into the result index buffer v65[0][v61]. [callee:0x00449A80, callee:0x0044B110, source:raw]
    // LOOP: For each patch whose stored permutation index pointer is non-null: gather the face vertices with CollisionFaceVerticesGather(v81, v82), pack a color identifier with RGBColorPacking(v82[0], &v66), copy the capsule collision shape into the pipeline with CollisionCapsuleShapeCopyToPipeline(v81, color, &v74), then loop over the three edges writing fitted surface-height doubles into neighbour vertex fields using the v74..v79 coefficients. [callee:0x0044AF20, callee:0x00448EE0, callee:0x0044B040, source:raw]
    // CALL: Allocate the output adjacency buffer: CollisionContactBufferAllocator(a3, count). [callee:0x004492D0, source:raw]
    // STATE_TRANSITION: Per-patch output build: dispatch on the stored permutation index through the jpt_44B6EC jump table (global 0x0044B8F4): case 0 re-gathers vertex components per edge and emits TriangleMeshAdjacencyBuilder for each of the four edges; cases 1-3 perform two AxisPermutationMatrixRead(v81, v82, perm, k) passes for k in 0..1 then emit TriangleMeshAdjacencyBuilder; case 4 gathers vertices once with CollisionFaceVerticesGather and emits TriangleMeshAdjacencyBuilder; default performs no output. [callee:0x0044AF60, callee:0x0044AF20, callee:0x00448EE0, callee:0x004493A0, global:0x0044B8F4, source:raw]
    // CALL: Release the intermediate shape buffer: PhysicsBufferFree(v69). [callee:0x00449340, source:raw]
    // CALL: Free the result index buffer v65[0] via FreeWrapper_7bcf when it is non-null. [callee:0x00587BCF, source:raw]
    // RETURN: Return the result of a final PhysicsBufferFree(v69) release of the local shape buffer. [callee:0x00449340, function:0x0044B370, source:raw]
    // CALL: Invoked from CollisionGeometryOperationSelector (0x0044BB60). [caller:0x0044BB60]

    // Conservative worker pseudocode:
    //   int TessellateBezierPatchCollision(void *this, int *a2, char **a3) {
    //     CollisionShapeInit(v69);
    //     count = a2[0];
    //     CollisionContactBufferAllocator(v69, 4 * count);
    //     for (each triangle) {
    //       pack vertices from a2[2] at 32-byte stride;
    //       RGBColorPacking(vertex, v65);
    //       TriangleMeshAdjacencyBuilder(v69, ..., 4 permutations);
    //     }
    //     CollisionContactResponse(v69);
    //     PhysicsBufferFree(a2);
    //     v65[0] = OperatorNewNhMallocWrapper(4 * count);
    //     for (each patch) {
    //       for (v = 0..3) HATPolygonSurfaceFit(...);
    //       v65[0][i] = sub_44B110(v82);
    //       if (v65[0][i]) {
    //         CollisionFaceVerticesGather(v81, v82);
    //         color = RGBColorPacking(v82[0], &v66);
    //         CollisionCapsuleShapeCopyToPipeline(v81, color, &v74);
    //         write fitted height doubles into neighbour vertices;
    //       }
    //     }
    //     CollisionContactBufferAllocator(a3, count);
    //     for (each patch) {
    //       RGBColorPacking(v82[0], &v64);
    //       switch (v65[0][i]) via jpt_44B6EC {
    //         case 0: per-edge gather + TriangleMeshAdjacencyBuilder; break;
    //         case 1..3: 2x AxisPermutationMatrixRead + TriangleMeshAdjacencyBuilder; break;
    //         case 4: CollisionFaceVerticesGather + gather + TriangleMeshAdjacencyBuilder; break;
    //       }
    //     }
    //     PhysicsBufferFree(v69);
    //     if (v65[0]) FreeWrapper_7bcf(v65[0]);
    //     return PhysicsBufferFree(v69);
    //   }
    // UNRESOLVED: The exact meaning of the sub_44B110-derived permutation index (0..4) that drives the jpt_44B6EC switch is not established; the jump table is referenced (global 0x0044B8F4) but its case semantics are inferred from the switch body.
    // UNRESOLVED: The fitted surface-height double arithmetic that writes into neighbour vertex fields uses coefficient registers v74..v79 recovered from raw source only.
}
