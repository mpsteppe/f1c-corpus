// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005598B0
// Canonical corpus name: sub_5598B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5598B0_005598b0.c

void UnknownObject::ActorResponseLinkAllocate()
{
    // Links an actor name to a response name by appending an 8-byte mapping node to the mapping list headed at a1+0x224. Looks the actor up in the UTF-16 string linked list (global dword_8B8F2C) and the response up in a binary tree, resolves or creates the actor-response mapping node, then appends it to the tail of the list. On any lookup failure logs a formatted error and returns -1.
    // GUARD: Global guard: if the resource list handle dword_8B8F2C is null, call sub_53C590 with the 'Could not find resource' string (aCouldNotFindRe) and return -1. [global:0x008B8F2C, global:0x005DC1D8, callee:0x0053C590]
    // CALL: Search the UTF-16 string linked list rooted at dword_8B8F2C for the actor name a2 via UTF16StringSearchInLinkedList; capture the returned node. [callee:0x00559760, global:0x008B8F2C]
    // GUARD: Actor-lookup guard: if the actor node was not found, format 'Could not find actor %s' (aCouldNotFindAc) via StringFormatWithBufferOverflowCheck and return -1. [global:0x005DC1F4, callee:0x0058815F]
    // CALL: Search the binary tree for the response name a3 via BinaryTreeSearch; capture the returned node. [callee:0x005597C0]
    // GUARD: Response-lookup guard: if the response node was not found, format 'Could not find resposne %s' via StringFormatWithBufferOverflowCheck and return -1. [callee:0x0058815F]
    // CALL: Resolve or create the actor-to-response mapping node via LinkedListNodeSearchAllocation over the linked list dword_8B8F2C using the actor node and response node as keys. [callee:0x00559630, global:0x008B8F2C]
    // GUARD: Inspect the mapping list head at a1+0x224: if it is non-null, walk to the tail by following next pointers (head node +0x4). [field:this:0x00000224, field:*(this+0x224):0x00000004]
    // CALL: Allocate an 8-byte mapping node (value pointer + next pointer) via OperatorNewNhMallocWrapper(8). [callee:0x00587C03]
    // ASSIGNMENT: Append the new node: when the list at a1+0x224 was non-empty, set the tail's next pointer (*(*(*(this+0x224)+0x4)+0x4)) to the new node; when it was empty, set the head a1+0x224 to the new node. The new node's value is the resolved mapping and its next pointer is 0. [field:this:0x00000224, field:*(this+0x224):0x00000004, field:*(*(*(this+0x224)+0x4)+0x4):0x00000004]
    // RETURN: Return 0 on the success paths and -1 on any of the three failure guards. [source:raw]

    // Conservative worker pseudocode:
    //   int ActorResponseLinkAllocate(int a1, const char *actorName, const char *responseName) {
    //     if (!dword_8B8F2C) { sub_53C590(-1, "Could not find resource"); return -1; }
    //     int actorNode = UTF16StringSearchInLinkedList(dword_8B8F2C, actorName);
    //     if (!actorNode) { StringFormatWithBufferOverflowCheck(buf, "Could not find actor %s", actorName); return -1; }
    //     int respNode = BinaryTreeSearch(dword_8B8F2C, responseName);
    //     if (!respNode) { StringFormatWithBufferOverflowCheck(buf, "Could not find resposne %s", responseName); return -1; }
    //     int mapping = LinkedListNodeSearchAllocation(dword_8B8F2C, actorNode, respNode);
    //     DWORD *node = OperatorNewNhMallocWrapper(8);
    //     node[0] = mapping; node[1] = 0;
    //     if (DWORD head = *(DWORD*)(a1 + 0x224)) {
    //       DWORD *tail = head;
    //       while (tail[1]) tail = tail[1];
    //       tail[1] = node;
    //     } else {
    //       *(DWORD*)(a1 + 0x224) = node;
    //     }
    //     return 0;
    //   }
    // UNRESOLVED: The mapping-list nodes are 8 bytes (value pointer + next pointer); the concrete type of the value pointer and the owning class of a1+0x224 are unknown.
    // UNRESOLVED: The relationship of a1 to the caller SceneNode (0x0055A910) is not established; the append target is an opaque list head at a1+0x224.
    // UNRESOLVED: The binary's format string is the misspelled 'Could not find resposne %s'; no dedicated global evidence ref is listed for it in the packet.
    // UNRESOLVED: dword_8B8F2C is read as a render/resource handle root; exact global semantics are DERIVED from callers.
}
