// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00582BA0
// Canonical corpus name: sub_582BA0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_582BA0_00582ba0.c

void UnknownObject::AudioStreamTimerCallbackListInit()
{
    // Initializes a timer callback list for audio stream construction: allocates a 620-byte callback block holding 2 entries of 308 bytes each, links the block node into the object's first linked list, then allocates one 12-byte node per callback entry into a second linked list. Uses AudioStreamConstructWithVTableInit and SingleVTablePointerSet as the per-entry callback pair. No static callers recorded.
    // ASSIGNMENT: Allocate a 4-byte node via OperatorNewNhMallocWrapper(4); result kept in v3 and null-checked. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Allocate a 620-byte callback block; store entry count literal 2 at block[0] and treat block+4 as the entries base pointer. [callee:0x00587C03, source:raw]
    // CALL: Call NTimeCallbackLoopWithSEH_a6eb(block+4, 308, 2, AudioStreamConstructWithVTableInit, SingleVTablePointerSet) to initialize 2 callback entries of 308 bytes each. [callee:0x0058A6EB, global:0x00581E80, global:0x0057BC70, source:raw]
    // ASSIGNMENT: Store the entries base pointer into *v3 (the 4-byte node); when the block allocation succeeded v4 points at that node. [source:raw]
    // GUARD: If the block node v4 is non-null, allocate a 12-byte first-list node holding the block node pointer, next=0 and flag byte=1; on allocation failure the node stays 0. [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Link the first-list node: if head this[0] is non-null append it after tail this[1] and advance this[1]; otherwise set head this[0], tail this[1] and iterator this[2] to the node. Increment count this[3]. [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, source:raw]
    // LOOP: Iterate entry_byte_offset v5 from 0 step 308 while below 616 (2 iterations); each iteration computes the entry address as v5 + *v4 and, when non-null, allocates a 12-byte second-list node (data=entry address, next=0, flag byte=0). [callee:0x00587C03, source:raw]
    // STATE_TRANSITION: Link each second-list node: if head this[4] is non-null prepend it by setting node next to the old head; otherwise set tail this[5] and iterator this[6] to the node. Always set head this[4]=node and increment count this[7]. [field:this:0x00000010, field:this:0x00000014, field:this:0x00000018, field:this:0x0000001C, source:raw]
    // RETURN: Return result, which holds the final value of count this[7] after the loop's last increment. [field:this:0x0000001C, source:raw]

    // Conservative worker pseudocode:
    //   node = operator_new(4);
    //   block = operator_new(620);
    //   if (block) { block[0] = 2; NTimeCallbackLoopWithSEH_a6eb(block+4, 308, 2, AudioStreamConstructWithVTableInit, SingleVTablePointerSet); }
    //   if (node) node[0] = (block) ? block+4 : 0;
    //   if (node) insert_first_list_node(node, 1);
    //   for (off = 0; off < 616; off += 308) insert_second_list_node(off + block_entries);
    // UNRESOLVED: Exact semantics of the NTimeCallbackLoopWithSEH_a6eb arguments (entry size 308, count 2, the two per-entry callback pointers) are inferred from call shape, not documented.
    // UNRESOLVED: Meaning of the node flag byte at node+8 (1 for the block node, 0 for entry nodes) is unknown.
    // UNRESOLVED: Owner object type is unknown; audio association comes only from the AudioStreamConstructWithVTableInit callback name.
    // UNRESOLVED: No static callers are recorded, so consumption of the two linked lists is unknown.
    // UNRESOLVED: SEH guard global 0x0059CD76 (SEH_582BA0) does not appear in the decompiled body.
}
