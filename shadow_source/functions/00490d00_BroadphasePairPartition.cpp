// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00490D00
// Canonical corpus name: sub_490D00
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_490D00_00490d00.c

void UnknownObject::BroadphasePairPartition()
{
    // Broadphase collision-partition pass over two proxy lists (outer a2, inner a1). Walks the outer list, tests each outer proxy AABB against the inner proxies; non-overlapping pairs are refined with sub_491680/RectangleClipping and clipped results are re-appended to the inner list, while overlapping pairs are unlinked from the inner list and re-prepended to the outer list. Inner list (a1/this) is a head/tail/current/count linked list.
    // ASSIGNMENT: Cache the outer list head: result = *(a2); synchronize *(a2+8) to *(a2). [source:raw]
    // GUARD: Proceed only if the inner list head at this+0x0 is non-null (guard:0, *(a1) != 0); an empty inner list skips pair processing. [guard:0, field:this:0x00000000]
    // LOOP: Outer loop over the outer list a2: read the first outer node's data (v5 = *result); when the inner list is non-empty capture the first inner node v7 = *v6, else advance the outer list via LinkedListNodeAdvance and continue. [callee:0x00581780, source:raw]
    // CALL: Test the current outer proxy box (v5[0..3]) against the inner proxy via AABBOverlapTest(*v5, v5[1], v5[2], v5[3]). [callee:0x004915A0, field:obj:0x00000000, source:raw]
    // GUARD: While the pair does not AABB-overlap, refine it: if sub_491680(*v5, v5[1], v5[2], v5[3]) returns true, run RectangleClipping(*v5, v5[1], v5[2], v5[3]) to obtain the clipped result chain. [callee:0x00491680, callee:0x00491350]
    // CALCULATION: v10/v12 holds the RectangleClipping result chain; its next link is read at *(v12+12). [callee:0x00491350]
    // STATE_TRANSITION: Remove node v7 from the inner list: walk nodes comparing their value field (*v8, obj+0) to v7, relink the previous node's next pointer (obj+4), update tail/current when needed (this+0x8), fix the tail pointer (this+0x4), patch the head (this+0x0) when unlinking the first node, and decrement the count (this+0xC). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:obj:0x00000000, field:obj:0x00000004]
    // CALL: ConditionalResourceCleanup(1) after removing the node from the inner list. [callee:0x00491E10]
    // LOOP: Rebuild the inner list from the clipped chain: for each entry allocate a node via OperatorNewNhMallocWrapper(12); if allocation succeeds init it via ShortComputation_ac20(entry, 0). Append the node: set the tail node's next (*(this+0x4)+0x4), or when the list was empty set head and current (this+0x0, this+0x8); update tail (this+0x4) and count (this+0xC); when the count reaches 1 call ShortComputation_a780(a1). [callee:0x00587C03, callee:0x004BAC20, field:*(this+0x4):0x00000004, field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, callee:0x004BA780]
    // STATE_TRANSITION: Unlink the overlapping node v7 from the inner list: walk nodes comparing *v8 to v7, update head/tail/current (this+0x0, this+0x4, this+0x8), relink via node next (obj+4), decrement count (this+0xC), then invoke sub_491E40(v8) and free the node via FreeWrapper_7bcf(v8). [field:this:0x00000000, field:this:0x00000004, field:this:0x00000008, field:this:0x0000000C, field:obj:0x00000000, field:obj:0x00000004, callee:0x00491E40, callee:0x00587BCF]
    // CALL: LinkedListNodePrepend(v7) re-inserts the overlapping proxy node into the outer list. [callee:0x00490AA0]
    // LOOP: Continue outer traversal: read the current inner node from this+0x8 (value at *(this+0x8)), and if it is null fall through to advance the outer list via LinkedListNodeAdvance; otherwise take its value and re-test. [field:*(this+0x8):0x00000000, callee:0x00581780, source:raw]
    // RETURN: Return result (the last outer node, or null when the outer list is exhausted). [source:raw]

    // Conservative worker pseudocode:
    //   headA2 = *a2; *(a2+8) = *a2
    //   if *a2 == 0: return result
    //   outer = first node of a2
    //   while outer != null:
    //       inner = first node of a1
    //       while inner != null:
    //           if AABBOverlapTest(outer[0..3]):
    //               unlink inner node from a1 (update head/tail/current/count)
    //               LinkedListNodePrepend(inner)
    //           elif sub_491680(outer[0..3]):
    //               clip = RectangleClipping(outer[0..3])
    //               unlink inner node from a1
    //               ConditionalResourceCleanup(1)
    //               for each entry in clip chain:
    //                   node = OperatorNewNhMallocWrapper(12)
    //                   if node: ShortComputation_ac20(node, entry)
    //                   append node to a1 (tail next, head/current when empty, count++)
    //                   if count == 1: ShortComputation_a780(a1)
    //           inner = next of inner
    //       outer = LinkedListNodeAdvance(a2)
    //   return last outer node
    // UNRESOLVED: field:obj:0x00000008 is recorded as a read but no exact access site was identified in the cleaned source; likely the node liveness/flag byte.
    // UNRESOLVED: The exact meaning of the four v5 shorts passed to AABBOverlapTest/sub_491680 (box coords) is not named.
    // UNRESOLVED: The purpose of sub_491680 vs AABBOverlapTest (loose vs strict test) is inferred, not confirmed.
}
