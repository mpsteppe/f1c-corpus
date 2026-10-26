// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x00565E20
// Canonical corpus name: LinkedListDestructorWithChildCleanup
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListDestructorWithChildCleanup_00565e20.c

void UnknownObject::DestroyTwoLevelListWithCleanup()
{
    // Destroys a two-level linked list. Cleans the inner list through EnhancedListCleanupWithSubObjectDelete, frees an extra sub-resource pointer at head+0x210 when present, then walks the outer nodes releasing each node's data (with a ShortComputation_4370 sub-object teardown when the node flag at +8 is set) and the node itself. Finally zeroes the four head fields and frees the head structure.
    // CALL: EnhancedListCleanupWithSubObjectDelete(*this) first cleans the inner list reachable through this+0. [callee:0x00565D50, field:this:0x00000000]
    // GUARD: When this+0 (list head) is null the outer teardown is skipped and the inner-cleanup result is returned directly. [field:this:0x00000000]
    // CALL: If the extra sub-resource pointer at head+0x210 (v3[132]) is non-null it is released through FreeWrapper_7bcf before node iteration. [callee:0x00587BCF, field:obj:0x00000210]
    // LOOP: Walks the outer node chain from the head, advancing each iteration through the node's next pointer at node+4. [field:*(obj+0x0):0x00000000]
    // GUARD: A node's data is only cleaned when the flag byte at node+8 is non-zero. [field:*(obj+0x0):0x00000008]
    // CALL: For flagged nodes, the data pointer at node+0 is torn down via ShortComputation_4370 on data+81 dwords (0x144 bytes) and then freed through FreeWrapper_7bcf. [callee:0x00414370, callee:0x00587BCF, field:*(obj+0x0):0x00000000]
    // CALL: Every node itself is freed through FreeWrapper_7bcf regardless of its data flag. [callee:0x00587BCF]
    // ASSIGNMENT: The four head fields at +0x0, +0x4, +0x8 and +0xC are zeroed before the head is released. [field:obj:0x00000000, field:obj:0x00000004, field:obj:0x00000008, field:obj:0x0000000C]
    // CALL: FreeWrapper_7bcf releases the head structure allocation after the list is drained. [callee:0x00587BCF, field:this:0x00000000]
    // RETURN: Returns the inner-cleanup result when the head was already null. [source:raw]

    // Conservative worker pseudocode:
    //   result = EnhancedListCleanupWithSubObjectDelete(*this)
    //   head = *this
    //   if not head: return result
    //   if head[132]: Free(head[132])
    //   node = head[0]
    //   while node:
    //       next_node = node[1]
    //       if node.flag_at_8:
    //           if node[0]:
    //               ShortComputation_4370(node[0] + 81 dwords)
    //               Free(node[0])
    //       Free(node)
    //       node = next_node
    //   head[0] = head[1] = head[2] = head[3] = 0
    //   return Free(head)
    // UNRESOLVED: field *(obj+0x0):0x00000008 only proves the node carries a data-cleanup flag byte; whether offset +8 is a dedicated bool or a struct member is not established.
    // UNRESOLVED: The caller-level meaning of the second-level list stored at this+0 (the inner list) is outside this function's evidence.
}
