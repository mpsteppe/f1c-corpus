// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00491D30
// Canonical corpus name: LinkedListNodeRemovalByValue
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeRemovalByValue_00491d30.c

void UnknownObject::LinkedListNodeRemovalByValue()
{
    // Removes the first node of a singly-linked list whose value field (first DWORD) matches a2. Walks from the head via the next pointer at node+0x4, returns 0 if the value is not found, otherwise unlinks the node, updates head/tail/cached-end pointers and the count, optionally clears the node flag byte when a3 is 0, frees the node data payload when the flag is set, frees the node, and returns 1.
    // GUARD: Return 0 when the match value a2 is null. [source:raw]
    // LOOP: Walk the list from head (*this) through next pointers at node+0x4, comparing each node's value field at node+0x0 against a2; return 0 if the end of the list is reached without a match. [field:this:0x00000000, field:*(obj+0x4):0x00000000, field:*(obj+0x4):0x00000004, source:raw]
    // STATE_TRANSITION: When the removed node is the cached end pointer this[2], advance the cached end to the removed node's next pointer. [field:this:0x00000008, field:*(obj+0x4):0x00000004]
    // ASSIGNMENT: Unlink the removed node: if a previous node exists, point prev->next at the removed node's next, otherwise update the list head *this. [field:this:0x00000000, field:*(obj+0x4):0x00000004]
    // STATE_TRANSITION: When the removed node is the list tail (this[1], also tracked at obj+0x4), set the tail to the previous node (or null when the removed node was the head). [field:obj:0x00000004, field:this:0x00000004]
    // CALCULATION: Decrement the list node count at this+0xC. [field:this:0x0000000C]
    // ASSIGNMENT: When a3 is 0, clear the node flag byte at node+0x8 (force no data free). [field:*(obj+0x4):0x00000008]
    // CALL: When the node flag byte at node+0x8 is set and the node's data pointer (first DWORD) is non-null, free the data payload via FreeWrapper_7bcf. [callee:0x00587BCF, field:*(obj+0x4):0x00000008, field:*(obj+0x4):0x00000000]
    // CALL: Free the removed node allocation via FreeWrapper_7bcf. [callee:0x00587BCF]
    // RETURN: Return 1 when a node was removed, 0 otherwise. [source:raw]

    // Conservative worker pseudocode:
    //   char sub_491D30(int *list, int value, char freeData) {
    //     if (!value) return 0;
    //     int cur = list[0], prev = 0;
    //     if (!cur) return 0;
    //     while (*(int*)cur != value) {
    //       prev = cur;
    //       cur = *(int*)(cur + 4);
    //       if (!cur) return 0;
    //     }
    //     if (cur == list[2]) list[2] = *(int*)(cur + 4);
    //     int next = *(int*)(cur + 4);
    //     if (prev) *(int*)(prev + 4) = next; else list[0] = next;
    //     if (list[1] == cur) list[1] = prev;
    //     --list[3];
    //     if (!freeData) *(char*)(cur + 8) = 0;
    //     if (*(char*)(cur + 8) && *(int*)cur) FreeWrapper_7bcf(*(void**)cur);
    //     FreeWrapper_7bcf((void*)cur);
    //     return 1;
    //   }
    // UNRESOLVED: The semantics of the flag byte at node+0x8 (e.g. owns-data / keep-payload) are not established from this packet alone.
    // UNRESOLVED: The relationship between the tail pointers tracked at obj+0x4 and this+0x4 needs an external layout check.
}
