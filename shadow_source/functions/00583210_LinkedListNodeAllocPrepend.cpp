// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00583210
// Canonical corpus name: LinkedListNodeAllocPrepend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeAllocPrepend_00583210.c

void UnknownObject::LinkedListNodeAllocPrepend()
{
    // Allocates a 12-byte list node, initializes its payload/flag fields, prepends it to a doubly-linked-list container maintained on `this` (head, tail pointers, and node count), and reports success. Returns 0 immediately when the payload argument is null.
    // GUARD: If a2 (payload pointer) is non-zero, proceed with allocation and prepend; otherwise return 0. [source:raw]
    // CALL: Allocate a 12-byte node via OperatorNewNhMallocWrapper(12). [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the allocated node: node+0 = a2 (payload pointer), node+4 = 0, node+8 = a3 (byte flag). [source:raw]
    // GUARD: If the list head (*this) is already non-null, link the new node's next pointer to the old head. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Empty-list case: set both list boundary pointers this[1] and this[2] to the new node. [field:this:0x00000004, field:this:0x00000008, source:raw]
    // ASSIGNMENT: Set the list head *this to the new node. [field:this:0x00000000]
    // CALCULATION: Increment the node count this[3]. [field:this:0x0000000C]
    // RETURN: Return 1 on the successful prepend path. [source:raw]

    // Conservative worker pseudocode:
    //   if (payload == 0) return 0;
    //   node = OperatorNewNhMallocWrapper(12);
    //   if (!node) return 0;
    //   node->payload = payload; node->next = 0; node->flag = flag;
    //   if (head) node->next = head; else { this[1] = node; this[2] = node; }
    //   head = node;
    //   count += 1;
    //   return 1;
    // UNRESOLVED: Node object type and the exact meaning of the node+8 byte flag are unknown.
    // UNRESOLVED: Role of this[1] versus this[2] as distinct list boundary pointers is derived from the empty-list write pattern, not independently confirmed.
}
