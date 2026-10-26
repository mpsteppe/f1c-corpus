// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0054A340
// Canonical corpus name: SpatialTreeNearestNeighborQuery
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpatialTreeNearestNeighborQuery_0054a340.c

void UnknownObject::SpatialTreeNearestNeighborQuery()
{
    // Finds the nearest spatial object to a 3D query point that also passes a 6-plane frustum visibility test, and stores it in the cached result slot this[105] (this+0x1A4). The query direction a2 is negated (a2[9..11]) to build signed plane tests. Primary path walks the spatial tree rooted at this+0x2A0: the tree node chain is traversed via the child object pointer at node+0x10 and the next-sibling pointer at node+0x14; each child is accepted when its bounding-sphere squared distance beats the current best and all 6 plane dot products at +0x8C/+0x90/+0x94 are negative (inside the frustum). If the tree is absent, a fallback linear walk of an inline linked list (head this[64] = this+0x100, next pointer at node+0x104) is used instead, with the same sphere-distance and 6-plane acceptance test.
    // ASSIGNMENT: Read the cached best-result pointer v2 = this[105] (this+0x1A4); initialize the fallback best v3 = 0, the best squared distance v26 = 9.9999997e37, the fallback list head v4 = this[64] (this+0x100), and the negated query components v24 = -a2[9], v25 = -a2[10], v28 = -a2[11]. [field:this:0x000001A4, field:this:0x00000100, source:raw]
    // GUARD: Guard on the tree root at this+0x2A0 being null; if no tree exists, skip the tree walk and go to the fallback linear-list walk. [field:this:0x000002A0, source:raw]
    // GUARD: Guard on residual CPU status flags v6/v7 (c0/c3) left from an earlier comparison: when both are clear, keep the cached result v2, write it back to this[105] and return it early without re-searching. [field:this:0x000001A4, source:raw]
    // ASSIGNMENT: Load the tree child-list head v9 = *(tree_node + 252), which resolves to *(this + 0x1A4 + 252) = *(this + 0x2A0); if non-null, enter the tree walk. [field:this:0x000002A0, source:raw]
    // LOOP: Tree walk over the node chain: each iteration reads the child object pointer v11 = *(node + 16) (child at node+0x10) and advances v10 = *(node + 20) (next sibling at node+0x14). [field:*(this+0x2A0):0x00000010, field:*(*(this+0x2A0)+0x14):0x00000014, source:raw]
    // CALCULATION: Compute squared distance from the negated query point to the child's bounding-sphere center at v11[31..33] (offsets +0x7C/+0x80/+0x84): v15 = (v28 - z)^2 + (v25 - y)^2 + (v24 - x)^2. [field:*(*(this+0x2A0)+0x10):0x0000007C, field:*(*(this+0x2A0)+0x10):0x00000080, field:*(*(this+0x2A0)+0x10):0x00000084, source:raw]
    // GUARD: If the candidate distance v15 improves on the best v26, run the 6-plane frustum test: for each of the 6 planes, accumulate the dot product of the negated query point against the plane data at +0x8C/+0x90/+0x94 and break out of the inner loop when any plane rejects (dot product >= 0.0). [field:*(*(this+0x2A0)+0x10):0x0000008C, field:*(*(this+0x2A0)+0x10):0x00000090, field:*(*(this+0x2A0)+0x10):0x00000094, source:raw]
    // ASSIGNMENT: When all 6 planes accept (inner counter v16 reaches 6), record the best distance v26 = v15 and the best result v3 = the child object pointer. [field:*(this+0x2A0):0x00000010, source:raw]
    // ASSIGNMENT: After the tree walk, store the best result v3 into this[105] and return it. [field:this:0x000001A4, source:raw]
    // LOOP: Fallback linear walk of the inline linked list: v4 starts at this[64] (this+0x100); each iteration reads the next node from *(node + 260) (the next pointer at node+0x104, which for the inline first node lives at this+0x204). [field:this:0x00000104, field:*(this+0x204):0x00000104, source:raw]
    // GUARD: Skip inactive nodes: the node is only tested when the flag byte at node+4 masked with 0x40 is zero. [source:raw]
    // CALCULATION: Compute squared distance to the inline node's bounding sphere: v27 = (v28 - z)^2 + (v25 - y)^2 + (v24 - x)^2 using the center at node+0x7C/+0x80/+0x84 and the radius at node+0x18; accept only if v27 is below radius squared (node+24 squared) and below the current best v26. [field:this:0x00000118, field:this:0x0000017C, field:this:0x00000180, field:this:0x00000184, source:raw]
    // GUARD: Run the same 6-plane frustum test on the inline node using its plane data at node+0x8C/+0x90/+0x94, breaking out of the inner loop when any plane rejects the negated query point. [field:this:0x0000018C, field:this:0x00000190, field:this:0x00000194, source:raw]
    // ASSIGNMENT: When all 6 planes accept (inner counter v22 reaches 6), record the best distance v26 = v27 and the best result v3 = v4. [source:raw]
    // ASSIGNMENT: After the fallback walk, store the best result v3 into this[105] and return it. [field:this:0x000001A4, source:raw]

    // Conservative worker pseudocode:
    //   int sub_54A340(_DWORD *this, float *query) {
    //     int best = 0;
    //     float best_dist = 9.9999997e37;
    //     float nx = -query[9], ny = -query[10], nz = -query[11];
    //     int tree_root = *(int *)(this[105] + 252); /* == *(int *)(this + 0x2A0) * /
    //     if (tree_root) {
    //       int node = tree_root;
    //       do {
    //         float *child = *(float **)(node + 16);
    //         float d2 = (nz - child[33]) * (nz - child[33])
    //                  + (ny - child[32]) * (ny - child[32])
    //                  + (nx - child[31]) * (nx - child[31]);
    //         if (d2 < best_dist) {
    //           int i = 0;
    //           float *p = child + 35;
    //           do {
    //             if (nz * p[1] + nx * *(p - 1) + ny * *p + p[2] >= 0.0) break;
    //             ++i; p += 4;
    //           } while (i < 6);
    //           if (i == 6) { best_dist = d2; best = *(int *)(node + 16); }
    //         }
    //         node = *(int *)(node + 20);
    //       } while (node);
    //     } else {
    //       int node = this[64];
    //       while (node) {
    //         if ((*(unsigned char *)(node + 4) & 0x40) == 0) {
    //           float d2 = (nz - *(float *)(node + 132)) * (nz - *(float *)(node + 132))
    //                    + (ny - *(float *)(node + 128)) * (ny - *(float *)(node + 128))
    //                    + (nx - *(float *)(node + 124)) * (nx - *(float *)(node + 124));
    //           if (d2 < *(float *)(node + 24) * *(float *)(node + 24) && d2 < best_dist) {
    //             int i = 0;
    //             float *p = (float *)(node + 140);
    //             do {
    //               if (nz * p[1] + nx * *(p - 1) + ny * *p + p[2] >= 0.0) break;
    //               ++i; p += 4;
    //             } while (i < 6);
    //             if (i == 6) { best_dist = d2; best = node; }
    //           }
    //         }
    //         node = *(int *)(node + 260);
    //       }
    //     }
    //     this[105] = best;
    //     return best;
    //   }
    // UNRESOLVED: The global dbl_59E430 is listed as read by this function but does not appear in the raw pseudocode; the constant may have been folded into the FLT_MAX sentinel 9.9999997e37 by Hex-Rays.
    // UNRESOLVED: The residual CPU-status-flag guard (v6|c0 and v7|c3, both unsigned __int8) cannot be reconstructed into a source-level comparison from the pseudocode; the early-return condition it gates is unknown beyond keeping the cached result.
    // UNRESOLVED: The exact meaning of the 0x40 flag in the node+4 byte (inactive/active bit) is inferred from the skip behavior, not proven.
    // UNRESOLVED: Caller sub_556E70 semantics and the query-point layout a2[9..11] (query position/direction selection) are not recoverable here.
}
