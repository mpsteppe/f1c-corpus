// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004E2D00
// Canonical corpus name: VertexClusteringLODGrouping
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/VertexClusteringLODGrouping_004e2d00.c

void UnknownObject::VertexClusteringLODGrouping()
{
    // Scene-graph vertex clustering for LOD generation. Zeroes four per-cluster work slots, selects a working scene-graph child, counts vertices per cluster by nearest reference position (block at this+0x150, 74-dword stride), allocates per-cluster packed arrays, then writes each vertex into its cluster array with a projected normal and a clamped LOD blend weight. Called by VehicleGraphicsSceneLoader.
    // ASSIGNMENT: Initialize local sentinels for per-vertex nearest-distance tracking (FLT_MAX-style values, 2139095039) and reset the found-cluster index. [source:raw]
    // LOOP: Cluster init loop over the 4 cluster work slots (74-dword stride starting at this+125 dwords): zero the per-cluster array pointer at this+0x1F4 and the slot at this+0x1F8, saving a copy of each cluster entry's first dword (block at this+0x150) into this+0x1F8. [field:this:0x000001F4, field:this:0x000001F8, field:this:0x00000150]
    // ASSIGNMENT: Read the scene-graph node pointer this[548] (this+0x890) and clear the found-child slot this[569] (this+0x8E4) to 0. [field:this:0x00000890, field:this:0x000008E4]
    // GUARD: Only proceed when the scene-graph node pointer at this+0x890 is non-null. [field:this:0x00000890]
    // CALL: Call SceneGraphChildCount on the scene-graph node to obtain its child count. [callee:0x0054C210]
    // LOOP: Iterate the children, fetching each child via LinkedListIndexedAccessor_c230; select the first child whose vertex position value (child+244 dwords) is zero (zero-threshold test, global flt_59E440) and store it as the working node at this+0x8E4. [callee:0x0054C230, field:this:0x000008E4, global:0x0059E440]
    // GUARD: Only proceed when a working child node was found (this+0x8E4 non-null). [field:this:0x000008E4]
    // CALL: Call PackedArrayTotalSize on the working node to get the total vertex count v39. [callee:0x0054E100]
    // LOOP: First vertex pass: fetch each vertex via PackedArrayIndexLookup, compute squared 3D distance to each of the 4 cluster reference positions (block at this+0x150), and record the nearest cluster plus a running minimum |x| used to size the LOD radius. [callee:0x0054E120, field:this:0x00000150]
    // CALCULATION: Increment the nearest cluster's vertex tally (the per-cluster count block alongside this+0x1F4) and update the cluster's minimum |x| value. [field:this:0x000001F4]
    // ASSIGNMENT: Replace the per-cluster distance sentinels (1036831949) with small initial radius values before array allocation. [source:raw]
    // LOOP: Allocation loop over 4 clusters: call OperatorNewNhMallocWrapper(32 * clusterCount) and store the returned packed-array pointer at the cluster's this+0x1F4 slot. [callee:0x00587C03, field:this:0x000001F4]
    // LOOP: Second vertex pass: re-fetch each vertex via PackedArrayIndexLookup, recompute its nearest cluster by 3D distance to the reference block at this+0x150, write x/y/z into the cluster's packed array (32-byte stride, offset by current count at this+0x1F4 region), project the vertex onto the cluster transform rows to build a normal at +12..+20, and store the source vertex pointer at +28. [callee:0x0054E120, field:this:0x00000150, field:this:0x000001F4]
    // CALCULATION: Compute the per-vertex LOD blend weight at +24 from |x| against the cluster's minimum |x| with a small slack term (0.090000004 literal); global flt_5AD15C is read as a threshold in this vertex/LOD pipeline. [global:0x005AD15C]

    // Conservative worker pseudocode:
    //   void VertexClusteringLODGrouping(DWORD *this) {
    //     for (int c = 0; c < 4; ++c) {
    //       this[124 + 74*c] = 0;
    //       this[125 + 74*c] = 0;
    //       this[126 + 74*c] = this[84 + 74*c];
    //     }
    //     this[569] = 0;
    //     if (DWORD sg = this[548]) {
    //       int n = SceneGraphChildCount(sg);
    //       for (int i = 0; i < n; ++i) {
    //         DWORD child = LinkedListIndexedAccessor_c230(i);
    //         if (*(float*)(child + 244) == 0.0f) { this[569] = child; break; }
    //       }
    //       if (DWORD node = this[569]) {
    //         int total = PackedArrayTotalSize(node);
    //         for (int vi = 0; vi < total; ++vi) {
    //           float *v = PackedArrayIndexLookup(vi);
    //           // nearest of 4 reference positions at this+0x150
    //           // ++count[cluster]; minAbsX[cluster] = min(minAbsX[cluster], |v[0]|);
    //         }
    //         for (int c = 0; c < 4; ++c)
    //           this[125 + 74*c] = OperatorNewNhMallocWrapper(32 * count[c]);
    //         for (int j = 0; j < total; ++j) {
    //           float *v = PackedArrayIndexLookup(j);
    //           int c = nearestCluster(v);
    //           float *out = this[125 + 74*c] + 32 * this[124 + 74*c]++;
    //           out[0] = v[0]; out[1] = v[1]; out[2] = v[2];
    //           // out[3..5] = transform(c) * (v - center(c));
    //           out[7] = v;
    //           out[6] = clamp((|v[0]| - minAbsX[c]) / slack, 0, 1);
    //         }
    //       }
    //     }
    //   }
    // UNRESOLVED: Exact layout of the 74-dword cluster entry at this+0x150 is inferred: center positions are read at this+82..84 dwords and transform rows at this+88..96 dwords, but only this+0x150 is listed as a packet field.
    // UNRESOLVED: The precise meaning of the child vertex-position zero test at child+244 dwords is unverified.
    // UNRESOLVED: Global thresholds flt_59E440 and flt_5AD15C are read per the packet, but the decompiler inlined their uses, so the exact comparison each feeds is not observable in the pseudocode.
    // UNRESOLVED: Behavior for a scene graph with no qualifying child node is untraced beyond the guard on this+0x8E4.
}
