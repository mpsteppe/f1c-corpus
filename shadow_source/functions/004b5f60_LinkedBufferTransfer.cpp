// Generated semantic map; not claimed original or recompilable game source.
// Binary address: 0x004B5F60
// Canonical corpus name: LinkedBufferTransfer
// Owner: UnknownObject [UNKNOWN]
// Raw source: functions/LinkedBufferTransfer_004b5f60.c

void UnknownObject::LinkedBufferTransfer()
{
    // Drains a doubly-linked source list (this+0x714 head / this+0x718 tail / this+0x71C current / this+0x720 count) into a singly-linked output list (this+0x30 head / this+0x34 tail / this+0x38 current / this+0x3C count). For each node it unlinks the node whose data pointer matches the current head data, frees the node wrapper (and its data when the node+0xC flag is set), reinitializes the data via SmallStructZeroInit, allocates a fresh 12-byte wrapper via OperatorNewNhMallocWrapper, and prepends it into the output list. Returns the source current pointer, null once the source list is drained.
    // ASSIGNMENT: The source current pointer this+0x71C is set to the source list head this+0x714; this head value also seeds the outer loop and the return value. [field:this:0x00000714, field:this:0x0000071C, source:raw]
    // LOOP: Outer loop walks the doubly-linked source list while its head this+0x714 is non-null; each iteration captures the head node's data pointer (node+0) as the item being moved. [field:this:0x00000714, field:*(this+0x718):0x00000000, source:raw]
    // LOOP: Inner search walks node+4 (next) links from the source head to locate the node whose data pointer (node+0) equals the captured item. [field:*(this+0x718):0x00000004, field:*(this+0x718):0x00000000, source:raw]
    // ASSIGNMENT: Doubly unlink the found node: when a predecessor exists its node+4 link is relinked past the removed node, otherwise the source head this+0x714 advances to the removed node's next; when a successor exists its node+8 link is relinked to the removed node's prev; the source tail this+0x718 moves to the predecessor when the removed node was tail, and the source current this+0x71C advances past the removed node when it was current. [field:*(this+0x718):0x00000008, field:*(*(this+0x718)+0x8):0x00000004, field:*(*(this+0x718)+0x4):0x00000008, field:this:0x00000714, field:this:0x00000718, field:this:0x0000071C, source:raw]
    // ASSIGNMENT: Decrement the source list count this+0x720 for the removed node. [field:this:0x00000720, source:raw]
    // GUARD: When the removed node's +0xC flag byte is set, its data pointer (node+0) is released before the node wrapper is freed. [field:*(this+0x718):0x0000000C, field:*(this+0x718):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf releases the node's data pointer when the flag is set. [callee:0x00587BCF, field:*(this+0x718):0x00000000, source:raw]
    // CALL: FreeWrapper_7bcf releases the source node wrapper itself. [callee:0x00587BCF, field:*(this+0x718):0x00000004, source:raw]
    // CALL: SmallStructZeroInit reinitializes the data record of the item being moved. [callee:0x004B4460, field:*(this+0x718):0x00000000, source:raw]
    // CALL: OperatorNewNhMallocWrapper(12) allocates a fresh 12-byte output-list node wrapper. [callee:0x00587C03, source:raw]
    // ASSIGNMENT: Initialize the new wrapper: +0 stores the reinitialized data pointer, +4 (next) is cleared, and the +8 flag byte is cleared. [field:*(this+0x718):0x00000000, field:*(this+0x718):0x00000004, source:raw]
    // ASSIGNMENT: Link the new node into the singly-linked output list: when the output head this+0x30 is non-null the new node's +4 link is set to it, otherwise the output tail this+0x34 and output current this+0x38 are both set to the new node. [field:this:0x00000030, field:this:0x00000034, field:this:0x00000038, field:*(this+0x718):0x00000004, source:raw]
    // ASSIGNMENT: Advance the output list: the output count this+0x3C is incremented and the output head this+0x30 is set to the new node. [field:this:0x0000003C, field:this:0x00000030, source:raw]
    // LOOP: The outer loop continues while the source current this+0x71C is non-null; it breaks when that pointer becomes null after a transfer. [field:this:0x0000071C, source:raw]
    // RETURN: Return the source current pointer this+0x71C, which is null once the source list has been fully drained. [field:this:0x0000071C, source:raw]

    // Conservative worker pseudocode:
    //   result = this[453];                       // source head (this+0x714)
    //   this[455] = result;                       // source current (this+0x71C)
    //   if (result) {
    //       for (i = *result; *result; i = *result) {
    //           node = this[453];                 // restart walk from source head
    //           if (node) {
    //               while (*node != i) { node = *(node+4); if (!node) goto link; }
    //               // doubly unlink node; adjust source head/tail/current; decrement source count
    //               if (*(node+12)) FreeWrapper_7bcf(*(node+0));
    //               FreeWrapper_7bcf(node);
    //           }
    //   link:
    //           SmallStructZeroInit(i);
    //           nn = OperatorNewNhMallocWrapper(12);
    //           *(nn+0) = i; *(nn+4) = 0; *(nn+8) = 0;
    //           if (this[12]) *(nn+4) = this[12]; else { this[13] = nn; this[14] = nn; }
    //           this[12] = nn; this[15]++;
    //           result = this[455];
    //           if (!result) break;
    //       }
    //   }
    //   return result;
    // UNRESOLVED: The source node and the output wrapper have different layouts (source: data/next/prev/flag; output 12-byte: data/next/flag), yet both are tracked by the extraction through the same dereference bases, so node+8 is the prev link in the source list but the flag byte in the output wrapper.
    // UNRESOLVED: The ownership and lifecycle contract between the source list (this+0x714) and the output list (this+0x30) on the same object are caller-defined.
}
