// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044B110
// Canonical corpus name: sub_44B110
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44B110_0044b110.c

void UnknownObject::CollisionFaceProximityAxisSelector()
{
    // Proximity-based axis selector for a collision pipeline. Packs the first field of the input struct as an RGB color identifier, gathers the triangle-face vertices, copies the capsule shape into the pipeline buffer, then tests each face edge against the capsule. Counts how many edges pass the proximity test: more than one pass returns 0 (ambiguous), zero passes runs a three-way fallback that returns 4 when every edge still passes, otherwise a single resolved edge selects a permutation axis (2 or 3) read via AxisPermutationMatrixRead and re-validated with a final two-edge proximity check that retries the whole selection on failure.
    // CALL: Pack the first DWORD of the input struct a1 as an RGB color identifier into the stack color buffer v15, reading field this+0x0. [callee:0x00448EE0, field:this:0x00000000]
    // CALL: Gather the six coordinate values from the three triangle-face vertices of a1 into the stack array v16. [callee:0x0044AF20]
    // CALL: Copy the capsule collision shape from v16/v15 into the pipeline buffer v17 for proximity testing. [callee:0x0044B040]
    // LOOP: Loop over three face edges: clear the per-edge pass flag byte, then while TriangleProximityTest on the edge (a1 offset 4 within 23-DWORD stride rows) against pipeline buffer v17 passes, advance the edge cursor; on exhaustion record the edge as passing and increment the pass count v10. [callee:0x0044B090]
    // GUARD: If the pass count v10 is greater than 1, the result is ambiguous: return 0 immediately. [source:raw]
    // GUARD: If no edge passed (v10 == 0), enter the three-way fallback loop: test each edge against the next edge in the cycle; if all three pass consecutively return 4 (edge-fallback marker), otherwise the first failing edge sets the retry state v11/v12. [callee:0x0044B090]
    // LOOP: Scan the per-edge pass byte array to locate the first edge that passed proximity; if none is found return 0. [source:raw]
    // STATE_TRANSITION: Select the axis permutation based on the resolved passing edge: edge 0 maps to permutation 2 with edge pair (v1=0, v3=1, v14=2); edge 1 maps to permutation 2 via AxisPermutationMatrixRead(v16, a1, 2, 0) with pair (v1=1, v3=2, v14=0); edge 2 maps to permutation 3 via AxisPermutationMatrixRead(v16, a1, 3, 0) with pair (v1=2, v3=0, v14=1). [callee:0x0044AF60]
    // CALL: Re-copy the capsule shape into the pipeline buffer after the permutation matrix has been read, refreshing v17 for the final proximity check. [callee:0x0044B040]
    // GUARD: Final two-edge proximity check: if the primary edge fails, or after reading the transposed permutation via AxisPermutationMatrixRead(v16, a1, v10, 1) and refreshing the buffer the secondary edge fails, retry from the edge scan loop. [callee:0x0044AF60, callee:0x0044B090]
    // RETURN: Return the resolved permutation axis index v10 once both edges of the selected axis pass proximity. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_44B110(int *face) {
    //     int v15; _DWORD verts[6]; _DWORD pipeline[23];
    //     RGBColorPacking(*face, &v15);
    //     CollisionFaceVerticesGather(verts, face);
    //     CollisionCapsuleShapeCopyToPipeline(verts, &v15, pipeline);
    //     int passed[3] = {0}; int passCount = 0;
    //     for (int e = 0; e < 3; ++e) {
    //       int cursor = e;
    //       while (TriangleProximityTest(&face[23 * (cursor == 3 ? 0 : cursor) + 4],
    //                                    pipeline, *(face[cursor == 3 ? 0 : cursor] + 8 * e + 4))) {
    //         if (++cursor >= ???) break;
    //       }
    //       passed[e] = 1; ++passCount;
    //     }
    //     if (passCount > 1) return 0;
    //     if (passCount == 0) {
    //       for (int e = 0; ; ) {
    //         int next = e == 2 ? 0 : e + 1;
    //         if (!TriangleProximityTest(&face[23 * e + 4], pipeline, *(face[e] + 8 * next + 4))) break;
    //         if (++e >= 3) return 4;
    //       }
    //       // fallback retry state seeded
    //     }
    //     int pick = 0;
    //     while (!passed[pick]) { if (++pick >= 3) return 0; }
    //     int axis; int v1, v3, v14;
    //     if (pick == 0)      { axis = 2; v1 = 0; v3 = 1; v14 = 2; }
    //     else if (pick == 1) { axis = 2; v1 = 1; v3 = 2; v14 = 0; AxisPermutationMatrixRead(verts, face, 2, 0); }
    //     else                { axis = 3; v1 = 2; v3 = 0; v14 = 1; AxisPermutationMatrixRead(verts, face, 3, 0); }
    //     CollisionCapsuleShapeCopyToPipeline(verts, &v15, pipeline);
    //     if (!TriangleProximityTest(&face[23 * v1 + 4], pipeline, *(face[v1] + 8 * v3 + 4)) ||
    //         (AxisPermutationMatrixRead(verts, face, axis, 1),
    //          CollisionCapsuleShapeCopyToPipeline(verts, &v15, pipeline),
    //          !TriangleProximityTest(&face[23 * v3 + 4], pipeline, *(face[v3] + 8 * v14 + 4))))
    //       goto edge_scan_retry;
    //     return axis;
    //   }
    // UNRESOLVED: The exact loop bound for the per-edge proximity while loop (v4) is not restored by the decompiler and its retry semantics are ambiguous.
    // UNRESOLVED: Whether the returned index selects a response axis or a permutation of collision normals depends on the caller BezierPatchTessellation (0x0044B370).
    // UNRESOLVED: The v11/v12 fallback retry state seeded when no edge passes is an unconfirmed edge case.
}
