// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004FF2B0
// Canonical corpus name: sub_4FF2B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4FF2B0_004ff2b0.c

void UnknownObject::RecursiveMergeSortLinkedList()
{
    // Recursively merge-sorts a singly-linked list of nodes ordered by a float sort key. Each node holds a pointer to its key at +0 (compared as `**(float**)node`) and a next-node pointer at +4. The list is split into two halves, each half is sorted recursively, then the halves are merged back in ascending key order. Returns the new head. Structural twin of MergeSort_b2e0 (004bb2e0). Called by AudioEventRingBufferProcessing (004FEAF0).
    // GUARD: If the input head a1 is NULL, return it immediately [field:this:0x00000000, source:raw]
    // LOOP: Walk the list via +4 next pointers to count the number of nodes [field:this:0x00000004, field:*(*(this+0x4)+0x4):0x00000004, source:raw]
    // GUARD: If the node count is less than 2 the list is already sorted; return the head [source:raw]
    // CALCULATION: Compute the split position mid = count/2 - 1 and walk from the head that many +4 hops to find the middle node [field:*(*(this+0x4)+0x4):0x00000000, field:*(*(this+0x4)+0x4):0x00000004, source:raw]
    // ASSIGNMENT: Cut the list: save the second half as the middle node's successor, then write 0 into the middle node's +4 next pointer [field:this:0x00000004, source:raw]
    // CALL: Recursively sort both halves: sub_4FF2B0(head) and sub_4FF2B0(secondHalf) [callee:0x004FF2B0, source:raw]
    // LOOP: Merge the two sorted halves: compare the float keys (`**(float**)node` reads at node+0) and re-link nodes via the +4 pointers in ascending key order [field:obj:0x00000000, field:this:0x00000000, field:*(this+0x4):0x00000004, field:*(*(*(this+0x4)+0x4)+0x0):0x00000000, source:raw]
    // RETURN: Return the head of the merged, sorted list [source:raw]
    // CALL: Invoked by AudioEventRingBufferProcessing (004FEAF0) to order an event ring-buffer list by its key [caller:0x004FEAF0]

    // Conservative worker pseudocode:
    //   int sub_4FF2B0(node *head) {
    //     if (!head) return head;
    //     int n = 0;
    //     for (node *p = head; p; p = (node*)p->next) ++n;
    //     if (n < 2) return head;
    //     node *mid = head;
    //     for (int i = n/2 - 1; i > 0; --i) mid = (node*)mid->next;
    //     node *second = (node*)mid->next;
    //     mid->next = NULL;
    //     node *l = sub_4FF2B0(head);
    //     node *r = sub_4FF2B0(second);
    //     if (!l) return r; if (!r) return l;
    //     node *out, *t;
    //     if (key(l) >= key(r)) { out = t = r; r = (node*)r->next; }
    //     else                   { out = t = l; l = (node*)l->next; }
    //     while (l && r) {
    //       if (key(l) >= key(r)) { t->next = r; t = r; r = (node*)r->next; }
    //       else                  { t->next = l; t = l; l = (node*)l->next; }
    //     }
    //     t->next = l ? l : r;
    //     return out;
    //   }
    //   float key(node *p) { return **(float**)p; }
    // UNRESOLVED: The node key layout is unusual: +0 holds a pointer to the float key, so keys live in a separate storage area; only the pointer is stored in the node
    // UNRESOLVED: Caller AudioEventRingBufferProcessing (004FEAF0) semantics and the meaning of the sort key are outside this function
}
