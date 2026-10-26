// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004967D0
// Canonical corpus name: DoublyLinkedListAppend_67d0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/DoublyLinkedListAppend_67d0_004967d0.c

void UnknownObject::DoublyLinkedListAppend_67d0()
{
    // Appends a node carrying value a2 to a doubly-linked list whose head/tail/secondary-pointer/count live at this+0x18CC, this+0x18D0, this+0x18D4, this+0x18D8. Allocates a 16-byte node via OperatorNewNhMallocWrapper(16), initializes its payload/next/prev/flag fields, links it after the tail (or seeds head and secondary pointer on an empty list), updates the tail pointer and increments the count. A null a2 returns immediately without touching the list.
    // UNKNOWN: This-call entry: receiver pointer passed in this (ECX), value argument a2; reconstructed function identity 0x004967D0. [function:0x004967D0, abi:lead, source:raw]
    // GUARD: Null a2 blocks the append: when a2 == 0 the function returns immediately. [source:raw]
    // CALL: Allocate a 16-byte node via OperatorNewNhMallocWrapper(16). [callee:0x00587C03, source:raw]
    // GUARD: Allocation success check: when the allocation result v3 is nonzero the node is initialized; on failure v3 is forced to 0 and the null node is still processed below. [source:raw]
    // ASSIGNMENT: Initialize the new node on allocation success: node+0 = a2 (payload value), node+4 = 0 (next), node+8 = 0 (prev), node+12 = 0 (byte flag). [source:raw]
    // GUARD: Branch on the list head: this[1587] (offset 0x18CC) nonzero selects the non-empty path, else the empty-list path. [field:this:0x000018CC, source:raw]
    // ASSIGNMENT: Non-empty path: link the node after the tail — tail_ptr->next (tail_ptr + 4) = v3 and v3 + 8 (prev) = tail_ptr, where tail_ptr is this[1588] (offset 0x18D0). [field:this:0x000018D0, source:raw]
    // ASSIGNMENT: Empty-list path: set the head this[1587] (offset 0x18CC) = v3 and the secondary pointer this[1589] (offset 0x18D4) = v3. [field:this:0x000018CC, field:this:0x000018D4, source:raw]
    // ASSIGNMENT: Update the tail pointer this[1588] (offset 0x18D0) = v3 on both paths. [field:this:0x000018D0, source:raw]
    // CALCULATION: Increment the node count this[1590] (offset 0x18D8) by 1. [field:this:0x000018D8, source:raw]
    // RETURN: Implicit void return; a2 == 0 returns early without modifying the list. [source:raw]

    // Conservative worker pseudocode:
    //   // appends value v to the doubly-linked list rooted at this+0x18CC (head),
    //   // this+0x18D0 (tail), this+0x18D4 (secondary pointer), this+0x18D8 (count)
    //   // node layout: +0 payload, +4 next, +8 prev, +12 flag byte
    //   void DoublyLinkedListAppend(this, v) {
    //     if (v == 0) return;
    //     node = OperatorNewNhMallocWrapper(16);
    //     if (node) {
    //       node[0]  = v;
    //       node[4]  = 0;
    //       node[8]  = 0;
    //       node[12] = 0;
    //     }
    //     if (this[0x18CC]) {
    //       tail = this[0x18D0];
    //       tail[4] = node;   // old tail -> node (next)
    //       node[8] = tail;   // node -> old tail (prev)
    //     } else {
    //       this[0x18CC] = node;
    //       this[0x18D4] = node;
    //     }
    //     this[0x18D0] = node;
    //     this[0x18D8] += 1;
    //   }
    // UNRESOLVED: On allocation failure the null node is still linked into the list and the count is still incremented; intent is ambiguous (likely a latent bug) and no correction is applied.
    // UNRESOLVED: Field 0x18D4 is written on the first append alongside the head; its read-side purpose is not visible within this function.
    // UNRESOLVED: The owning class for the 0x18CC-0x18D8 list fields is unidentified; the list is reachable only through this-pointer offsets.
}
