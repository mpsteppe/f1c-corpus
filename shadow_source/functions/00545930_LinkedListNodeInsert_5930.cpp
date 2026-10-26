// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00545930
// Canonical corpus name: LinkedListNodeInsert_5930
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeInsert_5930_00545930.c

void UnknownObject::LinkedListNodeInsert_5930()
{
    // Allocates a 56-byte node, initializes it with parameter a2 and the allocator counter at this+0x158, then inserts it into a linked list. When parent object a3 with a non-null child-list container at a3+560 is supplied, the new node is appended to that child list (head at +44); when the child list is empty the new node becomes its head. Without a parent, the node is appended to the main list headed at this+0x15C. The new node's previous (+48) and next (+52) links are written, its next link cleared, and the counter at this+0x158 is incremented.
    // CALL: Allocate a 56-byte node block: OperatorNewNhMallocWrapper(56). On failure the new-node pointer is null. [callee:0x00587C03, source:raw]
    // CALL: When the allocation succeeded, initialize the node with parameter a2 and the allocator counter at this+0x158: ObjectInitWithParameterLinking(a2, this[86]). [callee:0x00560BA0, field:this:0x00000158, source:raw]
    // GUARD: Read the main-list head at this+0x15C; when it is non-null append to the list tail, otherwise promote the new node to head. [field:this:0x0000015C, source:raw]
    // GUARD: The parent path is taken only when argument a3 is non-null and its child-list container pointer at a3+560 is non-null; otherwise the node is appended to the main list. [source:raw]
    // ASSIGNMENT: When the child-list head at +44 is null, the new node becomes the child-list head. [source:raw]
    // LOOP: Walk the child list to its tail by following the next-node links at +52. [source:raw]
    // LOOP: Walk the main list to its tail by following the next-node links at +52, starting from the head's first link at this+0x190. [field:this:0x00000190, source:raw]
    // ASSIGNMENT: Append: set the tail node's next-node link (at +52) to the new node. [field:*(*(this+0x190)+0x34):0x00000034, source:raw]
    // ASSIGNMENT: Link the new node: write the previous node into its +48 field and clear its +52 next field. [source:raw]
    // ASSIGNMENT: Increment the node counter at this+0x158. [field:this:0x00000158, source:raw]
    // RETURN: Return 0. [source:raw]

    // Conservative worker pseudocode:
    //   int LinkedListNodeInsert(void* this, void* param, void* parent) {
    //     new_node = OperatorNewNhMallocWrapper(56) ? ObjectInitWithParameterLinking(param, this[86]) : 0;
    //     tail = 0;
    //     head = this[87];                    // this+0x15C main-list head
    //     if (head) {
    //       if (parent && (container = *(parent + 560))) {
    //         if (!*(container + 44)) { *(container + 44) = new_node; goto link; }
    //         tail = *(container + 44);
    //         for (link = *(tail + 52); link; link = *(link + 52)) tail = link;
    //       } else {
    //         tail = head;
    //         for (link = *(head + 52); link; link = *(link + 52)) tail = link;
    //       }
    //       *(tail + 52) = new_node;
    //     } else {
    //       this[87] = new_node;
    //     }
    //   link:
    //     *(new_node + 48) = tail;
    //     *(new_node + 52) = 0;
    //     ++this[86];                          // this+0x158 node counter
    //     return 0;
    //   }
    // UNRESOLVED: The child-list head at +44 and the parent container link at a3+560 appear only in the raw source; the packet field table does not carry those offsets.
    // UNRESOLVED: The meaning of parameter a2 and the exact role of this+0x158 (allocator counter vs node count) is unresolved.
    // UNRESOLVED: The owning class is unknown; the pit-crew loaders and SceneNode callers do not evidence an owner type.
}
