// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004046B0
// Canonical corpus name: MemoryAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MemoryAllocation_004046b0.c

void UnknownObject::WheelContactHeightSmoothing()
{
    // Iterates a fixed-stride (316-byte) element array at this[0x134], whose count is this[0x130]. Each element with a valid neighbor pointer at +276 is processed: when its node type at +300 is below the threshold this[0x10], the +76 contact height is zeroed and then reconstructed by walking the +272/+268 linked-list ancestor chain accumulating (+268+76)+ (+268+60); when the type is at or above the threshold, the contact height is smoothed by averaging the node and its spatial-neighbor heights from SpatialNearestNeighborQueryWithPlaneTest. Type 1 nodes with no parent take the ancestor-chain path.
    // ASSIGNMENT: Seed the iteration count from this[0x130] (this[76]) and initialize the loop index to 0. [field:this:0x00000130, source:raw]
    // GUARD: Guard on this[0x130] > 0; when the element count is zero the loop body never runs. [field:this:0x00000130, source:raw]
    // LOOP: do-while loop over the elements at this[0x134], advancing the element base by stride 316 each iteration. [field:this:0x00000134, source:raw]
    // CALCULATION: Compute the current element address v5 = *(array base + index*316 + 276) and dereference it as the element pointer. [field:this:0x00000134, source:raw]
    // GUARD: Guard on the dereferenced element pointer v5 being non-null; null entries are skipped. [source:raw]
    // CALCULATION: Read the node type v7 at element offset +300. [source:raw]
    // GUARD: Branch on whether v7 is below the threshold this[0x10] (this[4]): below goes to the ancestor-chain path, otherwise to the spatial-neighbor query path. [field:this:0x00000010, source:raw]
    // GUARD: Guard on v7 == 1 and the element having no parent (*(element base + 300) == 0). [source:raw]
    // ASSIGNMENT: Zero the contact height at element offset +76. [source:raw]
    // LOOP: while loop walking the linked list via the +272 next-node pointer starting from *(element + 272). [source:raw]
    // GUARD: Loop exit guards: break when the next node is null, the next node equals the current element, or *(next + 268) != current node. [source:raw]
    // CALCULATION: Accumulate the node +76 contact height as (*(*(node+268)+76) + *(*(node+268)+60)) at each chain step. [source:raw]
    // CALL: For nodes whose type is at/above the threshold, call SpatialNearestNeighborQueryWithPlaneTest(this, element, 1) to find a spatial neighbor node. [callee:0x004038E0, source:raw]
    // CALCULATION: When a spatial neighbor exists, smooth the element contact height to the average of the neighbor's height and the element's height: *(element+76) = (*(neighbor+76) + *(element+76)) * 0.5. [source:raw]
    // RETURN: Return the last computed loop counter value. [source:raw]
    // CALL: Called by SurfaceHeightfieldCollisionCallback (0x00404250). [caller:0x00404250]

    // Conservative worker pseudocode:
    //   int sub_4046B0(int *this) {
    //     int count = this[76], idx = 0;
    //     if (count > 0) {
    //       do {
    //         int base = this[77] + idx * 316;
    //         int elem = *(int *)(base + 276);
    //         if (elem) {
    //           int type = *(int *)(elem + 300);
    //           if (type < this[4]) {
    //             if (type == 1 && !*(int *)(base + 300)) {
    //               *(int *)(elem + 76) = 0;
    //               int node = *(int *)(elem + 272);
    //               while (node && node != elem && *(int *)(node + 268) == /*parent* /) {
    //                 *(float *)(node + 76) = *(float *)(*(int *)(node + 268) + 76) + *(float *)(*(int *)(node + 268) + 60);
    //                 node = *(int *)(node + 272);
    //               }
    //             }
    //           } else {
    //             int nn = SpatialNearestNeighborQueryWithPlaneTest(this, (float *)elem, 1);
    //             if (nn && *(int *)(nn + 268))
    //               *(float *)(elem + 76) = (*(float *)(*(int *)(nn + 268) + 76) + *(float *)(nn + 76)) * 0.5f;
    //           }
    //         }
    //         idx++;
    //       } while (idx < count);
    //     }
    //     return idx;
    //   }
    // UNRESOLVED: Meaning of the threshold this[0x10] and the node type enum at +300 is not established by this packet.
    // UNRESOLVED: The +268 parent/back pointer and +272 next-node pointer roles are inferred from the walk pattern, not proven.
    // UNRESOLVED: Global flt_59E450 (0x0059E450) is listed in the packet's globals but is not referenced in the raw source text; its role here is unresolved.
    // UNRESOLVED: Element struct layout (offsets +60, +76, +268, +272, +276, +300) is only partially understood.
}
