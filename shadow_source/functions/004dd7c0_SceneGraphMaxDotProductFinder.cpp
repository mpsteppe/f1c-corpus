// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004DD7C0
// Canonical corpus name: sub_4DD7C0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4DD7C0_004dd7c0.c

void UnknownObject::SceneGraphMaxDotProductFinder()
{
    // Finds the scene-graph vertex whose dot product with a direction vector (a2) is maximal and stores its coordinates in a3. Iterates the node's children (SceneGraphChildCount / LinkedListIndexedAccessor_c230), filters each child by a LOD level derived from dword flags compared against a threshold from sub_4DD4E0, then scans the child's packed vertex array (PackedArrayTotalSize / PackedArrayIndexLookup). Returns the child count.
    // CALL: Compute the LOD threshold: v17 = sub_4DD4E0(a1). [callee:0x004DD4E0, source:raw]
    // ASSIGNMENT: Initialize the output vector a3[0..2] to 0.0 and cache the direction vector a2 components into locals v20 (a2[0]), v22 (a2[1]), v21 (a2[2]). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // CALL: v18 = SceneGraphChildCount(a1) returns the number of child nodes. [callee:0x0054C210, source:raw]
    // LOOP: Iterate over children i from 0 to the child count v18. [callee:0x0054C210, callee:0x0054C230, source:raw]
    // CALL: v7 = LinkedListIndexedAccessor_c230(i) retrieves the i-th child node. [callee:0x0054C230, source:raw]
    // GUARD: Compute the child's LOD level v9: when the float at child+244 is 0.0, derive it from the dword flags at child+20 ((flags & 0x2000000) ? 2 - ((flags & 0x40) != 0) : 4 - ((flags & 0x40) != 0)); otherwise v9 = 0. [source:raw]
    // GUARD: Skip the child's vertices unless its LOD level v9 is >= the threshold v17. [callee:0x004DD4E0, source:raw]
    // CALL: v10 = PackedArrayTotalSize(v7) returns the vertex count of the child's packed array. [callee:0x0054E100, source:raw]
    // LOOP: Iterate over vertices j from 0 to the packed array size v10. [callee:0x0054E120, source:raw]
    // CALL: v12 = PackedArrayIndexLookup(j) retrieves the j-th vertex as a float pointer. [callee:0x0054E120, source:raw]
    // CALCULATION: v13 = v12[0]*v20 + v12[2]*v21 + v12[1]*v22, the dot product of the vertex with the direction vector. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // GUARD: When v13 exceeds the current best v19, adopt this vertex as the new extreme point. [source:raw]
    // ASSIGNMENT: Update the best dot product v19 = v13 and write the winning vertex coordinates to a3[0..2]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // RETURN: Return the child count v18. [source:raw]

    // Conservative worker pseudocode:
    //   int SceneGraphMaxDotProductFinder(void *node, float *dir, float *out) {
    //     int lodThreshold = sub_4DD4E0(node);
    //     out[0] = out[1] = out[2] = 0.0f;
    //     float dirX = dir[0], dirY = dir[1], dirZ = dir[2];
    //     float bestDot = 0.0f;
    //     int count = SceneGraphChildCount(node);
    //     for (int i = 0; i < count; ++i) {
    //       int child = LinkedListIndexedAccessor_c230(i);
    //       int lod;
    //       if (*(float *)(child + 244) == 0.0f) {
    //         int flags = *(_DWORD *)(child + 20);
    //         lod = (flags & 0x2000000) ? 2 - ((flags & 0x40) != 0) : 4 - ((flags & 0x40) != 0);
    //       } else {
    //         lod = 0;
    //       }
    //       if (lod >= lodThreshold) {
    //         int n = PackedArrayTotalSize(child);
    //         for (int j = 0; j < n; ++j) {
    //           float *v = PackedArrayIndexLookup(j);
    //           float dot = v[0] * dirX + v[2] * dirZ + v[1] * dirY;
    //           if (dot > bestDot) {
    //             bestDot = dot;
    //             out[0] = v[0]; out[1] = v[1]; out[2] = v[2];
    //           }
    //         }
    //       }
    //     }
    //     return count;
    //   }
    // UNRESOLVED: Global flt_59E440 (0x0059E440) is listed as a referenced global but does not appear in the raw source text; its role is ungrounded.
    // UNRESOLVED: Semantics of the child-node LOD flags (0x2000000, 0x40) and of the zero-compare at child+244 are unknown; values are preserved from raw source only.
}
