// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00559630
// Canonical corpus name: LinkedListNodeSearchAllocation
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListNodeSearchAllocation_00559630.c

void UnknownObject::FindOrAppendListNode()
{
    // Searches a singly-linked list rooted at this+0x8 for a node whose two key fields (+0x14, +0x18) match the pair (a2, a3), returning the matched node on a hit. On a miss it allocates a 32-byte node, zero-initializes it via SmallStructInitWithParentCall, links it at the tail (or as the new head when the list was empty), and sets the key pair through StructFieldInit_9390.
    // LOOP: Walk the chain from head this+0x8 via the +0x1C next pointers, comparing node +0x14 against a2 and node +0x18 against a3; iteration stops on a full match (hit) or when the walk reaches a null next pointer [field:this:0x00000008, source:raw]
    // GUARD: Match test: a node is returned only when both node+0x14 equals a2 and node+0x18 equals a3; otherwise the search continues and a null next pointer routes to the allocation path [source:raw]
    // LOOP: When the head exists but no match was found, walk the chain a second time to its last node so the new node can be appended at the tail [field:this:0x00000008, source:raw]
    // CALL: OperatorNewNhMallocWrapper(32) heap-allocates the 32-byte node; on allocation failure a null node is carried into the link/init steps [callee:0x00587C03, source:raw]
    // CALL: SmallStructInitWithParentCall zero-initializes the freshly allocated node (or yields 0 when allocation failed) [callee:0x00559330, source:raw]
    // ASSIGNMENT: Link the new node into the list: when the head is null the head this+0x8 becomes the new node (this+0x8 = 0 on allocation failure), otherwise the previous tail's +0x1C link is set to the new node [field:this:0x00000008, source:raw]
    // CALL: StructFieldInit_9390(new_node, a2, a3) writes the two search keys into the new node, using a null node pointer on the failed-allocation branch [callee:0x00559390, source:raw]
    // RETURN: Returns the matched node pointer on a search hit, or the tail/list-head result of the allocation path otherwise; the final two return slots are Hex-Rays artifacts reading never-initialized registers; invoked from sub_5598B0 (005598b0) [function:0x00559630, caller:0x005598B0, source:raw]

    // Conservative worker pseudocode:
    //   head = this[2];
    //   node = head;
    //   while (node != 0 && (node[5] != a2 || node[6] != a3)) node = node[7];
    //   if (node != 0) return node;
    //   if (head != 0) {
    //     tail = head;
    //     while (tail[7] != 0) tail = tail[7];
    //     new_node = OperatorNewNhMallocWrapper(32);
    //     new_node = new_node ? SmallStructInitWithParentCall(new_node) : 0;
    //     tail[7] = new_node;
    //     StructFieldInit_9390(new_node, a2, a3);
    //   } else {
    //     new_node = OperatorNewNhMallocWrapper(32);
    //     if (new_node) {
    //       new_node = SmallStructInitWithParentCall(new_node);
    //       this[2] = new_node;
    //       StructFieldInit_9390(new_node, a2, a3);
    //     } else {
    //       this[2] = 0;
    //       StructFieldInit_9390(0, a2, a3);
    //     }
    //   }
    // UNRESOLVED: The final return statements yield never-initialized registers (v8/v12 in the decompiler), so the exact return value of the allocation branches is uncertain — the search-hit path return is the only well-defined one
    // UNRESOLVED: Read-only fields this+0x24, +0x38, +0x3C, +0x40 and +0x5C are flagged by packet facts but appear nowhere in the raw decompiled source; the skeleton fill marks them unknown
}
