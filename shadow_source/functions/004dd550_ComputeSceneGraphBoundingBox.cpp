// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD550
// Canonical corpus name: BoundingBoxComputation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BoundingBoxComputation_004dd550.c

void UnknownObject::ComputeSceneGraphBoundingBox()
{
    // Computes a 3D axis-aligned bounding box of a scene-graph node. Derives a LOD detail threshold via sub_4DD4E0(a1), initializes the min buffer a2 to +FLT_MAX and the max buffer a3 to -FLT_MAX (each a float3), iterates the node's children (SceneGraphChildCount), and for each child that passes a per-child detail-level filter computes the packed-array extent using PackedArrayTotalSize / PackedArrayIndexLookup, folding each vertex into the running min/max. Returns the child count. The min output fields map to offsets 0x0/0x4/0x8 of the caller's min buffer.
    // CALL: Call sub_4DD4E0(a1) to obtain the LOD detail threshold v13 used later to filter children. [callee:0x004DD4E0, source:raw]
    // ASSIGNMENT: Initialize the min buffer a2[0..2] (offsets 0x0/0x4/0x8) to +FLT_MAX (3.4028235e38). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Initialize the max buffer a3[0..2] to -FLT_MAX (-3.4028235e38). [source:raw]
    // CALL: Call SceneGraphChildCount(a1) to obtain the number of child nodes; this value is also the return value. [callee:0x0054C210, source:raw]
    // LOOP: Loop over each child index i from 0 to the child count. [callee:0x0054C210, source:raw]
    // CALL: Call LinkedListIndexedAccessor_c230(i) to resolve child index i to a node pointer v8. [callee:0x0054C230, source:raw]
    // GUARD: Per-child detail check: test the float at (v8 + 244) against the zero threshold flt_59E440; when nonzero the detail level v10 becomes 0. [global:0x0059E440, source:raw]
    // CALCULATION: When the (v8 + 244) float is zero, derive the detail level v10 from node flag bits: (flags & 0x2000000) selects base 2 or 4, then subtract 1 when (flags & 0x40) is set. [source:raw]
    // GUARD: Skip the child when its detail level v10 is below the LOD threshold v13 (v10 < v13). [callee:0x004DD4E0, source:raw]
    // CALL: Call PackedArrayTotalSize(v8) to get the packed-array element count v14 for the child node. [callee:0x0054E100, source:raw]
    // LOOP: Inner do-while loop over packed-array element index v11 from 0 while v11 < v14. [callee:0x0054E100, source:raw]
    // CALL: Call PackedArrayIndexLookup(v11) to resolve the packed element to a float3 vertex pointer v12. [callee:0x0054E120, source:raw]
    // CALCULATION: Fold the vertex into the running minimum: update min X/Y/Z (offsets 0x0/0x4/0x8) when the corresponding vertex component is smaller. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALCULATION: Fold the vertex into the running maximum: update max X/Y/Z when the corresponding vertex component is larger. [source:raw]
    // RETURN: Return the scene-graph child count v15. [callee:0x0054C210, source:raw]

    // Conservative worker pseudocode:
    //   int ComputeSceneGraphBoundingBox(void* node, float* minOut, float* maxOut) {
    //     int detailThreshold = sub_4DD4E0(node);
    //     minOut[0] = minOut[1] = minOut[2] = 3.4028235e38f;
    //     maxOut[0] = maxOut[1] = maxOut[2] = -3.4028235e38f;
    //     int childCount = SceneGraphChildCount(node);
    //     for (int i = 0; i < childCount; ++i) {
    //       void* child = LinkedListIndexedAccessor_c230(i);
    //       int detail;
    //       if (*(float*)(child + 244) == 0.0f) {
    //         int flags = *(DWORD*)(child + 20);
    //         detail = (flags & 0x2000000) ? (2 - ((flags & 0x40) != 0)) : (4 - ((flags & 0x40) != 0));
    //       } else {
    //         detail = 0;
    //       }
    //       if (detail >= detailThreshold) {
    //         int count = PackedArrayTotalSize(child);
    //         for (int j = 0; j < count; ++j) {
    //           float* v = PackedArrayIndexLookup(j);
    //           if (v[0] < minOut[0]) minOut[0] = v[0];
    //           if (v[1] < minOut[1]) minOut[1] = v[1];
    //           if (v[2] < minOut[2]) minOut[2] = v[2];
    //           if (v[0] > maxOut[0]) maxOut[0] = v[0];
    //           if (v[1] > maxOut[1]) maxOut[1] = v[1];
    //           if (v[2] > maxOut[2]) maxOut[2] = v[2];
    //         }
    //       }
    //     }
    //     return childCount;
    //   }
    // UNRESOLVED: Semantics of the sub_4DD4E0 LOD threshold and its numeric meaning relative to the per-child detail level are unknown.
    // UNRESOLVED: Meaning of the child flag bits 0x2000000 and 0x40 and of the float at (child + 244) is unverified.
    // UNRESOLVED: The packed-array element layout (assumed float3 XYZ) is derived, not independently confirmed.
    // UNRESOLVED: Relationship between the scene-graph child list (LinkedListIndexedAccessor_c230) and the packed-array storage (PackedArrayIndexLookup) is not established.
}
