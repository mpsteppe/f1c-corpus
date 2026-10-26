// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00556930
// Canonical corpus name: RecursiveStateTraversalWithFlagCheck
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveStateTraversalWithFlagCheck_00556930.c

void UnknownObject::RecursiveStateTraversalWithFlagCheck()
{
    // Traverses a sibling-linked scene node list rooted at `this`. For each node, reads a visibility/state mask at this+0x38 and breaks out of the traversal when the node mask is non-zero yet the masked global render visibility mask (0x008B8E34 combined with the caller mask at a2+0x84) does not fully cover it. Otherwise dispatches animation updates via AnimationDispatchWithSkipFlag(a2), recurses into children when this+0x44 is set, then follows the next-sibling pointer at this+0x4C until it is null or the sibling continuation flag at this+0x40 is zero.
    // GUARD: Read node mask this+0x38; if it is non-zero AND (global mask 0x008B8E34 & node mask & caller mask a2+0x84) != node mask, break out of the traversal, skipping this node and its subtree. [field:this:0x00000038, global:0x008B8E34, source:raw]
    // CALL: Dispatch animation updates for the node with AnimationDispatchWithSkipFlag(a2). [callee:0x00556980, source:raw]
    // GUARD: If the children flag this+0x44 is non-zero, recurse into child nodes via RecursiveStateTraversalWithFlagCheck(a2). [field:this:0x00000044, callee:0x00556930, source:raw]
    // GUARD: If the sibling continuation flag this+0x40 is zero, break out of the traversal. [field:this:0x00000040, source:raw]
    // ASSIGNMENT: Advance the traversal pointer to the next sibling node at this+0x4C. [field:this:0x0000004C, source:raw]
    // LOOP: do-while loop over the sibling chain: continues while the current node pointer is non-null. [field:this:0x0000004C, source:raw]
    // RETURN: Return the last read node mask / sibling flag value that caused loop termination. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_556930(Node *this, int a2) {
    //     int result;
    //     do {
    //       result = this->mask38;
    //       if (result && (g_8B8E34 & result & *(int*)(a2 + 0x84)) != result) break;
    //       AnimationDispatchWithSkipFlag(a2);
    //       if (this->childrenFlag44) RecursiveStateTraversalWithFlagCheck(a2);
    //       result = this->siblingFlag40;
    //       if (!result) break;
    //       this = this->nextSibling4C;
    //     } while (this);
    //     return result;
    //   }
    // UNRESOLVED: Meaning of the caller-supplied mask at a2+0x84 and how it combines with the node and global masks.
    // UNRESOLVED: Recursive call passes a2 rather than a child pointer; the callee's own 'this' argument must be derived elsewhere (possibly from a2's context).
    // UNRESOLVED: Ownership and exact node object type are unknown.
}
