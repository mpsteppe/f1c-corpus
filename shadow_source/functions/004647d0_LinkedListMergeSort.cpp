// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004647D0
// Canonical corpus name: LinkedListMergeSort_47d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListMergeSort_47d0_004647d0.c

void UnknownObject::LinkedListMergeSort()
{
    // Recursive merge sort for a singly-linked list. Counts nodes via the next pointer at +0x4, splits the list at its midpoint by clearing the mid node's +0x4 link, recursively sorts both halves, then merges them by comparing a sort key read from each node's pointed-to record (key at record+0x8, falling back to record+0x0 when the key equals -1).
    // GUARD: If the input head a1 is NULL, return NULL immediately. [source:raw, function:0x004647D0]
    // LOOP: Count the nodes by walking the next pointer stored at node+0x4 until it becomes NULL. [field:*(this+0x4):0x00000004, source:raw]
    // GUARD: If the node count is less than 2, return the list head unchanged (already sorted). [source:raw]
    // CALCULATION: Walk from the head to the midpoint node (count/2 - 1 steps) using the next pointers at +0x4. [field:*(this+0x4):0x00000004, source:raw]
    // ASSIGNMENT: Save the second-half head v6 as the mid node's +0x4 successor, then clear the mid node's +0x4 link (write 0) to split the list into two halves. [field:*(this+0x4):0x00000004, source:raw]
    // CALL: Recursively sort the first half of the list. [callee:0x004647D0, source:raw]
    // CALL: Recursively sort the second half of the list. [callee:0x004647D0, source:raw]
    // GUARD: If either sorted half is NULL, return the other half as the result. [source:raw]
    // LOOP: Merge the two sorted halves by comparing the sort key of each node's pointed-to record (key at record+0x8, falling back to record+0x0 when the key equals -1), relinking the +0x4 next pointers and tracking the merge tail. [field:*(this+0x4):0x00000004, callee:0x004647D0, source:raw]
    // RETURN: Return the head of the merged list. [source:raw, function:0x004647D0]

    // Conservative worker pseudocode:
    //   if (head == NULL) return NULL;
    //   count = count_nodes(head);
    //   if (count < 2) return head;
    //   mid = advance(head, count/2 - 1);
    //   second = mid->next;
    //   mid->next = NULL;
    //   first = mergesort(head);
    //   second = mergesort(second);
    //   if (!first) return second;
    //   if (!second) return first;
    //   return merge(first, second);  // compare key (fallback to data[0] when key == -1)
    // UNRESOLVED: The node layout is only partially covered by packet evidence: the next pointer at +0x4 is an evidence-backed field, while the sort-key reads at record+0x8 and the fallback to record+0x0 appear in the raw source text only and have no packet field evidence_ref.
    // UNRESOLVED: The identity of the pointed-to record type and the meaning of the -1 sentinel key are not resolvable from this packet alone.
}
