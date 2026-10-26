// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005664A0
// Canonical corpus name: sub_5664A0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5664A0_005664a0.c

void UnknownObject::MergeSortLinkedList()
{
    // Recursive merge sort of a singly-linked list whose next pointer lives at node offset +4. Counts the nodes by walking the list, returns early for empty/one-node lists, splits the list at the midpoint by clearing the midpoint node's next pointer, recursively sorts both halves, then merges them in order using the data comparator sub_565BB0, and returns the head of the merged list. Structural twin of MergeSortLinkedList (004C6810) per cluster_copy prelabel (DERIVED). Called by sub_566380.
    // GUARD: If the list head a1 is null, return it unchanged. [function:0x005664A0, source:raw]
    // LOOP: Count the nodes by following the next pointer at offset +4 until a null link is reached. [field:*(this+0x4):0x00000004, source:raw]
    // GUARD: If fewer than 2 nodes, the list is already sorted; return a1 unchanged. [source:raw]
    // LOOP: Advance a cursor to the midpoint node (node count/2 - 1 steps) by following next pointers. [field:*(this+0x4):0x00000004, source:raw]
    // ASSIGNMENT: Split the list: capture the midpoint node's next pointer as the second-half head v6, then clear that next pointer to 0 to detach the halves. [field:*(this+0x4):0x00000004]
    // CALL: Recursively sort the first half starting at a1. [callee:0x005664A0, source:raw]
    // CALL: Recursively sort the second half starting at v6. [callee:0x005664A0, source:raw]
    // LOOP: Merge the two sorted halves: compare node data values with comparator sub_565BB0 and relink the next pointers (+4) to produce one ascending list. [callee:0x00565BB0, field:*(this+0x4):0x00000004]
    // RETURN: Return the head of the fully merged, sorted list. [function:0x005664A0, source:raw]
    // CALL: Called by sub_566380. [caller:0x00566380]

    // Conservative worker pseudocode:
    //   int *MergeSortLinkedList(int *head) {
    //     if (head == NULL) return head;
    //     int count = 0;
    //     for (int *n = head; n != NULL; n = *(int **)(n + 1)) count++;
    //     if (count < 2) return head;
    //     int *mid = head;
    //     for (int steps = count / 2 - 1; steps > 0; steps--) mid = *(int **)(mid + 1);
    //     int *second = *(int **)(mid + 1);
    //     *(int **)(mid + 1) = NULL;
    //     int *a = MergeSortLinkedList(head);
    //     int *b = MergeSortLinkedList(second);
    //     return merge(a, b);  // relink +4 next pointers by sub_565BB0 comparison
    //   }
    // UNRESOLVED: The comparator sub_565BB0's sort order direction and the data type at each node are not resolved here.
    // UNRESOLVED: The merge step's edge handling for empty halves is reconstructed from the raw source but not independently verified.
    // UNRESOLVED: Object owner of the linked list nodes is unknown; field +4 is shared across all nodes as the next link.
}
