// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004BAFC0
// Canonical corpus name: MemoryAllocation_afc0
// Owner: DualListContainer [DERIVED]
// Raw source: functions/MemoryAllocation_afc0_004bafc0.c

void DualListContainer::AllocDualListBlockAndInsertNodes()
{
    // Allocates and populates two linked lists on this container. Builds a 2036-byte block holding two 1016-byte sub-chunks initialized by DualCallWrapper_4f50, appends a node referencing it to the first list, then appends one node per nonzero 1016-stride pointer from the block into the second list. Returns the last allocation.
    // CALL: allocate 4-byte pointer block via heap allocator [callee:0x00587C03]
    // GUARD: if pointer-block allocation failed, short-circuit the whole body [function:0x004BAFC0]
    // CALL: allocate 2036-byte block via heap allocator [callee:0x00587C03]
    // ASSIGNMENT: store header value 2 at block start [source:raw]
    // LOOP: initialize the two 1016-byte sub-chunks via DualCallWrapper_4f50 [callee:0x004B4F50]
    // ASSIGNMENT: store block pointer into the 4-byte pointer block [source:raw]
    // CALL: allocate 12-byte list node for the first list [callee:0x00587C03]
    // ASSIGNMENT: initialize first-list node: data pointer at +0, previous 0 at +4, flag 1 at +8 [source:raw]
    // GUARD: branch on whether first-list head pointer at +0x0 is set [field:this:0x00000000]
    // ASSIGNMENT: empty first list: set head at +0x0 and current pointer at +0x8 to the node [field:this:0x00000000, field:this:0x00000008]
    // ASSIGNMENT: link node into first list: update tail at +0x4 and increment count at +0xC [field:this:0x00000004, field:this:0x0000000C]
    // LOOP: iterate block offsets 0 to 2032 in steps of 1016; guard each nonzero offset pointer [source:raw]
    // CALL: allocate 12-byte list node for the second list [callee:0x00587C03]
    // ASSIGNMENT: initialize second-list node: data pointer at +0, previous 0 at +4, flag 0 at +8 [source:raw]
    // GUARD: branch on whether second-list head pointer at +0x10 is set [field:this:0x00000010]
    // ASSIGNMENT: empty second list: set anchor at +0x14 and secondary pointer at +0x18 to the node [field:this:0x00000014, field:this:0x00000018]
    // ASSIGNMENT: link node into second list: update head at +0x10 and increment count at +0x1C [field:this:0x00000010, field:this:0x0000001C]
    // RETURN: return the last allocated node [function:0x004BAFC0]

    // Conservative worker pseudocode:
    //   pb = alloc4();
    //   if (!pb) return 0;
    //   block = alloc2036();
    //   block[0] = 2;
    //   for (chunk = block+1, k = 2; k; --k) { DualCallWrapper_4f50(chunk); chunk += 1016; }
    //   pb[0] = block;
    //   n1 = alloc12(); n1+0 = pb; n1+4 = 0; n1+8 = 1;
    //   if (head1) tail1->next = n1; else { head1 = n1; cur1 = n1; }
    //   tail1 = n1; count1++;
    //   for (i = 0; i < 2032; i += 1016) {
    //     if (block + i) {
    //       n2 = alloc12(); n2+0 = block + i; n2+4 = 0; n2+8 = 0;
    //       if (head2) n2->next = head2; else { anchor2 = n2; sec2 = n2; }
    //       head2 = n2; count2++;
    //     }
    //   }
    //   return n2;
    // UNRESOLVED: semantic of the initialization performed by DualCallWrapper_4f50 on each 1016-byte sub-chunk is unknown
    // UNRESOLVED: meaning of the header value 2 at block start is unknown
    // UNRESOLVED: purpose of the two distinct lists and of the flag difference (1 versus 0) on their nodes is unknown
}
