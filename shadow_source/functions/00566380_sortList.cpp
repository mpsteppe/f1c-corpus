// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00566380
// Canonical corpus name: sub_566380
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_566380_00566380.c

void UnknownObject::sortList()
{
    // Merge-sorts a singly linked list in place. Stores the sort-mode argument at obj+0x220, counts the nodes by walking node next pointers, splits the list in half, recursively sorts each half via sub_5664A0, merges the halves using the sub_565BB0 comparator, then rebuilds the list object's head (obj+0), tail (obj+4) and cursor (obj+8). Called by file/profile/texture scanner objects.
    // ASSIGNMENT: Store the sort-mode argument a2 into the list object at offset 0x220 before sorting. [field:obj:0x00000220, source:raw]
    // GUARD: Proceed only when the list is non-empty: the head pointer at obj+0 (dereferenced through this+0) is non-null. [field:this:0x00000000, field:obj:0x00000000, source:raw]
    // LOOP: Count the nodes by walking each node's next pointer (node+0x4) from the head until null. [field:*(obj+0x0):0x00000004, field:obj:0x00000000, source:raw]
    // GUARD: Sort only when the node count is at least 2; a singleton or empty list keeps its head unchanged. [field:obj:0x00000000, source:raw]
    // CALCULATION: Compute the midpoint as count/2 and advance from the head to the node immediately before it. [field:*(obj+0x0):0x00000004, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Split the list: save the second half as the mid node's next, then terminate the first half by zeroing the split node's link; static extraction records the zero literal at node+0x8 for this split. [field:*(obj+0x0):0x00000004, field:*(obj+0x0):0x00000008, source:raw]
    // CALL: Recursively sort the first half by calling sub_5664A0 with the half's head. [callee:0x005664A0, field:obj:0x00000000, source:raw]
    // CALL: Recursively sort the second half by calling sub_5664A0 with its head. [callee:0x005664A0, source:raw]
    // GUARD: When exactly one sorted half is non-empty, that half becomes the merged head. [field:obj:0x00000000, source:raw]
    // CALL: Compare the current leading node's data of each half with the comparator sub_565BB0 to decide merge order. [callee:0x00565BB0, source:raw]
    // LOOP: Merge loop: repeatedly pick the smaller leading node per sub_565BB0, link it onto the merged tail via node+0x4, and advance the selected half until one half is exhausted. [callee:0x00565BB0, field:*(obj+0x0):0x00000004, source:raw]
    // ASSIGNMENT: Append any remaining nodes of the non-exhausted half to the merged tail via node+0x4. [field:*(obj+0x0):0x00000004, source:raw]
    // ASSIGNMENT: Write the merged head back to obj+0 (the list head pointer). [field:obj:0x00000000, source:raw]
    // LOOP: Traverse from the head to the last node to recover the tail pointer. [field:*(obj+0x0):0x00000004, field:obj:0x00000000, source:raw]
    // ASSIGNMENT: Store the recovered tail at obj+4 and set the cursor at obj+8 to the head; on an empty or singleton list both obj+4 and obj+8 are set to the head. [field:obj:0x00000004, field:obj:0x00000008, source:raw]
    // RETURN: Return the trailing traversal sentinel (zero); callers' use of the return value is not visible in this packet. [function:0x00566380, source:raw]

    // Conservative worker pseudocode:
    //   listObj[0x220] = sortMode;
    //   head = listObj->head;
    //   if (head != NULL) {
    //       count = number of nodes reachable via next links;
    //       if (count >= 2) {
    //           split at midpoint;
    //           firstSorted = sub_5664A0(firstHalf);
    //           secondSorted = sub_5664A0(secondHalf);
    //           merged = merge(firstSorted, secondSorted) using sub_565BB0 comparator;
    //       }
    //   }
    //   listObj->head = merged;
    //   listObj->tail = last node of merged;
    //   listObj->cursor = merged;
    //   return 0;
    // UNRESOLVED: Node layout discrepancy: raw code zeroes the split node's link at node+0x4 and links via node+0x4, but static field extraction classifies node+0x8 as the zeroed flag (init 0) and node+0x4 as read-only.
    // UNRESOLVED: Exact comparator semantics of sub_565BB0 (data pointers at node+0x0) and whether the sort order depends on the mode stored at obj+0x220.
    // UNRESOLVED: Owner object identity is unknown; the caller set (profile/bitmap/texture scanners) is consistent with directory or file-name sorting but is not proven.
    // UNRESOLVED: Whether the char return value signals success or is an unused traversal artifact is not determinable from this packet.
}
