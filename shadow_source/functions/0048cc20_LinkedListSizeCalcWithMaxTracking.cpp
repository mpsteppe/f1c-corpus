// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x0048CC20
// Canonical corpus name: LinkedListSizeCalcWithMaxTracking
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedListSizeCalcWithMaxTracking_0048cc20.c

void UnknownObject::LinkedListSizeCalcWithMaxTracking()
{
    // Walks the linked list rooted at this[199] (this+0x31C), and for each node whose sub-object pointer resolves to a child struct, computes two dimension maxima: this[203] (this+0x32C) as max(prev, child+28 plus 2) and this[204] (this+0x330) as max(prev, child+32), both seeded to 5. The walk iterator this[201] (this+0x324) is advanced through each node's next pointer, and the final node pointer (or null) is returned.
    // ASSIGNMENT: Seed the two tracked maxima to 5: this[203] = 5 and this[204] = 5. [field:this:0x0000032C, field:this:0x00000330, source:raw]
    // ASSIGNMENT: Initialize the walk iterator from the list head: this[201] = this[199]. [field:this:0x00000324, field:this:0x0000031C, source:raw]
    // GUARD: Proceed only when the head pointer this[199] is non-null. [field:this:0x0000031C, field:*(this+0x31C):0x00000000, source:raw]
    // LOOP: Iterate the list following each node's next pointer (node+0x0); break when the walk pointer or next pointer is null. [field:*(*(this+0x31C)+0x0):0x00000000, field:this:0x00000324, source:raw]
    // GUARD: For each node, read the sub-object pointer at node+0x4; skip to the next node when it is null. [field:*(*(this+0x31C)+0x0):0x00000004, source:raw]
    // GUARD: Resolve the child struct through the sub-object chain; skip the node when the child pointer (sub-object+12) is null. [field:*(*(this+0x31C)+0x0):0x00000010, source:raw]
    // CALCULATION: Compute dimension one candidate as child offset 28 plus 2 and keep the running maximum in this[203]. [field:*(*(*(this+0x31C)+0x0)+0x10):0x0000001C, field:this:0x0000032C, source:raw]
    // CALCULATION: Compute dimension two candidate from child offset 32 and keep the running maximum in this[204]. [field:*(*(*(this+0x31C)+0x0)+0x10):0x00000020, field:this:0x00000330, source:raw]
    // STATE_TRANSITION: Advance the walk: this[201] becomes the current node's next pointer (node+0x0); terminate when it is null. [field:this:0x00000324, field:*(*(this+0x31C)+0x0):0x00000000, source:raw]
    // RETURN: Return the final walk pointer (the last node visited, or null when the list is empty or fully traversed). [field:this:0x00000324, source:raw]

    // Conservative worker pseudocode:
    //   _DWORD *LinkedListSizeCalcWithMaxTracking(_DWORD *this) {
    //     this[203] = 5; this[204] = 5;
    //     _DWORD *node = this[199]; this[201] = node;
    //     if (!node) return node;
    //     do {
    //       _DWORD *next = (_DWORD*)*node;
    //       if (node[1]) {
    //         int child = *(_DWORD*)(node[1] + 12);
    //         if (child) {
    //           int d1 = *(_DWORD*)(child + 28) + 2; if (d1 > this[203]) this[203] = d1;
    //           int d2 = *(_DWORD*)(child + 32);  if (d2 > this[204]) this[204] = d2;
    //         }
    //       }
    //       node = (_DWORD*)this[201]; if (!node) break;
    //       node = (_DWORD*)node[1]; this[201] = node;
    //       if (!node) break;
    //     } while (node);
    //     return node;
    //   }
    // UNRESOLVED: The exact semantics of child struct offsets 28 and 32 and the extra 2 added to dimension one are not grounded by the packet.
    // UNRESOLVED: The purpose of the base value 5 for both maxima is unknown.
    // UNRESOLVED: The caller LinkedListNodeAppend (0x0048D2B0) is the only known consumer of these computed maxima.
}
