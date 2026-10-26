// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549470
// Canonical corpus name: sub_549470
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_549470_00549470.c

void UnknownObject::ComputeOBBAndBoundingSphere()
{
    // Computes an oriented bounding box (OBB) and bounding sphere from scene-graph mesh vertex data reachable through the node object at this+0xEC. Pass 1 walks the mesh-entry linked list (head at node+0x204, entries linked at +0x10) accumulating per-vertex sums, sum-of-squares and cross products, then normalizes them into a centered covariance matrix and factors it with QRDecomposition to obtain the orientation axes. Pass 2 walks the same geometry again, transforms every vertex into the local frame (optionally through an indirect D3D transform via dword_8B8F24 when flag bit 0x10 at node+0x3C is set), tracks per-axis min/max, and writes the 8 OBB corners plus the center into this+0x1C..this+0x70 and this+0x7C. Pass 3 measures the farthest squared distance from the center (this+0x7C..this+0x84) and stores sqrt as the bounding-sphere radius at this+0x18. A final loop builds the 6 OBB face planes (normalized edge cross products) anchored at this+0x8C and returns a pointer there. Called per audio node from the audio engine initialization pipeline (00546010).
    // ASSIGNMENT: v2 = *((_DWORD*)this + 59); load the node/mesh object pointer from this+0xEC. [field:this:0x000000EC]
    // ASSIGNMENT: Zero the nine covariance accumulators (sum-of-squares and cross-product terms) before pass 1. [source:raw]
    // GUARD: Guard: pass 1 runs only if the node pointer v2 (this+0xEC) is non-null. [field:this:0x000000EC, source:raw]
    // LOOP: Walk the node sibling chain: after each node, advance v2 to the next sibling via the next pointer at node+0x4C; stop when it is null. [field:*(this+0xEC):0x0000004C, source:raw]
    // LOOP: Walk the mesh-entry linked list: head at *(node+0x204), next entry pointer at entry+0x10. [field:*(this+0xEC):0x00000204, field:*(*(this+0xEC)+0x204):0x00000010]
    // LOOP: Iterate the vertex sub-buffers of a mesh entry: count at entry+0x118, sub-buffer array pointer at entry+0x11C. [field:*(*(this+0xEC)+0x204):0x00000118, field:*(*(this+0xEC)+0x204):0x0000011C]
    // GUARD: Guard: a sub-buffer is processed only when its vertex count at +0x128 is greater than 0. [guard:0, field:*(*(this+0xEC)+0x204):0x00000128]
    // LOOP: Vertex loop: each vertex base is read at sub-buffer +0x12C and the pointer strides 48 bytes per vertex. [field:*(*(this+0xEC)+0x204):0x0000012C, source:raw]
    // GUARD: Guard: when flag bit 0x10 at node+0x3C is set, each vertex is first transformed through an indirect D3D coordinate-space call on the object at dword_8B8F24 (vtable slot at +4) using the matrix at node+416. [field:*(this+0xEC):0x0000003C, global:0x008B8F24, source:raw]
    // CALCULATION: Accumulate covariance terms per vertex: x*x, y*y, z*z, x*y, x*z, y*z into the sum-of-squares accumulators, and x, y, z into the sum accumulators. [source:raw]
    // ASSIGNMENT: Accumulate the total vertex count v69 by adding each sub-buffer's vertex count. [source:raw]
    // CALCULATION: After pass 1: v13 = 1.0/v69; compute the centered covariance matrix (v89..v97) by scaling the squared sums by v13 and subtracting the squared scaled means. [source:raw]
    // CALL: Call QRDecomposition(&v89, v99, v98) to factor the covariance matrix; the rotation matrix result is placed in v98. [callee:0x0053B6F0, source:raw]
    // CALCULATION: Build a 4x4 rotation matrix v85 from the QR result v98 and copy it into the local matrix v100. [source:raw]
    // ASSIGNMENT: Pass 2 init: reset the per-axis AABB extremes to +-9.99999995904e11 using the bound constant globals. [global:0x0059E420, global:0x0059E880, source:raw]
    // LOOP: Pass-2 walk of the same node sibling chain and mesh-entry linked list (node+0x4C next, head at node+0x204, entry next at +0x10). [field:*(this+0xEC):0x0000004C, field:*(this+0xEC):0x00000204, field:*(*(this+0xEC)+0x204):0x00000010]
    // GUARD: Guard: pass-2 vertex transforms run through the indirect D3D call on dword_8B8F24 into the local matrix v100 when flag bit 0x10 at node+0x3C is set. [field:*(this+0xEC):0x0000003C, global:0x008B8F24, source:raw]
    // CALCULATION: Track per-axis minima and maxima (x in v77/v78, y in v81/v80, z in v79/v82) across all transformed vertices. [source:raw]
    // LOOP: Compute the 8 OBB corners (each a min/max coordinate combination transformed by the indirect D3D call on dword_8B8F24 with the rotation matrix v85) into this+0x1C..this+0x70, and the center (per-axis midpoints) into this+0x7C. [global:0x008B8F24, field:this:0x0000007C, source:raw]
    // LOOP: Pass-3 walk of the mesh geometry: for every vertex compute the squared distance from the center at this+0x7C, this+0x80, this+0x84 and keep the maximum. [field:*(this+0xEC):0x00000204, field:*(*(this+0xEC)+0x204):0x00000010, field:this:0x0000007C, field:this:0x00000080, field:this:0x00000084]
    // GUARD: Guard: pass-3 vertices are also pre-transformed via the indirect D3D call on dword_8B8F24 when flag bit 0x10 at node+0x3C is set. [field:*(this+0xEC):0x0000003C, global:0x008B8F24, source:raw]
    // ASSIGNMENT: v1[6] = sqrt(max squared distance); write the bounding-sphere radius into this+0x18. [field:this:0x00000018, source:raw]
    // LOOP: Build the 6 OBB face planes: for each face read three corner indices from the corner index table, compute the cross product of two edges, normalize it, and write the normalized normal plus the plane offset (negative dot product with the face point) into the plane-result block beginning at this+0x8C. [field:this:0x0000008C, field:this:0x00000090, source:raw]
    // RETURN: Return the pointer to the first plane result at this+0x8C. [source:raw, function:0x00549470]

    // Conservative worker pseudocode:
    //   float* ComputeOBBAndBoundingSphere(float* this) {
    //     node = *((_DWORD*)this + 59);   // this+0xEC
    //     zero the 9 covariance accumulators; total = 0;
    //     if (node) {
    //       do {
    //         for (entry = *(node + 0x204); entry; entry = entry[4])
    //           for (sb = 0; sb < entry[0x118/4]; ++sb) {
    //             for (v = 0; v < *(subbuf+sb + 8); ++v) {
    //               p = (float*)(*(subbuf+sb + 12) + 48*v);
    //               if (*(node+0x3C) & 0x10) D3DXform(p, node+416, dword_8B8F24);
    //               acc x, y, z, x*x, y*y, z*z, x*y, x*z, y*z;
    //             }
    //             total += *(subbuf+sb + 8);
    //           }
    //         node = *(node + 0x4C);
    //       } while (node);
    //     }
    //     scale accumulators by 1/total, subtract mean terms;
    //     QRDecomposition(&cov, tmp, rot);
    //     build 4x4 rotation from rot;
    //     re-init AABB extremes to +-9.99999995904e11;
    //     walk mesh list again; transform each vertex (flag 0x10 -> D3D) and track min/max;
    //     corners[8] = D3D(transform of each min/max combination);  this[7..28] = corners;
    //     this[0x7C/4] = midpoint of extremes;
    //     walk mesh list; maxd2 = max over vertices of |p - center|^2;
    //     this[0x18/4] = sqrt(maxd2);
    //     for (face = 0; face < 6; ++face) {
    //       pick 3 corner indices;  n = normalize(cross(e1, e2));
    //       write n and -dot(n, facePoint) into the plane-result block;
    //     }
    //     return this + 0x8C;
    //   }
    // UNRESOLVED: Field *(*(this+0xEC)+0x204)+0x20 is listed as accessed by the deterministic extractor but has no direct read in the raw source; its role is unknown.
    // UNRESOLVED: Field *(*(this+0xEC)+0x4C)+0x4C (a dereference of the sibling pointer) is listed as accessed but no matching direct read appears in the raw source; likely an artifact of the linked-list walk.
    // UNRESOLVED: The identity of the object at dword_8B8F24 and the exact matrix semantics of the vtable-slot-4 indirect D3D transform calls are not established by this packet.
    // UNRESOLVED: The extraction provenance of fields this+0x7C..this+0x84 (marked R) vs the writes performed here (center computation and read-back) is not fully reconciled.
}
