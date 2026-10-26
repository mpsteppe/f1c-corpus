// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00549110
// Canonical corpus name: sub_549110
// Owner: SceneGraphNode [DERIVED]
// Raw source: functions/sub_549110_00549110.c

void SceneGraphNode::recursiveNodeFree()
{
    // Recursively frees a node in a linked tree/list. First recurses into the child pointer at byte offset 0x44 when non-null, then recurses into the pointer at byte offset 0x4C when both the guard field at offset 0x40 and that pointer are non-null. Calls SceneGraph as a shutdown/validation check and returns -1 immediately if it reports failure; otherwise runs the TwoFunctionCallChain teardown, frees the node via FreeWrapper_7bcf, and returns 0.
    // GUARD: If the pointer at byte offset 0x44 (a1[17]) is non-null, recurses into that child first. [field:this:0x00000044, source:raw]
    // CALL: Recursively calls sub_549110 on the child pointer at byte offset 0x44 to free the child subtree. [callee:0x00549110, field:this:0x00000044, source:raw]
    // GUARD: If the guard field at byte offset 0x40 (a1[16]) is non-null AND the pointer at byte offset 0x4C (a1[19]) is non-null, recurses into the second child. [field:this:0x00000040, field:this:0x0000004C, source:raw]
    // CALL: Recursively calls sub_549110 on the pointer at byte offset 0x4C to free the second child subtree. [callee:0x00549110, field:this:0x0000004C, source:raw]
    // GUARD: Calls SceneGraph(a1) as a shutdown/validation check; a non-zero return aborts the free. [callee:0x0054A770, source:raw]
    // RETURN: When SceneGraph returns non-zero, returns -1 immediately without running teardown or freeing the node. [callee:0x0054A770, source:raw]
    // CALL: Runs TwoFunctionCallChain(a1), the cleanup/teardown sequence, before the node is freed. [callee:0x0054A710, source:raw]
    // CALL: Frees the current node via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Returns 0 on the successful free path. [function:0x00549110, source:raw]

    // Conservative worker pseudocode:
    //   if (this->firstChild != 0)
    //       recursiveNodeFree(this->firstChild);
    //   if (this->guardField != 0 && this->secondChild != 0)
    //       recursiveNodeFree(this->secondChild);
    //   if (SceneGraph(this) != 0)
    //       return -1;
    //   TwoFunctionCallChain(this);
    //   FreeWrapper_7bcf(this);
    //   return 0;
    // UNRESOLVED: Whether the node is a tree or a linked-list node (and which offsets are child vs sibling) is not evidenced; only the two recursion targets and their guard are visible.
    // UNRESOLVED: The meaning of the SceneGraph return check (shutdown guard vs validation error) is not evidenced here; a non-zero value blocks the free.
    // UNRESOLVED: The two functions inside TwoFunctionCallChain are not visible in this packet.
    // UNRESOLVED: Owner type SceneGraphNode is DERIVED from the SceneGraph callee and the node-shaped field pattern; the exact class is not evidenced.
}
