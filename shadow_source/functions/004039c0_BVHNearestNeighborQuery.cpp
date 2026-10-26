// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004039C0
// Canonical corpus name: BVHNearestNeighborQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BVHNearestNeighborQuery_004039c0.c

void UnknownObject::BVHNearestNeighborQuery()
{
    // Nearest-neighbor traversal over a linked chain of physics nodes. Computes the squared distance from the query position (this+0/4/8) to the first node, then walks node+272 child links while the cumulative path length (sum of node+60 values) stays below 200.0 (flt_59E470). Descends when a child's squared distance is strictly smaller than the current best; early-outs and returns the current node otherwise, or returns the child immediately when it has no further child. A null start node returns itself unchanged. Called by AISteering (004270A0).
    // GUARD: Null guard: when a2 (start node) is 0 the function returns a2 immediately without traversing [source:raw]
    // CALCULATION: Seed squared distance v15 from the query position this+0/4/8 against the first node's position fields (node+148/152/156) [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, source:raw]
    // LOOP: Chain traversal: while the current node has a child at node+272, accumulate node+60 into the path length v16, compute the child's squared distance, and descend when it is strictly below the current best v15 [source:raw]
    // GUARD: Path-length guard: traversal stops when the accumulated path length v16 exceeds 200.0, the threshold held by flt_59E470 [global:0x0059E470, source:raw]
    // GUARD: Spatial-culling guard: when the child's squared distance is >= the current best v15, traversal stops and the current node is returned [source:raw]
    // RETURN: Returns the closest node v4, or the child v10 immediately when that child has no further child at node+272; the function is called by AISteering (004270A0) [function:0x004039C0, caller:0x004270A0, source:raw]

    // Conservative worker pseudocode:
    //   if (a2 == 0) return a2;
    //   v15 = dist_sq(a1, a2+148, a2+152, a2+156);
    //   v4 = a2; v16 = 0.0;
    //   while (true) {
    //     v16 += *(v4 + 60);
    //     if (v16 > 200.0) break;
    //     v10 = *(v4 + 272); if (!v10) break;
    //     child_sq = dist_sq(a1, v10+148, v10+152, v10+156);
    //     if (child_sq >= v15) break;
    //     v15 = child_sq; v4 = v10;
    //     if (!*(v10 + 272)) return v10;
    //   }
    //   return v4;
    // UNRESOLVED: Node layout offsets (+60 path length, +148/152/156 position, +272 child link) are read from raw source but are not flagged as packet fields; whether +272 is a child pointer or a sibling link is inferred from the existing analysis and not provable from this packet alone
    // UNRESOLVED: The meaning of the 200.0 bound (flt_59E470) as a search radius is DERIVED; the raw source only compares the accumulated path length against it
}
