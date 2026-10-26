// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005832E0
// Canonical corpus name: sub_5832E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5832E0_005832e0.c

void UnknownObject::LinkedListRemoveByValueWithFlaggedCleanup()
{
    // Removes a node from a singly-linked list container maintained on `this` (head, tail, iterator and count fields) by searching for a node whose payload equals a2. Unlinks the matched node, updates the iterator when the matched node is current, updates the tail when the matched node is last, and decrements the count. Optionally clears the node's cleanup flag when a3 is false; if the flag remains set and the payload is non-null, invokes the payload's first virtual-method-table entry with argument 1, then frees the node. Returns 1 on success and 0 when a2 is null, the list is empty, or no match is found.
    // GUARD: If the search value a2 is null, return 0 without touching the list. [source:raw]
    // GUARD: If the list head *this is null, return 0. [field:this:0x00000000, source:raw]
    // LOOP: Walk the list from the head comparing each node's payload field (*v4) against a2 while remembering the previous node v5; if the walk reaches a null next pointer without a match, return 0. [field:*(*(obj+0x4)+0x0):0x00000000, field:*(obj+0x4):0x00000000, source:raw]
    // GUARD: If the matched node is the current/iterator pointer this[2], advance the iterator to the matched node's next pointer. [field:this:0x00000008, source:raw]
    // ASSIGNMENT: Unlink the matched node: the previous node's next pointer (obj+0x4), or the head *this when there is no previous node, becomes the matched node's next pointer. [field:obj:0x00000004, field:this:0x00000000, source:raw]
    // ASSIGNMENT: If the matched node is the tail pointer this[1], set the tail to the previous node. [field:this:0x00000004, source:raw]
    // CALCULATION: Decrement the node count stored at this[3] (also exposed as obj+0xC). [field:obj:0x0000000C, field:this:0x0000000C, source:raw]
    // ASSIGNMENT: When a3 is false, clear the node's cleanup-flag byte at node+8. [field:obj:0x00000008, source:raw]
    // GUARD: If the node's cleanup-flag byte at node+8 is still set and the node's payload pointer *v4 is non-null, call the payload object's first virtual-method-table entry with argument 1. [field:obj:0x00000008, source:raw]
    // CALL: Free the removed node via FreeWrapper_7bcf. [callee:0x00587BCF, source:raw]
    // RETURN: Return 1 on successful removal, and 0 on the null-value, empty-list and no-match paths. [source:raw]

    // Conservative worker pseudocode:
    //   int sub_5832E0(this, int a2, char a3) {
    //     if (!a2 || !this[0]) return 0;
    //     prev = 0; node = this[0];
    //     while (node && *node != a2) { prev = node; node = node[1]; }
    //     if (!node) return 0;
    //     if (node == this[2]) this[2] = node[1];
    //     if (prev) prev[1] = node[1]; else this[0] = node[1];
    //     if (this[1] == node) this[1] = prev;
    //     this[3] -= 1;
    //     if (!a3) *((_BYTE*)node + 8) = 0;
    //     if (*((_BYTE*)node + 8) && *node) (***(_DWORD**)_DWORD(node))(*node, 1);
    //     FreeWrapper_7bcf(node);
    //     return 1;
    //   }
    // UNRESOLVED: Whether the first virtual-method-table entry invoked on the payload is a destructor is a DERIVED reading from the existing analysis; the raw source only shows a virtual call with argument 1.
    // UNRESOLVED: The object types of the list container `this` and of the node payload are unknown; equal offsets on the different bases are not proof of identical layout.
}
