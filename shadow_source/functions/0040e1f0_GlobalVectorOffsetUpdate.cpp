// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0040E1F0
// Canonical corpus name: GlobalVectorOffsetUpdate
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/GlobalVectorOffsetUpdate_0040e1f0.c

void UnknownObject::GlobalVectorOffsetUpdate()
{
    // Iterates every scene-graph child (linked list), and for each child walks its packed vertex array subtracting a 3-component offset vector (a2[0..2]) from every vertex. Afterwards clears two bits in the child's flag word at +20, recomputes the bounding box (extents then full recompute from vertex data), and invokes a post-processing helper. Returns the last processed child index. Used to shift whole scene-graph objects by a global offset on frame paths.
    // CALL: Query the scene-graph child count via SceneGraphChildCount (0x0054C210) and store it as the outer loop bound v9. [callee:0x0054C210, source:raw]
    // LOOP: Outer loop over scene-graph children: for (i = 0; i < v9; ++i). [source:raw]
    // CALL: Fetch child i with LinkedListIndexedAccessor_c230 (0x0054C230) into v4. [callee:0x0054C230, source:raw]
    // CALL: Query the child's packed-array element count with PackedArrayTotalSize (0x0054E100) as the inner loop bound v5. [callee:0x0054E100, source:raw]
    // LOOP: Inner loop over packed-array vertices: for (j = 0; j < v5; ...), retrieving each element via PackedArrayIndexLookup (0x0054E120) into v7. [callee:0x0054E120, source:raw]
    // CALCULATION: Subtract the offset vector from the current vertex: v7[0] -= a2[0] (field 0x0); v7[1] -= a2[1] (field 0x4); and as the loop increment v7[2] -= a2[2] (field 0x8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Clear two bits in the child's flag DWORD at v4 + 20 with the mask 0xFEFFFFDF. [source:raw]
    // CALL: Recompute the child's 3D bounding-box extents via F_3DBoundingBoxExtentsComputation (0x0054D520) with a COERCE_FLOAT(1) argument. [callee:0x0054D520, source:raw]
    // CALL: Rebuild the child's bounding box from vertex data via BoundingBoxComputationFromVertexData (0x0054E270) on v4. [callee:0x0054E270, source:raw]
    // CALL: Invoke the unknown post-processing helper sub_54D080 (0x0054D080) with argument 0. [callee:0x0054D080, source:raw]
    // ASSIGNMENT: Record result = i + 1 so the function returns the last processed child index. [source:raw]
    // RETURN: Return the last processed child index (result), which is 0 when no children were processed. [function:0x0040E1F0, source:raw]
    // CALL: Invoked on frame paths by AudioPhysicsMixWithLerp (0x0040E2B0) and VehicleSceneLoadAndPositionTires (0x004681B0) to shift scene-graph geometry by a global offset. [caller:0x0040E2B0, caller:0x004681B0, source:raw]

    // Conservative worker pseudocode:
    //   int sub_40E1F0(int a1, float *a2) {
    //     int v9 = SceneGraphChildCount();
    //     for (int i = 0; i < v9; ++i) {
    //       int v4 = LinkedListIndexedAccessor_c230(i);
    //       int v5 = PackedArrayTotalSize(v4);
    //       for (int j = 0; j < v5; ++j) {
    //         float *v7 = (float *)PackedArrayIndexLookup(j);
    //         *v7 -= a2[0];
    //         v7[1] -= a2[1];
    //         v7[2] -= a2[2];
    //       }
    //       *(DWORD *)(v4 + 20) &= 0xFEFFFFDF;
    //       F_3DBoundingBoxExtentsComputation(1.0f);
    //       BoundingBoxComputationFromVertexData(v4);
    //       sub_54D080(0);
    //     }
    //     return v9 ? v9 : 0;
    //   }
    // UNRESOLVED: Purpose of the unused first argument a1 is unknown; it may be a vestigial this/context pointer.
    // UNRESOLVED: The two bits cleared by the 0xFEFFFFDF mask on v4+20 are not interpreted (likely dirty/validity flags of the vertex data).
    // UNRESOLVED: Role of sub_54D080's argument 0 and its exact post-processing behavior are not documented in this function.
    // UNRESOLVED: The flag-clear store targets a child offset (+20) that has no packet field evidence reference.
}
