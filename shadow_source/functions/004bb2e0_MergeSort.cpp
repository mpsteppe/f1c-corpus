// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BB2E0
// Canonical corpus name: MergeSort_b2e0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/MergeSort_b2e0_004bb2e0.c

void UnknownObject::MergeSort()
{
    // Recursive merge sort for a singly-linked list sorted by a float key (descending). Counts the nodes, splits the list at the midpoint by clearing the mid node's next pointer, recursively sorts both halves, then merges them by comparing the float value at each node's data pointer (node+0x0 -> float) and relinking next pointers (node+0x4). Returns the new list head. Returns the input unchanged when the list is null or has fewer than two nodes.
    // GUARD: Return the list head unchanged when it is null. [source:raw, field:this:0x00000000]
    // LOOP: Count the nodes by walking the next pointer at this+0x4 until null. [source:raw, field:this:0x00000004]
    // GUARD: Return the list head unchanged when the node count is less than 2. [source:raw, field:this:0x00000000]
    // CALCULATION: Compute the midpoint index (count / 2 - 1) and walk to the split node through next pointers at this+0x4. [source:raw, field:this:0x00000004]
    // ASSIGNMENT: Sever the list at the midpoint: set the split node's next pointer (*(this+0x4) at +0x4) to 0 so the two halves are independent. [source:raw, field:*(this+0x4):0x00000004]
    // CALL: Recursively sort the left half of the list. [source:raw, callee:0x004BB2E0]
    // CALL: Recursively sort the right half of the list. [source:raw, callee:0x004BB2E0]
    // GUARD: If either half is null, return the other half as the merged result. [source:raw, field:this:0x00000000]
    // LOOP: Merge the two sorted halves: compare the float sort key at the node data pointer (obj+0x0, reached via this+0x4+0x4 chains) and take the node with the larger key, relinking next pointers at this+0x4 until one half is exhausted. [source:raw, field:obj:0x00000000, field:*(*(*(this+0x4)+0x4)+0x0):0x00000000, field:*(*(this+0x4)+0x4):0x00000000, field:*(*(this+0x4)+0x4):0x00000004, field:this:0x00000004]
    // ASSIGNMENT: Append the remaining tail of whichever half was not exhausted to the merged list. [source:raw, field:this:0x00000004]
    // RETURN: Return the head of the merged list. [source:raw]

    // Conservative worker pseudocode:
    //   Node* MergeSort(Node* head) {
    //     if (!head) return head;
    //     int count = 0;
    //     for (Node* n = head; n; n = n->next) ++count;
    //     if (count < 2) return head;
    //     Node* mid = head;
    //     for (int i = count / 2 - 1; i > 0; --i) mid = mid->next;
    //     Node* right = mid->next;
    //     mid->next = NULL;
    //     Node* left = MergeSort(head);
    //     right = MergeSort(right);
    //     if (!left) return right;
    //     if (!right) return left;
    //     Node* out;
    //     if (*(float*)left->data >= *(float*)right->data) { out = right; right = right->next; }
    //     else { out = left; left = left->next; }
    //     Node* tail = out;
    //     while (left && right) {
    //       Node* take;
    //       if (*(float*)left->data >= *(float*)right->data) { take = right; right = right->next; }
    //       else { take = left; left = left->next; }
    //       tail->next = take;
    //       tail = take;
    //     }
    //     tail->next = left ? left : right;
    //     return out;
    //   }
    // UNRESOLVED: Sort key comparison uses >=, so ties keep the node from the right half during merge.
    // UNRESOLVED: Node layout and data-pointer meaning are caller-defined; caller is SortedLinkedListInsert (0x004B81A0).
}
