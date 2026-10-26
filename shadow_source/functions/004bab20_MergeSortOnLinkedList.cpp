// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAB20
// Canonical corpus name: sub_4BAB20
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4BAB20_004bab20.c

void UnknownObject::MergeSortOnLinkedList()
{
    // Recursive merge sort (stdcall) of a singly linked list keyed by a float stored in each node's payload record at payload+4. Counts the nodes, splits the list at the midpoint by severing the middle next-link, recurses on both halves, then merges the two sorted runs into one ascending list keyed on that float. Returns the new head of the sorted list (or the original head for lists of fewer than two nodes). Structural twin of MergeSortOnLinkedList (00465c70) per cluster evidence.
    // GUARD: Early return of the original head a1 when the list pointer is null. [source:raw]
    // LOOP: Count the nodes by walking next links: v3 = v3[1] (node next at +0x4), incrementing a count until the tail is reached. [field:this:0x00000004, source:raw]
    // GUARD: Early return of the head when the node count is below 2; such a list is trivially sorted. [source:raw]
    // CALCULATION: Compute the split point v4 = count/2 - 1 and advance a cursor v5 from the head by next links to the node just before the midpoint. [field:this:0x00000004, source:raw]
    // ASSIGNMENT: Sever the list at the midpoint: store 0 into the next-link of the mid node (v5[1] = 0), and capture the second-half head v6 = v5[1] before the write. [field:this:0x00000004, source:raw]
    // CALL: Recursively sort the first half: v1 = sub_4BAB20(a1). [callee:0x004BAB20, source:raw]
    // CALL: Recursively sort the second half: v7 = sub_4BAB20(v6). [callee:0x004BAB20, source:raw]
    // GUARD: If one sorted half is empty, return the other half as the merge result (if !v1 return v7; if !v7 return v1). [source:raw]
    // CALCULATION: Merge loop: compare the sort keys of the two run heads, each key read as a float from the node's payload record at payload+4 (*(float*)(*node + 4)); advance the side with the smaller key and append the chosen node to the merged tail. [field:*(this+0x8):0x00000004, field:obj:0x00000004, field:this:0x00000000, field:this:0x00000004, source:raw]
    // ASSIGNMENT: After one run is exhausted, append the remaining run (or 0 if both are empty) to the merged tail via the next-link writes v10[1] = v9 / v8 / 0. [field:this:0x00000004, source:raw]
    // RETURN: Return the merged list head. [source:raw]
    // CALL: Invoked by CollisionObjectListManagement (0x004B4B50), indicating the sorted list feeds a collision-object list. [caller:0x004B4B50, source:raw]

    // Conservative worker pseudocode:
    //   node* MergeSortOnLinkedList(node* head) {
    //     if (!head) return head;
    //     int n = 0; for (node* p = head; p; p = p->next) ++n;
    //     if (n < 2) return head;
    //     node* mid = head; int m = n/2 - 1; while (m-- > 0) mid = mid->next;
    //     node* right = mid->next; mid->next = 0;
    //     node* L = MergeSortOnLinkedList(head);
    //     node* R = MergeSortOnLinkedList(right);
    //     if (!L) return R; if (!R) return L;
    //     node* out; node* tail;
    //     if (key(L) >= key(R)) { out = R; R = R->next; } else { out = L; L = L->next; }
    //     tail = out;
    //     while (L && R) {
    //       node* pick = (key(L) >= key(R)) ? R : L;
    //       if (key(L) >= key(R)) R = R->next; else L = L->next;
    //       tail->next = pick; tail = pick;
    //     }
    //     tail->next = R ? R : L;
    //     return out;
    //   }
    //   // key(x) = *(float*)(x->payload + 4)
    // UNRESOLVED: Identity and full layout of the node payload record holding the float sort key at +4 (the float at payload+4 is observed as field obj+0x4 and via *(this+0x8)+0x4; the base pointer convention differs between the two field annotations).
    // UNRESOLVED: Semantic meaning of the float sort key (ordering metric) is unknown here.
    // UNRESOLVED: Node record state at node+0x8 (initialized to 0, RW per facts) is not visibly touched by this function; likely managed by the list owner.
    // UNRESOLVED: Read of node+0xC appears in the facts but not in this decompilation's control flow.
    // UNRESOLVED: Owner of the list (which object maintains the sorted list consumed by CollisionObjectListManagement) is unknown.
}
