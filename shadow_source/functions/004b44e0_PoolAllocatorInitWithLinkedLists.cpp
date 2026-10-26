// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B44E0
// Canonical corpus name: sub_4B44E0
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/sub_4B44E0_004b44e0.c

void UnknownObject::PoolAllocatorInitWithLinkedLists()
{
    // One-time initialization of a fixed-block pool and its two linked lists. Zeroes eight pool globals dword_8AB6F0..dword_8AB70C, allocates a 4-byte root node that owns a 13824-byte buffer, then builds one 12-byte active-list head node (flag byte 1) linked via dword_8AB6F0 (head) / dword_8AB6F4 (tail) with count dword_8AB6FC. Then, in 32 iterations of 432 bytes, creates one 12-byte free-list node per buffer sub-block (flag byte 0), linking them front-first through dword_8AB700 (head), dword_8AB704 / dword_8AB708 (first-node anchors) and counting them in dword_8AB70C. Returns the last allocation result.
    // ASSIGNMENT: Zero all eight pool globals dword_8AB6F0, dword_8AB6F4, dword_8AB6F8, dword_8AB6FC, dword_8AB700, dword_8AB704, dword_8AB708, dword_8AB70C. [global:0x008AB6F0, global:0x008AB6F4, global:0x008AB6F8, global:0x008AB6FC, global:0x008AB700, global:0x008AB704, global:0x008AB708, global:0x008AB70C, source:raw]
    // CALL: Allocate the 4-byte root node via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // GUARD: When the root node allocation succeeds, proceed with buffer and active-list setup; otherwise the buffer pointer v2 is set to null. [source:raw]
    // CALL: Allocate the 13824-byte pool buffer and store its pointer into the root node. [callee:0x00587C03, source:raw]
    // CALL: Allocate the 12-byte active-list head node. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the active-list head node: data pointer = root node, next pointer at node+4 = 0, flag byte at node+8 = 1. [source:raw]
    // ASSIGNMENT: Wire the active-list node: when dword_8AB6F0 is non-null link it after the current tail dword_8AB6F4; otherwise set both dword_8AB6F0 and dword_8AB6F8 to it; always update tail dword_8AB6F4 and increment the count dword_8AB6FC. [global:0x008AB6F0, global:0x008AB6F4, global:0x008AB6F8, global:0x008AB6FC, source:raw]
    // LOOP: Iterate across the 13824-byte buffer in 432-byte sub-blocks (32 iterations). [source:raw]
    // GUARD: Skip a sub-block when its address (iteration offset i + buffer start) is null. [source:raw]
    // CALL: Allocate a 12-byte free-list node for each non-null sub-block via OperatorNewNhMallocWrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the free-list node: data pointer = sub-block address, next pointer at node+4 = 0, flag byte at node+8 = 0. [source:raw]
    // ASSIGNMENT: Wire the free-list node: when dword_8AB700 is non-null link it as the new head; otherwise set both dword_8AB704 and dword_8AB708 to it as first-node anchors; always update head dword_8AB700 and increment the count dword_8AB70C. [global:0x008AB700, global:0x008AB704, global:0x008AB708, global:0x008AB70C, source:raw]
    // RETURN: Return the last allocation result (null when a failed allocation terminated the path). [source:raw]

    // Conservative worker pseudocode:
    //   dword_8AB6F0 = dword_8AB6F4 = dword_8AB6F8 = dword_8AB6FC = 0;
    //   dword_8AB700 = dword_8AB704 = dword_8AB708 = dword_8AB70C = 0;
    //   root = OperatorNewNhMallocWrapper(4);
    //   if (root) {
    //       *(DWORD*)root = OperatorNewNhMallocWrapper(13824);
    //       head = OperatorNewNhMallocWrapper(12);
    //       if (head) {
    //           *(DWORD*)head = root;      *(DWORD*)(head+4) = 0;   *(BYTE*)(head+8) = 1;
    //       }
    //       if (dword_8AB6F0) *(DWORD*)(dword_8AB6F4+4) = head;
    //       else { dword_8AB6F0 = head; dword_8AB6F8 = head; }
    //       dword_8AB6F4 = head; ++dword_8AB6FC;
    //   }
    //   for (i = 0; i < 13824; i += 432) {
    //       block = i + *(DWORD*)root;
    //       if (!block) continue;
    //       node = OperatorNewNhMallocWrapper(12);
    //       if (node) {
    //           *(DWORD*)node = block;     *(DWORD*)(node+4) = 0;   *(BYTE*)(node+8) = 0;
    //       }
    //       if (dword_8AB700) *(DWORD*)(node+4) = dword_8AB700;
    //       else { dword_8AB704 = node; dword_8AB708 = node; }
    //       dword_8AB700 = node; ++dword_8AB70C;
    //   }
    //   return result;
    // UNRESOLVED: The exact meaning of the two list heads (dword_8AB6F0 active list, dword_8AB700 free list) and the flag bytes (1 vs 0) is inferred; the consumer of this pool is unknown.
    // UNRESOLVED: dword_8AB6F8 and dword_8AB708 are written only on the first node of their respective lists; their distinct role from the head/tail pointers is unresolved.
    // UNRESOLVED: The number of iterations (13824 / 432 = 32) is derived arithmetic, not an explicit packet constant.
}
