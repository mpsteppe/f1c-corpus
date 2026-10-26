// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434030
// Canonical corpus name: DoublyLinkedListAppend
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_00434030.c

void UnknownObject::DoublyLinkedListAppend()
{
    // Appends a node to a linked list tracked by head/tail/count. Allocates a 12-byte node via OperatorNewNhMallocWrapper, stores the data pointer and a flag byte, links the node after the current tail (or as the first node when the list is empty), updates the tail pointer and increments the count, then returns 1. A null data argument returns 0 immediately.
    // GUARD: If the data pointer argument a2 is null, return 0 immediately without allocating a node. [source:raw, function:0x00434030]
    // CALL: Call OperatorNewNhMallocWrapper(12) to allocate the 12-byte node; on a null result the node pointer is forced to 0. [callee:0x00587C03]
    // ASSIGNMENT: Initialize the new node: data pointer a2 at +0, next pointer 0 at +4, flag byte a3 at +8. [source:raw, function:0x00434030]
    // GUARD: Branch on the list head (*this): when non-null, link the new node after the current tail node (set the tail node's +4 next to the new node); when null, set both the head (*this) and this+0x8 to the new node. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008]
    // ASSIGNMENT: Update the tail pointer this+0x4 to the new node and increment the element count this+0xC. [field:this:0x00000004, field:this:0x0000000C]
    // RETURN: Return 1 to signal a successful append (the append proceeds even when the node allocation returned null). [source:raw, function:0x00434030]

    // Conservative worker pseudocode:
    //   if (data == 0) return 0;
    //   node = OperatorNewNhMallocWrapper(12);
    //   if (node) { node->data = data; node->next = 0; node->flag = flag; } else node = 0;
    //   if (this->head) this->tail->next = node; else { this->head = node; this->first = node; }
    //   this->tail = node;
    //   this->count++;
    //   return 1;
    // UNRESOLVED: The allocation-failure path still appends a null node: tail is set to null, count is incremented and 1 is returned. Caller behavior on a null node is unknown.
    // UNRESOLVED: The 12-byte node layout (4 data + 4 next + 1 flag + padding) is inferred; whether it matches other list implementations is not established.
}
