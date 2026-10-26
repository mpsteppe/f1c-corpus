// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00586670
// Canonical corpus name: sub_586670
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_586670_00586670.c

void UnknownObject::RemoveListNodeByData()
{
    // Removes the first node whose stored data pointer matches a2 from a singly-linked container (head at this+0x0, tail at this+0x4, count at this+0xC). Unlinks the node, adjusts the current-node cursor this+0x8 when needed, optionally frees the node payload and then the node itself, and returns 1. Returns 0 when the target a2 is null or the list is empty.
    // GUARD: Return 0 immediately when the removal target a2 is null (no data pointer to match). [source:raw]
    // GUARD: Return 0 when the head pointer this[0] is null, meaning the container is empty. [field:this:0x00000000, source:raw]
    // LOOP: Walk the list from the head using each node's next pointer at obj+0x4, comparing each node's stored data pointer against a2 and remembering the previous node; return 0 when the next pointer becomes null before a match. [field:obj:0x00000004, source:raw]
    // ASSIGNMENT: When the matched node equals the current-node cursor this[2], advance this[2] to the matched node's next pointer (obj+0x4). [field:this:0x00000008, field:obj:0x00000004]
    // ASSIGNMENT: Unlink the matched node: set the previous node's next (obj+0x4) to the matched node's next, or set the container head this[0] to that next when there is no previous node. [field:obj:0x00000004, field:this:0x00000000]
    // ASSIGNMENT: When the matched node is the container tail this[1], set the tail to the previous node. [field:this:0x00000004]
    // ASSIGNMENT: Decrement the node count this[3]. [field:this:0x0000000C]
    // STATE_TRANSITION: When the keep-node flag a3 is zero, clear the node flag byte at obj+0x8 (marking the node as no longer owning its payload). [field:obj:0x00000008, source:raw]
    // GUARD: When the node flag byte at obj+0x8 is set and the node's data pointer is non-null, call EmptyStub_0170 and free the payload via FreeWrapper_7bcf. [field:obj:0x00000008, callee:0x004B0170, callee:0x00587BCF]
    // CALL: Free the node object via FreeWrapper_7bcf and return 1 (success). [callee:0x00587BCF]

    // Conservative worker pseudocode:
    //   result = 0
    //   if a2 == 0: return result
    //   node = this[0]
    //   if node == 0: return result
    //   while node.data != a2:
    //       prev = node
    //       node = node.next
    //       if node == 0: return result
    //   if node == this[2]: this[2] = node.next
    //   if prev != 0: prev.next = node.next
    //   else: this[0] = node.next
    //   if node == this[1]: this[1] = prev
    //   this[3] -= 1
    //   if a3 == 0: node.flag = 0
    //   if node.flag != 0 and node.data != 0:
    //       EmptyStub_0170()
    //       FreeWrapper_7bcf(node.data)
    //   FreeWrapper_7bcf(node)
    //   return 1
    // UNRESOLVED: The data pointer is stored at node offset 0 (v4[0]) but the packet provides no field evidence ref for obj+0x0; the comparison and payload free reference it through source:raw only.
    // UNRESOLVED: The purpose of the container cursor this[2] (advanced to the matched node's successor) is unknown; it may track the most recently touched node or an iteration position.
    // UNRESOLVED: EmptyStub_0170 (0x004B0170) is called with no observable arguments before the payload free; its role is unknown.
    // UNRESOLVED: Node field obj+0xC (init literal 0) is never accessed in this function's raw source; its role is unassigned here.
}
