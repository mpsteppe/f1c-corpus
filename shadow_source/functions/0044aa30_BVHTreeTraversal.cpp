// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044AA30
// Canonical corpus name: BVHTreeTraversal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/BVHTreeTraversal_0044aa30.c

void UnknownObject::BVHTreeTraversal()
{
    // Recursive BVH (bounding-volume hierarchy) traversal for collision queries (per-frame tick, called by SpatialGridQuery 0x0044C4C0). Reads the node type word at this+0x8: negative values mark a leaf that runs QuadraticSurfaceCollisionTest against the surface pointer stored in the node (this+0x10), with the sentinel 0xFFFE additionally testing a second surface at surface+92. Non-negative values mark an interior node: it computes a split coordinate from the query a2 using the axis tables indexed by the split-axis word at this+0xA (global 0x007CA3A4) with a sign selection from the node, recurses into the child subtree (this+0x1C) when the split coordinate falls inside the child bounding interval, then walks the next sibling (this+0x20) while the split coordinate remains within the next node's bound (this+0x24), re-checking the leaf sentinel after each step.
    // ASSIGNMENT: Read the node type word v3 from this+0x8 at entry. [field:this:0x00000008, source:raw]
    // GUARD: Leaf dispatch: when v3 (word at this+0x8) is negative the node is a leaf and execution takes the surface-test path. [field:this:0x00000008, source:raw]
    // CALL: Leaf primary test: QuadraticSurfaceCollisionTest(surface, a2) against the surface pointer at this+0x10, updating closest-hit data. [callee:0x0044A070, field:this:0x00000010, source:raw]
    // GUARD: Two-surface sentinel: when the word at this+0x8 equals 0xFFFE, additionally run QuadraticSurfaceCollisionTest against the secondary surface at surface+92. [guard:0, callee:0x0044A070, source:raw]
    // CALCULATION: Interior split coordinate: v5 = axis_table[split-axis at this+0xA] * a2[0] and v6 = axis_table_other[split-axis at this+0xA] * a2[2], then v7 = v5 - v6 or v6 + v5 selected by the node sign word (this+0xC), using the axis table global 0x007CA3A4. [global:0x007CA3A4, field:this:0x0000000A, field:this:0x0000000C, source:raw]
    // GUARD: Child subtree range test: when the split coordinate falls inside the child bounding interval (bounds carried at this+0x1C), recurse BVHTreeTraversal(a2) into the child subtree. [callee:0x0044AA30, field:this:0x0000001C, source:raw]
    // LOOP: Sibling walk: advance to the next sibling node pointer (this+0x20) and continue while the split coordinate is not below the next node's lower bound and not above its upper bound (bound at this+0x24); the loop re-reads the node type word at +0x8 after each step and re-enters the leaf surface-test path when it turns negative. [field:this:0x00000020, field:this:0x00000024, field:this:0x00000008, source:raw]
    // CALL: Invoked by SpatialGridQuery (0x0044C4C0) to resolve which surfaces a query intersects. [caller:0x0044C4C0, source:raw]

    // Conservative worker pseudocode:
    //   type = word(this + 0x8);
    //   if (type < 0) {
    //     QuadraticSurfaceCollisionTest(*(this + 0x10), a2);
    //     if (type == 0xFFFE) QuadraticSurfaceCollisionTest(*(this + 0x10) + 92, a2);
    //   } else {
    //     for (;;) {
    //       split = (sign at this+0xC) ? axis[this+0xA]*a2[0] - axis2[this+0xA]*a2[2]
    //                                 : axis2[this+0xA]*a2[2] + axis[this+0xA]*a2[0];
    //       if (boundsMin(this+0x1C) <= split <= boundsMax(this+0x1C)) BVHTreeTraversal(a2);
    //       node = nextSibling(this+0x20);
    //       if (split < lowerBound(node) || split > upperBound(this+0x24)) break;
    //       type = word(node + 0x8);
    //       if (type < 0) goto leafPath;
    //     }
    //   }
    // UNRESOLVED: The exact node layout mapping the packet fields (bounds at this+0x1C, next sibling at this+0x20, next bound at this+0x24) onto the raw pointer/float arithmetic (v8[0]/v8[1], v9+4, *(next+1)) follows the skeleton fill at DERIVED trust and is not independently verified here.
    // UNRESOLVED: The axis table is rendered by the raw source as both dword_7CA388 and the indexed float access unk_7CA3A4; only the single global 0x007CA3A4 is granted by the packet, so the second table address is not referenced as an evidence ref.
}
