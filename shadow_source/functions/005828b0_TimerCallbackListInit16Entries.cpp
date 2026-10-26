// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x005828B0
// Canonical corpus name: sub_5828B0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_5828B0_005828b0.c

void UnknownObject::TimerCallbackListInit16Entries()
{
    // Zeros the eight fields of a timer callback list object, then allocates a 1348-byte callback block holding 16 entries of 84 bytes each, links the block node into the object's first linked list, and allocates one 12-byte node per callback entry into a second linked list. Same pattern as the sibling 4-entry init with 16 entries instead of 4. Called by sub_57BA10.
    // ASSIGNMENT: Zero the eight object fields this[0] through this[7] (two linked-list heads/tails/iterators plus two counts). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // ASSIGNMENT: Allocate a 4-byte node via OperatorNewNhMallocWrapper(4) into v2; null-checked. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Allocate a 1348-byte callback block; store entry count literal 16 at block[0] and use block+1 dwords as the entries base pointer. [callee:0x00587C03, source:raw]
    // CALL: Call NTimeCallbackLoopWithSEH_a6eb(entries_base, 84, 16, SEHProtectedDirectXRenderStateSetup, SEHGuardedFunctionWithExceptionHandling) to initialize 16 callback entries of 84 bytes each. [callee:0x0058A6EB, global:0x00586700, global:0x005867B0, source:raw]
    // ASSIGNMENT: Store the entries base pointer into *v2 (the 4-byte node); entries base is 0 when block allocation failed. [source:raw]
    // GUARD: If the block node v2 is non-null, allocate a 12-byte first-list node holding the block node pointer, next=0 and flag byte=1; on allocation failure the node stays 0. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Link the first-list node: if head this[0] is non-null append it after tail this[1] and advance this[1]; otherwise set head this[0], tail this[1] and iterator this[2] to the node. Increment count this[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: Iterate entry_byte_offset v7 from 0 step 84 while below 1344 (16 iterations); each iteration computes the entry address as v7 + *v5 and, when non-null, allocates a 12-byte second-list node (data=entry address, next=0, flag byte=0). [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Link each second-list node: if head this[4] is non-null prepend it by setting node next to the old head; otherwise set tail this[5] and iterator this[6] to the node. Always set head this[4]=node and increment count this[7]. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return this (the object pointer), unlike the sibling init which returns the final count. [function:0x005828B0, source:raw]

    // Conservative worker pseudocode:
    //   memset(this, 0, 32);
    //   node = operator_new(4);
    //   block = operator_new(1348);
    //   if (block) { block[0] = 16; NTimeCallbackLoopWithSEH_a6eb(block+1, 84, 16, SEHProtectedDirectXRenderStateSetup, SEHGuardedFunctionWithExceptionHandling); }
    //   if (node) node[0] = (block) ? block+1 : 0;
    //   if (node) insert_first_list_node(node, 1);
    //   for (off = 0; off < 1344; off += 84) insert_second_list_node(off + block_entries);
    // UNRESOLVED: Exact semantics of the NTimeCallbackLoopWithSEH_a6eb arguments (entry size 84, count 16, two callback pointers) are inferred from call shape, not documented.
    // UNRESOLVED: Meaning of the node flag byte at node+8 (1 for the block node, 0 for entry nodes) is unknown.
    // UNRESOLVED: How the two linked lists are consumed by caller sub_57BA10 is unknown.
    // UNRESOLVED: Difference from the sibling 4-entry init in returned value (this here, count there) has no documented rationale.
    // UNRESOLVED: SEH guard global 0x0059CD29 (SEH_5828B0) does not appear in the decompiled body.
}
