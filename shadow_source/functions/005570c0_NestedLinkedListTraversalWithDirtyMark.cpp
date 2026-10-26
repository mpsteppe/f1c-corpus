// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005570C0
// Canonical corpus name: NestedLinkedListTraversalWithDirtyMark
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/NestedLinkedListTraversalWithDirtyMark_005570c0.c

void UnknownObject::NestedLinkedListTraversalWithDirtyMark()
{
    // Walks two scene-graph lists of a this object and marks every node dirty for D3D re-upload. First traverses parent nodes rooted at this+0x100, descending into each parent's child list head at node offset 0xEC and advancing through children via each child's dword index 19; then walks a flat sibling list rooted at this+0x108 advancing the same way. Each node is passed to D3DMarkDirty(node, a2, 0); the last call's return value becomes the function result. Invoked by sub_557120.
    // LOOP: Outer traversal: start at the parent-list head stored at dword index 64 (byte offset 0x100) of the this object and advance through parent nodes using each node's next-sibling pointer at byte offset 0x104. [field:this:0x00000100, field:*(this+0x204):0x00000104, source:raw]
    // LOOP: Inner traversal per parent: start at the child-list head at byte offset 0xEC within the parent node and advance through children via each child's pointer at dword index 19. [field:*(this+0x204):0x000000EC, source:raw]
    // CALL: D3DMarkDirty(child, a2, 0) marks each child node dirty for re-upload. [callee:0x00556CD0, source:raw]
    // LOOP: Flat traversal: start at the sibling-list head stored at dword index 66 (byte offset 0x108) of the this object and advance via each node's pointer at dword index 19. [field:this:0x00000108, source:raw]
    // CALL: D3DMarkDirty(node, a2, 0) marks each flat-list node dirty for re-upload. [callee:0x00556CD0, source:raw]
    // RETURN: Return the result of the final D3DMarkDirty call. [function:0x005570C0, source:raw]
    // CALL: Invoked by sub_557120 (0x00557120). [caller:0x00557120]

    // Conservative worker pseudocode:
    //   int NestedLinkedListTraversalWithDirtyMark(int *this, int a2) {
    //     for (i = this[64]; i; i = *(int *)(i + 0x104))
    //       for (j = *(int **)(i + 0xEC); j; j = j[19])
    //         result = D3DMarkDirty(j, a2, 0);
    //     for (k = (int *)this[66]; k; k = k[19])
    //       result = D3DMarkDirty(k, a2, 0);
    //     return result;
    //   }
    // UNRESOLVED: field:*(*(this+0x204)+0xEC):0x98 is listed in the deterministic field set but is not referenced by the decompiled body.
    // UNRESOLVED: field:this:0x1A0 is listed in the deterministic field set but is not referenced by the decompiled body.
}
