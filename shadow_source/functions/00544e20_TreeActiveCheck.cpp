// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00544E20
// Canonical corpus name: TreeActiveCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/TreeActiveCheck_00544e20.c

void UnknownObject::TreeActiveCheck()
{
    // Recursive tree-activity check. Reads two child pointers (this+0x44, this+0x4C) and recurses TreeActiveCheck(child, 1) when present, returning -1 when a recursion reports true (the second child recursion is additionally gated on flag a2). Then walks a sibling list from the head at this+0x204 following next pointers at node+0x10, returning -1 if any node satisfies SceneNodeChildrenClear (0x0054D030); returns 0 when the list is exhausted.
    // GUARD: Read the child pointer at this+0x44 (a1[17]); if non-null, recurse TreeActiveCheck(child, 1) and return -1 when it returns non-zero. [field:this:0x00000044, callee:0x00544E20, source:raw]
    // GUARD: Read the child pointer at this+0x4C (a1[19]); if non-null and flag a2 is set, recurse TreeActiveCheck(child, 1) and return -1 when it returns non-zero. [field:this:0x0000004C, callee:0x00544E20, source:raw]
    // GUARD: Read the sibling list head at this+0x204 (a1[129]); if null, return 0. [field:this:0x00000204, source:raw]
    // LOOP: Walk the sibling list following the next pointer at node+0x10 while SceneNodeChildrenClear(v5) returns false; if the next pointer becomes null, return 0. [callee:0x0054D030, field:*(this+0x214):0x00000010, source:raw]
    // RETURN: Return -1 when a sibling node satisfies SceneNodeChildrenClear. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_544E20(node* a1, int a2) {
    //     if (a1->childA(0x44) && TreeActiveCheck(a1->childA, 1)) return -1;
    //     if (a1->childB(0x4C) && a2 && TreeActiveCheck(a1->childB, 1)) return -1;
    //     n = a1->siblingHead(0x204);
    //     if (!n) return 0;
    //     while (!SceneNodeChildrenClear(n)) {
    //       n = *(node**)(n + 0x10);
    //       if (!n) return 0;
    //     }
    //     return -1;
    //   }
    // UNRESOLVED: Semantics of flag a2: it gates only the second child recursion.
    // UNRESOLVED: The -1 vs 0 return convention and the meaning of 'active' relative to SceneNodeChildrenClear are not established; the -1 branch fires when a node's children are reported clear.
    // UNRESOLVED: The field base *(this+0x214) for the +0x10 next pointer differs textually from the sibling list head at this+0x204; the node object layout beyond the next pointer is unknown.
    // UNRESOLVED: Exact behavior of SceneNodeChildrenClear (0x0054D030) is unknown.
}
