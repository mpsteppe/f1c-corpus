// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004C2E20
// Canonical corpus name: MergeSortLinkedListByFloat
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MergeSortLinkedListByFloat_004c2e20.c

void UnknownObject::MergeSortLinkedListByFloat()
{
    // Merge-sorts a singly linked list of nodes, each node's first DWORD (this+0x0) pointing at a payload whose +4 field is a float sort key. It counts the nodes, splits the list at the midpoint, recursively sorts both halves, then merges them in ascending key order.
    // GUARD: If the list head (this+0x0) is NULL, return NULL immediately. [field:this:0x00000000, source:raw]
    // LOOP: Walk the next pointers (this+0x4) from the head, counting every node until NULL. [field:this:0x00000004]
    // GUARD: If the node count is less than 2, the list is trivially sorted; return the head unchanged. [field:this:0x00000000]
    // CALCULATION: Advance from the head by (count / 2 - 1) nodes to locate the midpoint. [field:this:0x00000004]
    // ASSIGNMENT: Split the list by clearing the midpoint node's next pointer (this+0x4 set to 0); retain the right-half head. [field:this:0x00000004]
    // CALL: Recursively merge-sort the left half (original head). [callee:0x004C2E20]
    // CALL: Recursively merge-sort the right half. [callee:0x004C2E20]
    // GUARD: If either half is empty, return the other half unchanged as the merged result. [field:this:0x00000000]
    // CALCULATION: Compare sort keys: read the float at payload+4 where payload is the node's first DWORD (this+0x0); select the node with the smaller-or-equal key as the merged head. [field:*(this+0x8):0x00000004, field:obj:0x00000004, field:this:0x00000000]
    // LOOP: Merge: while both halves still have nodes, repeatedly link the node with the smaller-or-equal key into the result via the next pointers (this+0x4); when one half drains, link the remaining tail. [field:this:0x00000004, field:*(this+0x8):0x00000004, field:obj:0x00000004]
    // RETURN: Return the merged list head. [field:this:0x00000000]

    // Conservative worker pseudocode:
    //   if (head == NULL) return NULL;
    //   count = walk_next(head);
    //   if (count < 2) return head;
    //   mid = advance(head, count / 2 - 1);
    //   right = mid->next; mid->next = NULL;
    //   left = mergesort(head); right = mergesort(right);
    //   return merge_by_key(left, right);  // key = *(float*)(node->payload + 4), ascending
    // UNRESOLVED: Fields this+0x8 and this+0xC were extracted from the cluster twin (00465c70) but are not visibly accessed in this function's body; their role is unclear.
    // UNRESOLVED: The float comparison uses <= after widening to double; tie-breaking is deterministic but the intended ordering (ascending by key) is inferred, not confirmed by an external contract.
    // UNRESOLVED: Both callers (004BF790, 004BFA00) invoke this as a sorting helper; per-call-site argument semantics were not analyzed.
}
