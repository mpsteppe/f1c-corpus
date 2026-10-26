// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B9000
// Canonical corpus name: sub_4B9000
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B9000_004b9000.c

void UnknownObject::ProcessZoneCollisionFramePass()
{
    // Frame pass over zone/collision objects driven by float threshold a2. Iterates all 104 object slots via LinkedListTraversalWithFilter, keeping a local slot array, then walks a threshold-sorted node list whose cursor lives at this+0x71C (list heads at this+0x714/0x718, length bound at this+0x720). The walk selects a start node based on floats at this+0xF30/0xF34, advances through node child links, runs an ascending message-processing pass (sub_566DB0/WrapperPassThrough/sub_4B44A0, StreamReadWithScale, NetworkMessageDispatch and ZoneThresholdComparisonWithConditionalAction) and a second descending pass, then finishes with CollisionFilterAABBCull and LinkedListIteratorWithStateUpdate on the embedded list at this+0xF44.
    // LOOP: Loop i over all 104 slots: LinkedListTraversalWithFilter(this, i, a2) returns a per-slot object stored into local array v45[i+108]. A slot is nulled when FieldCompareConstant(v4+36) is true, its lower key (v5[147]) is <= a2, FloatComparisonCheck(v5+36) holds and its upper key (v5[39]) is >= a2; otherwise ThunkWithStructInitSubCalls(v5+36) runs on it. [callee:0x004B72A0, callee:0x005001D0, callee:0x005001F0, callee:0x004FFFA0, source:raw]
    // CALL: Run FloatComparisonListIteration on the embedded message list at this+0xF44 with threshold a2. [callee:0x004B5380, source:raw]
    // GUARD: Select the BST walk root: when float at this+0xF34 minus float at this+0xF30 plus float at this+0xF30 is >= a2 pick the secondary root pointer this+0x718, otherwise the primary root pointer this+0x714, then store the chosen root into the cursor this+0x71C and read its key. [field:this:0x00000F30, field:this:0x00000F34, field:this:0x00000714, field:this:0x00000718, field:this:0x0000071C, field:*(this+0x714):0x00000000, field:*(this+0x718):0x00000000, source:raw]
    // LOOP: Walk the threshold-sorted node list from the cursor this+0x71C by following child links (node+0x4 next/right or node+0x8 prev/left) and reading each node's float key at +0x0, comparing it against a2 to decide direction; child keys and child pointers are read from the cursor node via *(*(this+0x71C)+0x0), *(*(this+0x71C)+0x4) and *(*(this+0x71C)+0x8), and from the root node links at *(*(this+0x714)+0x4)/*(*(this+0x714)+0x8). [field:this:0x0000071C, field:*(this+0x71C):0x00000000, field:*(this+0x71C):0x00000004, field:*(this+0x71C):0x00000008, field:*(*(this+0x714)+0x4):0x00000004, field:*(this+0x714):0x00000008, field:*(*(this+0x71C)+0x4):0x00000000, field:*(*(this+0x71C)+0x8):0x00000000, field:*(*(*(this+0x71C)+0x4)+0x0):0x00000000, field:*(*(*(this+0x71C)+0x8)+0x0):0x00000000, field:*(*(this+0x71C)+0x0):0x00000000, field:*(*(this+0x71C)+0x0):0x00000004, field:*(*(this+0x71C)+0x0):0x00000008, source:raw]
    // CALCULATION: Compute the linear index j of the cursor node within the list starting at this+0x714 by following next pointers (node+0x4); the search stops when the index reaches the list length at this+0x720 minus one. [field:this:0x00000714, field:this:0x00000720, source:raw]
    // LOOP: First (ascending) message-processing pass from the current cursor node: per node build a working record via sub_566DB0((int*)this+441, nodeId), WrapperPassThrough(v44) and sub_4B44A0(v44, this+1764) with a hard cap of 64 nodes; per message StreamReadWithScale reads from the this+1764 stream keyed by the node float. Messages tagged 0x20000000 are dispatched: non-zero 6-bit subtype <= 6 goes to NetworkMessageDispatch on the list head at this+0xF44, subtype zero with low byte < 0x68 routes to ZoneThresholdComparisonWithConditionalAction(slot+144, a2, message). [callee:0x00566DB0, callee:0x004B4450, callee:0x004B44A0, callee:0x004B4360, callee:0x004B54E0, callee:0x004FFFB0, field:this:0x0000071C, source:raw]
    // LOOP: First-pass termination scan across the 104 stored slot pointers v45[108..211]: stop early when a slot fails FieldCompareConstant((float*)(slot+144)); reaching index 104 combined with ListWalkWithUserCancelCheck(this+0xF44) marks the end of the pass. [callee:0x005001D0, callee:0x004B5460, source:raw]
    // STATE_TRANSITION: Advance the cursor this+0x71C to the next node via the prev/left link (node+0x8); after the first pass completes the original cursor (saved in v43) is restored into this+0x71C for the second pass. [field:this:0x0000071C, source:raw]
    // LOOP: Second (descending) message-processing pass mirroring the first: it walks prev/left from the restored cursor while node keys stay > a2, uses the same sub_566DB0/WrapperPassThrough/sub_4B44A0 record build, StreamReadWithScale, NetworkMessageDispatch and ZoneThresholdComparisonWithConditionalAction dispatch, but validates stored slots with FloatComparisonCheck and detects end-of-pass via LinkedListValidationWalk(this+0xF44). [callee:0x00566DB0, callee:0x004B4450, callee:0x004B44A0, callee:0x004B4360, callee:0x004B54E0, callee:0x004FFFB0, callee:0x005001F0, callee:0x004B54A0, field:this:0x00000714, field:this:0x00000720, field:this:0x0000071C, source:raw]
    // CALCULATION: Recompute the cursor's linear index from the list starting at this+0x714 and use the accumulated count relative to the length at this+0x720 to bound the descending walk; the cursor advances through next/right links (node+0x4) at the end of the second pass. [field:this:0x00000714, field:this:0x00000718, field:this:0x0000071C, field:this:0x00000720, source:raw]
    // CALL: Run CollisionFilterAABBCull on the embedded list at this+0xF44 to cull AABB candidates. [callee:0x004B5630, source:raw]
    // RETURN: Return LinkedListIteratorWithStateUpdate(this+0xF44), resuming the list iteration with updated state. [callee:0x004B5760, function:0x004B9000, source:raw]
    // CALL: Invoked from ConditionalMultiPathDispatcher (0x004BA180). [caller:0x004BA180]

    // Conservative worker pseudocode:
    //   void ProcessZoneCollisionFramePass(void *this, float a2) {
    //     for (int i = 0; i < 104; ++i) {
    //       float *node = LinkedListTraversalWithFilter(this, i, a2);
    //       v45[i + 108] = node;
    //       if (node && FieldCompareConstant(node + 36) && node[147] <= a2
    //           && FloatComparisonCheck(node + 36) && node[39] >= a2)
    //         v45[i + 108] = 0;
    //       else if (node)
    //         ThunkWithStructInitSubCalls(node + 36);
    //     }
    //     FloatComparisonListIteration(this + 0xF44, a2);
    //     pick root = (float(this+0xF34) - float(this+0xF30) + float(this+0xF30) >= a2)
    //               ? *(this + 0x718) : *(this + 0x714);
    //     cursor = *(this + 0x71C);
    //     while (cursor and key out of range) advance cursor via node+0x4 or node+0x8;
    //     index = linear_index(cursor, *(this + 0x714));
    //     if (index < *(this + 0x720) - 1 and cursor) {
    //       run ascending message pass (cap 64) with StreamReadWithScale,
    //         NetworkMessageDispatch / ZoneThresholdComparisonWithConditionalAction;
    //     }
    //     restore cursor;
    //     run descending message pass (cap 64) over prev/left nodes;
    //     CollisionFilterAABBCull(this + 0xF44);
    //     return LinkedListIteratorWithStateUpdate(this + 0xF44);
    //   }
    // UNRESOLVED: Whether the threshold-sorted structure is a strict binary tree or a doubly-linked sorted list is not fully resolvable from the raw decompilation; cursor advancement uses both node+0x4 and node+0x8 links.
    // UNRESOLVED: The message tag interpretation (0x20000000 mask, 6-bit subtype field, low-byte slot index) is recovered from raw source only and is not independently corroborated.
}
