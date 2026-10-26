// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00561620
// Canonical corpus name: RecursiveTreeNodeTraversal
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/RecursiveTreeNodeTraversal_00561620.c

void UnknownObject::RecursiveTreeNodeTraversal()
{
    // Recursively traverses a tree of nodes. Skips the whole traversal when bit 1 of the byte at this+0x3C is set. Otherwise recurses into the child pointer at this+0x44 when non-null, then recurses into the pointer at this+0x4C only when both this+0x40 and this+0x4C are non-null, and finally processes the current node via sub_561660, returning its result. Called from sub_5613E0.
    // GUARD: Test bit 1 (value 2) of the byte at this+0x3C; when it is set, skip the entire traversal and return without visiting children or the node itself. [field:this:0x0000003C, source:raw]
    // GUARD: Read the child pointer at this+0x44 and recurse only when it is non-null. [field:this:0x00000044, source:raw]
    // CALL: Recursively traverse the child node at this+0x44. [callee:0x00561620, field:this:0x00000044, source:raw]
    // GUARD: Read the pointer at this+0x40 and gate the second recursion on it being non-null. [field:this:0x00000040, source:raw]
    // GUARD: Read the pointer at this+0x4C and recurse into it only when both this+0x40 and this+0x4C are non-null. [field:this:0x0000004C, source:raw]
    // CALL: Recursively traverse the node at this+0x4C when the double guard passes. [callee:0x00561620, field:this:0x0000004C, source:raw]
    // CALL: Process the current node via sub_561660 and return its result. [callee:0x00561660, source:raw]
    // RETURN: Return the result of sub_561660 as the traversal outcome for the current node. [function:0x00561620, source:raw]
    // CALL: Invoked from sub_5613E0 (0x005613E0). [caller:0x005613E0]

    // Conservative worker pseudocode:
    //   int RecursiveTreeNodeTraversal(Node* this) {
    //     if ((*(_BYTE*)(this + 0x3C) & 2) == 0) {
    //       if (*(_DWORD*)(this + 0x44)) RecursiveTreeNodeTraversal(*(_DWORD*)(this + 0x44));
    //       if (*(_DWORD*)(this + 0x40) && *(_DWORD*)(this + 0x4C))
    //         RecursiveTreeNodeTraversal(*(_DWORD*)(this + 0x4C));
    //       return sub_561660(this);
    //     }
    //     return result;
    //   }
    // UNRESOLVED: The early-return value when the skip flag at this+0x3C bit 1 is set is the uninitialized Hex-Rays register, not a meaningful result; the caller likely ignores it on that path.
    // UNRESOLVED: The semantics of the this+0x40 and this+0x4C pointer pair (sibling versus nested child) are not evidenced beyond the gating control flow.
    // UNRESOLVED: Whether this+0x40 and this+0x4C belong to distinct object types is not evidenced; equal offsets on different this pointers do not imply identical classes.
}
