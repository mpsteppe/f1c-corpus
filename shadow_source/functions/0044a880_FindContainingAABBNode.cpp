// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0044A880
// Canonical corpus name: sub_44A880
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_44A880_0044a880.c

void UnknownObject::FindContainingAABBNode()
{
    // Descending containment search of a tree of AABB nodes. The node type word at this+0x8 is a leaf marker when negative: the function then returns the current node. For internal nodes it loads two scale factors from a material table (base unk_7CA3A4, index this+0xA; the raw source also reads the adjacent dword_7CA388), negates the second factor when the node type is nonzero, and builds four scaled values from the input point a2[0..3]. It then tests all four values against the child bound buffer (this+0xC): first-axis min/max at +0x0/+0x4 and second-axis min/max at +0x10/+0x14. When the point is inside all planes the current node is returned; when it is outside on both axes the search fails with 0; otherwise the walk descends to a child buffer and repeats until a leaf marker is reached.
    // GUARD: Leaf marker check: when the node type word at this+0x8 is negative the traversal stops and the current node is returned. [field:this:0x00000008, source:raw]
    // CALCULATION: Load scale factor A from the material table indexed by the word at this+0xA (raw source reads dword_7CA388, table region anchored by unk_7CA3A4). [field:this:0x0000000A, global:0x007CA3A4, source:raw]
    // CALCULATION: Load scale factor B from the same material table (base unk_7CA3A4) and negate it when the node type word at this+0x8 is nonzero. [field:this:0x00000008, field:this:0x0000000A, global:0x007CA3A4, source:raw]
    // CALCULATION: Build four scaled values from the input point a2[0..3] as combinations of scale factors A and B. [source:raw]
    // GUARD: First-axis outside test against the child bound min at +0x0 and max at +0x4: all four scaled values below the min or all above the max. [field:*(this+0xC):0x00000000, field:*(this+0xC):0x00000004, source:raw]
    // GUARD: Second-axis outside test against the child bound min at +0x10 and max at +0x14: all four scaled values below the min or all above the max. [field:*(this+0xC):0x00000010, field:*(this+0xC):0x00000014, source:raw]
    // RETURN: Return the current node when the point is inside both axes; return 0 when it is outside on both axes. [source:raw]
    // ASSIGNMENT: Descend by re-pointing the walk to the child buffer stored at this+0xC, or to that buffer advanced by four floats when only the first axis was outside. [field:this:0x0000000C, source:raw]
    // LOOP: Iterate the descent, re-reading the node type word at this+0x8 after each move, until a negative (leaf) value is found. [field:this:0x00000008, source:raw]

    // Conservative worker pseudocode:
    //   float *FindContainingAABBNode(float *this, float *a2) {
    //     while (*(short*)(this + 8) >= 0) {
    //       double s1 = dword_7CA388[*(short*)(this + 10)];
    //       double s2 = unk_7CA3A4[*(short*)(this + 10)];
    //       if (*(short*)(this + 8)) s2 = -s2;
    //       float *child = *(float**)(this + 12);
    //       double c0 = s1*a2[0] + s2*a2[2];
    //       double c1 = s1*a2[0] + s2*a2[3];
    //       double c2 = s1*a2[1] + s2*a2[2];
    //       double c3 = s1*a2[1] + s2*a2[3];
    //       bool out_first  = (c0<child[0]&&c1<child[0]&&c2<child[0]&&c3<child[0]) ||
    //                         (c0>child[1]&&c1>child[1]&&c2>child[1]&&c3>child[1]);
    //       bool out_second = (c0<child[4]&&c1<child[4]&&c2<child[4]&&c3<child[4]) ||
    //                         (c0>child[5]&&c1>child[5]&&c2>child[5]&&c3>child[5]);
    //       if (!out_first) {
    //         if (!out_second) return this;   // contained
    //         this = child;                   // descend
    //       } else {
    //         if (out_second) return 0;       // outside tree
    //         this = child + 4;               // descend to sibling
    //       }
    //     }
    //     return this;                        // leaf node reached
    //   }
    // UNRESOLVED: Exact meaning of the two material scale factors (the raw source reads dword_7CA388 and unk_7CA3A4) and why only unk_7CA3A4 is present in the packet global evidence.
    // UNRESOLVED: Whether the four computed values are corners of an oriented quad or sign-variant samples of a transformed point.
    // UNRESOLVED: Why the fourth input component a2[3] participates in the scaled values.
    // UNRESOLVED: Meaning of the two different descent targets (child buffer versus child buffer advanced by four floats).
}
