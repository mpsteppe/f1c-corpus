// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00465C70
// Canonical corpus name: MergeSortOnLinkedList
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MergeSortOnLinkedList_00465c70.c

void UnknownObject::MergeSortAscendingOnLinkedList()
{
    // Recursive merge sort on a singly linked list of nodes, ascending by the float key stored at (data pointer + 4) of each node's payload. Counts the nodes, returns early for null or fewer-than-2 nodes, splits the list at its midpoint, sorts each half recursively (this same function), then merges the two sorted halves in ascending float-key order, relinking the node next pointers. Returns the head of the merged list. Used by EntityVisibilityGridManager.
    // GUARD: Return a1 unchanged when the list head is null (empty list). [source:raw]
    // LOOP: Count list nodes by walking the next pointer at node offset 4, tracking the count in the node-count field. [field:obj:0x00000004, field:this:0x0000000C, source:raw]
    // GUARD: Return a1 unchanged when the node count is below 2 (trivially sorted). [source:raw]
    // CALCULATION: Compute the split index as (node count / 2) minus 1. [source:raw]
    // LOOP: Advance the walk pointer from the head by the split index to reach the midpoint node, following node offset 4. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: Split the list: capture the right half head from the midpoint node's next pointer, then write 0 into that next pointer to terminate the left half. [field:*(this+0x8):0x00000004, field:this:0x00000008, source:raw]
    // CALL: Recursively sort the left half via this same MergeSortOnLinkedList routine. [callee:0x00465C70, source:raw]
    // CALL: Recursively sort the right half via this same MergeSortOnLinkedList routine. [callee:0x00465C70, source:raw]
    // GUARD: Return the non-null sorted half when either half is empty. [source:raw]
    // CALCULATION: Compare the float keys: read the key at (data pointer + 4) of the left head node and the right head node, each node's data pointer at node offset 0. [field:this:0x00000000, source:raw]
    // ASSIGNMENT: Select the smaller-key node as the head of the merged list (ascending order). [source:raw]
    // LOOP: Merge the remaining nodes of both halves, relinking node next pointers (offset 4) to the smaller key each step until one half is exhausted. [field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: Terminate the merged tail: link the remaining nodes of the non-empty half, or write 0 as the null sentinel when both halves are exhausted. [field:this:0x00000008, source:raw]
    // RETURN: Return the head of the merged ascending list. [source:raw]
    // CALL: Invoked by EntityVisibilityGridManager to order entity entries by their float key. [caller:0x00465460, source:raw]

    // Conservative worker pseudocode:
    //   if (!a1) return a1;
    //   n = 0; p = a1;
    //   while (p) { n++; p = p[1]; }
    //   if (n < 2) return a1;
    //   m = n/2 - 1; p = a1;
    //   while (m > 0) { m--; p = p[1]; }
    //   right = p[1];
    //   p[1] = 0;
    //   left = MergeSortOnLinkedList(a1);
    //   right = MergeSortOnLinkedList(right);
    //   if (!left) return right;
    //   if (!right) return left;
    //   // merge ascending by float key at (node data pointer + 4)
    //   head = smaller_key_head(left, right);
    //   // ... relink next pointers by smaller key ...
    //   tail_next = remaining_or_zero;
    //   return head;
    // UNRESOLVED: The payload record behind each node's data pointer is not identified; only the float key at (data + 4) is used here.
    // UNRESOLVED: The float-to-double comparison widening is a Hex-Rays artifact of the decompiled comparison; semantics are ascending order by the float key.
    // UNRESOLVED: The 'sentinel' field at this+0x8 doubles as the split termination write and the merge tail terminator; the static field evidence assigns it both roles.
    // UNRESOLVED: The caller EntityVisibilityGridManager's entity record layout is not visible in this packet.
}
