// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B8360
// Canonical corpus name: SpriteOverlayDisplayListCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/SpriteOverlayDisplayListCleanup_004b8360.c

void UnknownObject::DisplayListNodeRemoveByFloatKey()
{
    // Walks a sorted doubly-linked node list (head 0x6C0, tail 0x6C4, cursor 0x6C8, count 0x6CC, dirty flag 0x6D0) comparing each node's inner-data float key against a reference key at 0xF38 with epsilon 2.0, and removes the first node whose key matches within the epsilon. Unlinks the node, decrements the count, frees the node's inner data (and its string pointer) when the node's byte flag is set, frees the node frame via FreeWrapper_7bcf, sets the dirty flag to 1, and returns 1. Traversal stops early when the sorted list's keys exceed the reference key.
    // ASSIGNMENT: Seed the traversal cursor from the list head: *(this+0x6C8) = *(this+0x6C0). [field:this:0x000006C8, field:this:0x000006C0]
    // GUARD: Begin traversal only when the head pointer is non-null and the head node's data pointer is non-null. [field:this:0x000006C0, field:*(this+0x6C0):0x00000000]
    // CALCULATION: Compare the node's float key at its inner data pointer with the reference key this+0xF38 using fabs, accepting a match within epsilon 2.0. [field:*(*(this+0x6C0)+0x0):0x00000000, field:this:0x00000F38]
    // GUARD: When the key difference exceeds epsilon and the node key is greater than the reference key, stop searching (the list is sorted ascending) and return 1. [field:*(*(this+0x6C0)+0x0):0x00000000, field:this:0x00000F38]
    // LOOP: Walk nodes from the head via node->next (+0x4) to locate the node whose data pointer equals the cursor's data pointer. [field:*(this+0x6C0):0x00000004, field:*(this+0x6C0):0x00000000, field:*(this+0x6C8):0x00000000]
    // STATE_TRANSITION: Unlink the matching node: if it is the cursor, advance the cursor to node->next; relink prev->next to node->next (or set head 0x6C0 to node->next when no prev); relink next->prev to node->prev; if it is the tail 0x6C4, set tail to node->prev; decrement the element count at 0x6CC. [field:this:0x000006C8, field:*(this+0x6C0):0x00000004, field:*(this+0x6C0):0x00000008, field:this:0x000006C0, field:this:0x000006C4, field:this:0x000006CC]
    // CALL: If the node's byte flag (+0xC) is set, free the inner data's string pointer (+0x4) and then the inner data object (+0x0) via FreeWrapper_7bcf. [field:*(this+0x6C0):0x0000000C, field:*(*(this+0x6C0)+0x4):0x00000004, field:*(*(this+0x6C0)+0x0):0x00000000, callee:0x00587BCF]
    // CALL: Free the removed node frame itself via FreeWrapper_7bcf. [callee:0x00587BCF]
    // ASSIGNMENT: Set the dirty/sorted flag at this+0x6D0 to 1 after a removal. [field:this:0x000006D0]
    // CALCULATION: When no match was found at the current node, advance the cursor to the next node via node->next (+0x4) and continue while a next node exists. [field:this:0x000006C8, field:*(this+0x6C8):0x00000004]
    // RETURN: Return 1 on all exit paths. [source:raw]

    // Conservative worker pseudocode:
    //   char DisplayListNodeRemoveByFloatKey(this, ref_key) {
    //     cursor = head;
    //     while (cursor && *cursor) {
    //       if (fabs(**cursor - this[0xF38]) > 2.0) {
    //         if (**cursor > this[0xF38]) return 1;
    //       } else if (node = find_node_with_data(*cursor)) {
    //         unlink(node); --count;
    //         if (node[0xC]) { free(node[0][0x4]); free(node[0]); }
    //         free(node); dirty = 1;
    //         return 1;
    //       }
    //       cursor = cursor[0x4];
    //     }
    //     return 1;
    //   }
    // UNRESOLVED: Global flt_5ACD20 is listed in the evidence but never referenced by the raw source; possibly the epsilon constant (2.0) folded by the decompiler.
    // UNRESOLVED: Node field +0x10 (beyond the 16-byte node frame) is neither read nor written in this function.
    // UNRESOLVED: Exact owner class is unknown; callers are overlay/menu display-list management code.
    // UNRESOLVED: The float epsilon (2.0) semantics are inferred from the fabs comparison in the raw source.
}
