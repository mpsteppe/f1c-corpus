// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00434290
// Canonical corpus name: LinkedListMergeSort_4290
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListMergeSort_4290_00434290.c

void UnknownObject::LinkedListMergeSortRecursive()
{
    // Recursive merge sort for a singly-linked list whose nodes hold a string pointer at +0 and a next-node pointer at +4. Counts the list, splits it at the midpoint by writing 0 into the next pointer of the split node, sorts both halves recursively, then merges them in ascending string order using strcmp with a fallback empty string for null string pointers. Returns the head of the merged list, or the input unchanged when it is null or has fewer than two nodes.
    // GUARD: Return the input pointer unchanged when the list is null or contains fewer than 2 nodes. [source:raw]
    // LOOP: Walk the list following the next pointers at node+4 to count the number of nodes. [source:raw]
    // CALCULATION: Locate the midpoint by advancing floor(count/2)-1 hops; split the list by writing 0 into the next pointer at node+4 of the midpoint node, severing the left half. [field:*(this+0x4):0x00000004, source:raw]
    // CALL: Recursively sort the left half of the list. [callee:0x00434290]
    // CALL: Recursively sort the right half of the list. [callee:0x00434290]
    // LOOP: Merge the two sorted halves: at each step compare the current nodes' string members with strcmp, treating a null string pointer as the fallback string at byte_5EA438, and append the node whose string sorts first (ascending order). [global:0x005EA438, source:raw]
    // ASSIGNMENT: Relink the merged list by writing each chosen node into the next pointer of the previous merged node as the merge walk advances. [field:*(this+0x4):0x00000004, source:raw]
    // RETURN: Return the head of the merged list; when one half ends early the remainder of the other half is appended directly. [source:raw]

    // Conservative worker pseudocode:
    //   Node* sub_434290(Node* head) {
    //     if (!head) return head;
    //     int n = 0;
    //     for (Node* p = head; p; p = p->next) ++n;
    //     if (n < 2) return head;
    //     Node* mid = head;
    //     for (int i = n / 2 - 1; i > 0; --i) mid = mid->next;
    //     Node* right = mid->next;
    //     mid->next = 0;
    //     Node* left = sub_434290(head);
    //     right = sub_434290(right);
    //     if (!left) return right;
    //     if (!right) return left;
    //     Node* merged;
    //     Node* tail;
    //     const char* a = left->str ? left->str : byte_5EA438;
    //     const char* b = right->str ? right->str : byte_5EA438;
    //     if (strcmp(a, b) >= 0) { merged = tail = right; right = right->next; }
    //     else { merged = tail = left; left = left->next; }
    //     while (left && right) {
    //       const char* x = right->str ? right->str : byte_5EA438;
    //       const char* y = left->str ? left->str : byte_5EA438;
    //       if (strcmp(x, y) >= 0) { tail->next = right; tail = right; right = right->next; }
    //       else { tail->next = left; tail = left; left = left->next; }
    //     }
    //     tail->next = left ? left : right;
    //     return merged;
    //   }
    // UNRESOLVED: Purpose of byte_5EA438 as the fallback string and the meaning of the sorted string keys depend on the directory-enumeration caller.
    // UNRESOLVED: List node ownership/allocation is not visible in this packet.
}
